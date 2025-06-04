#include<iostream>

using namespace std;

typedef struct _common_tree_node{
    int data;
    _common_tree_node * first_child;
    _common_tree_node * next_sibling;

} CommonTreeNode;

//以数组的方式存储，旋转90度就是二叉树
void traversal(CommonTreeNode  *root){
    if(!root){return;}
    traversal(root->first_child);
    traversal(root->next_sibling);
    
    cout<< root->data<<endl;
}