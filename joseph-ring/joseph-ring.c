int josephring(int n,int ,m) %约瑟夫环函数
{
	int remainseat = 0;   %remainseat是每次挑选出的座位数
	for(int i = 0;i < n;i++)
	{
		remainseat = (remainseat + m) % i;
	}
	return remainseat;
}	