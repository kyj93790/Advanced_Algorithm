#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll p[130][130];
int cnt[2];

void countPaper(ll n, ll x, ll y) {
    int i, j;
    int color = p[x][y];
    bool flag = true;
    for (i=x; i<x+n; i++) {
        for (j=y; j<y+n; j++) {
            if (p[i][j] != color) {
                flag = false;
                break ;
            }
        }
    }
    if (flag) cnt[color]++;
    else {
        countPaper(n/2, x, y);
        countPaper(n/2, x+n/2, y);
        countPaper(n/2, x, y+n/2);
        countPaper(n/2, x+n/2, y+n/2);
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) cin >> p[i][j];
    }
    countPaper(n, 0, 0);
    cout << cnt[0] << '\n' << cnt[1] << '\n';
    return 0;
}