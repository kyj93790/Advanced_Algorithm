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
#define n_ 505050

typedef long long ll;
ll N, m, p;
ll cnt, in[n_], out[n_], s[n_], tree[3*n_];
vector<ll> child[n_];

// Euler Tour Technique
void dfs(ll curr) {
    cnt++;
    in[curr] = cnt;
    for (auto i : child[curr]) dfs(i);
    out[curr] = cnt;
}

void update(ll n, ll l, ll r, ll s, ll e, ll x) {
    if (r < s || e < l) return ;
    if (s <= l && r <= e) {
        tree[n] += x;
        return ;
    }
    ll m = (l+r)/2;
    update(2*n, l, m, s, e, x);
    update(2*n+1, m+1, r, s, e, x);
}

ll query(ll n, ll l, ll r, ll a, ll sum) {
    if (a < l || r < a) return 0;
    sum += tree[n];
    if (l == r) return sum;
    ll m = (l+r)/2;
    return query(2*n, l, m, a, sum) + query(2*n+1, m+1, r, a, sum);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> m;
    cin >> s[1];
    for (ll i=2; i<=N; i++) {
        cin >> s[i] >> p;
        child[p].push_back(i);
    }
    dfs(1);
    char op; int a, x;
    for (ll i=0; i<m; i++) {
        cin >> op;
        if (op == 'p') {
            cin >> a >> x;
            update(1, 1, N, in[a]+1, out[a], x);
        } else {
            cin >> a;
            cout << query(1, 1, N, in[a], 0) + s[a] << '\n';
        }
    }
    return 0;
}
