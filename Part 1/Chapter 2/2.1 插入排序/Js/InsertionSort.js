var numberArray = [2,8,6,7,1,10,5,3,9,4];

document.write("初始的数组:<br/>");
document.write(numberArray.toString()+"<br/>");

function InsertionSort(numArr) {
    for(var i = 1;i<numArr.length;++i)
    {
        for(var j = i;j>0;--j) {
            if(numArr[j]<numArr[j-1])
            {
                var temp = numArr[j-1];
                numArr[j-1]=numArr[j];
                numArr[j] = temp;
            }
            else break;
        }
    }
}
InsertionSort(numberArray);

document.write("经过插入排序后的数组:<br/>");
document.write(numberArray.toString()+"<br/>");