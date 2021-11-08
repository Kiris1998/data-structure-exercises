//给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组
//nums为输入数组，numsSize为数组大小
int shuffleAnArray(int *nums,int numsSize)
{
	int d = randNum(0,numsSize - 2);  //取随机数
	shuffle(nums,d,numsSize - 1);
	return nums;
}

//随机数函数，取得一个随机数
int randNum(int min,int max)
{
	return rand() % (max - min + 1) + min;
}

//交换元素
void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = *a;
}

//将最右侧元素与它之前任一元素交换，然后换倒数第二个交换，以此类推，left为随机的指针，right为要交换的右指针
void shuffle(int *nums,int left,int right)
{
	if(right > 0)  //一直交换到正数第二个数停止
	{
		swap(&nums[left],&nums[right]);
		right -= 1;
		int d = randNum(0,right - 1)
		shuffle(nums,d,right);
	}
	else
	{
		return ;
	}
}