public class QuickSort {

    // Recursive quickSort algorithm
    public static void quickSort(int[] arr, int begin, int end) {
        if (begin < end) {
            int partitionIndex = partition(arr, begin, end);

            quickSort(arr, begin, partitionIndex-1);
            quickSort(arr, partitionIndex+1, end);
        }
    }

    // Overloaded for only one input parameter (the array). By default it sorts the entire array
    public static void quickSort(int[] array){
        quickSort(array, 0, array.length - 1);
    }


    // Arbitrary choice for pivot element is the last element of the segment
    // Move all elements that are greater than the pivot to the right of the pivot
    private static int partition(int[] arr, int begin, int end) {
        int pivot = arr[end];
        int i = (begin-1);

        for (int j = begin; j < end; j++) {
            if (arr[j] <= pivot) {
                i++;

                int swapTemp = arr[i];
                arr[i] = arr[j];
                arr[j] = swapTemp;
            }
        }

        int swapTemp = arr[i+1];
        arr[i+1] = arr[end];
        arr[end] = swapTemp;

        return i+1;
    }

    public static void main(String[] args) {
        // Example with 3 parameters
        int[] array = {3,6,1,7,3,1,9,8};
        quickSort(array, 0, 7);
        for(int i : array){
            System.out.print(i + " ");
        }

        System.out.println();

        // Example with 1 parameter
        int[] array2 = {4,6,1,7,3,4};
        quickSort(array2);
        for(int i : array2){
            System.out.print(i + " ");
        }
    }
}
