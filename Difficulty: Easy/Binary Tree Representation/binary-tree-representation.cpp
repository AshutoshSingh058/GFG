//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

void traverseInOrder(struct node *temp, vector<int> &inorder) {

  if (temp != NULL) {
    traverseInOrder(temp->left,inorder);
    // cout << " " << temp->data;
    inorder.push_back(temp->data);
    traverseInOrder(temp->right,inorder);
  }
  return;
}


// } Driver Code Ends

//User function Template for C++

/*struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}*/

class Solution{
public:

    void create_tree(node* root0, vector<int> &v){
        //Your code goes here
        deque<node*> que;
        que.push_back(root0);
        
        int i=0;
        while(!que.empty()) {
            node* cur = que.front();
            que.pop_front();
            
            if((2*i + 1) < 7) {
                cur->left = newNode(v[2*i + 1]);
                que.push_back(cur->left);
            }
            if((2*i + 2) < 7) {
                cur->right = newNode(v[2*i + 2]);
                que.push_back(cur->right);
            }
            i++;
        }
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input
        vector<int> vec(7);
        for(int i = 0;i<7;i++){
            cin >> vec[i];
        }
        struct node *root0 = newNode(vec[0]);
        root0->left = newNode(vec[1]);
        root0->right = newNode(vec[2]);
        root0->left->left = newNode(vec[3]);
        root0->left->right = newNode(vec[4]);
        root0->right->left = newNode(vec[5]);
        root0->right->right = newNode(vec[6]);

        Solution obj;
        struct node *root = newNode(vec[0]);
        obj.create_tree(root, vec);

        vector<int> a;
        traverseInOrder(root0,a);
        vector<int> b;
        traverseInOrder(root,b);
        if(a == b) cout << 1 << endl;
        else cout << -1 << endl;

       
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends