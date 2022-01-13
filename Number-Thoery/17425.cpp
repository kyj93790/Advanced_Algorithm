#include <iostream>
using namespace std;

typedef long long ll;
ll f[1010101];
ll g[1010101];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    // 전처리 - 에라토스테네스의 체
    for (int i=1; i<=1000000; i++) {
        for (int j=i; j<=1000000; j+=i) {
            f[j] += i;
        }
    }
    for (int i=1; i<=1000000; i++) {
        g[i] = g[i-1] + f[i];
    }
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        cout << g[n] << '\n';
    }
    return (0);
}