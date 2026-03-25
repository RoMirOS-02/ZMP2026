# include <iostream>

using namespace std ;

int main () {
    int n, x, y, r;
    cin >> n;

    cin >> x;

    for (int i = 1; i < n; i++) {
        cin >> y;
        while (y != 0) {
            r = x % y;
            x = y;
            y = r;
        }
    }

    cout << x;
}