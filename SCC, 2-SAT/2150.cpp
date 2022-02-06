#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define max(a, b) (a>=b?a:b)
#define min(a, b) (a<=b?a:b)
#define p(a, b) make_pair(a, b)

typedef long long ll;
void swap(ll *a, ll *b) {
    ll temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int dfsn[10101];        // 방문 순서 저장
bool fin[10101];   // SCC 추출 여부 저장
vector<vector<int> > SCC;	// SCC 집합 저장
vector<int> v[10101];	// 간선 정보 저장
stack<int> s;			// 타잔 알고리즘을 위한 stack
int cnt;				// 방문 순서 저장

int dfs(int x) {
	dfsn[x] = ++cnt;
	s.push(x);
	int ret = dfsn[x]; // 현재 노드의 방문 순서 -> ret에는 '나와 내 자손' 중 가장 높은 조상으로 올라갈 수 있는 번호를 저장
	for (int i=0; i<v[x].size(); i++) {
		int nxt = v[x][i];
		// 아직 방문하지 않은 노드면 방문 진행
		if (!dfsn[nxt]) {
			int temp = dfs(nxt);
            ret = min(ret, temp);
        }
		// 방문한 노드 중 아직 SCC 처리가 되지 않은 노드면 back-edge -> 적어도 이 조상까지는 방문 가능
		else if (!fin[nxt]) {
            ret = min(ret, dfsn[nxt]);
        }
	}
	// 나 포함 자식 노드들 중에서 더 이상 조상 노드로 올라갈 수 없음.
	if (ret == dfsn[x]) {
		vector<int> temp;
		// stack에서 내 노드까지 뽑아냄.
		while (!s.empty()) {
			// fin check
			int top = s.top();
			temp.push_back(top);
			fin[top] = true;
			s.pop();
			if (top == x) break;
		}
		sort(temp.begin(), temp.end());
		SCC.push_back(temp);
	}
	return ret;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int V, E, a, b;
    cin >> V >> E;
    for (int i=0; i<E; i++) {
        cin >> a >> b;
		v[a].push_back(b);
    }
	for (int i=1; i<=V; i++) {
		// 방문되지 않은 노드에 대해서 dfs 진행
		// 연결그래프가 아닌 경우 추가적으로 dfs를 실행해야 함
		if (!dfsn[i]) dfs(i);
	}
	sort(SCC.begin(), SCC.end());
    cout << SCC.size() << '\n';
    for (int i=0; i<SCC.size(); i++) {
        for (int j=0; j<SCC[i].size(); j++) {
            cout << SCC[i][j] << ' ';
        }
        cout << -1 << '\n';
    }
    return 0;
}