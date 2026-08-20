class Solution {
    void nge(vector<int>& height,vector<int>&nge){
        int n=height.size();
       int maxi=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(maxi==INT_MIN){
                nge[i]=0;
                maxi=max(maxi,height[i]);
            }
            else{
                nge[i]=maxi;
                maxi=max(maxi,height[i]);
            }
        }
            
    }
    void pge(vector<int>& height,vector<int>&pge){
         int n=height.size();
       int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            if(maxi==INT_MIN){
                pge[i]=0;
                maxi=max(maxi,height[i]);
            }
            else{
                pge[i]=maxi;
                maxi=max(maxi,height[i]);
            }
        }
    }
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>nnge(n);
        vector<int>ppge(n);
        nge(height,nnge);
        pge(height,ppge);
        int ans=0;

        for(int i=0;i<height.size();i++){
            if(height[i]<nnge[i] && height[i]<ppge[i]){
                ans+=(min(nnge[i],ppge[i])-height[i]);
            }
        }
        return ans;

        
    }
};