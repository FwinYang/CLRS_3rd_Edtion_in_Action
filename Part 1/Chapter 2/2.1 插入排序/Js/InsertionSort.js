var numberArray = [2,8,6,7,1,10,5,3,9,4];

console.log("初始的数组:\n");
console.log(numberArray.toString()+"\n");

function InsertionSort(numArr) {
    for(let i = 1;i<numArr.length;++i)
    {
        for(let j = i;j>0;--j) {
            if(numArr[j]<numArr[j-1])
            {
                let temp = numArr[j-1];
                numArr[j-1]=numArr[j];
                numArr[j] = temp;
            }
            else break;
        }
    }
}
InsertionSort(numberArray);

console.log("经过插入排序后的数组:\n");
console.log(numberArray.toString()+"\n");