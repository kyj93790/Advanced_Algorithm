#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
int m, n;
int a, b;
int new_face[2020]; // x라는 정점을 대신할 새로운 정점들
int cap[2020][2020];  // capacity(용량)
int flow[2020][2020]; // flow(유랑)
vector<int> v[2020];
int cache[2020];     // 직전 경로 저장
int ans, source, sink;

void add_edge(int from, int to, int c) {
    v[from].push_back(to);
    v[to].push_back(from);
    cap[from][to] = c;
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
    cin >> m >> n;
    // 돼지 우리에 대한 처리
    for (int i=1; i<=m; i++) {
        cin >> a;
        add_edge(0, i, a);
        new_face[i] = i;    // initialize
    }
    int base = m+1;
    // n명의 손님 처리
    for (int i=1; i<=n; i++) {
        cin >> a;
        vector<int> A(a+1);
        for (int j=1; j<=a; j++) {
            cin >> A[j];
            // 현재 가지고 있는 키의 '대리자' -> base에 inf edge 추가
            add_edge(new_face[A[j]], base, 1e9);
        }
        cin >> b;
        add_edge(base, base+1, b);
        for (int j=1; j<=a; j++) new_face[A[j]] = base;
        // 모든 손님으로 흘러가는 돼지의 수를 더한다
        ans += Edmond_Karp(0, base+1);
        base += 2; // sink는 정점이 증가함에 따라 계속 번호가 증가
    }
    cout << ans << '\n';
    return 0;
}