//https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long sum = arr[0], max_sum = arr[0];
        
        for(int i = 1; i < n; i ++){
            
            if(sum + arr[i]< arr[i]){sum = arr[i];}
            else{ sum += arr[i];}
            
            if(sum > max_sum){max_sum = sum;}
        }
        return max_sum;
        
    }
};
