// H. Daniel Martinez A01177464
// Joaquín Aguirre A01177479
// Janet Espronceda A01197814

/*

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
using namespace std;

struct registro
{
	string mes, hora, mensaje;
	int dia;
};

struct acceso{
	string ip;
	int nAccesos;
	vector<registro> listaRegistro;
};

class Hash
{
	private:
		vector<vector<acceso>> accesos;
	public:
		Hash();
		void buildHash();
		void insert(string ip, string mes, int dia, string hora, string mensaje);
		void search(string ip);
};

Hash::Hash()
{
	accesos.resize(255);
}

void Hash::buildHash()
{
	accesos.resize(255);
	
	for (int i = 0; i < 255; i++)
	{
		accesos[i].resize(0);
	}
}

int chooseIndex(string ip)
{
  char a, b, c;
  a = ip[0];
  b = ip[1];
  c = ip[2];
  int e = 0;
  if (a != '.' && b != '.' && c != '.')
  {
    int ai = a - '0';
    int bi = b - '0';
    int ci = c - '0';
    e = ai*100 + bi*10 + ci;
    return e;
  }
  if (a != '.' && b != '.' && c == '.')
  {
    int ai = a - '0';
    int bi = b - '0';
    e = ai*10 + bi*1;
    return e;
  }
  if (a != '.' && b == '.')
  {
    int ai = a - '0';
    int bi = b - '0';
    e = ai*1;
    return e;
  }
  return e;
}

void Hash::insert(string ip, string mes, int dia, string hora, string mensaje)
{
	int idx = chooseIndex(ip);
	bool nuevoIp = false;
	int ipViejo;

	if (accesos[idx].size() == 0)
	{
		nuevoIp = true;
	}

	/*

	if (nuevoIp == false)
	{
		for (int i = 0; i < accesos[idx].size(); i++)
		{
			if (accesos[idx][i].ip == ip)
			{
				nuevoIp = false;
				ipViejo = i;
			}

			else
			{
				nuevoIp = true;
			}
		}
	}

	if (nuevoIp == true)
	{
		registro regTemp;
		acceso accTemp;
		
		regTemp.dia = dia;
		regTemp.mes = mes;
		regTemp.hora = hora;
		regTemp.mensaje = mensaje;

		accTemp.ip = ip;
		accTemp.nAccesos = 1;
		accTemp.listaRegistro.push_back(regTemp);

		accesos[idx].push_back(accTemp);
	}

	else
	{
		registro regTemp;
		
		regTemp.dia = dia;
		regTemp.mes = mes;
		regTemp.hora = hora;
		regTemp.mensaje = mensaje;

		accesos[idx][ipViejo].nAccesos = accesos[idx][ipViejo].nAccesos + 1;
		accesos[idx][ipViejo].listaRegistro.push_back(regTemp);
	}

}

void Hash::search(string ip)
{
	
}

*/