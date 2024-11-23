vector<long long> Solution::rangeSum(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size();
    int m = B.size();
    vector<long long> ans;
    vector<long long> prefixSum(n+1 , 0);
    for(int i = 0; i < n; i++){
        if(i == 0) prefixSum[0] = A[0];
        else
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }
    for(int i = 0; i < m; i++){
        if(B[i][0] == 0){
            ans.push_back(prefixSum[B[i][1]]);
        }
        else{
            ans.push_back(prefixSum[B[i][1]] - prefixSum[B[i][0] - 1]);
        }
    }
    return ans;
}
