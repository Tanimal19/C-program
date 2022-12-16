#include <stdio.h>
#include <stdlib.h>

typedef struct treenode{
	int data;
	struct treenode *left;
	struct treenode *right;
} Treenode;

typedef struct return_data{
	struct treenode *tree;
	int end;
} Rdata;

char s[4000];

void HLHR(Treenode *root);
void HRHL(Treenode *root);

Treenode *genTreenode(int data, Treenode *left, Treenode *right){
	Treenode *new = (Treenode*)malloc(sizeof(Treenode));
	new->data = data;
	new->left = left;
	new->right = right;
	return new;
}

Rdata *read_data(int now){
	Rdata *Parent = (Rdata*)malloc(sizeof(Rdata));

	if(s[now] == '('){
		Rdata *L = read_data(now+1);
		Rdata *R = read_data(L->end);

		Parent->tree = genTreenode((L->tree->data + R->tree->data), L->tree, R->tree);
		Parent->end = R->end + 1;
		return Parent;
	}
	else{
		int num = 0;
		while(s[now] != ')' && s[now] != ','){
			num *= 10;
			num += (s[now] - '0');
			now++;
		}
		Parent->tree = genTreenode(num, NULL, NULL);
		Parent->end = now + 1;
		return Parent;
	}
}

void HLHR(Treenode *root){
	printf("%d\n", root->data);

	if(root->left != NULL)
		HRHL(root->left);

	printf("%d\n", root->data);

	if(root->right != NULL)
		HRHL(root->right);

	return;
}

void HRHL(Treenode *root){
	printf("%d\n", root->data);

	if(root->right != NULL)
		HLHR(root->right);

	printf("%d\n", root->data);

	if(root->left != NULL)
		HLHR(root->left);

	return;
}

int main(){
	scanf("%s", s);
	Rdata *ans = read_data(0);
	HLHR(ans->tree);
	return 0;
}