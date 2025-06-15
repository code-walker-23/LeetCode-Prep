class Solution {
    public int maxProfit(int[] prices) {
        // naive will be (n^2) try to buy each day and sell in the future and calculate maxProfit;

        int maxProfit = 0;
        int buyPrice = prices[0];

        for(int i = 1; i < prices.length; i++){
            int sellingPrice = prices[i];
            if(sellingPrice > buyPrice){
                maxProfit = Math.max(maxProfit,sellingPrice-buyPrice);
            }else{
                buyPrice = sellingPrice;
            }
        }

        return maxProfit;
        
    }
}