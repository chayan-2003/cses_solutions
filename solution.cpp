#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define lli long long int
#define ll long long
#define MOD 1000000007

long long maximumSubarraySum(vector<int>& nums, int k)
{
  int max1=INT_MIN;
  sort(nums.begin() ,nums.end());
  for(int i=0;i<nums.size();i++)
  {
    if(abs(nums[i+1]-nums[i])==1)
    {
      max1=max(max1,nums[i]+nums[i+1]);
    }
  }
  return max1;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++)
    {
      cin>>nums[i];
    }
    cout<<maximumSubarraySum(nums,k);
    return 0;
}
