package bibliotheque;
import java.util.Vector;

public class Livre {
    private final String ISBN;
    private String titre;
    private String sousTitre;
    private String auteur;
    private Vector<Exemplaire> vEx;
    
    public Livre() {
	ISBN = "";
	titre = "";
	sousTitre = "";
	auteur = "";
	vEx = new Vector<Exemplaire>();
    }
    
    public Livre(String i, String t, String st, String a) {
	ISBN = i;
	titre = t;
	sousTitre = st;
	auteur = a;
	vEx = new Vector<Exemplaire>();
    }
    
    public void addExemplaire(Exemplaire e) {
	if(!vEx.contains(e)) {
	    vEx.addElement(e);
	}
    }

    public void retirerExemplaire(Exemplaire e) {
	if(vEx.contains(e)) {
	    vEx.removeElement(e);
	}
    }
    
    public String getTitre() {
	return titre;
    }
}
