//https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1?page=1&difficulty[]=1&difficulty[]=2&category[]=Tree&sortBy=submissions

class Solution {
  public:
    void map_insert(Node* node, int angle, int level, map<int,int> &mp, map<int,int> &node_level){
        if(!mp[angle]){
            mp[angle] = node->data; 
            node_level[angle] = level;
            
        }else{
            if(level >= node_level[angle]){
                mp[angle] = node->data;
                node_level[angle] = level;
            }
        }
        if(node -> left){map_insert(node->left, angle-1, level+1, mp, node_level);}
        if(node -> right){map_insert(node->right, angle+1, level+1, mp, node_level);}
    }
  
    vector <int> bottomView(Node *root) {
        
        map<int,int> mymap;
        map<int,int> node_level;
        vector<int> result;
        map_insert(root, 0, 0, mymap, node_level);
        
        for(map <int,int>:: iterator it = mymap.begin(); it!= mymap.end(); ++it){
            result.push_back(it->second);
        }
        return result;
    }
};
