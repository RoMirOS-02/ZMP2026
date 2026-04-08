#include <iostream>

using namespace std;

int main() {
    int x, n, a;
    cin >> x >> n;

    int idx = -1;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == x && idx == -1) {
            idx = i;
        }
    }

    if (idx == -1) {
        cout << "nie";
    } else {
        cout << "tak " << idx;
    }
}