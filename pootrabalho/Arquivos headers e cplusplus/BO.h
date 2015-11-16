/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: BO.h

   Definição da classe BO, de seus atributos e métodos.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

#ifndef __BO_H__
#define __BO_H__

/* inclusão das bibliotecas do sistema */
#include <iostream>
#include <string>

/* inclusão dos headers referentes às classes utilizadas */
#include "Data.h"

class Data;		/* forward declaration */

class BO
{
	/* atributos da classe BO */
	private:

		int num;			/* número do BO */

		Data dateBO;		/* objeto da classe Data onde é armazenada a data do registro do BO */

		std::string tipo;   /* definição do tipo de BO */

	/* métodos da classe BO */
	public:

		void criarBO(int x, Data d, std::string n); /* chama as funções Set para modificar os atributos da classe BO */

		void imprimirDadosBO();						/* imprime os dados da classe BO */

		/* funções Set da classe */

		void setNumBO(int x);						/* modifica o atributo 'num' */

		void setDateBO(Data d);						/* modifica o atributo 'dateBO' */

		void setTipoBO(std::string n);				/* modifica o atributo 'tipo' */

		/* funções Get da classe */

		int getNumBO() const;						/* retorna o atributo 'num' */

		Data getDateBO() const;						/* retorna o atributo 'dateBO' */

		std::string getTipoBO() const; 				/* retorna o atributo 'tipo' */
};

#endif /* __BO_H__ */