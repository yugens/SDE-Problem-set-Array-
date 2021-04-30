//My solution for  time and space o(n) 
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]>1)
                return nums[i];
        }
        return 1;
            
        
    }
};

//SLow and fast pointer approach with T.C. o(n) and S.C. o(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int slw=nums[0];
       int fst=nums[0];
       do
       {
         slw = nums[slw];
         fst=nums[nums[fst]];
       }
        while(slw!=fst);
        fst=nums[0];
        while(slw!=fst)
        {
            slw=nums[slw];
            fst=nums[fst];
        }
        return slw;
    }
};



