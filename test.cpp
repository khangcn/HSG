#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n,m,ans = 0;
vector <int> adj[N];
bool visited[2*N];
pair <int,int> connect[N];
void DFS(int u){
    visited[u] = true;
    for (auto v : adj[u]){
        if (!visited[v]){
            DFS(v);
        }
    }
}
void connected_component(){
    int j = 1;
    memset(visited,false,sizeof visited);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i]){
            ans++;
            connect[j] = make_pair(i-1,i);
            DFS(i);
        }
    }  
}
int main(){
    freopen("Road.inp","r",stdin);
    freopen("Road.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }  
    connected_component();
} 