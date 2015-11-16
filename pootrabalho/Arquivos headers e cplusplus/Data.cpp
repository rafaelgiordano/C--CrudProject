/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: Data.cpp

   Definição dos métodos da classe Data.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

/* inclusão dos headers referentes às classes utilizadas */
#include "Data.h"

/* chama as funções Set da classe para atribuir valores aos atributos */
void Data::inserirData(int d, int m, int a)
{
	setDiaData(d);
	setMesData(m);
	setAnoData(a);
}

/* função Set que modifica o atributo 'dia' */
void Data::setDiaData(int d)
{
	dia = d;
}

/* função Set que modifica o atributo 'mes' */
void Data::setMesData(int m)
{
	mes = m;
}	

/* função Set que modifica o atributo 'ano' */
void Data::setAnoData(int a)
{
	ano = a;
}

/* função Get que retorna o dia */
int Data::getDiaData() const
{
	return dia;
}

/* função Get que retorna o mes */
int Data::getMesData() const
{
	return mes;
}

/* função Get que retorna o ano */
int Data::getAnoData() const
{
	return ano;
}