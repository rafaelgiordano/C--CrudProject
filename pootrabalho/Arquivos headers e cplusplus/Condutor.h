/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: Condutor.h

   Definição da classe Condutor, de seus atributos e métodos.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

#ifndef __CONDUTOR_H__
#define __CONDUTOR_H__

/* inclusão das bibliotecas do sistema */
#include <iostream>
#include <string>

/* inclusão dos headers referentes às classes utilizadas */
#include "Cliente.h"

class Apolice;		/* forward declaration */

class Condutor: public Cliente
{
	private:

		static const int MAX;	/* atributo constante da classe */

		int qtdeApolice;		/* contador da quantidade de apólices */

		std::string numCNH;		/* número da CNH do condutor */

		int idade;				/* idade do condutor */

	public:

		Condutor();		/* construtor */

		~Condutor();	/* destrutor */

		/* funções Set da classe */

		void setNomeCondutor(std::string n);		/* modifica o atributo 'nome' */

		void setTelefoneCondutor(std::string t);	/* modifica o atributo 'telefone' */

		void setEnderecoCondutor(std::string e);	/* modifica o atributo 'endereco' */

		bool setApoliceCondutor(Apolice *ap);		/* modifica o atributo 'apolice' */

		void setCNHCondutor(std::string cnh);		/* modifica o atributo 'numCNH' */

		void setIdadeCondutor(int x);				/* modifica o atributo 'idade' */

		void setCPFCondutor(std::string cpf);		/* modifica o atributo 'CPF' */

		/* funções Get da classe */

		std::string getNomeCondutor();				/* retorna o atributo 'nome' */

		std::string getTelefoneCondutor();			/* retorna o atributo 'telefone' */

		std::string getEnderecoCondutor();			/* retorna o atributo 'endereco' */

		std::string getCNHCondutor();				/* retorna o atributo 'numCNH' */

		int getIdadeCondutor();						/* retorna o atributo 'idade' */

		std::string getCPFCondutor();				/* retorna o atributo 'CPF' */

		// Apolice getApoliceCondutor();
};

#endif /* __CONDUTOR_H__ */