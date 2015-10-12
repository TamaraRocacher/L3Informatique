package fichierEcole;

public class Livre extends DocumentAFN {
	private String titre;
	private int tpLecE;
	
	
	
	public Livre() {
		super();
		// TODO Auto-generated constructor stub
	}

	public Livre(Fourchette niveaux) {
		super(niveaux);
		// TODO Auto-generated constructor stub
	}
	
	public Livre(Fourchette niveaux, String titre, int tpLecE) {
		super(niveaux);
		this.titre = titre;
		this.tpLecE = tpLecE;
	}

	

	@Override
	public String toString() {
		return "Livre [titre=" + titre + ", tpLecE=" + tpLecE + "]";
	}

	public String getTitre() {
		return titre;
	}
	public void setTitre(String titre) {
		this.titre = titre;
	}
	public int getTpLecE() {
		return tpLecE;
	}
	public void setTpLecE(int tpLecE) {
		this.tpLecE = tpLecE;
	}
}
