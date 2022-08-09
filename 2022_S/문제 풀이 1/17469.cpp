#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll root[101010], par[101010], d[101010];
set<ll> color[101010];
stack<ll> ans;
stack<pair<ll, ll> > s;
ll n, q, x, a, c;
set<ll>::iterator it;

ll find(ll u) {
    if (root[u] == u) return u;
    return find(root[u]);
}

void merge(ll u, ll v) {
    u = find(u);
    v = find(v);
    // set의 크기가 큰 쪽이 union-find 상에서 부모가 되도록 구현
    if (color[u].size() < color[v].size()) {
        root[u] = root[v];
        for (it=color[u].begin(); it!=color[u].end(); it++) {
            color[v].insert(*it);
        }
    } else if (color[u].size() > color[v].size()){
        root[v] = root[u];
        for (it=color[v].begin(); it!=color[v].end(); it++) {
            color[u].insert(*it);
        }
    } else {
        if (d[u] < d[v]) {
             root[u] = root[v];
            for (it=color[u].begin(); it!=color[u].end(); it++) {
                color[v].insert(*it);
            }
        } else {
            root[v] = root[u];
            for (it=color[v].begin(); it!=color[v].end(); it++) {
                color[u].insert(*it);
            }
            if (d[u] == d[v]) d[u]++;
        }
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> q;
    for (ll i=2; i<=n; i++) cin >> par[i];
    for (ll i=1; i<=n; i++) {
        cin >> c;
        color[i].insert(c);
        root[i] = i;
        d[i] = 1;
    }
    for (ll i=0; i<n+q-1; i++) {
        cin >> x >> a;
        s.push({x, a});
    }
    pair<ll, ll> temp;
    ll ra;
    while (!s.empty()) {
        temp = s.top(); s.pop();
        x = temp.first;
        a = temp.second;
        if (x == 1) merge(par[a], a);
        else {
            ra = find(a);
            ans.push(color[ra].size());
        }
    }
    while (!ans.empty()) {
        cout << ans.top() << '\n';
        ans.pop();
    }
    return 0;
}