#include<iostream>
#include<algorithm>
using namespace std;

//examen parcial 1 de Analisis y Diseño de Algoritmos
//por Daniel Alejandro Vazquez Valadez 614331 


//problema: identificar los IDs que se repiten en dos arreglos y contar cuantos identificadores no se hayan repetido

int main(){
    int m=1,n=1; 
    while(m!=0 && n!=0){
    cin>>m>>n;
    int identificadores[m+n], cantrepetidos=0,repetidos[n+m],sinconflictos=0;
    bool banderarepetidos=true;

    for(int i=0; i< n+m; i++){
        cin>>identificadores[i];
    }

    for(int i=0; i<n+m; i++){
        for(int j=i+1;j<n+m; j++){ 
            if(identificadores[i] == identificadores[j] && identificadores[i] != -1 && identificadores[j] != -1){
                identificadores[j]=-1;
                sinconflictos= sinconflictos+2;
                for(int k=0; k<cantrepetidos; k++){
                    if(repetidos[k]==identificadores[i]){
                        banderarepetidos=false;
                        sinconflictos--;
                    }
                }
                if(banderarepetidos==true){
                repetidos[cantrepetidos]=identificadores[i];
                cantrepetidos++;
                }
                else{
                banderarepetidos = true;
                }
            }
        }
    }
    sort(repetidos,repetidos+cantrepetidos); 
    if(m==0 && n==0){ 
        break;
    }
    for(int i=0; i<cantrepetidos; i++){
        cout<<repetidos[i] << " ";
    }

    if(cantrepetidos == 0){
        cout<<": )";
        cout<<endl<<(n+m) - sinconflictos<<endl;
        
    } 
    else{ 
        cout<<endl<<(n+m) - sinconflictos<<endl;
    }
    sinconflictos=0;
    cantrepetidos=0;
    }
    return 0;
}