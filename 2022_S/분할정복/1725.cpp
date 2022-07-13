#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
int n, result;
int h[101010];

void find_mid(int l, int m, int r) {
    int i=m, j=m+1;
    int height = min(h[i], h[j]);
    while (i>=l && j<=r) {
        result = max(result, height * (j-i+1));
        if (i-1 < 0) height = min(height, h[++j]);
        else if (j+1 > r) height = min(height, h[--i]);
        else if (h[i-1] >= h[j+1]) height = min(height, h[--i]);
        else height = min(height, h[++j]);
    }
}

void f(int l, int r) {
    if (l < r) {
        int m = (l + r)/2;
        f(l, m);
        f(m+1, r);
        find_mid(l, m, r);
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> h[i];
        result = max(h[i], result);
    }
    f(0, n-1);
    cout << result << '\n';
    return 0;
}