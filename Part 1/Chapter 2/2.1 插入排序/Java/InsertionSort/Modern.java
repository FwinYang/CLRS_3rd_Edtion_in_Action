package InsertionSort;

import java.util.ArrayList;
import java.util.Arrays;

public class Modern {
    ArrayList<Integer> a = new ArrayList<>(Arrays.asList(2, 8, 6, 7, 1, 10, 5, 3, 9, 4 ));

    public Modern()
    {
        System.out.println("“现代”实现");
    }

    public void print()
    {
        for (int num : a)
        {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public void Insertion_Sort()
    {
        ArrayList<Integer> b = new ArrayList<>();
        for (int num : a)
        {
            int i;
            for (i = b.size() - 1; i >= 0 && b.get(i) > num; i--) ;
            b.add(i + 1, num);
        }
        a = b;
    }
}
