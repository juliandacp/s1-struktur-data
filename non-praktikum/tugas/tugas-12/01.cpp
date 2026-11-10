#include <bits/stdc++.h>
#define ll long long
using namespace std;

class TreeNode{
    ll *keys, t, n;
    bool leaf;
    TreeNode **C;

public:
    TreeNode(ll temp, bool bool_leaf);
    void insertNonFull(ll k);
    void splitChild(ll i, TreeNode *y);
    void traverse();
    TreeNode *search(ll k);
    friend class BTree;
};

class BTree{
    TreeNode *root;
    ll t;

public:
    BTree(ll temp){
        root = NULL;
        t = temp;
    }

    void traverse(){
        if(root != NULL) root->traverse();
    }

    TreeNode *search(ll k){
        return (root == NULL) ? NULL : root->search(k);
    }

    void insert(ll k);
};

TreeNode::TreeNode(ll t1, bool leaf1){
    t = t1;
    leaf = leaf1;

    keys = new ll[2 * t - 1];
    C = new TreeNode *[2 * t];

    n = 0;
}

void TreeNode::traverse(){
    ll i;

    for(i = 0; i < n; i++){
        if(leaf == false) C[i]->traverse();
        cout << " " << keys[i];
    }

    if(leaf == false) C[i]->traverse();
}

TreeNode *TreeNode::search(ll k){
    ll i = 0;

    while(i < n && k > keys[i]) i++;

    if(keys[i] == k) return this;
    if(leaf == true) return NULL;

    return C[i]->search(k);
}

void BTree::insert(ll k){
    if(root == NULL){
        root = new TreeNode(t, true);

        root->keys[0] = k;
        root->n = 1;
    }
    else{
        if(root->n == 2 * t - 1){
            TreeNode *s = new TreeNode(t, false);

            s->C[0] = root;
            s->splitChild(0, root);

            ll i = 0;

            if(s->keys[0] < k) i++;

            s->C[i]->insertNonFull(k);

            root = s;
        }
        else root->insertNonFull(k);
    }
}

void TreeNode::insertNonFull(ll k){
    ll i = n - 1;

    if(leaf == true){
        while(i >= 0 && keys[i] > k){
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = k;
        n = n + 1;
    }
    else{
        while(i >= 0 && keys[i] > k) i--;
        if(C[i + 1]->n == 2 * t - 1) {
            splitChild(i + 1, C[i + 1]);
            if(keys[i + 1] < k) i++;
        }
        C[i + 1]->insertNonFull(k);
    }
}

void TreeNode::splitChild(ll i, TreeNode *y){
    TreeNode *z = new TreeNode(y->t, y->leaf);

    z->n = t - 1;

    for(ll j = 0; j < t - 1; j++) z->keys[j] = y->keys[j + t];
    if(y->leaf == false) for (ll j = 0; j < t; j++) z->C[j] = y->C[j + t];
    y->n = t - 1;
    for(ll j = n; j >= i + 1; j--) C[j + 1] = C[j];
    C[i + 1] = z;
    for(ll j = n - 1; j >= i; j--) keys[j + 1] = keys[j];
    keys[i] = y->keys[t - 1];

    n = n + 1;
}

int main(){
    BTree t(3);

    t.insert(8);
    t.insert(9);
    t.insert(10);
    t.insert(11);
    t.insert(15);
    t.insert(16);
    t.insert(17);
    t.insert(18);
    t.insert(20);
    t.insert(23);

    cout << "The B-tree is: ";

    t.traverse();

    ll k = 10;
    (t.search(k) != NULL) ? cout << endl << k << " is found" : cout << endl << k << " is not Found";
    
    k = 2;
    (t.search(k) != NULL) ? cout << endl << k << " is found" : cout << endl << k << " is not Found\n";

    return 0;
}