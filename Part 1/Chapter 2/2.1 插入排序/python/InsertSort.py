# -*-coding:utf8-*-

def InsertSort(list):
    lenth = len(list)
    for i in range(1, lenth):
        current = list[i]
        j = i - 1
        while j >= 0:
            if list[j] > current:  # 结果为增序列
                list[j + 1] = list[j]
                list[j] = current
            j = j - 1
    return list


# listx = [5, 4, 3, 2, 1]
# print InsertSort(listx)
