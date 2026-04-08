#include <iostream>

using namespace std;

int main() {
    int x, n;
    cin >> x >> n;

    int a[100000];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = n - 1, mid;
    int idx = -1;

    while (l <= r) {
        mid = (l + r) / 2;

        if (a[mid] == x) {
            idx = mid;
            break;
        }
        if (a[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if (idx == -1) {
        cout << "nie";
    } else {
        cout << "tak " << idx;
    }
}