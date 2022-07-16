#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll tree[3030303];

void update(ll n, ll l, ll r, ll val, ll cnt)
{
    if (val < l || r < val) return;
    if (l == r) {
        tree[n] += cnt;
        return;
    }
    ll m = (l+r)/2;
    update(2*n, l, m, val, cnt);
    update(2*n+1, m+1, r, val, cnt);
    tree[n] = tree[2*n] + tree[2*n+1];
}

ll pop(ll n, ll l, ll r, ll idx, ll keep)
{
    if (l == r) return l;
    ll m = (l+r)/2;
    // tree[n]--;
    if (keep + tree[2*n] >= idx) return pop(2*n, l, m, idx, keep);
    else return pop(2*n+1, m+1, r, idx, keep+tree[2*n]);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n, a, b, c, num;
    cin >> n;
    ll N = 1000000;
    while (n--) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            num = pop(1, 1, N, b, 0);
            cout << num << '\n';
            update(1, 1, N, num, -1);
        } else {
            cin >> b >> c;
            update(1, 1, N, b, c);
        }
    }
    return 0;
}