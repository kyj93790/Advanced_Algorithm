#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)
#define p(a, b) make_pair(a, b)

typedef long long ll;
void swap(ll *a, ll *b) {
    ll temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll f[10101][15] = {0, };
        ll d[10101] = {0, };
        ll a, b;
        for (ll i=0; i<n; i++){
            cin >> a >> b;
            f[b][0] = a; // a가 b의 1(2^0)번째 부모
        }
        // 전처리
        ll root;
        for (ll y=1; y<=14; y++) {
            for (ll x=1; x<=n; x++) {
                if (!f[x][0]) { // 부모가 없는 root node
                    root = x;
                    break;
                } 
                f[x][y] = f[f[x][y-1]][y-1];
            }
        }
        // query
        cin >> a >> b;
        
    }
    return 0;
}