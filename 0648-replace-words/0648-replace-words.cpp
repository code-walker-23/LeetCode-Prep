class Node{
public:
    Node* arr[26];
    bool flag;
    string root;

    Node(){
        fill(begin(arr),end(arr),nullptr);
        flag = false;
        root = "";
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string s){
        Node* temp = root;
        for(int i = 0; i < s.size(); i++){
            if(temp->arr[s[i]-'a'] == NULL){
                temp->arr[s[i]-'a'] = new Node();
            }
            temp = temp->arr[s[i]-'a'];
        }
        temp->flag = true;
        temp->root = s; 
    }

    string findRoot(string s){
        
        Node* temp = root;
        for(int i = 0; i < s.size(); i++){
            // no match
            if(temp->arr[s[i]-'a'] == NULL)return s;
            temp = temp->arr[s[i]-'a'];
            // root exist
            if(temp->flag)return temp->root;
        }
        // we have iterated through all elements that means we did not get its root
        // s is root in itself -> root + "" = possible derivative = s + "" = s -> s is root itself
        return s;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* obj = new Trie();
        for(int i = 0; i < dictionary.size(); i++)obj->insert(dictionary[i]);

        stringstream ss(sentence);
        string word;
        vector<string> words;

        while (ss >> word) words.push_back(word);

        string res;
        for(int i = 0; i < words.size(); i++){
            if(res == "")res += obj->findRoot(words[i]);
            else res = res + " " + obj->findRoot(words[i]);
        }

        return res;
    }
};