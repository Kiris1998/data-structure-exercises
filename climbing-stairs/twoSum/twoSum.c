//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。
//numsSize为数组大小，*returnSize为返回目标数组大小
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	for(int i = 0; i < numsSize; i++) //从第一个数开始遍历
	{
		for(int j = i + 1; j < numsSize; j++) //从首数字的下一个开始遍历
		{
			if(nums[i] + nums[j] == target) //遍历寻找目标值
			{
				int* ret = malloc(sizeof(int) * 2); //分配2个int字节空间，ret存放对应数的下标
				ret[0] = i; //将对应下标放入ret数组
				ret[1] = j;
				* returnSize = 2; //目标数组大小为2
				return ret;
			}
		}
	}
	* returnSize = 0; //未找到对应目标时为0
	reurn NULL; //返回空
}