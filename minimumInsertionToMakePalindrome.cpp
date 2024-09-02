int findLCS(int idx1,int idx2,const string &s1,const string &s2,vector<vector<int>> &dp){
	  if(idx1==s1.size()||idx2==s2.size())return 0;
	  if(dp[idx1][idx2]!=-1){
		  return dp[idx1][idx2];
	  }
	  if(s1[idx1]==s2[idx2]){
		  return dp[idx1][idx2]=1+findLCS(idx1+1,idx2+1,s1,s2,dp);
	  }
	  return dp[idx1][idx2]=max(findLCS(idx1+1,idx2,s1,s2,dp),findLCS(idx1,idx2+1,s1,s2,dp));
}
int minimumInsertions(string &s1)
{
	string s2=s1;
	reverse(s2.begin(),s2.end());
	int l1=s1.size();
	int l2=s2.size();
	vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));
	int lcs=findLCS(0,0,s1,s2,dp);
	// cout<<s1<<" "<<s2<<" "<<lcs<<" "<<endl;
	return l1-lcs;
}
