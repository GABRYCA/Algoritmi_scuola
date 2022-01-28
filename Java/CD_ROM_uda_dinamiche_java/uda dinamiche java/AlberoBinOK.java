class NodoBinOK{
  public int info;
  public NodoBinOK sin;
  public NodoBinOK des;

  public NodoBinOK(int info, NodoBinOK sin, NodoBinOK des){
 	this.info = info;
 	this.sin = sin;
 	this.des = des;
  }
	
  public String toString(){
 	String q = "(";
	q += info;
	if (sin != null)
		q += "(" + sin + ")";
	else
		q += "()";
	if (des != null)
		q += "(" + des+ ")";
	else
		q += "()";
	return q + ")";
  }
}


public class AlberoBinOK{
  private NodoBinOK bt;
  public AlberoBinOK(){
		bt = null;
  }

  private AlberoBinOK(NodoBinOK root){
		bt = root;
  }
  	
  public AlberoBinOK(int info, AlberoBinOK sin, AlberoBinOK des){
		bt = new NodoBinOK(info, sin.bt, des.bt);
  }

  public AlberoBinOK(int info){
		bt = new NodoBinOK(info, null, null);
  }

  public boolean is_Empty(){
		return bt == null;
  }

  public int radice(){
	if (bt == null)
		throw new RuntimeException("radice: lista vuota");
	else
		return bt.info;
  }

  public AlberoBinOK sin(){
 	if (bt == null)
	  throw new RuntimeException("pop: lista vuota");
	else
 	 return new AlberoBinOK(bt.sin);
  }
	
  public AlberoBinOK des(){
 	if (bt == null)
  	 throw new RuntimeException("pop: lista vuota");
	else
	  return new AlberoBinOK(bt.des);
  }

  /*-------------------------------------------*/
  public String toString(){
	if (bt == null)
	  return "()";
	else
	  return bt.toString();
  }

  public String visitaInAmpiezza(){
    String s = "";
    CodaOK q = new CodaOK();
	q.enqueue(this);
	while (! q.is_Empty()){
	  AlberoBinOK b = (AlberoBinOK) q.front();
	  q.dequeue();
	  if (!b.is_Empty()){
	    s += b.radice()+" ";
	    q.enqueue(b.sin());
	    q.enqueue(b.des());
	  }
	}
	return s;
  }
	
  public String visitaInProfondita(){
	String s = "";
	PilaOK p = new PilaOK();
	p.push(this);
	while (! p.is_Empty()){
	  AlberoBinOK b = (AlberoBinOK) p.top();
	  p.pop();
	  if (!b.is_Empty()){
	 	s += b.radice()+" ";
		p.push(b.des());
		p.push(b.sin());
	  }
	}
	return s;
  }
}
