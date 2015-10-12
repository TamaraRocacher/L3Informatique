package cercleSportif;
import java.util.Vector;


public class Cours {
    private String id;
    private int debH;
    private int debM;
    private int finH;
    private int finM;
    private Vector<Equipement> equipRequis;
    private Vector<Adherent> participants;
    private Moniteur ens;
    private Discipline dis;
    private Lieu l;

    public Cours(String id, int dH, int dM, int fH, int fM, Moniteur m, Discipline d) {
	this.id = id;
	debH = dH;
	debM = dM;
	finH = fH;
	finM = fM;
	equipRequis = new Vector<Equipement>();
	participants = new Vector<Adherent>();
	ens = m;

	dis = d;
	dis.ajoutCours(this);
    }

    public void ajoutEquipement(Equipement e) {
	equipRequis.addElement(e);
    }

    public void ajoutParticipants(Adherent a) {
	participants.addElement(a);
    }

    public Vector<Equipement> getEqRequis() {
	return equipRequis;
    }
    
    public String toString() {
	String s = "Le cours commence à "+debH+":"+debM+" et fini à "+finH+":"+finM+".\n";
	s+="Le moniteur est "+ens+"\n";
	s+="Les participants sont :\n";
	for(int i = 0; i<participants.size();i++) {
	    s+="\t"+participants.elementAt(i);
	    s+="\n";
	}
	return s;
    }

    public void ajoutLieu(Lieu li) {
	int i = 0;
	for(i = 0; i<equipRequis.size(); i++) {
	    if(!li.getEq().contains(equipRequis.elementAt(i))){
		break;
	    }
	}
	if(i <equipRequis.size()) {
	    System.out.println("Le lieu ne correspond pas à la discipline enseignée");
	}
	else {
	    l = li;
	}
    }

    
}
