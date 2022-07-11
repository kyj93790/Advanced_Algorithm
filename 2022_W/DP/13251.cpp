#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
vector<int> v(50);

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll m;
    cin >> m;
    ll sum = 0;
    for (int i=0; i<m; i++) {
        cin >> v[i];
        sum += v[i];
    }
    ll k;
    cin >> k;
    double ans = 0;
    for (int i=0; i<m; i++) {
        if (v[i] < k) continue;
        ll s = sum;
        double temp = 1;
        for (int j=v[i]; j>v[i]-k; j--) {
            double p = (double)j/s;
            temp *= p;
            s--;
        }
        ans += temp;
    }
    cout << fixed;
    cout.precision(13);
    cout << ans << '\n';
    return (0);
}