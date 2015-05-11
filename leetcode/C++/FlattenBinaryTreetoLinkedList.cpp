// Given a binary tree, flatten it to a linked list in-place.

// For example,
// Given

//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
// The flattened tree should look like:
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6


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
    queue<TreeNode*> Q;

    void preorder(TreeNode *root)
    {
        if(root)
        {
          Q.push(root);
          preorder(root->left);
          preorder(root->right);
        }
          
    }

    void flat(TreeNode * root)
    {

        if(!Q.empty())
        {
          root->right=Q.front();
          root->left=NULL;
          Q.pop();
          flat(root->right);
        }

        
    }

    void flatten(TreeNode* root) {
       if(root==NULL) return ;
        preorder(root);
        root=Q.front();
        Q.pop();
        root->left=NULL;
        flat(root);

    }
};



//前序遍历，在加上个队尾指针。
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* Tail;
    void preOrder(TreeNode* root)
    {
        if(root != NULL)
        {
            TreeNode* left = root->left;
            TreeNode* right = root->right;
            if(Tail == NULL){
                Tail = root;
            }
            else{
                if(Tail->right != root)
                    Tail->right = root;
                Tail->left = NULL;
                Tail = root;
            }
            preOrder(left);
            preOrder(right);
        }
    }
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        Tail = NULL;
        preOrder(root);
    }
};


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
    public void flatten(TreeNode root) {
        if (root == null) return;
        Stack<TreeNode> stack = new Stack<TreeNode>();
        stack.push(root);
        TreeNode lastNode = null;
        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            if (lastNode != null) {
                lastNode.left = null;
                lastNode.right = node;
            }
            lastNode = node;
            TreeNode left = node.left;
            TreeNode right = node.right;
            if (right != null) {
                stack.push(right);
            }
            if (left != null) {
                stack.push(left);
            }
        }
    }
};

// LeetCode, Flatten Binary Tree to Linked List
// 递归版1，时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) return;  // 终止条件

        flatten(root->left);
        flatten(root->right);

        if (nullptr == root->left) return;

        // 三方合并，将左子树所形成的链表插入到root和root->right之间
        TreeNode *p = root->left;
        while(p->right) p = p->right; //寻找左链表最后一个节点
        p->right = root->right;
        root->right = root->left;
        root->left = nullptr;
    }
};


// LeetCode, Flatten Binary Tree to Linked List
// 递归版2
// @author 王顺达(http://weibo.com/u/1234984145)
// 时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    void flatten(TreeNode *root) {
        flatten(root, NULL);
    }
private:
    // 把root所代表树变成链表后，tail跟在该链表后面
    TreeNode *flatten(TreeNode *root, TreeNode *tail) {
        if (NULL == root) return tail;

        root->right = flatten(root->left, flatten(root->right, tail));
        root->left = NULL;
        return root;
    }
};


// LeetCode, Flatten Binary Tree to Linked List
// 迭代版，时间复杂度O(n)，空间复杂度O(logn)
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;

        stack<TreeNode*> s;
        s.push(root);

        while (!s.empty()) {
            auto p = s.top();
            s.pop();

            if (p->right)
                s.push(p->right);
            if (p->left)
                s.push(p->left);

            p->left = nullptr;
            if (!s.empty())
                p->right = s.top();
        }
    }
};








