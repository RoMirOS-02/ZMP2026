# include <iostream>

using namespace std ;

int main () {
int a,i,cnt;
bool n = true;
cin >> a;

while (n)
{
    a++;
    cnt = 0;
    for (int i = 1; i <= a; i++) {  
            if (a % i == 0)
                cnt++;
        }
    if (cnt == 2) {
        n = false;
    }
}

cout << a;
}