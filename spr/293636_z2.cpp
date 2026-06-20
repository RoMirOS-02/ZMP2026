# include <iostream>

using namespace std;

int main () {
int a,b;
cin >> a;
int c = -1;
for (int i = 0; i < a; i++)
{
    cin >> b;
    if (i == b) c = b;
}

cout << c;
}