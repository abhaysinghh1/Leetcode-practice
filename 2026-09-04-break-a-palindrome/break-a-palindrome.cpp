class Solution {
public:
    string breakPalindrome(string str) {
        int n=str.size();
        if(n==1) return "";
        for(int i=0;i<n/2;i++){
            if(str[i]!='a'){
                str[i]='a';
                return str;
            }
        }
        str[n-1]='b';
        return str;
        
    }
};