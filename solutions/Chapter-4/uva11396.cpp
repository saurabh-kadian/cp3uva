// UVa 11396 - Claw Decomposition
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
        unordered_map<int, vector<int>> adjList;
        while(true){
            int u,v;
            cin >> u >> v;
            if(u ==0 && v == 0)
                break;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        // bfs
        vector<int> visited(nodes + 1, false);
        vector<int> color(nodes + 1, -1);
        queue<int> bfsQueue;
        bfsQueue.push(1);
        color[1] = 0;
        visited[1] = true;
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
        cout << (isColorable ? "YES" : "NO") << endl;
        cin >> nodes;
    }
    return 0;
}