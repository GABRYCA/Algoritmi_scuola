package Coda;

public class Coda {

    private Nodo head;
    private Nodo tail;

    public Coda(){
        this.head = null;
        this.tail = null;
    }

    public boolean isEmpty(){
        return head == null;
    }

    public int size(){
        int count = 0;
        for (Nodo x = head; x != null; x = x.next) {
            count++;
        }
        return count;
    }

    public void enqueue(Object item){
        Nodo oldTail = tail;
        tail = new Nodo();
        tail.item = item;
        tail.next = null;
        if (isEmpty()) {
            head = tail;
        } else {
            oldTail.next = tail;
        }
    }

    public Object dequeue(){
        if (isEmpty()) return -1;
        Object item = head.item;
        head = head.next;
        if (isEmpty()) {
            tail = null;
        }
        return item;
    }

    public Object front(){
        if (isEmpty()) return null;
        return head.item;
    }

    public void print(){
        if (isEmpty()){
            System.out.println("Coda vuota.");
        } else {
            for (Nodo x = head; x != null; x = x.next) {
                System.out.print(x.item + " ");
            }
            System.out.println();
        }
    }

    public boolean contains(Object item){
        for (Nodo x = head; x != null; x = x.next) {
            if (x.item.equals(item)) {
                return true;
            }
        }
        return false;
    }

    @Override
    public String toString(){
        StringBuilder s = new StringBuilder();
        for (Nodo x = head; x != null; x = x.next) {
            s.append(x.item).append(" ");
        }
        return "Coda{" + "item=" + s.toString() + "}";
    }
}