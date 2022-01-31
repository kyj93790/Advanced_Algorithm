#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)

typedef long long ll;
ll s[101010];
ll m[4];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        ll a;
        cin >> a;
        s[i] = s[i-1] + a;
    }
    if (s[n] % 4 != 0) {
        cout << 0 << '\n';
        return 0;
    }
    ll x = s[n]/4;
    for (int i=1; i<n; i++) {
        // 중간에 음수 값으로 인한 0이 되는 부분에서 문제가 발생?
        // x는 0이 되는데 s[i] != x일수 있는가?
        // x가 0이라면 s[n]이 0.
        // 중간에 0이 아닐 수 있지.
        // -1 1 3 4 -3 -4 -> 결국 총합은 0이지만 중간에 합이 0이 아닌 구간이 나옴
        // x는 0. -> 런타임 에러 발생 !!!!!!!!!!!!!!
        if (x == 0) {
            if (s[i] == 0) {
                m[3] += m[2];
                m[2] += m[1];
                m[1]++;
            }
        }
        else if (s[i]%x == 0) {
            if (s[i] == x*3) m[3] += m[2];
            if (s[i] == x*2) m[2] += m[1];
            if (s[i] == x) m[1]++;
        }
    }
    cout << m[3] << '\n';
    return 0;
}