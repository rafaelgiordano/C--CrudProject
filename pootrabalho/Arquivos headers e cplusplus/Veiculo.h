/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: Veiculo.h

   Definição da classe Veiculo, de seus atributos e métodos.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

#ifndef __VEICULO_H__
#define __VEICULO_H__

/* inclusão das bibliotecas do sistema */
#include <iostream>
#include <string>

class Veiculo
{
	/* atributos da classe Veiculo */
	private:

		int ano;				/* ano do veículo */

		int tipoveiculo;		/* tipo do veículo */

		int marca;				/* marca do veículo */

		std::string placa;		/* placa do veículo */

		std::string renavam;    /* renavam do veículo */

	/* métodos da classe Veiculo */
	public:

		/* funções Set da classe */

		void setPlacaVeiculo(std::string p);		/* modifica o atributo 'placa' */

		void setAnoVeiculo(int x);					/* modifica o atributo 'ano' */

		void setRenavamVeiculo(std::string r);		/* modifica o atributo 'renavam' */

		void setTipoVeiculoVeiculo(int tv);			/* modifica o atributo 'tipoveiculo' */

		void setMarcaVeiculo(int m);				/* modifica o atributo 'marca' */


		/* funções Get da classe */

		std::string getPlacaVeiculo() const;		/* retorna o atributo 'placa' */

		int getAnoVeiculo() const;					/* retorna o atributo 'ano' */

		std::string getRenavamVeiculo() const;		/* retorna o atributo 'renavam' */

		int getTipoVeiculoVeiculo() const;			/* retorna o atributo 'tipoveiculo' */

		int getMarcaVeiculo() const;				/* retorna o atributo 'marca' */
};

#endif /* __VEICULO_H__ */