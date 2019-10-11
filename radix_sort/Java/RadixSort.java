import java.util.*;

class Node{
    int data;
    Node next;

    public Node(int data, Node next){
        this.data = data;
        this.next = next;
    }
}

class LinkedListQueue{
    private Node head;

    public LinkedListQueue(){
        this.head=null;
    }

    public boolean isEmpty(){
        return (this.head == null);
    }

    public void insert(int data){
        /* The data will be added to the end of the queue.*/
        if(isEmpty()){
            this.head=new Node(data, null);
        }else{
            Node curr = this.head;
            while(curr.next != null){
                curr = curr.next;
            }
            curr.next = new Node(data, null);
        }
    }

    public Node delete(){
        /* 
        Removes a node from the beginning and returns it.
        */
        if(isEmpty()){
            return null;
        }
        Node firstNode = this.head;
        this.head = this.head.next; // Point the head to the 2nd node
        firstNode.next = null; // Remove unnecessary pointer to the new first node.
        return firstNode;
    }

    public void display(){
        if(isEmpty()){
            return ;
        }
        Node curr = this.head;
        // System.out.print(curr.data + " ");
        while(curr != null){
            System.out.print(curr.data + " ");
            curr = curr.next;
        }
        System.out.println();
    }
}

class RadixSortClass{
    private int[] array;
    private int nElems;

    public RadixSortClass(int maxElems){
        array = new int[maxElems];
        nElems = 0;
    }

    public void insert(int elem){
        array[nElems++] = elem;
    }

    public void display(){
        for(int i = 0; i<nElems; i++){
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }  

    public int getDigitCount(int number){
        return (int)Math.floor(Math.log10(number) + 1); 
    }

    public int getMaxNumber(){
        int max = 0;
        for(int num:array){
            if(num>max)
                max=num;
        }
        return max;
    }

    public void sort(){

        // Initialize 10 linked lists for each possible digit.
        LinkedListQueue tempList[] = new LinkedListQueue[10];
        // Initialize the temp list.
        for(int i =0; i<10; i++){
            tempList[i] = new LinkedListQueue();
        }

        // Find the largest number.
        int maxNumber = getMaxNumber();
        // System.out.println("Max number: " + maxNumber);
        int digitCount = getDigitCount(maxNumber);
        // System.out.println("Digit Count: " + getDigitCount(maxNumber));

        // An outer loop for all the digits.
        for(int place=0; place<digitCount; place++){
            // System.out.println("Place: " + (place+1));
            // Place each element in the Linked List.
            for(int j=0; j<nElems; j++){
                int element = array[j]; // Element in array at that index.
                int digitAtPlace = (element/(int)Math.pow(10,place)) % (10);
                // System.out.println("element: " + element + " digit at place: " + digitAtPlace);
                tempList[digitAtPlace].insert(element);
            }

            // Now add the sorted elements to the array.
            int count = 0;
            while(count < nElems){
                for(int i = 0; i<10; i++){
                    while(!tempList[i].isEmpty()){
                        array[count] = tempList[i].delete().data;
                        count++;
                    }
                }
            }
            // for(int i = 0; i<10; i++){
            //     tempList[i].display();
            // }
            // break;

        }
    }

}

class RadixSort{
    public static void main(String[] args) {
        int nElems = 10;
        Random random = new Random();
        RadixSortClass rSortClass = new RadixSortClass(nElems);
        // rSortClass.insert(15);
        for(int i = 0; i<nElems; i++){
            rSortClass.insert(random.nextInt(100));
        }
        rSortClass.display();
        System.out.println("Sorting now...");
        rSortClass.sort();
        System.out.println("Sorted!!!");
        rSortClass.display();

    }
}