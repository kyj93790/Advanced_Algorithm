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

int n, m, a, b;
int C[2020];
vector<int> edge[2020], rev[2020], v;

void init() {
    memset(C, 0, sizeof(C));
    for (int i=0; i<2002; i++) {
        while (!edge[i].empty()) edge[i].pop_back();
        while (!rev[i].empty()) rev[i].pop_back();
    }
    while (!v.empty()) v.pop_back();
}

int notx(int x) {
    if (x <= n) return (x + n);
    return (x - n);
}

void dfs(int curr) {
    C[curr] = -1;
    for (auto i : edge[curr]) if (!C[i]) dfs(i);
    v.push_back(curr);
}

void dfs2(int curr, int g) {
    C[curr] = g;
    for (auto i : rev[curr]) if (C[i] == -1) dfs2(i, g);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    while (cin >> n >> m) {
        init();
        for (int i=0; i<m; i++) {
            cin >> a >> b;
            if (a < 0) a = -a + n;
            if (b < 0) b = -b + n;
            edge[notx(a)].push_back(b);
            rev[b].push_back(notx(a));
            edge[notx(b)].push_back(a);
            rev[a].push_back(notx(b));
        }
        edge[notx(1)].push_back(1);
        rev[1].push_back(notx(1));
        for (int i=1; i<=2*n; i++) if (!C[i]) dfs(i);
        reverse(v.begin(), v.end());
        int cnt = 0;
        for (auto i : v) {
            if (C[i] == -1) {
                dfs2(i, ++cnt);
            }
        }
        int ans = 0;
        for (int i=1; i<=n; i++) {
            if (C[i] == C[i+n]) ans = 1;
        }
        if (!ans && C[1] > C[notx(1)]) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}
