//https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        stack<int> st;
        vector<long long> result(n, -1);
        int index;
        
        st.push(0);
        
        for(int i = 1; i < n; i ++){
            
            while(!st.empty() && arr[i] > arr[index = st.top()]){
                
                result[index] = arr[i];
                st.pop();
                
            }
            
            st.push(i);
        }
        
        return result;
    }
};
