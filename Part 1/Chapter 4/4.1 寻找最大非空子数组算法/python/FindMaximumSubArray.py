# -*-coding:utf8-*-
# Find the Maximum Sub Array
# x = [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]


def find_max_subarray(listx):
    lenth = len(listx)
    if lenth == 1:
        return listx[0]
    else:
        mid = lenth / 2
        # print "%d "%mid
        # print listx,listx[:mid],listx[mid:]
        # print "\n"
        left_max = find_max_subarray(listx[:mid])
        right_max = find_max_subarray(listx[mid:])
        cross_max = find_max_crossing(listx, mid)
        tmpmax = max(left_max, right_max)
        return max(tmpmax, cross_max)


def find_max_crossing(listx, mid):
    leftmax = float('-inf')
    sum = 0
    for i in range(mid - 1, -1, -1):
        # alert:
        #   if use "for i in range(x,x)",
        #   then the program won't go into the for object,
        #   so I write "range(mid-1,-1,-1)" here in case mid-1=0
        sum = sum + listx[i]
        if sum > leftmax:
            leftmax = sum
    rightmax = float('-inf')
    sum = 0
    for i in range(mid, len(listx)):
        sum = sum + listx[i]
        if sum > rightmax:
            rightmax = sum
    return rightmax + leftmax


# print find_max_subarray(x)
