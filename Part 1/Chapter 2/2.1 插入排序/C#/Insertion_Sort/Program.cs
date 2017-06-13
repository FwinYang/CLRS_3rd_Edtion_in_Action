using System;

namespace Insertion_Sort
{
    class Program
    {
        static void Main(string[] args)
        {
            var classic = new Classic();
            Console.WriteLine("初始的数组：");
            classic.print();
            classic.Insertion_Sort();
            Console.WriteLine("经过插入排序后的数组：");
            classic.print();
            Console.WriteLine("--------------------------------");
            var modern = new Modern();
            Console.WriteLine("初始的数组：");
            classic.print();
            classic.Insertion_Sort();
            Console.WriteLine("经过插入排序后的数组：");
            classic.print();
        }
    }
}
