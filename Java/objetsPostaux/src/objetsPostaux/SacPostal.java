package objetsPostaux;

import java.util.Vector;

public class SacPostal {

	private float capacite;
	private Vector<ObjetPostal> objets;
	
	public SacPostal(){
		capacite = 0.5F;
		objets = new Vector<ObjetPostal>();
	}
	public SacPostal(float cap){
		capacite = cap;
		objets = new Vector<ObjetPostal>();
	}
	
	public float getCapacite(){
		return capacite;
	}
	
	public float getVolume(){
		float v =0.F;
		for(ObjetPostal o : objets){
			v+= o.getVolume();
		}
		return v;
	}
	
	public boolean ajoute(ObjetPostal o){
		if(getVolume()<getCapacite()){
			objets.add(o);
			return true;
		}
		else
			return false;
	}
	
	public SacPostal extraireV1(String cp){
		SacPostal s = new SacPostal(this.getCapacite());
		for(ObjetPostal o : objets){
			if(o.getCodePostal().equals(cp))
				s.ajoute(o);
		}
		this.objets.removeAll(s.objets);
		return s;
	}
	
	public float valeurRemboursement(){
		float r = 0.F;
		for(ObjetPostal o : objets){
			r+= o.tarifRemboursement();
		}
		return r;
	}
	
	public String toString(){
		String res = "Le sac contient ";
		int nbO = objets.size();
		res+= nbO+" objet(s), pour un volume total de ";
		float vol = getVolume();
		float val = valeurRemboursement();
		res+= vol+" m3 et une valeur de remboursement de "+val+"€.\n";
		return res;
		
	}
}
