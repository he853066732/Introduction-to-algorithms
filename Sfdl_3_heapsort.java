//�㷨����
//NO.3
//������
//2017.1.3
//BY chang

import java.util.Scanner;

public class Sfdl_3_heapsort {
	
	int[] A;//��������
	
	int heap_size;//�Ѵ�С
	
	//��i�ĸ��ڵ�
	int parent(int i)
	{
		double a=i;
		return (int)Math.ceil(a/2)-1;
	}
	
	//��i�������
	int left(int i)
	{
		return 2*i;
	}
	
	//��i���Ҷ���
	int right(int i)
	{
		return 2*i+1;
	}
	
	//����A
	void inputA()
	{
		System.out.print("���������ָ���:\n");
		Scanner scan = new Scanner(System.in);
		int sizeofA = 0;
		if(scan.hasNextInt())
		{    
			sizeofA= scan.nextInt() ; 
		}
		A=new int[sizeofA];
		for(int i=0;i<sizeofA;i++)
		{
			System.out.print("�������"+(i+1)+"������\n");
			if(scan.hasNextInt())
			{    
				A[i]= scan.nextInt() ; 
			}
		}
		scan.close();
	}
	
	//���A
	void outputA()
	{
		System.out.print("�����Ľ��Ϊ��\n");
		for(int i=0;i<A.length;i++)
		{
			System.out.print(A[i]+" ");
		}
	}
	
	//ʹһ���ڵ�����С����
	void MIN_HEAPIFY(int i)
	{
		int l=left(i);
		int r=right(i);
		int min=i;
		if(l<heap_size && A[l]<A[i])
		{
			min=l;
		}
		if(r<heap_size && A[r]<A[min])
		{
			min=r;
		}
		if(min!=i)
		{
			int n=A[i];
			A[i]=A[min];
			A[min]=n;
			MIN_HEAPIFY(min);
		}
	}
	
	//��������С����
	void BUILD_MIN_HEAP()
	{
		heap_size=A.length;
		for(int i=A.length/2;i>=0;i--)
		{
			MIN_HEAPIFY(i);
		}
	}
	
	//������
	void HEAPSORT()
	{
		BUILD_MIN_HEAP();
		for(int i=A.length-1;i>0;i--)
		{
			int n=A[i];
			A[i]=A[0];
			A[0]=n;
			heap_size--;
			MIN_HEAPIFY(0);
		}
	}
	
	public static void main(String []args) 
	{
		Sfdl_3_heapsort c = new Sfdl_3_heapsort();
		c.inputA();
		c.HEAPSORT();
		c.outputA();
	}
	
}
