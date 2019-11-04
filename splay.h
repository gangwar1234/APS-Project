// #include <bits/stdc++.h>
// using namespace std;
#ifndef xxx
#define xxx

class splay{

struct node
{  int key;
   node *left, *right;
};
node* newNode(int key)
{
node* Node = new node();
Node->key = key;
Node->left = Node->right = NULL;
return (Node);
}

void insert(node*root,int data)
{
if(!root)return;
if(root->key<data)
{  node* new_node=newnode(data);
  new_node->right=root;
    }
    else if(root-<key>data)
    {  node* new_node=newnode(data);
  new_node->left=root;
    }
    else
     splay(root,key);
   
}  

node *rightRotate(node *x)
{
node *y = x->left;
x->left = y->right;
y->right = x;
return y;
}
node *leftRotate(node *x)
{
node *y = x->right;
x->right = y->left;
y->left = x;
return y;
}
node *splay(node *root, int key)
{
    if (root == NULL || root->key == key)
return root;
    if (root->key > key)
{   if (root->left == NULL) return root;
if (root->left->key > key)
{  root->left->left = splay(root->left->left, key);
root = rightRotate(root);
}
else if (root->left->key < key)
{
root->left->right = splay(root->left->right, key);
if (root->left->right != NULL)
root->left = leftRotate(root->left);
}
return (root->left == NULL)? root: rightRotate(root);
}
else
{  
if (root->right == NULL) return root;
if (root->right->key > key)
{  root->right->left = splay(root->right->left, key);
if (root->right->left != NULL)
root->right = rightRotate(root->right);
}
else if (root->right->key < key)
{
root->right->right = splay(root->right->right, key);
root = leftRotate(root);
}
return (root->right == NULL)? root: leftRotate(root);
}
}  

node *search(node *root, int key)
{
return splay(root, key);
}

};
#endif