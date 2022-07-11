#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)
#define inf 3*10e12
typedef long long ll;

ll dp[10101][5];
ll arr[10101][5];

int cmpItem(vector<int> a, vector<int> b) {
    ll sum_a = 0, sum_b = 0;
    for (int i=0; i<5; i++) {
        sum_a += a[i];
        sum_b += b[i];
    }
    return (sum_a >= sum_b);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4];
        }
        ll ans = 0;
        ll i, j;
        for (i=1; i<=n; i++) {
            for (j=k; j>=1; j--) {
                ll sum = 0;
                ll pre = 0;
                for (int r=0; r<5; r++) {
                    pre += dp[j][r];
                    sum += max(dp[j-1][r],arr[i][r]);
                }
                if (pre < sum) {
                    for (int r=0; r<5; r++) {
                        dp[j][r] = max(dp[j-1][r],arr[i][r]);
                    }
                }
                if (j==k) {
                    ll temp = 0;
                    for (int r=0; r<5; r++) {
                        temp += dp[k][r];
                    }
                    ans = max(ans, temp);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}