#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll tree[303030], arr[101010];

void update(ll n, ll l, ll r, ll i, ll j, ll k)
{
    if (j < l || r < i) return ;
    if (i <= l && r <= j) {
        tree[n] += k;
        return ;
    }
    ll m = (l+r)/2;
    update(2*n, l, m, i, j, k);
    update(2*n+1, m+1, r, i, j, k);
}

ll query(ll n, ll l, ll r, ll idx, ll w) {
    if (idx < l || r < idx) return (0);
    w += tree[n];
    if (l == r) return (w);
    ll m = (l+r) / 2;
    return (query(2*n, l, m, idx, w) + query(2*n+1, m+1, r, idx, w));
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n, m, op, a, b, c;
    cin >> n;
    for (ll i=1; i<=n; i++) cin >> arr[i];
    cin >> m;
    for (ll i=0; i<m; i++) {
        cin >> op;
        if (op == 1) {
            cin >> a >> b >> c;
            update(1, 1, n, a, b, c);
        } else {
            cin >> a;
            cout << arr[a] + query(1, 1, n, a, 0) << '\n';
        }
    }
    return 0;
}