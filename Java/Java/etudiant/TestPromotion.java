package etudiant;

public class TestPromotion {
    public static void main(String[] args) {

	Promotion p = new Promotion(2005);
	Date d1 = new Date(12,11,1991);
	Date d2 = new Date(25,5,1997);
	
	Etudiant e1 = new Etudiant("Jeanne", 20, d1, true, "France", 5,6,9);
	Etudiant e2 = new Etudiant("Michel", 20, d2, true, "France", 17, 17, 15);

	p.inscrire(e1);
	p.inscrire(e2);
	
	System.out.println(p.getNbEtud());
	System.out.println(p.getEtudiant(1));
	System.out.println(p.recherche("Michel"));
	p.afficheResultat();
    }
}
