#include <bits/stdc++.h> 
int R,C;
void solve(int r,int c,vector<vector<int>> &mat,string &path,vector<string> &ans
,vector<vector<bool>> &vis){
    if(r<0 || r>= R || c<0 || c>=C || mat[r][c]==0 || vis[r][c]){
        return;
    }
        if(r==R-1 && c==C-1){
            ans.push_back(path);
            return;
        }
        // cout<<path<<" ";
        vis[r][c]=true;
        path+='D';
        solve(r+1,c,mat,path,ans,vis);
        path.pop_back();

        path+='R';
        solve(r,c+1,mat,path,ans,vis);
        path.pop_back();

        path+='L';
        solve(r,c-1,mat,path,ans,vis);
        path.pop_back();

        path+='U';
        solve(r-1,c,mat,path,ans,vis);
        path.pop_back();
        vis[r][c]=false;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
         vector<string> ans;
         R=arr.size();
         C=arr[0].size();
         string temp;
         vector<vector<bool>> vis(R,vector<bool>(C,false));
         solve(0,0,arr,temp,ans,vis);
         return ans;
}