#include <iostream>
using namespace std;

typedef long long ll;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    ll cnt = 0;
    ll temp;
    for (ll i=1; i<n;) {
        temp = (n-1)/i;
        cnt += temp * ((n-1)/temp - i + 1);
        i = (n-1)/temp + 1;
    }
    cnt += n;
    cout << cnt << '\n';
    return (0);
}