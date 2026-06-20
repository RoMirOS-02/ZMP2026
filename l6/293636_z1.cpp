#include <iostream>

using namespace std ;

struct Node {
    int val ;
    Node* next ;
} ;

int main () {
    int n ;
    if (!(cin >> n)) return 0 ;
    
    Node* head = nullptr ;
    Node* tail = nullptr ;
    
    for (int i = 0; i < n; i++) {
        int x ;
        cin >> x ;
        Node* t = new Node{x, nullptr} ;
        if (!head) {
            head = t ;
            tail = t ;
        } else {
            tail->next = t ;
            tail = t ;
        }
    }
    
    if (head) {
        bool sw = true ;
        while (sw) {
            sw = false ;
            Node* curr = head ;
            while (curr && curr->next) {
                if (curr->val > curr->next->val) {
                    int tmp = curr->val ;
                    curr->val = curr->next->val ;
                    curr->next->val = tmp ;
                    sw = true ;
                }
                curr = curr->next ;
            }
        }
    }
    
    Node* curr = head ;
    while (curr) {
        cout << curr->val << " " ;
        curr = curr->next ;
    }
    cout << endl ;
    
    while (head) {
        Node* tmp = head ;
        head = head->next ;
        delete tmp ;
    }
    
    return 0 ;
}