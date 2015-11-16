/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: Data.h

   Definição da classe Data, de seus atributos e métodos.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

#ifndef __DATA_H__
#define __DATA_H__

/* inclusão das bibliotecas do sistema */
#include <iostream>

class Data
{
	/* atributos da classe Data */
	private:

		int dia;	/* referente ao dia */

		int mes;	/* referente ao mês */

		int ano;	/* referente ao ano */

	/* métodos da classe Data */
	public:

		void inserirData(int d, int m, int a);	/* chama as funções Set da classe para definir seus atributos */
		
		/* funções Set da classe */

		void setDiaData(int d);					/* modifica o atributo 'dia' */
		
		void setMesData(int m);					/* modifica o atributo 'mes' */
		
		void setAnoData(int a);					/* modifica o atributo 'ano' */

		/* funções Get da classe */

		int getDiaData() const;					/* retorna o atributo 'dia' */

		int getMesData() const;					/* retorna o atributo 'mes' */

		int getAnoData() const;					/* retorna o atributo 'ano' */
};

#endif /* __DATA_H__ */