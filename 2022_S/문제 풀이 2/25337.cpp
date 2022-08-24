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
ll n, v, w;
vector<pair<ll, ll> > edge[202020]; // (next node, color)
ll sum[202020]; // node가 포함되는 group의 sum
ll group[202020]; 
ll a[202020], b[202020], d[202020], visit[202020], par[202020], c[202020];

ll find(ll v) {
    if (v == par[v]) return v;
    return find(par[v]);
}

void merge(ll u, ll v) {
    u = find(u);
    v = find(v);
    if (d[u] < d[v]) par[u] = par[v];
    else {
        par[v] = par[u];
        if (d[u] == d[v]) d[u]++;
    }
}

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    return (c[a.second] < c[b.second]);
}

bool comp2(pair<ll, ll> a, pair<ll, ll> b) {
    return (find(a.second) < find(b.second));
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (ll i=1; i<n; i++) { // tree edge
        cin >> v >> w >> c[i];
        edge[v].push_back({w, i});
        edge[w].push_back({v, i});
    }
    for (ll i=1; i<=n; i++) cin >> a[i];
    for (ll i=1; i<=n; i++) cin >> b[i];
    for (ll i=1; i<=n; i++) {
        par[i] = i;
        d[i] = 1;
    }
    for (ll i=1; i<=n; i++) sort(edge[i].begin(), edge[i].end(), comp);
    for (ll i=1; i<=n; i++) {
        for (ll j=1; j<edge[i].size(); j++) {
            if (c[edge[i][j-1].second] == c[edge[i][j].second])
                merge(edge[i][j-1].second, edge[i][j].second);
        }
    }
    // 그룹에 속한 정점들의 가중치 합
    for (ll i=1; i<=n; i++) sort(edge[i].begin(), edge[i].end(), comp2);
    for (ll i=1; i<=n; i++) {
        group[find(edge[i][0].second)] += a[i];
        for (ll j=1; j<edge[i].size(); j++) {
            if (find(edge[i][j-1].second) != find(edge[i][j].second)) group[find(edge[i][j].second)] += a[i];
        }
    }
    // 각 정점이 속한 그룹의 가중치 합
    for (ll i=1; i<=n; i++) {
        sum[i] += group[find(edge[i][0].second)];
        for (ll j=1; j<edge[i].size(); j++) {
            if (find(edge[i][j-1].second) != find(edge[i][j].second)) sum[i] += group[find(edge[i][j].second)];
        }
    }
    sort(b+1, b+n+1);
    sort(sum+1, sum+n+1);
    ll mn = 0, mx = 0;
    for (ll i=1; i<=n; i++) {
        mx += b[i]*sum[i];
        mn += b[n-i+1]*sum[i];
    }
    cout << mn << '\n' << mx << '\n';
    return 0;
}
