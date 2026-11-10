#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct BSTNode{
    ll key;
    BSTNode *left, *right;
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

    BSTNode* createNode(ll value){
        BSTNode* node = (BSTNode*) malloc(sizeof(BSTNode));

        node->key = value;
        node->left = node->right = NULL;

        return node;
    }

    BSTNode* search(BSTNode *root, ll value){
        while(root != NULL){
            if(value < root->key) root = root->left;
            else if(value > root->key) root = root->right;
            else return root;
        }

        return NULL;
    }

    BSTNode* insertNode(BSTNode *root, ll value){
        if(root == NULL){
            BSTNode* node = createNode(value);
            return node;
        }

        if(value < root->key) root->left = insertNode(root->left, value);
        else if(value > root->key) root->right = insertNode(root->right, value);

        return root;
    }

    bool find(ll value){
        BSTNode *temp = search(_root, value);

        return temp != NULL && temp->key == value;
    }

    void insert(ll value){
        if(!find(value)){
            _root = insertNode(_root, value);
            _size++;
        }
    }

    BSTNode* findNode(ll value){
        return search(_root, value);
    }

    ll maxDepth(BSTNode *root){
        if(root == NULL) return 0;

        ll left = maxDepth(root->left);
        ll right = maxDepth(root->right);
        ll res;

        if(left > right) res = left;
        else res = right;

        return 1 + res;
    }
};

int main(){
    BST bst;
    bst.init();

    ll N;
    cin >> N;

    for(ll i = 0; i < N; i++){
        ll x;
        cin >> x;

        bst.insert(x);
    }

    ll M;
    cin >> M;

    BSTNode* start = bst.findNode(M);
    ll depth = bst.maxDepth(start) - 1;
    ll gaji = 10000 * depth * depth;

    cout << gaji << endl;

    return 0;
}
