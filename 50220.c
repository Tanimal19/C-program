#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "isIsomorphic.h"

struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *mid;
    struct TreeNode *right;
};
 
typedef struct TreeNode TreeNode;
 
bool isIsomorphic(TreeNode* root1, TreeNode* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }

    return 
    ( isIsomorphic(root1->left , root2->mid)
      && isIsomorphic(root1->mid , root2->right)
      && isIsomorphic(root1->right , root2->left) ) ||
    ( isIsomorphic(root1->left , root2->right)
      && isIsomorphic(root1->mid , root2->left)
      && isIsomorphic(root1->right , root2->mid) ) ||
    ( isIsomorphic(root1->left , root2->left)
      && isIsomorphic(root1->mid , root2->mid)
      && isIsomorphic(root1->right , root2->right) ) ||
    ( isIsomorphic(root1->left , root2->mid)
      && isIsomorphic(root1->mid , root2->left)
      && isIsomorphic(root1->right , root2->right) ) ||
    ( isIsomorphic(root1->left , root2->right)
      && isIsomorphic(root1->mid , root2->mid)
      && isIsomorphic(root1->right , root2->left) ) ||
    ( isIsomorphic(root1->left , root2->left)
      && isIsomorphic(root1->mid , root2->right)
      && isIsomorphic(root1->right , root2->mid) );
}

TreeNode *buildTree(TreeNode **roots) {
    int val;
    scanf("%d", &val);
    if(val == 0) return NULL;
 
    TreeNode *now = *roots;
 
    (*roots)++;
 
    now->left = buildTree(roots);
    now->mid = buildTree(roots);
    now->right = buildTree(roots);
 
    return now;
}
 
 
int main() {
    int T, size;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &size);
        TreeNode* root1 = (TreeNode*)calloc(size, sizeof(TreeNode));
        TreeNode* root2 = (TreeNode*)calloc(size, sizeof(TreeNode));
 
        TreeNode *nptr1 = root1, *nptr2 = root2;
 
        root1 = buildTree(&nptr1);
        root2 = buildTree(&nptr2);
 
        isIsomorphic(root1, root2) == true ? printf("True\n") : printf("False\n");
 
        free(root1);
        free(root2);
    }
    return 0;
}