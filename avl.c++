#include <iostream>

using namespace std;


typedef int MyType;
class AVLnode{
    public:
        MyType data;
        int balance;
        AVLnode *left, *right, *parent;
        AVLnode(MyType k, AVLnode *p): data(k), balance(0), parent(p),
            left(nullptr), right(nullptr){}
};

class MyAVL{
    public:
        MyAVL();
        ~MyAVL();
        void Insert(MyType x);
        void Delete(MyType x);
        bool Search(MyType x);
        void Display();
        void Display1();
    private:
        void InsertNode(AVLnode** root, AVLnode* parent, MyType data);
        AVLnode* DeleteNode(AVLnode *root, MyType data);

        AVLnode* rebalance_node(AVLnode* n){
            setBalance(n);
            if(n->balance == -2){
                if(height(n->left->left) >= height(n->left->right)){
                    n = rotateRight(n);
                }else{
                    n = rotateRightThenLeft(n);
                }
            }
            return n;
        }
        void rebalance(AVLnode *n){
            if(n != nullptr){
                n = rebalance_node(n);
                if(n->parent != nullptr){
                    rebalance(n->parent);
                }else{
                    root = n;
                }
            }
        }
        AVLnode *root;
    };
AVLnode* rotateLeft(AVLnode *a){
    if(a != nullptr){
        AVLnode *b = a->right;
        b->parent = a->parent;
        a->right = b->left;
        if(a->right != nullptr){
            a->right->parent = a;
        }
        b->left = a;
        a->parent = b;
        if(b->parent != nullptr){
            if(b->parent->right == a){
                b->parent->right = b;
            }else{
                b->parent->left = b;
            }
        }
        setBalance(a);
        setBalance(b);
        return b;
    }
    else{
        return nullptr;
    }
}
AVLnode* rotateRight(AVLnode *a){
    if(a != nullptr){
        AVLnode *b = a->left;
        b->parent = a->parent;
        a->left = b->right;
        if(a->left != nullptr){
            a->left->parent = a;
        }
        b->right = a;
        a->parent = b;
        if(b->parent != nullptr){
            if(b->parent->right ==a){
                b->parent->right = b;
            }else{
                b->parent->left = b;
            }
        }
        setBalance(a);
        setBalance(b);
        return b;
    }
    else{
        return nullptr;
    }
}
AVLnode* rotateLeftThenRight(AVLnode *n){
    n->left = rotateLeft(n->left);
    return rotateRight(n);
}
AVLnode* rotateRightThenLeft(AVLnode *n){
    n->right = rotateRight(n->right);
    return rotateLeft(n);
}

int height(AVLnode *n){
    if(n == nullptr){
        return -1;
    }
    return 1 + max(height(n->left), height(n->right));
}

void setBalance(AVLnode *n){
    if(n!=nullptr){
        n->balance = height(n->right) - height(n->left);
    }
}

void printBalance(AVLnode *n){
    if(n != nullptr){
        printBalance(n->left);
        cout << n->balance << " ";
        printBalance(n->right);
    }
}

void PrintGivenLevel(AVLnode* root, int level){
    if(root != nullptr){
        if(level == 0){
            if(root->parent != nullptr){
                cout << "_" << root->data << "(" << root->parent->data << ")_";
            }
            else{
                PrintGivenLevel(root->left, level - 1);
                PrintGivenLevel(root->right, level -1);
            }
        }
    }
}

void Display(){
    int h = height(root);
    int i;
    for(i = 0; i <=h; i++){
        PrintGivenLevel(root, i);
        cout << endl;
    }
}

int main(){

}