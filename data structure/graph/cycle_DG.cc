#include <iostream>
#include <list>

using namespace std;

class Graph{
    int V;
    list<int> *adj;

    public:
        Graph(int n) {
            V = n;
            adj = new list<int>[n];
        }

        void AddEdge(int src, int dest){
            adj[src].push_back(dest);
        }

        bool IsCycle(int node, bool* visited, bool* stackArr){
            if (!visited[node]) {
                visited[node] = true;
                stackArr[node] = true;

                for(list<int>::iterator it = adj[node].begin();
                        it != adj[node].end(); ++it){
                    if (!visited[*it] && IsCycle(*it, visited, stackArr))
                        return true;
                    else if (stackArr[*it]) return true;
                }
            }

            stackArr[node] = false;
            return false;
        }

        void DectCycle(){
            bool *visited = new bool[V];
            bool *stackArr = new bool[V];
    
            for (int i = 0; i < V; i++) {
                visited[i] = false;
                stackArr[i] = false;
            }

            bool flag = false;

            for (int i = 0; i < V; i++)
                if((flag = IsCycle(i, visited, stackArr))) break;

            if (flag) cout << "Contains a cycle" << endl;
            else cout << "No cycle" << endl;
        }
};

int main(){
    Graph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    //g.AddEdge(2, 0);
    g.AddEdge(2, 3);
    //g.AddEdge(3, 3);
    g.DectCycle();

    return 0;
}
