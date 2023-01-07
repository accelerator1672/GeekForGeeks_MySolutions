//https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1?page=1&difficulty[]=1&difficulty[]=2&category[]=Tree&curated[]=1&sortBy=submissions

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    int tag_angle(Node *node, int angle, int *ptr1, int *ptr2, unordered_map <Node*,int> &node_angle){
        node_angle[node] = angle;
        
        if(angle < *ptr1){*ptr1 = angle;}
        else if(angle > *ptr2){*ptr2 = angle;}
        
        if(node->left){tag_angle(node->left, angle-1, ptr1, ptr2, node_angle);}
        if(node->right){tag_angle(node->right, angle+1, ptr1, ptr2, node_angle);}
    }
    
    void bfs(Node *root, int offset, vector<vector<int>> &vec, unordered_map<Node*,int> &node_angle){
        
        int angle;
        queue<Node*> myqueue;
        myqueue.push(root);
        
        while(!myqueue.empty()){
            
            Node* node = myqueue.front();
            myqueue.pop();
            angle = node_angle[node];
            vec[angle+offset].push_back(node->data);
            
            if(node->left){myqueue.push(node->left);}
            if(node->right){myqueue.push(node->right);}
        }
    }
    
    vector<int> verticalOrder(Node *root)
    {
      
        vector<int>result;
        unordered_map<Node*, int> node_angle;
        int min = 0, max = 0;
        
        tag_angle(root, 0, &min, &max, node_angle);
        int size = max-min+1;
        int offset = - min;
        
        vector<vector<int>> vec(size);
        
        bfs(root, offset, vec, node_angle);
        
        for(auto row : vec){
            for(auto col: row){
                result.push_back(col);
            }
        }
        return result;
        
    }
};
