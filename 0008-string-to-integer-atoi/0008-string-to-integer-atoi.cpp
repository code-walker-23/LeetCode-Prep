
class Solution {
public:
// Time Complexity -> O(n)
// Space Complexity -> O(1)
    int myAtoi(string s) {
        int n = s.size();
        long long num = 0;
        int sign = 1;

        // avoiding the whitespaces
        int i = 0;
        while(i < n && s[i] == ' '){
            i++;
        }

        // checking for he sign +/-

        if(i < n && s[i] == '-'){
            sign = -1;
            i++;
        }else if(i < n && s[i] == '+'){
            i++;
        }
        
        // chekcing the char digit in the constant time
        unordered_set<char> se = {'0','1','2','3','4','5','6','7','8','9'};
        
        // checking digit char
        while(i < n && se.count(s[i])){
            if(num*sign < INT_MIN/10 || (num*sign == INT_MIN/10 && (s[i]-'0')>8)){
                return INT_MIN;
            }else if(num*sign > INT_MAX/10 || (num*sign == INT_MAX/10 && (s[i]-'0')>7)){
                return INT_MAX;
            }
            num = num*10 + (s[i]-'0');
            i++;

            // if(num*sign < INT_MIN){
            //     return INT_MIN;
            // }else if(num*sign > INT_MAX){
            //     return INT_MAX;
            // }
        }

        // return the value in range
        cout << "hello";
        return num*sign;
    }
};