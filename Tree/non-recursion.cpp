
class Solution{
public:
	vector<int> preorderTraversal(TreeNode * root){
		vector<int> out;
		stack<TreeNode *> s;
		s.push(root);
		while(!s.empty()&&root){
			TreeNode *node=s.top();
			out.push_back(node->val);
			s.pop();
			if(node->right) s.push(node->right);
			if(node->left) s.push(node->left);
		}

		return out;
	}

	vector<int> inorderTraversal(TreeNode * root){
		stack<TreeNode *> s;
		vector<int> out;
		TreeNode *node=root;
		bool done=false;
		while(!done){
			if(node){
				s.push(node);
				node=node->left;
			}else{
				if(s.empty())
					done=true;
				else{
					node=s.top();
					s.pop();
					out.push_back(node->val);
					node=node->right;
				}
			}
		}

		return out;
	}

	vector<int> postorderTraversal(TreeNode * root){
		vector<int> out;
		stack<TreeNode*> s;
		TreeNode * node=root;
		s.push(node);
		while(!s.empty()&&node){
			node=s.top();
			out.push_back(node->val);
			s.pop();
			if(node->left) s.push(node->left);
			if(node->right) s.push(node->right);
		}

		reverse(out.begin(),out.end());
		return out;
	}

}