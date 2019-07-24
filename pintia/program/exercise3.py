#https://pintia.cn/problem-sets/1134360184290500608/problems/1138764336949059585
# 4 3 4 -5 2 6 1 -2 0
# 3 5 20 -7 4 3 1
import copy
def exercise3():
    list1=list(map(int,input().split()))
    list2=list(map(int,input().split()))
    if list1[0]==0:
        list1=[0,0]
    else:
        list1=list1[1:]
    if list2[0]==0:
        list1=[0,0]
    else:
        list2=list2[1:]

    dict1={}
    dict2={}
    for i in range(0,len(list1),2):
        dict1[list1[i+1]]=list1[i]
    for i in range(0,len(list2),2):
        dict2[list2[i+1]]=list2[i]

    dict4=multiDict(copy.copy(dict1),copy.copy(dict2))
    printDict(dict4)

    dict3=addDict(copy.copy(dict1),copy.copy(dict2))
    printDict(dict3)
    
    
def addDict(dict1,dict2):
    dictn = dict1
    for key in dict2:
        if key in dictn.keys():
            dictn[key] += dict2[key]
        else:
            dictn[key]=dict2[key]
    return dictn

def multiDict(dict1,dict2):
    dictn={}
    for key1 in dict1:
        dictCur = {}
        for key2 in dict2:
            dictCur[key1+key2]=dict1[key1]*dict2[key2]
        dictn = addDict(dictn,dictCur)
        #print(dictn)
    return dictn

def printDict(dict1):
    #先排序
    for key in list(dict1):
        if dict1[key]==0:
            dict1.pop(key)
    if len(dict1)==0:
        print('0 0',end='')
        return
    dict1=sorted(dict1.items(),key = lambda x:x,reverse = True)
    for i in range(len(dict1)):
        print("%d %d"%(dict1[i][1],dict1[i][0]),end="")
        if i!=len(dict1)-1:
            print(' ',end='')
    


exercise3()