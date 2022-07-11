#include <iostream>
using namespace std;

typedef long long ll;
ll arr[1010101];
ll tree[3030303];

void update(ll N, ll s, ll e, ll idx) {
    if (s == e) {
        if (s == idx) tree[N]++;
        return ;
    }
    ll mid = (s+e)/2;
    if (idx <= mid) update(2*N, s, mid, idx);
    else update(2*N+1, mid+1, e, idx);
    tree[N] = tree[2*N] + tree[2*N+1];
}

ll query(ll N, ll s, ll e, ll l, ll r) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return tree[N];
    ll mid = (s+e)/2;
    return (query(2*N, s, mid, l, r) + query(2*N+1, mid+1, e, l, r));
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (ll i=0; i<n; i++) {
        ll temp;
        cin >> temp;
        arr[temp] = i;
    }
    ll ans = 0;
    for (int i=n; i>0; i--) {
        ans = ans + query(1, 0, n-1, 0, arr[i]);
        update(1, 0, n-1, arr[i]);
    }
    cout << ans << '\n';
    return 0;
}