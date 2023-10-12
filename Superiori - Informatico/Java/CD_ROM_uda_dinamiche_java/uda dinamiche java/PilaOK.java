class NodoPila{
	public Object info;
	public NodoPila next;

	public NodoPila(Object info, NodoPila next){
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


public class PilaOK{

	public PilaOK(){
		l = null;
	}

	public boolean is_Empty(){
		return l == null;
	}

	public Object top(){
		if (l == null)
			throw new RuntimeException("top: lista vuota");
		else
			return l.info;
	}

	public void pop(){
		if (l == null)
			throw new RuntimeException("pop: lista vuota");
		else
			l = l.next;
	}

	public void push(Object info){
		l = new NodoPila(info, l);
	}

/*-------------------------------------------*/

	public String toString(){
		String q = "";
		if (l == null)
			return ">|";
		else
			return ">" + l + "|";
	}


/*--------------------------------------------------------------------*/
	private NodoPila l;
}
