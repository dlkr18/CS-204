#include<bits/stdc++.h>
using namespace std;


typedef struct treapnode{
  int key,prio;
  treapnode *left,*right;
}treapnode;


treapnode *rrot(treapnode *y){
    treapnode *x=y->left;
    treapnode *z=x->right;
    x->right=y;
    y->left=z;
    return x;
}

treapnode *lrot(treapnode *x){
    treapnode *y=x->right,*z=y->left;
    y->left=x;
    x->right=z;
    return y;
}

treapnode *newnode(int key){
    treapnode *temp=new(treapnode);
    temp->key=key;
    temp->prio=rand()%100;
    temp->left=temp->right=NULL;
    return temp;
}

treapnode *Search(treapnode *root,int key){
    if(root==NULL || root->key==key)
        return root;
    if(root->key <key)
        return Search(root->right,key);
    return Search(root->left,key);

}

treapnode *Insert(treapnode *root,int key){
        if(!root) return newnode(key);

        if(key<=root->key){
            root->left=Insert(root->left,key);

            if(root->left->prio>root->prio)
                root=rrot(root);
        }
        else{
            root->right=Insert(root->right,key);
            if(root->right->prio>root->prio)
                root=lrot(root);
        }


treapnode *Delete(treapnode* root,int key){
    if(root==NULL)return root;

    if(key <root->key)
        root->left=Delete(root->left,key);
    else if(key >root->key)
        root->right=Delete(root->right,key);
    else if(root->left==NULL){
        treapnode *temp=root->right;
        delete(root);
        root=temp;
    }
    else if(root->right==NULL){
        treapnode *temp=root->left;
        delete(root);
        root=temp;
    }
    else if(root->left->prio < root->right->prio){
        root=lrot(root);
        root->left=Delete(root->left,key);
    }
    else{
        root=rrot(root);
        root->right=Delete(root->right,key);
    }
    return root;
}

void inorder(treapnode *root){
    if(root){
        inorder(root->left);
        cout << "key " << root->key << "priority " << root->prio;
        if(root->left)
            cout << "left child " << root->left->key;
        if(root->right)
            cout << "right child" << root->right->key;
        cout << '\n';
        inorder(root->right);
    }

}

int main{
    srand(time(NULL));

    treapnode *root=NULL;
    root=Insert(root,38);
    root=Insert(root,45);
    root=Insert(root.98);
    root=Insert(root,21);
    root=Insert(root,50);
    root=Insert(root,75);
    root=Insert(root,9);

    cout << "inorder traversal of treap\n";
    inorder(root);

    cout << "\ndelete 21\n";
    root=Delete(root,21);
    cout << "inorder traversal of treap\n";
    inorder(root);

    treapnode *ser =Search(root,50);
    (ser==NULL) ? cout << "\n 50 not found\n" : cout << "\n 50 found\n";

return 0;
}
