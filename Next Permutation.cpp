//If you code in c++ then by using basic next_permutation STL function this problem can be solved in just one line::
//With time complexity o(n) and space complexity o(1)::

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
     bool x=std::next_permutation(nums.begin(),nums.end());
      return; 
    }
};

//Now, the Best approach with time complexity O(n) and space complexity o(1)::
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     int n=nums.size(),k,l;
        for(k=n-2;k>=0;k--)
        {
            if(nums[k]<nums[k+1])
                break;
        }
        if(k<0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(l=n-1;l>k;l--)
            {
                if(nums[l]>nums[k])
                    break;
            }
        swap(nums[k],nums[l]);
        reverse(nums.begin() +k+1,nums.end());
        }
    }
};
