package objetsPostaux;

public abstract class ObjetPostal {

	private String origine;
	private String destination;
	private String codePostal;
	private float poids;
	private float volume;
	private int txRecommandation;
	private SacPostal sac;
	
	public ObjetPostal(){
		origine = "";
		destination = "";
		codePostal = "";
		poids = 0.F;
		volume = 0.F;
		txRecommandation = 0;
		sac = null;
	}
	
	
	
	public ObjetPostal(String origine, String destination, String codePostal,
			float poids, float volume, int txRecommandation) {
		this.origine = origine;
		this.destination = destination;
		this.codePostal = codePostal;
		this.poids = poids;
		this.volume = volume;
		this.txRecommandation = txRecommandation;
	}



	public String getOrigine() {
		return origine;
	}



	public void setOrigine(String origine) {
		this.origine = origine;
	}



	public String getDestination() {
		return destination;
	}



	public void setDestination(String destination) {
		this.destination = destination;
	}



	public String getCodePostal() {
		return codePostal;
	}



	public void setCodePostal(String codePostal) {
		this.codePostal = codePostal;
	}



	public float getPoids() {
		return poids;
	}



	public void setPoids(float poids) {
		this.poids = poids;
	}



	public float getVolume() {
		return volume;
	}



	public void setVolume(float volume) {
		this.volume = volume;
	}



	public int getTxRecommandation() {
		return txRecommandation;
	}



	public void setTxRecommandation(int txRecommandation) {
		this.txRecommandation = txRecommandation;
	}



	/*public static void main(String[] args) {
		Lettre l = new Lettre("ici","la-bas","CP",10.F,0.1F,2,false);
		Colis c = new Colis ("Laponie","Montpellier","34000",10.F,0.5F,1,"surprise",100.F);
		System.out.println(c);
		SacPostal sac1 = new SacPostal();
		sac1.ajouter(l);
		sac1.ajouter(c);
		System.out.println(sac1);
		SacPostal sac2 = new SacPostal();
		sac2 = sac1.extraire("34000");
		System.out.println("sac1 :\n");
		System.out.println(sac1);
		System.out.println("sac2 :\n");
		System.out.println(sac2);
		

	}*/

	public abstract float getTarifBase();
	
	public abstract float tarifRemboursement();
	
	public float tarifAffranchissement(){
		float x =0.F;
		if (getTxRecommandation()==1)
			x = 0.5F;
		else if (getTxRecommandation()==2)
			x=1.5F;
		 return getTarifBase()+x;
	}
	
	public String toString(){
		String r= nomObjetPostal()+" "+getCodePostal()+"/"+getDestination()+"/"+getTxRecommandation();
		return r;
	}
	
	public abstract String nomObjetPostal();
}
