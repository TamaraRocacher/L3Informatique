package fileAttente;


public class Principale {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	
		Personne moi = new Personne("tam",23);
		Personne vieux = new Personne("mamie",65);
		Personne jeune = new Personne("bébé",1);
		FileAttentePrio<Personne> fileP = new FileAttentePrio<Personne>();
		fileP.entre(moi);
		fileP.entre(vieux);
		System.out.println(fileP);
	
		Personne sortie1=fileP.sort();
		System.out.println(sortie1);
		
		fileP.entre(jeune);
		System.out.println(fileP);
		
		Personne sortie2=fileP.sort();
		System.out.println(sortie2);
		
		Personne sortie3=fileP.sort();
		System.out.println(sortie3);
		
		
	}

}
