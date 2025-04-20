// we can also make this code more modular by making some helper methods in Node class
class Node {
public:
    Node* arr[26]; // Array of pointers for each character (a-z)
    bool flag; // Indicates if the node marks the end of a word
    string word;

    Node() {
        fill(begin(arr), end(arr), nullptr); // Initialize all pointers to nullptr
        flag = false; // Initialize flag to false
        word = "";
    }
};

class Trie{
private:
    Node* root;
public :
    Trie(){
        root = new Node();
    }

    Node* getRoot(){
        return root;
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
        temp->word = str;
    }

    bool search(string str) {
        Node* temp = root;
        for (char ch : str) {
            if (temp->arr[ch - 'a'] == nullptr) return false;
            temp = temp->arr[ch - 'a'];
        }
        return temp->flag;
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

class Solution {
public:
    void dfs(int i,int j,Node* head,vector<vector<char>>&board,vector<string>&res){

        if(i < 0 || i == board.size() || j < 0 || j == board[0].size())return;
        if(board[i][j] == '$')return;
        
        char ch = board[i][j];
        if(head->arr[ch-'a'] == NULL)return;
        // we have to remove duplicacy beacuse this may be inserted before
        if(head->arr[ch-'a']->word != ""){
            res.push_back(head->arr[ch-'a']->word);
            head->arr[ch-'a']->word = "";
        }

        int del[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        Node* next = head->arr[ch-'a'];
        board[i][j] ='$';
        
        for(int k = 0; k < 4; k++){
            int nrow = del[k][0] + i;
            int ncol = del[k][1] + j;

            dfs(nrow,ncol,next,board,res);
        }

        board[i][j] = ch;
    }
    

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // n*m*words.len*3^word[i].len -> TLE
        int n = words.size();
        Trie* obj = new Trie();
        vector<string>res;

        // W*L where W is the size of words and L is the avg size of any words[i]
        for(int i = 0; i < n; i++)obj->insert(words[i]);
        //  (n*m*4^L)
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                // for each cell as starting -> O(4^L) approx O(3^L)[exluding the cell it comes from]
                dfs(i,j,obj->getRoot(),board,res);
            }
        }
        // Total -> O(W*L + n*m*4^L) = O(n*m*4^L) 
        // suppose worst scenerio from constraints -> (12*12*4^10) = 144*1048576 = 150994944 = O(10^8) 

        return res;
    }
};