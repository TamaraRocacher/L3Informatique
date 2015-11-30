package etudiant;

public class Date
{
    private int jour;
    private int mois;
    private int an;
    
    public Date(int j, int m, int a) {
	jour = j;
	mois = m;
	an = a;
    }
    public int getDiff(Date d) {
	if(this.mois < d.mois) {
	    return ((d.an)-(this.an));
	}
        else if (this.mois == d.mois){
	    if (this.jour <= d.jour) {
		return ((d.an)-(this.an));
	    }
	    else {
		return (d.an-this.an-1);
	    }
	}
	else {
	    return (d.an-this.an-1);
	}
    }
}
