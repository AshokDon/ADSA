#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    //constructor
    TreeNode(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

};
TreeNode *Insert(TreeNode *root, int val){
    //base case
    if(root == NULL) return new TreeNode(val);
    if(val < root->data){
        root->left = Insert(root->left,val);
    }
    if(val > root->data){
        root->right = Insert(root->right,val);
    }
    return root;
}
TreeNode *BSTInsertion(vector<int>&array){
    int len = array.size();
    if(len == 0) return NULL;
    TreeNode *root = NULL;
    for(int i = 0 ; i < len ; i++){
        root = Insert(root, array[i]);
    }
    return root;
}
void Inorder(TreeNode *root){
    if(root == NULL) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
//Search 
bool Search(TreeNode *root , int key){
    if(root==NULL) return false;
    if(root->data == key) return true;
    if(key < root->data){
        return Search(root->left,key);
    }
    else{
        return Search(root->right,key);
    }

}
TreeNode *Findmin(TreeNode *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
TreeNode *Delete(TreeNode *root, int key){
    if(root == NULL) return NULL;

    if(key < root->data){
        root->left = Delete(root->left,key);
    }
    if(key > root->data){
        root->right = Delete(root->right,key);
    }
    else{
        //no child 
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        //One child
        if(root->left == NULL || root->right== NULL){
            TreeNode *temp;
            if(root->left != NULL){
                temp = root->left;
            }
            else{
                temp = root->right;
            }
            free(root);
            return temp;
        }
        //two children
        else{
            TreeNode *temp = Findmin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;
}
int main(){
   
   vector<int>array = {3,2,1,5,6,4};
   TreeNode *root = BSTInsertion(array);
   Inorder(root);

   int key = 5;
   bool find = Search(root,key);

   root = Delete(root,key);
   


}
