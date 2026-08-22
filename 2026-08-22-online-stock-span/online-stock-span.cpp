class StockSpanner {
    stack<pair<int,int>>st; 
public:
    StockSpanner() {
       
    }
    
    int next(int price) {
       // stack<pair<int,int>>st; yaha par stack ko define nahi karnge kyunki har baar naya stack declre hoga na
        int span=1;
        while(!st.empty() && st.top().first<=price){
            span+=st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */