# include <iostream>

using namespace std ;

int f(int T[], int l, int r, int &a, int &b) {
    if (l == r) {
        a = T[l] ;
        b = T[l] ;
        return 0 ;
    }
    int q = (l + r) / 2 ;
    int a1, b1, a2, b2 ;
    int d1 = f(T, l, q, a1, b1) ;
    int d2 = f(T, q + 1, r, a2, b2) ;
    
    a = (a1 < a2) ? a1 : a2 ;
    b = (b1 > b2) ? b1 : b2 ;
    
    int d = (d1 > d2) ? d1 : d2 ;
    if (b2 - a1 > d) d = b2 - a1 ;
    return d ;
}

int main () {
    int n ;
    cin >> n ;
    if (n == 0) return 0 ;
    int T[100000] ;
    for (int i = 0; i < n; i++) cin >> T[i] ;
    
    int a, b ;
    cout << f(T, 0, n - 1, a, b) << endl ;
    return 0 ;
}