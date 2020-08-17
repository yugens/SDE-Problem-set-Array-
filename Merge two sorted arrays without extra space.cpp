//My approach for time complexity o(n*m) 

#include<bits/stdc++.h>
typedef long long int ll;
typedef long long unsigned int llu;
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define YUGEN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define lp(i,start,end) for(int i=start;i<end;i++)
#define MAX 105
#define test() ll t; cin>>t; while(t--)
using namespace std;
ll gcd(ll a,ll b) {if (a==0) return b;return gcd(b%a,a);}
int main()
 {
    YUGEN;
       ll n,m;
       cin>>n>>m;
       ll a[n];
       for(int i=0;i<n;i++)
        cin>>a[i];
       ll b[m];
       for(int i=0;i<m;i++)
        cin>>b[i];
        for(int i=0;i<n;i++)
        {
            if(a[i]>b[0])
            {
                swap(a[i],b[0]);
                sort(b,b+m);
            }
        }
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
       cout<<endl;
       for(int i=0;i<m;i++)
        cout<<b[i]<<" ";
       cout<<endl;



 return 0;
 }
 
 //Now , the code with most optimised approach having time complexity o(nlog(n)) commonly known as "Insertion Sort Algorithm"
 
 #include<bits/stdc++.h>
typedef long long int ll;
typedef long long unsigned int llu;
#define pb push_back
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define YUGEN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define lp(i,start,end) for(int i=start;i<end;i++)
#define MAX 105
#define test() ll t; cin>>t; while(t--)
using namespace std;
ll gcd(ll a,ll b) {if (a==0) return b;return gcd(b%a,a);}
int main()
 {
    YUGEN;
       ll n,m;
       cin>>n>>m;
       ll a[n];
       for(int i=0;i<n;i++)
        cin>>a[i];
       ll b[m];
       for(int i=0;i<m;i++)
        cin>>b[i];
        ll gap=(n+m+1)/2;
     ll x=0,y=x+gap;
       while(1)
       {
           while(y<(n+m) )
           {
           if(x<n and y<n)
           {
               if(a[x]<a[y])
                {
                    x++;
                    y++;
                    continue;
                }
               else{
                swap(a[x],a[y]);
                   x++;
                   y++;
               }
           }
           else if(x<n and y>=n)
           {
               if(a[x]<=b[y-n])
               {
                   x++;
                   y++;
                   continue;
               }
               else{
                swap(a[x],b[y-n]);
                   x++;
                   y++;
               }
           }
           else if(x>=n and y>=n)
           {
               if(b[x-n]<=b[y-n])
               {
                   x++;
                   y++;
                   continue;
               }
               else{
                swap(b[x-n],b[y-n]);
                   x++;
                   y++;
               }
           }
           }
           if(gap==1)
               break;
           gap=(gap+1)/2;
           x=0;
           y=x+gap;

       }
       for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
       cout<<endl;
       for(int i=0;i<m;i++)
        cout<<b[i]<<" ";
       cout<<endl;
       return 0;

 }
