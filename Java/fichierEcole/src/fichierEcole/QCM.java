package fichierEcole;

import java.util.Vector;

public class QCM extends Question {
	private Vector<String> reponses;
	private Vector<Boolean> repCorrectes;
	
	public QCM(String enonce, int tpRepE) {
		super(enonce, tpRepE);
		reponses = new Vector<String>();
		repCorrectes = new Vector<Boolean>();
	}

	public void addRep(String r,boolean b){
		reponses.addElement(r);
		repCorrectes.addElement(b);
	}
	
	public String toString(){
		String s = "\tQCM\n";
		s+="Enoncé: "+enonce+"\n";
		for (int i=0;i<reponses.size();i++){
			s+="\t"+reponses.elementAt(i);
		}
		s+="\n";
		return s;
	}
}
