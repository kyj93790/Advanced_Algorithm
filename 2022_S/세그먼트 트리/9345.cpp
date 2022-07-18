#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)
#define MAX 1e5-1
#define MIN 0

typedef long long ll;
int t;
pair<int, int> tree[303030];

void init(int n, int l, int r)
{
    if (l == r) {
        tree[n].first = l;
        tree[n].second = l;
        return ;
    }
    int m = (l+r) / 2;
    init(2*n, l, m);
    init(2*n+1, m+1, r);
    tree[n].first = min(tree[2*n].first, tree[2*n+1].first);
    tree[n].second = max(tree[2*n].second, tree[2*n+1].second);
}

pair<int, int> query(int n, int l, int r, int s, int e)
{
    if (e < l || r < s) return p(MAX, MIN);
    if (s <= l && r <= e) return tree[n];
    pair<int, int> left, right;
    int m = (l+r) / 2;
    left = query(2*n, l, m, s, e);
    right = query(2*n+1, m+1, r, s, e);
    return p(min(left.first, right.first), max(left.second, right.second));
}

void update(int n, int l, int r, int idx, int val)
{
    if (idx < l || r < idx) return ;
    if (l == r) {
        tree[n].first = val;
        tree[n].second = val;
        return ;
    }
    int m = (l+r) / 2;
    update(2*n, l, m, idx, val);
    update(2*n+1, m+1, r, idx, val);
    tree[n].first = min(tree[2*n].first, tree[2*n+1].first);
    tree[n].second = max(tree[2*n].second, tree[2*n+1].second);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        int n, k, q, a, b, i;
        pair<int, int> ans;
        cin >> n >> k;
        init(1, 0, n-1);
        for (i=0; i<k; i++) {
            cin >> q >> a >> b;
            if (q) {
                ans = query(1, 0, n-1, a, b);
                if (ans.first == a && ans.second == b) cout << "YES\n";
                else cout << "NO\n";
            } else {
                int in_b = query(1, 0, n-1, b, b).first;
                int in_a = query(1, 0, n-1, a, a).first;
                update(1, 0, n-1, a, in_b);
                update(1, 0, n-1, b, in_a);
            }
        }
    }
    return 0;
}