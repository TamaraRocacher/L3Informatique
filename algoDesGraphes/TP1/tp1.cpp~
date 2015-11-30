#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

void grapherandom(int n, int m, int edge[][2]){
  srand(time(NULL));
  for( int i =0; i<m;i++){
    edge[i][0]=rand()%n;
    edge[i][1]=rand()%n;
  }
  for(int j=0;j<m;j++){
    cout << "arête "<<j+1<<": "<< edge[j][0]<< "-"<< edge [j][1]<<endl;
  }
}

void composantes(int n, int m, int edge[][2],int comp[]){
  int compI=0,compJ=0; 
  vector<int> sommetsKi;
  vector<int> sommetsKj;
  for(int i=0;i<n;i++){
    comp[i]=i;
  }
  for(int k=0;k<m;k++){
    if(comp[edge[k][0]] != comp[edge[k][1]]){
      cout<<"comp(i)= "<<comp[edge[k][0]]<<"   comp(j)= "<<comp[edge[k][1]]<<endl;
      for(int relect=0;relect<n; relect++){

	if(comp[relect]==comp[edge[k][0]]){// si comp[k]==comp[i]
	  
	  sommetsKi.push_back(relect);//vestor contient les k
	  compJ=comp[edge[k][1]];// et on "retient" comp[j] pour eaffecter

	}
      
	if(comp[relect]==comp[edge[k][1]]){
	  sommetsKj.push_back(relect);	
	  compI=comp[edge[k][0]];
	}
      }
     
    }

 //si comp[i] de taille mini, reaffecter vctorI a compJ
   
      if (sommetsKi.size() <= sommetsKj.size()){
	while(!sommetsKi.empty()){
	  comp[sommetsKi[0]]=compJ;
	  sommetsKi.erase(sommetsKi.begin());
	}
      }
      else{
	while(!sommetsKj.empty()){
	  comp[sommetsKj[0]]=compI;
	  sommetsKj.erase(sommetsKj.begin());
	}
      }
  }
 

  for (int i=0; i<n; i++){
    cout<<"sommet "<<i<<": composante "<<comp[i]<<endl;
  }
}
void ecrituretailles( int n, int m, int comp[]){
  int taillecomp[n]={0}, nbComp[n]={0};

    for(int i;i<n;i++){
      taillecomp[comp[i]]++;
    }
    for (int j=0;j<n;j++){
      nbComp[taillecomp[j]]++;
    }
  cout<<"Il y a "<<nbComp[1]<<" points isolés."<<endl;
  for(int k=2;k<n;k++){
    if(nbComp[k]!=0)
      cout<<"Il y a "<<nbComp[k]<<" composante de taille "<<k<<"."<<endl;
  }
}

int main(){ 
    int n;     // Nombre de sommets.	
    int m;     // Nombre d'aretes.	
    cout << "Entrer le nombre de sommets:";
    cin >> n;
    cout << "Entrer le nombre d'aretes:";
    cin >> m;
    int edge[m][2];    // Tableau des aretes.
    int comp[n];       // comp[i] est le numero de la composante contenant i.
    grapherandom(n,m,edge);
    composantes(n,m,edge,comp);
    ecrituretailles(n,m,comp);




    return 0;
}
