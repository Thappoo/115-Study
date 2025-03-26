#include <iostream>
#include <cstring>

using namespace std;

typedef double MyType;
class SkipNode{
    public:
        SkipNode() : next(nullptr), data(0){};
        SkipNode **next;
        MyType data;
        int level;
        SkipNode(MyType x, int level1){
            data = x;
            level = level1;
            next = new SkipNode*[level + 1];
            //fill the next array w/ null
            memset(next, 0, sizeof(SkipNode*)*(level + 1));
        }
};

class MySkipList{
    public:
        MySkipList(){
            MaxLvl = 4;
            P = 0.5;
            level = 0;
            head = new SkipNode(-1, MaxLvl);
        }

        MySkipList(int MAXLVL1, float P1){
            MaxLvl = MAXLVL1;
            P = P1;
            level = 0;
            //-1 for smallest value
            head  = new SkipNode(-1, MaxLvl);
        }

        ~MySkipList(){
            SkipNode *current = head;
            while(current){
                SkipNode *next = current->next[0];
                delete current;
                current = next;
            }
        }

        int RandomLevel(){
            float r = (float)rand()/RAND_MAX;
            int lvl = 0;
            while(r < P && lvl < MaxLvl){
                lvl++;
                r = (float)rand()/RAND_MAX;
            }
            return lvl;
        }

        void Insert(MyType x){
            SkipNode *current  = head;
            SkipNode **update = new SkipNode*[MaxLvl + 1];
            memset(update, 0, sizeof(SkipNode*)*(MaxLvl + 1));
            for(int i = level; i >= 0; i--){
                while(current->next[i] != nullptr && 
                        current->next[i]->data < x){
                            current = current->next[i];
                        }
                update[i] = current;
            }
            current = current->next[0];
            if(current == nullptr || current->data != x){
                int rlevel = RandomLevel();
                if(rlevel > level){
                    for(int i = level + 1; i < rlevel + 1; i++){
                        update[i] = head;
                    }
                    level = rlevel;
                }
                SkipNode* n = new SkipNode(x, rlevel);
                for(int i = 0; i <= rlevel; i++){
                    n->next[i] = update[i]->next[i];
                    update[i]->next[i] = n;
                }
            }
        }

        void Delete(MyType x){
            SkipNode *current = head;
            SkipNode **update = new SkipNode*[MaxLvl + 1];
            memset(update, 0, sizeof(SkipNode*)*(MaxLvl + 1));
            for(int i = level; i >= 0; i--){
                while(current->next[i] != nullptr &&
                    current->next[i]->data < x){
                        current = current->next[i];
                    }
                update[i] = current;
            }
            if(current->next[0] != nullptr){
                current = current->next[0];
                if(current->data == x){
                    for(int i = 0; i <= current->level;i++){
                        update[i]->next[i] = current->next[i];
                    }
                    delete current;
                }
            }
        }
        bool Search(MyType x){
            SkipNode* current = head;
            SkipNode **update = new SkipNode*[MaxLvl + 1];
            memset(update, 0, sizeof(SkipNode*)*(MaxLvl + 1));
            for(int i = level; i >= 0; i--){
                while(current->next[i] != nullptr &&
                        current->next[i]->data < x){
                            current = current->next[i];
                        }
                update[i] = current;
            }
            if(current->next[0] == nullptr){
                return false; //not found
            }
            if(current->next[0]->data == x){
                return true; //found
            }
            return false;//not found after both if cases
        }

        void Display(){
            for(int i = 0; i <= level; i++){
                SkipNode *node = head->next[i];
                cout << "Level " << i << endl;
                while(node != nullptr){
                    cout << node->data << " ";
                    cout << "(" << node->level << ")";
                    node = node->next[i];
                }
                cout << endl;
            }
        }
        void DisplayFile();
    
    private:
        int RandomLevel();
        int MaxLvl;
        float P;
        //current level of skip list
        int level;
        SkipNode *head;
};

int main(){
    MySkipList* s = new MySkipList(2,0.5);
    s->Insert(10);
    s->Insert(20);
    s->Insert(5);
    s->Insert(7);
    s->Insert(9);
    s->Insert(8);
    s->Insert(5);
    s->Insert(15);
    s->Insert(25);
    s->Insert(16);
    s->Insert(26);

    cout << s->Search(25) << endl;
    cout << s->Search(14) << endl;
    cout << s->Search(26) << endl;

    s->Display();
    s->Delete(15);
    s->Display();

    delete s;

}