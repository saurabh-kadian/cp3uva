// UVa 872 - Ordering
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<(i==len-1?"":" ");cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

void backtrackWithIndegree(unordered_map<char, vector<char>>& adjList, unordered_map<char, int>& indegree, 
                            string& order, vector<string>& orders,
                            unordered_set<char>& used){
    if(order.size() == indegree.size())
        orders.push_back(order);

    for(auto kv : indegree){
        char k = kv.first;
        int v = kv.second;
        if(used.count(k) || indegree[k] != 0)
            continue;

        order += k;
        for(auto neighbour : adjList[k])
            indegree[neighbour] -= 1;
        used.insert(k);

        backtrackWithIndegree(adjList, indegree, order, orders, used);

        used.erase(k);
        for(auto neighbour : adjList[k])
            indegree[neighbour] += 1;
        order.pop_back();
    }
}

int main(){
    int t;
    cin >> t;
    string blank;
    bool firstIgnore = true;
    while(t--){
        getline(cin, blank);
        if(firstIgnore){
            cin.ignore();
            firstIgnore = false;
        }
        
        string chars;
        getline(cin, chars);

        istringstream inputstringstream(chars);
        string variable;
        unordered_map<char, vector<char>> adjList;
        unordered_map<char, int> indegree;
        
        while(getline(inputstringstream, variable, ' ')){
            indegree[variable[0]] = 0;
        }

        string constraints;
        getline(cin, constraints);
        
        inputstringstream.clear();
        inputstringstream.str(constraints);
        string constraint;

        while(getline(inputstringstream, constraint, ' ')){
            char u = constraint[0], symbol = constraint[1], v = constraint[2];
            adjList[u].push_back(v);
            indegree[v] += 1;
        }

        vector<string> orders;
        unordered_set<char> used;
        for(auto kv : indegree){
            char k = kv.first;
            int v = kv.second;
            if(v == 0){
                string order = "";
                
                order += k;
                used.insert(k);
                for(auto neighbour : adjList[k])
                    indegree[neighbour] -= 1;

                backtrackWithIndegree(adjList, indegree, order, orders, used);   
                
                used.erase(k);
                for(auto neighbour : adjList[k])
                    indegree[neighbour] += 1;
            }
        }
        
        if(orders.size() == 0)
            cout << "NO" << endl;
        else{
            sort(orders.begin(), orders.end());
            for(auto order : orders){
                for(int i = 0;i < order.size();++i){
                    cout << order[i] << (i == order.size() - 1 ? "" : " ");
                }
                cout << endl;
            }
        }
        if(t != 0)
            cout << endl;
    }
    return 0;
}
