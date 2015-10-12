package cercleSportif;
import java.util.Vector;

public class Moniteur {
    private String nom;
    private String prenom;
    private Vector<Discipline> qualif;
    private Vector<Cours> disp;
    
    public Moniteur(String n, String p) {
	nom=n;
	prenom=p;
	qualif = new Vector<Discipline>();
	disp = new Vector<Cours>();

    }

    public String toString() {
	return prenom+" "+ nom;
    }
}
