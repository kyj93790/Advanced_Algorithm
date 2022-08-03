#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)
#define INF 1e16

typedef long long ll;
ll n, m, u, v, w, cnt;
vector<pair<ll, ll> > edge[202020];
priority_queue<pair<ll, ll> > pq;
queue<ll> q;
vector<ll> res, edge_in[202020], edge_out[202020], ans;
ll note[202020], visit[202020], dist[202020], in[202020];
pair<ll, ll> dp[202020];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    for (ll i=0; i<m; i++) {
        cin >> u >> v >> w;
        edge[v].push_back(p(u, w));
        edge[u].push_back(p(v, w));
    }
    for (ll i=1; i<=n; i++) {
        dist[i] = INF;
        cin >> note[i];
        if (note[i]) cnt++;
    }
    // 다익스트라
    dist[1] = 0;
    pq.push(p(0, 1)); // cost, vertex
    while (!pq.empty()) {
        ll cost = -pq.top().first, curr = pq.top().second; pq.pop();
        if (visit[curr]) continue;
        visit[curr] = 1;
        for (ll i=0; i<edge[curr].size(); i++) {
            ll next = edge[curr][i].first;
            if (visit[next]) continue;
            ll nextw = cost + edge[curr][i].second;
            if (nextw <= dist[next]) {
                dist[next] = nextw;
                pq.push(p(-nextw, next));
            }
        }
    }
    for (ll i=1; i<=n; i++) {
        for (ll j=0; j<edge[i].size(); j++) {
            ll next = edge[i][j].first, cost = edge[i][j].second;
            if (dist[next] == dist[i] + cost) {
                edge_out[i].push_back(next);
                edge_in[next].push_back(i);
            }
        }
    }
    for (ll i=1; i<=n; i++) in[i] = edge_in[i].size();
    // 위상정렬
    q.push(1);
    while (!q.empty()) {
        ll curr = q.front(); q.pop();
        res.push_back(curr);
        for (ll i=0; i<edge_out[curr].size(); i++) {
            ll next = edge_out[curr][i];
            if (--in[next] == 0) q.push(next);
        }
    }
    for (ll i=0; i<res.size(); i++) {
        ll curr = res[i], mx = 0, mx_idx = 0;
        for (ll j=0; j<edge_in[curr].size(); j++) {
            ll prev = edge_in[curr][j];
            if (mx <= dp[prev].first) {
                mx = dp[prev].first;
                mx_idx = prev;
            }
        }
        dp[curr].first = mx + note[curr];
        dp[curr].second = mx_idx;
    }
    if (dp[n].first != cnt) cout << -1 << '\n';
    else {
        ll idx = n;
        while (idx) {
            ans.push_back(idx);
            idx = dp[idx].second;
        }
        cout << ans.size() << '\n';
        for (ll i=ans.size()-1; i>=0; i--) cout << ans[i] << ' ';
    }
    return 0;
}