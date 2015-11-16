/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: Terceiro.h

   Definição da classe Terceiro, de seus atributos e métodos.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

#ifndef __TERCEIRO_H__
#define __TERCEIRO_H__

/* inclusão das bibliotecas do sistema */
#include <iostream>
#include <string>

/* inclusão dos headers referentes às classes utilizadas */
#include "PessoaFisica.h"

class Terceiro: public PessoaFisica
{
	/* atributos da classe Terceiro */
	private:

		std::string seguradora;		/* nome da seguradora */

		std::string nome;			/* nome do terceiro */

		std::string telefone;		/* telefone do terceiro */

		std::string endereco;		/* endereço do terceiro */

		int idade;					/* idade do terceiro */

	/* métodos da classe Terceiro */
	public:

		/* funções Set da classe */  

		void setIdadeTerceiro(int anos);							/* modifica o atributo 'idade' */

		void setNomeTerceiro(std::string nomeTerceiro);				/* modifica o atributo 'nome' */

		void setTelefoneTerceiro(std::string tel);					/* modifica o atributo 'telefone' */

		void setEnderecoTerceiro(std::string end);					/* modifica o atributo 'endereco' */

		void setSeguradoraTerceiro(std::string seguroTerceiro);		/* modifica o atributo 'seguradora' */

		void setCPFTerceiro(std::string cpf);						/* modifica o atributo 'CPF' */

		/* funções Get da classe */

		int getIdadeTerceiro() const;								/* retorna o atributo 'idade' */

		std::string getNomeTerceiro() const;						/* retorna o atributo 'nome' */

		std::string getTelefoneTerceiro() const;					/* retorna o atributo 'telefone' */

		std::string getEnderecoTerceiro() const;					/* retorna o atributo 'endereco' */

		std::string getSeguradoraTerceiro() const;					/* retorna o atributo 'seguradora' */

		std::string getCPFTerceiro() const;							/* retorna o atributo 'CPF' */
};

#endif /* __TERCEIRO_H__ */