class NodoCoda{
	public Object info;
	public NodoCoda next;

	public NodoCoda(Object info, NodoCoda next){
		this.info = info;
		this.next = next;
	}
	public String toString(){
		String q = "";
		if (next != null)
			return q + info +", "+ next;
		else
			return q + info;
	}
}


public class CodaOK{

	public CodaOK(){
		head = null;
		tail = null;
	}

	public boolean is_Empty(){
		return head == null;
	}

	public Object front(){
		if (head == null)
			throw new RuntimeException("front: lista vuota");
		else
			return head.info;
	}

	public void dequeue(){
		if (head == null)
			throw new RuntimeException("dequeue: lista vuota");
		else{
			head = head.next;
			if (head == null)
				tail = null;
		}
	}

	public void enqueue(Object info){
		NodoCoda aux = new NodoCoda(info, null);
		if (head == null)
			head = aux;
		else
			tail.next = aux;
		tail = aux;
	}

/*-------------------------------------------*/

	public String toString(){
		String q = "";
		if (head == null)
			return "<<";
		else
			return "<" + head + "<";
	}


/*--------------------------------------------------------------------*/
	private NodoCoda head;
	private NodoCoda tail;
}
