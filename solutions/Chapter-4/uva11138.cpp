// UVa 11138 - Nuts and Bolts
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
    int nodes;
    vector<vector<int>> adjMat;
    vector<int> parent;
    queue<pair<int, int>> bfsQueue;
    int source, destination;
    int INF = 1e8;
    public:
        MinFlow(int nodes, vector<vector<int>> adjMat): nodes(nodes), adjMat(adjMat){
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
        void addConnection(int u, int v, int flow){
            adjMat[u][v] += flow;
        }
        int getParent(int node){
            return parent[node];
        }
        void printParent(){
            for(auto x : parent)
                cout << x << " ";
            cout << endl;
        }
        int getEdge(int u, int v){
            return adjMat[u][v];
        }
        pair<int, int> flowBFS(){
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
                            return make_pair(newFlow, node);
                        bfsQueue.push(make_pair(neighbour, newFlow));
                    }
                }
            }
            return make_pair(0, -1);
        }
        void adjustFlow(int u, int v, int flow){
            adjMat[u][v] -= flow;
            adjMat[v][u] += flow;
        }
};


int main(){
    int SOURCE = 0;
    int INF = 1e8;
    int t = 0, c = 1;
    cin >> t;
    while(t--){
        int nuts, bolts;
        cin >> nuts >> bolts;
        vector<vector<int>> adjMat(nuts + bolts + 4, vector<int>(nuts + bolts + 4, 0));
        int DESTINATION = nuts + bolts + 1;
        for(int v = 0;v < nuts;++v)
            adjMat[SOURCE][v + 1] = 1;
        for(int u = 0;u < nuts;++u){
            for(int v = 0;v < bolts;++v){
                int isConnection;
                cin >> isConnection;
                adjMat[u + 1][nuts + v + 1] = (isConnection == 1 ? INF : 0);
            }
        }
        for(int u = 0;u < bolts;++u)
            adjMat[nuts + u + 1][DESTINATION] = 1;

        MinFlow minFlow(DESTINATION, adjMat);
        minFlow.setSource(SOURCE);
        minFlow.setDestination(DESTINATION);
               
        int totalFlow = 0;
        pair<int, int> flow = minFlow.flowBFS();
        
        while(flow.first){
            int currentNode = DESTINATION;
            while(currentNode != SOURCE){
                int u = minFlow.getParent(currentNode);
                int v = currentNode;
                minFlow.adjustFlow(u, v, flow.first);
                currentNode = u;
            };
            totalFlow += flow.first;
            minFlow.flushBfsQueue();
            flow = minFlow.flowBFS();
        }
        cout << "Case " << c << ": a maximum of " << totalFlow << " nuts and bolts can be fitted together" << endl;
        c++;
    }
    return 0;
}
