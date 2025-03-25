// UVa 11080 - Place the guards
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

int totalCovered = 0;
int dfs(int node, bool hasGuard, unordered_map<int, vector<int>>& adjList, vector<bool>& visited, vector<int>& color){
    visited[node] = true;
    totalCovered += 1;
    int guards = hasGuard;
    for(auto neighbour : adjList[node]){
        if(color[neighbour] == color[node])
            return -1e6;
        if(!visited[neighbour]){
            color[neighbour] = !color[node];
            guards += dfs(neighbour, !hasGuard, adjList, visited, color);
        }
    }
    return guards;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        int nodes, edges;
        cin >> nodes >> edges;
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
        int answer = 0;
        bool isColorable = true;
        for(int node = 0;node < nodes;++node){
            if(visited[node])   continue;
            int total = 0;
            int zero = 0;
            bfsQueue.push(node);
            color[node] = 0;
            visited[node] = true;
            while(!bfsQueue.empty()){
                int frontNode = bfsQueue.front();
                total += 1;
                if(color[frontNode] == 0)   zero += 1;
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
            // cout << "XX: " << zero << " " << total - zero << endl;
            answer += max(1, min(total - zero, zero));
        }
        cout << (isColorable ? answer : -1) << endl;
        
    }
    return 0;
}