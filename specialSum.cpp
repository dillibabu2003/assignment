#include <bits/stdc++.h> 
int specialSum(vector<int> &arr, int n)
{
	vector<int> preSum(n,0);
	preSum[0]=arr[0];
	for(int i=1;i<n;i++){
		preSum[i]=preSum[i-1]+arr[i];
	}
	int ans=INT_MAX;
	for(int i=0;i<n;i++){
		// cout<<preSum[i]<<" "<<(preSum[n-1]-preSum[n-i-2])<<endl;
		int currSum=preSum[i]+(preSum[n-1]-preSum[n-i-2]);
		ans=min(ans,currSum);
	}
	return ans;
}