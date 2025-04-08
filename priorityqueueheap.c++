#include <iostream>

using namespace std;

struct MyData{
    int index;
    double value;
};

class MyPriorityQueue{
    public:
        MyPriorityQueue(){
            capacity = 0;
            nelements = 0;
            queue = nullptr;
        }

        MyPriorityQueue(int c){
            capacity = c;
            nelements = 0;
            queue = new MyData[capacity];
        }

        ~MyPriorityQueue(){
            delete[] queue;
        }

        int GetNElements(){ return nelements; }

        bool IsEmpty(){
            return (nelements == 0);
        }

        bool IsFull(){
            return(nelements == capacity);
        }

        int GetParent(int child){
            if(child % 2 == 0){
                return (child/2) - 1;
            }else{
                return child/2;
            }
        }

        int GetLeftChild(int parent){
            return (2 * parent + 1);
        }

        int GetRightChild(int parent){
            return (2 * parent + 2);
        }

        void Push(int index, double value){
            if(nelements < capacity){
                MyData x;
                x.index = index;
                x.value = value;

                int i = nelements;
                while((i != 0) && (x.value < queue[i / 2].value)){
                    queue[i] = queue[i / 2];
                    i/=2;
                }
                queue[i] = x;
                nelements++;
                cout << "Added (" << index 
                        << "," << value << ") size="
                        << nelements << endl;
            }
            else{
                cout << "Out of capacity" << endl;
            }
        }

        MyData Pop(){
            if(nelements > 0){
                MyData tmp = queue[0];
                queue[0] = queue[nelements - 1];
                MinHeapify(0, nelements);
                nelements--;
                return tmp;
            }
            else{
                MyData tmp;
                tmp.value = 0;
                tmp.index = -1;
                return tmp;
            }
        }
        void DecreaseKey(int index, double value);

        void MinHeapify(int i, int size){
            int left, right, smallest;
            left = 2 * i + 1;
            right = 2 * i + 2;
            smallest = i;
            if((left < size) && (queue[left].value < queue[smallest].value)){
                smallest = left;
            }
            if(smallest != i){
                swap(queue[i], queue[smallest]);
                MinHeapify(i, nelements);
            }
        }
        void BuildMinHeap(){
            for(int i = nelements / 2 -1; i >= 0; i--){
                MinHeapify(i, nelements);
            }
        }

        void Display(){
            cout<<"Priority Queue" << endl;
            cout << "\t capacity: " << endl;
            cout << "\t nelements: " << endl;
            for(int i = 0; i < nelements; i++){
                cout << i << ": (" << queue[i].value << ")" << endl;
            }
            cout << endl;
        }

    private:
        void MinHeapify(int i, int size);
        int capacity;
        int nelements;
        MyData* queue;
};

int main(){

    return 0;
}