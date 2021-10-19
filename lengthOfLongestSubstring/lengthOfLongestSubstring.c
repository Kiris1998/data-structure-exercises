//无重复字符的最长子串 :给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
int lengthOfLongestSubstring(char * s)
{
	int hash[256];  //哈希表
	int left = 0;  //左指针
	int right;  //右指针
	int max = 0;  //不含有重复字符的 最长子串 的长度
	int length = strlen(s);
	for(right = 0; right < length; right++)  //通过左右指针形成滑动窗口，将窗口中的值映射到哈希表中
	{
		hash[s[right]] = hash[s[right]] + 1;
		while(hash[s[right]] > 1)  //遇到重复字母时将左窗口往前进一位
		{
			hash[s[left]] = hash[s[left]] - 1;
			left = left + 1;
		}
		max = fmax(max,right - left + 1)  //更新最长串的最大值
	}
	return max;
}