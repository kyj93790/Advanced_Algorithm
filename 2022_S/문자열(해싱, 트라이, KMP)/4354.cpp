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
string s;
ll n;
int f[1010101];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    while (1) {
        cin >> s;
        if (s.compare(".") == 0) break ;
        n = s.length();
        for (ll i=0; i<=n; i++) f[i] = 0;
        for (ll i=1, j=0; i<n; i++) {
            while (j>0 && s[i]!=s[j]) j=f[j-1];
            if (s[i]==s[j]) {
                f[i] = ++j;
            }
        }
        ll p = n-f[n-1];
        if (n%p) cout << 1 << '\n';
        else cout << n/p << '\n';
    }
    return 0;
}