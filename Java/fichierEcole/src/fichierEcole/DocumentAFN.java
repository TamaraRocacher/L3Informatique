package fichierEcole;

import java.util.Scanner;

public class DocumentAFN {
	Fourchette niveaux;

	
	
	public DocumentAFN() {
		
	}

	public DocumentAFN(Fourchette niveaux) {
		this.niveaux = niveaux;
	}

	public Fourchette getNiveaux() {
		return niveaux;
	}

	public void setNiveaux(Fourchette niveaux) {
		this.niveaux = niveaux;
	}
	
	
}
