#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
int n, k, x, y, w, t, curr;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        vector<int> edge_out[1001];
        vector<int> edge_in[1001];
        queue<int> q;   // 위상 정렬을 위한 queue
        vector<int> v;  // 위상 정렬 result
        int D[1001];    // 건물 짓는 시간
        int in[1001];   // 정점으로 들어오는 간선의 수
        int dp[1001];
        cin >> n >> k;
        for (int i=1; i<=n; i++) cin >> D[i];
        for (int i=1; i<=k; i++) {
            cin >> x >> y;
            edge_out[x].push_back(y);
            edge_in[y].push_back(x);
            in[y]++;
        }
        cin >> w;
        for (int i=1; i<=n; i++) { // 진입 차수가 0인 정점 추가
            if (in[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            curr = q.front(); q.pop();
            v.push_back(curr);
            for (int i=0; i<edge_out[curr].size(); i++) {
                if (--in[edge_out[curr][i]] == 0) q.push(edge_out[curr][i]);
            }
        }
        dp[v[0]] = D[v[0]];
        for (int i=0; i<v.size(); i++) {
            int mx = 0;
            for (int j=0; j<edge_in[v[i]].size(); j++) mx = max(mx, dp[edge_in[v[i]][j]]);
            dp[v[i]] = mx + D[v[i]];
        }
        cout << dp[w] << '\n';
    }
    return 0;
}