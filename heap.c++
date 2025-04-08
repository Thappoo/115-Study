#include <iostream>

using namespace std;

typedef int Mytype;
class MyMaxHeap{
    public:
        MyMaxHeap(){
            n = 0;
            a = nullptr;
            heap = true;
        }

        ~MyMaxHeap(){
            delete[] a;
        }

        void InitArray(int n1){
            if(n1 > 0){
                delete[] a;
                n = n1;
                a = new Mytype[n];
                for(int i = 0; i < n; i++){
                    a[i] = rand() % 200;
                }
            }
        }

        void InitHeap(int n1){
            InitArray(n1);
            BuildMaxHeap();
        }

        void MaxHeapify(int i, int size){
            int left, right, largest;
            left = 2 * i + 1; //left child of a[i]
            right = 2 * i + 2; //right child of a[i]
            largest = i; //original largest element
            if((left<size) && a[left] > a[i]){
                largest = left;
            }
            if((right<size) && (a[right] > a[largest])){
                largest = right;
            }
            if(largest != i){
                swap(a[i], a[largest]);
                MaxHeapify(largest, size);
            }
        }

        bool IsSorted(){
            if(n <= 1){
                return true;
            }
            else{
                int i = 1;
                while((a[i - 1] <= a[i]) && (i < n)){
                    i++;
                }
                return (i == n);
            }
        }

        bool IsMaxHeap(){
            bool isheap = true;
            int left, right;
            int i = 0;
            for(int i = 0; (i < n) && isheap; i++){
                left = 2 * i + 1;
                right = 2 * i + 2;
                if((left < n) && a[left] > a[i]){
                    isheap = false;
                }
                if((right < n) && (a[right] > a[i])){
                    isheap = false;
                }
            }
            heap = isheap;
            return isheap;
        }
        void BuildMaxHeap(){
            //traverse the complete tree backwards
            //(right to left, bottom to top)
            for(int i = n/2 -1; i >= 0; i--){
                MaxHeapify(i, n);
            }
            heap = true;
        }

        void HeapSort(){
            //first build the maxheap
            BuildMaxHeap();
            
            for(int i = n -1; i > 0; i--){
                //a[0] always contains the max value
                swap(a[0], a[i]);

                MaxHeapify(0, i);
            }
            heap = false;
        }

        void InsertMaxHeap(int x){
            Mytype* a1 = new Mytype[n + 1];
            a1[0] = x;
            for(int i = 0; i < n; i++){
                a1[1 + i] = a[i];
            }
            delete [] a;
            a = a1;
            MaxHeapify(0, n+1);
            n++;
        }

        void DeleteMaxHeap(int x){
            int i = 0;
            int indx = 0;
            bool found = false;
            while((i < n) && (!found)){
                if(a[i] == x){
                    found = true;
                    indx = i;
                }
                i++;
            }
            if(found){
                Mytype* a1 = new Mytype[n - 1];
                a[indx] = a[n - 1];
                for(int i = 0; i < n - 1; i++){
                    a1[i] = a[i];
                }
                delete [] a;
                a = a1;
                MaxHeapify(indx, n - 1);
                n--;
            }
        }

        void Display(){
            for(int i = 0; i < n; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }

    private:
        Mytype* a;
        int n;
        bool heap;

};


int main(){
    int n = 10;
    MyMaxHeap* H = new MyMaxHeap();
    H->InitArray(n);
    cout << "Sorted: " << H->IsSorted() << endl;
    H->HeapSort();
    cout << "Sorted: " << H->IsSorted() << endl;
    H->BuildMaxHeap(); //need to build the heap first
    cout << "IsHeap: " << H->IsMaxHeap() << endl;
    H->Display();
    cout << "Insert.." << endl;
    H->InsertMaxHeap(99);
    H->Display();
    cout << "IsHeap: " << H->IsMaxHeap() << endl;
    cout << "Delete.." << endl;
    H->DeleteMaxHeap(99); 
    H->Display();
    cout << "IsHeap:" << H->IsMaxHeap() << endl;
    delete H;

    return 0;
}