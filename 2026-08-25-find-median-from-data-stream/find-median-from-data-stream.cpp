class MedianFinder {
    priority_queue<int>p;
           priority_queue<int,vector<int>, greater<int>>r;
public:
    MedianFinder() {

        
    }
    
    void addNum(int num) {
    if(p.empty()||p.top()>num){
                   p.push(num);
               }
               else{
                   r.push(num);
               }
               
               if(p.size()>r.size()+1){
                   auto temp=p.top();
                   p.pop();
                   r.push(temp);
               }
               else if(r.size()>p.size()){
                   auto temp=r.top();
                   r.pop();
                   p.push(temp);
               }
               
        
    }
    
    double findMedian() {
        if(p.size()!=r.size()){
                return (p.top());
               }
               else{
                   return ((double)(p.top()+r.top())/2);
               }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */