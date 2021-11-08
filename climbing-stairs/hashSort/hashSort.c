//利用哈希表进行排序
//输入数组为nums[10] = { 12, 88, 66, 122, 43, 66, 88, 99, 666, 888}
//numsSize是数组大小
int Hash(int nums[],int numsSize)
{
	int max = 1001;  //哈希表的值要大于输入数组的最大值
	int hashMap[max] = {0};  //创建哈希表并初始化为0
	for(int i = 0;i < numsSize)  //将输入数组映射到哈希表上
	{
		hashMap[nums[i]] += 1;
	}
	for(int m = 1,p = 0;m < max;m++)  //将哈希表重新按升序映射到原数组里实现排序
	{
		for(int n = 0;n < hashMap[m];n++)
		{
			nums[p++] = m;
		}
	}
	return nums;
}