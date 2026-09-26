class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>str;
        for(auto it:nums){
            str.push_back(to_string(it));

        }
        sort(str.begin(),str.end(),[](auto a ,auto b){
            return a+b>b+a;
        });

        if(str[0]=="0") return "0";

        string ans="";
        for(auto it:str){
            ans+=it;
        }
        return ans;
        
    }
};