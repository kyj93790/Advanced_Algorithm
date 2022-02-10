#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
int n, m;
int cap[410][410];  // capacity(용량)
int flow[410][410]; // flow(유랑)
vector<int> v[410];
int cache[410];     // 직전 경로 저장
int ans, source, sink;

void add_edge(int from, int to, int c) {
    v[from].push_back(to);
    v[to].push_back(from);
    cap[from][to] = c;
    // 유랑은 현재 0이므로 추가 처리하지 않음.
}

int Edmond_Karp(int source, int sink) {
    int max_flow = 0;
    // while문은 augmenting path가 없을 때까지 실행
    while (1) {
        // bfs를 통해 augmenting path를 찾는다.
        queue<int> q;
        q.push(source);
        memset(cache, -1, sizeof(cache));
        cache[source] = 0;
        while(q.size()) {
            int cur = q.front();
            q.pop();
            for (int i=0; i<v[cur].size(); i++) {
                int nxt = v[cur][i];
                // 미방문이면서 아직 더 흐를 수 있다면 추가
                if (cache[nxt] == -1 && cap[cur][nxt] - flow[cur][nxt] > 0) {
                    cache[nxt] = cur;
                    q.push(nxt);
                    if (nxt == sink) break;
                }
            }
        }
        // 경로가 더 이상 없으면 빠져나옴.
        if (cache[sink] == -1) break;
        // 현재 residual graph 용량의 최소값을 min_cap에 저장
        int min_cap = 1e9;
        for (int i=sink; i!=source; i=cache[i]) {
            int bef = cache[i];
            min_cap = min(min_cap, cap[bef][i] - flow[bef][i]);
        }
        max_flow += min_cap;
        // residual graph 변경
        for (int i=sink; i!=source; i=cache[i]) {
            int bef = cache[i];
            flow[bef][i] += min_cap;
            flow[i][bef] -= min_cap;
        }
    }
    return max_flow;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int c, temp;
        cin >> c;
        while (c--) {
            cin >> temp;
            add_edge(i, temp + n, 1);
        }
    }
    // source랑 소들 연결
    for (int i=1; i<=n; i++) add_edge(0, i, 1);
    // 축사들이랑 sink 연결
    for (int i=1; i<=m; i++) add_edge(n+i, n+m+1, 1);
    cout << Edmond_Karp(0, n + m + 1) << '\n';
    return 0;
}