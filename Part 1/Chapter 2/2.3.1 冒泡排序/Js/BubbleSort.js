var numberArray = [2,8,6,7,1,10,5,3,9,4];

document.write("初始的数组:<br/>");
document.write(numberArray.toString()+"<br/>");

function BubbleSort(nArr) {
    for (var i=0;i<nArr.length-1;++i)
    {
        for (var j=nArr.length-1;j>i;--j)
        {
            if (nArr[j]<nArr[j-1])
            {
                var tempKey = nArr[j];
                nArr[j] = nArr[j - 1];
                nArr[j - 1] = tempKey;
            }
        }
    }
}

BubbleSort(numberArray);

document.write("排序后的数组:<br/>");
document.write(numberArray.toString()+"<br/>");