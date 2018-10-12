class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0)
            return -1;
        sort(coins.begin(), coins.end());
        int napSack[amount+1];
        napSack[0] = 0;
        for(int i = 1; i <= amount;++i){
            int min = amount+1;
            for(int j = coins.size()-1; j >= 0; --j){
                if(coins[j] <= i && napSack[i-coins[j]] != -1){
                    if(min > napSack[i-coins[j]])
                        min = napSack[i-coins[j]];
                }
            }
            if(min != amount+1){
                napSack[i] = min + 1;
            } else
                napSack[i] = -1;
        }
        return napSack[amount];
    }
};