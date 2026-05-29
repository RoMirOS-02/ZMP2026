# include <iostream>

using namespace std ;

long long c = 0 ;

void m(int T[], int W[], int l, int q, int r) {
    int i = l, j = q + 1, k = l ;
    while (i <= q && j <= r) {
        if (T[i] <= T[j]) {
            W[k++] = T[i++] ;
        } else {
            W[k++] = T[j++] ;
            c += (q - i + 1) ;
        }
    }
    while (i <= q) W[k++] = T[i++] ;
    while (j <= r) W[k++] = T[j++] ;
    for (i = l; i <= r; i++) T[i] = W[i] ;
}

void f(int T[], int W[], int l, int r) {
    if (l < r) {
        int q = (l + r) / 2 ;
        f(T, W, l, q) ;
        f(T, W, q + 1, r) ;
        m(T, W, l, q, r) ;
    }
}

int main () {
    int n ;
    cin >> n ;
    int T[100000], W[100000] ;
    for (int i = 0; i < n; i++) {
        cin >> T[i] ;
    }
    f(T, W, 0, n - 1) ;
    cout << c << endl ;
}