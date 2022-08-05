#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll t;

ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

ll EEA(ll a, ll b, ll *x, ll *y) {
    if (!b) {
        *x = 1; *y = 0;
        return (a);
    }
    ll gcd = EEA(b, a%b, x, y);
    ll temp = *x;
    *x = *y;
    *y = temp - (a / b) * (*y);
    if (*x <= 0) {
        *x += b;
        *y -= a;
    }
    return (gcd);
}

ll mul(ll x, ll y, ll mod) {
    if (y == 0) return 0;
    if (y == 1) return (x%mod);
    ll tmp = mul(x, y/2, mod)%mod;
    ll res = ((tmp + tmp)%mod + mul(x, y%2, mod)%mod)%mod;
    return res;
}

// chinese remainder theorem
pair<ll, ll> crt(ll a1, ll m1, ll a2, ll m2) {
    ll x, y, g = gcd(m1, m2), c = a2-a1;
    if (c%g) return p(INT64_MAX, INT64_MAX);
    m1/=g;
    m2/=g;
    c/=g;

    EEA(m1, m2, &x, &y);
    x*=c;
    y*=c;

    m1*=g;
    pair<ll, ll> ans;
    ll mod = m1*m2;
    map<ll, ll> m;
    // x*m1에서 overflow 발생 가능
    ans.first = (mul(x, m1, mod) + a1)%mod;
    ans.second = mod;
    return ans;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        int a[3], m[3];
        for (int i=0; i<3; i++) cin >> m[i];
        for (int i=0; i<3; i++) cin >> a[i];
        // 연립 1
        pair<ll, ll> res = crt(a[0], m[0], a[1], m[1]);
        if (res.first == INT64_MAX) {
            cout << -1 << '\n';
            continue;
        }
        // 연립 2
        res = crt(res.first, res.second, a[2], m[2]);
        if (res.first == INT64_MAX) {
            cout << -1 << '\n';
            continue;
        }
        if (res.first < 0) { // 양수화
            ll q = abs(res.first);
            q %= res.second;
            res.first = res.second - q;
        }
        cout << res.first % res.second << '\n';
    }
    return 0;
}