#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct Edge{
    int from, to, cost;
    Edge(int from, int to, int cost){
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
};


class Prims{
    int N;
    vector<pair<int, int>> *adj;
public:
    Prims(int N){
        this->N = N;
        adj = new vector<pair<int, int>>[N];
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void findMST(){
        priority_queue<pii, vector<pii>, greater<pii>> pq; // (distance, node) pair
        vector<bool> visited(N, false);
        int edgeCount = 0, minCostSum = 0;
        vector<int> parent(N, -1), weight(N, INT_MAX);

        pq.push({0, 0});
        weight[0] = 0;

        while (!pq.empty() || edgeCount!=N-1)
        {
            minCostSum += pq.top().first;
            int nodeIndex = pq.top().second;
            pq.pop();   // fetch next most promising  min {dist, node} pairs
            visited[nodeIndex] = true;

            for(auto edge : adj[nodeIndex]){
                int to = edge.first;
                int cost = edge.second;
                if(!visited[to] && cost < weight[to]){
                    edgeCount++;
                    parent[to] = nodeIndex;
                    weight[to] = cost;
                    pq.push({cost, to});
                }
            }
        }

        // Check if MST spans entire graph or not
        bool mstExists = (edgeCount == N-1);
        if(!mstExists) return;

        cout << "\nCost of MST: " << minCostSum << endl ;
        for(int i=1; i<N; i++){
            cout << parent[i] << " to " << i << " with cost " << weight[i] << "\n";
        }
    }
};


int main(){
    Prims g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 3);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 4, 7);
    g.findMST();
}
