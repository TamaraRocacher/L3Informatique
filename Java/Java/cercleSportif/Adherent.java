package cercleSportif;
import java.util.Vector;

public class Adherent {
    private String nom;
    private String prenom;
    private int age;
    private int idA;
    private Vector<Cours> listCours;
    private boolean paye;

    public Adherent(String n, String p, int a, int id) {
	nom = n;
	prenom = p;
	age =a;
	idA = id;
	paye = false;
	listCours = new Vector<Cours>();
    }

    public boolean getPaye() {
	return paye;
    }
    public void ajoutCours(Cours c) {
	listCours.addElement(c);
	c.ajoutParticipants(this);
    }

    public String toString() {
	return prenom+" "+nom;
    }
}
