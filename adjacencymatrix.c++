#include <iostream>

using namespace std;

class MyGraphAM{
    public:
        MyGraphAM(){
            n = 0;
            M = nullptr;
            current = nullptr;
        }

        MyGraphAM(int n1){
            n = n1;
            M = new double[n*n];
            for(int i = 0; i< n*n; i++){
                M[i] = 0;
            }
            current = new int[n];
            for(int i = 0; i < n; i++){
                current[i] = 0;
            }
        }

        ~MyGraphAM(){
            delete[] M;
            delete[] current;
        }

        int GetIndex(int u, int v){
            // u: source, v : destination
            return u*n + v;
        }

        bool ExistEdge(int u, int v){
            return (M[GetIndex(u,v)] != 0);
        }

        double GetEdgeWeight(int u, int v){
            return M[GetIndex(u,v)];
        }

        int GetDegree(int u){
            int degree = 0;
            for(int v = 0; v < n; v++){
                if(ExistEdge(u,v)){
                    degree++;
                }
            }
            return degree;
        }

        void SetDirectedEdge(int u, int v, double w){
            M[GetIndex(u,v)] = w;
        }

        void SetDirectedEdge(int u, int v){
            M[GetIndex(u,v)] = 1;
        }

        void SetUndirectedEdge(int u, int v, double w){
            M[GetIndex(u,v)] = w;
            M[GetIndex(v,u)] = w;
        }

        void SetUndirectedEdge(int u, int v){
            M[GetIndex(u, v)] = 1;
            M[GetIndex(v, u)] = 1;
        }

        void RemoveDirectedEdge(int u, int v){
            M[GetIndex(u, v)] = 0;
        }

        void RemoveUndirectedEdge(int u, int v){
            M[GetIndex(u, v)] = 0;
            M[GetIndex(v, u)] = 0;
        }

        bool HasSelfLoops(){
            int u = 0;
            while(u < n){
                if(M[GetIndex(u, u)] != 0){
                    return true;
                }
                u++;
            }
            return false;
        }

        bool IsUndirected(){
            int v, u = 0;
            while(u < n){
                v = u;
                while(v < n){
                    if(M[GetIndex(u , v)] != M[GetIndex(v, u)]){
                        return false;
                    }
                    v++;
                }
                u++;
            }
            return !HasSelfLoops();
        }

        void Display(){
            int k = 0;
            cout << " :";
            for(int v = 0; v < n; v++){
                cout << v << "\t";
            }
            cout << endl;
            for(int u = 0; u < n; u++){
                cout << u << ": ";
                for(int v = 0; v < n; v++){
                    cout << M[k] << "\t";
                    k++;
                }
                cout << endl;
            }
        }

        void DisplayDirectedEdge(){
            int k = 0;
            cout << "List of edges :" << endl;
            for(int u = 0; u < n; u++){
                for(int v = 0; v < n; v++){
                    if(ExistEdge(u,v)){
                        cout << "(" << u << ","
                        << v << ") w:" << GetEdgeWeight(u, v)
                        << endl;
                    }
                }
            }
        }

        void DisplayUndirectedEdge(){
            int k = 0;
            cout << "List of edges :" << endl;
            for(int u = 0; u < n; u++){
                for(int v = 0; v < n; v++){
                    if(ExistEdge(u,v)){
                        cout << "(" << u << ","
                        << v << ") w:" << GetEdgeWeight(u,v)
                        << endl;
                    }
                }
            }
        }
    
    private:
        int n; 
        double* M;
        int* current;
};

int main(){

    int n = 5;
    MyGraphAM* G = new MyGraphAM(n);
    G->SetUndirectedEdge(0, 1);
    G->SetUndirectedEdge(1, 2);
    G->SetUndirectedEdge(2, 3);
    G->SetUndirectedEdge(3, 0);
    G->SetUndirectedEdge(0, 4);
    G->SetUndirectedEdge(1, 4);
    G->Display();
    G->DisplayDirectedEdge();
    cout << "Removing an edge: " << endl;
    G->RemoveUndirectedEdge(3,0);
    G->Display();
    delete G;



}