struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    void map_insert(Node * node, int angle, int level, map<int,int> &mp, map<int,int> &node_level){
      
        if(node == NULL){return;}
        
        if(!mp[angle]){mp[angle] = node->data; node_level[angle] = level;}
        else{
            if(level < node_level[angle]){
                mp[angle] = node->data;
                node_level[angle] = level;
            }
        }
        
        if(node->left){map_insert(node->left, angle - 1, level+1, mp, node_level);}
        if(node->right){map_insert(node->right, angle + 1, level+1, mp, node_level);}
        
    }
    vector<int> topView(Node *root)
    {
        map <int,int> mymap;
        map <int,int> node_level;
        vector<int> result;
        
        map_insert(root, 0, 0, mymap, node_level);
        for (std::map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it){
           result.push_back(it->second);
        }   
        return result;
        
    }

};
