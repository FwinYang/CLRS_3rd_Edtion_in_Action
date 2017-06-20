using System;
using System.Linq;
using System.Collections.Generic;

namespace Find_Maximum_SubArray
{
    class Program
    {

        static int count = 0;

        static void Main(string[] args)
        {
            List<int> A = new List<int>{ 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 } ;
            Console.WriteLine("original:" + string.Join(",",A));
            

            var result = FindMaximunSubarray(A, 0, A.Count);

            Console.WriteLine("MaximunSubarray:");
            for (int index = result.Item1;index < result.Item2; index ++)
            {
                Console.WriteLine(A[index]);
            }
            Console.WriteLine("MaximunSubarray:" + result.Item3);
            Console.ReadKey();


        }


        static  Tuple<int, int, int> FindMaxCrossingSubarray(List<int> A, int low, int mid, int high)
        {
            int maxLeft = 0;
            int leftSum = int.MinValue, sum = 0;
            for (int index = mid; index >= low; index--)
            {
                sum = sum + A[index];
                if (sum > leftSum)
                {
                    leftSum = sum;
                    if (sum >= leftSum)
                    {
                        leftSum = sum;
                        maxLeft = index;
                    }
                }
            }

            sum = 0;

            int maxRight = 0;
            int rightSum = int.MinValue;
            for (int index = mid + 1; index < high; index++)
            {
                sum = sum + A[index];
                if (sum >= maxRight)
                {
                    rightSum = sum;
                    maxRight = index;
                }
            }

            return Tuple.Create<int, int, int>(maxLeft, maxRight, (leftSum) + (rightSum));
        }


        static Tuple<int, int, int> FindMaximunSubarray(List<int> A, int low, int high)
        {
            if (high == low)
            {
               // Console.WriteLine(count++);
                return Tuple.Create<int, int, int>(low, high, A[low]);

            }
               
            else
            {
                var mid = (low + high) / 2;
                var leftResult = FindMaximunSubarray(A, low, mid);
                var rightResult = FindMaximunSubarray(A, mid+1, high);
                var crossResult = FindMaxCrossingSubarray(A, low, mid, high);
                if (leftResult.Item3 >= rightResult.Item3 && leftResult.Item3 >= crossResult.Item3)
                    return leftResult;
                else if (rightResult.Item3 >= leftResult.Item3 && rightResult.Item3 >= crossResult.Item3)
                    return rightResult;
                else return crossResult;
            }

        }

        //int findMaxSubArray(int[] a, int n)
        //{
        //    int result = a[0];
        //    int sum = a[0];

        //    for (int i = 1; i < n; ++i)
        //    {
        //        if (sum > 0)
        //            sum += a[i];
        //        else
        //            sum = a[i];

        //        if (sum > result)
        //            result = sum;
        //    }

        //    return result;
        //}

    }


}
