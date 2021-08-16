int josephring(int n,int ,m)
{
	int rem = 0;
	for(int i = 0;i < n;i++)
	{
		rem = (rem + m) % i;
	}
	return rem;
}	