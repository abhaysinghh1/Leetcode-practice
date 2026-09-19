class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        int len=0;
        unordered_map<string ,int>mpp;
        for(auto it:words){
            string r_word=it;
            swap(it[0],it[1]);
            if(mpp[it]>0){
len+=4;
mpp[it]--;
            }
            else{
                mpp[r_word]++;
            }
        }

        for(auto it:mpp){
             string word=it.first;
             int times=it.second;
             if(word[0]==word[1]&& times>0){
                len+=2;
                break;
             }
        }
        return len;
        
    }
};