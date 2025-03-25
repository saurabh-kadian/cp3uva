// UVa 10004 - Bicoloring
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

int main(){
    ll nodes;
    cin >> nodes;
    while(nodes != 0){
        int edges;
        cin >> edges;
        unordered_map<int, vector<int>> adjList;
        for(int edge = 0;edge < edges;++edge){
            int u,v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        // bfs
        vector<int> visited(nodes, false);
        vector<int> color(nodes, -1);
        queue<int> bfsQueue;
        bfsQueue.push(0);
        color[0] = 0;
        visited[0] = true;
        bool isColorable = true;
        while(!bfsQueue.empty()){
            int frontNode = bfsQueue.front();
            bfsQueue.pop();
            for(auto neighbour : adjList[frontNode]){
                if(color[neighbour] == color[frontNode]){
                    isColorable = false;
                    break;
                }
                if(!visited[neighbour]){
                    bfsQueue.push(neighbour);
                    visited[neighbour] = true;
                    color[neighbour] = !color[frontNode];
                }
            }
        }
        cout << (isColorable ? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
        cin >> nodes;
    }
    return 0;
}