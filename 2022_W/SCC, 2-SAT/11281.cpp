#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define p(a, b) make_pair(a, b)
#define all(v) v.begin(), v.end()

typedef long long ll;
void swap(ll *a, ll *b) {
    ll temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

ll n, m;
vector<vector<ll> > SCC;
vector<ll> v[20202];
stack<ll> s;
ll dfsn[20202];
ll sn[20202];
bool fin[20202];
ll SN, cnt;
int ans[20202];

ll rev(ll x) {
    if (x <= n) return (x+n);
    else return (x-n);
}

ll dfs(ll x) {
    dfsn[x] = ++cnt;
    s.push(x);
    ll ret = dfsn[x];
    for (ll i=0; i<v[x].size(); i++) {
        ll nxt = v[x][i];
        if (!dfsn[nxt]) ret = min(ret, dfs(nxt));
        else if (!fin[nxt]) ret = min(ret, dfsn[nxt]);
    }
    if (ret == dfsn[x]) {
        vector<ll> temp;
        while (!s.empty()) {
            ll top = s.top();
            s.pop();
            fin[top] = true;
            sn[top] = SN;
            temp.push_back(top);
            if (top == x) break ;
        }
        SCC.push_back(temp);
        SN++;
    }
    return ret;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    ll a, b;
    while (m--) {
        cin >> a >> b;
        if (a < 0) a = -a + n;
        if (b < 0) b = -b + n;
        v[rev(a)].push_back(b);
        v[rev(b)].push_back(a);
    }
    for (ll i=1; i<=2*n; i++) {
        if (!dfsn[i]) dfs(i);
    }
    for (ll i=1; i<=n; i++) {
        if (sn[i] == sn[i+n]) {
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << 1 << "\n";
    // 타잔 알고리즘 -> 스택
    // 마지막에 발견된 SCC일수록 DAG에서는 앞쪽에 있음.
    // 가장 tree의 끝단에 있는 노드를 1로 만드는 것이 좋음.
    // 윗 단에서 true가 되면 그 아래도 연쇄적으로 영향을 받기 때문.
    reverse(SCC.begin(), SCC.end());
    for (ll i=0; i<SN; i++) {
        for (ll j=0; j<SCC[i].size(); j++) {
            ll curr = SCC[i][j];
            if (ans[curr]) continue;
            ans[curr] = 0;
            ans[rev(curr)] = 1;
        }
    }
    for (ll i=1; i<=n; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}