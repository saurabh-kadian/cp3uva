// UVa 10305 - Ordering Tasks
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<(i==len-1?"":" ");cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

int main(){
    // int t;
    // cin >> t;
    int nodes, edges;
    cin >> nodes >> edges;
    while(true){
        if(nodes == 0 && edges == 0)
            break;

        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(nodes, 0);
        for(int i = 0; i < edges;++i){
            int u, v;
            cin >> v >> u;
            v--, u--;
            adjList[v].push_back(u);
            indegree[u] += 1;
        }
        queue<int> bfsQueue;
        for(int i = 0;i < nodes;++i)
            if(indegree[i] == 0)
                bfsQueue.push(i);
        vector<int> order;
        while(!bfsQueue.empty()){
            int node = bfsQueue.front();
            bfsQueue.pop();
            order.push_back(node + 1);
            for(auto neighbour : adjList[node]){
                indegree[neighbour] -= 1;
                if(indegree[neighbour] == 0)
                    bfsQueue.push(neighbour);
            }
        }
        debug(order, order.size());
        cin >> nodes >> edges;
    }
    return 0;
}
