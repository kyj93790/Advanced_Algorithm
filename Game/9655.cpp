#include <iostream>
using namespace std;

typedef long long ll;

int main(void) {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    ll n;
    cin >> n;
    if (n % 2 == 0) cout << "CY\n";
    else cout << "SK\n";
    return 0;
}