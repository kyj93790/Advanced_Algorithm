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
vector<vector<ll> > v(100001);
ll d[101010];
ll f[101010][21]; // f[x][y] : x의 2^y번째 부모

void dfs(ll x, ll par) {
    d[x] = d[par] + 1;
    // 현재 x의 자식들에 대해서 재귀 호출
    for (ll i=0; i<v[x].size(); i++) {
        if (v[x][i] == par) continue;
        f[v[x][i]][0] = x;
        dfs(v[x][i], x);
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll a, b;
    for (ll i=0; i<n-1; i++) { // O(n)
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    // 각 node들의 depth 계산하기
    dfs(1, 0);
    for (ll y=1; y<=20; y++) {
        for (ll x=1; x<=n; x++) {
            f[x][y] = f[f[x][y-1]][y-1];
        }
    }
    ll m;
    cin >> m;
    while (m--) {
        cin >> a >> b;
        if (d[a] > d[b]) swap(a, b); // 항상 b의 depth가 크도록 함
        // 깊이 맞춰주기
        ll temp = d[b] - d[a];
        ll digit = 0;
        while (temp) {
            if (temp%2) b = f[b][digit];
            temp /= 2;
            digit++;
        }
        // 최상위 조상부터 차례로 내려오면서 같은지 다른지 check
        for (ll y=20; y>=0; y--) {
            if (f[a][y] != f[b][y]) {
                a = f[a][y];
                b = f[b][y];
            }
        }
        if (a == b) cout << a << '\n'; // 깊이 맞추고 바로 같아지는 경우
        else cout << f[a][0] << '\n';
    }
    return 0;
}