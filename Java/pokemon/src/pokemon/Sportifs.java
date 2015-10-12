package pokemon;

public class Sportifs extends PokemonTerre{
	private int fCard;
	
	public Sportifs(String n, int p,int nbP, float t,int f){
		super(n,p,nbP,t);
		fCard=f;
	}

	public int getfCard() {
		return fCard;
	}

	public void setfCard(int fCard) {
		this.fCard = fCard;
	}
	public String toString(){
		return super.toString()+", ma fréquence cardiaque est de "+fCard+" pulsations à la minute.";
	}
}
