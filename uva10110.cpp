// UVa 10110 - Light, more light
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

    ll n;
    cin >> n;
    while(n != 0){
        double rt = sqrt((double)n);
        double intPart;
        double frac = modf(rt, &intPart);
        if(rt == intPart)                       // if(rt == floor(rt))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        cin >> n;
    }
    return 0;
}
