//https://practice.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1?page=1&category[]=Tree&sortBy=submissions

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

//Function to return a list containing the level order traversal in spiral form.
void tag_level(Node *node, int level, map<Node*, int> &node_level){
    node_level[node] = level;
    if(node->left){tag_level(node->left, level+1, node_level);}
    if(node->right){tag_level(node->right, level+1, node_level);}
}

vector<int> findSpiral(Node *root)
{
    vector<int>result;
    if(!root){return result;}
    
    map<Node*,int> node_level;
    map<int,vector<int>> mymap;
    queue <Node*> myqueue;
    Node* node;
   
    tag_level(root, 0, node_level);
    myqueue.push(root);

    while(!myqueue.empty()){
        node = myqueue.front();
        mymap[node_level[node]].push_back(node->data);
        myqueue.pop();
        if(node->left){myqueue.push(node->left);}
        if(node->right){myqueue.push(node->right);}
        
    }
    for(map<int,vector<int>>::iterator it = mymap.begin(); it!= mymap.end(); ++it){
        if(it->first % 2){
            for(vector<int>::iterator u = it->second.begin(); u!= it->second.end(); ++u){
                result.push_back(*u);
            }
        }else{
             for(vector<int>::reverse_iterator u = it->second.rbegin(); u!= it->second.rend(); ++u){
                result.push_back(*u);
            }
        }
    }
    
    return result;
}
