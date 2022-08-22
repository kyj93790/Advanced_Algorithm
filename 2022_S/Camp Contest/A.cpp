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

typedef long long ll;
ll t, arr[3];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr, arr+3);
        cout << arr[0] << '\n';
    }
    return 0;
}
