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
        _size = 0u;
    }

    bool isEmpty(){
        return _root == NULL;
    }

    bool find(ll value){
        BSTNode *temp = __search(_root, value);

        if(!temp) return false;

        if(temp->key == value) return true;
        else return false;
    }

    void insert(ll value){
        if(!find(value)){
            _root = __insert(_root, value);
            _size++;
        }
    }

    void remove(ll value){
        if(find(value)){
            _root = __remove(_root, value);
            _size++;
        }
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

    ll findmax(){
        return __findmax(_root);
    }

    BSTNode* __createNode(ll value){
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));

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

        return root;
    }

    BSTNode* __insert(BSTNode *root, ll value){
        if(root == NULL) return __createNode(value);

        if(value < root->key) root->left = __insert(root->left, value);
        else if(value > root->key) root->right = __insert(root->right, value);

        return root;
    }

    BSTNode* __findMinNode(BSTNode *node){
        BSTNode *currNode = node;

        while(currNode && currNode->left != NULL) currNode = currNode->left;

        return currNode;
    }

    BSTNode* __remove(BSTNode *root, ll value){
        if(root == NULL) return NULL;

        if(value > root->key) root->right = __remove(root->right, value);
        else if(value < root->key) root->left = __remove(root->left, value);
        else{
            if(root->left == NULL){
                BSTNode *rightChild = root->right;

                free(root);

                return rightChild;
            }else if(root->right == NULL){
                BSTNode *leftChild = root->left;

                free(root);

                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);

            root->key = temp->key;
            root->right = __remove(root->right, temp->key);
        }

        return root;
    }

    void __inorder(BSTNode *root){
        if(root){
            __inorder(root->left);
            printf("%lld ", root->key);
            __inorder(root->right);
        }else{
            printf("%lld ", root->key);
        }
    }

    void __postorder(BSTNode *root){
        if(root){
            __postorder(root->left);
            __postorder(root->right);
            printf("%lld ", root->key);
        }
    }

    void __preorder(BSTNode *root){
        if(root){
            printf("%lld ", root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }

    ll __findmax(BSTNode *root){
        while(root && root->right != NULL) root = root->right;

        return root->key;
    }
};

int main(){
    BST set;
    set.init();

    ll T, N;
    cin >> T;

    for(ll i = 0; i < T; i++){
        cin >> N;

        set.insert(N);
    }

    ll max_new = set.findmax();

    cout << max_new << endl;

    ll v;

    while(cin >> v){
        set.remove(v);
        max_new = set.findmax();

        cout << max_new << endl;
    }

    return 0;
}
