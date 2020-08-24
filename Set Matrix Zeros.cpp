//Brute force approach having time complexity o(n*m)*(n+m) and space complexity o(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
          for (int i=0;i<n;i++)
          {
              for(int j=0;j<m;j++)
              {
                  if(matrix[i][j]==0)
                  {
                      for(int k=0;k<n;k++)
                      {
                          if(matrix[k][j]!=0)
                              matrix[k][j]=-2000000000;
                          for(int k=0;k<m;k++)
                          {
                              if(matrix[i][k]!=0)
                                  matrix[i][k]=-2000000000;
                          }
                              
                      }
                  }
              }
          }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==-2000000000)
                    matrix[i][j]=0;
            }
        }
  }
};

//Better approach having time complexity o(n*m + n*m) and space complexity o(n)+o(m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
         if(n==0)
             return;
        int m = matrix[0].size();
        if(m==0)
            return;
        vector<int> v1(n,0);
        vector<int> v2(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    v1[i]=1;
                    v2[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v1[i]==1 or v2[j]==1)
                    matrix[i][j]=0;
                    
            }
        }

        return;
        
    }
};

//Optimised approach having time complexity o(n*m) and space complexity o(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(matrix[i][0]==0)
                flag=1;
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==0)
                    matrix[i][0]=matrix[0][j]=0;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=1;j--)
            {
                if(matrix[i][0]==0 or matrix[0][j]==0)
                    matrix[i][j]=0;
            }
            if(flag==1)
                matrix[i][0]=0;
        }
        
    }
};

