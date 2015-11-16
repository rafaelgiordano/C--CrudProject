/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: CRUDTerceiro.h

   Definição da classe CRUDTerceiro, de seus atributos e métodos.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

#ifndef __CRUDTERCEIRO_H__
#define __CRUDTERCEIRO_H__

/* inclusão das bibliotecas do sistema */
#include <iostream>

/* inclusão dos headers referentes às classes utilizadas */
#include "Terceiro.h"

class Terceiro;		/* forward declaration */

class CRUDTerceiro
{
	/* atributos da classe CRUDTerceiro */
	private:

		Terceiro *terceiro; /* ponteiro para um objeto da classe Terceiro */

	/* métodos da classe CRUDTerceiro */
	public:

		CRUDTerceiro();  /* construtor */

		~CRUDTerceiro(); /* destrutor */

		
		void criarTerceiro(int anos, std::string nomeTerceiro, std::string tel, std::string end, std::string seguroTerceiro, std::string cpf);   /* cria um objeto da classe 'Terceiro' chamando suas funções Set dados os parâmetro */


		void alterarTerceiro(int anos, std::string nomeTerceiro, std::string tel, std::string end, std::string seguroTerceiro, std::string cpf); /* altera um objeto da classe 'Terceiro' chamando a função criarTerceiro dados os parâmetro */

		void excluirTerceiro();			/* devolve a memória alocada */

		bool consultarTerceiro();		/* consulta de um 'Terceiro' */

		void imprimirDadosTerceiro();	/* imprime os dados da classe 'Terceiro' */

		Terceiro* getTerceiro() const;	/* retorna o atributo 'terceiro' */
};

#endif /* __CRUDTERCEIRO_H__ */