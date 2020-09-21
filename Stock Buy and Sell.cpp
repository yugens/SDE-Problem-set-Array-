//Time complexity : o(n) , Space complexity : o(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minimum = INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++)
        {
           minimum=min(minimum,prices[i]);
           ans=max(ans,prices[i]-minimum); 
        }
        return ans;
    }
};
