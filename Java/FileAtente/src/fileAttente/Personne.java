package fileAttente;

public class Personne implements ElementAvecPriorite{
	private String nom;
	private int age;

	public Personne(){};
	public Personne (String n, int a){
		nom=n;
		age=a;
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String toString(){
		return nom+" "+age;
	}
	public int priorite(){
		if (this.age >=0 && this.age <13)
			return 1;
		else if(this.age >59)
			return 2;
		else
			return 3;
	}
}
