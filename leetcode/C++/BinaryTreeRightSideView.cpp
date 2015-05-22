// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// For example:
// Given the following binary tree,
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
// You should return [1, 3, 4].

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //层序遍历
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(root==NULL) return ret;

        queue<TreeNode*> Q;
        Q.push(root);
        TreeNode * node;
        while(!Q.empty()){
        	int qlen=Q.size();
        	for(int i=0;i<qlen;i++){
        		node=Q.front();
        		Q.pop();

        		if(node->left) Q.push(node->left);
        		if(node->right) Q.push(node->right);

        	}
        	ret.push_back(node->val);
        }

        return ret;
    }
};


//======
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<int> rightvalue;
    int level = 0;
    
    vector<int> rightSideView(TreeNode* root) {
        if(root)  
            down(root, 0);
        return rightvalue;
    }
    
    void down(TreeNode *node, int N)
    {
        if(N >= level)
        {
            rightvalue.push_back(node->val);
            level++;
        }
        N++;
        if(node->right) down(node->right, N);
        if(node->left)  down(node->left, N);
    }
};

//
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        
        vector<int> result;
        if(root == NULL) return result;
        int depth = treeDepth(root);
        vector<bool> sign;
        for(int i = 0; i < depth; i++){
            sign.push_back(false);   
        }
       
       
       int floor = 0;
       traverse(root,result,sign,floor);
       return result;
       
    }
    
    //计算树高
    int treeDepth(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int right,left;
        right = treeDepth(root->right);
        left = treeDepth(root->left);
        if(right>left){
            return right+1;
        }
        else{
            return left+1;
        }
    }
    
    void traverse(TreeNode *root,vector<int> &result,vector<bool> &sign,int floor){
        if(root == NULL) return;
        
        if(sign[floor] == false){
            result.push_back(root->val);
            sign[floor] = true;
        }
        
        traverse(root->right,result,sign,floor+1);
        traverse(root->left,result,sign,floor+1);
        
    }
};

//
/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<Integer>();
        if(root == null) {
            return result;
        }
        Queue<TreeNode> queue = new LinkedList<TreeNode>();
        queue.offer(root);
        
        while(queue.size() > 0) {
            int size = queue.size();
            while(size > 0) {
                TreeNode current = queue.poll();
                if(current.left != null) {
                    queue.offer(current.left);
                }
                if(current.right != null) {
                    queue.offer(current.right);
                }
                if(size == 1) {
                    result.add(current.val);
                }
                size--;
            }
        }
        return result;
    }
}//


//
// 每一层最右边的那个数据，因此只需要按照层次遍历一遍这个二叉树，获取每一层的最右边的数据即可。
// 二叉树层次遍历需要的数据结构是queue，现在是怎样判断每一层遍历结束，
// 为了解决这个问题，可以再queue中插入一个标记NULL，读取到NULL，那说明NULL之前的那个数据就是该层最右边的数据。代码如下：
class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        queue<TreeNode *> myQue;
        vector<int> res;        
        res.clear();

        if (NULL == root)
        {
            return res;
        }
        
        myQue.push(root);
        myQue.push(NULL);
        TreeNode *temp1,*temp2;

        while (true)
        {
            temp1 = myQue.front();
            myQue.pop();
            temp2 = myQue.front();
            //myQue.pop();
            if(NULL == temp1 && NULL == temp2)
                break;
            if(NULL == temp1)
            {
                myQue.push(NULL);//为下一层添加标记
                continue;

            }
            if (NULL == temp2)//提取下一个指针，判断是否是标记NULL
            {
                res.push_back(temp1->val);//保存最右边的值
            }            
            
            if(NULL != temp1->left)
                myQue.push(temp1->left);
            if (NULL != temp1->right)
            {
                myQue.push(temp1->right);
            }
        }
        return res;        
    }
};
