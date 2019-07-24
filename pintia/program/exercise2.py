
n = eval(input())
list1=list(map(int,input().split(' ')))
max1=0;count1=0;j=-1;k=0;d=0;f=0
for i in range(n):
    count1+=list1[i]
    if j==-1:
        d=list1[i]
        j=0
    if count1>max1:          
        k=list1[i]
        f=d
        max1=count1
    if count1<0:
        j=-1
        count1=0
isAllFu = True
for x in list1:
    if x>=0:
        isAllFu=False
        break

if isAllFu:
    f=list1[0]
    k=list1[n-1]

print("%d %d %d"%(max1,f,k),end="")