#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define p(a, b) make_pair(a, b)

typedef long long ll;
ll a, b, q, k;
ll dp[1080][100];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> q;
    while (q--) {
        ll f=0, r=1;
        cin >> a >> b >> k;
        ll len = b-a;
        ll s = k*(k+1)/2;
        ll reset = len/s;
        if (reset&1) {  // reset이 홀수
            if (k&1) {  // k가 홀수
                f=1; r=0;
            } 
        }
        len -= reset*s;
        // 나머지 영역 처리 - bit dp..?
        for (int i=0; i<=len; i++) {
            dp[s][i] = 1;
        }
        if ((b-a)%(k+1) == 0) {
            cout << "raararaara\n";
        } else cout << "swoon\n";
    }
    return 0;
}