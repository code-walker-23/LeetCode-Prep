class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())return false;
        if(s == goal) return true;
        // Brute Force

        int rightMost = 0;
        int leftMost = s.size()-1;

        int rotation = 0;

        while(rotation < s.size()-1){
            s = s.substr(1) + s[0];
            if(s == goal)return true;
            rotation++;
        }

        return false;

    }
};