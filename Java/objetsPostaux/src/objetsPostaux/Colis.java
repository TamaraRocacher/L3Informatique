package objetsPostaux;

public class Colis extends ObjetPostal {
	
	private String contenu;
	private float valeur;
	
	public Colis(){
		contenu ="";
		valeur = 0.F;
	}	
	
	public Colis(String origine, String destination, String codePostal,
			float poids, float volume, int txRecommandation, String c, float val) {
		super(origine, destination, codePostal, poids, volume, txRecommandation);
		contenu = c;
		valeur = val;
	}

	public String getContenu() {
		return contenu;
	}

	public void setContenu(String contenu) {
		this.contenu = contenu;
	}

	public float getValeur() {
		return valeur;
	}

	public void setValeur(float valeur) {
		this.valeur = valeur;
	}

	@Override
	public float getTarifBase() {
		
		return 2.F;
	}

	@Override
	public float tarifRemboursement() {
		if (getTxRecommandation()==0)
			return 0;
		else if(getTxRecommandation()==1)
			return (getValeur()*10)/100;
		else
			return (getValeur()*50)/100;
	}

	public float tarifAffranchissement(){
		float sup = 0.F;
		if (getVolume()>(1/8))
			sup = 3.F;
		return super.tarifAffranchissement()+sup;
	}
	
	public String toString(){
		return super.toString()+"/"+getVolume()+"/"+getValeur();
	}
	
	@Override
	public String nomObjetPostal() {
		return "Colis";
	}

}
