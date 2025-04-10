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

void fib2(int x, int t, int step){
    if(x == 0){
        t[x] = 0;
        step++;
        return 0;
    }
    else if(x == 1){
        t[x] = 1;
        step++;
        return 1;
    }else{
        int a, b;
        a = (t[x-1] != -1) ? t[x-1] : fib2(x-1, t, step); //t[] not needed
        b = (t[x-2] != -1) ? t[x-2] : fib2(x-2, t, step);
        t[x] = a+b;
        step++; //<- forgotten line
        return f[x];
    }
}


void leftRotate(TreeNode* a){
    if(root != nullptr){
        TreeNode* b = a->right; //rotate on a so set b as new head
        b->parent = a->parent;
        a->right = b->left; //a node is moving to be 'b' left so we need to move it
        if(b->left != nullptr){
            a->right->parent = a;
        }
        b->left = a; //a node finally moves to become b->left
        a->parent = b; 

    }
}
int main(){

    return 0;
}