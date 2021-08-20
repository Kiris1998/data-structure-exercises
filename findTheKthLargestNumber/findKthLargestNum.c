//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
//请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
//nums为要查找的数组，k为第k个最大的数
int findKthLargestNum(int *nums,int numsSize,int k)  
{
	srand(time(0)); 
	return quickSelect(nums,0,numsSize - 1,numsSize - k);
}

//nums为要查找的数组,min为划分后数组的左坐标，max为对应右坐标，index为要找的第k个最大数
int quickSelect(int *nums,int min,int max,int index)  
{
	int q = randNum(nums,min,max);  //找一个随机数作为中间元,q为返回的中间元
	if(q == index)  //若返回的中间元坐标与index相等，则q对应的数字就是第k个最大数
	{
		return nums[q];
	}
	else  
	{
		return q < index ? quickSelect(nums,q+1,max,index) : quickSelect(nums,0,q - 1,index);
	}
}

//取一个随机数做中间元，其他参数与上一致
int randNum(int *nums,int min,int max)  
{
	int rn = rand() % (max - min + 1) + min;  // rn为取得随机数
	int temp = nums[rn];  // 将随机数对应的数先放入最后
	nums[rn] = nums[max];
	nums[max] = temp;
	return divideQue(nums,min,max);
}

//将小于随机数对应数的全放入数组最左侧，不管是否排好序，其他参数与上一致
int divideQue(int *nums,int min,int max) 
{
	int i = min - 1;  //i为左指针
	for(int j = min;j < max;++j)  //j为右指针
	{
		if(nums[j] <= nums[max])  //若右指针的数小于中间元，则与左指针交换
		{
			int temp = nums[i += 1];
			nums[i] = nums[j];
			nums[j] = temp;
		}
	}
	int tem = nums[i + 1];  //将中间元放入第i+1个位置，即大于左侧小于右侧的对应位置
	nums[i + 1] = nums[max];
	nums[max] = tem;
	return i + 1;  //返回的i+1即为第q个最大数，若q与inde相等就是要找的第k个最大数
}