package bibliotheque;
import java.util.Vector;

public class Bibliotheque {
    private Vector<Exemplaire> vCat; //Catalogue
    private Vector<Abonne> vA;

    public static void main(String[] args) {
	Bibliotheque b = new Bibliotheque();
	
	Abonne a1 = new Abonne(1, "Tamara");
	Abonne a2 = new Abonne(2, "Henry");
	Abonne a3 = new Abonne(3, "Jacquie");

	Livre l1 = new Livre("948-484-545-1515", "Lol", "lolilol", "Sacha Guitry");
	Livre l2 = new Livre("949-848-646-5644", "La Désencyclopédie", "", "Louis");
	Livre l3 = new Livre("884-458-813-5411", "Martine à la plage", "", "Henri Dès");

	Exemplaire e1 = new Exemplaire(l1);

	Exemplaire e2 = new Exemplaire(l2);
	Exemplaire e3 = new Exemplaire(l2);
	Exemplaire e4 = new Exemplaire(l2);

	Exemplaire e5 = new Exemplaire(l3);
	Exemplaire e6 = new Exemplaire(l3);
	

	b.ajouterExemplaire(e1);
	b.ajouterExemplaire(e2);
	b.ajouterExemplaire(e3);
	b.ajouterExemplaire(e4);
	b.ajouterExemplaire(e5);
	b.ajouterExemplaire(e6);

	a1.emprunter(e5);
	a2.emprunter(e5);
	a1.rendre(e5);
    }

    public Bibliotheque() {
	vCat = new Vector<Exemplaire>();
	vA = new Vector<Abonne>();
    }

    public void ajouterExemplaire(Exemplaire e) {
	vCat.addElement(e);
    }

    
    public void retirerDuCatalogue(Exemplaire e) {
	while(vCat.contains(e)){
	    vCat.removeElement(e);
	}
    }
    
    public void ajouterAbonne(Abonne a) {
	vA.add(a);
    }
    
}
