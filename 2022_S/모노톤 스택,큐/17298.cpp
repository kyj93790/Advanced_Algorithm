#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
stack<pair<int, int> > s;
int a[1000000];
int ans[1000000];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) {

        while (!s.empty() && s.top().first < a[i]) {
            ans[s.top().second] = a[i];
            s.pop();
        }
        s.push(p(a[i], i));
    }
    for (int i=0; i<n; i++) {
        if (!ans[i]) cout << -1 << ' ';
        else cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}