/*************************************************************

    Following is the Binary Tree node structure for reference:

    class BinaryTreeNode{
	public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K) {
       queue<BinaryTreeNode<int>*> q;
       q.push(root);
       map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> par;
       while(!q.empty()){
           BinaryTreeNode<int>* curr=q.front();
           q.pop();
           if(curr->left){
               q.push(curr->left);
               par[curr->left]=curr;
           }
           if(curr->right){
               q.push(curr->right);
               par[curr->right]=curr;
           }
       }
       q.push(target);
       vector<BinaryTreeNode<int>*> ans;
       set<BinaryTreeNode<int>*> vis;
       vis.insert(target);
       while(!q.empty()){
           int len=q.size();
           if(K==0){
               while(!q.empty()){
                   ans.push_back(q.front());
                   q.pop();
               }
               break;
           }
           while(len--){
               BinaryTreeNode<int>* curr=q.front();
               q.pop();
               if(curr->left && vis.count(curr->left)==0){
                     vis.insert(curr->left);
                     q.push(curr->left);
               }
               if(curr->right && vis.count(curr->right)==0){
                    vis.insert(curr->right);
                    q.push(curr->right);
               }
               if(par.count(curr) && vis.count(par[curr])==0){
                   vis.insert(par[curr]);
                   q.push(par[curr]);
               }
           }
           K--;
           

       }
       return ans;
}