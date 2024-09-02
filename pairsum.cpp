#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>> ans;
    map<int,int> mp;
    for(int val:arr){
         if(mp.find(s-val)!=mp.end()){
            int mi=min(val,s-val);
            int ma=max(val,s-val);
            int cnt=mp[s-val];
            while(cnt--)ans.push_back({mi,ma});
         }
         mp[val]++;
    }
    sort(ans.begin(),ans.end());
    return ans;
}