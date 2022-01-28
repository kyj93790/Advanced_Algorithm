#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
ll cnt[1010];   // prefix sum을 m으로 나눴을 때의 나머지에 대한 정보
// 내 앞에서 prefix sum 나머지가 동일한 것의 개수만큼 !

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n, m;
    cin >> n >> m;
    ll sum = 0;
    ll count = 0;
    cnt[0] = 1; // 나머지가 0인 친구들은 앞에 동일한 나머지 값이 없어도 기본적으로 1개 가능
    for (ll i=0; i<n; i++) {
        ll temp;
        cin >> temp;
        sum += temp;
        count += cnt[sum % m]++;
    }
    cout << count << '\n';
    return 0;
}