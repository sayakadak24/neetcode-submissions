class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start = 0; int end = 1;
        int max_profit = 0;

        while(end < prices.size()){
            if(prices[start] < prices[end]){
                int profit = prices[end] - prices[start];
                max_profit = max(max_profit, profit);
            } else {
                start = end;
            }
            end++;
        }
        return max_profit;
    }
};
