class Solution {
public:
    int charToInt(char ch){
        if(ch == '0'){
            return 0;
        }
        if(ch == '1'){
            return 1;
        }
        if(ch == '2'){
            return 2;
        } 
        if(ch == '3'){
            return 3;
        } 
        if(ch == '4'){
            return 4;
        }
        if(ch == '5'){
            return 5;
        } 
        if(ch == '6'){
            return 6;
        } 
        if(ch == '7'){
            return 7;
        } 
        if(ch == '8'){
            return 8;
        }
        if(ch == '9'){
            return 9;
        }
        return -1;
    }
    int myAtoi(string s) {
        int n = s.size();
        long long num = 0;
        char sign = '+';
        int i = 0;

        for(i; i < n; i++){
            if(s[i] != ' '){
                break;
            }
        }
        cout << i << endl;
        if(s[i] == '-'){
            sign = '-';
            cout << s[i] << endl;
            i++;
        }else if(s[i] == '+'){
            i++;
        }
        cout << "sign -> " << sign << endl; 
        set<char> se = {'0','1','2','3','4','5','6','7','8','9'};
        for(i; i < n; i++){
            if(se.count(s[i]) == 0){
                break;
            }else{
              if(s[i] == '0' && num == 0){

              }else{
                int x = charToInt(s[i]);
                cout << x << endl;
                cout << i << " -> " << s[i] << " -> " << x << endl;
                num = (num*10) + x;
                if(sign == '-' && (num*-1) <= INT_MIN){
                    num = INT_MIN;
                    cout << "hoo" << endl;
                    break;
                }else if(sign == '+' && num >= INT_MAX ){
                    num = INT_MAX;
                    cout << "Hello";
                    break;
                }
              } 
            }
        }
        cout << num << endl;
        return sign == '+' ? num : num*-1;
    }
};