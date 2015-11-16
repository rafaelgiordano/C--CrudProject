/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: Sinistro.h

   Definição da classe Sinistro, de seus atributos e métodos.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

#ifndef __SINISTRO_H__
#define __SINISTRO_H__

/* inclusão das bibliotecas do sistema */
#include <iostream>
#include <string>
#include <fstream>

/* inclusão dos headers referentes às classes utilizadas */
#include "Terceiro.h"
#include "BO.h"
#include "Data.h"

class Terceiro;		/* forward declaration */

class BO;			/* forward declaration */

class Data;			/* forward declaration */

class Sinistro
{
	/* atributos da classe Sinistro */
	private:

		int num;				/* número do sinistro */

		Data dateSinistro;      /* objeto da classe Data onde é armazenada a data do sinistro */

		std::string local;		/* local referente ao sinistro */
		
		int tiposinistro;		/* tipo do sinistro */

		Terceiro *terceiro;		/* ponteiro para um objeto da classe Terceiro */

		BO *bo;					/* ponteiro para um objeto da classe BO */

	/* métodos da classe Sinistro */
	public:

		~Sinistro(); /* destrutor */

		void incluirBO();							/* aloca memória necessária para um objeto da classe 'BO' */

		void incluirTerceiro();						/* aloca memória necessária para um objeto da classe 'Terceiro' */

		void imprimirDadosSinistro();				/* imprime os dados do sinistro e do terceiro */

		void salvarArquivoSinistro();				/* salva em arquivo os dados */

		/* funções Set da classe */ 						

		void setNumSinistro(int x);					/* modifica o atributo 'num' */

		void setDateSinistro(Data d);				/* modifica o atributo 'dateSinistro' */

		void setLocalSinistro(std::string place);	/* modifica o atributo 'local' */

		void setTerceiroSinistro(Terceiro *t);		/* modifica o atributo 'terceiro' */

		void setBOSinistro(BO *b);					/* modifica o atributo 'bo' */

		void setTipoSinistroSinistro(int x);		/* modifica o atributo 'tiposinistro' */
		
		/* funções Get da classe */

		int getNumSinistro() const;					/* retorna o atributo 'num' */

		Data getDateSinistro() const;				/* retorna o atributo 'dateSinistro' */

		std::string getLocalSinistro() const;		/* retorna o atributo 'local' */

		Terceiro* getTerceiroSinistro() const;		/* retorna o atributo 'terceiro' */

		BO* getBOSinistro() const;					/* retorna o atributo 'BO' */

		int getTipoSinistro() const;				/* retorna o atributo 'tiposinistro' */
};

#endif /* __SINISTRO_H__ */