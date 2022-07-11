#include <iostream>
using namespace std;

typedef long long ll;
ll A[1010];
double f[1010];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    f[0] = n;
    for (int i=1; i<=k; i++) cin >> A[i];
    for (int i=1; i<=k; i++) {
        double p = (double)A[i]/n;
        f[i] = f[i-1]*(1-p) + (n-f[i-1])*p;
    }
    cout << fixed;
    cout.precision(13);
    cout << f[k] << '\n';
    return (0);
}