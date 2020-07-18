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

ll N, M, r, c, cnt;
char arr[25][25];
bool visited[25][25];

void FloodFill(ll i, ll j) {
	if (i + 1 < N and !visited[i + 1][j] and arr[i + 1][j] == '.') {
		visited[i + 1][j] = 1;
		cnt++;
		FloodFill(i + 1, j);
	}

	if (i - 1 >= 0 and !visited[i - 1][j] and arr[i - 1][j] == '.') {
		visited[i - 1][j] = 1;
		cnt++;
		FloodFill(i - 1, j);
	}

	if (j + 1 < M and !visited[i][j + 1] and arr[i][j + 1] == '.') {
		visited[i][j + 1] = 1;
		cnt++;
		FloodFill(i, j + 1);
	}

	if (j - 1 >= 0 and !visited[i][j - 1] and arr[i][j - 1] == '.') {
		visited[i][j - 1] = 1;
		cnt++;
		FloodFill(i, j - 1);
	}
}

void Input() {
	cin >> N >> M, cnt = 1, mem(visited, false);
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '@') {
				r = i, c = j;
				visited[i][j] = true;
			}
		}
	}
}

void Solve() {
	FloodFill(r, c);
	cout << cnt << endl;
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