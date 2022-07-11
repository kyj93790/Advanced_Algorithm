#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)
#define mod 1000000007
typedef long long ll;

ll n, m;
ll temp, a, l;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    ll ans = 0;
    ll val, idx, dif;
    for (ll i=1; i<=n; ){
        val = n/i;
        idx = n/(n/i);  // 현재 i부터 idx까지
        dif = idx - i + 1;
        //  cout << "curr i : " << i << '\n';
        // cout << "idx : " << idx << '\n';
        if (dif > m) {
            temp = (m-1)*m%mod/2%mod;
            ans += ((dif/m)%mod * temp%mod * val%mod)%mod;
            ans %= mod;
            i += (dif/m) * m;
            // cout << "next i : " << i << '\n';
            // cout << "ans : " << ans << '\n';
            // cout << '\n';
        }
        if (i > idx) continue;
        else if (i==idx) {   // 1개 짜리
            ans += (val%mod * (i%m)%mod)%mod;
            ans %= mod;
            i++;
        } else {
            temp = 0;
            if (i%m > idx%m) {
                a = i%m; l=m-1-a+1;
                temp += (2*a%mod + (l-1)%mod)*l/2%mod*val%mod;
                temp %= mod;
                a = 1; l=idx%m-a+1;
                temp += (2*a%mod + (l-1)%mod)*l/2%mod*val%mod;
                temp %= mod;
                ans += temp;
                ans %= mod;
            } else if (i%m < idx%m) {
                a = i%m; l=idx%m-a+1;
                temp += (2*a%mod + (l-1)%mod)*l/2%mod*val%mod;
                temp %= mod;
                ans += temp;
                ans %= mod;
            }
            i = idx+1;
        }
        // cout << "next i : " << i << '\n';
        // cout << "ans : " << ans << '\n';
        // cout << '\n';
    }
    cout << ans << '\n';
    return 0;
}