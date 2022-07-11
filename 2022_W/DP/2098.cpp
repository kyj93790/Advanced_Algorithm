#include <iostream>
#define inf 1<<24
#define min(a, b) (a>b?b:a)
using namespace std;

typedef long long ll;
ll w[17][17];
ll dp[1 << 17][17];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> w[i][j];
        }
    }
    // dp inf로 초기화
    for (int i=1; i<(1 << n); i++) {
        for (int j=0; j<n; j++) {
            dp[i][j] = inf;
        }
    }
    // start node는 0이라고 가정 -> 어차피 cycle이니까 상관 x
    dp[1][0] = 0;
    ll result = inf;
    for (int i=1; i<(1<<n); i++) {
        for (int j=0; j<n; j++) {
            if (!(i & (1<<j))) continue; // i와 j의 정보가 일치하지 않음.
            // j->k로의 간선에 대한 처리
            for (int k=0; k<n; k++) {
                if (!w[j][k] || (i & (1<<k))) continue;
                ll x = i | (1<<k);
                dp[x][k] = min(dp[x][k], dp[i][j] + w[j][k]);
            }
        }
    }
    for (int i=0; i<n; i++) {
        if (w[i][0]) {
            result = min(result, dp[(1<<n)-1][i] + w[i][0]);
        }
    }
    cout << result << '\n';
    return (0);
}