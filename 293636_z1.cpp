# include <iostream>

using namespace std ;

int main () {
int a,b;
cin >> a;
b = 1;
while (a > 1)
{
    cout << " " << a;
    b++;
    if (a%2 == 0) {
        a = a/2;
    }
    else {
        a = 3*a+1;
    }
}
cout << " 1" << ", " << b;
}