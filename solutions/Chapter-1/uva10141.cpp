// UVa 10141 - Request for Purposal
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef double lf;

int main(){
	ll rfp, p;
	cin >> rfp >> p;
	int i = 1;
	while(rfp || p){
		lf bestComp = 0;
		lf bestPrice = 10000000000;
		string company = "";
		lf tot = rfp;
		string x;
		cin.ignore();
		while(rfp--)
			getline(cin, x);
		while(p--){
			string comp;
			getline(cin, comp);
			lf price, met;
			cin >> price >> met;
			lf w = met;
			cin.ignore();
			while(w--)
				getline(cin, x);
			lf co = met;
			if(co > bestComp)
				bestComp = co, company = comp, bestPrice = price;
			else if(co == bestComp && price < bestPrice)
				bestComp = co, company = comp, bestPrice = price;
		}
		cin >> rfp >> p;
		cout << "RFP #" << i << endl;
		cout << company << endl;
		if(rfp || p)	cout << endl;
		++i;
	}
	return 0;
}
