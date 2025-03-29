// UVa 10600 - ACM Contest and Blackout
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
        void clear(){
            for(int i = 0;i < parent.size();++i)
                parent[i] = i;
        }
        bool isSane(){
            set<int> islands;
            for(int i = 0;i < parent.size();++i){
                islands.insert(find(i));
                if(islands.size() >= 2) return false;
            }
            return (islands.size() == 1);
        }
        void pprint(){
            debug(parent, parent.size());
        }
};

int getMinCost(vector<pair<int, pair<int, int>>>& edgeList, DSU* dsu, vector<int>& treeEdgeList){
    int minCost = 0;
    for(int i = 0;i < edgeList.size();++i){
        pair<int, pair<int, int>> edge = edgeList[i];
        int u = edge.second.first, v = edge.second.second;
        int px = dsu->find(u), py = dsu->find(v);
        if(px == py)
            continue;
        minCost += edge.first;
        treeEdgeList.push_back(i);
        dsu->uni(px, py);
    }
    return minCost;
}

int getSecondMinCost(vector<pair<int, pair<int, int>>>& edgeList, DSU* dsu, vector<int>& treeEdgeList){
    int secondMinCost = INT_MAX;
    for(int remove = 0;remove < treeEdgeList.size();++remove){
        int removeIndex = treeEdgeList[remove];
        dsu->clear();
        int localMinCost = 0;
        for(int i = 0;i < edgeList.size();++i){
            if(i == removeIndex)
                continue;
            pair<int, pair<int, int>> edge = edgeList[i];
            int u = edge.second.first, v = edge.second.second;
            int px = dsu->find(u), py = dsu->find(v);
            if(px == py)
                continue;
            localMinCost += edge.first;
            dsu->uni(px, py);
        }
        if(dsu->isSane())
            secondMinCost = min(secondMinCost, localMinCost);
    }
    return secondMinCost;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int nodes, edges;
        cin >> nodes >> edges;
        vector<pair<int, pair<int, int>>> edgeList(edges);
        for(int i = 0; i < edges;++i){
            int cost, u, v;
            cin >> u >> v >> cost;
            u--, v--;
            edgeList[i] = make_pair(cost, make_pair(u, v));
        }
        sort(edgeList.begin(), edgeList.end());
        DSU* dsu = new DSU(nodes);
        vector<int> treeEdgeList;
        int minCost = getMinCost(edgeList, dsu, treeEdgeList);
        int secondMinCost = getSecondMinCost(edgeList, dsu, treeEdgeList);
        cout << minCost << " " << (secondMinCost == INT_MAX ? minCost : secondMinCost) << endl;
    }
    return 0;
}
