#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)

typedef long long ll;
ll dp[10101];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        // 구조체 -> 메모리 초과..
        vector<pair<ll, pair<ll, ll> > > v(m);
        for (int i=0; i<m; i++) {
            // <가격, <갯수, 배송비>>
            cin >> v[i].second.first >> v[i].first >> v[i].second.second;
        }
        sort(v.begin(), v.end());
        for (int i=1; i<=n; i++) dp[i] = 1000000000000;
        dp[0] = 0;
        ll ans = 1000000000000;
        for (int i=0; i<m; i++) {
            ll s = v[i].second.first , p = v[i].first, o = v[i].second.second;
            for (int j=n; j>=0; j--) {
                // 현재 품목에 대한 구매로 n개를 정확히 살 수 있을 때 -> min check
                if (j + s >= n) ans = min(ans, dp[j] + o + (n-j)*p);
                // greedy 하게 품목 구매 (s개 전부 구매함); 전부 구매하지 못하는 케이스(마지막 선택 store)는 위의 if문에서 처리됨
                if (j >= s) dp[j] = min(dp[j], dp[j-s] + o + s*p);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}