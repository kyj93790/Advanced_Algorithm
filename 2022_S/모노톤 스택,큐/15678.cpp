#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n, d, ans;
ll arr[101010];
pair<ll, ll> tmp;
deque<pair<ll, ll> > q; // idx, max num

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> d;
    for (ll i=0; i<n; i++) cin >> arr[i];
    ans = -1e10;
    for (ll i=0; i<n; i++) {
        while (!q.empty() && q[0].first < i - d) q.pop_front();
        tmp.first = i;
        if (!q.empty()) tmp.second = max(q[0].second + arr[i], arr[i]);
        else tmp.second = arr[i];
        ans = max(ans, tmp.second);
        while (!q.empty() && q.back().second <= tmp.second) q.pop_back();
        q.push_back(tmp);
    }
    cout << ans << '\n';
    return 0;
}