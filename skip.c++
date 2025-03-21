#include <iostream>

using namespace std;

typedef double MyType;
class SkipNode{
    public:
        SkipNode() : next(nullptr), data(0){};
        SkipNode **next;
        MyType data;
        int level;
};

class MySkipList{
    public:
        MySkipList();
        MySkipList(int MAXLVL, float P);
        ~MySkipList();
        void Insert(MyType x);
        void Delete(MyType x);
        bool Search(MyType x);
        void Display();
        void DisplayFile();
    
    private:
        int RandomLevel();
        int MaxLvl;
        float P;

        int level;
        SkipNode *head;
};

int main(){

}