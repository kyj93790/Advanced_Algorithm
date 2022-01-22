#include <iostream>
#include <cstdlib>
#define min(a, b) (a<=b?a:b)
#define max(a, b) (a>=b?a:b)
using namespace std;

typedef long long ll;
int A[1010], B[1010];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i=0; i<n; i++) cin >> A[i];
    for (int i=0; i<n; i++) cin >> B[i];
    int max = 0;
    for (int i=0; i<n; i++) {
        int a = 1e9;
        for (int j=0; j<n; j++) {
            // 현재 a의 원소에 대해 가장 작은 차이값 계산
            a = min(a, abs(A[i] - B[j]));
        }
        if (max < a) max = a;
    }
    cout << max << '\n';
    return 0;
}