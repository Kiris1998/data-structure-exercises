char pairs(char a)
{
	if(a == ')') return '(';
	if(a == ']') return '[';
	if(a == '}') return '{';
	return 0;
}

bool vilad(char *s)
{
	int n = strlen(s);
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