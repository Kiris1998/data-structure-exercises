//给你一个整数数组 nums，请你将该数组升序排列。
//nums为输入数组，numsSize为数组打小，*returnSize为返回数组的大小
int* sortArray(int* nums, int numsSize, int* returnSize)
{
	quickSort(nums,0,numsSize - 1)
	*returnSize = numsSize;
	return nums;
}

//交换元素
void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = *a;
}

//快速排列主函数,left为左指针，right为右指针
void quickSort(int *nums,int left,int right)
{
	if(left >= right)  //指针相遇或是左指针超过右指针，则返回
	{
		return ;
	}
	int low = left;  //划分后数组的左指针
	int high = right - 1;  //划分后数组的右指针
	int x = nums[right];  //中间元
	while(low < high)  //小于中间元的放数组最左侧，大于中间元的放数组右侧
	{
		while(low < high && nums[low] <= x)
		{
			low += 1;
		}
		while(low < high && nums[high] > = x)
		{
			high -= 1;
		}
		swap(&nums[low],&nums[high]);
	}
	if(nums[low] > x)  //将中间元放入对应位置
	{
		swap(&nums[low],&nums[right]);
		quickSort(num,low + 1,right);
		quickSort(num,left,low - 1);
	}
	else
	{
		swap(&nums[low + 1],&nums[right]);
		quickSort(nums,low + 2,right);
		quickSort(nums,left,low - 1);
	}
}