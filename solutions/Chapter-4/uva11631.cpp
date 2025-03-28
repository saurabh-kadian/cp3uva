// UVa 11631 - Dark roads
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

class DSU{
    vector<int> parent;
    public:
        DSU(int size){
            parent.resize(size);
            for(int i = 0;i < size;++i)
                parent[i] = i;            
        }
        int find(int x){
            return parent[x] = (parent[x] == x ? x : find(parent[x]));
        }
        void uni(int px, int py){
            parent[px] = py;
        }
};

int main(){
    int nodes, edges;
    cin >> nodes >> edges;
    while(nodes != 0 || edges != 0){
        int totalCost = 0;
        vector<pair<int, pair<int, int>>> edgeList(edges);
        for(int i = 0; i < edges;++i){
            int cost, u, v;
            cin >> u >> v >> cost;
            totalCost += cost;
            edgeList[i] = make_pair(cost, make_pair(u, v));
        }
        sort(edgeList.begin(), edgeList.end());
        DSU dsu(nodes);
        int minCost = 0;
        for(auto edge : edgeList){
            int u = edge.second.first, v = edge.second.second;
            int px = dsu.find(u), py = dsu.find(v);
            if(px == py)    continue;
            minCost += edge.first;
            dsu.uni(px, py);
        }
        cout << totalCost - minCost << endl;
        cin >> nodes >> edges;
    }
    return 0;
}
