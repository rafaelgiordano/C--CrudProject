/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: Cliente.h

   Definição da classe Cliente, de seus atributos e métodos.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

#ifndef __CLIENTE_H__
#define __CLIENTE_H__

/* inclusão das bibliotecas do sistema */
#include <iostream>
#include <fstream>

/* inclusão dos headers referentes às classes utilizadas */
#include "Apolice.h"
#include "PessoaFisica.h"

class Apolice;		/* forward declaration */

class Cliente: public PessoaFisica
{
	/* atributos da classe Cliente */
	private:
	
		static const int MAX;	/* atributo constante da classe */

		int qtdeApolice;		/* contador da quantidade de apólices */

		std::string nome;		/* nome do cliente */

		std::string telefone;	/* telefone do cliente */

		std::string endereco; 	/* endereço do cliente */
	
	/* métodos da classe Cliente */
	public:

		Apolice *apolice[100];  /* vetor de ponteiros para um objeto da classe Apolice */

		Cliente();  /* construtor */

		~Cliente(); /* destrutor */

		bool procurarVeiculoCliente(std::string placa);     /* pesquisa um veículo com a placa dada */

		bool excluirApoliceCliente(int pos);				/* exclui uma apólice na posição dada */

		bool alterarApoliceCliente(int pos, Apolice *ap);	/* modifica uma apólice na posição dada */

		void imprimirDadosApoliceCliente();					/* imprime os dados da apólice referente ao cliente */

		void salvarArquivoCliente(); 						/* salva em arquivo os dados */

		/* funções Set da classe */

		void setNomeCliente(std::string n);					/* modifica o atributo 'nome' */

		void setTelefoneCliente(std::string t);				/* modifica o atributo 'telefone' */

		void setEnderecoCliente(std::string e);				/* modifica o atributo 'endereco' */

		bool setApoliceCliente(Apolice *ap);				/* modifica o atributo 'apolice' */

		void setCPFCliente(std::string cpf);				/* modifica o atributo 'CPF' */

		/* funções Get da classe */

		std::string getNomeCliente() const;					/* retorna o atributo 'nome' */

		std::string getTelefoneCliente() const;				/* retorna o atributo 'telefone' */

		std::string getEnderecoCliente() const;				/* retorna o atributo 'endereco' */

		std::string getCPFCliente() const;					/* retorna o atributo 'CPF' */

		int getQtdeApoliceCliente() const;					/* retorna o atributo 'qtdeApolice' */

};

#endif /* __CLIENTE_H__ */