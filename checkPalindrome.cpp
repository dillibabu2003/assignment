#include <bits/stdc++.h> 
bool isPalindrome(const string & nstr){
    int left=0,right=nstr.size()-1;
    while(left<=right){
        if(nstr[left++]!=nstr[right--])return false;
    }
    return true;
}
bool checkPalindrome(string s)
{
    string nstr;
    for(char ch:s){
        if(isalpha(ch) || (ch>='0' && ch<='9'))nstr+=tolower(ch);
    }
    // cout<<nstr<<endl;
    return isPalindrome(nstr);
}