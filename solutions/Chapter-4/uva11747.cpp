// UVa 11747 - Heavy cycle edges
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
        vector<pair<int, pair<int, int>>> edgeList(edges);
        for(int i = 0; i < edges;++i){
            int cost, u, v;
            cin >> u >> v >> cost;
            edgeList[i] = make_pair(cost, make_pair(u, v));
        }
        sort(edgeList.begin(), edgeList.end());
        DSU dsu(nodes);
        vector<int> answer;
        for(auto edge : edgeList){
            int u = edge.second.first, v = edge.second.second;
            int px = dsu.find(u), py = dsu.find(v);
            if(px == py){
                answer.push_back(edge.first);
                continue;
            }
            dsu.uni(px, py);
        }
        if(answer.size() == 0)
            cout << "forest" << endl;
        else{
            for(int i = 0;i < answer.size();++i)
                cout << answer[i] << (i == answer.size() - 1 ? "\n" : " ");
        }
        cin >> nodes >> edges;
    }
    return 0;
}
