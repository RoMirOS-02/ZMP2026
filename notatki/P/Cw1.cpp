#include <iostream>

using namespace std;

int mx=0,mn=0,r;
const int n=5;
int a[n];
int petla() {


    for (int i = 0; i < n; i++) {
        if (a[i] > mx){
            mx = a[i];
            continue;
        }
            if (a[i] < mn){
                mn = a[i];
            }
        }
        return (mn, mx);

}

int rek(r,mn,mx) {
    if (r == 1) {

    if (a[1] > a[0]){
            mx = a[1];
            mn = a[0];
        }
    else {
        mx = a[0];
        mn = a[1];
    }
   return (mn, mx);
}

    if (a[r] > mx){
            mx = a[r];
    }


    
}

int main() {

}