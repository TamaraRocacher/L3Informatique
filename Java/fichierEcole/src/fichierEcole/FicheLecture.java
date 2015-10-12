package fichierEcole;

import java.util.Vector;

public class FicheLecture {
	Livre livre;
	Vector<Question> quest;
	Niveau niveau;
	
	public FicheLecture() {
		quest = new Vector<Question>();
	}

	public FicheLecture(Livre livre, Niveau niveau) {
		this.livre = livre;
		this.quest = new Vector<Question>();
		this.niveau = niveau;
	}

	@Override
	public String toString() {
		return "FicheLecture [livre=" + livre + ", quest=" + quest
				+ ", niveau=" + niveau + "]";
	}

	public Livre getLivre() {
		return livre;
	}

	public void setLivre(Livre livre) {
		this.livre = livre;
	}

	public Vector<Question> getQuest() {
		return quest;
	}

	public void setQuest(Vector<Question> quest) {
		this.quest = quest;
	}

	public Niveau getNiveau() {
		return niveau;
	}

	public void setNiveau(Niveau niveau) {
		this.niveau = niveau;
	}
	
	
	
}
