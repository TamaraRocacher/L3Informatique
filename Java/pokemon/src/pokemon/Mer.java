package pokemon;

public class Mer extends PokemonEau{
	public Mer(String n, int p, int nbN){
		super(n,p,nbN);
	}
	public float vitesse(){
		return(getPoids()/25*getNbNageoire());
	}
}
