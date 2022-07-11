#include <iostream>
using namespace std;

typedef long long ll;

ll EEA(ll a, ll b, ll *x, ll *y) {
	if (!b) {
		*x = 1; *y = 0;
		return (a);
	}
	ll gcd = EEA(b, a%b, x, y);
	ll temp = *x;
	*x = *y;
	*y = temp - (a/b)*(*y);
    if (*x < 0) {
        *x += b;
        *y -= a;
    }
	return (gcd);
}

int main(void) {
	cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		ll k, c;
		cin >> k >> c;
		ll x, y;
		ll gcd = EEA(k, c, &x, &y);
        while (c*y <= k) y+=k;
		if (gcd != 1 || y > 1000000000) cout << "IMPOSSIBLE\n";
		else {
			cout << y << '\n';
		}
	}
	return 0;
}