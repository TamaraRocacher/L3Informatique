package bibliotheque;
import java.util.Vector;

public class Exemplaire {
    private Livre ref;
    private boolean estDispo;

    public Exemplaire() 
    {
	ref = null;
	estDispo = true;
    }
    public Exemplaire(Livre l) 
    {
	ref = l;
	estDispo = true;
	if(ref != null) {
	    ref.addExemplaire(this);
	}
    }
   
    public void setReference(Livre l) {
	ref = l;
    }

    public void rendreDisponible() {
	estDispo = true;
    }

    public void rendreIndisponible() {
	estDispo = false;
    }
    public boolean getDispo() {
	return estDispo;
    }
    
    public String toString() {
	String s = ref.getTitre();
	return s;
    }
}
