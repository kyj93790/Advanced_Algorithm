#include <iostream>
using namespace std;

typedef long long ll;
double T[1010101];
double S[1010101];

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    T[0] = 0; T[1] = 1; S[0] = 0; S[1] = 1;
    for (int i=2; i<=n; i++) {
        double sum = 0;
        int cnt = 0;
        for (int j=6; j>0; j--) {
            if (i-j <= 0) {
                cout << "here\n";
                sum += (double)1/6;
            }
            else {
                sum += (S[i-1] - S[i-j-1] + j) / 6 / j;
            }
            cout << i << " : " << sum << '\n';
        }
        T[i] = sum;
        S[i] = S[i-1] + T[i];
    }
    cout << T[n] << '\n';
    return (0);
}