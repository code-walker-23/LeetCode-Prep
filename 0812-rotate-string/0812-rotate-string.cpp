class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())return false;
        if(s == goal) return true;

        int n = s.size();
        // efficient
        // when we concatenate a string with itself we get all possible rotations

        s = s+s;
        // we know goal is created by doing rotations now we can check it is a valid rotation or not
        // for(int i = 1; i <= n; i++){
        //     if(s.substr(i,n) == goal)return true;
        // }

        // return false;
        // one liner

        return s.find(goal) != string::npos;
    }
};

 // using stl
// for(int i = 1; i < s.size(); i++){
//     rotate(s.begin(),s.begin()+1,s.end());
//     if(s == goal)return true;
// }

// return false;


    // Brute Force
    // int rightMost = 0;
    // int leftMost = s.size()-1;

    // int rotation = 0;
    // O(n^2)
    // while(rotation < s.size()-1){
    //     s = s.substr(1) + s[0];
    //     if(s == goal)return true;
    //     rotation++;
    // }

    // return false;