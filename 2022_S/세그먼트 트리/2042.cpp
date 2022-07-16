#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll in[1010101], tree[3030303];

void init(ll n, ll l, ll r)
{
    if (l > r) return ;
    if (l == r) {
        tree[n] = in[l];
        return ;
    }
    init(2*n, l, (l+r)/2);
    init(2*n+1, (l+r)/2 + 1, r);
    tree[n] = tree[2*n] + tree[2*n+1];
}

void update(ll n, ll l, ll r, ll idx, ll val)
{
    if (idx < l || idx > r) return ;
    if (l == r) {
        tree[n] = val;
        return ;
    }
    update(2*n, l, (l+r)/2, idx, val);
    update(2*n+1, (l+r)/2+1, r, idx, val);
    tree[n] = tree[2*n] + tree[2*n+1];
}

ll f(ll n, ll l, ll r, ll s, ll e)
{
    if (e < l || r < s) return 0;
    if (s <= l && r <= e) return tree[n];
    return (f(2*n, l, (l+r)/2, s, e) + f(2*n+1, (l+r)/2+1, r, s, e));
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n, m, k;
    ll i, a, b, c;
    cin >> n >> m >> k;
    for (i=1; i<=n; i++) cin >> in[i];
    init(1, 1, n);
    for (i=0; i<m+k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 1, n, b, c);
        } else {
            cout << f(1, 1, n, b, c) << '\n';
        }
    }
    return 0;
}