// UVa 11827 - Maximum GCD
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
// #define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

ll gcdR(ll a, ll b) {
    return (b ? gcdR(b, a % b): a);
}

inline ll gcd(ll a, ll b){
    while(b){
        ll c = b;
        b = a % b;
        a = c;
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;
    string str;
    getline(cin, str);
    while(t--){
        getline(cin, str);
        stringstream ss(str);
        vector<ll> nums;
        ll num;
        while(ss >> num)
            nums.push_back(num);

        // sort(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.end());

        ll maxGcd = 1;
        for(int i = 0;i < nums.size();++i)
            for(int j = i + 1;j < nums.size();++j)
                maxGcd = max(maxGcd, gcd(nums[i], nums[j]));
        cout << maxGcd << endl;
    }

    return 0;
}
