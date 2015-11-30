package etudiant;
import java.util.Vector;

public class Promotion {
    private Vector<Etudiant> vEtudiant;
    private int annee;

    public Promotion() {
	annee = 1900;
	vEtudiant = new Vector<Etudiant>();
    }
    
    public Promotion(int a) {
	annee = a;
	vEtudiant = new Vector<Etudiant>();
    }

    public int getAnnee() {
	return annee;
    }
    public Vector<Etudiant> getEtudiants() {
	return vEtudiant;
    }

    public Etudiant getEtudiant(int i) {
	if(!vEtudiant.isEmpty()) {
	    Etudiant e = vEtudiant.elementAt(i);
	    return e;
	}
	return null;
    }

    public void inscrire(Etudiant e) {
	vEtudiant.addElement(e);
    }
    public int getNbEtud() {
	if(vEtudiant.isEmpty()) {
	    return 0;
	}
	else 
	    return vEtudiant.size();
    }

    public float moy() {
	float m= 0;
	for(int i = 0; i<vEtudiant.size();i++) {
	    m+=vEtudiant.elementAt(i).moy();
	}
	return m/vEtudiant.size();
    }

    public void afficheResultat() {
	for(int i = 0;i<vEtudiant.size();i++) {
	    System.out.println(vEtudiant.elementAt(i).ligneResultat());
	}
    }
    
    public Etudiant recherche(String n) {
	for(int i=0;i<vEtudiant.size();i++) {
	    if(vEtudiant.elementAt(i).getNom()==n)
	       return vEtudiant.elementAt(i);
	}
	System.out.println("Pas de résultat");
	return null;
    }

    public Vector<Etudiant> admis() {
	Vector<Etudiant> vAdmis = new Vector<Etudiant>();
	for(int i = 0; i<vEtudiant.size();i++) {
	    if(vEtudiant.elementAt(i).moy() >= 10) {
		vAdmis.addElement(vEtudiant.elementAt(i));
	    }
	}
	return vAdmis;
    }

    public Vector<Etudiant> nouveauxInscritsNonFrancophone() {
	Vector<Etudiant> v = new Vector<Etudiant>();
	for(int i = 0; i<vEtudiant.size();i++) {
	    if(vEtudiant.elementAt(i).getCodeIns()==true 
	       && vEtudiant.elementAt(i).getCodePays() != "France") {
		v.addElement(vEtudiant.elementAt(i));
	    }
	}
	return v;
    }

    public Vector<Etudiant> majors() {
	Vector<Etudiant> majors = new Vector<Etudiant>();
	float max= 0;
	for(int i =0; i<vEtudiant.size();i++) {
	    if(vEtudiant.elementAt(i).moy()>max) {
		max = vEtudiant.elementAt(i).moy();
	    }
	}
	for(int i = 0;i<vEtudiant.size();i++) {
	    if(vEtudiant.elementAt(i).moy() == max) {
		majors.addElement(vEtudiant.elementAt(i));
	    }
	}
	return majors;
    }
}
