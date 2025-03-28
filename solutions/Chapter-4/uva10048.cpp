// UVa 10048 - Audiophobia
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

pair<int, bool> dfs(int node, int parent, unordered_map<int, vector<pair<int, int>>>& adjList, int& destination){
    int maxPath = INT_MIN;
    if(node == destination)
        return make_pair(INT_MIN, true);
    bool foundPath = false;
    for(auto neighbour : adjList[node]){
        if(neighbour.first == parent)
            continue;
        pair<int, bool> isPath = dfs(neighbour.first, node, adjList, destination);
        if(isPath.second){
            maxPath = max(neighbour.second, isPath.first);
            foundPath = true;
        }
    }
    return make_pair(maxPath, foundPath);
}

int main(){
    int nodes, edges, queries;
    cin >> nodes >> edges >> queries;
    int t = 1;
    while(true){
        vector<pair<int, pair<int, int>>> edgeList(edges);
        for(int i = 0; i < edges;++i){
            int cost, u, v;
            cin >> u >> v >> cost;
            u--, v--;
            edgeList[i] = make_pair(cost, make_pair(u, v));
        }
        sort(edgeList.begin(), edgeList.end());
        DSU dsu(nodes);
        unordered_map<int, vector<pair<int, int>>> adjList; // u, v, cost
        for(auto edge : edgeList){
            int u = edge.second.first, v = edge.second.second;
            int px = dsu.find(u), py = dsu.find(v);
            int cost = edge.first;
            if(px == py)
                continue;
            adjList[u].push_back(make_pair(v, cost));
            adjList[v].push_back(make_pair(u, cost));
            dsu.uni(px, py);
        }

        cout << "Case #" << (t++) << endl;
        for(int i = 0;i < queries;++i){
            int s, d;
            cin >> s >> d;
            s--, d--;
            pair<int, bool> maxItemOnPath = dfs(s, -1, adjList, d);
            if(!maxItemOnPath.second)
                cout << "no path" << endl;
            else
                cout << maxItemOnPath.first << endl;
        }
        cin >> nodes >> edges >> queries;
        if(nodes == 0 && edges == 0 && queries == 0)    break;
        cout << endl;
    }
    return 0;
}
