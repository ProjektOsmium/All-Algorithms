import java.util.Random;

class Array{
    int[] array;
    int nElems;

    public Array(int maxElems){
        array = new int[maxElems];
        nElems = 0;
    }

    public void insert(int elem){
        array[nElems++] = elem;
    }

    public void display(){
        for(int i=0; i<nElems; i++){
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    public void shellsort(){

        int h = 1;
        
        // Get the largest number from Knuth Sequence that is less than number of Elements in array.
        while(h <= nElems/3){
            h = 3*h + 1;
        }

        // Perform sorting
        while(h > 0){ // h will decrease with each iteration.
            for(int outer = h; outer<nElems; outer++){
                // A temp variable for the array under consideration.
                int temp = array[outer];
                int index = outer; // Keep track of the index that we will be comparing.
                while(index>=h && array[index-h] > temp){
                    array[index] = array[index-h]; // Put the smaller element in the bigger's place.
                    index -= h;
                }
                array[index] = temp;
            } 
            h = (h-1) / 3;

        }

    }

}

class ShellSort{

    public static void main(String[] args) {
        Array array = new Array(20);
        Random random = new Random();
        for(int i = 0; i<10; i++){
            array.insert(random.nextInt(100));
        }

        System.out.println("Array before sorting:");
        array.display();
        array.shellsort();
        System.out.println("Array after sorting:");
        array.display();
    }
}