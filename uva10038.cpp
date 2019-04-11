// UVa 10038 - Jolly Jumper
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
        ll n;
        cin >> n;
        if(cin.eof())
            break;
        vector<ll> numbers(n);
        vector<bool> jolly(n);
        vector<bool> check(n, true);
        jolly[0] = true;
        for(int i = 0;i < n;++i)
            cin >> numbers[i];
        for(int i = 0;i < n-1;++i){
            jolly[abs(numbers[i]-numbers[i+1])] = true;
        }
        if(jolly == check)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }
    return 0;
}
