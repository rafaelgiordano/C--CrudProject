/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: Orcamento.cpp

   Definição dos métodos da classe Orcamento.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

/* inclusão dos headers referentes às classes utilizadas */
#include "Orcamento.h"

using namespace std;

/* função Set que modifica o atributo 'tipo' */
void Orcamento::setTipoOrcamento(string t)
{
	tipo = t;
}

/* função Set que modifica o atributo 'valorRessarc' */
void Orcamento::setValorRessarcOrcamento(float x)
{
	valorRessarc = x;
}

/* função Get que retorna o tipo do orçamento */
string Orcamento::getTipoOrcamento() const
{
	return tipo;
}

/* função Get que retorna o valor de ressarcimento do orçamento */
float Orcamento::getValorRessarcOrcamento() const
{
	return valorRessarc;
}