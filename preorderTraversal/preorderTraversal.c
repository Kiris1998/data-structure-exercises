//深度遍历，给定一个二叉树的根节点root，返回它的前序、中序、后续遍历
//前序遍历主程序，root为二叉树节点，ret存放着二叉树节点的数值，size表示随着ret数组存放节点数值个数的变化
void sortFun(struct TreeNode* root,int* ret,int* size)
{
	if(root == NULL)  //当节点为空时结束
	{
		return ;
	}
	ret[(*size)++] = root->val;  //将节点数值放入数组    
	sortFun(root->left,ret,size);  //转入节点的左儿子   （中序遍历则将上一行代码放入此行代码下面）
	sortFun(root->right,ret,size);  //转入节点的右儿子   （后序遍历则将上上行代码放入此行下面）
}

int* inorderTraversal(struct TreeNode* root,int* returnSize)  //root为二叉树根节点，returnSize为其大小
{
	int* sort = (int*)malloc(sizeof(int) * 200);  //创建数组存放二叉树节点数值
	*returnSize = 0;
	sortFun(root,sort,returnSize);
	return sort;
}