#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Album{
public:
  void CompraSobre(int n_en_sobre);
  void Status(void);
  Album(int n);
  bool esta_lleno();
  int sobres_comprados();
  bool esta_lamina(int lamina);
 
  
private:
  int n_total;
  int n_repetidas;
  int n_en_album;
  int n_sobres_comprados;
  
  int *album;
  int *repetidas;
};

void cambia(Album A, Album B);

bool Album::esta_lamina(int lamina){
  if(album[lamina] == 1){
    return true;
  }
  else{
    return false;
  }
}
void Album::Status(void){
  cout << n_en_album << " "<<n_repetidas << endl;
}

void cambia(Album A, Album B,int lamina){
  bool condicion_a = A.esta_lamina(lamina);
  bool condicion_b = B.esta_lamina(lamina);
 
  if (condicion_a == true && condicion_b == false){
    cout << "esta lamina se puede intercambiar" << endl;
  }
  if (condicion_a == false && condicion_b ==true){
    cout << "esta lamina se puede intercambiar" <<endl;
  }
  else{
    cout << "esta lamina no se puede intercambiar" << endl;
  }
}

			 
void Album::CompraSobre(int n_en_sobre){
  int lamina;
  for(int i=0;i<n_en_sobre;i++){
    lamina = rand()%n_total;
    if(album[lamina]==0){
      album[lamina] = 1;
      n_en_album++;
    }
    else{
      repetidas[lamina] +=1;
      n_repetidas++;
    }
   
  }
  n_sobres_comprados ++;
}

bool Album::esta_lleno(void){
  if(n_total == n_en_album){
    return true;

  }
  else{
    return false;
  }

}

int Album::sobres_comprados(void){
  return n_sobres_comprados;
}


Album::Album(int n){
  album = new int[n];
  repetidas = new int[n];
  n_total = n;
  n_repetidas = 0;
  n_en_album = 0 ;
  n_sobres_comprados = 0;
  for (int i=0;i<n_total;i++){
    album[i] = 0;
    repetidas[i] = 0;
  }
}

int main(){
  srand(time(0));
  Album A(660);
  Album B(660);
  int lamina = 160;
   
  while(!A.esta_lleno()){
    A.CompraSobre(5);
    cambia(A,B,lamina);
  }

  cout << "el numero de sobres comprados para llenar el album fue: " << A.sobres_comprados() << endl;
}




