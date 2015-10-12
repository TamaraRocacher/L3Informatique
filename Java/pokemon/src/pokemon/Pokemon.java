package pokemon;

public abstract class Pokemon {
	private String nom;
	private int poids;
	
	public Pokemon(String n, int p){
		nom=n;
		poids=p;
	}

	public abstract float vitesse();
	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public int getPoids() {
		return poids;
	}

	public void setPoids(int poids) {
		this.poids = poids;
	}
	public String toString(){
		return "Je suis le pokemon "+nom+", mon poids est de "+poids+"kg, ma vitesse est de "+vitesse()+" km/h";
	}
}
