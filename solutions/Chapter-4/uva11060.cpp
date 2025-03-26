// UVa 11060 - Beverages
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

int main(){
    int test = 1;
    while(!cin.eof()){
        int n;
        cin >> n;
        if(cin.eof())
            break;
        else if(test != 1)
            cout << "\n";
        unordered_map<string, int> mapping;
        unordered_map<int, string> reverseMapping;
        for(int i = 0;i < n;++i){
            string beverage;
            cin >> beverage;
            mapping[beverage] = i;
            reverseMapping[i] = beverage;
        }
        unordered_map<int, vector<int>> adjList;
        vector<int> indegree(mapping.size(), 0);
        int m;
        cin >> m;
        for(int i = 0;i < m;++i){
            string a, b;
            cin >> a >> b;
            int u = mapping[a], v = mapping[b];
            indegree[v] += 1;
            adjList[u].push_back(v);
        }
        
        vector<int> order;
        set<int> bfsQueue;

        for(int i = 0;i < mapping.size();++i)
            if(indegree[i] == 0)
                bfsQueue.insert(i);

        while(!bfsQueue.empty()){
            int size = bfsQueue.size();
            while(size--){
                int frontNode = *bfsQueue.begin();
                order.push_back(frontNode);
                bfsQueue.erase(bfsQueue.begin());
                for(auto neighbour : adjList[frontNode]){
                    indegree[neighbour] -= 1;
                    if(indegree[neighbour] == 0)
                        bfsQueue.insert(neighbour);
                }
            }
        }
        
        cout << "Case #" << test << ": Dilbert should drink beverages in this order: ";
        for(int i = 0;i < order.size();++i)
            cout << reverseMapping[order[i]] << (i == order.size() - 1 ? "." : " ");
        cout << endl;
        test += 1;
    }
    cout << "\n";
    return 0;
}