import java.util.ArrayList;
import java.util.Random;

class Link{
    public int data;
    public Link next;

    public Link(int data, Link next){
        this.data = data;
        this.next = next;
    }

    public void displayLink(){
        System.out.println("{" + this.data + "}");
    }
}

class List{

    private Link head;

    public List(){
        this.head = null;
    }

    public boolean isEmpty(){
        return (head==null);
    }

    public void prepend(int data){
        this.head = new Link(data, this.head);
    }

    public void append(int data){
        /*
        Add a link to the end of the list
        */
        // For empty list
        if(this.head == null){
            prepend(data);
        }else{
            Link current = this.head;
            while(current.next != null){ // If the list is empty, the loop won't execute.
                current = current.next;
            }
            current.next = new Link(data, null);
        }
    }

    public Link find(int key){
        /*
        Find the link that has data = key.
        */
        Link current = this.head;
        while(current!=null && current.data != key){
            current = current.next;
        }
        return current;

    }

    public void delete(int key){
        // Get the link that matches the data.
        Link current = this.head;
        Link prev = null;
        while(current != null && current.data != key){
            prev = current;
            current = current.next;
        }
        // The node could be the first.
        if(prev == null){
            this.head = current.next;
        }else if(current!=null){
            prev.next = current.next;
            current.next = null;
        }
    }

    public void displayList(){
        ArrayList<Integer> nodes = new ArrayList<>();

        Link current = head;
        while(current != null){
            nodes.add(current.data);
            // current.displayLink();
            current = current.next;
        }
        System.out.println(nodes);
    }
}

class LinkedList{
    public static void main(String args[]){
        
        Random random = new Random();
        
        List list = new List();
        for(int i = 0; i<10; i++){
            list.append(random.nextInt(100));
        }
        
        list.append(7);
        list.prepend(6);

        list.displayList();
        list.find(6).displayLink();
        list.delete(7);
        list.displayList();
    }
}