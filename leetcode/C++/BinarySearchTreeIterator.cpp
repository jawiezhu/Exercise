// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

// Calling next() will return the next smallest number in the BST.

// Note: next() and hasNext() should 
// run in average O(1) time and uses O(h) memory, where h is the height of the tree.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 中序遍历的思路。
// 用栈来保存从根到最左侧叶子节点的路径，栈最上面的结点是最小的结点，
// 每次取next,都是取栈最上面的结点，然后把剩余结点到最左侧叶子节点的路径放入栈中。
 //找最小值，可以参考中序遍历，借助栈！每弹出一个元素，才增加栈中元素，不用马上遍历整颗树!
class BSTIterator {
	stack<TreeNode *>s;
public:
    BSTIterator(TreeNode *root) {
        while(!s.empty())
        	s.pop();
        while(root) // 初始化时，栈里保存从根节点到最左边叶子的节点，栈顶是整颗树的最小值
        {
        	s.push(root);
        	root=root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmp=s.top();
        s.pop();
        int ret=tmp->val;
        tmp=tmp->right;
        while(tmp) // 开始保存当前弹出栈的节点的右子树，还是先压入右儿子的所有左儿子！
        {
        	s.push(tmp);
        	tmp=tmp->left;
        }

        return ret;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */



class BSTIterator {
public:
    BSTIterator(TreeNode *root){	
		while(root)
		{
			inorder.push(root);
			root = root->left;
		}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		return inorder.empty() ? false :  true;
    }

    /** @return the next smallest number */
    int next() {
		TreeNode *cur = inorder.top();
		inorder.pop();
		if(cur->right)
		{			
			TreeNode *temp = cur->right;
			while(temp)
			{
				inorder.push(temp);
				temp = temp->left;
			}
		}
		return cur->val;
	}
private:
	stack<TreeNode *> inorder;
};


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode *> s;
    BSTIterator(TreeNode *root) {
        pushLeft(root);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *top = s.top();
        s.pop();
        pushLeft(top -> right);
        return top -> val;
    }
    void pushLeft(TreeNode *root){
        if(root){
            s.push(root);
            TreeNode *cur = root;
            while(cur -> left){
                s.push(cur -> left);
                cur = cur -> left;
            }
        }
    }
};




/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */



