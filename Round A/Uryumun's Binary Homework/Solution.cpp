/*May The Force Be With Me*/
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define endl "\n"
#define vll vector<long long>
#define pll pair<long long, long long>
#define all(c) c.begin(),c.end()
#define f first
#define s second
#define inf INT_MAX
#define size_1d 10000000
#define size_2d 10000
#define mem(a,val) memset(a,val,sizeof(a))
//Snippets: bigint, bsearch, graph, splitstring, segtree, delta

using namespace std;

ll N, ans;
string bary;

void Input() {
	cin >> N, bary.clear();
	while (N >= 2) {
		bary += ('0' + (N % 2));
		N /= 2;
	}
	bary += ('0' + N);
	bary += '0';
}

void Solve() {
	reverse(all(bary));
	next_permutation(all(bary));
	ans = 0;
	for (ll i = 0; i < bary.size(); i++) {
		if (bary[i] == '1')
			ans += (pow(2, bary.size() - 1 - i));
	}
	cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	ll T = 1;
	cin >> T;
	while (T--) {
		Input();
		Solve();
	}
	return 0;
}