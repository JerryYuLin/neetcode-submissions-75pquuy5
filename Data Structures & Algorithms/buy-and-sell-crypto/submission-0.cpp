class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, min_price = prices[0];

        for(int price:prices){
            if(price>min_price && (price - min_price) > profit){
                profit = price-min_price;
            }
            else if (price < min_price){
                min_price = price;
            }
        }

        return profit;
    }
};