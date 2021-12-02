// H. Daniel Martinez A01177464
// Joaquín Aguirre A01177479
// Janet Espronceda A01197814

//Act 5.2 - Actividad Integral sobre el uso de códigos hash (Evidencia Competencia)

// Headers
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
using namespace std;

long convertIpToNumber(string ip)
{
    char c;
    int idx = 0;
    c = ip[idx];

    unsigned int integer;
    int val;
    int i, j = 0;
    for (j = 0; j < 4; j++)
    {
        if (!isdigit(c))
        { //first char is 0
            return (0);
        }
        val = 0;
        for (i = 0; i < 3; i++)
        {
            if (isdigit(c))
            {
                val = (val * 10) + (c - '0');
                c = ip[++idx];
            }
            else
                break;
        }
        if (val < 0 || val > 255)
        {
            return (0);
        }
        if (c == '.')
        {
            integer = (integer << 8) | val;
            c = ip[++idx];
        }
        else if (j == 3 && c == '\0')
        {
            integer = (integer << 8) | val;
            break;
        }
    }
    if (c != '\0')
    {
        return (0);
    }
    return integer;
}

string getOnlyIpPart(string ipAndPort)
{
    int portPosition = ipAndPort.find_first_of(':');
    string ip = ipAndPort.substr(0, portPosition);
    return ip;
}

// Struct para guardar los atributos de los logs de la bitacora
struct patron
{
    long key;
    string mes, hora, ip, concepto;
    int dia;

    bool operator<(const patron &atr) const
    {
        return (key < atr.key);
    }
};

// Función para crear la llave unica para cada entrada en la bitacora
long fechaANumero(string mes, int diab)
{
  long numMes;

  if(mes == "Jun"){
    numMes = 0;
  }
  else if(mes == "Jul"){
    numMes = 30;
  }
  else if(mes == "Aug"){
    numMes = 60;
  }
  else if(mes == "Sep"){
    numMes = 90;
  }
  else if (mes == "Oct"){
    numMes = 120;
  }

  long representacion = numMes + diab;
  return representacion;
}

// Orden Merge
// Complejidad: O(n log(n))
void unir(vector<patron> &vec, vector<patron> &aux, int ini, int fin){
  int m = (ini + fin) / 2;
  int i=ini, j = m + 1, k=ini;

  while (i<=m && j<=fin){
    if (vec[i].key <= vec[j].key){
      aux[k++] = vec[i++];
    }
    else{
      aux[k++] = vec[j++];
    }
  }
  
  while (i<=m){
    aux[k++] = vec[i++];
  }

  while (j<=fin){
    aux[k++] = vec[j++];
  }

  for (int z = ini; z<=fin; z++){
    vec[z] = aux[z];
  }
}

void ordenaMerge(vector<patron> &vec, vector<patron> &aux, int ini, int fin){
  if (ini < fin){
    int m = (ini + fin) / 2;
    ordenaMerge(vec, aux, ini, m);
    ordenaMerge(vec, aux, m+1, fin);
    unir(vec, aux, ini, fin);
  }
}

int main() {
  vector<patron> atributos;
  string mes, hora, ip, descripcion;
  int diab, n;
  long ipKey;
	n = 0;

  // 1. Leyendo archivo de entrada
  ifstream inputBitacora("bitacora-5_2.txt"); 
  // Mientras se pueda leer cada atributo (excepto descripción)
  while (inputBitacora >> mes >> diab >> hora >> ip)
  {
    // leer atributo
    getline(inputBitacora, descripcion);

    // crear la estructura
    patron atr;
    atr.mes = mes;
    atr.dia = diab;
    atr.hora = hora;
    atr.ip = ip;
    atr.concepto = descripcion;
    atr.key = fechaANumero(mes, diab);

    // almacenarla en vector
    atributos.push_back(atr);

    n++;
  }

  vector<patron> listaAux(n);
  
  // TODO: 2. Ordenar bitacora en memoria
  //Complejidad: O(n log(n))
  ordenaMerge(atributos, listaAux, 0, n);

	vector<patron> registros;
  
	unordered_map<long, vector<patron>> map;
	unordered_map<long, int> mapAccess;

	for (int i = 0; i < n; i++)
	{
		ip = getOnlyIpPart(listaAux[i].ip);
		ipKey = convertIpToNumber(ip);

		mapAccess[ipKey] = mapAccess[ipKey]+1;
		
		map[ipKey].push_back(listaAux[i]);
		
	}

	int continuar = 1;
	string ipUser;
	long ipUserAsNum;

	do
	{
		cout << "Escriba la dirección IP que quiere buscar: ";
		cin >> ipUser;
		cout << endl;
		ipUserAsNum = convertIpToNumber(ipUser);

		if (map.count(ipUserAsNum))
		{
			cout << "Registros de la dirección IP " << ipUser << ": " << endl;
			cout << "Accesos: " << mapAccess[ipUserAsNum] << endl;

			for (int i = 0; i < map[ipUserAsNum].size(); i++)
			{
				cout << map[ipUserAsNum][i].mes << " " << map[ipUserAsNum][i].dia << " " << map[ipUserAsNum][i].hora << " " << map[ipUserAsNum][i].concepto << endl;
			}
		}
		else
		{
			cout << "No se encontró la dirección IP" << endl;
		}
    
    cout << endl;
    cout << "Para buscar de nuevo ingrese un 1: ";
    cin >> continuar;
    cout << endl;
    
	} while (continuar == 1);

  

	
} 