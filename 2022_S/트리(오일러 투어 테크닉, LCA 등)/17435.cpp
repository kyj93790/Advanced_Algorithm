#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <tuple>
using namespace std;
#define p(a, b) make_pair(a, b)
#define n_ 202020

typedef long long ll;
ll m, q;
ll f[n_][20];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> m;
    for (ll i=1; i<=m; i++) cin >> f[i][0];
    for (ll j=1; j<20; j++) {
        for (ll i=1; i<=m; i++) f[i][j] = f[f[i][j-1]][j-1];
    }
    cin >> q;
    ll n, x;
    for (ll i=0; i<q; i++) {
        cin >> n >> x;
        ll cnt=0, curr=0;
        while (n) {
            if (n%2) {
                if (!curr) curr = f[x][cnt];
                else curr = f[curr][cnt];
            }
            n /= 2;
            cnt++; 
        }
        cout << curr << '\n';
    }
    return 0;
}
