/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: Orcamento.cpp

   Definição dos métodos da classe Orcamento.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

/* inclusão dos headers referentes às classes utilizadas */
#include "Sinistro.h"

using namespace std;

/* destrutor da classe, devolve a memória alocada por cada ponteiro */
Sinistro::~Sinistro()
{
	delete terceiro;
	delete bo;
}

/* aloca espaço suficiente para um objeto da classe BO */
void Sinistro::incluirBO() 
{
	try 
	{
		bo = new BO;
	}

	catch(bad_alloc)
	{
		cout << "Memória insuficiente!" << endl;
	}
}

/* aloca espaço suficiente para um objeto da classe Terceiro */
void Sinistro::incluirTerceiro()
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

/* imprime os dados do sinistro e do terceiro */
void Sinistro::imprimirDadosSinistro()
{
	cout << "Data: " << dateSinistro.getDiaData() << "." << dateSinistro.getMesData() << "." << dateSinistro.getAnoData() << endl << endl;
	
	// cout << "BO" << endl;
	// cout << "Número: " << bo->getNumBO() << endl;
	// cout << "Tipo: " << bo->getTipoBO() << endl;
	// bo->imprimirDadosBO();
	
	cout << "Terceiro" << endl;
	cout << "Seguradora: " << terceiro->getSeguradoraTerceiro() << endl;
	cout << "Nome: " << terceiro->getNomeTerceiro() << endl;
	cout << "Telefone: " << terceiro->getTelefoneTerceiro()  << endl;
	cout << "CPF: " << terceiro->getCPFTerceiro() << endl;
	cout << "Endereço: " << terceiro->getEnderecoTerceiro() << endl;
	cout << "Idade: " << terceiro->getIdadeTerceiro() << endl << endl;
}

/* função Set que modifica o atributo 'num' */
void Sinistro::setNumSinistro(int x)
{
	num = x;
}

/* função Set que modifica o atributo 'dateSinistro' */
void Sinistro::setDateSinistro(Data d)
{
	dateSinistro = d;
}

/* função Set que modifica o atributo 'local' */
void Sinistro::setLocalSinistro(string place)
{
	local = place;
}

/* função Set que modifica o atributo 'terceiro' */
void Sinistro::setTerceiroSinistro(Terceiro *t)
{
	terceiro = t;
}		

/* função Set que modifica o atributo 'bo' */
void Sinistro::setBOSinistro(BO *b)
{
	bo = b;
}

/* função Set que modifica o atributo 'tiposinistro' */
void Sinistro::setTipoSinistroSinistro(int x)
{
	tiposinistro = x;
}

/* função Get que retorna o número do sinistro */
int Sinistro::getNumSinistro() const
{
	return num;
}

/* função Get que retorna a data do sinistro */
Data Sinistro::getDateSinistro() const
{
	return dateSinistro;
}

/* função Get que retorna o local do sinistro */
string Sinistro::getLocalSinistro() const
{
	return local;
}

/* função Get que retorna um ponteiro para o terceiro do sinistro */
Terceiro* Sinistro::getTerceiroSinistro() const
{
	return terceiro;
}

/* função Get que retorna o tipo do sinistro */
int Sinistro::getTipoSinistro() const
{
	return tiposinistro;
}

/* função Get que retorna um ponteiro para o bo do sinistro */
BO* Sinistro::getBOSinistro() const
{
	return bo;
}