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
ll t, n, m, k, a, b, c, d, N;
ll road[4040], C[4040];
vector<ll> edge[4040], rev[4040], v;

ll opp(ll x) {
    if (x <= N) return (x+N);
    return (x-N);
}

void add_edge(ll x, ll y) {
    edge[opp(x)].push_back(y);
    edge[opp(y)].push_back(x);
    rev[y].push_back(opp(x));
    rev[x].push_back(opp(y));
}

void init() {
    memset(road, 0, sizeof(road));
    memset(C, 0, sizeof(C));
    for (ll i=0; i<4040; i++) {
        while (!edge[i].empty()) edge[i].pop_back();
        while (!rev[i].empty()) rev[i].pop_back();
    }
    while (!v.empty()) v.pop_back();
}

void dfs(ll curr) {
    C[curr] = -1;
    for (auto i : edge[curr]) if (!C[i]) dfs(i);
    v.push_back(curr);
}

void dfs2(ll curr, ll g) {
    C[curr] = g;
    for (auto i : rev[curr]) if (C[i] == -1) dfs2(i, g);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        init();
        cin >> n >> m >> k;
        N = n + m; // N+1~ :  세로 도로
        for (ll i=0; i<k; i++) {
            cin >> a >> b >> c >> d;
            b += n;
            d += n;
            if (a == c && b == d) continue; // 출발지, 도착지 동일
            if (a == c) { // 가로 route만 가능
                if (b < d) {
                    edge[opp(a)].push_back(a); // aVa
                    rev[a].push_back(opp(a));
                } else {
                    edge[a].push_back(opp(a)); // ~aV~a
                    rev[opp(a)].push_back(a);
                }
            } else if (b == d) { // 세로 route만 가능
                if (a < c) {
                    edge[opp(b)].push_back(b); // bVb
                    rev[b].push_back(opp(b));
                } else {
                    edge[b].push_back(opp(b)); // ~bV~b
                    rev[opp(b)].push_back(b);
                }
            } else { // AD + BC = (A+B)(B+D)(A+C)(C+D)
                if (a > c) {
                    b = opp(b);
                    d = opp(d);
                }
                if (b > d) {
                    a = opp(a);
                    c = opp(c);
                }
                add_edge(a, b);
                add_edge(b, d);
                add_edge(a, c);
                add_edge(c, d);
            }
        }
        for (ll i=1; i<=N; i++) if (!C[i]) dfs(i);
            reverse(v.begin(), v.end());
            ll cnt = 0;
            for (auto i : v) {
                if (C[i] == -1) dfs2(i, ++cnt);
            }
            ll ans = 1;
            for (ll i=1; i<=N; i++) {
                if (C[i] == C[i+N]) ans = 0;
            }
            if (ans) cout << "Yes\n";
            else cout << "No\n";
    }
    return 0;
}
