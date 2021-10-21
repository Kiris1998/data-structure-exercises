//寻找两个正序数组的中位数 :给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
//nums1Size为第一组数组的大小，nums2Size为第二组数组的大小
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int firArray = 0;  //第一个数组的指针
	int secArray = 0;  //第二个数组的指针
	int length = nums1Size + nums2Size;  //数组合并后大小
	int cur = -1;  //当前的数
	int next = -1;  //下个数
	for(int i = 0; i <= length / 2; i++)  //找中位数
	{
		cur = next;  //当前数更新
		if(firArray < nums1Size && (secArray >= nums2Size || nums1[firArray]) < nums2[secArray])  //第一数组不为空时，第二数组为空或第一数组的数小于第二数组
	
		{
			next = nums1[firArray];  //下一个数在第一数组上
			firArray = firArray + 1;  //指针往前进一
			continue;  //符合条件则跳出本次for循环，继续下次循环
		}  
		next = nums2[secArray];  //反之更新第二数组指针
		secArray = secArray + 1;
	}
	return length % 2 == 0 ? return (cur + next) / 2.0 : next; //长度为偶数时选前者,长度为奇数时选后者
}