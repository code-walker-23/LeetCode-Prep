class Node {
public:
    Node* arr[26]; // Array of pointers for each character (a-z)
    bool flag; // Indicates if the node marks the end of a word

    Node() {
        fill(begin(arr), end(arr), nullptr); // Initialize all pointers to nullptr
        flag = false; // Initialize flag to false
    }
};



class Trie{
private:
    Node* root;
public :
    Trie(){
        root = new Node();
    }
    void insert(string str) {
        Node* temp = root;
        for (char ch : str) {
            if (temp->arr[ch - 'a'] == nullptr) {
                temp->arr[ch - 'a'] = new Node();
            }
            temp = temp->arr[ch - 'a'];
        }
        temp->flag = true;
    }

    bool search(string str) {
        Node* temp = root;
        for (char ch : str) {
            if (temp->arr[ch - 'a'] == nullptr) return false;
            temp = temp->arr[ch - 'a'];
        }
        return temp->flag; // Corrected check for word existence
    }

    bool startsWith(string str) {
        Node* temp = root;
        for (char ch : str) {
            if (temp->arr[ch - 'a'] == nullptr) return false;
            temp = temp->arr[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */