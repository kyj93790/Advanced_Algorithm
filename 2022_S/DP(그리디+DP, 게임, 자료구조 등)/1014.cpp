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
ll t, n, m;
char seat[11][11];
ll dp[11][1<<11];

bool check1(ll s) {
    ll prev = s & 1;
    for (ll i=1; i<m; i++) {
        if (s & (1 << i) && prev) return false;
        prev = s & (1 << i);
    }
    return true;
}

bool check2(ll s, ll r) {
    for (ll i=0; i<m; i++) {
        if (s & (1<<i) && seat[r][m-i] == 'x') return false;
    }
    return true;
}

bool check3(ll s1, ll s2, ll r) {
    for (ll i=0; i<m; i++) {
        if (s1 & (1<<i)) {
            if (i > 0 && (s2 & (1<<(i-1)))) return false;
            if (i < m-1 && (s2 & (1<<(i+1)))) return false;
        }
    }
    return true;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (ll i=0; i<=n; i++) {
            for (ll j=0; j<(1<<m); j++) dp[i][j] = 0;
        }
        for (ll i=0; i<=m; i++) seat[0][i] = 'x';
        for (ll i=0; i<=n; i++) seat[i][0] = 'x';
        for (ll i=1; i<=n; i++) {
            for (ll j=1; j<=m; j++) cin >> seat[i][j];
        }
        ll ans = 0;
        for (ll i=1; i<=n; i++) {
            for (ll j=0; j<(1<<m); j++) { // i번째 행이 state j일 때
                if (!check1(j) || !check2(j, i)) continue;
                for (ll k=0; k<(1<<m); k++) {
                    if (!check1(k) || !check2(k, i-1) || !check3(j, k, i)) continue;
                    ll add = 0;
                    for (ll x=0; x<m; x++) {
                        if (j & (1<<x)) add++;
                    }
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + add);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
