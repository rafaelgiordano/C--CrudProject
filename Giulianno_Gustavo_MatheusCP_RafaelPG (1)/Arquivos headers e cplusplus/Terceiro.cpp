/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: Terceiro.cpp

   Definição dos métodos da classe Terceiro.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

/* inclusão dos headers referentes às classes utilizadas */
#include "Terceiro.h"

using namespace std;

/* função Set que modifica o atributo 'idade' */
void Terceiro::setIdadeTerceiro(int anos)
{
	idade = anos;
}

/* função Set que modifica o atributo 'nome' */
void Terceiro::setNomeTerceiro(string nomeTerceiro)
{
	nome = nomeTerceiro;
}

/* função Set que modifica o atributo 'telefone' */
void Terceiro::setTelefoneTerceiro(string tel)
{
	telefone = tel;
}

/* função Set que modifica o atributo 'endereco' */
void Terceiro::setEnderecoTerceiro(string end)
{
	endereco = end;

}

/* função Set que modifica o atributo 'seguradora' */
void Terceiro::setSeguradoraTerceiro(string seguroTerceiro)
{
	seguradora = seguroTerceiro;
}

/* função Set que modifica o atributo 'CPF' */
void Terceiro::setCPFTerceiro(string cpf)
{
	CPF = cpf;
}

/* função Get que retorna a idade do terceiro */
int Terceiro::getIdadeTerceiro() const
{
	return idade;
}

/* função Get que retorna o nome do terceiro */
string Terceiro::getNomeTerceiro() const
{
	return nome;
}

/* função Get que retorna o telefone do terceiro */
string Terceiro::getTelefoneTerceiro() const
{
	return telefone;
}

/* função Get que retorna o endereco do terceiro */
string Terceiro::getEnderecoTerceiro() const
{
	return endereco;
}

/* função Get que retorna o nome da seguradora */
string Terceiro::getSeguradoraTerceiro() const
{
	return seguradora;
}

/* função Get que retorna o CPF do terceiro */
string Terceiro::getCPFTerceiro() const
{
	return CPF;
}
