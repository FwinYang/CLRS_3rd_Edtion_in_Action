# -*-coding:utf8-*-
def Merge(list1, list2):
    x = len(list1)
    y = len(list2)
    head1 = 0
    head2 = 0
    ans = []
    while 1:
        if list1[head1] < list2[head2]:
            ans.append(list1[head1])
            head1 = head1 + 1
        else:
            ans.append(list2[head2])
            head2 = head2 + 1
        if head1 == x:
            ans = ans + list2
            break
        if head2 == y:
            ans = ans + list1
            break
    return ans


def MergeSort(listx):
    lenth = len(listx)
    # print listx
    mid = lenth / 2
    if lenth == 1:
        return listx
    else:
        A = MergeSort(listx[0:mid])
        B = MergeSort(listx[mid:lenth])
        return Merge(A, B)

# listx = [5, 4, 3, 2, 1]
# print MergeSort(listx)
