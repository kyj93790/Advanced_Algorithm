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
ll n, u, v, q;
double p[505050], sum[505050];
vector<ll> edge[505050];
vector<pair<ll, double> > query;
ll after[505050];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cout << fixed;
    cout.precision(7);
    cin >> n;
    double ans = 0;
    for (ll i=1; i<=n; i++) {
        cin >> p[i];
        ans += p[i];
    }
    for (ll i=1; i<n; i++) { // 양방향
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
        sum[u] += p[v];
        sum[v] += p[u];
        ans += p[u]*(1-p[v]) + p[v]*(1-p[u]);
    }
    cout << ans << '\n';
    cin >> q;
    ll x; double y;
    for(ll i=0; i<q; i++) {
        cin >> x >> y;
        query.push_back({x, y});
        after[x]++;
    }
    for (ll i=0; i<q; i++) {
        x = query[i].first; y = query[i].second;
        after[x]--;
        ans = ans - p[x] + y;
        ans = ans - sum[x]*(1-p[x]) - (edge[x].size() - sum[x])*p[x] + sum[x]*(1-y) + (edge[x].size() - sum[x])*y;
        cout << ans << '\n';
        for (auto j : edge[x]) {
            if (!after[j]) continue;
            sum[j] = sum[j] - p[x] + y;
        }
        p[x] = y;
    }
    return 0;
}
