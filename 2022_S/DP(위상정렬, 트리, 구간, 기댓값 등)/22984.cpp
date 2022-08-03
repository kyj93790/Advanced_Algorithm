#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n;
double p[101010];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cout << fixed;
    cout.precision(7);
    cin >> n;
    for (ll i=0; i<n; i++) cin >> p[i];
    double sum = p[0];
    for (ll i=1; i<n; i++) {
        sum += p[i-1]*(1-p[i]) + (1-p[i-1])*p[i] + p[i];
    }
    cout << sum << '\n';
    return 0;
}