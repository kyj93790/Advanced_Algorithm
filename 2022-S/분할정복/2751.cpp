#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll n;
ll arr[1010101];

void merge(ll l, ll m, ll r) {
	static int temp[1010101];
	ll i=l, j=m+1, k=0;
	while (i<=m && j<=r) {
		if (arr[i] <= arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	while (i<=m) temp[k++] = arr[i++];
	while (j<=r) temp[k++] = arr[j++];
	for (k=0; k<r-l+1; k++) {
		arr[l+k] = temp[k];
	}
}

void mergeSort(ll l, ll r) {
	if (l < r) {
		ll m = (l + r)/2;
		mergeSort(l, m);
		mergeSort(m+1, r);
		merge(l, m, r);
	}
}

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> n;
	for (int i=0; i<n; i++) cin >> arr[i];
	mergeSort(0, n-1);
	for (int i=0; i<n; i++) cout << arr[i] << '\n';
    return 0;
}