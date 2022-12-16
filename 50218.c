# include<stdio.h>
# include<stdlib.h>
# include<assert.h>
//# include "treeToList.h"

struct treenode {
    int value;
    struct treenode *left;
    struct treenode *right;
};
 
struct list {
    struct treenode *head;
    struct treenode *tail;
};
 
typedef struct treenode TreeNode;
typedef struct list List;
 
List treeToListFunc(TreeNode * root){
    List ans;
    ans.head = root;

    if(root->right == NULL && root->left == NULL){
        // printf("%d R null / L null\n", root->value);
        ans.head->left = NULL;
        ans.tail = ans.head;
        ans.head->right = NULL;
        return ans;
    }
    else if(root->right == NULL){
        // printf("%d R null\n", root->value);
        List L_list = treeToListFunc(root->left);
        ans.head->left = L_list.head;
        ans.tail = L_list.tail;
        ans.head->right = NULL;
        return ans;
    }
    else if(root->left == NULL){
        // printf("%d L null\n", root->value);
        List R_list = treeToListFunc(root->right);
        ans.head->left = R_list.head;
        ans.tail = R_list.tail;
        ans.head->right = NULL;
        return ans;
    }

    if(root->value % 2 == 1){
        // printf("%d R first\n", root->value);
        List L_list = treeToListFunc(root->left);
        List R_list = treeToListFunc(root->right);
        ans.head->left = R_list.head;
        R_list.tail->left = L_list.head;
        ans.tail = L_list.tail;
        ans.head->right = NULL;
        return ans;
    }
    else{
        // printf("%d L first\n", root->value);
        List L_list = treeToListFunc(root->left);
        List R_list = treeToListFunc(root->right);
        ans.head->left = L_list.head;
        L_list.tail->left = R_list.head;
        ans.tail = R_list.tail;
        ans.head->right = NULL;
        return ans;
    }
}

 
TreeNode *buildTree(int **values, TreeNode **roots) {
    int val;
    scanf("%d", &val);
    if(val == 0) return NULL;
    **values = val;
    TreeNode *now = *roots;
    (*values)++; (*roots)++;
    now -> value = val;
    now -> left  = buildTree(values, roots);
    now -> right = buildTree(values, roots);
    return now;
}
 
int main(void) {
    int size;
    scanf("%d\n", &size);
    TreeNode * root = (TreeNode*)calloc(size, sizeof(TreeNode));
 
    int valueRecord[size];
    int *vptr = valueRecord;
    TreeNode *nptr = root;
 
    root = buildTree(&vptr, &nptr);
 
    List ans = treeToListFunc(root);
 
    TreeNode * node = ans.head;
    TreeNode * firstAddr = &root[0];
    TreeNode * lastAddr = &root[size];
    for(; node != NULL; node = node -> left) {
        if (node -> right != NULL) {
            printf("Right node should be null\n");
            break;
        }
        if (firstAddr > node || lastAddr <= node) {
            printf("Memory address out of bound\n");
            break;
        }
        int counter = node - firstAddr;
        if (node -> value != valueRecord[counter]) {
            printf("You can't modify the value in the given treeNode\n");
            break;
        }
        printf("%d ", node -> value);
    }
 
     free(root);
    return 0;
}