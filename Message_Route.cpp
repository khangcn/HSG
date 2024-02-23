#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n,m;
vector <int> adj[N];
bool visited[2*N];
int parent[N];
void BFS(int u){
    queue <int> q;
    visited[u] = true;
    q.push(u);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto x : adj[v]){
            if (!visited[x]){
                parent[x] = v;
                visited[x] = true;
                q.push(x);
            }
        }
    }
}
void connect(){
    memset(visited,false,sizeof visited);
    memset(parent,0, sizeof parent);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i]){
            BFS(i);
        }   
    }
    for (int i = 0; i < N; i++)
    {
        if (parent[i] != 0){
            cout << parent[i];
        }
    }     
}
int main(){
    freopen("Route.inp","r",stdin);
    freopen("Route.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    connect();   
}