// UVa 10616 - Divisible Group Sum
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef unsigned int ll;

int mod(int val, int modulo){
    if(val >= 0)
        return val%modulo;
    else
        return (modulo + (val%modulo))%modulo;
}

int solve(int index, int left, int modulo, vector<ll>& input, ll& d, unordered_map<string, int>& save){
    if(index == input.size()){
        if(modulo == 0 && left == 0)
            return 1;
        return 0;
    }
    stringstream ss;
    ss << index << "-" << left << "-" << modulo;
    string key = ss.str();
    if(save.find(key) != save.end())
        return save[key];

    int answer = 0;
    // choose or not choose
        // choose
        if(left > 0){
            answer += solve(index + 1, left - 1, mod(modulo + input[index], d), input, d, save);
        }
        // not choose
        answer += solve(index + 1, left, modulo, input, d, save);
    return save[key] = answer;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int counter  = 1;
    ll n,q; 
    cin >> n >> q;
    while(n != 0 && q != 0){
        cout << "SET " << counter++ << ":" << endl;
        vector<ll> input(n);
        unordered_map<string, int> save;
        for(int i = 0;i < n;++i)
            cin >> input[i];
        for(int i = 0;i < q;++i){
            save.clear();
            ll d, m;
            cin >> d >> m;
            cout << "QUERY " << i + 1 << ": " << solve(0, m, 0, input, d, save) << endl;
        }
        cin >> n >> q;
    }
    return 0;
}
