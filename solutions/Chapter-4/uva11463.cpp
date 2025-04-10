// UVa 11463 - Commandos
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<(i==len-1?"":" ");cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

class FloydWarshall{
    vector<vector<int>> adjMat;
    int totalNodes;
    int INF = 1e5;
    public:
        FloydWarshall(int nodes, unordered_map<int, unordered_set<int>> adjList) : totalNodes(nodes){
            adjMat.resize(nodes + 1, vector<int>(nodes + 1, INF));
            for(auto kv : adjList){
                int u = kv.first;
                for(auto v : kv.second){
                    adjMat[u][v] = 1;
                    adjMat[v][u] = 1;
                    adjMat[u][u] = 0;
                    adjMat[v][v] = 0;
                }
            }
        }
        void run(){
            for(int k = 0;k < totalNodes;++k){
                for(int i = 0;i < totalNodes;++i){
                    for(int j = 0;j < totalNodes;++j){
                        if(adjMat[i][j] > adjMat[i][k] + adjMat[k][j])
                            adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                    }
                }
            }
        }
        void pprint(){
            debugMatrix(adjMat, totalNodes + 1, totalNodes + 1);
        }
        int getDistance(int source, int destination){
            int maxi = 0;
            for(int i = 0;i < totalNodes;++i){
                if(adjMat[source][i] != INF && adjMat[i][destination] != INF)
                    maxi = max(adjMat[source][i] + adjMat[i][destination], maxi);
            }
            return maxi;
        }
};

int main(){
    int caseNumber = 1;
    int t = 0;
    cin >> t;
    while(t--){
        unordered_map<int, unordered_set<int>> adjList;
        int nodes = 0;
        cin >> nodes;
        int edges = 0;
        cin >> edges;
        for(int i = 0;i < edges;++i){
            int u,v;
            cin >> u >> v;
            adjList[u].insert(v);
        }
        int source, destination;
        cin >> source >> destination;
        FloydWarshall floydWarshall(nodes, adjList);
        floydWarshall.run();
        // floydWarshall.pprint();
        cout << "Case " << caseNumber << ": " << floydWarshall.getDistance(source, destination) << endl;
        caseNumber += 1;
    }
    return 0;
}
