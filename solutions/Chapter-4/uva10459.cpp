// UVa 10459 - The Tree Root
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

void dfs(int node, int parent, int& distance, vector<int>& distances, unordered_map<int, vector<int>>& adjList, vector<int>& parentList){
    distances[node] = distance;
    for(auto neighbour : adjList[node]){
        if(neighbour == parent)
            continue;
        distance += 1;
        parentList[neighbour] = node;
        dfs(neighbour, node, distance, distances, adjList, parentList);
        distance -= 1;
    }
}

template<typename T> 
void clear(T obj, int newSize, int value){
    obj.clear();
    obj.resize(newSize, value);
}

int main(){
    while(!cin.eof()){    
        ll nodes;
        cin >> nodes;
        if(cin.eof())
            break;
        unordered_map<int, vector<int>> adjList;
        for(int i = 0; i < nodes;++i){
            int edges;
            cin >> edges;
            for(int j = 0;j < edges;++j){
                int x;
                cin >> x;
                adjList[i].push_back(x - 1);
            }
        }
        // first dfs, find farthest point
        vector<int> distances(nodes + 1, 0);
        vector<int> parentList(nodes + 1, -1);

        int d = 0;
        dfs(0, -1, d, distances, adjList, parentList);
        int firstCorner = distance(distances.begin(), max_element(distances.begin(), distances.end()));

        clear<vector<int>>(distances, nodes + 1, 0);
        clear<vector<int>>(parentList, nodes + 1, -1);
        d = 0;
        
        dfs(firstCorner, -1, d, distances, adjList, parentList);
        
        int secondCorner = distance(distances.begin(), max_element(distances.begin(), distances.end()));
        
        // now diameter is firstCorner -> secondCorner, find midPoint
        // 2 midpoints if odd, 1 if even
        int maxDistances = *max_element(distances.begin(), distances.end());
        int midpoints = 1 + ((*max_element(distances.begin(), distances.end())) % 2);
        
        set<int> midpoint;  
        if(midpoints == 1){
            int length = maxDistances/2;
            int singleMidpoint = secondCorner;
            while(length--){
                singleMidpoint = parentList[singleMidpoint];
            }
            midpoint.insert(singleMidpoint);
        } else {
            int length = maxDistances/2;
            int firstMidpoint = secondCorner;
            while(length--){
                firstMidpoint = parentList[firstMidpoint];
            }
            midpoint.insert(firstMidpoint);
            midpoint.insert(parentList[firstMidpoint]);
        }

        set<int> worstRoots;
        for(auto x : midpoint){
            d = 0;
            clear<vector<int>>(distances, nodes + 1, 0);
            clear<vector<int>>(parentList, nodes + 1, -1);
            
            dfs(x, -1, d, distances, adjList, parentList);
            int md = *max_element(distances.begin(), distances.end());
            for(int i = 0;i < nodes;++i)
                if(md == distances[i])
                    worstRoots.insert(i);
        }

        cout << "Best Roots  : ";
        set<int>::iterator x = midpoint.begin();
        for(int w = 0;w < midpoint.size();x++,w++)
            cout << *x + 1 << (w == midpoint.size() - 1 ? "" : " ");
        cout << endl;
        cout << "Worst Roots : ";
        x = worstRoots.begin();
        for(int w = 0;w < worstRoots.size();++x,++w)
            cout << *x + 1 << (w == worstRoots.size() - 1 ? "": " ");
        cout << endl;
    }
    return 0;
}