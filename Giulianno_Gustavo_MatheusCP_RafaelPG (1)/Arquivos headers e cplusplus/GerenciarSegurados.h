/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: GerenciarSegurados.h

   Definição da classe GerenciarSegurados, de seus atributos e métodos.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

#ifndef __GERENCIARSEGURADOS_H__
#define __GERENCIARSEGURADOS_H__

/* inclusão das bibliotecas do sistema */
#include <iostream>
#include <fstream>

/* inclusão dos headers referentes às classes utilizadas */
// #include "Condutor.h"
#include "Cliente.h"
#include "Apolice.h"

// class Condutor;

class Cliente;		/* forward declaration */

class Apolice;		/* forward declaration */

class GerenciarSegurados
{
	/* atributos da classe GerenciarSegurados */
	private:

		static const int MAX;    /* atributo constante da classe */

		int qtdeCliente;         /* contador da quantidade de clientes */

		int qtdeCondutor;	     /* contador da quantidade de condutores */

		Cliente *cliente[100];   /* vetor de ponteiros para um objeto da classe Cliente */

		// Condutor *condutor[100];

	/* métodos da classe GerenciarSegurados */
	public:

		GerenciarSegurados();  /* construtor */

		~GerenciarSegurados(); /* destrutor */

		bool criarCliente(std::string n, std::string t, std::string e, int pos, std::string cpf);		/* chama as funções Set da classe 'Cliente', passando seus parâmetros */

		bool alterarCliente(std::string n, std::string t, std::string e, int pos, std::string cpf);		/* chama a função criarCliente, passando seus parâmetros */

		bool excluirCliente(int pos);																	/* devolve a memória alocada na posição dada, puxa os demais elemento do vetor */

		bool consultarCliente();																		/* procura por determinado cliente */

		bool imprimirDadosCliente();																	/* imprime os dados de todos os clientes */

		bool consultarVeiculo(std::string placa);														/* procura por um veículo de mesma placa */

		bool removerApolice(int posicao, int pos);														/* remove uma determinada apólice de um determinado cliente */

		bool alterarApolice(int posicao, int pos, Apolice *ap);											/* altera uma determinada apólice de um determinado cliente */

		bool vincularApoliceCliente(Apolice *ap, int pos);												/* chama a função setApoliceCliente da classe 'Cliente', dada a posição */

		void salvarArquivo();																			/* salva em arquivo os dados */

		// bool criarCondutor(std::string n, std::string t, std::string e, Apolice *ap, std::string CNH, int idade_cond, std::string cpf, int pos);

		// bool alterarCondutor(std::string n, std::string t, std::string e, Apolice *ap, std::string CNH, int idade_cond, std::string cpf, int pos);

		// bool excluirCondutor(int pos);

		// bool consultarCondutor(int pos);

		// bool imprimirDadosCondutor();
};

#endif /* __GERENCIARSEGURADOS_H__ */