class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        vector<pair<char, int>> freq(mpp.begin(), mpp.end());
        sort(freq.begin(),freq.end(),[](auto a,auto b){
            return a.second>b.second ;
        });
        string ans="";
        for(auto it:freq){
            char ch=it.first;
            int num=it.second;
            while(num>0){
                ans+=ch;
                num--;
            }
        }

  return ans;
    }
};