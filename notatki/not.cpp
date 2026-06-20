# include <iostream>

using namespace std ;

int a,c;
int i=1;

double log7 (int a) {
    return (log(a)/log(7));
}



int main () {
    cin >> a;
    while (i <= a)
    {
        c =+ 1/(log7(i+6));
        i++;
    }
    cout << c;
    return 0 ;
}