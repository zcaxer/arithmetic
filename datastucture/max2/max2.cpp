﻿#include <iostream>
using namespace std;
/*两次遍历得到list中区间[lo,hi)中的最大值点x1和x2
* 无论什么情况复杂度Θ(n-1+n-2)=Θ(2n-3)
*/
void max2_0(int list[],int lo,int hi,int & x1,int & x2) {
	if (hi-lo>1)
	{
		x1 = lo, x2 = lo;
		for (int i = lo+1 ; i < hi; i++)
		{
			if (list[x1] < list[i]) {
				x1 = i;
			}
		}
		for (int i = lo+1; i < x1; i++)
		{
			if (list[x2] < list[i]) {
				x2 = i;
			}
		}
		for (int i = x1+1; i < hi; i++)
		{
			if (list[x2] < list[i]) {
				x2 = i;
			}
		}
	}
}
/*一次遍历得到list中区间[lo,hi)中的最大值点x1和x2，要求hi-lo>2
* 复杂度最优Θ(1+n-2)，最差Θ[1+2(n-2)]=Θ(2n-3)
*/
void max2_1(int list[], int lo, int hi, int& x1, int& x2) {
	if (list[x1=lo]<list[x2=lo+1])swap(x1, x2);
	for (int i = lo+2; i < hi; i++)
	{
		if (list[x2] < list[i]) 
			if (list[x1] < list[x2=i])swap(x1, x2);
	}
}


/*二分法得到list中区间[lo,hi)中的最大值点x1和x2，要求hi-lo>2
* 复杂度最优Θ(1+n-2)，最差Θ[1+2(n-2)]=Θ(2n-3)
*/
void max2_2(int list[], int lo, int hi, int& x1, int& x2) {
	if (hi - lo == 2) {
		if (list[x1 = lo] < list[x2 = lo + 1])swap(x1, x2);
		return;
	}
	else if (hi-lo==3)
	{
		if (list[x1 = lo] < list[x2 = lo + 1])swap(x1, x2);
		if (list[x2] < list[lo + 2])x2=lo+2;
		if (list[x1] < list[x2 ])swap(x1, x2);
		return;
	}
	int mi = lo + (hi - lo) / 2;
	int x1r, x2r, x1l, x2l;
	max2_2(list, lo, mi, x1r, x2r);
	max2_2(list, mi, hi, x1l, x2l);
	if (list[x1 = x1r] < list[x2 = x1l]) {
		swap(x1, x2);
		if (list[x2] < list[x2l]) x2=x2l;
	}
	else if (list[x2r]<list[x1l])
		{
			x2 = x1l;
		}
}

