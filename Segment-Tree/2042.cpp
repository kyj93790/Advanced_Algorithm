#include <iostream>
using namespace std;

typedef long long ll;
ll tree[3030303];
ll arr[1010101];
ll n, m, k;

void init(int N, int s, int e) {
    if (s == e) tree[N] = arr[s];
    else {
        int mid = (s + e)/2;
        init(2*N, s, mid);
        init(2*N+1, mid+1, e);
        tree[N] = tree[2*N] + tree[2*N+1];
    }
}

// b번째 수를 c로 바꿈
void update(int N, int s, int e, int idx, ll val) {
    if (s > idx || e < idx) return;
    if (s == e) {
        if (s == idx) tree[N] = val;
        return ;
    }
    int mid = (s+e)/2;
    update(2*N, s, mid, idx, val);
    update(2*N+1, mid+1, e, idx, val);
    tree[N] = tree[2*N] + tree[2*N+1];
}

// b번째 수부터 c번째 수까지의 합
ll query(int N, int s, int e, int l, int r) {
    if (s > r || e < l) return 0;
    if (l <= s && e <= r) return tree[N];
    int mid = (s + e)/2;
    return query(2*N, s, mid, l, r) + query(2*N+1, mid+1, e, l, r);
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0); 
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
    init(1, 0, n-1);
    for (int i=0; i<m+k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {   // update
            update(1, 0, n-1, b-1, c);
        }
        else {  // query
            cout << query(1, 0, n-1, b-1, c-1) << '\n';
        }
    }
    return 0;
}