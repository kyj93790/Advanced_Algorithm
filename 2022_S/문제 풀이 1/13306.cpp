#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, q, a, b, c;
ll group[202020], par[202020], d[202020]; // group의 root, parent, tree depth
stack<pair<ll, ll> > s;
stack<string> ans;

ll find(ll u) {
    if (u == group[u]) return u;
    return find(group[u]);
}

void merge(ll u, ll v) {
    ll ru, rv;
    ru = find(u);
    rv = find(v);
    if (d[ru] < d[rv]) group[ru] = group[rv];
    else {
        group[rv] = group[ru];
        if (d[ru] == d[rv]) d[ru]++;
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> q;
    for (ll i=2; i<=n; i++) cin >> par[i];
    for (ll i=1; i<=n; i++) {
        group[i] = i;
        d[i] = 1;
    }
    for (ll i=0; i<n+q-1; i++) {
        cin >> a;
        if (a) {
            cin >> b >> c;
            s.push(p(b, c));
        } else {
            cin >> b;
            s.push(p(0, b));
        }
    }
    pair<ll, ll> tmp;
    while (!s.empty()) {
        tmp = s.top(); s.pop();
        b = tmp.first; c = tmp.second;
        if (b) { // query (b, c)
            if (find(b) == find(c)) ans.push("YES");
            else ans.push("NO");
        } else { // cut b -> merge
            merge(par[c], c);
        }
    }
    while (!ans.empty()) {
        cout << ans.top() << '\n';
        ans.pop();
    }
    return 0;
}