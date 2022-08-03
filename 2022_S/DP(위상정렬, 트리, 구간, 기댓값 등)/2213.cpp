#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, u, v;
ll w[10101], visit[10101];
vector<ll> ans;
vector<ll> edge[10101], edge_out[10101];
pair<ll, ll> dp[10101]; // max, prev_idx
queue<ll> q;

void f(ll curr) {
    if (edge_out[curr].empty()) {
        dp[curr].first = w[curr];
        dp[curr].second = 0;
        return ;
    }
    ll sum_ex = 0, sum_in = 0;
    for (ll i=0; i<edge_out[curr].size(); i++) {
        ll next = edge_out[curr][i];
        f(next);
        sum_ex += dp[next].second;
        sum_in += max(dp[next].second, dp[next].first);
    }
    dp[curr].first = sum_ex + w[curr];
    dp[curr].second = sum_in;
}

void find_ans(int ex, ll curr) {
    if (!ex && dp[curr].first >= dp[curr].second) {
        ans.push_back(curr);
        for (ll i=0; i<edge_out[curr].size(); i++) {
            find_ans(1, edge_out[curr][i]);
        }
    } else {
        for (ll i=0; i<edge_out[curr].size(); i++) {
            find_ans(0, edge_out[curr][i]);
        }
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (ll i=1; i<=n; i++) cin >> w[i];
    for (ll i=1; i<n; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    q.push(1);
    visit[1] = 1;
    while (!q.empty()) {
        ll curr = q.front(); q.pop();
        for (ll i=0; i<edge[curr].size(); i++) {
            ll next = edge[curr][i];
            if (visit[next]) continue;
            visit[next] = 1;
            edge_out[curr].push_back(next);
            q.push(next);
        }
    }
    f(1);
    cout << max(dp[1].first, dp[1].second) << '\n';
    find_ans(0, 1);
    sort(ans.begin(), ans.end());
    for (ll i=0; i<ans.size(); i++) cout << ans[i] << ' ';
    return 0;
}