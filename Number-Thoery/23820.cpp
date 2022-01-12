#include <iostream>
using namespace std;

typedef long long ll;
ll exist[2020202];
ll check[2020202];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (ll i=0; i<n; i++) {
        ll temp;
        cin >> temp;
        exist[temp]++;
    }
    for (ll i=0; i<2020202; i++) {
        if (!exist[i]) continue;
        for (ll j=i; j<2020202; j++) {
            if (!exist[j]) continue;
            if (i*j > 2020202) break;
                check[i*j] = 1;
        }
    }
    for (ll i=0; i<2020202; i++) {
        if (!check[i]) {
            cout << i << '\n';
            break ;
        }
    }
    return 0;
}