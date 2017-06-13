package InsertionSort;

public class Classic {
    int[] a = { 2, 8, 6, 7, 1, 10, 5, 3, 9, 4 };

    public Classic(){
        System.out.println("经典实现");
    }

    public void print()
    {
        for(int num : a)
        {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public void Insertion_Sort()
    {
        for (int j = 1; j <= a.length - 1; ++j)
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
