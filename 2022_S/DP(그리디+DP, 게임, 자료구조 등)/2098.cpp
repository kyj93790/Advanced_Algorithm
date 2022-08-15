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
ll n;
ll w[17][17], dp[1<<17][17];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (ll i=0; i<n; i++) {
        for (ll j=0; j<n; j++) cin >> w[i][j];
    }
    for (ll i=0; i<(1<<n); i++) {
        for (ll j=0; j<n; j++) dp[i][j] = 1<<24;
    }
    dp[1][0] = 0;
    for (ll i=1; i<(1<<n); i++) {
        for (ll j=0; j<n; j++) {
            if (!((1<<j) & i)) continue;
            for (ll k=0; k<n; k++) {
                if (!w[j][k] | (i & (1<<k))) continue;
                ll nxt = i | (1<<k);
                dp[nxt][k] = min(dp[nxt][k], dp[i][j] + w[j][k]);
            }
        }
    }
    ll ans = 1<<24;
    for (ll i=0; i<n; i++) {
        if (w[i][0]) ans = min(ans, dp[(1<<n)-1][i] + w[i][0]);
    }
    cout << ans << '\n';
    return 0;
}
