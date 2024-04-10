// UVa 12442 - Forwarding Emails
#include <bits/stdc++.h>
using namespace std;


int dfsRevisitChains(int node, vector<bool>& visited, vector<int>& reach, vector<int>& graph){
    visited[node] = true;
    reach[node] = 1;
    if(graph[node] != -1 && !visited[graph[node]])
        reach[node] = 1 + dfsRevisitChains(graph[node], visited, reach, graph);
    visited[node] = false;
    return reach[node];
}


void fillLoop(int node, int stopAt, int value, vector<int>& reach, vector<int>& graph){
    reach[node] = value;
    if(node == stopAt)
        return ;
    fillLoop(graph[node], stopAt, value, reach, graph);
    return ;
}

int dfs(int node, vector<bool>& visited, vector<int>& reach, vector<int>& graph){
    visited[node] = true;
    if(!visited[graph[node]]){
        int leaf = dfs(graph[node], visited, reach, graph);
        reach[node] = reach[graph[node]] + 1;
        return leaf;
    }
    reach[node] = reach[graph[node]] + 1;
    return (reach[graph[node]] != -1 ? -1 : node);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for(int test = 1;test <= t;++test){
        int n;
        cin >> n;
        vector<int> graph(n, -1);
        for(int i = 0;i < n;++i){
            int u,v;
            cin >> u >> v;
            u--;
            v--;
            graph[u] = v;
        }

        vector<int> reach(graph.size(), -1);
        vector<bool> visited(graph.size(), false);

        // Repeating chains
        for(int i = 0;i < reach.size();++i){
            if(reach[i] == -1)
                dfsRevisitChains(i, visited, reach, graph);
        }

        
        // Non-repeating chains. Failing for some case, not sure which

        // for(int i = 0;i < visited.size();++i){
        //     if(!visited[i]){
        //         int leaf = dfs(i, visited, reach, graph);
        //         if(leaf != -1)
        //             fillLoop(graph[leaf], leaf, reach[i], reach, graph);
        //     }
        // }
        
        // DEBUG
        // for(int i = 0;i < graph.size();++i)
        //     cout << i << " -> " << reach[i] << endl;
        cout << "Case " << test << ": " << distance(reach.begin(), max_element(reach.begin(), reach.end())) + 1 << endl;
    }
    return 0;
}