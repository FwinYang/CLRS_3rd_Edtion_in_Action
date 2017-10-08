var numberArray = [2,8,6,7,1,10,5,3,9,4];

console.log("初始的数组:\n");
console.log(numberArray.toString()+"\n");

function BubbleSort(nArr) {
    for (let i=0;i<nArr.length-1;++i)
    {
        for (let j=nArr.length-1;j>i;--j)
        {
            if (nArr[j]<nArr[j-1])
            {
                let tempKey = nArr[j];
                nArr[j] = nArr[j - 1];
                nArr[j - 1] = tempKey;
            }
        }
    }
}

BubbleSort(numberArray);

console.log("排序后的数组:\n");
console.log(numberArray.toString()+"\n");