package bibliotheque;
import java.util.Vector;

public class Abonne {
    private final int id;
    private String nom;
    private Vector<Exemplaire> vEx;

    public Abonne(int i, String n) {
	id = i;
	nom = n;
	vEx = new Vector<Exemplaire>();
    }
    public void emprunter(Exemplaire e) {
	if(vEx.size() < 5 && e.getDispo()) {
	    System.out.println(nom + " a emprunté "+ e);
	    vEx.add(e);
	    e.rendreIndisponible();
	}
	else {
	    System.out.println("Le livre est indisponible");
	}
    }

    public void rendre(Exemplaire e) {
	System.out.println(nom + " a rendu " + e);
	vEx.remove(e);
	e.rendreDisponible();
    }

    public String toString() {
	String s = nom + "possède les livres suivants : \n";
	for(int i = 0; i < vEx.size(); i++) {
	    s+="\t"+vEx.elementAt(i)+"\n";
	}
	return s;
    }
}
