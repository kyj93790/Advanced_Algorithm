#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    cout << n/2 + m/2 << '\n';
    ll i, j;
    // n, m이 각각 홀수면 2, 짝수면 1
    for (i=(n&1)+1; i<=n; i+=2) {
        cout << i << ' ' << 1 << ' ' << i << ' ' << m << '\n';
    }
    for (j=(m&1)+1; j<=m; j+=2) {
        cout << 1 << ' ' << j << ' ' << n << ' ' << j << '\n';
    }
    return 0;
}