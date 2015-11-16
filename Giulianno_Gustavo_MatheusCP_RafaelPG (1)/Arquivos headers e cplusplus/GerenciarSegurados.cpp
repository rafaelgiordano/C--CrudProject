/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: GerenciarSegurados.cpp

   Definição dos métodos da classe GerenciarSegurados.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

/* inclusão dos headers referentes às classes utilizadas */
#include "GerenciarSegurados.h"

using namespace std;

const int GerenciarSegurados::MAX = 100; /* define o tamanho máximo do vetor de ponteiros */

/* construtor da classe, zera os contadores e atribui NULL a todas as posições dos vetores de ponteiros */
GerenciarSegurados::GerenciarSegurados()
{
	qtdeCliente = 0;
	qtdeCondutor = 0;

	for (int i = 0; i < MAX; i++)
	{
		cliente[i] = NULL;
		// condutor[i] = NULL;
	}
}

/* destrutor da classe, devolve a memória alocada por cada ponteiro dos vetores de ponteiros, depois atribui NULL */
GerenciarSegurados::~GerenciarSegurados()
{
	for (int i = 0; i < qtdeCliente; i++)
	{
		if (cliente[i] != NULL)
		{
			delete cliente[i];
			cliente[i] = NULL;
		}
	}

	// for (int i = 0; i < qtdeCondutor; i++)
	// {
	// 	if (condutor[i] != NULL)
	// 	{
	// 		delete condutor[i];
	// 		condutor[i] = NULL;
	// 	} 
	// }
}

/* aloca a memória necessária para um objeto da classe Cliente, e em seguida chama as funções Set da classe para atribuir aos atributos da classe os parâmetros passados */
bool GerenciarSegurados::criarCliente(string n, string t, string e, int pos, string cpf)
{
	if ((qtdeCliente == MAX) || (pos >= qtdeCliente))
	{
		return false;
	}

	if (pos == -1)
	{
		pos = qtdeCliente;
	}

	try
	{
		cliente[pos] = new Cliente;
	}

	catch(bad_alloc)
	{
		cout << "Memória insuficiente!" << endl;
	}

	cliente[pos]->setNomeCliente(n);
	cliente[pos]->setTelefoneCliente(t);
	cliente[pos]->setEnderecoCliente(e);
	cliente[pos]->setCPFCliente(cpf);
	// cliente[pos]->setApoliceCliente(ap);

	qtdeCliente++;

	return true;
}

/* se a posição passada por parâmetro for válida, chama a função criarCliente para que o objeto na posição dada seja alterado */
bool GerenciarSegurados::alterarCliente(string n, string t, string e, int pos, string cpf)
{
	if ((qtdeCliente == MAX) || (pos >= qtdeCliente))
	{
		return false;
	}

	return criarCliente(n, t, e, pos, cpf);
}

/* se a posição passada por parâmetro for válida, há um laço que puxa todos os objetos da posição dada para frente, garantindo que o objeto seja excluído */
bool GerenciarSegurados::excluirCliente(int pos)
{
	if (pos >= MAX || pos >= qtdeCliente)
	{
		return false;
	}

	for (int i = pos; i < qtdeCliente; i++)
	{
		cliente[i] = cliente[i + 1];
	}

	qtdeCliente--;

	return true;
}

/* a consulta por um cliente pode ser feita pelo número da apólice, nome do cliente ou CPF do cliente */
bool GerenciarSegurados::consultarCliente()
{
	int opcao;

	cout << "Tipo de consulta" << endl;
	cout << "1 - Número da apólice" << endl;
	cout << "2 - Nome do cliente" << endl;
	cout << "3 - CPF do cliente" << endl;
	cin >> opcao;

	switch (opcao)
	{
		case 1: 
		{

			int num;
			cout << "Digite o número da apólice que deseja procurar: ";
			cin >> num;

			for (int i = 0; i < qtdeCliente; i++)
			{
				for (int j = 0; j < cliente[i]->getQtdeApoliceCliente(); j++)
				{
					if ((num) == (cliente[i]->apolice[j]->getNumApolice()))
					{
						cout << "Apólice encontrada!" << endl;

						return true;
					}
				}
			}
		}
		break;

		case 2: 
		{
			string nomeConsulta;
			cout << "Digite o nome do cliente que deseja procurar: ";
			cin >> nomeConsulta;

			for (int i = 0; i < qtdeCliente; i++)
			{
				if ((nomeConsulta) == (cliente[i]->getNomeCliente()))
				{
					cout << "Cliente encontrado!" << endl;

					return true;
				}
			}
		}
		break;

		case 3: 
		{
			string cpfConsulta;
			cout << "Digite o CPF do cliente que deseja procurar: ";
			cin >> cpfConsulta;

			for (int i = 0; i < qtdeCliente; i++)
			{
				if ((cpfConsulta) == (cliente[i]->getCPFCliente()))
				{
					cout << "Cliente encontrado!" << endl;

					return true;
				}
			}
		}
		break;

		default:
		{
			cout << "Opção inexistente!" << endl;
		}
	}

	return false;
}

/* chama o método da classe veículo, que verifica se a placa passada como parâmetro é igual ao atributo placa */
bool GerenciarSegurados::consultarVeiculo(string placa)
{
	for (int i = 0; i < qtdeCliente; i++)
	{
		if (cliente[i]->procurarVeiculoCliente(placa))
		{
			return true;
		}
	}

	return false;
}

/* realiza a impressão dos dados de cada objeto da classe Cliente, em cada posição do vetor de ponteiros */
bool GerenciarSegurados::imprimirDadosCliente()
{
	if (qtdeCliente == 0)
	{
		return false;
	}

	for (int i = 0; i < qtdeCliente; i++)
	{
		cout << "Cliente #" << i + 1 << endl;
		cout << "Nome: " << cliente[i]->getNomeCliente() << endl;
		cout << "Telefone: " << cliente[i]->getTelefoneCliente() << endl;
		cout << "Endereco: " << cliente[i]->getEnderecoCliente() << endl;
		cout << "CPF: " << cliente[i]->getCPFCliente() << endl;
		cout << endl << endl;

		// FILE.open("data.txt", ios::app);

		// FILE << "Cliente #" << i + 1 << "\n";
		// FILE << "Nome: " << cliente[i]->getNomeCliente() << "\n";
		// FILE << "Telefone: " << cliente[i]->getTelefoneCliente() << "\n";
		// FILE << "Endereco: " << cliente[i]->getEnderecoCliente() << "\n";
		// FILE << "CPF: " << cliente[i]->getCPFCliente() << "\n";
		// FILE << "\n" << "\n";

		// FILE.close();

		if (cliente[i]->getQtdeApoliceCliente() == 0)
		{
			cout << "Não possui apólices vinculadas" << endl << endl << endl;
		}
		else
		{
			cliente[i]->imprimirDadosApoliceCliente();
		}
	}

	return true;
}

void GerenciarSegurados::salvarArquivo()
{
	ofstream file;
	string resposta;

	cout << "Deseja sobrescrever o arquivo de dados existente? (S/N)" << endl;
	cin >> resposta;

	if (resposta == "S")
	{
		file.open("data.txt", ios::trunc);
		file.close();
		cout << "Arquivo de dados existente foi sobreescrito" << endl;
	}
	else
	{
		cout << "Arquivo de dados existente não foi sobreescrito" << endl;
	}

	if (qtdeCliente != 0)
	{
		for (int i = 0; i < qtdeCliente; i++)
		{
			file.open("data.txt", ios::app);

			file << "Cliente #" << i + 1 << "\n";
			file << "Nome: " << cliente[i]->getNomeCliente() << "\n";
			file << "Telefone: " << cliente[i]->getTelefoneCliente() << "\n";
			file << "Endereco: " << cliente[i]->getEnderecoCliente() << "\n";
			file << "CPF: " << cliente[i]->getCPFCliente() << "\n";
			file << "\n" << "\n";

			if (cliente[i]->getQtdeApoliceCliente() == 0)
			{
				file << "Não possui apólices vinculadas" << "\n\n\n";
			}
			else
			{
				file.close();
				cliente[i]->salvarArquivoCliente();
			}
			
			file.close();
		}
	}
}

/* se a posição for válida, a função chama o método excluirApolice da classe Cliente */
bool GerenciarSegurados::removerApolice(int posicao, int pos)
{
	if (posicao >= MAX || posicao >= qtdeCliente)
	{
		return false;
	}

	return cliente[posicao]->excluirApoliceCliente(pos);
}

/* se a posição for válida, a função chama o método alterarApoliceCliente da classe Cliente */
bool GerenciarSegurados::alterarApolice(int posicao, int pos, Apolice *ap)
{
	if (posicao >= MAX || posicao >= qtdeCliente)
	{
		return false;
	}

	return cliente[posicao]->alterarApoliceCliente(pos, ap);
}

/* se a posição for válida, a função chama o método setApoliceCliente da classe Cliente */
bool GerenciarSegurados::vincularApoliceCliente(Apolice *ap, int pos)
{
	if (pos >= MAX || pos > qtdeCliente)
	{
		return false;
	}

	return cliente[pos]->setApoliceCliente(ap);
}

// bool GerenciarSegurados::criarCondutor(std::string n, std::string t, std::string e, Apolice *ap, std::string CNH, int idade_cond, std::string cpf, int pos)
// {
// 	if (qtdeCondutor == MAX)
// 	{
// 		return false;
// 	}

// 	if (pos == -1)
// 	{
// 		pos = qtdeCondutor;
// 	}

// 	try
// 	{
// 		condutor[pos] = new Condutor;
// 	}

// 	catch(std::bad_alloc)
// 	{
// 		std::cout << "Memória insuficiente!" << std::endl;
// 	}

// 	condutor[pos]->setNomeCondutor(n);
// 	condutor[pos]->setTelefoneCondutor(t);
// 	condutor[pos]->setEnderecoCondutor(e);
// 	condutor[pos]->setApoliceCondutor(ap);
// 	condutor[pos]->setCNHCondutor(CNH);
// 	condutor[pos]->setIdadeCondutor(idade_cond);
// 	condutor[pos]->setCPFCondutor(cpf);

// 	return true;
// }

// bool GerenciarSegurados::alterarCondutor(std::string n, std::string t, std::string e, Apolice *ap, std::string CNH, int idade_cond, std::string cpf, int pos)
// {
// 	if (pos >= MAX || pos >= qtdeCondutor)
// 	{
// 		return false;
// 	}

// 	return criarCondutor(n, t, e, ap, CNH, idade_cond, cpf, pos);
// }

// bool GerenciarSegurados::excluirCondutor(int pos)
// {
// 	if (pos >= MAX || pos >= qtdeCondutor)
// 	{
// 		return false;
// 	}

// 	delete condutor[pos];

// 	// laço que puxa os demais elementos do vetor

// 	qtdeCondutor--;

// 	return true;
// }

// bool GerenciarSegurados::consultarCondutor(int pos)
// {
// 	if (pos >= MAX || pos >= qtdeCondutor || pos < 0)
// 	{
// 		return false;
// 	}	

// 	return true;
// }

// bool GerenciarSegurados::imprimirDadosCondutor()
// {

// }