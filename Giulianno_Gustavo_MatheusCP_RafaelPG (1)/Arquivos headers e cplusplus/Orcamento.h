/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: GerenciarVeiculos.h

   Definição da classe GerenciarVeiculos, de seus atributos e métodos.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

#ifndef __ORCAMENTO_H__
#define __ORCAMENTO_H__

/* inclusão das bibliotecas do sistema */
#include <iostream>
#include <string>

class Orcamento
{
	/* atributos da classe Orcamento */
	private:

		std::string tipo;		/* tipo do orçamento */

		float valorRessarc;     /* valor do ressarcimento */

	/* métodos da classe Orcamento */
	public:

		/* funções Set da classe */

		void setTipoOrcamento(std::string t);		/* modifica o atributo 'tipo' */

		void setValorRessarcOrcamento(float x);     /* modifica o atributo 'valorRessarc' */

		/* funções Get da classe */

		std::string getTipoOrcamento() const;		/* retorna o atributo 'tipo' */

		float getValorRessarcOrcamento() const;		/* retorna o atributo 'valorRessarc' */
};

#endif /* __ORCAMENTO_H__ */