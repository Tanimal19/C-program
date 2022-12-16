#include <stdio.h>
#include <stdlib.h>
//#include "Pascal.h"

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;
 
void build_Pascal(Node* node_array, int height){
    if(height == 0) return;

    node_array[0].value = 1;
    int i;
    for(i=0 ; i<height-1 ; i++){
        node_array[i].left = &node_array[i+height];
        node_array[i].right = &node_array[i+1];

        node_array[i].left->value += node_array[i].value;
        node_array[i].right->value += node_array[i].value;
    }
    node_array[i].left = NULL;
    node_array[i].right = NULL;

    build_Pascal(&node_array[height], height-1);
    return;
}

int main(){
    int height;
    scanf("%d", &height);
    int node_num = height * (height+1) / 2;
    Node* node_array = (Node*)calloc(node_num, sizeof(Node));
    build_Pascal(node_array, height);
 
    for (int i = 0; i < node_num; i++){
        int value = node_array[i].value;
        int left = (node_array[i].left == NULL)? -1 : (node_array[i].left - node_array);
        int right = (node_array[i].right == NULL)? -1 : (node_array[i].right - node_array);
        printf("%d %d %d\n", value, left, right);
    }
    free(node_array);
    node_array = NULL;
    return 0;
}