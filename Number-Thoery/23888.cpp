#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    int r;
    while (1) {
        int r = a % b;
        if (r == 0) return (b);
        a = b;
        b = r;
    }
}

int main(void){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    ll a, d;
    cin >> a >> d;
    ll q;
    cin >> q;
    while (q--) {
        ll x, y, z;
        cin >> x >> y >> z;
        if (x == 1) {
            ll sum;
            sum = z*(2*a + (z-1)*d)/ 2 - (y-1)*(2*a + (y-2)*d) / 2;
            cout << sum << '\n';
        }
        else if (x == 2) {
            if (y == z) cout << a + (y-1)*d << '\n';
            else {
                ll GCD = gcd(a + (y-1)*d, d);
                cout << GCD << '\n';
            }
        }
    }
    return (0);
}