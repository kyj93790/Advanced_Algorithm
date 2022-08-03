#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)
#define r 0
#define c 1

typedef long long ll;
ll mat[505][2];
ll n;
ll dp[505][505]; // [x, y]번 행렬을 합치는 비용

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (ll i=1; i<=n; i++) {
        cin >> mat[i][r] >> mat[i][c];
        dp[i][i] = 0;
    }
    for (ll l=2; l<=n; l++) {
        for (ll s=1; s<=n-l+1; s++) {
            ll e = s+l-1, mn=1e10;
            for (ll m=s; m<e; m++) {
                ll cost = mat[s][r]*mat[m][c]*mat[e][c];
                mn = min(mn, dp[s][m] + dp[m+1][e] + cost);
            }
            dp[s][e] = mn;
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}