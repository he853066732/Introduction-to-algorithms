//算法导论
//NO.1
//插入排序算法
//2017.1.2    
//BY    chang

#include<iostream>

using namespace std;
//插入排序函数
void insert_sort(int length, int A[])
{
	for (int i = 1; i < length; i++)
	{
		int key = A[i];
		int j = i - 1;
		while (j>=0 && A[j] > key)
		{
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = key;
	}
}


int main()
{
	int A[100];//需要排序的数组
	int length = 0;
	cout << "请输入数组长度："<<endl;
	cin >> length;
	//输入
	for (int i = 0; i < length; i++)
	{
		cout << "请输入第" << i + 1 << "个数字" << endl;
		cin >> A[i];
	}
	insert_sort(length, A);

	//输出
	cout << "排序结果：" << endl;
	for (int i = 0; i < length; i++)
		cout << A[i] << " ";
	system("pause");

	return 0;
}