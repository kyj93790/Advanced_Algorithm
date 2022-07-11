#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)
#define mod 200003

typedef long long ll;
ll n, m, x, y, t, a, b, c;
string s;

bool f(int m) {
    ll hash = 0, pw = 1;
    ll nxt;
    // hash : 문자열을 26진수로 만들기
    // pw : 문자열보다 자릿수 하나 큰 26의 거듭제곱수
    for (int i=0; i<m; i++) {
        hash = (hash*26 + s[i])%mod;
        pw = (pw*26)%mod;
    }

    vector<ll> v[mod];
    v[hash].push_back(0);
    for (int i=1; i+m-1<n; i++) {
        // ex) 1230 - 1000 + 4(다음 살펴볼 수) : 123 -> 234
        hash = (hash*26 % mod - pw*s[i-1] % mod + s[i-1+m] + mod) % mod;
        // 해싱 충돌 발생 가능 -> 순회하면서 체크
        for (ll j=0; j<v[hash].size(); j++) {
            nxt = v[hash][j];
            if (!strncmp(&s[nxt], &s[i], m)) return true;
        }
        v[hash].push_back(i);
    }
    return false;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
    cin >> s;
    // 이분 탐색
    n = s.size();
    ll l=0, r=n, mid, ans=-1;
    while (l <= r) {
        mid = (l+r)/2;
        if (f(mid)) {
            ans = max(ans, mid);
            l = mid + 1;
        } else r = mid-1;
    }
    cout << ans << '\n';
    return 0;
}