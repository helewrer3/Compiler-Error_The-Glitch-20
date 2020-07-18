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

ll N, chk;

void Input() {
	cin >> N, chk = 0;
	for (ll i = 0; i < N; i++) {
		ll a, b;
		cin >> a >> b;
		chk ^= (b - a - 1);
	}
}

void Solve() {
	if (chk)
		cout << "Priyansh\n";
	else
		cout << "Priyanshi\n";
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