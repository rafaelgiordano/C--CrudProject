/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: BO.cpp

   Definição dos métodos da classe BO.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

/* inclusão dos headers referentes às classes utilizadas */
#include "BO.h"

using namespace std;

/* chama as funções Set da classe para atribuir valores aos atributos */
void BO::criarBO(int x, Data d, string n)
{
	setNumBO(x);
	setDateBO(d);
	setTipoBO(n);
}

/* função Set que modifica o atributo 'num' */
void BO::setNumBO(int x)
{
	num = x;
}

/* função Set que modifica o atributo 'dateBO' */
void BO::setDateBO(Data d)
{
	dateBO = d;
}

/* função Set que modifica o atributo 'tipo' */
void BO::setTipoBO(string n)
{
	tipo = n;
}

/* função Get que retorna o número da apólice */
int BO::getNumBO() const
{
	return num;
}

/* função Get que retorna a data do BO */
Data BO::getDateBO() const
{
	return dateBO;
}

/* função Get que retorna o tipo do BO */
string BO::getTipoBO() const
{	
	return tipo;
}

/* método que imprime os atributos refentes à classe */
void BO::imprimirDadosBO()
{
	// cout << "Número: " << getNumBO() << endl;
	cout << "Data: " << dateBO.getDiaData() << "." << dateBO.getMesData() << "." << dateBO.getAnoData() << endl;
	// cout << "Tipo: " << getTipoBO() << endl;
}