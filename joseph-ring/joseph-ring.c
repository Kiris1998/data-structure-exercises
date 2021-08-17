int josephring(int n,int ,m) %约瑟夫环函数
{
	int rem = 0;   %rem是每次挑选出的座位数
	for(int i = 0;i < n;i++)
	{
		rem = (rem + m) % i;
	}
	return rem;
}	