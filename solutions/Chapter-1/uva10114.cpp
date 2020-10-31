// UVa 10114 - Loansome Car Buyer
#include <bits/stdc++.h>
#define debug(v,len) for(long long int i=0;i<len;++i)cout<<v[i]<<" ";cout<<endl;
#define debugMatrix(name,row,col) for(long long int i=0;i<row;++i){for(long long int j=0;j<col;++j)cout<<name[i][j]<<" ";cout<<endl;}
#define print(v) cout<<v<<endl;
#define gcd(v,h) __gcd(v,h)
#define popcount(v) __builtin_popcount(v)
#define sl(T) scanf("%lld",&T)
using namespace std;
typedef long long ll;
typedef double lf;
typedef vector<ll> vll;

int main(){

	lf months, downPay, total, records;
	cin >> months >> downPay >> total >> records;

	while(months > 0){

		vector<lf> depR(months + 5);
		for(int i = 0;i < records;++i){
			int a;
			lf b;
			cin >> a >> b;
			for(int j = a;j < months + 5;++j)
				depR[j] = b;
		}

		lf cut = total/months;
		int mon = 0;
		lf curDep = depR[mon];
		lf car = downPay + total;
		car -= car*curDep;
		while(car < total){
			mon++;
			curDep = depR[mon];
			total -= cut;
			car -= car*curDep;
		}

		if(mon == 1)
			cout << "1 month" << endl;
		else
			cout << mon << " months" << endl;

		cin >> months >> downPay >> total >> records;

	}


	return 0;
}
