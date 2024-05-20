#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
     ll n, m;
    cin >> n >> m;
    vector<ll>tickets(n);
    multiset<int>st;
    for (int i = 0; i < n; i++)
    {
        cin >> tickets[i];
        st.insert(tickets[i]);
    }
    debug(st);
    vector<ll>customers(m);
    for (int i = 0; i < m; i++)
    {
        cin >> customers[i];
    }
    for(int i=0;i<customers.size();i++)
    {
        auto it=st.upper_bound(customers[i]);
       if(it==st.begin())
       {
        cout<<-1<<endl;
       }
       else 
       {
        cout<<*(--it)<<endl;
        st.erase(it);
       }
    }
   
 
    return 0;
}
