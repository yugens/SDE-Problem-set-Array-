// Brute force approach with time complexity of o(n^3)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum=0,maximum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                for(int k=i;k<=j;k++)
                {
                    sum+=nums[k];
                }
                
                    maximum = max(maximum,sum);
                    sum=0;
            }
        }
        return maximum;
        
        
    }
};


// Better approach with a time complexity of o(n^2)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum=0,maximum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                 sum+=nums[j];
                 maximum = max(maximum,sum);
            }
                 sum=0;
        }
        return maximum;
        
        
    }
};  


// Most optimised approach with time complexity of o(n) commonly known as "KADANE'S ALGORITHM"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum=0,maximum=INT_MIN;
        for(int i=0;i<n;i++)
        {
                 sum+=nums[i];
                 maximum = max(maximum,sum);
               if(sum<0)
                 sum=0;
        }
        return maximum;
        
        
    }
};
