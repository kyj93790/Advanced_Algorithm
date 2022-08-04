#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll m, s, x, y, a, b, c;
ll coef[33];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> m >> s >> x >> y;
    ll tmp = m-2, w=(s-x+m)%m, i;
    i = 0;
    while (tmp) {
        if (tmp%2==1) coef[i] = 1;
        tmp/=2;
        i++;
    }
    a = 1;
    for (ll j=0; j<i; j++) {
        if (coef[j]) a = (a*w)%m;
        w = (w*w) % m;
    }
    a = (a*(x-y+m))%m;
    c = ((x-a*s)%m + m)%m;
    cout << a << ' ' << c;
    return 0;
}