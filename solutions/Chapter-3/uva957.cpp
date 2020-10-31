// UVa 957 - Popes
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
    while(!cin.eof()){
        ll y;
        cin >> y;
        if(cin.eof())
            break;
        ll p;
        cin >> p;
        vector<ll> years(p);
        for(ll i = 0;i < p;++i)
            cin >> years[i];

        ll j = 0;
        ll maxPope = 1;
        ll firstPope = years[0];
        ll lastPope = years[0];
        for(ll i = 0;i < p;++i){
            while(j < p && years[j] - years[i] + 1 <= y)
                j++;
            if(j - i > maxPope){
                maxPope = j - i;
                firstPope = years[i];
                lastPope = years[j - 1];
            }
        }
        cout << maxPope << " " << firstPope << " " << lastPope << endl;
    }
    return 0;
}
