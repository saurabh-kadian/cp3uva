// UVa 10369 - Arctic Network
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

double distance(pair<int, int>& u, pair<int, int>& v){
    int xdiff = u.first - v.first;
    int ydiff = u.second - v.second;
    return sqrt(xdiff*xdiff + ydiff*ydiff);
}

int main(){
    int t = 1;
    cin >> t;
    while(t--){
        int satellites, nodes;
        cin >> satellites >> nodes;
        vector<pair<int, int>> coords(nodes);
        for(int i = 0;i < nodes;++i){
            int x, y;
            cin >> x >> y;
            coords[i] = make_pair(x, y);
        }
        vector<pair<double, pair<int, int>>> edgeList;
        for(int i = 0; i < nodes;++i){
            for(int j = i + 1;j < nodes;++j){
                int u = i, v = j;
                double cost = distance(coords[i], coords[j]);
                edgeList.push_back(make_pair(cost, make_pair(u, v)));
            }
        }
        sort(edgeList.begin(), edgeList.end());
        DSU dsu(nodes);
        vector<pair<double, pair<int, int>>> treeEdgeList;
        for(auto edge : edgeList){
            int u = edge.second.first, v = edge.second.second;
            int px = dsu.find(u), py = dsu.find(v);
            if(px == py)
                continue;
            treeEdgeList.push_back(edge);
            dsu.uni(px, py);
        }
        // vector<bool> stations(nodes, false);
        double maxDistance = treeEdgeList[treeEdgeList.size() - 1].first;
        for(int i = treeEdgeList.size() - 1;i >= 0;--i){
            // int u = treeEdgeList[i].second.first, v = treeEdgeList[i].second.second;
            // if(satellites > 0 && !stations[u])  satellites -= 1, stations[u] = true;
            // if(satellites > 0 && !stations[v])  satellites -= 1, stations[v] = true;
            // if(stations[u] && stations[v])  continue;
            if(satellites <= 0)
                break;
            maxDistance = treeEdgeList[i].first;
            satellites -= 1;
            // break;
        }
        cout << fixed;
        cout << setprecision(2);
        cout << maxDistance << endl;
    }
    return 0;
}
