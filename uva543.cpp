// UVa 543 - Goldbach's Conjecture
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

void makePrimes(ll n){
    bool visit[n];
    fill(visit, visit + n, true);
    for(ll i = 2;i*i <= n;++i){
        if(visit[i]){
            for(ll j = i*i;j <= n;j += i){
                visit[j] = false;
            }
        }
    }
    for(ll i = 2;i <= n;++i)
        if(visit[i])
            primes.push_back(i);
}

pair<ll, ll> findSum(ll n){
    for(int i = 0;i < primes.size();++i){
        if(binary_search(primes.begin(), primes.end(), n - primes[i]))
            return make_pair(primes[i], n - primes[i]);
    }
    return make_pair(-1, -1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    makePrimes(1000000);

    ll n;
    cin >> n;
    while(n != 0){
        pair<ll, ll> answer = findSum(n);
        if(answer.first == -1)
            cout << "Goldbach's conjecture is wrong." << endl;
        else
            cout << n << " = " << min(answer.first, answer.second) << " + " << max(answer.first, answer.second) << endl;
        cin >> n;
    }

    return 0;
}
