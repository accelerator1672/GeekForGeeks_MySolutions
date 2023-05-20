//https://www.hackerrank.com/challenges/climbing-the-leaderboard/

int search(vector<int> &ranked, int num, int left, int right){
    if(right-left <=1) return right;
    
    int mid = right - (right-left)/2;
    
    if(num == ranked[mid]){return mid;}
    else if(num < ranked[mid]){left = mid;}
    else {right = mid;}
    
    return search(ranked, num, left, right);
    
}
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    unordered_map<int, int> mp;
    int rank = 0, sz = ranked.size();
    for(auto x : ranked){
        if(mp[x]){continue;}
        mp[x] = ++rank;
    }
    vector<int> result;
    for(auto x : player){
        
        if(x <ranked[sz-1]){result.push_back(mp[ranked[sz-1]]+1);}
        else if(x>=ranked[0]){result.push_back(1);}
        else{
            int score = ranked[search(ranked, x, 0, sz-1)];
            if(score>x){result.push_back(mp[score]-1);}
            else{result.push_back(mp[score]);}
        }
        
    }
    return result;
}
