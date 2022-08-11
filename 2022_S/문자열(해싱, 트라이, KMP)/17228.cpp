#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
#include <tuple>
#include <cmath>
#include <set>
#include <numeric>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
vector<pair<ll, char> > edge[505050];
ll n, H, B=1, C=917, M=998244353;
string s;
// 경로의 hash값을 저장할 예정
vector<ll> stk;
ll ans;

void dfs(int v) {
    if (stk.size() > s.size()) {
        // string 길이만큼만 stack에서 hash처리
        ll curr = (stk.back() - stk[stk.size()-s.size()-1] * B) % M;
        if (curr < 0) curr += M;
        if (curr == H) ans++;
    }
    for (ll i=0; i<edge[v].size(); i++) {
        stk.push_back((stk.back() * C + edge[v][i].second) % M);
        dfs(edge[v][i].first);
        stk.pop_back();
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (ll i=0; i<n-1; i++) {
        ll u, v; char c;
        cin >> u >> v >> c;
        edge[u].push_back({v, c});
    }
    cin >> s;
    // string s의 hash 값 계산
    for (ll i=0; i<s.length(); i++) {
        H = (H * C + s[i]) % M;
        B = B * C % M;
    }
    stk.push_back(0);
    dfs(1);
    cout << ans << '\n';
    return 0;
}