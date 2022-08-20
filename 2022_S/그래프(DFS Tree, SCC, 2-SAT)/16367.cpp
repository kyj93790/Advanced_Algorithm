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
ll k, n, l;
char c;
vector<ll> edge[10101], rev[10101], v;
ll C[10101], ans[10101];
vector<vector<ll> > SCC;

int opp(int x) {
    if (x <= k) return (x + k);
    return (x - k);
}

void dfs(ll curr) {
    C[curr] = -1;
    for (auto i : edge[curr]) if (!C[i]) dfs(i);
    v.push_back(curr);
}

void dfs2(ll curr, ll g) {
    C[curr] = g;
    SCC.back().push_back(curr);
    for (auto i : rev[curr]) if (C[i] == -1) dfs2(i, g);
}

void add_edge(ll u, ll v) {
    edge[opp(u)].push_back(v);
    edge[opp(v)].push_back(u);
    rev[v].push_back(opp(u));
    rev[u].push_back(opp(v));
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> k >> n;
    for (ll i=0; i<n; i++) {
        ll tmp[3];
        for (ll j=0; j<3; j++) {
            cin >> l >> c;
            if (c == 'B') tmp[j] = opp(l);
            else tmp[j] = l;
        }
        add_edge(tmp[0], tmp[1]);
        add_edge(tmp[1], tmp[2]);
        add_edge(tmp[2], tmp[0]);
    }
    for (ll i=1; i<=2*k; i++) if (!C[i]) dfs(i);
    reverse(v.begin(), v.end());
    ll cnt = 0;
    for (auto i : v) {
        if (C[i] == -1) {
            SCC.emplace_back();
            dfs2(i, ++cnt);
        }
    }
    for (ll i=1; i<=k; i++) {
        if (C[i] == C[i+k]){
            cout << -1 << '\n';
            return (0);
        }
    }
    for (ll i=0; i<cnt; i++) {
        for (auto j : SCC[i]) {
            if (ans[j]) continue;
            ans[j] = 0;
            ans[opp(j)] = 1;
        }
    }
    for (ll i=1; i<=k; i++) {
        if (ans[i]) cout << 'R';
        else cout << 'B';
    }
    return 0;
}
