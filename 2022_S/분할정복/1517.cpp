#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
int a[505050];
ll cnt;

void merge(int l, int m, int r) {
    static int temp[505050];
    int i=l, j=m+1, k=0;
    while (i<=m && j<=r) {
        if (a[i] <= a[j]) {
            cnt += (j-(m+1));
            temp[k++] = a[i++];
        }
        else temp[k++] = a[j++];
    }
    while (i<=m) {
        temp[k++] = a[i++];
        cnt += (j-(m+1));
    }
    while (j<=r) temp[k++] = a[j++];
    for (k=0; k<r-l+1; k++) a[l+k] = temp[k];
}

void mergeSort(int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l, m, r);
    }
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    mergeSort(0, n-1);
    cout << cnt << '\n';
    return 0;
}