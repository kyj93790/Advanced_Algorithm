#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, m, t, q, x, y, z;
char a;
ll tree[404040];
ll lazy[404040];

void swap(ll *a, ll *b) {
    ll temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// 대입 연산 진행
void update_lazy(ll N, ll s, ll e) {
    if (!lazy[N]) return;
    tree[N] = lazy[N];
    if (s!=e) {
        lazy[N*2] = lazy[N];
        lazy[N*2+1] = lazy[N];
    }
    lazy[N] = 0;
}

void update(ll N, ll s, ll e, ll l, ll r, ll val) {
    update_lazy(N, s, e);
    if (e<l || r<s) return;
    if (l<=s && e<=r) { // 그 하위 tree는 전부 하나의 종류 -> 대입 연산으로 처리 가능
        tree[N] = val;
        if (s!=e) {
            lazy[N*2] = val;
            lazy[N*2+1] = val;
        }
        return;
    }
    ll mid = (s+e)/2;
    update(N*2, s, mid, l, r, val);
    update(N*2+1, mid+1, e, l, r, val);
    tree[N] = tree[N*2] | tree[N*2+1];  // OR 연산 -> 종류를 bit로 인식할 수 있음
}

ll f(ll N, ll s, ll e, ll l, ll r) {
    update_lazy(N, s, e);
    if (l>e || r<s) return 0;
    if (l<=s && e<=r) return tree[N];
    ll mid = (s+e)/2;
    return f(N*2, s, mid, l, r) | f(N*2+1, mid+1, e, l, r);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> t >> q;
    update(1, 1, n, 1, n, 1);
    while (q--) {
        cin >> a;
        if (a == 'C') {
            cin >> x >> y >> z;
            if (x > y) swap(&x, &y);
            update(1, 1, n, x, y, (ll)1 << (z - 1));
        } else {
            cin >> x >> y;
            if (x > y) swap(&x, &y);
            x = f(1, 1, n, x, y);
            y = 0;
            while (x) {
                if (x%2) y++;   // bit이 1인 갯수 count -> 색 종류
                x /= 2;
            }
            cout << y << '\n';
        }
    }
    return 0;
}