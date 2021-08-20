//给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组
//创建类
typedef struct  
{
	int *array;  //存放变换后数组
	int *origin;  //存放原始数组
	int numsSize;  //数组大小
}Solution;

//交换元素位置
void swap(int *a,int *b)  
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// 函数功能为：获取一个随机数
int randNum(int min,int max)  
{
	int randNumber = rand() % (max - min + 1) + min;
	return randNumber;
}

//nums为输入数组，创建新的数组存放数据,size为输入数组大小
Solution *solutionCreat(int *nums,int size)  
{
	Solution *newNum = malloc(sizeof(Solution));
	newNum->array = malloc(sizeof(int) * size);  //用来存放打乱或重置后的数组
	newNum->origin = malloc(sizeof(int) * size);  //用来存放原始数组
	newNum->numsSize = size;
	for(int i = 0;i < size;i++)  //将输入数组放入,循环数组大小的次数
	{
		newNum->array[i] = nums[i];
		newNum->origin[i] = nums[i];
	}
	return newNum;
}

//重置为初始数组，*retSize是数组大小
int *solutionReset(Solution *obj,int *retSize) 
{
	*retSize = obj->numsSize;
	for(int i = 0;i < *retSize;i++)  //将原始数组复制出来，循环数组大小的次数
	{
		obj->array[i] = obj->origin[i];
	}
	return obj->array;
}

// 将数组随机打乱，*shuffleSize是数组大小
int *solutionShuffle(int *obj,int *shuffleSize)  
{
	*shuffleSize = obj->numsSize;
	for(int i = 0;i < *shuffleSize;i++)  //通过获取随机数来与每个位置上的数交换位置达到随机打乱的效果，循环数组大小的次数
	{
		swap(&(obj->array[i]),&(obj->array[randNum(i,*shuffleSize - 1)]));
	}
	return obj->array;
}

//释放空间
void solutionFree(int *obj)  
{
	free(obj->array);
	free(obj->origin);
	free(obj);
}