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
ll N, M, P, S, a, b;
vector<ll> edge[404040], rev[404040], V, edge_out[404040], fi, se;
ll C[404040], in[404040], able[404040], mx[404040];
queue<ll> q;
ll r1[404040], r2[404040];

void dfs(ll curr) {
    C[curr] = -1;
    for (auto i : edge[curr]) if (!C[i]) dfs(i);
    V.push_back(curr);
}

void dfs2(ll curr, ll g) {
    C[curr] = g;
    set<ll> tmp;
    for (auto i : rev[curr]) {
        if (C[i] == -1) {
            dfs2(i, g);
        }
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> M;
    for (ll i=0; i<M; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        rev[b].push_back(a);
    }
    cin >> P;
    ll x;
    for (ll i=1; i<=P; i++) {
        cin >> x;
        fi.push_back(x);
    }
    for (ll i=1; i<=P; i++) {
        cin >> x;
        se.push_back(x);
    }
    for (ll i=1; i<=N; i++) if (!C[i]) dfs(i);
    reverse(V.begin(), V.end());
    ll cnt = 0;
    pair<ll, ll> tmp;
    for (auto i : V) {
        if (C[i] == -1) {
            cnt++;
            dfs2(i, cnt);
        }
    }
    // group 개수가 같으면
    for (auto i : fi) {
        r1[C[i]]++;
    }
    for (auto i : se) {
        r2[C[i]]++;
    }
    ll ans = 1;
    for (ll i=1; i<=cnt; i++) {
        if (r1[i] != r2[i]) ans = 0;
    }
    if (ans) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
