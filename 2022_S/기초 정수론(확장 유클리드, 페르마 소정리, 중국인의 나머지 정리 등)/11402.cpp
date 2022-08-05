#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, k, m;
ll fac[2020], inv[2020], base[70];

ll pow_mod(ll a, ll b, ll mod) {
    if (a == 0 || b == 0) return 1;
    if (b == 1) return (a%mod);
    ll tmp = pow_mod(a, b/2, mod);
	if (b%2==0) return tmp*tmp%mod;
    else return a*((tmp*tmp)%mod)%mod;
}

ll comb(ll n, ll r, ll m) {
    if (n < r) return 0;
    return (fac[n]*inv[n-r]%m*inv[r]%m);
}

// 뤼카의 정리
// n과 k를 모두 m진법으로 변환 (n>=k)
ll lucas(ll n, ll r, ll m) {
    if (n < r) return 0;
    if (n < 0 || r < 0) return 0;
    if (n == 0 || r == 0) return 1;
    if (n == r) return 1;
    ll res = comb(n%m, r%m, m);
    return comb(n%m, r%m, m) * lucas(n/m, r/m, m) % m;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k >> m;
    fac[0] = 1;
    for (ll i=1; i<=m; i++) {
        fac[i] = fac[i-1]*i%m;
    }
    inv[m-1] = pow_mod(fac[m-1], m-2, m);
    for (ll i=m-2; i>=0; i--) inv[i] = inv[i+1]*(i+1)%m;
    cout << lucas(n, k, m);
    return 0;
}