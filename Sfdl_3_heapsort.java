//算法导论
//NO.3
//堆排序
//2017.1.3
//BY chang

import java.util.Scanner;

public class Sfdl_3_heapsort {
	
	int[] A;//排序数组
	
	int heap_size;//堆大小
	
	//求i的父节点
	int parent(int i)
	{
		double a=i;
		return (int)Math.ceil(a/2)-1;
	}
	
	//求i的左儿子
	int left(int i)
	{
		return 2*i;
	}
	
	//求i的右儿子
	int right(int i)
	{
		return 2*i+1;
	}
	
	//输入A
	void inputA()
	{
		System.out.print("请输入数字个数:\n");
		Scanner scan = new Scanner(System.in);
		int sizeofA = 0;
		if(scan.hasNextInt())
		{    
			sizeofA= scan.nextInt() ; 
		}
		A=new int[sizeofA];
		for(int i=0;i<sizeofA;i++)
		{
			System.out.print("请输入第"+(i+1)+"个数字\n");
			if(scan.hasNextInt())
			{    
				A[i]= scan.nextInt() ; 
			}
		}
		scan.close();
	}
	
	//输出A
	void outputA()
	{
		System.out.print("排序后的结果为：\n");
		for(int i=0;i<A.length;i++)
		{
			System.out.print(A[i]+" ");
		}
	}
	
	//使一个节点生成小顶堆
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
	
	//建立整个小顶堆
	void BUILD_MIN_HEAP()
	{
		heap_size=A.length;
		for(int i=A.length/2;i>=0;i--)
		{
			MIN_HEAPIFY(i);
		}
	}
	
	//堆排序
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
