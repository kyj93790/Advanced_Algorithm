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
#define n_ 505050

typedef long long ll;
ll n, u, v;
ll cnt, in[n_], out[n_], a[n_], odd[n_];
vector<ll> child[n_], ans;
vector<pair<ll, ll> > sub;

// Euler Tour Techniqu
void dfs(ll curr, ll d)
{
    cnt++;
    in[curr] = cnt;
    sub.push_back({a[curr], d});
    for (auto i : child[curr]) {
        dfs(i, d + 1);
        sub.push_back({a[curr], d});
        cnt++;
    }
    out[curr] = cnt;
}

void manachers_odd(void)
{
    ll l = 0, r = -1, sz;
    for (ll i = 0; i < sub.size(); i++)
    {
        if (i <= r)
            sz = min(r - i + 1, odd[l + r - i]);
        else
            sz = 1;
        while (i - sz >= 0 && i + sz < sub.size() && sub[i - sz] == sub[i + sz])
            sz++;
        odd[i] = sz--;
        if (i + sz > r)
        {
            l = i - sz;
            r = i + sz;
        }
    }
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i];
    for (ll i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        child[u].push_back(v);
    }
    for (ll i = 1; i <= n; i++)
        sort(child[i].begin(), child[i].end());
    dfs(1, 1);
    manachers_odd();
    for (ll i = 1; i <= n; i++)
    {
        ll m = (in[i]-1 + out[i]-1) / 2;
        if (odd[m] >= (out[i]-in[i])/2)
            ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (ll i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}
