#include <iostream>
using namespace std;

typedef long long ll;

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        if (n % 3 == 2 || n % 9 == 0) cout << "TAK\n";
        else cout << "NIE\n";
    }
    return (0);
}