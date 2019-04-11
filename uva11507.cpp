// UVa 11507 - Bender B. Rodr´iguez Problem
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

    ll l;
    cin >> l;
    while(l != 0){
        // +x = +1, +y = +2, +z = +3
        // -x = -1, -y = -2, -z = -3
        ll last = 1;
        ll position = 1;
        ll lastXDir = 1;
        for(ll i = 0;i < l - 1;++i){
            char dir, dim;
            cin >> dir >> dim;
            if(dir == 'N')
                continue;
            ll convertToNum = (dir == '-' ? -1 * (dim == 'x' ? 1 : dim == 'y' ? 2 : 3) : (dim == 'x' ? 1 : dim == 'y' ? 2 : 3));
            if(last == convertToNum)
                last = lastXDir, position = -1 * lastXDir, lastXDir *= -1;
            else if(last == -1 * convertToNum)
                last = lastXDir, position = lastXDir;
            else if(position == 1 || position == -1)
                last = convertToNum, position = convertToNum * lastXDir;
        }
        cout << (position > 0 ? (position == 1 ? "+x" : (position == 2 ? "+y" : "+z")) : (position == -1 ? "-x" : (position == -2 ? "-y" : "-z"))) << endl;
        cin >> l;
    }
    return 0;
}
