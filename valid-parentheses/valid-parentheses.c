char pairs(char a)  %返回右括号对应的左括号
{
	if(a == ')') return '(';
	if(a == ']') return '[';
	if(a == '}') return '{';
	return 0;
}

bool vilad(char *s) %布尔函数，括号匹配主函数，返回输入括号形式是否正确
{
	int n = strlen(s);  %输入字符串s的有效字符数
	if(n % 2 == 1)
	{
		return false;
	}
	int skt[n + 1],top = 0;  
	for(int i = 0;i < n;i++)
	{
		c = s[i];
		if(top !=0 && pairs(c) == skt[top - 1])
		{
			top--;
		}
		else
		{
			skt[top++] = c;
		}
	}
	return top == 0;
}	