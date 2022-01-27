#include <iostream>
using namespace std;

typedef long long ll;
ll n, m;
ll arr[1010101];
ll tree[3030303];

// Ai~Aj에 대한 가중치 처리
void update(ll N, ll s, ll e, ll i, ll j, ll k) {
    if (e < i || j < s) return ;
    if (i <= s && e <= j) {
        tree[N] += k;
        return ;
    }
    ll mid = (s + e)/2;
    update(2*N, s, mid, i, j, k);
    update(2*N+1, mid+1, e, i, j, k);
}

ll query(ll N, ll s, ll e, ll x, ll w) {
    if (x < s || e < x) return 0;
    w += tree[N];
    if (s == e) return w;
    ll mid = (s + e)/2;
    if (x <= mid) return query(2*N, s, mid, x, w);
    else return query(2*N+1, mid+1, e, x, w);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (ll i=1; i<=n; i++) cin >> arr[i];
    cin >> m;
    for (ll i=0; i<m; i++) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll i, j, k;
            cin >> i >> j >> k;
            update(1, 1, n, i, j, k);
        } else {
            ll x;
            cin >> x;
            cout << arr[x] + query(1, 1, n, x, 0) << '\n';
        }
    }
    return 0;
}