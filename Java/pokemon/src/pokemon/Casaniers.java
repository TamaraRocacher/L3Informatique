package pokemon;

public class Casaniers extends PokemonTerre{
	private int nbHeureTV;
	
	public Casaniers(String n, int p, int nbP, float t, int nbHtv){
		super(n,p,nbP,t);
		nbHeureTV=nbHtv;
	}

	public int getNbHeureTV() {
		return nbHeureTV;
	}

	public void setNbHeureTV(int nbHeureTV) {
		this.nbHeureTV = nbHeureTV;
	}
	public String toString(){
		return super.toString()+", je regarde la tv "+nbHeureTV+"H par jour.";
	}
}
