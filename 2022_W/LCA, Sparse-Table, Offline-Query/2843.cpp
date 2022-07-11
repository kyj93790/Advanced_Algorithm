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

stack<pair<int, int> > query;
int arr[303030]; // 초기 입력 저장
int par[303030]; // 집합 정보 저장
int cycle[303030]; // 집합의 cycle 정보 저장
bool rmedge[303030]; // 제거될 엣지 정보 저장

// union find 알고리즘
int find(int x) {
    if (!par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    par[x] = y;
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n, m, a, b;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    cin >> m;
    // query 먼저 저장 -> 추후 마지막 쿼리부터 처리할 예정
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        query.push(p(a, b));
        if (a == 2) rmedge[b] = true;
    }
    // 제거될 간선 제외; query가 모두 끝난 후의 graph 구축
    for (int i=1; i<=n; i++) {
        if (!arr[i] || rmedge[i]) continue; // 간선이 존재하지 않거나 제거된다면 병합하지 않음
        if (find(i) == find(arr[i])) { // 이미 다른 루트를 통해 이어져있다면 cycle
            cycle[find(i)] = 1; // 이 집합은 cycle
        }
        else merge(i, arr[i]);
    }
    stack<int> ans; // offline query 처리
    while (!query.empty()) {
        a = query.top().first; b = query.top().second;
        query.pop();
        if (a == 1) { // 집합 정보 확인 쿼리
            if (cycle[find(b)]) {   // cycle 집합인지 check
                ans.push(-1);
            } else {
                ans.push(find(b));
            }
        } else { // 간선 제거 쿼리 -> 여기서는 복구하는 과정이므로 merge 진행
            if (find(b) == find(arr[b])) {
                cycle[find(b)] = 1;
            } else merge(b, arr[b]);
        }
    }
    while (!ans.empty()) {
        if (ans.top() < 0) cout << "CIKLUS\n";
        else cout << ans.top() << '\n';
        ans.pop();
    }
    return 0;
}