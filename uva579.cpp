// UVa 579 - ClockHands
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

    ll h,m;
    char colon;
    cin >> h >> colon >> m;
    while(h != 0 || m != 0){
        double hh = (double)h * 30.0 + ((double)m/60.0) * 30.0;
        double mm = (double)m * 6.0;
        printf("%0.3lf\n", min(max(hh, mm) - min(hh, mm), 360 - (max(hh, mm) - min(hh, mm))));
        cin >> h >> colon >> m;
    }
    return 0;
}
