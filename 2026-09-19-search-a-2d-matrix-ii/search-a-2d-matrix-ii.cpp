class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m=mat[0].size();
        int n=mat.size();
         int i=0;
         int j=m-1;
         while(i<n && j>=0){
            if(mat[i][j]<target){
                i++;

            }
            else if(mat[i][j]>target){
                j--;

            }
            else{
                return true;
            }
         }
         return false;
    }
};