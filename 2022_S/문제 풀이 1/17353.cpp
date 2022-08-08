#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll tree[303030], arr[101010], lazy[303030];

void init(ll n, ll l, ll r) {
    if (l>r) return ;
    if (l==r) {
        tree[n] = arr[l] - arr[l-1];
        return ;
    }
    ll m = (l+r)/2;
    init(2*n, l, m);
    init(2*n+1, m+1, r);
    tree[n] = tree[2*n] + tree[2*n+1];
}

void update_lazy(ll n, ll l, ll r) {
    if (!lazy[n]) return ;
    tree[n] += (r-l+1)*lazy[n];
    if (l != r) {
        ll m = (l+r)/2;
        lazy[2*n] += lazy[n];
        lazy[2*n+1] += lazy[n];
    }
    lazy[n] = 0;
}

void update(ll n, ll l, ll r, ll s, ll e, ll val) {
    update_lazy(n, l, r);
    if (r<s || e<l) return;
    if (s<=l && r<=e) {
        tree[n] += (r-l+1)*val;
        if (l != r) {
            lazy[2*n] += val;
            lazy[2*n+1] += val;
        }
        return ;
    }
    ll m = (l+r)/2;
    update(2*n, l, m, s, e, val);
    update(2*n+1, m+1, r, s, e, val);
    tree[n] = tree[2*n] + tree[2*n+1];
}

ll query(ll n, ll l, ll r, ll s, ll e) {
    update_lazy(n, l, r);
    if (r<s || e<l) return 0;
    if (s<=l && r<=e) return tree[n];
    ll m = (l+r)/2;
    return query(2*n, l, m, s, e) + query(2*n+1, m+1, r, s, e);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n, l, r, x, q, op;
    cin >> n;
    for (ll i=1; i<=n; i++) cin >> arr[i];
    init(1, 1, n);
    cin >> q;
    for (ll i=0; i<q; i++) {
        cin >> op;
        if (op == 1) { // 1 l r
            cin >> l >> r;
            update(1, 1, n, l, r, 1);
            update(1, 1, n, r+1, r+1, -(r-l+1));
        } else { // 2 x
            cin >> x;
            cout << query(1, 1, n, 1, x) << '\n';
        }
    }
    return 0;
}