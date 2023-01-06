//https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1?page=1&difficulty[]=1&difficulty[]=2&category[]=Tree&curated[]=1&sortBy=submissions

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    int tag_angle(Node * node, int angle, map<Node*, int> &node_angle){
        node_angle[node] = angle;
        
        if(node->left){tag_angle(node->left, angle-1, node_angle);}
        if(node->right){tag_angle(node->right, angle+1, node_angle);}
    }
    
    void bfs(Node *root, map<int,vector<int>> &mymap, map<Node*,int> &node_angle){
        int angle;
        queue<Node*> myqueue;
        myqueue.push(root);
        while(!myqueue.empty()){
            Node* node = myqueue.front();
            myqueue.pop();
            angle = node_angle[node];
            mymap[angle].push_back(node->data);
            
            if(node->left){myqueue.push(node->left);}
            if(node->right){myqueue.push(node->right);}
        }
    }
    
    vector<int> verticalOrder(Node *root)
    {
        vector<int>result;
        map<Node*, int> node_angle;
        map<int, vector<int>> mymap;
        
        tag_angle(root, 0, node_angle);

        bfs(root, mymap, node_angle);
        
        for(map<int,vector<int>>::iterator it = mymap.begin(); it!= mymap.end(); ++it){
            for(vector<int>::iterator u = it->second.begin(); u != it->second.end(); ++u){
                result.push_back(*u);
            }
        }
        return result;
    }
};