// UVa 573 - The Snail
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

    ll H, U, D, F;
    cin >> H >> U >> D >> F;

    while(H != 0){
        double climb = 0;
        double power = U;
        double powerDecrease = (double)U * (double)F/(double)100;
        ll day = 1;
        while(climb >= 0 && climb < H){
            climb += power;
            if(climb > H)
                break;
            if(power - powerDecrease > 0)
                power -= powerDecrease;
            else
                power = 0;
            climb -= D;
            day++;
        }
        if(climb >= H)
            cout << "success on day " << day << endl;
        else
            cout << "failure on day " << day - 1 << endl;
        cin >> H >> U >> D >> F;
    }

    return 0;
}
