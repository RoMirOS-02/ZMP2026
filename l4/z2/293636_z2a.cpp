# include <iostream>

using namespace std ;

void f(int i, int n, int T[], int v[], int s) {
    if (i == n) {
        if (s == 0) {
            cout << "empty" << endl;
        } else {
            for (int j = 0; j < s; j++) {
                cout << v[j] << " ";
            }
            cout << endl;
        }
        return ;
    }
    f(i + 1, n, T, v, s);
    v[s] = T[i];
    f(i + 1, n, T, v, s + 1);
}

int main () {
    int n;
    cin >> n;
    int T[100], v[100];
    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }
    f(0, n, T, v, 0);
}