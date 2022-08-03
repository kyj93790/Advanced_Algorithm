#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, m, x, y;
ll arr[2002];
ll dp[2002][2002]; // [s, e]

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (ll i=1; i<=n; i++) {
        cin >> arr[i];
        dp[i][i] = 1;
    }
    for (ll l=2; l<=n; l++) {
        for (ll s=1; s<=n-l+1; s++) {
            ll e=s+l-1;
            if (arr[s] != arr[e]) dp[s][e] = 0;
            else {
                if (l==2 || dp[s+1][e-1]==1) dp[s][e] = 1;
                else dp[s][e] = 0;
            }
        }
    }
    cin >> m;
    for (ll i=0; i<m; i++) {
        cin >> x >> y;
        cout << dp[x][y] << '\n';
    }
    return 0;
}