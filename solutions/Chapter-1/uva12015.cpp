// UVa 12015 - Google is Feeling Lucky
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool compare(pair<ll, string> a, pair<ll, string> b){
return a.first < b.first;
}

int main() {
    int t;
    cin >> t;
    for(ll q = 1;q <= t;++q){
    vector<pair<ll, string> > output(10);
    for(int i = 0;i < 10;++i)
        cin >> output[i].second >> output[i].first;
    stable_sort(output.begin(), output.end(), compare);
    ll high = output[9].first;
    cout << "Case #" << q << ":" << endl;
    for(int i = 0;i < 10;++i)
    if(high == output[i].first)
        cout << output[i].second << endl;
    }
return 0;
}
