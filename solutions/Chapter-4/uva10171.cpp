// UVa 10171 - Meeting Prof. Miguel ...
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
    unordered_map<char, int> cities;
    int totalNodes;
    int INF = 1e5;
    public:
        FloydWarshall(unordered_map<char, int> cities, unordered_map<int, unordered_map<int, int>> adjList){
            adjMat.resize(cities.size() + 1, vector<int>(cities.size() + 1, INF));
            for(auto kv : adjList){
                int u = kv.first;
                for(auto nodeCost : kv.second){
                    int v = nodeCost.first;
                    int c = nodeCost.second;
                    adjMat[u][v] = c;
                }
            }
            for(auto city : cities)
                adjMat[city.second][city.second] = 0;
            totalNodes = cities.size();
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
            return adjMat[source][destination];
        }
};

int main(){
    int INF = 1e5;
    while(true){
        int streets;
        cin >> streets;
        if(streets == 0)
            break;
        unordered_map<char, int> cities;
        int index = 0;
        unordered_map<int, unordered_map<int, int>> youngAdjList;
        unordered_map<int, unordered_map<int, int>> oldAdjList;
        for(int i = 0;i < streets;++i){
            char age, direction;
            char cu, cv;
            int cost;
            cin >> age >> direction >> cu >> cv >> cost;
            int u, v;
            if(!cities.count(cu)){
                u = index++;
                cities[cu] = u;
            }
            if(!cities.count(cv)){
                v = index++;
                cities[cv] = v;
            }
            u = cities[cu];
            v = cities[cv];
            if(age == 'Y' && direction == 'U'){
                youngAdjList[u][v] = cost;
            } else if(age == 'Y' && direction == 'B'){
                youngAdjList[u][v] = cost;
                youngAdjList[v][u] = cost;
            } else if(age == 'M' && direction == 'U'){
                oldAdjList[u][v] = cost;
            } else {
                oldAdjList[u][v] = cost;
                oldAdjList[v][u] = cost;
            }
        }
        char s, d;
        cin >> s >> d;
        int source, destination;
        if(!cities.count(s)){
            source = index++;
            cities[s] = source;
        }
        if(!cities.count(d)){
            destination = index++;
            cities[d] = destination;
        }
        source = cities[s];
        destination = cities[d];
        
        FloydWarshall young(cities, youngAdjList);
        young.run();
        FloydWarshall old(cities, oldAdjList);
        old.run();

        int minTime = INT_MAX;
        vector<char> minCity;
        for(auto city : cities){
            int k = city.second;
            int total = young.getDistance(source, k) + old.getDistance(destination, k);
            
            if(total < minTime){
                minTime = total;
                minCity.clear();
                minCity.push_back(city.first);
            } else if(total == minTime){
                minCity.push_back(city.first);
            }
        }
        sort(minCity.begin(), minCity.end());

        if(minTime >= INF)
            cout << "You will never meet." << endl;
        else{
            cout << minTime << " ";
            debug(minCity, minCity.size());
        }
    }
    return 0;
}
