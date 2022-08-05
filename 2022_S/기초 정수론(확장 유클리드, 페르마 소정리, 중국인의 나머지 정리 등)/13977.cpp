#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)
#define MOD 1000000007

typedef long long ll;
ll m, n, k;
ll fac[4040404], inv[4040404];

ll pow_mod(ll a, ll b) {
    if (a == 0 || b == 0) return 1;
    if (b == 1) return (a%MOD);
    ll tmp = pow_mod(a, b/2);
	if (b%2==0) return tmp*tmp%MOD;
    else return a*((tmp*tmp)%MOD)%MOD;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> m;
    fac[0] = 1;
    for (ll i=1; i<=4000000; i++) fac[i] = fac[i-1]*i%MOD;
    inv[4000000] = pow_mod(fac[4000000], MOD-2); // 페르마의 소정리 -> 역원 계산
    for(ll i=4000000-1; i>=0; i--) inv[i] = inv[i+1]*(i+1)%MOD;
    for (ll i=0; i<m; i++) {
        cin >> n >> k;
        ll res = fac[n] * inv[k] % MOD * inv[n-k] % MOD;
        cout << res << '\n';
    }
    return 0;
}