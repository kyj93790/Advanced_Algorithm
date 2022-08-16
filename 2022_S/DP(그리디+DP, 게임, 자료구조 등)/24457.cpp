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
pair<ll, ll> v[5050];
ll dp[5050][5050];

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.second != b.second) return (a.second < b.second);
    else return (a.first > b.first);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (ll i=1; i<=n; i++) cin >> v[i].first;
    for (ll i=1; i<=n; i++) cin >> v[i].second;
    sort(v+1, v+n+1, comp);
    for (ll i=1; i<=n; i++) {
        for (ll j=0; j<n; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j+1] + v[i].first - j*v[i].second);
        }
    }
    ll mx=0;
    for (ll i=1; i<=n; i++) mx = max(mx, dp[i][0]);
    cout << mx << '\n';
    return 0;
}
