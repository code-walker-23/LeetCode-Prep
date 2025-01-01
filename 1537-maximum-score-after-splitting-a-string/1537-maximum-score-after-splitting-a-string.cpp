class Solution {
public:
    int maxScore(string s) {
        //prefix sum
        int n = s.size();
        vector<int>prefixZeros(n);
        vector<int>suffixOnes(n);

        prefixZeros[0] = s[0] == '0' ? 1 : 0;
        suffixOnes[n-1] = 0;

        for(int i = 1; i < n; i++){
            prefixZeros[i] = prefixZeros[i-1];
            if(s[i] == '0')prefixZeros[i]++;
        }
        
        for(int i = n-2; i >= 0; i--){
            suffixOnes[i] = suffixOnes[i+1];
            if(s[i+1] == '1')suffixOnes[i]++;
        }

        int maxScore = 0;
        for(int i = 0; i < n-1; i++){
            maxScore = max(maxScore,prefixZeros[i]+suffixOnes[i]);
        }

        return maxScore;
    }
};