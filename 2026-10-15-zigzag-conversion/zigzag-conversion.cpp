class Solution {
public:
    string convert(string s, int numRows) {
  if(numRows==1 || s.size()<numRows) return s;
  vector<string>rows(numRows);
  int curr=0;
  int flag=false;
  for(auto c:s){
    rows[curr]+=c;
    if(curr==0|| curr==numRows-1){
        flag=!flag;
    }
    curr+= flag?1:-1;
  }        
  string ans="";
  for(auto it:rows){
    ans+=it;
  }
  return ans;

    }
};