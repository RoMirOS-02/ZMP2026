#include <iostream>

using namespace std;

int main() {
    int s[8], m[8];

    for (int i = 0; i < 8; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < 8; i++) {
        cin >> m[i];
    }

    for (int i = 0; i < 8; i++) {
        cout << (s[i] ^ m[i]) << " ";
    }
}