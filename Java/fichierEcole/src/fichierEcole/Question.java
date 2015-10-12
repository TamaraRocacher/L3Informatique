package fichierEcole;

public class Question extends DocumentAFN {
	protected String enonce;
	protected int tpRepE;
	
	public Question() {
		
	}
	
	public Question(Fourchette niveaux) {
		super(niveaux);
	}

	public Question(String enonce, int tpRepE) {
		super();
		this.enonce = enonce;
		this.tpRepE = tpRepE;
	}

	public Question(Fourchette niveaux, String enonce, int tpRepE) {
		super(niveaux);
		this.enonce = enonce;
		this.tpRepE = tpRepE;
	}
	
	@Override
	public String toString() {
		return "Question [enonce=" + enonce + ", tpRepE=" + tpRepE + "]";
	}

	public int getTpRepE() {
		return tpRepE;
	}
	public void setTpRepE(int tpRepE) {
		this.tpRepE = tpRepE;
	}
	public String getEnonce() {
		return enonce;
	}
	public void setEnonce(String enonce) {
		this.enonce = enonce;
	}
}
