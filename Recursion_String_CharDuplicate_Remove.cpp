class Solution{
public:

    string remove(string s, int n){

       int len = s.length(), i = 1;
       bool changed = 0;
       
       if(len <=1 ){return s;}
       
       while( i < len){
      
           if(s[i] == s[i-1]){
               
               if(!changed){changed = 1;}
               
               if(i < len-1 && s[i] == s[i+1]){
                   s.erase(i, 1);
                   len-- ;
               }else{
                   s.erase(i-1, 2);
                   len-=2;
               }
           }
           else{ i++; }
       }
       
       if(changed){ return remove(s,1); }
      
       return s;
    }
    
    
    string rremove(string s){
        return remove(s, 1);
    }
};
