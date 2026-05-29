# include <iostream>

using namespace std ;

void m(int T[], int W[], int l, int q, int r) {
    int i = l, j = q + 1, k = l ;
    while (i <= q && j <= r) {
        if (T[i] <= T[j]) W[k++] = T[i++] ;
        else W[k++] = T[j++] ;
    }
    while (i <= q) W[k++] = T[i++] ;
    while (j <= r) W[k++] = T[j++] ;
    for (i = l; i <= r; i++) T[i] = W[i] ;
}

int main () {
    int n ;
    cin >> n ;
    int T[100000], W[100000] ;
    for (int i = 0; i < n; i++) cin >> T[i] ;
    
    for (int s = 1; s < n; s *= 2) {
        for (int l = 0; l < n - 1; l += 2 * s) {
            int q = l + s - 1 ;
            int r = l + 2 * s - 1 ;
            if (q > n - 1) q = n - 1 ;
            if (r > n - 1) r = n - 1 ;
            m(T, W, l, q, r) ;
        }
    }
    
    for (int i = 0; i < n; i++) cout << T[i] << " " ;
    cout << endl ;
    return 0 ;
}