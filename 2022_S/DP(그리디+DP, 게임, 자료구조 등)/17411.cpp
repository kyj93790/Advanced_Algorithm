#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)
#define M 1000000007

typedef long long ll;
vector<ll> comp;
ll arr[1010101];
pair<ll, ll> tree[3030303]; // max segtree

pair<ll, ll> merge(pair<ll, ll> p, pair<ll, ll> q) {
    if (p.first == q.first) return {p.first, (p.second + q.second) % M};
    return max(p, q);
}

void update(ll n, ll l, ll r, ll idx, pair<ll, ll> val)
{
    if (idx < l || r < idx) return ;
    if (l == r) {
        tree[n] = merge(tree[n], val);
        return ;
    }
    ll m = (l+r)/2;
    update(2*n, l, m, idx, val);
    update(2*n+1, m+1, r, idx, val);
    tree[n] = merge(tree[2*n], tree[2*n+1]);
}

pair<ll, ll> query(ll n, ll l, ll r, ll s, ll e)
{
    if (e < l || r < s) return {0, 0};
    if (s <= l && r <= e) return tree[n];
    ll m = (l+r)/2;
    return merge(query(2*n, l, m, s, e), query(2*n+1, m+1, r, s, e));
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n, a;
    cin >> n;
    for (ll i=0; i<n; i++) {
        cin >> arr[i];
        comp.push_back(arr[i]);
    }
    // 좌표 압축
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end()); // 중복 제거
    // idx를 찾아서 그 값을 활용 (대소 관계만 중요하기 때문)
    for (ll i=0; i<n; i++) arr[i] = lower_bound(comp.begin(), comp.end(), arr[i]) - comp.begin() + 1;
    pair<ll, ll> temp, m = {0, 0};
    ll N = 1000000;
    for (ll i=0; i<n; i++) {
        temp = query(1, 1, N, 1, arr[i]-1);
        temp.first++;
        if (!temp.second) temp.second = 1;
        m = merge(m, temp);
        update(1, 1, N, arr[i], temp);
    }
    cout << m.first << ' ' << m.second << '\n';
    return 0;
}