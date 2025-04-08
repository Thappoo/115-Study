#include <iostream>

using namespace std;

//full tree?
bool FullTree(TreeNode* root){
    if(root == nullptr || root->left == nullptr && root->right == nullptr){
        return true; // full
    }
    else if (root->left != nullptr && root->right != nullptr){
        return(FullTree(root->left) && FullTree(root->right)); //keep going down the tree to make sure if full
    }
    else{
        return false; // not full
    }
}

int main(){

    return 0;
}