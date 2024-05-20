#include <bits/stdc++.h>
#define lli long long int
#define ll long long
#define MOD 1000000007
using namespace std;
int sex(vector<vector<int>> grid)
{
    int n = grid.size();
    vector<vector<bool>> yele(n, vector<bool>(n, false));
    // calculating the centre
    map<int, int> ymap, rest;
    int crow = n / 2;
    bool mark = true;
    for (int i = 0; i <= crow; i++)//00 11 22 
    {

        yele[i][i] = true;
        ymap[grid[i][i]]++;
    }
    int i = crow - 1;//13 
    int j = crow + 1;
    while (j <= n - 1)
    {
        yele[i][j] = true;
        ymap[grid[i][j]]++;
        i = i - 1;
        j = j + 1;
    }
    for (int i = crow + 1; i < n; i++)
    {
        yele[i][crow] = true;
        ymap[grid[i][crow]]++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (yele[i][j] == false)
            {
                rest[grid[i][j]]++;
            }
        }
    }
    int numy=0,nony=0,ans=INT_MAX;
  for(auto it:ymap)
  {
        numy+=it.second;
  }
  for(auto it:rest)
  {
        nony+=it.second;
  }
  for(int a=0;a<3;a++)
  {
    for(int b=0;b<3;b++)
    {
        if(a!=b)
        {
            ans=min(ans,numy-ymap[a]+nony-rest[b]);
        }
    }
  }
  return ans;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> grid = {{0,0,0,1,0},{0,0,0,0,0},{2,0,0,2,0},{0,1,0,2,1},{0,0,0,2,1}};
    cout<<sex(grid);
    return 0;
}
