using System;
using System.Collections.Generic;

namespace Insertion_Sort
{
    class Modern
    {
        List<int> a = new List<int> { 2, 8, 6, 7, 1, 10, 5, 3, 9, 4 };

        public Modern()
        {
            Console.WriteLine("“现代”实现");
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
            List<int> b = new List<int>();
            foreach (var num in a)
            {
                int i;
                for (i = b.Count - 1; i >= 0 && b[i] > num; i--) ;
                b.Insert(i + 1, num);
            }
            a = b;
        }
    }
}
