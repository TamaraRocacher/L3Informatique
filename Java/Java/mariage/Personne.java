package mariage;


public class Personne {
    private String prenom;
    private String nom;
    private String nomJF=null;
    private Sexe s;
    private Personne conjoint;

    public Personne() {
	nom = null;
	s=Sexe.Unknown;
	conjoint=null;
    }
    public Personne(String unPrenom, String unNom, Sexe s2) {
	prenom = unPrenom;
	nom = unNom;
	s=s2;
	
    }
    public void seMarier(Personne p) {
	if(p.s != s) {
	    this.conjoint = p;
	    p.conjoint = this;
	    if(p.s == Sexe.Femme) {
		p.nomJF = p.nom;
		p.nom = nom;
	    }
	    else {
		nomJF=nom;
		this.nom = p.nom;
	    }
	}
	System.out.println("Par les pouvoirs qui me sont conférés, je vous déclare mari et femme");
    }

    public void divorce() {
	if(conjoint != null) {
	    if(conjoint.s==Sexe.Femme) {
		conjoint.nom=conjoint.nomJF;
		conjoint.nomJF=null;
	    }
	    else {
		nom=nomJF;
		nomJF=null;
	    }
	    this.conjoint.conjoint=null;
	    conjoint = null;
	    System.out.println("Divorce en cours");
	}
    }
    public String toString() {
	String res = prenom+" "+ nom+" ("+s+") ";
	String m,p;
	if(s == Sexe.Femme) {
	    m = "mariée";
	}
	else {
	    m = "marié";
	}
	if(conjoint !=null) {
	    p = " est "+m+" avec "+conjoint.prenom+" "+conjoint.nom+"\n";
	}
	else {
	    p = " n'est pas "+ m+"\n";
	}
	return res+p;
    }
    public static void main(String[] args) {
	Personne p1 = new Personne("Tamara", "Rocacher", Sexe.Femme);
	Personne p2 = new Personne("Peluche", "Peluche", Sexe.Homme);
	System.out.println(p2);
	p1.seMarier(p2);
	System.out.println(p2);

    }
}
