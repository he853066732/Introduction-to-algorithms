# -*- coding=utf-8 -*-
#算法导论
#N0.2
#合并排序
#2017.1.2
#By   chang

def MERGE(A,p,q,r):#把A[p:q]和A[q:r]合并
    n1=q-p+1
    n2=r-q
    i=0
    j=0
    L=[]
    R=[]
    while i<n1:
        L.append(A[p+i-1])
        i=i+1
    while j < n2:
        R.append(A[q+j])
        j=j+1
    L.append(99999)
    R.append(99999)
    i=0
    j=0
    k=p-1
    while k<r:
        if L[i]<R[j]:
            A[k]=L[i]
            i=i+1
        else:
            A[k]=R[j]
            j=j+1
        k=k+1


def MERGE_SORT(A,p,r):#递归函数，合并排序
    if p<r:
        q=(r+p)/2
        MERGE_SORT(A,p,q)
        MERGE_SORT(A,q+1,r)
        MERGE(A,p,q,r)

A=[]
length=int(raw_input("请输入数组长度："))
i=0
print length
while i<length:
    print "请输入第",i+1,"个数字"
    A.append(int(raw_input()))
    i=i+1
MERGE_SORT(A,1,len(A))
print A
