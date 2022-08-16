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

typedef long long ll;
ll n, sum, x;
vector<pair<ll, ll> > seat;
bool dp[303][101010], sz[101010];
vector<ll> ans;

// 의석 합 : i
// minimum element : j
// 총 의석 수
void track(ll i, ll j, ll cnt) {
    ans.push_back(seat[j].second);
    if (i - seat[j].first == 0) {
        cout << cnt << '\n';
        for (ll k=0; k<cnt; k++) cout << ans[k] << ' ';
        return ;
    }
    for (ll k=j-1; k>=0; k--) {
        if (dp[k][i-seat[j].first]) {
            track(i-seat[j].first, k, cnt+1);
            return ;
        }
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (ll i=1; i<=n; i++) {
        cin >> x;
        sum += x;
        seat.push_back({x, i});
    }
    sort(seat.rbegin(), seat.rend());
    sz[0] = 1;
    dp[0][seat[0].first] = 1; sz[seat[0].first] = 1;
    for (ll i=1; i<n; i++) {
        // 가능한 sz check 필요
        for (ll j=100000 - seat[0].first; j>=0; j--) {
            if (sz[j]) {
                dp[i][j + seat[i].first] = 1;
                sz[j + seat[i].first] = 1;
            }
        }
    }
    // sz가 전체 의석의 절반 이상인 연합
    for (ll i=100000; i>sum/2; i--) {
        // j를 minimum element로 하는 조합
        for (ll j=0; j<n; j++) {
            // 가장 작은 원소를 빼면 유효하지 않은 연합이 되는지 check
            if (dp[j][i] && i - seat[j].first <= sum/2) {
                track(i, j, 1);
                return 0;
            }
        }
    }
    return 0;
}
