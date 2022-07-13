#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
int arr[202020];

int gcd2(int x, int y) {
    if (y == 0) return (x);
    else return gcd2(y, x%y);
}

int getGcd(int l, int r) {
    int gcd = arr[l];
    for (int i=l+1; i<=r; i++) gcd = gcd2(gcd, arr[i]);
    return (gcd);
}

int f(int l, int r) {
    if (l==r) return arr[l];
    if (l>r) return 0;
    int m = (l+r-1)/2;
    int a, b;
    a = getGcd(l, m); b = getGcd(m+1, r);
    return max(a + f(m+1, r), b + f(l, m));
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) cin >> arr[i];
    cout << f(1, n) << '\n';
    return 0;
}