#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct BSTNode{
    BSTNode *left, *right;
    ll key;
};

struct BST{
    BSTNode *_root;
    unsigned int _size;

    void init(){
        _root = NULL;
        _size = 0;
    }

    bool isEmpty(){
        return _root == NULL;
    }

    bool find(ll value){
        return __search(_root, value) != NULL;
    }

    void insert(ll value){
        _root = __insert(_root, value);
        _size++;
    }

    void traverseInorder(){
        __inorder(_root);
    }

    void traversePreorder(){
        __preorder(_root);
    }

    void traversePostorder(){
        __postorder(_root);
    }

    ll getMin(){
        BSTNode *curr = _root;

        while(curr->left) curr = curr->left;

        return curr->key;
    }

    ll getMax(){
        BSTNode *curr = _root;

        while(curr->right) curr = curr->right;

        return curr->key;
    }

    ll getHeight(){
        return __height(_root);
    }

    BSTNode* __createNode(ll value){
        BSTNode *newNode = new BSTNode();

        newNode->key = value;
        newNode->left = newNode->right = NULL;

        return newNode;
    }

    BSTNode* __search(BSTNode *root, ll value){
        while(root != NULL){
            if(value < root->key) root = root->left;
            else if(value > root->key) root = root->right;
            else return root;
        }

        return NULL;
    }

    BSTNode* __insert(BSTNode *root, ll value){
        if(root == NULL) return __createNode(value);

        if(value < root->key) root->left = __insert(root->left, value);
        else root->right = __insert(root->right, value);

        return root;
    }

    void __inorder(BSTNode *root){
        if(root){
            __inorder(root->left);
            cout << root->key << " ";
            __inorder(root->right);
        }
    }

    void __preorder(BSTNode *root){
        if(root){
            cout << root->key << " ";
            __preorder(root->left);
            __preorder(root->right);
        }
    }

    void __postorder(BSTNode *root){
        if(root){
            __postorder(root->left);
            __postorder(root->right);
            cout << root->key << " ";
        }
    }

    ll __height(BSTNode *root){
        if(root == NULL) return 0;

        return 1 + max(__height(root->left), __height(root->right));
    }
};

int main(){
    BST tree;
    tree.init();

    map<ll, ll> freq;
    ll N;
    cin >> N;

    for(ll i = 0; i < N; i++){
        ll x;
        cin >> x;

        tree.insert(x);
        freq[x]++;
    }

    ll X;
    cin >> X;

    cout << "Inorder Traversal: ";
    tree.traverseInorder();
    cout << endl;

    cout << "Preorder Traversal: ";
    tree.traversePreorder();
    cout << endl;

    cout << "Postorder Traversal: ";
    tree.traversePostorder();
    cout << endl;

    cout << "Minimum Value: " << tree.getMin() << endl;
    cout << "Maximum Value: " << tree.getMax() << endl;
    cout << "Height: " << tree.getHeight() << endl;

    if(tree.find(X)) cout << "Search " << X << ": FOUND" << endl;
    else cout << "Search " << X << ": NOT FOUND" << endl;

    cout << "Frequency of " << X << ": " << freq[X] << endl;

    return 0;
}
