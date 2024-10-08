#include <bits/stdc++.h> 
vector<int> spiralPathMatrix(vector<vector<int>> matrix, int R, int C) 
{
         int left=0,right=C-1,top=0,bottom=R-1;
         int dir=0;
         vector<int> ans;
         while(left<=right && top<=bottom){
               if(dir==0){
                   for(int i=left;i<=right;i++){
                       ans.push_back(matrix[top][i]);
                   }
                   top++;
               }
               else if(dir==1){
                    for(int i=top;i<=bottom;i++){
                        ans.push_back(matrix[i][right]);
                    }
                    right--;
               }
               else if(dir==2){
                    for(int i=right;i>=left;i--){
                        ans.push_back(matrix[bottom][i]);
                    }
                    bottom--;
               }
               else if(dir==3){
                     for(int i=bottom;i>=top;i--){
                         ans.push_back(matrix[i][left]);
                     }
                     left++;
               }
               dir=(dir+1)%4;
         }
         return ans;
    
}