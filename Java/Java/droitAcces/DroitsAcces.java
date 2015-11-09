package droitAcces;

public class DroitsAcces {
    private Vector<TypeDroit> vD;
    private Machine m;
    private Utilisateur u;

    public DroitsAcces(Machine m, Utilisateur u) {
	vD = new Vector<TypeDroit>();
    }
}
