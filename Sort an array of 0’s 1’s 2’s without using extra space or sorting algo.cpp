//My solution for time complexity o(nlogn) and space complexity o(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for (auto x : nums) 
        cout<<x<<" ";
        
    }
};

//Now , the optimized solution in time complexity o(n) and space complexity o(1) commonly known as "DUTCH NATIONAL FLAG ALGORITHM'
class Solution {
public:
    void sortColors(vector<int>& nums) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int low=0;
        int high=nums.size()-1;
        int mid=0;
        while(mid<=high)
        {
            if(nums[mid]==0)
                swap(nums[low++],nums[mid++]);
            else if(nums[mid]==1)
                mid++;
            else if(nums[mid]==2)
                swap(nums[mid],nums[high--]);
        }
        
    }
};
