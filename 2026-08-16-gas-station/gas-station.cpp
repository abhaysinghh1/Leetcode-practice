class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         int n=gas.size();
         int st=0;
         int tank=0;
         int total=0;// this tels us that   is there the suffiecient total gas for the required total cost if at the end of loop this is less than 0 then it mena s that there is no suffiecient gas 

         for(int i=0;i<n;i++){
            int diff=gas[i]-cost[i];
            
            tank+=diff;
            total+=diff;
            if(tank<0){
                st=i+1;
                tank=0;
            }
         }
         if(total>=0) return st;
         return -1;

       
    }
};