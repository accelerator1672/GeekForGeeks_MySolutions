//https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
class Solution{
    public:

    int partition(int arr[], int l, int r) {
        int v = arr[r], i = (l - 1);
        
        for (int j = l; j <= r - 1; j++){

            if (arr[j] <= v) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[r]);
        
        return (i + 1);
    }
    
    
    void select(int arr[], int l, int r, int k){
        while(r>l){
            int i = partition(arr, l, r);
            if(i>=k) r = i-1;
            if(i<=k) l= i+1;
        }
    }
    
    int kthSmallest(int arr[], int l, int r, int k) {
        select(arr, 0, r, k-1);
        return arr[k-1];
    }
};
