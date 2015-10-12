package cercleSportif;
import java.util.Vector;

public class Lieu {
    private String nom;
    private Collectivite proprietaire;
    private Vector<Equipement> vE;

    public Lieu() {
	nom = "";
	proprietaire=null;
	vE= new Vector<Equipement>();
    }
    public Lieu(String n, Collectivite p) {
	nom = n;
	proprietaire = p;
    }
    public void ajoutEquipement(Equipement e) {
	vE.addElement(e);
    }
    public Vector<Equipement> getEq() {
	return vE;
    }
}
