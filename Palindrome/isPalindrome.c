//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//说明：本题中，我们将空字符串定义为有效的回文串。
//判断是否为回文串，s为需要判断的字符串
bool isPalindrome(char *s)  
{
	int num = strlen(s);  //获得字符串大小
	int left = 0;  //左指针
	int right = num - 1;  //右指针
	while(left < right)  //左右指针对比
	{
		while(left < right && !isalnum(s[left]))  //当为非字母或数字时，指针加一
		{
			left + = 1;
		}
		while(left < right && !isalnum(s[right]))  //当为非字母或数字时，指针减一
		{
			right -= 1;
		}
		if(tolower(s[left]) != tolower(s[right]))  //不相等时，输出为非回文串
		{
			return false;
		}
		left += 1;
		right -= 1;
	}
	return true;
}