var numArr = [2,8,6,7,1,10,5,3,11,9,4];

console.log("初始的数组:\n");
console.log(numArr+"\n");

function sort2Arr(arr1,arr2)
{
    var mixArr = new Array;

    var index1 = 0,index2 = 0;
    while(index1<arr1.length&&index2<arr2.length) {
        if(arr1[index1]<arr2[index2]) {
            mixArr.push(arr1[index1]);++index1;
        }
        else {
            mixArr.push(arr2[index2]);++index2;
        }
    }

    if(index1==arr1.length){ while(index2<arr2.length){mixArr.push(arr2[index2]);++index2;} }
    else{ while(index1<arr1.length){mixArr.push(arr1[index1]);++index1;} }

    return mixArr;
}

function mergeSort(nArr){
    if(nArr.length>1)
    {
        var part1ofArr = nArr.splice(0,nArr.length/2);
        var part2ofArr = nArr;

        return sort2Arr(mergeSort(part1ofArr),mergeSort(part2ofArr));
    }
    return nArr;
}

var sortedArr = mergeSort(numArr);

console.log("排序后的数组:\n");
console.log(sortedArr+"\n");