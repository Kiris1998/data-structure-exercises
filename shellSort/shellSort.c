//希尔排序，每次通过不同增量对数组进行分组，并每组进行插入排序，当增量为1时排序完成
//nums是输入数组，numsSize是数组大小
int shellSort(int nums[],int numsSize)
{
	for(int step = numsSize / 2;step > 0;step /= 2)  //每次步长减半
	{
		for(int i = step;i <= numsSize;i++)  //每组都进行插入排序直到最后
		{
			int j = i;
			temp = nums[i];
			while(j - step > 0 && nums[j - step] > temp)  //插入排序时每组间的对应位置相比较，将小的数放左边组，大的数放右边组
			{
				nums[j] = nums[j - step];
				j = j - step;
			}
			nums[j] = temp;
		}
	}
}