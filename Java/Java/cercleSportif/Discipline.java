package cercleSportif;
import java.util.Vector;

public class Discipline {
    private String nom;
    private Vector<Moniteur> listeEns;
    private Vector<Cours> vCours;

    public Discipline(String n) {
	nom = n;
	listeEns = new Vector<Moniteur>();
	vCours = new Vector<Cours>();
    }
    public void ajoutMoniteur(Moniteur m) {
	listeEns.addElement(m);
    }
    public void ajoutCours(Cours c) {
	vCours.addElement(c);
    }
}
