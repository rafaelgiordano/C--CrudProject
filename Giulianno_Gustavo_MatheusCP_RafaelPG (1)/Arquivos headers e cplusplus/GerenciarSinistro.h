/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: GerenciarSinistro.h

   Definição da classe GerenciarSinistro, de seus atributos e métodos.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

#ifndef __GERENCIARSINISTRO_H__
#define __GERENCIARSINISTRO_H__

/* inclusão das bibliotecas do sistema */
#include <iostream>
#include <string>

/* inclusão dos headers referentes às classes utilizadas */
#include "Sinistro.h"

class Sinistro;		/* forward declaration */

class GerenciarSinistro
{
	/* atributos da classe GerenciarSinistro */
	private:

		Sinistro *sinistro; /* ponteiro para um objeto da classe Sinistro */

	/* métodos da classe GerenciarSinistro */
	public:

		GerenciarSinistro();  /* construtor */

		~GerenciarSinistro(); /* destrutor */

		void criarSinistro(int x, Data d, std::string place, Terceiro *t, int tipoSinistro, BO *b);		/* chama as funções Set da classe 'Sinistro', passando seus parâmetros */

		void alterarSinistro(int x, Data d, std::string place, Terceiro t, int tipoSinistro, BO b);		/* chama a função criarSinistro, passando seus parâmetros */

		void excluirSinistro();																			/* devolve a memória alocada */

		bool consultarSinistro();																		/* consulta de um 'Sinistro' */

		/* funções Get da classe */

		Sinistro* getSinistro() const;																	/* retorna o atributo 'Sinistro' */
};

#endif /* __GERENCIARSINISTRO_H__ */