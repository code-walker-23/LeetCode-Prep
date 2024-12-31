class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int firstOddFromLast = -1;

        for(int i = n-1; i >= 0; i--){
            // this will play with ascii values
            int digit = num[i] - '0';
            if(digit%2){
                firstOddFromLast = i;
                break;
            }
        }

        if(firstOddFromLast == -1)return "";
        return num.substr(0,firstOddFromLast+1);
    }
};