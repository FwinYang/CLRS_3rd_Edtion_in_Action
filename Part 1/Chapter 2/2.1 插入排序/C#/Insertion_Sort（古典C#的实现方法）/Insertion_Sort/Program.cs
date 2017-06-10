using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Insertion_Sort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] a = { 2, 8, 6, 7, 1, 10, 5, 3, 9, 4 };
            Console.WriteLine("初始的数组：");
            foreach (var num in a)
            {
                Console.Write(num + " ");
            }
            Console.WriteLine();

            Insertion_Sort(ref a);

            Console.WriteLine("经过插入排序后的数组：");
            foreach (var num in a)
            {
                Console.Write(num + " ");
            }
            Console.WriteLine();
        }

        static void Insertion_Sort(ref int[] A)
        {
            int length = A.Length;
            for (int j = 1; j <= length - 1; ++j)
            {
                int key = A[j];
                int i = j - 1;
                while (i >= 0 && A[i] > key)
                {
                    A[i + 1] = A[i];
                    --i;
                }
                A[i + 1] = key;
            }
        }
    }
}
