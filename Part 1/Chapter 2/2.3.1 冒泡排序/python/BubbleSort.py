# -*-coding:utf8-*-
def BubbleSort(listx):
    lenth = len(listx)
    for i in range(lenth):
        for j in range(lenth, i, -1):
            if listx[j - 1] < listx[j - 2]:
                listx[j - 1], listx[j - 2] = listx[j - 2], listx[j - 1]
    return listx


# listx = [5, 4, 3, 2, 1]
# print BubbleSort(listx)
