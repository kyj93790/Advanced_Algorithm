#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)
#define p(a, b) make_pair(a, b)

typedef long long ll;
void swap(ll *a, ll *b) {
    ll temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

vector<vector<pair <ll, ll> > > v(40404);
pair<ll, ll> f[40404][21];
ll d[40404];

void dfs(ll x, ll par) {
    d[x] = d[par] + 1;
    for (int i=0; i<v[x].size(); i++) {
        if (v[x][i].first == par) continue;
        f[v[x][i].first][0] = p(x, v[x][i].second);
        dfs(v[x][i].first, x);
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll a, b, c;
    for (int i=0; i<n-1; i++) {
        cin >> a >> b >> c;
        v[a].push_back(p(b, c));
        v[b].push_back(p(a, c));
    }
    // root를 아무거나 잡아도 상관 x -> 1을 root로 가정
    dfs(1, 0);
    // 전처리
    for (int j=1; j<=20; j++) {
        for(int i=1; i<=n; i++) {
            f[i][j].first = f[f[i][j-1].first][j-1].first;
            f[i][j].second = f[i][j-1].second + f[f[i][j-1].first][j-1].second;
        }
    }
    ll m;
    cin >> m;
    while (m--){
        ll ans = 0;
        cin >> a >> b;
        if (d[a] > d[b]) swap(a, b);
        // depth 맞춰주기.
        for (int i=20; i>=0; i--) {
            if (d[b]-d[a] >= (1<<i)) {
                ans += f[b][i].second;
                b = f[b][i].first;
            }
        }
        if (a == b) {
            cout << ans << '\n';
            continue;
        }
        // lca
        for (int i=20; i>=0; i--) {
            if (f[a][i].first != f[b][i].first) {
                ans += f[a][i].second + f[b][i].second;
                a = f[a][i].first;
                b = f[b][i].first;
            }
        }
        ans += f[a][0].second + f[b][0].second;
        cout << ans << '\n';
    }
    return 0;
}