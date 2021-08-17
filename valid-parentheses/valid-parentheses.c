char pairs(char a)//返回右括号对应的左括号，a为输入的括号
{
    switch(a)
    {
        case ')':return '(';break;
        case ']':return '[';break;
        case '}':return '{';break;
    }
    return 0;
}

bool vilad(char *string) //布尔函数，括号匹配主函数，返回输入括号形式是否正确
{
	int n = strlen(string);  //输入字符串string的有效字符数
	if(n % 2 == 1)  //当输入符号数不为偶数时直接返回假值
	{
		return false;
	}
	int skt[n + 1],top = 0;  
	for(int i = 0;i < n;i++) //每次循环提取出一个符号，左括号推入堆栈，遇到右括号与堆栈最顶层匹配，相同则消去
	{
		c = string[i];  //c为提取出的单个括号
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