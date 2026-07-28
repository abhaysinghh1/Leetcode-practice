class Solution {
public:
    vector<string> symbols = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                              "XL", "X",  "IX", "V",  "IV", "I"};

    vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string intToRoman(int num) {
        string ans="";
        for(int i=0;i<13;i++){
            if(num==0) break;
            int times=num/values[i];
            for(int j=0;j<times;j++){
                ans+=symbols[i];

            }
            num=num%values[i];
        }
        return ans;
    }
};