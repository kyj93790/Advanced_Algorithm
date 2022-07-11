#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll f[200010][20]; // f_2^y(x)

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll m;
    cin >> m;
    for (ll i=1; i<=m; i++) {
        cin >> f[i][0];
    }
    for (ll y=1; y<20; y++) {
        for (ll x=1; x<=m; x++) {
            f[x][y] = f[f[x][y-1]][y-1];
        }
    }
    ll q;
    cin >> q;
    while (q--) {
        ll n, x;
        cin >> n >> x;
        ll ans=0, digit=0;
        while (n) {
            if (n%2) {
                if (!ans) ans = f[x][digit];
                else ans = f[ans][digit];
            }
            n /= 2;
            digit++;
        }
        cout << ans << '\n';
    }
    return 0;
}