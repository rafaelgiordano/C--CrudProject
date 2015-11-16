/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: Cliente.cpp

   Definição dos métodos da classe Cliente.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

/* inclusão dos headers referentes às classes utilizadas */
#include "Cliente.h"

using namespace std;

const int Cliente::MAX = 100; /* define o tamanho máximo do vetor de ponteiros */

/* construtor da classe, zera o contador e atribui NULL a todas as posições do vetor de ponteiros */
Cliente::Cliente()
{
	qtdeApolice = 0;

	for (int i = 0; i < MAX; i++)
	{
		apolice[i] = NULL;
	}
}

/* destrutor da classe, devolve a memória alocada por cada ponteiro do vetor de ponteiros, depois atribui NULL */
Cliente::~Cliente()
{
	for (int i = 0; i < qtdeApolice; i++)
	{
		if (apolice[i] != NULL)
		{
			delete apolice[i];
			apolice[i] = NULL;
		}
	}
}

/* função Set que modifica o atributo 'nome' */
void Cliente::setNomeCliente(string n)
{
	nome = n;
}

/* função Set que modifica o atributo 'telefone' */
void Cliente::setTelefoneCliente(string t)
{
	telefone = t;
}

/* função Set que modifica o atributo 'endereco' */
void Cliente::setEnderecoCliente(string e)
{
	endereco = e;
}

/* função Set para o atributo apolice, utiliza o contador para que cada índice do vetor de ponteiros aponte para o objeto corretamente */
bool Cliente::setApoliceCliente(Apolice *ap)
{
	if (qtdeApolice == MAX)
	{
		return false;
	}

	apolice[qtdeApolice] = ap;
	qtdeApolice++;

	return true;
}

/* função Set que modifica o atributo 'CPF' */
void Cliente::setCPFCliente(string cpf)
{
	CPF = cpf;
}

/* função Get que retorna o nome do cliente */
string Cliente::getNomeCliente() const
{
	return nome;
}

/* função Get que retorna o telefone do cliente */
string Cliente::getTelefoneCliente() const
{
	return telefone;
}

/* função Get que retorna o endereço do cliente */
string Cliente::getEnderecoCliente() const
{
	return endereco;
}

/* função Get que retorna o CPF do cliente */
string Cliente::getCPFCliente() const
{
	return CPF;
}	

/* função Get que retorna a quantidade de apólices do cliente */
int Cliente::getQtdeApoliceCliente() const
{
	return qtdeApolice;
}

/* chama o método da classe Apolice, passando como parâmetro a placa. Retorna true se a placa for igual à placa passada como parâmetro */
bool Cliente::procurarVeiculoCliente(string placa)
{
	for (int i = 0; i < qtdeApolice; i++)
	{
		if (apolice[i]->pesquisarVeiculo(placa))
		{
			return true;
		}
	}

	return false;
}

/* dada a posição passada por parâmetro, um laço puxa os elementos logo a frente, sobreescrevendo a apólice da posição */
bool Cliente::excluirApoliceCliente(int pos)
{
	if (pos >= MAX || pos >= qtdeApolice)
	{
		return false;
	}

	for (int i = pos; i < qtdeApolice; i++)
	{
		apolice[i] = apolice[i + 1];
	}

	qtdeApolice--;

	return true;
}

/* dada a posição passada por parâmetro e um ponteiro para a classe Apolice, na posição o vetor de ponteiro aponta agora para o ponteiro passado por referência */
bool Cliente::alterarApoliceCliente(int pos, Apolice *ap)
{
	if (pos >= MAX || pos >= qtdeApolice)
	{
		return false;
	}

	apolice[pos] = ap;

	return true;
}

/* imprime os dados das apólices do cliente */
void Cliente::imprimirDadosApoliceCliente()
{
	for (int i = 0; i < getQtdeApoliceCliente(); i++)
	{
		cout << "Apólice #" << i + 1 << endl;
		cout << "Número: " << apolice[i]->getNumApolice() << endl;

		cout << "Classificação: ";

		if (apolice[i]->getClassificacaoApolice() == 1)
		{
			cout << "classe1" << endl;
		}
		else
		{
			cout << "classe2" << endl;	
		}

		apolice[i]->imprimirDadosApolice();
		
		if (apolice[i]->getQtdeOrcamento() == 0)
		{
			cout << "Não possui orçamentos vinculados" << endl << endl;
		}
		else
		{
			apolice[i]->imprimirDadosOrcamentoApolice();
		}

		cout << endl;

		if (apolice[i]->getQtdeSinistro() == 0)
		{
			cout << "Não possui sinistros vinculados" << endl << endl;	
		}
		else
		{
			apolice[i]->imprimirDadosSinistroApolice();	
		}
	}
}