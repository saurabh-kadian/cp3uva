// UVa 259 - Software allocation
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
        MinFlow(int nodes): nodes(nodes){
            adjMat.resize(nodes + 1, vector<int>(nodes + 1, 0));
            parent.resize(nodes + 1, -1);
        }
        void convertFromAdjList(unordered_map<int, vector<pair<int, int>>>& adjList){
            for(auto kv : adjList){
                int u = kv.first;
                vector<pair<int, int>> neighbours = kv.second;
                for(auto neighbour : neighbours){
                    adjMat[u][neighbour.first] = neighbour.second;
                }
            }
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
    int SOURCE = 36;
    int DESTINATION = 37;
    int inf = 1e8;
    while(!cin.eof()){
        string input;
        unordered_map<int, vector<pair<int, int>>> adjList;
        int totalUsers = 0;
        while(true){
            getline(cin, input);
            if(input == "")
                break;
            int software = input[0] - 'A' + 10;
            int users = input[1] - '0';
            totalUsers += users;
            vector<int> machines;
            for(int i = 3;input[i] != ';';++i)
                adjList[software].push_back(make_pair(input[i] - '0', inf));
            adjList[SOURCE].push_back(make_pair(software, users));
        }
        map<int, char> allocation;
        for(int i = 0;i < 10;++i)
            adjList[i].push_back(make_pair(DESTINATION, 1)), allocation[i] = '_';

        MinFlow minFlow(DESTINATION);
        minFlow.setSource(SOURCE);
        minFlow.setDestination(DESTINATION);
        minFlow.convertFromAdjList(adjList);
               
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
        if(totalFlow != totalUsers)
            cout << "!";
        else{
            for(int sw = 10;sw <= 35;++sw){
                for(int comp = 0;comp <= 9;++comp){
                    if(minFlow.getEdge(comp, sw) == 1){          // check if back edge has flow
                        allocation[comp] = sw + 'A' - 10;
                    }
                }
            }
            for(auto kv : allocation){
                cout << kv.second;
            }
        }
        cout << endl;
    }
    return 0;
}
