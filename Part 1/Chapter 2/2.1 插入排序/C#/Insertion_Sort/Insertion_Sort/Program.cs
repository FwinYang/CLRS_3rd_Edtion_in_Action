using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Insertion_Sort
{
    class Program
    {
        int [] a = { 2, 8, 6, 7, 1, 10, 5, 3, 9, 4 };
        static void Main(string[] args)
        {
            var temp = new Program();
            Console.WriteLine("初始的数组：");
            temp.print();
            
            temp.Insertion_Sort();

            Console.WriteLine("经过插入排序后的数组：");
            temp.print();
        }

        public void print()
        {
            foreach (var num in a)
            {
                Console.Write(num + " ");
            }
            Console.WriteLine();
        }

        public void Insertion_Sort()
        {
            int length = a.Length;
            for (int j = 1; j <= length - 1; ++j)
            {
                int key = a[j];
                int i = j - 1;
                while (i >= 0 && a[i] > key)
                {
                    a[i + 1] = a[i];
                    --i;
                }
                a[i + 1] = key;
            }
        }
    }
}
