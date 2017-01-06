//算法导论
//NO.4
//基于堆的优先队列
//2017.1.5
//BY  chang

#include<iostream>

using namespace std;

int heap_size;//堆大小

int length;//集合大小

//求i的左儿子
int left(int i)
{
	return 2 * i + 1;
}

//求i的右儿子
int right(int i)
{
	return 2 * i + 2;
}

//使一个节点生成大顶堆
void MAX_HEAPIFY(int S[],int i)
{
	int l = left(i);
	int r = right(i);
	int max = i;
	if (l<heap_size && S[l]>S[i])
	{
		max = l;
	}
	if (r<heap_size && S[r]>S[max])
	{
		max = r;
	}
	if (max != i)
	{
		int n = S[i];
		S[i] = S[max];
		S[max] = n;
		MAX_HEAPIFY(S,max);
	}
}

//建立整个大顶堆
void BUILD_MAX_HEAP(int S[])
{
	heap_size = length;
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		MAX_HEAPIFY(S,i);
	}
}

//把元素x插入集合S
void INSERT(int S[], int x)
{
	if (length < 100)
	{
		S[length] = x;
		length++;
		BUILD_MAX_HEAP(S);
	}
}

//返回S中具有最大关键字的元素
int MAXIMUM(int S[])
{
	return S[0];
}

//去掉并返回S中的具有最大关键字的元素
int EXTRACT_MAX(int S[])
{
	int n = S[0];
	S[0] = S[length - 1];
	length--;
	heap_size--;
	MAX_HEAPIFY(S, 0);
	return n;
}

//将元素x的关键字的值增加到k，k不能小于x原关键字的值
void INCREASE_KEY(int S[], int x, int k)
{
	if (x<length && k >= S[x])
		S[x] = k;
	BUILD_MAX_HEAP(S);
}

void outputS(int S[])
{
	for (int i = 0; i < length; i++)
	{
		cout << S[i] << " ";
	}
	cout << "\n";
}

int main()
{
	length = 10;
	int S[100] = {  1, 3, 2, 16, 9, 17, 14, 8, 7,66 };
	cout << "原集合为：" << endl;
	outputS(S);
	BUILD_MAX_HEAP(S);
	cout << "建立堆之后为：" << endl;
	outputS(S);
	INSERT(S, 100);
	cout << "插入一个数字100后为" << endl;
	outputS(S);
	cout << "最大关键字为："<<MAXIMUM(S) << endl;
	cout << "此时集合为：" << endl;
	outputS(S);
	cout <<"去掉并输出最大关键字："<< EXTRACT_MAX(S) << endl;
	cout << "此时集合为：" << endl;
	outputS(S);
	INCREASE_KEY(S, 9, 101);
	cout << "把第10个元素键值改为101后集合为：" << endl;
	outputS(S);
	system("pause");
	return 0;
}