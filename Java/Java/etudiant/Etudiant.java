package etudiant;

public class Etudiant 
{
    /*public static void main(String[] args) 
    {
	Date d = new Date(04,02,2015);
	Date dateNaissance = new Date(04,02,1991);
	Etudiant e = new Etudiant("Tamara", dateNaissance.getDiff(d), dateNaissance, true, "Fr", 11,11,4);
	System.out.println(e.toString());
    }*/

    private String nom;
    private int age;
    private Date date;
    private boolean codeIns;
    private String codePays;
    private float noteA;
    private float noteB;
    private float noteC;

    public Etudiant(String name,int age, Date date, boolean ins, String pays, float A, float B, float C) {
	nom = name;
	this.age = age;
        this.date = date;
	codeIns = ins;
	codePays = pays;
	noteA = A;
	noteB = B;
	noteC = C;
    }

    public String getNom() {
	return nom;
    }
    public int getAge() {
	return age;
    }

    public String getCodePays() {
	return codePays;
    }
    public void setAge(int a) {
	age = a;
    }
    public float getNoteA() {
	return noteA;
    }
    public float getNoteB() {
	return noteB;
    }
    public float getNoteC() {
	return noteC;
    }

    public void setNoteA(float note) {
	noteA = note;
    }
    public void setNoteB(float note) {
	noteB = note;
    }
    public void setNoteC(float note) {
	noteC = note;
    }
    
    public Date getBirthYear() {
	return date;
    }
    public void setBirthYear(Date a) {
	date = a;
    }

    public boolean getCodeIns() {
	return codeIns;
    }
    public void setCodeIns(boolean code) {
	codeIns = code;
    }

    public float moy() {
	return ((noteA+noteB+noteC)/3);
    }

    public String mention() {
	if(moy() >= 16)
	    return "Très bien";
	else if(moy() >=14)
	    return "Bien";
	else if(moy() >=12)
	    return "Assez bien";
	else
	    return "Pas de mention";
    }
    
    public String ligneResultat() {
	String s = new String();
	s+=nom+" a eu "+moy()+" de moyenne et la mention "+mention();

	if(moy()<10 && (noteA>=10||noteB>=10||noteC>=10)) {
	s+="\n Les notes obtenues sont : \n";
	    if(noteA>=10)
		s+="noteA\n";
	    if(noteB>=10)
		s+="noteB\n";
	    if(noteC>=10)
		s+="noteC\n";
	}
	return s;
    }
    public String toString() {
	String a = new String();
	if(moy() <10) {
	    a="UE obtenues : \n";
	    if(noteA>10)
		a+="noteA ";
	    if(noteB>10)
		a+="noteB ";
	    
	}
	a+=".";
	return (nom + "\nAge : "+age+"\nMention : "+mention()+"\n" +a);
    }
}
