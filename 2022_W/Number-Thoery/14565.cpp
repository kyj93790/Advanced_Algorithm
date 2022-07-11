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
    *y = temp - (a / b) * (*y);
    if (*x <= 0) {
        *x += b;
        *y -= a;
    }
    return (gcd);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n, a;
    cin >> n >> a;
    cout << n-a << ' ';
    ll x, y;
    ll gcd = EEA(a, n, &x, &y);
    if (gcd == 1) {
        cout << x << '\n';
    }
    else cout << -1 << '\n';
    return (0);
}