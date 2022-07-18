#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll N;
ll tree[6060606];

void update(ll n, ll l, ll r, ll x, ll cnt)
{
    if (x < l || r < x) return ;
    tree[n] += cnt;
    if (l == r) return ;
    ll m = (l+r) / 2;
    update(2*n, l, m, x, cnt);
    update(2*n+1, m+1, r, x, cnt);
}

ll query(ll n, ll l, ll r, ll x, ll keep)
{
    if (l == r) return l;
    ll m = (l+r) / 2;
    if (keep + tree[2*n] >= x) return query(2*n, l, m, x, keep);
    else return query(2*n+1, m+1, r, x, keep+tree[2*n]);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    N = 2000000;
    ll n, t, x;
    cin >> n;
    while (n--) {
        cin >> t >> x;
        if (t == 1) {
            update(1, 1, N, x, 1);
        } else {
            ll ans = query(1, 1, N, x, 0);
            cout << ans << '\n';
            update(1, 1, N, ans, -1);
        }
    }
    return 0;
}