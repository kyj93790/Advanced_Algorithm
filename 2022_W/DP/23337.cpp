#include <iostream>
using namespace std;

typedef long long ll;
int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    double dp[n];
    dp[1] = 1.0/n-1;
    for (int i=2; i<n; i++) {
        dp[i] = (1-dp[i-1])*(1/n-i);
    }
    cout << fixed;
    cout.precision(13);
    cout << dp[n-1] << '\n';
    return (0);
}