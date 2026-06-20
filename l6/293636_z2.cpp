#include <iostream>

using namespace std ;

struct TNode {
    int v ;
    TNode* l ;
    TNode* r ;
} ;

TNode* mergeTrees(TNode* t1, TNode* t2, int r) {
    return new TNode{r, t1, t2} ;
}

TNode* buildTree(int A[], int n) {
    if (n <= 0) return nullptr ;
    int rootVal = A[n - 1] ;
    int lSz = (n - 1) / 2 ;
    int rSz = n - 1 - lSz ;
    TNode* root = new TNode{rootVal, nullptr, nullptr} ;
    root->l = buildTree(A, lSz) ;
    root->r = buildTree(A + lSz, rSz) ;
    return root ;
}

bool searchTree(TNode* root, int s) {
    if (!root) return false ;
    if (root->v == s) return true ;
    return searchTree(root->l, s) || searchTree(root->r, s) ;
}

int height(TNode* root) {
    if (!root) return 0 ;
    int lh = height(root->l) ;
    int rh = height(root->r) ;
    return (lh > rh ? lh : rh) + 1 ;
}

void count(TNode* root, int& nodes, int& leaves) {
    if (!root) return ;
    nodes++ ;
    if (!root->l && !root->r) leaves++ ;
    count(root->l, nodes, leaves) ;
    count(root->r, nodes, leaves) ;
}

void print(TNode* root, int d = 0) {
    if (!root) return ;
    print(root->r, d + 1) ;
    for (int i = 0; i < d; i++) cout << "    " ;
    cout << root->v << endl ;
    print(root->l, d + 1) ;
}

int main () {
    int n1, n2, r, s ;
    if (!(cin >> n1 >> n2 >> r >> s)) return 0 ;
    
    int A1[100000], A2[100000] ;
    for (int i = 0; i < n1; i++) cin >> A1[i] ;
    for (int i = 0; i < n2; i++) cin >> A2[i] ;
    
    TNode* t1 = buildTree(A1, n1) ;
    TNode* t2 = buildTree(A2, n2) ;
    TNode* root = mergeTrees(t1, t2, r) ;
    
    print(root) ;
    
    int nodes = 0, leaves = 0 ;
    count(root, nodes, leaves) ;
    
    cout << "Wezly: " << nodes << endl ;
    cout << "Liscie: " << leaves << endl ;
    cout << "Wysokosc: " << height(root) << endl ;
    cout << "Czy s jest w drzewie: " << (searchTree(root, s) ? "Tak" : "Nie") << endl ;
    
    return 0 ;
}