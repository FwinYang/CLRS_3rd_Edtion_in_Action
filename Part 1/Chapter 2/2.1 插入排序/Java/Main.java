import InsertionSort.Classic;
import InsertionSort.Modern;

public class Main {

    public static void main(String[] args) {
        Classic classic = new Classic();
        System.out.println("初始的数组：");
        classic.print();
        classic.Insertion_Sort();
        System.out.println("经过插入排序后的数组：");
        classic.print();
        System.out.println("--------------------------------");
        Modern modern = new Modern();
        System.out.println("初始的数组：");
        modern.print();
        modern.Insertion_Sort();
        System.out.println("经过插入排序后的数组：");
        modern.print();
    }
}
