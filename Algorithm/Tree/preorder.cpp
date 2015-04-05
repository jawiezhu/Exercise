#include <iostream>
using namespace std;

struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	char elem;
};

TreeNode* PreOrderFromOrderings(char * inorder,char * postorder,int length) //Get preorder,know POST and IN first.
{
	if(length==0)
	{
		return NULL;
	}

	TreeNode* node=new TreeNode;
	node->elem=postorder[length-1];
	int rootIndex=0;

	for(;rootIndex<length;rootIndex++)	// the length of left tree
	{
		if(inorder[rootIndex]==postorder[length-1])
			break;
	}

	cout<<node->elem<<" "; //preorder, cout the root firstly.
	node->left=PreOrderFromOrderings(inorder,postorder,rootIndex);
	node->right=PreOrderFromOrderings(inorder+rootIndex+1,postorder+rootIndex,length-(rootIndex+1));
	
	return node;
}



int main()
{
	char* post="DEBFGCA";
	char* in="DBEAFCG";
	PreOrderFromOrderings(in,pre,7);
	cout<<endl;
	return 0;
}