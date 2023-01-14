//https://practice.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1

class Solution{
    public:
  
    long long toh(int N, int from, int to, int aux) {
       int cnt = 1;
       if(N==1){
            cout << "move disk 1 from rod "<<from << " to rod "<<to<<endl;
            return 1;
       }
       cnt += toh(N-1, from, aux, to);
       cout << "move disk "<< N << " from rod "<<from << " to rod "<<to<<endl;
       cnt += toh(N-1, aux, to, from);
       return cnt;
       
    }

};
