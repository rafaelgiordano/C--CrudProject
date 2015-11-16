/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: GerenciarSinistro.cpp

   Definição dos métodos da classe GerenciarSinistro.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

/* inclusão dos headers referentes às classes utilizadas */
#include "GerenciarSinistro.h"

using namespace std;

/* construtor da classe, aloca espaço suficiente para um objeto da classe Sinistro */
GerenciarSinistro::GerenciarSinistro()
{
	try 
	{
		sinistro = new Sinistro;
	}

	catch(bad_alloc)
	{
		cout << "Memória insuficiente!" << endl;
	}
}

/* destrutor da classe, devolve a memória que foi alocada */
GerenciarSinistro::~GerenciarSinistro()
{
	delete sinistro;
}

/* chama as funções Set da classe para atribuir valores aos atributos */
void GerenciarSinistro::criarSinistro(int x, Data d, string place, Terceiro *t, int tipoSinistro, BO *b)
{
	sinistro->setNumSinistro(x);
	sinistro->setDateSinistro(d);
	sinistro->setLocalSinistro(place);
	sinistro->incluirTerceiro();
	sinistro->setTerceiroSinistro(t);
	sinistro->incluirBO();
	sinistro->setBOSinistro(b); 
	sinistro->setTipoSinistroSinistro(tipoSinistro);
}

/* chama o método criarSinistro, passando os parâmetros recebidos na chamada */
void GerenciarSinistro::alterarSinistro(int x, Data d, string place, Terceiro t, int tipoSinistro, BO b)
{
	criarSinistro(x, d, place, &t, tipoSinistro, &b);
}

/* devolve a memória que foi alocada */
void GerenciarSinistro::excluirSinistro()
{
	delete sinistro;
}

/* possui duas opções de pesquisa de um determinado sinistro. Retorna true e chama a função imprimirDadosSinistro se achou e false caso contrário */
bool GerenciarSinistro::consultarSinistro()
{
	if (sinistro != NULL)
	{
		int opcao;

		cout << "Tipo de consulta" << endl;
		cout << "1 - Número do sinistro" << endl;
		cout << "2 - Local do sinistro" << endl;
		cin >> opcao;

		switch (opcao)
		{
			case 1: 
			{
				int numConsulta;
				cout << "Digite o número do sinistro que deseja procurar: ";
				cin >> numConsulta;

				if ((numConsulta) == (sinistro->getNumSinistro()))
				{
					cout << "Sinistro encontrado!" << endl << endl;

					sinistro->imprimirDadosSinistro();

					return true;
				}
			}
			break;

			case 2: 
			{
				string localConsulta;
				cout << "Digite o local do sinistro que deseja procurar: ";
				cin >> localConsulta;

				if ((localConsulta) == (sinistro->getLocalSinistro()))
				{
					cout << "Sinistro encontrado!" << endl << endl;

					sinistro->imprimirDadosSinistro();

					return true;
				}
			}
			break;

			default:
			{
				cout << "Opção inexistente!" << endl;

				return false;
			}
		}
	}

	return false;
}

/* função Get que retorna um ponteiro do tipo 'Sinistro' */
Sinistro* GerenciarSinistro::getSinistro() const
{
	return sinistro;
}