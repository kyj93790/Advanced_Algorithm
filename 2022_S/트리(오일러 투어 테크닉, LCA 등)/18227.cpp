#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <tuple>
using namespace std;
#define p(a, b) make_pair(a, b)
#define n_ 202020

typedef long long ll;
ll n, c, x, y, q, visit[n_], in[n_], out[n_], cnt, tree[3*n_], d[n_];
vector<ll> child[n_], edge[n_];

void dfs(ll curr, ll dth) {
    visit[curr] = 1;
    cnt++;
    in[curr] = cnt; // id
    d[curr] = dth;
    for (auto i : edge[curr]) {
        if (visit[i]) continue;
        dfs(i, dth+1);
    }
    out[curr] = cnt;
}

void update(ll N, ll l, ll r, ll idx) {
    if (idx < l || r < idx) return ;
    if (l == r) {
        tree[N]++;
        return ;
    }
    ll m = (l+r)/2;
    update(2*N, l, m, idx);
    update(2*N+1, m+1, r, idx);
    tree[N] = tree[2*N] + tree[2*N+1];
}

ll query(ll N, ll l, ll r, ll s, ll e) {
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return tree[N];
    ll m = (l+r)/2;
    return query(2*N, l, m, s, e) + query(2*N+1, m+1, r, s, e);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> c;
    for (ll i=0; i<n-1; i++) {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(c, 1);
    cin >> q;
    for (ll i=0; i<q; i++) {
        cin >> x >> y;
        if (x == 1) { // y 도시에 물 채움
            update(1, 1, n, in[y]);
        } else {
            cout << d[y] * query(1, 1, n, in[y], out[y]) << '\n';
        }
    }
    return 0;
}
