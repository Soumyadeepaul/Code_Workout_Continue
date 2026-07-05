//https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/


class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result(prices.size());
        stack<int> store;
        for(int i=prices.size()-1;i>-1;i--){
            int get=0;
            while(!store.empty()){
                int top=store.top();
                if(top<=prices[i]){
                    get=top;
                    break;
                }
                else store.pop();
            }
            result[i]=prices[i]-get;
            store.push(prices[i]);
        }
        return result;
    }
};
