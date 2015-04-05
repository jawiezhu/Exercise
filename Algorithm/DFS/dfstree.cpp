void DepthFirstSearch(TreeNode* root){
	stack<TreeNode*> nodeStack;
	nodeStack.push(root);
	TreeNode* node;
	while(!nodeStack.empty()){
		node=nodeStack.top();
		printf(format,node->data);
		nodeStack.pop();
		if(node->rchild){
			nodeStack.push(node->rchild);
		}
		if(node->lchild){
			nodeStack.push(node->lchild);
		}
	}
}


//分析一下，在遍历了根结点后，就开始遍历左子树，最后才是右子树。

//因此可以借助堆栈的数据结构，由于堆栈是后进先出的顺序，由此可以先将右子树压栈，然后再对左子树压栈，

//这样一来，左子树结点就存在了栈顶上，因此某结点的左子树能在它的右子树遍历之前被遍历。