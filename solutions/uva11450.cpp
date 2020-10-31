// UVa 11450 - Wedding Shopping
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;

map<pair<ll,ll>, ll> save;

ll solve(ll money, ll index, vector<vector<ll> >& costs){
	// base case
	if(index == costs.size())
		return 0;

	// memoization
	if(save.find(make_pair(money, index)) != save.end())
		return save[make_pair(money, index)];

	// recurrence
	ll cost = INT_MIN;
	for(ll ii = 0;ii < costs[index].size();++ii){
		if(money - costs[index][ii] >= 0)
			cost = max(cost, solve(money - costs[index][ii], index + 1, costs) + costs[index][ii]);
	}

	if(cost < 0)
		cost = INT_MIN;

	return save[make_pair(money, index)] = cost;
}

int main(){
	ll testCases;
	cin >> testCases;
	while(testCases--){

		save.clear();

		// input
		ll money, garments;
		cin >> money >> garments;
		vector<vector<ll> > costs(garments);
		for(ll ii = 0;ii < garments;++ii){
			ll models;
			cin >> models;
			costs[ii].resize(models);
			for(ll jj = 0;jj < models;++jj)
				cin >> costs[ii][jj];
		}

		// solution
		ll answer = solve(money, 0, costs);
		if(answer < 0)
			cout << "no solution" << endl;
		else
			cout << answer << endl;
	}

	return 0;
}
