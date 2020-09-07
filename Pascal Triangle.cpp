//If it is only asked to find the element of nth row and cth column of a pascal's triangle , then the simple approach will be to find { (n-1)C(c-1) }.
//with a time complexity of o(n) and space complexity of o(1).


//Now, to find the whole row and column of a pascal's triangle.
//Time complexity o(n) and space complexity also o(n).
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> r(n);
        for(int i=0;i<n;i++)
        {
            r[i].resize(i+1);
            r[i][0]=r[i][i]=1;
            for(int j=1;j<i;j++)
                r[i][j]=r[i-1][j-1]+r[i-1][j];
        }
        return r;
    }
};
