package fileAttente;

public class FileAttentePrio<A extends ElementAvecPriorite> extends FileAttente<A>{
	public A sort(){
		A a = null;
		if(!contenu.isEmpty()){
			for(int i= 0;i<contenu.size();i++){
				if (contenu.get(i).priorite()==1){
					a=contenu.get(i);
					contenu.remove(i);
					return a;
				}
			}
			for(int i= 0;i<contenu.size();i++){
				if (contenu.get(i).priorite()==2){
					a=contenu.get(i);
					contenu.remove(i);
					return a;
				}
			}
			a=contenu.get(0);
			contenu.remove(0);
		}
		return a;
	}
}
