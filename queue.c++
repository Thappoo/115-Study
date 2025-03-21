#include <iostream>
#include <algorithm>

using namespace std;

typedef double MyType;
class MyQueue{
    public:
        MyQueue(){
            capacity = 0;
            front = size = 0;
            rear = capacity -1;
            q = nullptr;
        }
        ~MyQueue(){
            delete [] q;
        }

        MyQueue(int capacity1){
            capacity = capacity1;
            front = size = 0;
            rear = 0;
            q = new MyType[capacity];
        }

        bool IsFull(){
            return (size == capacity);
        }

        bool IsEmpty(){
            return (size == 0);
        }

        void Enqueue(MyType x){
            if(!IsFull()){
                q[rear] = x;
                rear = (rear + 1) % capacity;
                size = size + 1;
            }else{
                cout << "Impossible to Enqueue " << x << " Queue is full" << endl;
            }
        }

        MyType Dequeue(){
            if(IsEmpty()){
                return INT_MIN;
            }
            MyType item = q[front];
            front = (front + 1) % capacity;
            size = size - 1;
            return item;
        
        }

        MyType Front(){
            if(IsEmpty()){
                return INT_MIN;
            }
            return q[front];
        }

        MyType Rear(){
            if(IsEmpty()){
                return INT_MIN;
            }
            return q[rear];
        }
        void DisplayQueue(){
            cout << "Size: " << size << endl;
            for(int i = 0; i < size; i++){
                cout << "Element: " << q[i] << " at position " << i << endl;
            }
            cout << endl;
        }

    private:
        int front, rear, size;
        int capacity;
        MyType* q;
};

int main(){

    MyQueue* Q = new MyQueue(10);
    Q->Enqueue(4);
    Q->Enqueue(6);
    Q->Enqueue(8);
    Q->Enqueue(10);
    Q->Enqueue(12);
    Q->Enqueue(16);
    Q->Enqueue(18);
    Q->DisplayQueue();
    cout << "Dequeue: " << Q->Dequeue() << endl;
    cout << "Dequeue: " << Q->Dequeue() << endl;
    Q->Enqueue(20);
    Q->Enqueue(22);
    Q->Enqueue(24);
    Q->Enqueue(26);
    Q->DisplayQueue();
    cout << "Dequeue: " << Q->Dequeue() << endl;
    cout << "Dequeue: " << Q->Dequeue() << endl;
    Q->Enqueue(28);
    Q->Enqueue(30);
    cout << "Dequeue: " << Q->Dequeue() << endl;
    cout << "Dequeue: " << Q->Dequeue() << endl;
    Q->DisplayQueue();
    return 0;
}