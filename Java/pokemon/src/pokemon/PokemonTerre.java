package pokemon;

public abstract class PokemonTerre extends Pokemon{
	private int nbPattes;
	private float taille;
	
	public PokemonTerre(String n, int p, int nbP, float t){
		super(n,p);
		nbPattes=nbP;
		taille=t;
	}
	public float vitesse(){
		return (nbPattes*taille*3);
	}
	public int getNbPattes() {
		return nbPattes;
	}

	public void setNbPattes(int nbPattes) {
		this.nbPattes = nbPattes;
	}

	public float getTaille() {
		return taille;
	}

	public void setTaille(float taille) {
		this.taille = taille;
	}
	public String toString(){
		return super.toString()+",\n j'ai "+nbPattes+" pattes, ma taille est de "+taille+" m";
	}
}
