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
ll N, M, a, b;
vector<ll> edge[10101], rev[10101], V;
ll C[10101];
vector<vector<ll> > ans;
ll cnt;

void dfs(int v) {
    C[v] = -1;
    for (ll i=0; i<edge[v].size(); i++) if (!C[edge[v][i]]) dfs(edge[v][i]);
    V.push_back(v);
}

void dfs2(int v, int c) {
    C[v] = c; // 소속 SCC number 저장
    ans.back().push_back(v);
    for (ll i=0; i<rev[v].size(); i++) {
        if (C[rev[v][i]] == -1) dfs2(rev[v][i], c);
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
    for (ll i=1; i<=N; i++) if (!C[i]) dfs(i); // 분리 component
    reverse(V.begin(), V.end());
    ll cnt = 0; // SCC 개수
    for (ll i=0; i<V.size(); i++) {
        if (C[V[i]] == -1) {
            ans.emplace_back(); // SCC 그룹 하나 증가
            dfs2(V[i], ++cnt);
        }
        sort(ans[cnt-1].begin(), ans[cnt-1].end());
    }
    sort(ans.begin(), ans.end());
    cout << cnt << '\n';
    for (ll i=0; i<cnt; i++) {
        for (ll j=0; j<ans[i].size(); j++) cout << ans[i][j] << ' ';
        cout << -1 << '\n';
    }
    return 0;
}
