# -*-coding:utf8-*-
# InsertSort By Xu
# list为需要排序的元组
# x=[5,4,3,2,1]
def InsertSort(list):
    lenth=len(list)
    for i in range(1, lenth):
        current = list[i]
        j=i-1
        while j>=0:
            if list[j]>current:     # 结果为增序列
                list[j+1]=list[j]
                list[j]=current
            j=j-1
    return list
# print InsertSort(x)