# include <iostream>

using namespace std ;

int main () {
    int n ;
    cin >> n ;
    int T[100000] ;
    for (int i = 0; i < n; i++) cin >> T[i] ;
    
    int m = 0 ;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (T[j] - T[i] > m) m = T[j] - T[i] ;
        }
    }
    cout << m << endl ;
    return 0 ;
}