#include <bits/stdc++.h> 
string urlShortener(long long n) {
       if(n==0)return "0";
       string ans;
       string base62="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
       while(n){
           ans+=(base62[n%62]);
           n/=62;
       }
       reverse(ans.begin(),ans.end());
       return ans;

}