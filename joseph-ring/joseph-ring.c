int josephring(int n,int ,m) %约瑟夫环函数
{
	int remainSeat = 0;   %remainSeat是每次挑选出的座位数
	for(int i = 0;i < n;i++)
	{
		remainSeat = (remainSeat + m) % i;
	}
	return remainSeat;
}	