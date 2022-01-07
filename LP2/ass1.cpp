#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    bool *visited = new bool[V];

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
    void DFS(int s);
    void setVisited()
    {
        for (int i = 0; i < V; i++)
            visited[i] = false;
    }
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int s)
{
    visited[s] = true;
    cout << s << " ";
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

void Graph::BFS(int s)
{
    for (int i = 0; i < V; i++)
        visited[i] = false;
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    list<int>::iterator i;

    while (!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    cout << endl;
}

int main()
{
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);
    int ch;
    int v, w, s;
    bool flag = true;
    while (flag)
    {
        cout << "1. Add Edge\n";
        cout << "2. BFS\n";
        cout << "3. DFS\n";
        cout << "4. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter start and end vertex: ";
            cin >> v >> w;
            g.addEdge(v, w);
            break;
        case 2:
            cout << "Enter Start Vertex: ";
            cin >> s;
            g.BFS(s);
            break;
        case 3:
            cout << "Enter Start Vertex: ";
            cin >> s;
            g.setVisited();
            g.DFS(s);
            cout << endl;
            break;
        case 4:
            flag = false;
            break;
        default:
            cout << "invalid Input\n";
            break;
        }
    }
    return 0;
}
