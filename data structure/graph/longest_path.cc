#include <iostream>
#include <stack>
#include <list>
#include <climits>

using namespace std;

class AdjListNode {
    int v;
    int weight;
public:
    AdjListNode(int _v, int _w) {
        v = _v;
        weight = _w;
    } 

    int getV() { return v; }
    int getWeight() { return weight; }
};

class Graph {
    int V;
    list<AdjListNode> *adj; 
    void TopologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);
    void addEdge(int src, int dest, int weight);
    void longestPath(int s);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<AdjListNode>[V];    
}

void Graph::addEdge(int src, int dest, int weight){
    AdjListNode node(dest, weight);
    adj[src].push_back(node);
}

void Graph::TopologicalSortUtil(int v, bool visited[], stack<int> &Stack) {
    visited[v] = true;

    for (list<AdjListNode>::iterator i = adj[v].begin(); i != adj[v].end();
            i++) {
        AdjListNode node = *i;
        if (!visited[node.getV()]) TopologicalSortUtil(node.getV(), visited, Stack); 
    }

    Stack.push(v);
}

void Graph::longestPath(int s) {
    stack<int> Stack;
    int dist[V];
    int parent[V];

    bool *visited  = new bool[V];
    for (int i = 0; i < V; i++) visited[i] = false; 

    for (int i = 0; i < V; i++) {
        if (!visited[i]) TopologicalSortUtil(i, visited, Stack);
    }

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MIN;
        parent[i] = -1;
    }

    dist[s] = 0;

    while (!Stack.empty()) {
        int u = Stack.top();
        Stack.pop();

        if (dist[u] != INT_MIN) {
            for (list<AdjListNode>::iterator it = adj[u].begin();
                    it != adj[u].end(); it++) {
                if (dist[it->getV()] < dist[u] + it->getWeight()) {
                    dist[it->getV()] = dist[u] + it->getWeight();
                    parent[it->getV()] = u;
                }
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MIN) {
            cout << "NINF " << parent[i] << endl;        
        } else {
            cout << dist[i] << " ";
            cout << i << " ";
            int u = i;
            while (parent[u] != -1) {
                cout << parent[u] << " ";
                u = parent[u];
            }
            cout << endl;
        }
    }
}

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram.  Here vertex numbers are
    // 0, 1, 2, 3, 4, 5 with following mappings:
    // 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
 
    int s = 2;
    //cin >> s;
    cout << "Following are longest distances from source vertex " << s <<" \n";
    g.longestPath(s);
 
    return 0;
}
