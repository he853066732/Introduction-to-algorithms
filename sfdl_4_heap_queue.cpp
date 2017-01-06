//�㷨����
//NO.4
//���ڶѵ����ȶ���
//2017.1.5
//BY  chang

#include<iostream>

using namespace std;

int heap_size;//�Ѵ�С

int length;//���ϴ�С

//��i�������
int left(int i)
{
	return 2 * i + 1;
}

//��i���Ҷ���
int right(int i)
{
	return 2 * i + 2;
}

//ʹһ���ڵ����ɴ󶥶�
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

//���������󶥶�
void BUILD_MAX_HEAP(int S[])
{
	heap_size = length;
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		MAX_HEAPIFY(S,i);
	}
}

//��Ԫ��x���뼯��S
void INSERT(int S[], int x)
{
	if (length < 100)
	{
		S[length] = x;
		length++;
		BUILD_MAX_HEAP(S);
	}
}

//����S�о������ؼ��ֵ�Ԫ��
int MAXIMUM(int S[])
{
	return S[0];
}

//ȥ��������S�еľ������ؼ��ֵ�Ԫ��
int EXTRACT_MAX(int S[])
{
	int n = S[0];
	S[0] = S[length - 1];
	length--;
	heap_size--;
	MAX_HEAPIFY(S, 0);
	return n;
}

//��Ԫ��x�Ĺؼ��ֵ�ֵ���ӵ�k��k����С��xԭ�ؼ��ֵ�ֵ
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
	cout << "ԭ����Ϊ��" << endl;
	outputS(S);
	BUILD_MAX_HEAP(S);
	cout << "������֮��Ϊ��" << endl;
	outputS(S);
	INSERT(S, 100);
	cout << "����һ������100��Ϊ" << endl;
	outputS(S);
	cout << "���ؼ���Ϊ��"<<MAXIMUM(S) << endl;
	cout << "��ʱ����Ϊ��" << endl;
	outputS(S);
	cout <<"ȥ����������ؼ��֣�"<< EXTRACT_MAX(S) << endl;
	cout << "��ʱ����Ϊ��" << endl;
	outputS(S);
	INCREASE_KEY(S, 9, 101);
	cout << "�ѵ�10��Ԫ�ؼ�ֵ��Ϊ101�󼯺�Ϊ��" << endl;
	outputS(S);
	system("pause");
	return 0;
}