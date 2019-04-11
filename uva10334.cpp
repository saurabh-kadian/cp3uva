// UVa 10334 - Ray Through Glasses

// Has the problem that fibonacci numbers tend to go long and ll can't handle init

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

    ll arr[1005][4] = {0};

    arr[0][0] = 1; arr[0][1] = 0; arr[0][2] = 0; arr[0][3] = 1;

    arr[1][0] = 0; arr[1][1] = 1; arr[1][2] = 1; arr[1][3] = 2;

    for(int i = 2; i < 1002; ++i){
        if(i%2 == 0)
            arr[i][0] = arr[i-1][1] + arr[i-1][2], arr[i][1] = arr[i-1][2], arr[i][2] = 0, arr[i][3] = arr[i][0] + arr[i][1] + arr[i][2];
        else
            arr[i][2] = arr[i-1][0] + arr[i-1][1], arr[i][1] = arr[i-1][0], arr[i][0] = 0, arr[i][3] = arr[i][0] + arr[i][1] + arr[i][2];
    }

    ll a;
    while(!cin.eof()){
        cin >> a;
        if(cin.eof())
            break;
        cout << arr[a][3] << endl;
    }

    return 0;
}
