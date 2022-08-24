#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <tuple>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
int n, k;
set<int> res;
vector<int> ans;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> k;
    ans.push_back(k);
    int c = 0, tmp;
    while (1) {
        tmp = ans.back() * n + c;
        if (ans.back() != 0 && tmp == k) break ;
        if (res.find(tmp) != res.end()) {
            cout << 0 << '\n';
            return (0);
        }
        ans.push_back(tmp%10);
        c = tmp/10;
        res.insert(tmp);
    }
    for (ll i=ans.size()-1; i>=0; i--) cout << ans[i];
    return 0;
}
