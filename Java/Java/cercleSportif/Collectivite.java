package cercleSportif;
import java.util.Vector;

public class Collectivite {
    private String nom;
    private boolean prive;
    private Vector<Lieu> vL;

    public Collectivite(){
	nom="Mairie des bisounours";
	prive=false;
	vL = new Vector<Lieu>();
    }
    
    public Collectivite(String n, boolean p) {
	nom=n;
	prive=p;
	vL = new Vector<Lieu>();
    }

    public void ajoutLieu(Lieu l) {
	vL.addElement(l);
    }
}
