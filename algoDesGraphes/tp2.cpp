#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

void pointrandom(int n, int point[][2]){
  srand(time(NULL));
  for(int i=0; i<n;i++){
    point[i][0]=rand()%612;
    point[i][1]=rand()%792;
  }
}

void distances(int n, int m, int point[][2], int edge[][3]){
  int k=0;
  for(int i=0;i<n-1;i++){
    for(int j=0;j<i+1;j++){
      edge[k][0]=i;
      edge[k][1]=j;
      edge[k][2]=(point[i][0]-point[j][0])*(point[i][0]-point[j][0])+(point[i][1]-point[j][1])*(point[i][1]-point[j][1]);
      k++;
    }
  }
}

void tri (int m, int edge[][3]){
  int i=0,tmp=0;
  for (int j=0;i<m;j++){
    while(i < m){
      if(edge[i][2]>edge[i+1][2]){
	tmp=edge[i][2];
	edge[i][2]=edge[i+1][2];
	edge[i+1][2]=tmp;
      }
      i++;
    }
  }
}

void kruskal(int n,int m, int edge[][3], int arbre[][2]){
  int comp[n];
  int compI=0,compJ=0; 
  int compt=0;
  vector<int> sommetsKi;
  vector<int> sommetsKj;
  for(int i=0;i<n;i++){
    comp[i]=i;
  }
  for(int k=0;k<m;k++){
    if(comp[edge[k][0]] != comp[edge[k][1]]){
      arbre[compt][0]=edge[k][0];
      arbre[compt][1]=edge[k][1];
      compt++;
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

void AffichageGraphique(int n, int point[][2], int arbre[][2])       // Cree le fichier Exemple.ps qui affiche
                                 // les points et l'arbre de Kruskal.
{ofstream output;                           
 output.open("Exemple.ps",ios::out);
 output << "%!PS-Adobe-3.0" << endl;
 output << "%%BoundingBox: 0 0 612 792" << endl;
 output << endl;  
 for(int i=0;i<n;i++)
   {output << point[i][0] << " " << point[i][1] << " 3 0 360 arc" <<endl;
   output << "0 setgray" <<endl;
   output << "fill" <<endl;
   output << "stroke"<<endl;
   output << endl;
   }
 output << endl;
 for(int i=0;i<n-1;i++)
   {output << point[arbre[i][0]][0] << " " << point[arbre[i][0]][1] 
	   << " moveto" << endl;
   output << point[arbre[i][1]][0] << " " << point[arbre[i][1]][1] 
	  << " lineto" << endl;
   output << "stroke" << endl;
   output << endl;
   }
 output << "showpage";
 output << endl;
}

int main(){
  int n;
  cout<< "Entrez le nombre de points:"<<endl;
  cin>> n;
  int m=n*(n-1)/2; // nb d'aretes max
  int point[n][2]; // coordonnées des points dans le plan
  int edge[m][3]; // aretes(paires de pt) et carre des longueur
  int arbre[n-1][2]; // aretes de l'arbre de Kruskal

  pointrandom(n,point);
  distances(n,m,point,edge);
  tri(n,edge);
  kruskal(n,m,edge,arbre);
  AffichageGraphique(n,point,arbre);
  return 0;
}
