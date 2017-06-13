using System;

namespace Insertion_Sort
{
    //传统实现
    class Classic
    {
        int[] a = { 2, 8, 6, 7, 1, 10, 5, 3, 9, 4 };

        public Classic()
        {
            Console.WriteLine("经典实现");
        }

        public void print()
        {
            foreach(var num in a)
            {
                Console.Write(num + " ");
            }
            Console.WriteLine();
        }

        public void Insertion_Sort()
        {
            for (int j = 1; j <= a.Length - 1; ++j)
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
