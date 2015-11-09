package cercleSportif;
import java.util.Vector;

public class CercleSportif {
    public static void main(String[] args) {
	CercleSportif cercle = new CercleSportif();
	Moniteur m1= new Moniteur("Gertrude","Bertrand");
	Moniteur m2= new Moniteur("Barnabet","Menfou");

	Adherent a1 = new Adherent("Essig","Meryll",20,666);
	Adherent a2 = new Adherent("Rocacher","Tamara",23,7255);
	Adherent a3 = new Adherent("Sainte-Rose","Coraline",21,86916398);
	Adherent a4 = new Adherent("Condamy","Maïlys",19,7964);
	Adherent a5 = new Adherent("Zob","Wassim",26,68612);
	Adherent a6 = new Adherent("Zgeg","Michel",70,54696);

	Discipline d = new Discipline("Natation");
	Cours c = new Cours("Natation 1", 15,00,18,00,m1,d);
	Cours c2 = new Cours("Natation 2", 15,00,18,00,m2,d);

	c.ajoutParticipants(a2);
	c.ajoutParticipants(a3);
	c.ajoutParticipants(a4);
	c.ajoutParticipants(a5);

	c2.ajoutParticipants(a1);
	c2.ajoutParticipants(a6);

	System.out.println(c2);
    }

    private String nom;
    private Vector<Moniteur> pers;
    private Vector<Adherent> inscrits;
    private Vector<Lieu> lieux;

    public CercleSportif() {
	nom="Null";
	pers = new Vector<Moniteur>();
	inscrits = new Vector<Adherent>();
	lieux = new Vector<Lieu>();
    }

    public void inscrire(Adherent a) {
	if(a.getPaye()) {
	    inscrits.addElement(a);
	}
    }
}
