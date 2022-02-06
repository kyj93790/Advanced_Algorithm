#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;

ll n, m;
ll SN;
ll sn[20202];           // x_i, ~x_i가 소속된 SCC 정보 저장
bool fin[20202];        // SCC 처리 정보 저장
vector<ll> v[20202];    // 간선 정보 저장
stack<ll> s;            // 타잔 알고리즘을 위한 stack
ll dfsn[20202];
ll cnt;

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
	if (ret == dfsn[x]) { // SCC 하나 완성 >_<
		while (!s.empty()) {
			ll top = s.top();
			s.pop();
			sn[top] = SN;
			fin[top] = true;
			if (top == x) break;
		}
		SN++;
	}
	return ret;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll a, b;
    cin >> n >> m;
    for (ll i=0; i<m; i++) {
        cin >> a >> b;
        if (a < 0) a = -a + n;
        if (b < 0) b = -b + n;
        // ~a -> b, ~b->a 처리해주기
        v[rev(a)].push_back(b);
        v[rev(b)].push_back(a);
    }
	for (ll i=1; i<=2*n; i++) {
		if (!dfsn[i]) dfs(i);
	}
	int result = 1;
	for (ll i=1; i<=n; i++) {
		if (sn[i] == sn[i+n]) {
			result = 0;
			break;
		}
	}
	cout << result << '\n';
    return 0;
}