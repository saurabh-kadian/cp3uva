// UVa 357 - Let Me Count The Ways
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

ll solve(ll n){

    ll answer[n + 2];
    fill(answer, answer + n + 2, 0);
    answer[0] = 1;
    answer[1] = 1;

    ll changes[] = {1, 5, 10, 25, 50};

    for(int j = 0;j < 5;++j)
        for(int i = 2;i <= n;++i)
            if(i - changes[j] >= 0)
                answer[i] += answer[i - changes[j]];

    return answer[n];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    while(!cin.eof()){
        cin >> n;
        if(cin.eof())
            break;
        ll answer = solve(n);
        if(answer == 1)
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else
            cout << "There are " << solve(n) << " ways to produce " << n << " cents change."<< endl;
    }

    return 0;
}
