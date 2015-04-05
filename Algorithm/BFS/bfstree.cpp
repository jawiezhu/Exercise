void BreadthFirstSearch(TreeNode* root){
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);
	TreeNode* node;
	while(!nodeQueue.empty()){
		node=nodeQueue.front();
		nodeQueue.pop();
		printf(format,node->data);
		if(node->lchild){
			nodeQueue.push(node->lchild);
		}
		if(node->rchild){
			nodeQueue.push(node->rchild);
		}
	}
}