//Having time complexity o(n) and space complexity o(1)
vector<int> Solution::plusOne(vector<int> &A) {
    int n=A.size();
    A[n-1]+=1;
    int carry=A[n-1]/10;
    A[n-1]=A[n-1]%10;
    for(int i=n-2;i>=0;i--){
        if(carry==1){
        A[i]+=1;
        carry=A[i]/10;
        A[i]=A[i]%10;
        }
    }
    if(carry==1)
    {
        A.insert(A.begin(),1);
    }
    for(int i=0;i<n;i++){
        if(A[i]!=0)
        {
            return vector<int>(A.begin()+i,A.end());
        }
    }    
    return A;
    
}
