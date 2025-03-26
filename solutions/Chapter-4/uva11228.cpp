// UVa 11228 - Transportation system
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

void debugCostEdgeList(vector<pair<double, pair<int,int>>>& edgeList){
    for(auto edge : edgeList){
        cout << "Cost: " << edge.first << ", U:" << edge.second.first << ", V:" << edge.second.second << endl;
    }
}

void debugEdgeList(vector<pair<int,int>>& edgeList){
    for(auto edge : edgeList){
        cout << "U:" << edge.first << ", V:" << edge.second << endl;
    }
}

class DSU{
    vector<int> parent;
    public:
        DSU(int size){
            parent.resize(size, 0);
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
            int size = parent.size();
            parent.clear();
            parent.resize(size, 0);
            for(int i = 0;i < size;++i)
                parent[i] = i;
        }
        unordered_map<int, vector<int>> getIslands(){
            unordered_map<int, vector<int>> islands;
            for(int i = 0;i < parent.size();++i)
                islands[find(i)].push_back(i);
            return islands;
        }
        void printParent(){
            for(auto x : parent)
                cout << x << " ";
            cout << endl;
        }
};

vector<pair<int, int>> makeGraphEdgeList(unordered_map<int, pair<int,int>>& coords, int& nodes, int& radius){
    int radiusDistance = radius * radius;
    vector<pair<int, int>> edgeList;
    for(int i = 0;i < nodes;++i){
        for(int j = i + 1;j < nodes;++j){
            int xcoord = coords[i].first - coords[j].first;
            int ycoord = coords[i].second - coords[j].second;
            xcoord *= xcoord;
            ycoord *= ycoord;
            if(xcoord + ycoord <= radiusDistance)
                edgeList.push_back(make_pair(i, j));
        }
    }
    return edgeList;
}
vector<pair<double, pair<int,int>>> makeRoadEdgeList(unordered_map<int, pair<int,int>>& coords, int& nodes, 
                                                        vector<int>& cities){
    vector<pair<double, pair<int,int>>> edgeList;
    for(int i = 0;i < cities.size();++i){
        for(int j = i + 1;j < cities.size();++j){
            int xcoord = coords[cities[i]].first - coords[cities[j]].first;
            int ycoord = coords[cities[i]].second - coords[cities[j]].second;
            double distance = sqrt(xcoord*xcoord + ycoord*ycoord);
            edgeList.push_back(make_pair(distance, make_pair(cities[i], cities[j])));
        }
    }
    return edgeList;
}
vector<pair<double, pair<int,int>>> makeRailroadEdgeList(unordered_map<int, pair<int,int>>& coords, int& nodes, 
                                                            unordered_map<int, vector<int>>& islandList){
    vector<pair<double, pair<int,int>>> edgeList;
    for(int i = 0;i < islandList.size();++i){
        for(int j = i + 1;j < islandList.size();++j){
            vector<int> citiesOne = islandList[i];
            vector<int> citiesTwo = islandList[j];
            pair<double, pair<int, int>> minEdge = make_pair(DBL_MAX, make_pair(0, 0));
            for(int p = 0;p < citiesOne.size();++p){
                for(int q = 0;q < citiesTwo.size();++q){
                    int xcoord = coords[citiesOne[p]].first - coords[citiesTwo[q]].first;
                    int ycoord = coords[citiesOne[p]].second - coords[citiesTwo[q]].second;
                    double distance = sqrt(xcoord*xcoord + ycoord*ycoord);
                    if(distance < minEdge.first)
                        minEdge = make_pair(distance, make_pair(i, j));
                }
            }
            edgeList.push_back(minEdge);
        }
    }
    return edgeList;
}

double runKruskal(vector<pair<double, pair<int,int>>>& edgeList, DSU islands, bool debug){
    double cost = 0;
    islands.clear();
    sort(edgeList.begin(), edgeList.end());
    if(debug) debugCostEdgeList(edgeList);
    for(auto edge : edgeList){
        int px = islands.find(edge.second.first);
        int py = islands.find(edge.second.second);
        if(px == py)    continue;
        islands.uni(px, py);
        cost += edge.first;
    }
    return cost;
}



int main(){
    ll t;
    cin >> t;
    int tt = 1;
    while(t--){
        // cout << "========================================= NEW TEST CASE =========================================" << endl;
        int nodes, radius;
        cin >> nodes >> radius;
        unordered_map<int, pair<int,int>> coords;
        for(int i = 0;i < nodes;++i){
            int x,y;
            cin >> x >> y;
            coords[i] = make_pair(x, y);
        }
        vector<pair<int, int>> edgeList = makeGraphEdgeList(coords, nodes, radius);
        DSU islands = DSU(nodes);
        // debugEdgeList(edgeList);
        for(auto edge : edgeList){
            int px = islands.find(edge.first);
            int py = islands.find(edge.second);
            if(px == py)    continue;
            islands.uni(px, py);
        }
        
        
        unordered_map<int, vector<int>> islandList = islands.getIslands();
        // islands.printParent();
        int numberOfIslands = islandList.size();
        double roadNetworkCost = 0;
        for(auto kv : islandList){
            vector<pair<double, pair<int,int>>> edgeList = makeRoadEdgeList(coords, nodes, kv.second);
            roadNetworkCost += runKruskal(edgeList, islands, false);
        }
        
        vector<pair<double, pair<int,int>>> railroadEdgeList = makeRailroadEdgeList(coords, nodes, islandList);
        double railroadNetworkCost = runKruskal(railroadEdgeList, islands, false);
        
        cout << "Case #" << tt << ": " << numberOfIslands << " " << round(roadNetworkCost) << " " << round(railroadNetworkCost) << endl;
        tt += 1;
    }
    return 0;
}