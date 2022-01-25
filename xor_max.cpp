#include <iostream> 
#include <cstdint>

using namespace std;  

struct Node {
    Node* left; 
    Node* right; 
    int64_t val; 
};  

Node* create_node() {
    Node* node = new Node(); 
    node->left = nullptr; 
    node->right = nullptr; 
    node->val = 1;  
    return node; 
} 

void PrintTree(Node* root) {  
    if(root == nullptr) {
        return;
    }
    cout << root->val << "\n"; 
    PrintTree(root->left); 
    PrintTree(root->right);
}

bool _find(Node* root, uint64_t num) { 
    Node* node = root;  
    bool contains = true;
    for(int i = 63; i >= 0; i--) { 
        uint64_t bit = ((num>>i) & 1ull); 
        if(bit == 0) { 
            if(node->left != nullptr) {
                node = node->left; 
            } else  {
                contains = false; 
                break; 
            }
        }  
        if(bit == 1) { 
            if(node->right != nullptr) {
                node = node->right;
            } else  {
                contains = false; 
                break; 
            }
        }  
    } 
    return contains;
} 

void _insert(Node* root, uint64_t num) { 
    bool is = _find(root, num); 
    if(is == true) {
        return;
    }
    Node* node = root; 
    for(int i = 63; i >= 0; i--) { 
        uint64_t bit = ((num>>i)& 1ull);  
        if(bit == 0) { 
            if(node->left == nullptr) {
                node->left = create_node();  
            } else {
                node->left->val++;
            }
            node = node->left; 
        } 
        if(bit == 1) {
            if(node->right == nullptr) {
                node->right = create_node(); 
            }  else {
                node->right->val++;
            }
            node = node->right; 
        }
    } 
}  

void delete_tree(Node* node) {
    if(node->left != nullptr) {
        delete_tree(node->left);
    }  
    if(node->right != nullptr) {
        delete_tree(node->right); 
    } 
    delete node; 
} 

void del_element(Node* root, uint64_t num) {
    Node* node = root;  
    bool is = _find(root, num);  
    if(is == false) {
        return; 
    }
    for(int i = 63; i >= 0; i--) {
        uint64_t bit = ((num>>i) & 1ull);
        if(bit == 0) { 
            if(node->left->val == 1) {
                delete_tree(node->left); 
                node->left = nullptr;   
                break; 
            } else { 
                node->left->val--; 
                node = node->left; 
            }
        }
        if(bit == 1) {
            if(node->right->val == 1) {
                delete_tree(node->right); 
                node->right = nullptr; 
                break;
            } else { 
                node->right->val--; 
                node = node->right; 
            }
        }
    } 
    return; 
}  

uint64_t xor_max(Node* root, uint64_t num) {
    Node* node = root;  
    uint64_t res = 0;  
    if(root->left == nullptr && root->right == nullptr) {
        return res;
    }
    for(int i = 63; i >= 0; i--) { 
        uint64_t bit = ((num>>i) & 1ull);   
        if((node->left != nullptr && bit == 1) || node->right == nullptr) {
            node = node->left; 
        } else {
            if((node->right != nullptr && bit == 0) || node->left == nullptr) {
                res |= (1ull<<i); 
                node = node->right;
            } 
        }
    } 
    return res;
}


int main() {
    ios_base::sync_with_stdio(NULL); 
    cin.tie(NULL);
    cout.tie(NULL); 

    int64_t n;
    cin >> n;  

    Node* root = create_node(); 

    for(int i = 0; i < n; i++) {
        int command; 
        uint64_t num;
        cin >> command >> num; 
        if(command == 1) {
            _insert(root, num);  
        } 
        if(command == 2) {
            del_element(root, num);
        } 
        if(command == 3) { 
            cout << xor_max(root, num) << "\n"; 
        }
    }  
    
    delete_tree(root);
    return 0;
}