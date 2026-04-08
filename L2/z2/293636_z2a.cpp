# include <iostream>
# include <list>

using namespace std ;

int main () {
    int n, x, a;
    cin >> x >> n;
    list <int> L;
    for (int i=0; i < n; i++){
        cin >> a;
        L.push_back (a);
    }
    cout << L.size();
}