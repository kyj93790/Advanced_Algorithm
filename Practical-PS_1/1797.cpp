#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)
#define all(a) a.begin(), a.end()
#define inf 3*10e12
typedef long long ll;

ll s[1010101];
ll minx[2020202];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].second >> v[i].first;
        if (v[i].second == 0) v[i].second = -1;
    }
    sort(all(v));
    for (int i=1; i<=n; i++) {
        s[i] = s[i-1] + v[i-1].second;
    }
    for (int i=0; i<=2000000; i++) minx[i] = n+1;
    ll ans = 0;
    minx[1000000] = -1;
    for (int i=1; i<=n; i++) {
        // 현재 고려하고 있는 벡터에 대해서 저장.
        if (minx[s[i] + 1000000] > i-1) minx[s[i] + 1000000] = i-1;
        else ans = max(ans, v[i-1].first - v[minx[s[i] + 1000000]+1].first);
    }
    cout << ans << '\n';
    return 0;
}