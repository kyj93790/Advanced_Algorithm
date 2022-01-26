#include <iostream>
using namespace std;
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)

typedef long long ll;
typedef struct ans {
    ll max;
    ll min;
} ans;
ans tree[303030];
ll arr[101010];
ll n, m, a, b;

void init(ll N, ll s, ll e) {
    if (s == e) tree[N].max = tree[N].min = arr[s];
    else {
        ll mid = (s + e)/2;
        init(2*N, s, mid);
        init(2*N+1, mid+1, e);
        tree[N].max = max(tree[2*N].max, tree[2*N+1].max);
        tree[N].min = min(tree[2*N].min, tree[2*N+1].min);
    }
}

ans findans(ll N, ll s, ll e, ll l, ll r) {
    ans result;
    result.max = 0;
    result.min = 1e9;
    if (e < l || r < s) return result;
    if (l <= s && e <= r) return tree[N];
    ll mid = (s+e)/2;
    ans r1 = findans(2*N, s, mid, l, r);
    ans r2 = findans(2*N+1, mid+1, e, l, r);
    result.max = max(r1.max, r2.max);
    result.min = min(r1.min, r2.min);
    return result;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    for (ll i=0; i<n; i++) cin >> arr[i];
    init(1, 0, n-1);
    for (ll i=0; i<m; i++) {
        ll a, b;
        cin >> a >> b;
        ans result = findans(1, 0, n-1, a-1, b-1);
        cout << result.min << ' ' << result.max << '\n';
    }
    return 0;
}