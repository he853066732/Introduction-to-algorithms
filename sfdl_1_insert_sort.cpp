//�㷨����
//NO.1
//���������㷨
//2017.1.2    
//BY    chang

#include<iostream>

using namespace std;
//����������
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
	int A[100];//��Ҫ���������
	int length = 0;
	cout << "���������鳤�ȣ�"<<endl;
	cin >> length;
	//����
	for (int i = 0; i < length; i++)
	{
		cout << "�������" << i + 1 << "������" << endl;
		cin >> A[i];
	}
	insert_sort(length, A);

	//���
	cout << "��������" << endl;
	for (int i = 0; i < length; i++)
		cout << A[i] << " ";
	system("pause");

	return 0;
}