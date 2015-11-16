/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: GerenciarVeiculos.h

   Definição da classe GerenciarVeiculos, de seus atributos e métodos.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */
   
#ifndef __GERENCIARVEICULOS_H__
#define __GERENCIARVEICULOS_H__

/* inclusão das bibliotecas do sistema */
#include <iostream>
#include <string>

/* inclusão dos headers referentes às classes utilizadas */
#include "Veiculo.h"

class Veiculo;		/* forward declaration */

class GerenciarVeiculos
{
	/* atributos da classe GerenciarVeiculos */
	private:

		Veiculo *veiculo; /* ponteiro para um objeto da classe Sinistro */

	/* métodos da classe GerenciarVeiculos */
	public:

		GerenciarVeiculos();  /* destrutor */

		~GerenciarVeiculos(); /* construtor */

		void inserirVeiculo(std::string p, int x, std::string r, int tv, int m);	/* chama as funções Set da classe 'Sinistro', passando seus parâmetros */

		void imprimirDadosVeiculo();												/* imprime os dados referentes ao veículo */

		/* funções Get da classe */

		Veiculo* getVeiculo() const;												/* retorna o atributo 'Sinistro' */
};

#endif /* __GERENCIARVEICULOS_H__ */