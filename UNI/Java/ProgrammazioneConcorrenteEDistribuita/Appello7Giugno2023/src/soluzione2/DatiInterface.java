package soluzione2;

public interface DatiInterface {
	public void aggiungiDato(String key, String info);

	public void eliminaDato(String key);

	public boolean esisteDato(String key);

	public String trovaDato(String key);
}
