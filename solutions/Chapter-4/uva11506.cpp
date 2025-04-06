// UVa 11506 - Angry Programmer
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
    unordered_map<int, unordered_map<int, int>> adjList;
    unordered_map<int, unordered_map<int, int>> capacity;
    unordered_map<int, int> parent;
    queue<pair<int, int>> bfsQueue;
    int source, destination;
    int INF = 1e8;
    public:
        MinFlow(int nodes, int source, int destination, unordered_map<int, unordered_map<int, int>> adjList): 
                    nodes(nodes), source(source), destination(destination), adjList(adjList){
            capacity = adjList;
        }
        
        void removeNode(int node){
            if(!capacity.count(node) || !adjList.count(node))   return ;
            capacity.erase(node);
            adjList.erase(node);
        }
        void flushBfsQueue(){
            while(!bfsQueue.empty())
                bfsQueue.pop();
        }
        int getParent(int node){
            if(!parent.count(node)) return -1;
            return parent[node];
        }
        void printParent(){
            for(auto kv : parent)
                cout << kv.second << " is parent of " << kv.first << endl;
            cout << endl;
        }
        int getCapacityFor(int u, int v){
            return capacity[u][v];
        }
        int flowBFS(){
            parent.clear();
            parent[source] = -2;                        // So there is no circling back
            bfsQueue.push(make_pair(source, INF));
            while(!bfsQueue.empty()){
                int node = bfsQueue.front().first;
                int flow = bfsQueue.front().second;
                // cout << "Node: " << node << ", Flow: " << flow << endl;
                bfsQueue.pop();
                for(auto neighbour : capacity[node]){
                    if(capacity[node][neighbour.first] > 0 && !parent.count(neighbour.first)){
                        int newFlow = min(flow, capacity[node][neighbour.first]);
                        parent[neighbour.first] = node;
                        if(neighbour.first == destination)
                            return newFlow;
                        bfsQueue.push(make_pair(neighbour.first, newFlow));
                    }
                }
            }
            return 0;
        }
        void adjustFlow(int u, int v, int flow){
            capacity[u][v] -= flow;
            capacity[v][u] += flow;
        }
};


int main(){
    int INF = 1e8;
    int machines, wires;
    cin >> machines >> wires;
    int MAX_MACHINE_WIRE = 1001;
    while(machines != 0 || wires != 0){
        int SOURCE = 0;
        int DESTINATION = machines - 1;
        unordered_map<int, unordered_map<int, int>> adjList;
        // split each node into 2, node u becomes, u and u prime
        for(int i = 0;i < machines - 2;++i){
            int id, cost;
            cin >> id >> cost;
            int u = id - 1;
            int v = MAX_MACHINE_WIRE + u;
            adjList[u][v] = cost;
        }
        adjList[SOURCE][MAX_MACHINE_WIRE + SOURCE] = INF;
        adjList[DESTINATION][MAX_MACHINE_WIRE + DESTINATION] = INF;
        
        DESTINATION = MAX_MACHINE_WIRE + DESTINATION;

        for(int i = 0;i < wires;++i){
            int u,v,cost;
            cin >> u >> v >> cost;
            u--, v--;
            int up = MAX_MACHINE_WIRE + u;
            int vp = MAX_MACHINE_WIRE + v;
            if(u == SOURCE){
                if(v == DESTINATION){
                    adjList[up][v] = cost;
                    adjList[v][up] = cost;
                } else {
                    adjList[up][v] = cost;
                    adjList[vp][up] = cost;
                }
            } else if(v == DESTINATION) {
                adjList[up][v] = cost;
                adjList[v][up] = cost;
            } else {
                adjList[up][v] = cost;
                adjList[vp][u] = cost;
            }
        }

        MinFlow minFlow(machines, SOURCE, DESTINATION, adjList);
        int flow = minFlow.flowBFS();
        minFlow.flushBfsQueue();
        int minBreakdownCost = 0;
        while(flow){
            int currentNode = DESTINATION;
            minBreakdownCost += flow;
            while(currentNode != SOURCE){
                int parentOfCurrentNode = minFlow.getParent(currentNode);
                minFlow.adjustFlow(parentOfCurrentNode, currentNode, flow);
                currentNode = parentOfCurrentNode;
            }
            // cout << "FLOW: " << flow << endl;
            flow = minFlow.flowBFS();
            minFlow.flushBfsQueue();
        }
        cout << minBreakdownCost << endl;
        cin >> machines >> wires;
    }
    return 0;
}
