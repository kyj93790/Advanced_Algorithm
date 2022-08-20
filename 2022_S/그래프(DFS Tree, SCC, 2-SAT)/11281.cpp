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
ll n, m, a, b;
vector<ll> edge[20202], rev[20202], v; // n+1 ~ 2n range는 not(~)
ll C[20202], ans[20202];
vector<vector<ll> > SCC;

ll notx(ll x) {
    if (x <= n) return (x+n);
    else return (x-n);
}

void dfs(ll curr) {
    C[curr] = -1;
    for (auto i : edge[curr]) if (!C[i]) dfs(i);
    v.push_back(curr);
}

void dfs2(ll curr, ll g) {
    C[curr] = g;
    SCC.back().push_back(curr);
    for (auto i : rev[curr]) {
        if (C[i] == -1) dfs2(i, g);
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        if (a < 0) a = -a + n;
        if (b < 0) b = -b + n;
        edge[notx(a)].push_back(b);
        rev[b].push_back(notx(a));
        edge[notx(b)].push_back(a);
        rev[a].push_back(notx(b));
    }
    for (ll i=1; i<=2*n; i++) if (!C[i]) dfs(i);
    reverse(v.begin(), v.end());
    ll cnt = 0;
    for (auto i : v) {
        if (C[i] == -1) {
            SCC.emplace_back();
            dfs2(i, ++cnt);
        }
    }
    for (ll i=1; i<=n; i++) {
        if (C[i] == C[i+n]) {
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';
    for (ll i=0; i<cnt; i++) {
        for (auto j : SCC[i]) {
            if (ans[j]) continue;
            ans[j] = 0;
            ans[notx(j)] = 1;
        }
    }
    for (ll i=1; i<=n; i++) cout << ans[i] << ' ';
    return 0;
}
