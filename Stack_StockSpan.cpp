//https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1?page=1&difficulty[]=1&difficulty[]=2&category[]=Stack&sortBy=submissions

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> result;
       stack<int> st;
       int index; 
       
       for(int i =0; i < n; i++){ result.push_back(i+1); }
    
       st.push(n-1);
       
       for(int i = n-2; i>=0; i--){
         
          while(!st.empty() && price[i] > price[index = st.top()]){
                result[index] = (index - i);
                st.pop();
            }
            st.push(i);
       }
      
       return result;
    }
};
