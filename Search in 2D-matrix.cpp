//Better solution having time complexity o(nlog(m)) and space complexity o(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool res=false;
        for(int i=0;i<n;i++)
        {
              res=res or  binary_search(matrix[i].begin(),matrix[i].end(),target);
        }
        return res;
    }
};

//Another better solution which optimesd one if the matrix is row and column wise sorted
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size();
       int m=matrix[0].size();
       int i=0,j=m-1;
       while(i<n and j>=0)
       {
       if(matrix[i][j]==target)
           return true;
        else
        {
            if(matrix[i][j]>target)
                j--;
            else
                i++;
        }
       }
        return false;
    }
};

//Optimised Approach having time complexity log(n*m) and space complexity o(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size();
       int m=matrix[0].size();
       int l=0,r=n*m;
        while(l<r)
        {
            int mid=(l+r)/2;
            int row=mid/m , col=mid%m;
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]>target)
                r=mid;
            else
                l=mid+1;
        }
        return false;
    }
};










