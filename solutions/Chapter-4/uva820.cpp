// UVa 820 - Internet Bandwidth
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<(i==len-1?"":" ");cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

class MinFlow{
    int nodes, connections;
    vector<vector<int>> adjMat;
    vector<int> parent;
    queue<pair<int, int>> bfsQueue;
    int source, destination;
    int INF = 1e8;
    public:
        MinFlow(int nodes, int connections): nodes(nodes), connections(connections){
            adjMat.resize(nodes + 1, vector<int>(nodes + 1, 0));
            parent.resize(nodes + 1, -1);
        }
        void setSource(int source){
            this->source = source;
        }
        void setDestination(int destination){
            this->destination = destination;
        }
        void flushBfsQueue(){
            while(!bfsQueue.empty())
                bfsQueue.pop();
        }
        void addBidirectionConnection(int u, int v, int flow){
            adjMat[u][v] += flow;
            adjMat[v][u] += flow;
        }
        void addConnection(int u, int v, int flow){
            adjMat[u][v] += flow;
        }
        int getParent(int node){
            return parent[node];
        }
        int flowBFS(){
            int parentSize = parent.size();
            parent.clear();
            parent.resize(parentSize, -1);
            parent[source] = -2;                        // So there is no circling back
            bfsQueue.push(make_pair(source, INF));
            while(!bfsQueue.empty()){
                int node = bfsQueue.front().first;
                int flow = bfsQueue.front().second;
                bfsQueue.pop();
                for(int neighbour = 0;neighbour < adjMat[node].size();++neighbour){
                    if(adjMat[node][neighbour] > 0 && parent[neighbour] == -1){
                        int newFlow = min(flow, adjMat[node][neighbour]);
                        parent[neighbour] = node;
                        if(neighbour == destination)
                            return newFlow;
                        bfsQueue.push(make_pair(neighbour, newFlow));
                    }
                }
            }
            return 0;
        }
        void adjustFlow(int u, int v, int flow){
            adjMat[u][v] -= flow;
            adjMat[v][u] += flow;
        }
};


int main(){
    int testcase = 1;
    int nodes;
    cin >> nodes;
    while(nodes != 0){
        int source, destination, connections;
        cin >> source >> destination >> connections;
        source--, destination--;

        MinFlow minFlow(nodes, connections);
        minFlow.setSource(source);
        minFlow.setDestination(destination);

        for(int i = 0;i < connections;++i){
            int u, v, flow;
            cin >> u >> v >> flow;
            u--, v--;
            minFlow.addBidirectionConnection(u, v, flow);
        }
        
        int totalFlow = 0;
        int flow = minFlow.flowBFS();
        while(flow){
            int currentNode = destination;
            while(currentNode != source){
                int u = minFlow.getParent(currentNode);
                int v = currentNode;
                minFlow.adjustFlow(u, v, flow);
                currentNode = u;
            };
            totalFlow += flow;
            minFlow.flushBfsQueue();
            flow = minFlow.flowBFS();
        }
        cout << "Network " << testcase++ << endl;
        cout << "The bandwidth is " << totalFlow << "." << endl;
        cin >> nodes;
        cout << endl;
    }
    return 0;
}
