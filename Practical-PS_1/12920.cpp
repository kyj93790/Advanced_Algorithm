#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define max(a, b) (a>=b?a:b)
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, m;
vector<pair<ll, ll> > item;
ll dp[2020][10101];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    item.push_back(p(0, 0));
    for (int i=0; i<n; i++) {
        ll v, c, k;
        cin >> v >> c >> k;
        ll sum=0, digit=1;
        while (sum+digit<=k) {
            item.push_back(p(v*digit, c*digit));
            sum += digit;
            digit*=2;
        }
        if (sum < k) {
            item.push_back(p(v*(k-sum), c*(k-sum)));
        }
    }
    for (int i=1; i<item.size(); i++) {
        for (int j=0; j<=m; j++) {
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if (j >= item[i].first) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-item[i].first] + item[i].second);
            }
        }
    }
    cout << dp[item.size()-1][m] << '\n';
    return 0;
}