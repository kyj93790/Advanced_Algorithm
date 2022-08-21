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
ll n, m, N, x, y, z, d, b;
ll a[50505], bit[505050], C[505050], ans[505050];
vector<ll> edge[505050], rev[505050], v;
vector<vector<ll> > SCC;
char t;

ll opp(ll x) {
    if (x <= N) return (x+N);
    else return (x-N);
}

void add_edge(ll u, ll v) {
    edge[u].push_back(v);
    rev[v].push_back(u);
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

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    N = 5*n;
    for (ll i=1; i<=n; i++) {
        // 나이 setting : 8살 이상 19살 이하
        ll j = (i-1)*5+1;
        add_edge(j+4, opp(j+3));
        add_edge(j+3, opp(j+4));
        add_edge(j+4, opp(j+2));
        add_edge(j+2, opp(j+4));
        add_edge(opp(j+4), j+3);
        add_edge(opp(j+3), j+4);
        cin >> a[i];
        if (a[i] == 0) continue;
        d = 1; b = 0;
        while (b < 5) {
            if (a[i] & d) { // pVp
                add_edge(opp(j), j);
            } else { // ~pV~p
                add_edge(j, opp(j));
            }
            b++; j++;
            d = d << 1;
        }
    }
    cin >> m;
    for (ll i=0; i<m; i++) {
        cin >> t >> x >> y >> z;
        ll xi, yi; // bit 위치
        xi = (x-1)*5+1;
        yi = (y-1)*5+1;
        d = 1; b = 0;
        if (t == '&') {
            while (b < 5) {
                if (z & d) { // 둘 다 반드시 1
                    add_edge(opp(xi), xi);
                    add_edge(opp(yi), yi);
                } else { // 둘 중 하나가 0 : 하나가 1이면 다른 하나가 0
                    add_edge(xi, opp(yi));
                    add_edge(yi, opp(xi));
                }
                d = d << 1;
                xi++; yi++; b++;
            }
        } else { // t == '|'
            while (b < 5) {
                if (z & d) { // 둘 중 하나는 1 : 하나가 0이면 다른 하나가 1
                    add_edge(opp(xi), yi);
                    add_edge(opp(yi), xi);
                } else { // 둘 다 0
                    add_edge(xi, opp(xi));
                    add_edge(yi, opp(yi));
                }
                d = d << 1;
                xi++; yi++; b++;
            }
        }
    }
    for (ll i=1; i<=2*N; i++) if (!C[i]) dfs(i);
    reverse(v.begin(), v.end());
    ll cnt = 0;
    for (auto i : v) {
        if (C[i] == -1) {
            SCC.emplace_back();
            dfs2(i, ++cnt);
        }
    }
    ll flag = 1;
    for (ll i=1; i<=N; i++) {
        if (C[i] == C[i+N]) flag = 0;
    }
    if (!flag) cout << 0 << '\n';
    else {
        cout << 1 << '\n';
        for (ll i=0; i<cnt; i++) {
            for (auto j : SCC[i]) {
                if (ans[j]) continue;
                ans[j] = 0;
                ans[opp(j)] = 1;
            }
        }
        for (ll i=1; i<=N; i+=5) {
            ll sum = 0;
            d = 1; b = 0;
            while (b < 5) {
                sum += ans[i+b] * d;
                d = d << 1;
                b++;
            }
            cout << sum << ' ';
        }
    }
    return 0;
}
