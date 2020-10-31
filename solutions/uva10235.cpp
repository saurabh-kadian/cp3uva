// UVa 10235 - Simple Emirp
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    makePrimes(1000000);
    ll n;
    while(!cin.eof()){
        cin >> n;
        if(cin.eof())
            break;
        stringstream ss;
        ss << n;
        string str = ss.str();
        reverse(str.begin(), str.end());
        stringstream ssr(str);
        ll nr;
        ssr >> nr;
        bool prime = binary_search(primes.begin(), primes.end(), n);
        bool pr    = binary_search(primes.begin(), primes.end(), nr);
        if(nr == n && prime)
            cout << n << " is " << "prime." << endl;
        else
            cout << n << " is " << ((prime & pr) ? "emirp" : (prime ? "prime" : "not prime")) << "." << endl;
    }
    return 0;
}
