package pokemon;

public class Croisière extends PokemonEau{
	public Croisière(String n, int p, int nbN){
		super(n,p,nbN);
	}
	public float vitesse(){
		return((getPoids()/25*getNbNageoire())/2);
	}
}
