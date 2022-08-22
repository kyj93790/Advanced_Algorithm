#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <tuple>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, k, ans;
string a[10101], rev[10101];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k;
    for (ll i=0; i<n; i++) {
        cin >> a[i];
        ans += a[i].length();
    }
    sort(a, a+n);
    for (ll i=1; i<n; i++) {
        ll j;
        for (j=0; j<k; j++) {
            if (a[i][j] != a[i-1][j]) break;
        }
        ans -= j;
        reverse(a[i-1].begin(), a[i-1].end());
    }
    reverse(a[n-1].begin(), a[n-1].end());
    sort(a, a+n);
    for (ll i=1; i<n; i++) {
        ll j;
        for (j=0; j<k; j++) {
            if (a[i][j] != a[i-1][j]) break;
        }
        ans -= j;
    }
    cout << ans << '\n';
    return 0;
}
