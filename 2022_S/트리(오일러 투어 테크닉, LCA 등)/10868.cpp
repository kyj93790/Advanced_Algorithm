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
#define n_ 101010

typedef long long ll;
ll n, m, a, b, arr[n_], tree[3*n_];

void init(ll N, ll l, ll r) {
    if (l == r) {
        tree[N] = arr[l];
        return ;
    }
    ll m = (l+r)/2;
    init(2*N, l, m);
    init(2*N+1, m+1, r);
    tree[N] = min(tree[2*N], tree[2*N+1]);
}

ll query(ll N, ll l, ll r, ll s, ll e) {
    if (e < l || r < s) return 1e10;
    if (s <= l && r <= e) return tree[N];
    ll m = (l+r)/2;
    return min(query(2*N, l, m, s, e), query(2*N+1, m+1, r, s, e));
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    for (ll i=1; i<=n; i++) cin >> arr[i];
    init(1, 1, n);
    for (ll i=0; i<m; i++) {
        cin >> a >> b;
        cout << query(1, 1, n, a, b) << '\n';
    }
    return 0;
}
