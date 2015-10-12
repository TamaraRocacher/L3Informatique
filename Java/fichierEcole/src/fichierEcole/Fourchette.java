package fichierEcole;

public class Fourchette {
	Niveau nivMin;
	Niveau nivMax;

	public Fourchette(Niveau nivMin, Niveau nivMax) {
		this.nivMin = nivMin;
		this.nivMax = nivMax;
	}

	public Niveau getNivMin() {
		return nivMin;
	}

	public void setNivMin(Niveau nivMin) {
		this.nivMin = nivMin;
	}

	public Niveau getNivMax() {
		return nivMax;
	}

	public void setNivMax(Niveau nivMax) {
		this.nivMax = nivMax;
	}
	
	
	
}
