// UVa 821 - Page Hopping
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
    unordered_set<int> availableNodes;
    public:
        FloydWarshall(int nodes, unordered_map<int, unordered_set<int>> adjList) : totalNodes(nodes){
            adjMat.resize(nodes + 1, vector<int>(nodes + 1, 1e5));
            for(auto kv : adjList){
                int u = kv.first;
                for(auto v : kv.second){
                    availableNodes.insert(u);
                    availableNodes.insert(v);
                    adjMat[u][v] = 1;
                    adjMat[u][u] = 0;
                    adjMat[v][v] = 0;
                }
            }
        }
        void run(){
            vector<int> nodes(availableNodes.begin(), availableNodes.end());
            for(int k = 0;k < nodes.size();++k){
                for(int i = 0;i < nodes.size();++i){
                    for(int j = 0;j < nodes.size();++j){
                        if(adjMat[nodes[i]][nodes[j]] > adjMat[nodes[i]][nodes[k]] + adjMat[nodes[k]][nodes[j]])
                            adjMat[nodes[i]][nodes[j]] = adjMat[nodes[i]][nodes[k]] + adjMat[nodes[k]][nodes[j]];
                    }
                }
            }
        }
        void pprint(){
            debugMatrix(adjMat, totalNodes + 1, totalNodes + 1);
        }
        double getAverage(){
            double sum = 0;
            double paths = 0;
            vector<int> nodes(availableNodes.begin(), availableNodes.end());
            for(int i = 0;i < nodes.size();++i){
                for(int j = 0;j < nodes.size();++j){
                    if(i == j)
                        continue;
                    paths += 1;
                    sum += adjMat[nodes[i]][nodes[j]];
                }
            }
            return sum/paths; 
        }
};

int main(){
    int caseNumber = 1;
    while(true){
        unordered_map<int, unordered_set<int>> adjList;
        int a, b;
        cin >> a >> b;
        int nodes = 0;
        if(a == 0 && b == 0)
            break;
        nodes = max(max(b, a), nodes);
        adjList[a].insert(b);
        while(true){
            cin >> a >> b;
            if(a == 0 && b == 0)
                break;
            nodes = max(max(b, a), nodes);
            adjList[a].insert(b);
        }
        FloydWarshall floydWarshall(nodes, adjList);
        floydWarshall.run();
        // floydWarshall.pprint();
        cout << fixed << setprecision(3) 
             << "Case " << caseNumber << ": average length between pages = " << floydWarshall.getAverage() 
             << " clicks" << endl;
        caseNumber += 1;
    }
    return 0;
}
