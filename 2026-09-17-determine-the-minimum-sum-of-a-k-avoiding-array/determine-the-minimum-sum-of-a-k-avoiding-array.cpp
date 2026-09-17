class Solution {
public:
    int minimumSum(int n, int k) {
        int i=1;
        unordered_set<int>st;
        int sum=0;
        while(n>0){
            if( st.find( k-i)==st.end()){
                st.insert(i);
                sum+=i;
                n--;

            }
            i++;
        }
        return sum;
        
    }
};