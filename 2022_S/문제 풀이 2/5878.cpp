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

typedef long long ll;
string str;
ll a[101010], S[101010], pre[101010], suf[101010];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> str;
    ll n = str.length(), p;
    for (ll i=0; i<n; i++) {
        if (str[i] == '(') a[i+1] = 1;
        else a[i+1] = -1;
        S[i+1] = S[i] + a[i+1];
        pre[i+1] = suf[i+1] = 1e6;
    }
    pre[0] = suf[n+1] = 1e6;
    for (ll i=0; i<n; i++) {
        pre[i+1] = min(pre[i], S[i+1]);
        suf[n-i] = min(suf[n-i+1], S[n-i]);
    }
    ll ans = 0;
    for (ll i=1; i<=n; i++) {
        if (S[n] == 2 && a[i] == 1) { // ( -> )
            if (pre[i-1] >= 0 && suf[i] -2 >= 0) ans++;
        } else if (S[n] == -2 && a[i] == -1) { // ) -> (
            if (pre[i-1] >= 0 && suf[i] +2 >= 0) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
