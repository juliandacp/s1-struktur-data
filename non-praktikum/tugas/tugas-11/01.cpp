#include <bits/stdc++.h>
#include <windows.h>
#define ll long long
using namespace std;

class Node{
public:
    string name;
    Node* parent;
    vector<Node*> children;

    Node(string folderName, Node* p = NULL){
        name = folderName;
        parent = p;
    }
};

class FolderTree{
private:
    Node* root;

public:
    FolderTree(){
        root = new Node("Root");
    }
    
    Node* getRoot(){
        return root;
    }

    void addFolder(Node* parent, string folderName){
        Node* newFolder = new Node(folderName, parent);
        parent->children.push_back(newFolder);
        cout << "Folder '" << folderName << "' berhasil ditambahkan ke '" << parent->name << "'\n";
    }

    void prllTree(Node* node, string prefix = "", bool isLast = true){
        if(node == NULL) return;
        if(node == root) cout << node->name << endl;
        else{
            cout << prefix;
            cout << (isLast ? "└── " : "├── ");
            cout << node->name << endl;
        }

        string newPrefix;

        if(node == root) newPrefix = "";
        else newPrefix = prefix + (isLast ? "    " : "│   ");

        for(size_t i = 0; i < node->children.size(); i++){
            bool lastChild = (i == node->children.size() - 1);
            prllTree(node->children[i], newPrefix, lastChild);
        }
    }
    
    void preorder(Node* node){
        if(node == NULL) return;

        cout << node->name << endl;

        for(Node* child : node->children) preorder(child);
    }

    void postorder(Node* node){
        if(node == NULL) return;

        for(Node* child : node->children) postorder(child);

        cout << node->name << endl;
    }

    Node* search(Node* node, string target){
        if(node == NULL) return NULL;
        if(node->name == target) return node;

        for(Node* child : node->children){
            Node* result = search(child, target);

            if(result != NULL) return result;
        }

        return NULL;
    }

    ll countFolder(Node* node){
        if(node == NULL) return 0;

        ll total = 1;

        for(Node* child : node->children) total += countFolder(child);

        return total;
    }

    void showPath(Node* node){
        if(node == NULL) return;

        vector<string> path;
        Node* current = node;

        while(current != NULL){
            path.push_back(current->name);
            current = current->parent;
        }

        cout << "Path : ";

        for(ll i = path.size() - 1; i >= 0; i--){
            cout << path[i];
            if(i != 0) cout << "/";
        }

        cout << endl;
    }

    void deleteSubtree(Node* node){
        if(node == NULL) return;

        for(Node* child : node->children) deleteSubtree(child);

        delete node;
    }

    void deleteFolder(string folderName){
        Node* target = search(root, folderName);

        if(target == NULL){
            cout << "Folder tidak ditemukan!\n";
            return;
        }

        if(target == root){
            cout << "Root tidak dapat dihapus!\n";
            return;
        }

        Node* parent = target->parent;

        for(auto it = parent->children.begin(); it != parent->children.end(); it++){
            if(*it == target){
                parent->children.erase(it);
                break;
            }
        }

        deleteSubtree(target);
        cout << "Folder berhasil dihapus!\n";
    }
};

int main(){
    SetConsoleOutputCP(CP_UTF8);
    FolderTree tree;

    Node* root = tree.getRoot();
    tree.addFolder(root, "Documents");
    tree.addFolder(root, "Pictures");
    tree.addFolder(root, "Music");
    Node* documents = tree.search(root, "Documents");
    tree.addFolder(documents, "Kuliah");
    tree.addFolder(documents, "Tugas");

    cout << "\n===== STRUKTUR FOLDER =====\n";
    tree.prllTree(root);

    cout << "\n===== PREORDER TRAVERSAL =====\n";
    tree.preorder(root);

    cout << "\n===== POSTORDER TRAVERSAL =====\n";
    tree.postorder(root);

    cout << "\n===== SEARCH FOLDER =====\n";

    Node* result = tree.search(root, "Tugas");

    if(result != NULL){
        cout << "Folder ditemukan : " << result->name << endl;
        tree.showPath(result);
    }
    else cout << "Folder tidak ditemukan\n";

    cout << "\n===== JUMLAH FOLDER =====\n";
    cout << "Total Folder : " << tree.countFolder(root) << endl;
    cout << "\n===== HAPUS FOLDER =====\n";
    tree.deleteFolder("Pictures");
    cout << "\n===== STRUKTUR SETELAH DELETE =====\n";
    tree.prllTree(root);

    return 0;
}