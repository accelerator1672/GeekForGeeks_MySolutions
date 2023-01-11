//https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1
class Solution
{
	public:
	    
	    void permutation(string S, int l, int r, vector<string> &result){
	        if(l == r ){result.push_back(S); return;}

            char c; string T;
            
	        for (int i = l; i<=r; i++){
	            
	            if(i > l && S[i] == S[i-1]){continue;}
	            
	            T=S; c = S[i];
	            T.erase(T.begin()+i);
	            T.insert(T.begin()+l,c);
	            
                permutation(T, l+1, r, result);
                
	        }
	    }
		vector<string>find_permutation(string S)
		{   
		    sort(S.begin(), S.end());
            vector <string> result;

		    permutation(S, 0, S.length()-1, result);
		    return result;
		}
};
