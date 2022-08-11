#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
#include <tuple>
#include <cmath>
#include <set>
#include <numeric>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
// C진수, mod M
template<ll C, ll M> struct Hashing {
    vector<ll> H, B;

    // 전처리
    void build(vector<ll> &s) {
        H.resize(s.size()+1);
        B.resize(s.size()+1);
        B[0] = 1;
        // H[i] : s[0]~s[i]의 해시값
        for (ll i=1; i<=s.size(); i++) H[i] = (H[i-1] * C + s[i-1]) % M;
        // C의 거듭제곱 전처리
        for (ll i=1; i<=s.size(); i++) B[i] = B[i-1] * C % M;
    }

    // s[l..r]의 해시값 계산
    ll get(int l, int r) {
        ll res = (H[r+1] - H[l] * B[r-l+1]) % M;
        if (res < 0) res += M;
        return res;
    }
};

// c와 m 서로소, m이 소수이면 충돌 방지에 좋음
Hashing<524287, 998244353> h1;
vector<ll> v;
ll n, k;

// 이분탐색으로 문자열 사전순 비교
bool cmp(ll a, ll b) {
    ll l=0, r=n-1;
    while (l<r) {
        // 앞의 m개의 문자가 같은지 판단
        ll m=(l+r+1)/2;
        auto t1 = h1.get(a, a+m-1);
        auto t2 = h1.get(b, b+m-1);
        if (t1 == t2) l = m;
        else r = m-1;
    }
    if (l == n-1) return false;
    return v[a+l] < v[b+l];
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll tmp;
    cin >> n >> k;
    for (ll i=0; i<n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    reverse(v.begin(), v.end());
    // cyclic shift -> 2배 문자열로 만들어 처리
    for (ll i=0; i<n; i++) {
        v.push_back(v[i]);
    }
    h1.build(v);
    vector<ll> idx(n-1);
    // begin 자리부터 1, 2, 3 ... 으로 채워넣음 -> index로 활용
    iota(idx.begin(), idx.end(), 1);
    // idx를 실제 string의 사전 순에 따라 정렬
    stable_sort(idx.begin(), idx.end(), cmp);
    // idx에서 k번째 있는 친구 == start index
    // 그 위치부터 n개 출력
    for (ll i=0; i<n; i++) cout << v[idx[k-1]+i] << ' ';
    return 0;
}