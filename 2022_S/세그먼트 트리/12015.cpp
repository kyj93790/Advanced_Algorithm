#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
int tree[3030303]; // max segtree

void update(int n, int l, int r, int idx, int val)
{
    if (idx < l || r < idx) return ;
    tree[n] = max(tree[n], val);
    if (l == r) return ;
    int m = (l+r)/2;
    update(2*n, l, m, idx, val);
    update(2*n+1, m+1, r, idx, val);
}

int query(int n, int l, int r, int s, int e)
{
    if (e < l || r < s) return (0);
    if (s <= l && r <= e) return tree[n];
    int m = (l+r)/2;
    return max(query(2*n, l, m, s, e), query(2*n+1, m+1, r, s, e));
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, a, m, temp;
    cin >> n;
    m = 0;
    int N = 1000000;
    for (int i=0; i<n; i++) {
        cin >> a;
        temp = query(1, 1, N, 1, a-1) + 1;
        m = max(m, temp);
        update(1, 1, N, a, temp);
    }
    cout << m << '\n';
    return 0;
}