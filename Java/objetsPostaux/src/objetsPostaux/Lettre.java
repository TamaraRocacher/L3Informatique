package objetsPostaux;

public class Lettre extends ObjetPostal {

	private boolean urgence;
	
	public Lettre(){
		urgence = false;
	}
	
	
	
	public Lettre(String origine, String destination, String codePostal,
			float poids, float volume, int txRecommandation, boolean u) {
		super(origine, destination, codePostal, poids, volume, txRecommandation);
		urgence = u;
	}

	public boolean isUrgence(){
		return urgence;
	}

	public void setUrgence(boolean u){
		urgence = u;
	}
	
	public float tarifRemboursement(){
		if (getTxRecommandation()==0)
			return 0.F;
		else if (getTxRecommandation()==1)
			return 1.5F;
		else
			return 15.F;
	}
	
	@Override
	public float getTarifBase() {
		return 0.5F;
	}

	
	public float tarifAffranchissement() {
		float ur=0;
		if (isUrgence())
			ur=0.3F;
		return super.tarifAffranchissement()+ur;
	}

	public String toString(){
		String urg="ordinaire";
		if(isUrgence())
			urg="urgence";
		return super.toString()+"/"+urg;
	}
	
	@Override
	public String nomObjetPostal() {
		return "Lettre";
	}

}
