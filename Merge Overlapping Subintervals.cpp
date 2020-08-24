//Brute force approach having time complexity o(nlogn)+o(n^2) and space complexity o(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n=intervals.size();
        map<int,int> done;
        sort(intervals.begin(),intervals.end());
        for(int i = 0 ; i < n ; i++)
        {
            if(done[i])
                continue;
            done[i]=1;
            vector<int> temp;
            temp = intervals[i];
            int a = temp[0];
            int b = temp[1];
            
            for(int j = i + 1 ; j <n ; j++)
            {
                vector<int> temp2 = intervals[j];
                if((b >= temp2[0]) and !done[j] )
                {
                    done[j] = 1;
                    a = min(a,temp2[0]);
                    b = max(b,temp2[1]);
                }
            }
            vector<int> x;
            x.push_back(a);
            x.push_back(b);
            ans.push_back(x);
        }
        return ans;
    }
};


//Optimised approach having time complexity o(nlogn)+o(n) and space complexity o(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedintervals;
        if(intervals.size()==0)
            return mergedintervals;
        sort(intervals.begin(),intervals.end());
        vector<int> temp=intervals[0];
        for(auto it:intervals)
        {
            if(it[0]<=temp[1])
                temp[1]=max(it[1],temp[1]);
            else
            {
                mergedintervals.push_back(temp);
                temp=it;
            }
        }
        mergedintervals.push_back(temp);
        return mergedintervals;
        
    }
};
