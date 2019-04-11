// UVa 10491 - Cows and Cars
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    double cows, cars, opened;
    while(!cin.eof()){
        cin >> cows;
        if(cin.eof())
            break;
        cin >> cars >> opened;
        ll total = cars + cows;
        printf("%0.5lf\n", (cars * (cars - 1))/(total * (total - opened - 1)) + ((cows * cars)/(total * (total - opened - 1))));
    }
    return 0;
}
