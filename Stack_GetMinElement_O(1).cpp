//https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
            if(s.empty()){return -1; }
            else{ return minEle; }
       }
       
       /*returns poped element from stack*/
  
       int pop(){
           if(s.empty()){ return -1; }
           else{
              int topE = s.top();
              s.pop();
              if(topE < minEle){
                  int ret_val = minEle;
                  minEle = 2*minEle-topE;
                  return ret_val;
              }
              else{ return topE; }
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(s.empty()){
               minEle = x;
               s.push(x);
           }else if(x < minEle){ 
               s.push(2*x - minEle);
               minEle = x;
           }else{
               s.push(x);
           }
  
       }
};
