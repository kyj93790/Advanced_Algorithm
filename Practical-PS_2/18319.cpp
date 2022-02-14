#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> B(n);
    for (ll i=0; i<n; i++) {
        cin >> B[i];
    }
    ll ans = 0;
    for (ll i=1; i<=1000; i++) {
        // 동생이 가져가는 바구니들 중 최소가 i개라면 최대도 i인 것이 최적의 방법
        
        // 현재 i(동생 바구니의 최소)만큼 담을 수 있는 바구니의 개수를 세고,
        // 해당 나무에서 남은 berry는 pq에 넣어 필요한 경우 추후 큰 수부터 언니에게 할당해 줌
        ll sum = 0;
        priority_queue<int> pq;
        for (ll j=0; j<n; j++) {
            sum += (B[j]/i);
            pq.push(B[j]%i);
        }
        if (sum < k/2) break;   // 더 이상 i를 최소로 하는 바구니 k/2개를 만들 수 없음
        ll curr = sum - k/2;    // 언니가 가지는 i 바구니의 개수
        if (curr >= k/2) {
            ans = max(ans, i*k/2);
        } else {
            ll temp = i*curr;
            while (curr < k/2) {
                temp += pq.top();
                pq.pop();
                curr++;
            }
            ans = max(ans, temp);
        }
    }
    cout << ans << '\n';
    return 0;
}