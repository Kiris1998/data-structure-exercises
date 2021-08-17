//约瑟夫环函数,n为座位个数，m为相隔多少抽取一个座位
int josephring(int n,int ,m) 
{
	int remainSeat = 0;   //remainSeat是每次挑选出的座位数
	for(int i = 0;i < n;i++) //每次循环求出抽选的座位号，最后一次循环为最后剩下的座位
	{
		remainSeat = (remainSeat + m) % i;
	}
	return remainSeat;
}	