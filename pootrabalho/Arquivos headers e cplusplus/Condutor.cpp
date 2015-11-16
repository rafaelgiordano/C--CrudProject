/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: Condutor.cpp

   Definição dos métodos da classe Condutor.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

/* inclusão dos headers referentes às classes utilizadas */
#include "Condutor.h"

const int Condutor::MAX = 100; /* define o tamanho máximo do vetor de ponteiros */

/* construtor da classe, zera o contador e atribui NULL a todas as posições do vetor de ponteiros */

Condutor::Condutor()
{
	qtdeApolice = 0;

	for (int i = 0; i < MAX; i++)
	{
		apolice[i] = NULL;
	}
}

/* destrutor da classe, devolve a memória alocada por cada ponteiro do vetor de ponteiros, depois atribui NULL */
Condutor::~Condutor()
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
void Condutor::setNomeCondutor(std::string n)
{
	nome = n;
}

/* função Set que modifica o atributo 'telefone' */
void Condutor::setTelefoneCondutor(std::string t)
{
	telefone = t;
}

/* função Set que modifica o atributo 'endereco' */
void Condutor::setEnderecoCondutor(std::string e)
{
	endereco = e;
}

/* função Set para o atributo apolice, utiliza o contador para que cada índice do vetor de ponteiros aponte para o objeto corretamente */
bool Condutor::setApoliceCondutor(Apolice *ap) 
{
	if (qtdeApolice == MAX)
	{
		return false;
	}

	apolice[qtdeApolice] = ap;
	qtdeApolice++;

	return true;
}

/* função Set que modifica o atributo 'numCNH' */
void Condutor::setCNHCondutor(std::string cnh)
{
	numCNH = cnh;
}

/* função Set que modifica o atributo 'idade' */
void Condutor::setIdadeCondutor(int x)
{
	idade = x;
}

/* função Set que modifica o atributo 'CPF' */
void Condutor::setCPFCondutor(std::string cpf)
{
	CPF = cpf;
}

/* função Get que retorna o nome do condutor */
std::string Condutor::getNomeCondutor()
{
	return nome;
}

/* função Get que retorna o telefone do condutor */
std::string Condutor::getTelefoneCondutor()
{
	return telefone;
}

/* função Get que retorna o endereço do condutor */
std::string Condutor::getEnderecoCondutor()
{
	return endereco;
}

/* função Get que retorna o número da CNH do condutor */
std::string Condutor::getCNHCondutor()
{
	return numCNH;
}

/* função Get que retorna a idade do condutor */
int Condutor::getIdadeCondutor()
{
	return idade;
}

/* função Get que retorna o CPF do condutor */
std::string Condutor::getCPFCondutor()
{
	return CPF;
}

// Apolice Condutor::getApoliceCondutor()
// {
// 	return apolice;
// }