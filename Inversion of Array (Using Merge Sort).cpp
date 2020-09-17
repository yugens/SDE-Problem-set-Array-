//Brute force approach with time complexity o(n^2) and space complexity o(1)

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long long unsigned int llu;
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define mod 1000000007
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define YUGEN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define lp(i,start,end) for(int i=start;i<end;i++)
#define MAX 105
#define BPC(x)  __builtin_popcountll(x)
#define test() ll t; cin>>t; while(t--)
#define gcd(a,b)  __gcd(a,b)
#define SIZE 26
ll gcd(ll a,ll b) {if (a==0) return b;return gcd(b%a,a);}

int main()
 {
    YUGEN;
    test()
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                count++;
            }
        }
        cout<<count<<endl;
    }
 }
 
 //Optimised approach using merge sort in time complexity o(nlogn) and space complexity o(n)
 
#include<bits/stdc++.h>
using namespace std;
#define test() int t; cin>>t; while(t--)
long long int mergesort(long long int nums[],long long int temp[],long long int l,long long int r);
long long int merge(long long int nums[],long long int temp[],long long int l,long long int mid,long long int r);

        long long int merge(long long int nums[],long long int temp[],long long int l,long long int mid,long long int r)
        {
            long long int i=l;
            long long int j=mid;
            long long int k=l;
            long long int inv_count=0;
            while((i<=mid-1)and(j<=r))
            {
                if(nums[i]<=nums[j])
                {
                    temp[k]=nums[i];
                    k++;i++;
                }
                else
                {
                    temp[k]=nums[j];
                    k++;j++;
                    inv_count = inv_count + (mid-i);
                }
            }
            while(i<=mid-1)
                temp[k++]=nums[i++];
            while(j<=r)
                temp[k++]=nums[j++];
            for(i=l;i<=r;i++)
                nums[i]=temp[i];
            return inv_count;    
        }
          long long int mergesort(long long int nums[],long long int temp[],long long int l,long long int r)
        {
            long long int mid,inv_count=0;
            if(r>l)
            {
               mid=(r+l)/2;
               inv_count+= mergesort(nums,temp,l,mid);
               inv_count+=mergesort(nums,temp,mid+1,r);
               inv_count+= merge(nums,temp,l,mid+1,r);
            }
            return inv_count;
        }
        int main()
       {
        test()
        {
        long long int n;
        cin>>n;
        long long int nums[n];
        for(long long int i=0;i<n;i++)
        cin>>nums[i];
        long long int temp[n];
        long long int ans= mergesort(nums,temp,0,n-1);
        cout<<ans<<endl;
        }
        return 0;
        }
    

