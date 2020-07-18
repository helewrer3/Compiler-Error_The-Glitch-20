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
#define size 10000000
#define mem(a,val) memset(a,val,sizeof(a))

using namespace std;

ll N, M, C;
ll arr_u[size], arr_d[size], arr_s[size], seg[10000][10000];

void Input() {
	cin >> N >> M >> C, mem(arr_u, 0), mem(arr_d, 0), mem(arr_s, 0), mem(seg, 0);
	seg[0][0] = 1;
	for (ll i = 0; i < N; i++) {
		ll d;
		cin >> d;
		arr_u[d]++;
	}
	for (ll i = 0; i < M; i++) {
		ll d;
		cin >> d;
		arr_d[d]++;
	}
	for (ll i =  0; i <= C; i++)
		arr_s[i] = ((arr_u[i] % MOD) * 1ll * (arr_d[i] % MOD)) % MOD;
}

void Solve() {
	for (ll k = 1; k <= C + 1; k++) {
		ll sum = 0;
		for (ll r = 1; r <= C; r++) {
			sum  = (sum % MOD + seg[k - 1][r - 1] % MOD) % MOD;
			seg[k][r] = ((sum % MOD) * 1ll * (arr_s[r] % MOD)) % MOD;
		}
	}

	ll ans = 0;
	for (ll k = 2; k <= C + 1; k++) {
		ans = 0;
		for (ll r = 1; r <= C; r++) {
			ans = (ans % MOD + seg[k][r] % MOD) % MOD;
		}
		cout << ans << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif

	ll T = 1;
	//cin >> T;
	while (T--) {
		Input();
		Solve();
	}
	return 0;
}