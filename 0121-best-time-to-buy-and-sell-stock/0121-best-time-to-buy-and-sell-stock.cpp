class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //brute force will be the O(n^2)
        // int maxProfit = 0;
        // for(int i = 0; i < prices.size(); i++){
        //     for(int j = i+1; j < prices.size(); j++){
        //         if(prices[j] > prices[i])maxProfit = max(maxProfit,prices[j]-prices[i]);
        //     }
        // }
        // return maxProfit;

        // optimized will be O(n)
        
        // int maxProfit = 0;
        // int buy = prices[0];

        // for(int i = 1; i < prices.size(); i++){
        //     if(prices[i] > buy)maxProfit = max(maxProfit,prices[i]-buy);
        //     // i will buy now because it is minimum
        //     else buy = prices[i];
        // }
        // // we will keep simple approach i will buy for minnimum and sell for max such that we will do 1 transaction that maximize the objectivity of the problem.
        // return maxProfit;
        
        // opposite of above solution
        int n = (int)prices.size();
        if(n < 2) return 0;
        int maxPrize = 0, maxProfit = 0;
        for(int i = n-1; i >= 0; i--) {
            maxProfit = max(maxProfit, maxPrize - prices[i]);
            maxPrize = max(maxPrize, prices[i]);
        }
        return maxProfit;

    }
};