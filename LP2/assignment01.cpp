#include <bits/stdc++.h>
using namespace std;

class  Graph
{
    private:
        int V;
        list<int> *adj;
public:
    Graph(int v);
    void addEdge(int v, int w);
    void DFSIteratively(int s);
    void DFSRecursively(int s);
    void recursive(int v, vector<bool> &visited);
    void BFS(int s);
};

void Graph::DFSIteratively(int s) {
    vector<bool>visited(V, false);
    stack<int>st;
    st.push(s);
    while (!st.empty())
    {
        int s = st.top();
        st.pop();
        if (!visited[s])
        {
            cout << s << " ";
            visited[s] = true;
        }
        for(auto i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i])
                st.push(*i);
        }
    }
    cout<<endl;
}

Graph::Graph(int v)
{
    this->V = v;
    this->adj = new list<int>[v];
}
void Graph::addEdge(int v, int w) {
    if(v < 0 || v >= V || w < 0 || w >= V) {
        cout<<"Vertex Out Of Bound! v= " << v <<" w = "<< w<<endl;
        return;
    }
    adj[v].push_back(w);
    // if you want undirected graph uncomment this line
    // adj[w].push_back(v);
}
void Graph::recursive(int v, vector<bool>&visited) {
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            recursive(*i, visited);
}
void Graph::DFSRecursively(int s) {
    vector<bool>visited(V, false);
    recursive(s, visited);
}

void Graph::BFS(int s) {
    vector<bool>visited(V, false);
    list<int>queue;
    visited[s] = true;
    queue.push_back(s);
    while (!queue.empty()) {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for(auto i = adj[s].begin(); i != adj[s].end(); ++i) {
            if(!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    cout<<endl;
}

int main () {
    Graph g(5); // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    cout << "Following is Depth First Traversal\n";
    g.DFSIteratively(0);
    cout << "Following is Depth First Traversal Recursively\n";
    g.DFSRecursively(0);
    cout<<endl;
    cout << "Following is Breadth First Traversal\n";
    g.BFS(0);
    return 0;
}