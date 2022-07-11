#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
int n, p;
int cap[1000][1000];  // capacity(용량)
int flow[1000][1000]; // flow(유랑)
vector<int> v[1000];
int cache[1000];     // 직전 경로 저장
int ans, source, sink;

// in과 out을 분리
int in(int x) {
    return x;
}

int out(int x){
    return x+n;
}

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
    cin >> n >> p;
    for (int i=0; i<p; i++) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b, 1);
    }
    cout << Edmond_Karp(1, 2) << '\n';
    return 0;
}