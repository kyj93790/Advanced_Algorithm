#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
vector<ll> A(101010);

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (int i=0; i<n; i++) cin >> A[i];
    sort(A.begin(), A.begin()+n);
    ll ans = 0;
    ll pos = 0;
    ll cnt = 0;
    for (int i=n-1; i>=0; i--) {
        if (A[i] >= 0) {
             pos += A[i];
            cnt++;
        }
        else {
            if (pos > cnt*(-A[i])) {
                pos += A[i];
                cnt++;
            } else ans += A[i];
        }
    }
    ans += pos*cnt;
    cout << ans << '\n';
    return 0;
}