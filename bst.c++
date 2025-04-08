#include <iostream>
#include <tuple>
#include <climits>
#include <vector>

using namespace std;


typedef int MyType;
class TreeNode{
    public:
        TreeNode(): data(0), left(nullptr), right(nullptr){}
        TreeNode(int d) : data(d), left(nullptr), right(nullptr){}
        ~TreeNode(){}
        int data;
        TreeNode* left;
        TreeNode* right;
};

void DestroyTree(TreeNode *root){
    if(root != nullptr){
        DestroyTree(root->left);
        DestroyTree(root->right);
        delete root;
    }
}

int CountNodes(TreeNode* root){
    if(!root){
        return 0;
    }else{
        int count = 1;
        count += CountNodes(root->left);
        count += CountNodes(root->right);
        return count;
    }
}

void PrintNode(TreeNode* root){
    cout << root->data << " ";
}

void PreorderNode(TreeNode* root, void(*fct)(TreeNode* root)){
    if(root != nullptr){
        (*fct)(root);
        PreorderNode(root->left, fct);
        PreorderNode(root->right, fct);
    }
}

void InorderNode(TreeNode* root, void(*fct)(TreeNode* root)){
    if(root != nullptr){
        InorderNode(root->left, fct);
        (*fct)(root);
        InorderNode(root->right, fct);
    }
}

void PostorderNode(TreeNode* root, void(*fct)(TreeNode* root)){
    if(root != nullptr){
        PostorderNode(root->left, fct);
        PostorderNode(root->right, fct);
        (*fct)(root);
    }
}

int MaxDepthTree(TreeNode* root){
    if(root == nullptr){
        return 0;
    }else if((root->left == nullptr) && (root->right == nullptr)){
        return 0;
    }else{
        //compute the depth of each subtree
        int leftDepth = MaxDepthTree(root->left);
        int rightDepth = MaxDepthTree(root->right);
        //use the larger subtree
        if(leftDepth > rightDepth){
            return leftDepth + 1;
        }else{
            return rightDepth + 1;
        }
    }
}

int GetNumberNodesGivenLevel(TreeNode* root, int level){
    if(root != nullptr){
        if(level ==0){
            return 1;
        }else{
            return GetNumberNodesGivenLevel(root->left, level -1) + 
                    GetNumberNodesGivenLevel(root->right, level -1);
        }
    }else{
        return 0;
    }
}

void GetNumberNodesLevel(TreeNode* root){
    int h = MaxDepthTree(root);
    int i;
    for(i = 0; i <= h; i++){
        cout << "level: " << i << " with "
            << GetNumberNodesGivenLevel(root, i) << " nodes" << endl;
    }
}

TreeNode* InvertTreeNode(TreeNode* root){
    if(root == nullptr){
        return nullptr; //no nodes
    }
    auto left = InvertTreeNode(root->left); //invert left sub tree
    auto right = InvertTreeNode(root->right); //invert right sub tree
    root->left = right; //put right on left
    root->right = left; //put left on right
    return root;
}

void InsertNode(TreeNode** root, MyType data){
    if((*root) == nullptr){
        (*root) = new TreeNode(data);
    }else if((*root)->data == data){
        InsertNode(&((*root)->left), data);
    }else{
        InsertNode(&((*root)->right), data);
    }
}

void InsertNode1(TreeNode* &root, MyType data){
    if(root == nullptr){
        root = new TreeNode(data);
    }else if(root->data == data){
        cout << "Value already in the tree." << endl;
    }else if(data < root->data){
        InsertNode1(root->left, data);
    }else{
        InsertNode1(root->right, data);
    }
}

bool SearchNodeR(TreeNode* root, MyType data){
    if(root == nullptr){
        return false;
    }
    else if(root->data == data){
        return true;
    }
    else if(data < root->data){
        return SearchNodeR(root->left, data);
    }
    else{
        return SearchNodeR(root->right, data);
    }
}


TreeNode* FindMinNode(TreeNode *root){
    if(root == nullptr){
        return nullptr;
    }
    if(root->left != nullptr){
        return FindMinNode(root->left); //left is smaller
    }
    return root;
}

TreeNode* DeleteNode(TreeNode *root, MyType data){
    if(root == nullptr){
        return nullptr;
    }
    if(data < root->data){
        root->left = DeleteNode(root->left, data);
    }else if(data > root->data){
        root->right = DeleteNode(root->right, data);
    }else{
        //case 1 no children
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            root = nullptr;
        }else if(root->left == nullptr){
            TreeNode *temp = root;
            root = root->right;
            delete temp;
        }else if(root->right == nullptr){
            TreeNode *temp = root;
            root = root->left;
            delete temp;
        }else{
            //find minial value of right sub tree
            TreeNode *temp = FindMinNode(root->right);
            root->data = temp->data; //duplicate node
            //Delete the duplicate node
            root->right = DeleteNode(root->right, temp->data);
        }
    }
    return root;
}

TreeNode* RightRotate(TreeNode* root){
    if(root == nullptr || root->left == nullptr) return root;
    TreeNode* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    return newRoot;
}

TreeNode* LeftRotate(TreeNode* root){
    if(root == nullptr || root->right == nullptr) return root;
    TreeNode* newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    return newRoot;
}

int FindMinTree(TreeNode *root){
    if(root == nullptr){
        return INT_MAX; //or undefined
    }
    if(root->left != nullptr){
        return FindMinTree(root->left);
    }
    return root->data;
}

int FindMaxTree(TreeNode *root){
    if(root == nullptr){
        return INT_MAX;
    }
    if(root->right != nullptr){
        return FindMaxTree(root->right);
    }
    return root->data;
}

int FindPredecessor(TreeNode* root){
    if(!root || !root->left){
        return INT_MIN;
    }
    TreeNode* curr = root->left;
    while(curr->right){
        curr = curr->right;
    }
    return curr->data;
}

int FindSuccessor(TreeNode* root){
    if(!root || !root->right){
        return INT_MIN;
    }
    TreeNode* curr = root->right;
    while(curr->left){
        curr = curr->left;
    }
    return curr->data;
}

void PrintPreorderNode(TreeNode* root, int lvl){
    if(root != nullptr){
        cout << root->data << " (" << lvl << ")" << endl;
        PrintPreorderNode(root->left, lvl + 1);
        PrintPreorderNode(root->right, lvl + 1);
    }
}

void PrintInorderNode(TreeNode* root, int lvl){
    if(root != nullptr){
        PrintInorderNode(root->left, lvl + 1);
        cout << root->data << " (" << lvl << ")" << endl;
        PrintInorderNode(root->right, lvl + 1);
    }
}
//
void PrintPostorderNode(TreeNode* root, int lvl){
    if(root != nullptr){
        PrintPostorderNode(root->left, lvl + 1);
        PrintPostorderNode(root->right, lvl + 1);
        cout << root->data << " (" << lvl << ")" << endl;
    }
}

void PrintGivenLevel(TreeNode* root, int lvl){
    if(root != nullptr){
        if(lvl == 0){
            cout << "_" << root->data << "_";
        }else{
            PrintGivenLevel(root->left, lvl -1);
            PrintGivenLevel(root->right, lvl -1);
        }
    }
}

void PrintLevelOrder(TreeNode* root){
    int h = MaxDepthTree(root);
    int i;
    for(i = 0; i <= h; i++){
        PrintGivenLevel(root, i);
        //at each line we have max 2^h
        cout << endl;
    }
}

tuple<TreeNode*, int, int, int> getStats(TreeNode* root){
    if(!root){
        return make_tuple(root, INT_MIN, INT_MIN, INT_MAX);
    }
    return make_tuple(
            FindMinNode(root),
            FindMaxTree(root), 
            FindPredecessor(root), 
            FindSuccessor(root)
        );
}

bool IsBST(TreeNode* node, int min, int max){
    if(!node){
        return true;
    }
    if(node->data<min || node->data>max){
        return false;
    }
    return (IsBST(node->left, min, node->data -1 ) &&
         IsBST(node->right, node->data + 1, max));
}


class MyBST{
    public:
        MyBST(){ root = nullptr; }
        ~MyBST(){ DestroyTree(root); }

        void Insert(int data) { InsertNode1(root, data);}
        void Insert1(int data){ InsertNode1(root, data);}

        void Delete(int data){ root = DeleteNode(root, data);}

        void Preorder(void(*fct)(TreeNode* root)) { PreorderNode(root, fct);}
        void Inorder(void(*fct)(TreeNode* root)){ InorderNode(root, fct);}
        void PostOrder(void(*fct)(TreeNode* root)) { PostorderNode(root,fct);}

        void PrintPreorder(){ PrintPreorderNode(root , 0); }
        void PrintInorder(){ PrintInorderNode(root, 0);}
        void PrintPostorder(){ PrintPostorderNode(root, 0);}
        void PrintLevelorder(){ PrintLevelOrder(root);}
        void PrintGetNumberNodesLevel(){ GetNumberNodesLevel(root);}

        void InverTree() { InvertTreeNode(root);} 
        int Height() { return MaxDepthTree(root);}
        int size(){ return CountNodes(root);}
        void RotateRight() { root = RightRotate(root);}
        void RotateLeft() { root = LeftRotate(root);}

        int IsBSTv2() { return(IsBST(root, INT_MIN, INT_MAX));}
        tuple<TreeNode*, int, int, int> BSTStats(){return getStats(root);}

    private:   
        TreeNode* root; //pointer to the root


};

void TestRotation(const string& name, const vector<int>& elements) {
    cout << "\nTesting sequence: " << name << endl;
    MyBST t;
    for (int val : elements) {
        t.Insert(val);
    }
    
    cout << "Before rotation:" << endl;
    t.PrintLevelorder();
    
    // Determine which rotation is needed
    if (elements.size() == 3) {
        if (elements[1] < elements[0] && elements[2] > elements[0]) {
            // Left-Right case (needs right then left)
            cout << "\nAfter right rotation on root:" << endl;
            t.RotateRight();
            t.PrintLevelorder();
        } else if (elements[1] > elements[0] && elements[2] < elements[0]) {
            // Right-Left case (needs left then right)
            cout << "\nAfter left rotation on root:" << endl;
            t.RotateLeft();
            t.PrintLevelorder();
        } else if (elements[1] < elements[0] && elements[2] < elements[0]) {
            // Left-Left case (needs single right)
            cout << "\nAfter right rotation on root:" << endl;
            t.RotateRight();
            t.PrintLevelorder();
        } else if (elements[1] > elements[0] && elements[2] > elements[0]) {
            // Right-Right case (needs single left)
            cout << "\nAfter left rotation on root:" << endl;
            t.RotateLeft();
            t.PrintLevelorder();
        }
    }
}

int main(){
    /*
    TreeNode* n = nullptr;
    InsertNode1(n, 50);
    InsertNode1(n, 25);
    InsertNode(&n, 75);
    InsertNode(&n, 5);
    InsertNode(&n, 15);
    InsertNode(&n, 65);
    InsertNode(&n, 85);
    void (*fct)(TreeNode*) = PrintNode;
    PreorderNode(n, fct);
    */
    
    MyBST* t = new MyBST();
    t->Insert(10);
    t->Insert(5);
    t->Insert(15);
    t->Insert(2);
    t->Insert(7);
    t->Insert(12);
    t->Insert(20);
    void(*fct)(TreeNode*) = PrintNode;
    cout << "Print Pre-order: " << endl;
    t->Preorder(fct);
    cout << "MaxDepth: " << t->Height() << endl;
    cout << "Print Pre-order: " << endl;
    t->PrintPreorder();
    cout << "Print In-order: " << endl;
    t->PrintInorder();
    cout << "Print Post-order: " << endl;
    t->PrintPostorder();
    cout << "Print Level-order: " << endl;
    t->PrintLevelorder();
    cout << "Number of nodes per level: " << endl;
    t->PrintGetNumberNodesLevel();
    cout << "Is BST: " << (t->IsBSTv2() ? "Yes" : "No") << endl;

    auto stats = t->BSTStats();
    cout << "Min: " << get<0>(stats)->data << endl;
    cout << "Max: " << get<1>(stats) << endl;
    cout << "Predecessor of root: " << get<2>(stats) << endl;
    cout << "Successor of root: " << get<3>(stats) << endl;
    delete t;
    
   /*
    TestRotation("20,10,15", {20, 10, 15});
    TestRotation("10,5,1", {10, 5, 1});
    TestRotation("10,20,30", {10, 20, 30});
    TestRotation("10,20,50", {10, 20, 50});
    */

    return 0;
}