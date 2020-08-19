//Brute force approach with time complexity o(nlogn) and space complexity o(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for (auto x : nums) 
        cout<<x<<" ";
        
    }
};

//Better approach with time complexity o(2n) and space complexity o(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int , int> m;
        for(auto & it: nums)
        {
            m[it]++;
        }
        
        for(int i = 0;i<m[0];i++)
        {
            nums[i]=0;
        }
        for(int j = 0;j<m[1];j++)
        {
            nums[m[0]+j] = 1;
        }
         for(int j = 0;j<m[2];j++)
        {
            nums[m[1]+m[0]+j] = 2;
        }
        return ;
    }
};


//Now , the optimized solution with time complexity o(n) and space complexity o(1) in only one pass commonly known as "DUTCH NATIONAL FLAG ALGORITHM'
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
