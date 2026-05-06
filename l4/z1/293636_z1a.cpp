# include <iostream>

using namespace std ;

int F(int n) {
    if (n < 2) {
        return (1);
    }
    
    int a = 1;
    int b = 1; 
    int res = 0;
    
    for (int i = 2; i <= n; i++) {
        res = a + b;
        a = b;
        b = res;
    }
    
    return (res);
}

int main () {
    int n;
    cin >> n;
    cout << F(n);
}