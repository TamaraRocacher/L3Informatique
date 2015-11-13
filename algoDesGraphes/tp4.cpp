#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <ctime>

using namespace std;

void pointrandom(int n, int point[][2]){

  for(int i=0; i<n;i++){
    point[i][0]=rand()%611;
    point[i][1]=rand()%791;
  }
}

void voisins(int n, int dmax, int point[][2], vector<int> voisin[]){

  for( int i=0; i<n-1; i++){
    for(int j=i+1; j<n;j++){
      if((point[i][0]-point[j][0])*(point[i][0]-point[j][0])+(point[i][1]-point[j][1])*(point[i][1]-point[j][1])<=dmax*dmax){
	voisin[i].push_back(j);
	voisin[j].push_back(i);
	cout<<"arete: "<<i<<"-"<<j<<endl;
      }
    }
  }
}


void AffichageGraphique(int n, int point[][2], vector<int> voisin[])       // Cree le fichier Exemple.ps qui affiche
                                 // les points et l'arbre de Kruskal.
{ofstream output;                           
 output.open("Dijkstra.ps",ios::out);
 output << "%!PS-Adobe-3.0" << endl;
 output << "%%BoundingBox: 0 0 612 792" << endl;
 output << endl;  
 for(int i=0;i<n;i++)
   {output << point[i][0] << " " << point[i][1] << " 3 0 360 arc" <<endl;
     output << ((double)rand()/(RAND_MAX))<<" "<<((double)rand()/(RAND_MAX))<<" "<<((double)rand()/(RAND_MAX))<<" setrgbcolor" <<endl;
   output << "fill" <<endl;
   output << "stroke"<<endl;
   output << endl;
   }
 for(int i=0;i<n-1;i++)
   {for(int j=0;j<voisin[i].size();j++){
       output <<((double)rand()/(RAND_MAX))<<" "<<((double)rand()/(RAND_MAX))<<" "<<((double)rand()/(RAND_MAX))<<" setrgbcolor"<< endl;
       output << point[voisin[i].at(j)][0] << " " << point[voisin[i].at(j)][1] //x
	      << " moveto" << endl;
       
       
       output << point[i][0] << " " << point[i][1] //y
	       << " lineto" << endl;
       output << "stroke" << endl;
       output << endl;
     }
   }

 output << "showpage";
 output << endl;
}


int main(){
  srand(time(NULL));
  int n;
  int m;
  cout<< "Entrez le nombre de points:"<<endl;
  cin>> n;
  int dmax =50;
  vector<int> voisin[n];
  int point[n][2];
  int d[n];
  int arbre[n-1][2];
  int pere[n];
  pointrandom(n, point);
  voisins(n,dmax,point,voisin);
  AffichageGraphique(n, point, voisin);

  return 0;
}
  
