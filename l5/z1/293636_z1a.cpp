# include <iostream>

using namespace std ;

int main () {
    int n ;
    cin >> n ;
    
    int T[100000] ;
    for (int i = 0; i < n; i++) {
        cin >> T[i] ;
    }
    
    long long c = 0 ;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (T[i] > T[j]) {
                c++ ;
            }
        }
    }
    
    cout << c << endl ;
}