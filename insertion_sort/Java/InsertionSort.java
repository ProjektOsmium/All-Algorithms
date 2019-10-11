import java.util.Random;
import java.util.Scanner;

class Array{

    private int[] a;
    private int nElems;

    public Array(int max){
        a = new int[max];
        nElems = 0;
    }

    public void insert(int elem){
        a[nElems++] = elem;
    }

    public void display(){
        for(int i = 0; i<nElems; i++){
            System.out.print(a[i] + " ");
        }
        System.out.println("");
    }

    public void insertionSort(){
        // Out is the dividing line. In this case, the whole array is consider unsorted.
        
        int in, out;
        for(out = 1; out<nElems; out++){
            {
                int temp = a[out];
                in = out;
                while(in>0 && a[in-1] >= temp){ // Until a smaller item is found or we reach the left end
                    a[in] = a[in-1];
                    --in;
                }
                a[in] = temp;
            }
        }
    }
}

public class InsertionSort{
    public static void main(String[] args){

        Random random = new Random();

        int maxSize = 10;
        Array arr = new Array(maxSize);
        
        for(int i=0; i<maxSize; i++){
            arr.insert(random.nextInt(100));
        }
        System.out.println("Array before sorting: ");
        arr.display();
        System.out.println("Array after sorting: ");
        arr.insertionSort();
        arr.display();

    }
}