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
vector<ll> edge[505050], rev[505050], V, edge_out[505050];
ll atm[505050], rest[505050], C[505050], in[505050], able[505050], mx[505050];
pair<ll, ll> comp[505050];
queue<ll> q;

void dfs(ll curr) {
    C[curr] = -1;
    for (auto i : edge[curr]) if (!C[i]) dfs(i);
    V.push_back(curr);
}

pair<ll, ll> dfs2(ll curr, ll g) {
    pair<ll, ll> sum = {atm[curr], rest[curr]};
    C[curr] = g;
    set<ll> tmp;
    for (auto i : rev[curr]) {
        if (C[i] == -1) {
            pair<ll, ll> x = dfs2(i, g);
            sum.first += x.first;
            sum.second += x.second;
        }
        else if (C[i] != g) {
            if (tmp.find(C[i]) == tmp.end()) {
                in[g]++;
                tmp.insert(C[i]);
                edge_out[C[i]].push_back(g);
            }
        }
    }
    return sum;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N >> M;
    for (ll i=0; i<M; i++) {
        cin >> a >> b;
        edge[a].push_back(b);
        rev[b].push_back(a);
    }
    for (ll i=1; i<=N; i++) {
        cin >> atm[i];
    }
    cin >> S >> P;
    for (ll i=0; i<P; i++) {
        cin >> a;
        rest[a] = 1;
    }
    for (ll i=1; i<=N; i++) if (!C[i]) dfs(i);
    reverse(V.begin(), V.end());
    ll cnt = 0;
    pair<ll, ll> tmp;
    for (auto i : V) {
        if (C[i] == -1) {
            cnt++;
            comp[cnt] = dfs2(i, cnt);
        }
    }
    able[C[S]] = 1;
    for (ll i=1; i<=cnt; i++){
        mx[i] = comp[i].first;
        if (!in[i]) q.push(i);
    } 
    while (!q.empty()) {
        ll curr = q.front(); q.pop();
        for (auto i : edge_out[curr]) {
            if (able[curr]) {
                mx[i] = max(mx[i], mx[curr] + comp[i].first);
                able[i] = 1;
            }
            if (--in[i] == 0) q.push(i);
        }
    }
    ll ans = 0;
    for (ll i=1; i<=cnt; i++) {
        if (able[i] && comp[i].second) ans = max(ans, mx[i]);
    }
    cout << ans << '\n';
    return 0;
}
