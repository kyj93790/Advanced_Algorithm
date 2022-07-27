#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
deque<pair<int, int> > a;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int l, n;
    cin >> n >> l;
    int curr, min;
    for (int i=1; i<=n; i++) {
        cin >> curr;
        if (!a.empty() && a.front().first < i-l+1) a.pop_front();
        while(!a.empty()) {
            if (a.back().second >= curr) a.pop_back();
            else break;
        }
        a.push_back(p(i, curr));
        cout << a.front().second << ' ';
    }
    cout << '\n';
    return 0;
}