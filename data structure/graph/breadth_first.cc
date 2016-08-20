#include <iostream>
#include <list>

using namespace std;

class Graph{
    private:
        int V;
        list<int> *adj;
    public:
        Graph(int v){
            V = v;
            adj = new list<int>[v];
        }

        void AddEdge(int src, int dest){
            adj[src].push_back(dest);
        }

        void BFS(int start){
            bool *visited = new bool[V];

            for (int i = 0; i < V; i++)
                visited[i] = false;

            list<int> queue;

            queue.push_back(start);
            visited[start] = true;

            while(!queue.empty()){
                int n = queue.front();
                queue.pop_front(); 
                cout << n << " ";

                for(list<int>::iterator it = adj[n].begin();
                        it != adj[n].end(); it++) {
                    if (!visited[*it]) {
                        visited[*it] = true;
                        queue.push_back(*it);
                    }
                }
            }
            cout<<endl;
        }

        void DFSUtil(int v, bool *visited){
            visited[v] = true;
            cout << v << " ";

            for(list<int>::iterator it = adj[v].begin();
                    it != adj[v].end(); it++){
                if(!visited[*it]) DFSUtil(*it, visited); 
            }
        }

        void DFS(int start){
            bool *visited = new bool[V];
            for(int i = 0; i < V; i++) visited[i] = false;

            DFSUtil(start, visited);
            cout << endl;
        }
};

int main(){

    Graph g(4);
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 0);
    g.AddEdge(2, 3);
    g.AddEdge(3, 3);
 
    int start;
    cin >> start;
    cout << "Following is Breadth First Traversal (starting from vertex " <<  start << ")\n";
    g.BFS(start);

    cout << "Following is Depth First Traversal (starting from vertex " << start << ") \n";
    g.DFS(start);
}
