// UVa 12101 - Prime Path
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

vector<ll> primes;
vector<vector<ll> > adjList;

bool isPrime(ll n){
    if(n == 2 || n == 3)
        return true;
    if(n%2 == 0 || n%3 == 0)
        return false;
    for(ll i = 5;i*i <= n;i += 6)
        if(n%i == 0 || n%(i + 2) == 0)
            return false;
    return true;
}

void makePrimes(){
    for(int i = 1000;i <= 9999;++i)
        if(isPrime(i))
            primes.push_back(i);
}

bool distanceNumbers(ll a, ll b){
    stringstream ssa, ssb;
    ssa << a;
    ssb << b;
    string stra, strb;
    stra = ssa.str();
    strb = ssb.str();
    ll count = 0;
    for(int i = 0;i < stra.length();++i)
        if(stra[i] != strb[i])
            count++;
    return (count == 1 ? true : false);
}

void makeGraph(){
    adjList.resize(primes.size(), vector<ll>());
    for(int i = 0;i < primes.size();++i){
        for(int j = i + 1;j < primes.size();++j){
            if(distanceNumbers(primes[i], primes[j])){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
}

ll bfs(ll number, ll finalNumber){
    vector<bool> visit(primes.size(), false);
    queue<pair<ll,ll> > Q;
    ll dist = distance(primes.begin(), find(primes.begin(), primes.end(), number));
    Q.push(make_pair(dist, 0));
    visit[dist] = true;
    while(!Q.empty()){
        pair<ll,ll> fronter = Q.front();
        if(primes[fronter.first] == finalNumber)
            return fronter.second;
        for(int i = 0;i < adjList[fronter.first].size();++i)
            if(!visit[adjList[fronter.first][i]])
                    Q.push(make_pair(adjList[fronter.first][i], fronter.second + 1)), visit[adjList[fronter.first][i]] = true;
        Q.pop();
    }
    return -1;
}

int main(){
    makePrimes();
    makeGraph();
    ll t;
    cin >> t;
    while(t--){
        ll x,y;
        cin >> x >> y;
        ll answer = bfs(x, y);
        if(answer == -1)
            cout << "Impossible" << endl;
        else
            cout << answer << endl;
    }
    return 0;
}
