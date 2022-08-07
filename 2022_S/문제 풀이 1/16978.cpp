#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
using namespace std;

typedef long long ll;
ll arr[101010], tree[303030];
vector<pair<ll, ll> > q1;
vector<tuple <ll, ll, ll, ll> > q2; // k, i, j, idx(기존)
vector<pair<ll, ll> > ans;

void init(ll n, ll l, ll r) {
    if (l>r) return ;
    if (l==r) {
        tree[n] = arr[l];
        return ;
    }
    ll m = (l+r)/2;
    init(2*n, l, m);
    init(2*n+1, m+1, r);
    tree[n] = tree[2*n] + tree[2*n+1];
}

void update(ll n, ll l, ll r, ll idx, ll val) {
    if (idx < l || r < idx) return ;
    if (l == r) {
        tree[n] = val;
        return ;
    }
    ll m = (l+r)/2;
    update(2*n, l, m, idx, val);
    update(2*n+1, m+1, r, idx, val);
    tree[n] = tree[2*n] + tree[2*n+1];
}

ll query(ll n, ll l, ll r, ll s, ll e) {
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return tree[n];
    ll m = (l+r)/2;
    return query(2*n, l, m, s, e) + query(2*n+1, m+1, r, s, e);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n, m;
    cin >> n;
    for (ll i=1; i<=n; i++) cin >> arr[i];
    init(1, 1, n);
    cin >> m;
    ll op, k, x, y, cnt=0;
    for (ll i=0; i<m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            q1.push_back({x, y});
        } else {
            cin >> k >> x >> y;
            q2.push_back({k, x, y, cnt++});
        }
    }
    sort(q2.begin(), q2.end());
    ll j=0;
    cnt = 0;
    while (j < q2.size() || cnt < q1.size()) {
        while (j < q2.size()) {
            if (get<0>(q2[j]) > cnt) break;
            ans.push_back({get<3>(q2[j]), query(1, 1, n, get<1>(q2[j]), get<2>(q2[j]))});
            j++;
        }
        update(1, 1, n, q1[cnt].first, q1[cnt].second);
        cnt++;
    }
    sort(ans.begin(), ans.end());
    for (ll i=0; i<ans.size(); i++) {
        cout << ans[i].second << '\n';
    }
    return 0;
}