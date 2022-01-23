#include <iostream>
using namespace std;

typedef long long ll;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n&1) cout << "koosaga\n";
        else cout << "cubelover\n";
    }
    return 0;
}