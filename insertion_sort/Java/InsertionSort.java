package com.company;

import java.util.*;
public class InsertionSort {

    public static void main(String[] args) {
	    List<Integer> lst = Arrays.asList(23,34,36,8,3,54,6,10,1,62);
	    ArrayList<Integer> arr = new ArrayList<>();
	    arr.addAll(lst);

        arr = insertion(arr);

	    for (int i = 0; i < arr.size(); i++) {
	        System.out.print(arr.get(i) + " ");
        }
    }

    public static ArrayList<Integer> insertion(ArrayList<Integer> arr) {
        for (int i = 1; i < arr.size(); i++) {
            int key = arr.get(i);
            int sorted_index = i - 1;

//            move sorted numbers to the right of key if key is smaller
            while (sorted_index >= 0 && arr.get(sorted_index) > key) {
                arr.set(sorted_index + 1, arr.get(sorted_index));
                sorted_index -= 1;
            }
            arr.set(sorted_index + 1, key);
        }
        return arr;
    }
}
