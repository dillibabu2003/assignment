#include <bits/stdc++.h> 
int toInt(string &s){
     int val=1,ans=0;
     for(int i=s.size()-1;i>=0;i--){
         if(s[i]=='1'){
             ans+=(val);
         }
         val*=2;
     }
     return ans;
}

string toString(int val){
    string ans;
    while(val){
        ans+=to_string(val%2);
        val/=2;
    }
    if(ans.empty())ans+='0';
    reverse(ans.begin(),ans.end());
    return ans;
}
string findMissingNumber(vector<string> &binaryNums, int n) 
{
    int sum=0;
    for(string val:binaryNums){
        int curr=toInt(val);
        sum+=curr;
    }
    int ans=((n*(n+1))/2)-sum;
    // cout<<ans<<endl;
    return toString(ans);

}