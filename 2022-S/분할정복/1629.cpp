#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll a, b, c;

ll f(int i){
    if (i == 0) return 1;
    else if (i == 1) return (a%c);
    return (f(i/2)*f(i/2)%c * f(i%2))%c;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> a >> b >> c;
    cout << f(b) << '\n';
    return 0;
}