#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll dp[1010101];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n, m, k;
    cin >> n >> m >> k;
    ll total = 1;
    ll mod = 1e9 + 7;
    // 전체 만들 수 있는 문자열의 개수 : m^n개
    for (int i=1; i<=n; i++) {
        total *= m;
        total %= mod;
    }
    // 총 문자열 개수에서 substring이 최대 1 ~ k-1인 문자열을 제거
    ll sum = 0;
    for (int i=1; i<=n; i++) {
        if (i==1) sum += m % mod;
        else sum += (dp[i-1]*(m-1))%mod;        // 바로 직전 색과 다른 색을 칠하는 케이스 더해줌. m-1만큼만 가능 !!
        sum %= mod;
        if (i >= k) { // 이번에 하나를 추가함으로써 k개 이상 연속인 숫자열이 생길 수 있음 -> 이 부분 제거
            if (i-k == 0) sum -= m % mod;
            else sum -= (dp[i-k]*(m-1))%mod;    // 바로 마지막 k개의 연속 숫자열 있는 case를 제거
            sum = (sum+mod)%mod;    // sum이 음수가 될 수 있는 case에서 modulo연산이 원치 않는 방향으로 나아가는 것을 방지
        }
        dp[i] = sum;
    }
    cout << (total-dp[n]+mod)%mod << '\n';
    return 0;
}