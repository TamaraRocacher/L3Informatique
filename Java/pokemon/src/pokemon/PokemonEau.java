package pokemon;

public abstract class PokemonEau extends Pokemon{
	private int nbNageoire;
	
	public PokemonEau(String n, int p, int nbN){
		super(n,p);
		nbNageoire=nbN;
	}

	public int getNbNageoire() {
		return nbNageoire;
	}

	public void setNbNageoire(int nbNageoire) {
		this.nbNageoire = nbNageoire;
	}
	public String toString(){
		return super.toString()+", j'ai "+nbNageoire+" nageoires.";
				
	}
}
