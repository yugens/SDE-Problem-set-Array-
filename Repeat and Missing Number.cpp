//Brute force approach with time complexity o(n) and space complexity o(n)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(int i=0;i<=n;i++)
        {
            if(mp[i]==0)
                return i;
        }
        return 1;
        
    }
};


//Better approach using (xor property) having time complexity o(n) and space complexity o(n)

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    long long int x=0;
    for(int i=0;i<n;i++)
    x^=A[i];
    for(int i=1;i<=n;i++)
    x^=i;
    long long int a=0,b=0;
    int set=x & ~(x-1);
    for(int i=0;i<n;i++)
    {
        if(A[i]&set)
        a^=A[i];
        else
        b^=A[i];
    }
    for(int i=i;i<=n;i++)
    {
        if(i&set)
        a^=i;
        else
        b^=i;
    }
    long long int p,q;
    for(int i=0;i<n;i++){
    if(A[i]==a)
    {
        p=a; q=b; 
        break;
    }
    if(A[i]==b) 
    {
        p=b; q=a; break;
    }
    }
    vector<int> v;
    v.push_back((int)p);
    v.push_back((int)q);
    return v;
    

    
}
//Optimal approach using time complexity o(n) and space complexity o(1)
vector Solution::repeatedNumber(const vector &A) 
{
  long n = A.size();
    long S1 = 0, S2 = 0;
    for(int i:A)
    {
        S1 += i;
        S2 += ((long)i)*i;
    }
    
    long E1 = n*(n+1)/2;
    long E2 = n*(n+1)*(2*n+1)/6;
    
    long D1 = S1-E1;
    long D2 = S2-E2;
    
    long DIF = D1;
    long SUM = D2/D1;
    
    long repeat = (SUM+DIF)/2;
    long miss = (SUM-DIF)/2;
    
    return {(int)repeat,(int)miss};
}
