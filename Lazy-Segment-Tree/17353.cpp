#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, m, k, a, b, c, d, q;
const ll n_ = 4 * 1e5 + 100;
ll tree[n_], lazy[n_], arr[n_];

void init(ll N, ll s, ll e) {
	if (s == e) {
		tree[N] = arr[s]-arr[s-1];
		return ;
	}
	ll mid = (s+e)/2;
	init(N*2, s, mid);
	init(N*2+1, mid+1, e);
	tree[N] = tree[2*N] + tree[2*N+1];
}

// propagate를 진행하는 함수
// 자신의 구간에 lazy만큼 더하고 자식 노드의 lazy 값을 더해줌.
void update_lazy(ll N, ll s, ll e) {
	if (!lazy[N]) return;
	tree[N] += (e-s+1)*lazy[N]; // 나중에 더해주기로 한 값을 실제로 범위만큼 곱해서 더함
	if (s != e) {
		lazy[N*2] += lazy[N];
		lazy[N*2+1] += lazy[N];
	}
	lazy[N] = 0;
}

void update(ll N, ll s, ll e, ll l, ll r, ll val) {
	// propagation 작업 실행하는 함수
	// 지금 현재 앞에서 update해야 하는데 미룬게 있다면 전파시킴
	update_lazy(N, s, e);
	if (l>e || r<s) return;
	if (l<=s && e<=r) {
		tree[N] += (e-s+1)*val;	// 구간의 길이만큼 곱해서 update
		if (s != e) {	// leaf 노드가 아니라면 왼쪽, 오른쪽 자식에 각각 업데이트하지 않은 val 값을 저장
			lazy[N*2] += val;
			lazy[N*2+1] += val;
		}
		return;
	} 
	ll mid = (s+e)/2;
	update(N*2, s, mid, l, r, val);
	update(N*2+1, mid+1, e, l, r, val);
	tree[N] = tree[N*2] + tree[N*2+1];
}

// 구간 합을 구하는 함수
ll f(ll N, ll s ,ll e, ll l, ll r) {
	// propagate을 먼저 진행해준 뒤 구간 합을 구함
	update_lazy(N, s, e);
	if (l > e || r < s) return 0;
	if (l <= s && e <= r) return tree[N];
	ll mid = (s + e) / 2;
	return f(N*2, s, mid, l, r) + f(N*2+1, mid+1, e, l, r);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> arr[i];
	}
	init(1, 1, n);
    cin >> q;
	for (int i=0; i<q; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			update(1, 1, n, b, c, 1);
            // 영향권 바로 근접한 수는 점화식에 의해 음수 가중치를 얻게 됨
            update(1, 1, n, c+1, c+1, -(c-b+1));
		} else {
			cin >> b;
            // segment tree가 B[i] = A[i]-A[i-1] 꼴이므로
            // A[x] = B[1] + B[2] + ... + B[b]
			cout << f(1, 1, n, 1, b) << '\n';
		}
	}
    return 0;
}