#include <iostream>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;

    while (n) {
        n /= 5;
        cnt += n;
    }

    cout << cnt;
}