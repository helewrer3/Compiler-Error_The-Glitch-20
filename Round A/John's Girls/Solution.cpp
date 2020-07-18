/*May The Force Be With Me*/
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll N, Q, T, L, R;
vector<ll> arr_tree, arr_lazy;

void UpdateTree(ll l, ll r, ll node, ll st, ll ed) {
    ll mid = st + (ed - st) / 2;

    if (arr_lazy[node] % 2 == 1) {
        arr_tree[node] = (ed - st + 1) - arr_tree[node];
        if (st != ed) {
            arr_lazy[2 * node]++;
            arr_lazy[2 * node + 1]++;
        }
        arr_lazy[node] = 0;
    }

    if (st > ed or l > ed or r < st) {
        return;
    }

    if (l <= st and r >= ed) {
        arr_tree[node] = (ed - st + 1) - arr_tree[node];
        if (st != ed) {
            arr_lazy[2 * node]++;
            arr_lazy[2 * node + 1]++;
        }
    }
    else {
        UpdateTree(l, r, 2 * node, st, mid);
        UpdateTree(l, r, 2 * node + 1, mid + 1, ed);

        arr_tree[node] = arr_tree[2 * node] + arr_tree[2 * node + 1];
    }
    return;
}

ll SumTree(ll l, ll r, ll node, ll st, ll ed) {
    ll mid = st + (ed - st) / 2;

    if (arr_lazy[node] % 2 == 1) {
        arr_tree[node] = (ed - st + 1) - arr_tree[node];
        if (st != ed) {
            arr_lazy[2 * node]++;
            arr_lazy[2 * node + 1]++;
        }
        arr_lazy[node] = 0;
    }

    if (st > ed or l > ed or r < st)
        return 0;

    if (l <= st and r >= ed)
        return arr_tree[node];

    return (SumTree(l, r, 2 * node, st, mid) + SumTree(l, r, 2 * node + 1, mid + 1, ed));
}

void Input() {
    cin >> N >> Q, arr_tree.resize(4 * N), arr_lazy.resize(4 * N), fill(arr_lazy.begin(), arr_lazy.end(), 0), fill(arr_tree.begin(), arr_tree.end(), 0);
}

void Solve() {
    while (Q--) {
        cin >> T >> L >> R;
        if (T == 0) {
            UpdateTree(L, R, 1, 0, N - 1);
        }
        else {
            cout << SumTree(L, R, 1, 0, N - 1) << "\n";
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T = 1;
    //cin >> T;
    while (T--) {
        Input();
        Solve();
    }
    return 0;
}