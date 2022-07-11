#include <iostream>
using namespace std;

typedef long long ll;
double dp[1010101];

double f(ll x) {
    if (dp[x] >= 0.00) return dp[x];
    else {
        double sum = 0.00;
        for (ll i=1; i<=6; i++) {
            sum += (1.00/6.00)*(1 + f(x+i));
        }
        dp[x] = sum;
        return dp[x];
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (ll i=0; i<n; i++) dp[i] = -1.00;
    cout << fixed;
    cout.precision(16);
    cout << f(0) << '\n';
    return (0);
}