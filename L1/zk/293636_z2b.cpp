#include <iostream>
using namespace std;

int phi(int n) {
    int result = n;

    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {

            while (n % p == 0)
                n /= p;

            result -= result / p;
        }
    }

    if (n > 1)
        result -= result / n;

    return result;
}

int F(int n) {
    int sum = 0;

    for (int d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            sum += phi(d);

            if (d != n / d)
                sum += phi(n / d);
        }
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    cout << "F(n) = " << F(n) << endl;

    return 0;
}