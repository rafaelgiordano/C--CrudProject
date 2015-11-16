/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: CRUDTerceiro.cpp

   Definição dos métodos da classe CRUDTerceiro.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

/* inclusão dos headers referentes às classes utilizadas */
#include "CRUDTerceiro.h"

using namespace std;

/* construtor da classe, aloca espaço suficiente para um objeto da classe Terceiro */
CRUDTerceiro::CRUDTerceiro()
{
	try
	{
		terceiro = new Terceiro;	
	}

	catch(bad_alloc)
	{
		cout << "Memória insuficiente!" << endl;
	}
}

/* destrutor da classe, devolve a memória que foi alocada */
CRUDTerceiro::~CRUDTerceiro()
{
	delete terceiro;
}

/* chama as funções Set da classe para modificar os atributos */
void CRUDTerceiro::criarTerceiro(int anos, std::string nomeTerceiro, std::string tel, std::string end, std::string seguroTerceiro, std::string cpf)
{
	terceiro->setIdadeTerceiro(anos);
	terceiro->setNomeTerceiro(nomeTerceiro);
	terceiro->setTelefoneTerceiro(tel);
	terceiro->setEnderecoTerceiro(end);
	terceiro->setSeguradoraTerceiro(seguroTerceiro);
	terceiro->setCPFTerceiro(cpf);
}

/* chama o método criarTerceiro, passando os parâmetros recebidos na chamada */
void CRUDTerceiro::alterarTerceiro(int anos, std::string nomeTerceiro, std::string tel, std::string end, std::string seguroTerceiro, std::string cpf)
{
	criarTerceiro(anos, nomeTerceiro, tel, end, seguroTerceiro, cpf);
}

/* devolve a memória que foi alocada */
void CRUDTerceiro::excluirTerceiro()
{
	delete terceiro;
}

/* possui seis opções de pesquisa de um determinado terceiro. Retorna true e chama a função imprimirDadosTerceiro se achou e false caso contrário */
bool CRUDTerceiro::consultarTerceiro()
{
	if (terceiro != NULL)
	{
		int opcao;

		cout << "Tipo de consulta" << endl;
		cout << "1 - Nome da seguradora" << endl;
		cout << "2 - Nome do terceiro" << endl;
		cout << "3 - Telefone do terceiro" << endl;
		cout << "4 - Endereço do terceiro" << endl;
		cout << "5 - Idade do terceiro" << endl;
		cout << "6 - CPF do terceiro" << endl;
		cin >> opcao;

		switch (opcao)
		{
			case 1: 
			{
				string nomeConsulta;
				cout << "Digite o nome da seguradora que deseja procurar: ";
				cin >> nomeConsulta;

				if ((nomeConsulta) == (terceiro->getSeguradoraTerceiro()))
				{
					cout << "Terceiro encontrado!" << endl << endl;

					imprimirDadosTerceiro();

					return true;
				}
			}
			break;

			case 2: 
			{
				string nomeConsulta;
				cout << "Digite o nome do terceiro que deseja procurar: ";
				cin >> nomeConsulta;

				if ((nomeConsulta) == (terceiro->getNomeTerceiro()))
				{
					cout << "Terceiro encontrado!" << endl << endl;

					imprimirDadosTerceiro();

					return true;
				}
			}
			break;

			case 3: 
			{
				string telefoneConsulta;
				cout << "Digite o telefone do terceiro que deseja procurar: ";
				cin >> telefoneConsulta;

				if ((telefoneConsulta) == (terceiro->getTelefoneTerceiro()))
				{
					cout << "Terceiro encontrado!" << endl << endl;

					imprimirDadosTerceiro();

					return true;
				}
			}
			break;

			case 4: 
			{
				string enderecoConsulta;
				cout << "Digite o endereco do terceiro que deseja procurar: ";
				cin >> enderecoConsulta;

				if ((enderecoConsulta) == (terceiro->getEnderecoTerceiro()))
				{
					cout << "Terceiro encontrado!" << endl << endl;

					imprimirDadosTerceiro();

					return true;
				}
			}
			break;

			case 5: 
			{
				int idadeConsulta;
				cout << "Digite a idade do terceiro que deseja procurar: ";
				cin >> idadeConsulta;

				if ((idadeConsulta) == (terceiro->getIdadeTerceiro()))
				{
					cout << "Terceiro encontrado!" << endl << endl;

					imprimirDadosTerceiro();

					return true;
				}
			}
			break;

			case 6: 
			{
				string cpfConsulta;
				cout << "Digite o CPF do terceiro que deseja procurar: ";
				cin >> cpfConsulta;

				if ((cpfConsulta) == (terceiro->getCPFTerceiro()))
				{
					cout << "Terceiro encontrado!" << endl << endl;

					imprimirDadosTerceiro();

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

/* método que imprime os atributos da classe */
void CRUDTerceiro::imprimirDadosTerceiro()
{
	cout << "Impressão do terceiro" << endl; 
	cout << "Nome: " << terceiro->getNomeTerceiro() << endl; 
	cout << "Idade: " << terceiro->getIdadeTerceiro() << endl; 
	cout << "CPF: " << terceiro->getCPFTerceiro() << endl; 
	cout << "Endereço: " << terceiro->getEnderecoTerceiro() << endl; 
	cout << "Telefone: " << terceiro->getTelefoneTerceiro() << endl; 
	cout << "Seguradora: " << terceiro->getSeguradoraTerceiro() << endl; 
	cout <<  endl;
}

/* função Get para o atributo terceiro */
Terceiro* CRUDTerceiro::getTerceiro() const
{
	return terceiro;
}