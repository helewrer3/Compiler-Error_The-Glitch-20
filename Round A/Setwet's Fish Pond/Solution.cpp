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
char arr[size_1d];

void Input() {
	cin >> N;
	for (ll i = 0; i < N; i++)
		cin >> arr[i];
}

void Solve() {
	ans = 0;
	for (ll i = 0; i < N; i++) {
		if (arr[i] == '.') {
			ans++;
			arr[i] = '#';
			if (i + 1 < N)
				arr[i + 1] = '#';
			if (i + 2 < N)
				arr[i + 2] = '#';
		}
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
	ll t = 1;
	while (T--) {
		Input();
		Solve();
	}
	return 0;
}