//广度遍历，给你一个二叉树，请你返回其按层序遍历得到的节点值。（逐层地，从左到右访问所有节点）
//
int** levelorder(struct TreeNode* root,int* returnSize,int** returnColumnSize)
{
	int MAX = 10000;
	if(root == NULL)
	{
		*returnSize = 0;
		return ;
	}
	int** sort = (int**)malloc(sizeof(int*) * MAX);  //二叉树节点存放的二维数组
	struct TreeNode* queue[MAX];  //创建一个队列 
	int front = -1;  //前指针
	int rear = -1;  //后指针
	(*returnColumnSize) = (struct TreeNode*)malloc(sizeof(int) * MAX);
	int level = 0;  //二叉树层数
	int levelNum = 0;  //每层节点个数
	queue[++rear] = root;  //根节点入队
	while(front != rear)  //队列不为空时继续
	{
		levelNum = (rear - front % MAX);
		(*returnColumnSize)[level] = levelNum;  //记录每层节点数
		sort[level] = (struct TreeNode*)malloc(sizeof(int) * levelNum);  //按每层节点个数创建相应列
		for(int i = 0;i < levelNum;i++)  //将每层节点出队
		{
			struct TreeNode* p = queue[++front];  //指向队列里一层的每个节点
			sort[level][i] = p->val;  //将节点数值记录到二维数组中
			if(p->left != NULL)  //此节点若有左子树，则将左子树入队
			{
				queue[++rear] = p->left;
			}
			if(p->right != NULL)  //此节点若有右子树，则将右子树入队
			{
				queue[++rear] = p->right;
			}
		}
		level += 1;  //下一层
	}
	*returnSize = level;  //记录最终层数
	return sort;
}