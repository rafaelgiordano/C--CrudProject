/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: GerenciarOrcamento.h

   Definição da classe GerenciarOrcamento, de seus atributos e métodos.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

#ifndef __GERENCIARORCAMENTO_H__
#define __GERENCIARORCAMENTO_H__

/* inclusão das bibliotecas do sistema */
#include <iostream>

/* inclusão dos headers referentes às classes utilizadas */
#include "Orcamento.h"

class Orcamento;		/* forward declaration */

class GerenciarOrcamento
{
	/* atributos da classe GerenciarOrcamento */
	private:

		static float valorTotal;   /* atributo estático da classe */

		Orcamento *orcamento;      /* ponteiro para um objeto da classe Orcamento */

	/* métodos da classe GerenciarOrcamento */
	public:

		GerenciarOrcamento();  /* construtor */

		~GerenciarOrcamento(); /* destrutor */

		void inserirOrcamento(std::string t, float x);	/* chama as funções Set da classe 'Orcamento' para atribuir valores aos atributos, além de incrementar o atributo estático */

		void imprimirDadosOrcamento();					/* imprime os dados da classe 'Orcamento' */

		/* funções Get da classe */

		static float getValorTotal(); 					/* método da classe, retorna o atributo 'valorTotal' */

		Orcamento* getOrcamento() const;				/* retorna o atributo 'Orcamento' */
};

#endif /* __GERENCIARORCAMENTO_H__ */