#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
int n, k, ans, M, m;
int v[1000000];
deque<pair<int, int> > q;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i=0; i<n; i++) cin >> v[i];
    sort(v, v + n);
    ans = 1e8;
    for (int i=0; i<n; i++) { // 연속된 n-k개
        while (!q.empty() && q.front().first < i-(n-k-1)) q.pop_front();
        while (!q.empty() && i < n-1 && q.back().second > v[i+1] - v[i]) q.pop_back();
        if (i < n-1) q.push_back(p(i, v[i+1] - v[i]));
        if (i >= n-k-1) {
            M = v[i] - v[i-(n-k-1)];
            m = q.front().second;
            ans = min(ans, M+m);
        }
    }
    cout << ans << '\n';
    return 0;
}