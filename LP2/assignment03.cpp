#include <bits/stdc++.h>
using namespace std;

class Prims
{
private:
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
    // TC:- O(n^2) + o (n+e)
    void PrimsBrute() {
        int parent[N]; 
        int key[N];
        int mstSet[N];
        for(int i = 0; i < N; i++) {
            key[i] = INT_MAX;
            mstSet[i] = false;
            parent[i] = -1;
        }
        key[0] = 0;
        for(int count = 0; count < N - 1; count++) { // since spanning tree has n-1 edges
            int min = INT_MAX;
            int u; // this will be the minimum key node which will be included in mst
            for(int v = 0; v < N; v++) {
                if(mstSet[v] == false && key[v] < min) {
                    min = key[v];
                    u = v;
                }
            }
            mstSet[u] = true; // included in mst
            for(auto it : adj[u]) { // for all the adjacent nodes of u
                int v = it.first; // adjaceny node
                int w = it.second; //cost
                if(mstSet[v] == false && w < key[v]) {
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }
        for(int i = 1; i < N; i++) {
            cout<<"Parent of "<< i << " is "<<parent[i]<< " with cost "<<key[i]<<endl;
        }
    }
    // TC:- O(nlog(n)) + o (n+e)
    void PrimsEfficient() {
        int parent[N]; 
        int key[N];
        int mstSet[N];
        for(int i = 0; i < N; i++) {
            key[i] = INT_MAX;
            mstSet[i] = false;
            parent[i] = -1;
        }

        priority_queue< pair<int, int>, vector< pair<int, int>>, greater< pair<int,int>> > pq;

        key[0] = 0;
        pq.push({0, 0});
        for(int count = 0; count < N - 1; count++) { // since spanning tree has n-1 edges
            int u = pq.top().first;
            pq.pop();
            mstSet[u] = true; // included in mst
            for(auto it : adj[u]) { // for all the adjacent nodes of u
                int v = it.first; // adjaceny node
                int w = it.second; //cost
                if(mstSet[v] == false && w < key[v]) {
                    parent[v] = u;
                    pq.push({ v, key[v] });
                    key[v] = w;
                }
            }
        }
        for(int i = 1; i < N; i++) {
            cout<<"Parent of "<< i << " is "<<parent[i]<< " with cost "<<key[i]<<endl;
        }
    }
    
};


int main () {
    Prims g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 3);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 4, 7);
    cout<<"Using Burte force:\n";
    g.PrimsBrute();
    cout<<"Using Efficient Algorithm:\n";
    g.PrimsEfficient();
    return 0;
}