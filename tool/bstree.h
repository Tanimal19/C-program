#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct treenode{
	int data;
	struct treenode *left;
	struct treenode *right;
} Treenode;

Treenode *genTreenode(int data, Treenode *left, Treenode *right){
	Treenode *node = malloc(sizeof(Treenode));
	assert(node != NULL);
	node->data = data;
	node->left = left;
	node->right = right;
	return node;
}
Treenode *insertTreenode(Treenode *root, int data){
	if(root == NULL)
		return genTreenode(data, NULL, NULL);

	if(data < root->data)
		root->left = insertTreenode(root->left, data);
	else
		root->right = insertTreenode(root->right, data);

	return root;
}
void freeTree(Treenode *root){
	if(root == NULL) return;
	else{
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}
void printTree(Treenode *root){
	if(root == NULL) return;

	printTree(root->left);
	printf("%d\n", root->data);
	printTree(root->right);
}
