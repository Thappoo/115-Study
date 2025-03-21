#include <iostream>

using namespace std;

typedef double MyType; //instead of writing double everytime just this. 
                    //can also help if you need to change double
                    //only this changes
class MyStack{
    public:
        MyStack(){ //constructor
            s = nullptr;
            capacity = 0;
            size = 0;
        }

        MyStack(int capacity1){ //creates the size of stack
            capacity = capacity1; //amaount of numbers in stack
            s = new MyType[capacity]; //creates the stack
            size = 0; //keeps count of size of stack
        }

        ~MyStack(){ //destructor
            delete[] s;
        }

        bool IsFull(){ //gets full
            return (size == capacity); //reads as if size equals capacity
        }

        bool IsEmpty(){ //is empty
            return (size == 0); 
        }

        MyType Pop(){ //pops
            if(!IsEmpty()){ //makes sure there is something to pop
                size--;
                return s[size];
            }
        }

        MyType Top(){
            return s[size - 1]; // allows you to see what is currently at the top
        }

        void Push(MyType x){ //adds to stack
            if (size < capacity){
                s[size] = x;
                size++;
            }
        }

        void Display(){
            cout << "Max capacity: " << capacity << endl;
            cout << "Size: " << size << endl;
            for(int i = 0; i < size; i++){
                cout << "Element: " << s[i] << " at position " << i << endl;
            }
            cout << endl;
        }


    private: 
        MyType* s;
        int capacity;
        int size;

};


int main(){
    MyStack* S = new MyStack(5);
    S->Push(4);
    S->Push(6);
    S->Push(8);
    S->Push(10);
    S->Push(12);
    S->Push(16);
    S->Push(18); // doestn get displayed bc capacity is full
    S->Display();
    cout << "Pop: " << S->Pop() << endl;
    cout << "Pop: " << S->Pop() << endl;
    cout << "Top: " << S->Top() << endl;
    S->Push(20);
    S->Display();
    delete S;

    return 0;
}