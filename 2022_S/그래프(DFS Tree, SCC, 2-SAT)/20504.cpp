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
ll N, M, u, v, T, t, ans;
vector<ll> edge[202020], rev[202020], V, res, edge_out[202020];
ll C[202020], visit[202020], in[202020];
// queue<ll> q;

void dfs(int curr) {
    C[curr] = -1;
    for (auto i : edge[curr]) if (!C[i]) dfs(i);
    V.push_back(curr);
}

void dfs2(int curr, int g) {
    C[curr] = g;
    for (auto i : rev[curr]) {
        if (C[i] == -1) dfs2(i, g);
        else if (C[i] != g) {
            in[g]++;
            edge_out[C[i]].push_back(g);
        }
    }
}

void dfs3(int curr) {
    visit[curr] = 1;
    for (auto i : edge_out[curr]) {
        if (!visit[i]) dfs3(i);
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> M;
    for (ll i=0; i<M; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
        rev[v].push_back(u);
    }
    for (ll i=1; i<=N; i++) if (!C[i]) dfs(i);
    reverse(V.begin(), V.end());
    ll cnt = 0;
    for (auto i : V) {
        if (C[i] == -1) {
            dfs2(i, ++cnt);
            res.push_back(C[i]);
        }
    }
    cin >> T;
    while (T--) {
        cin >> t;
        if (!in[C[t]] && !visit[C[t]]) {
            ans++;
            dfs3(C[t]);
        }
    }
    for (ll i=1; i<=cnt; i++) {
        if (!visit[i]) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans << '\n';
    return 0;
}
