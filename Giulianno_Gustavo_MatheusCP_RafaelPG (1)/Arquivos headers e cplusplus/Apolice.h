/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: Apolice.h

   Definição da classe Apolice, de seus atributos e métodos.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

#ifndef __APOLICE_H__
#define __APOLICE_H__

/* inclusão das bibliotecas do sistema */
#include <iostream>
#include <fstream>

/* inclusão dos headers referentes às classes utilizadas */
#include "Veiculo.h"
#include "Sinistro.h"
#include "Orcamento.h"
#include "Data.h"
#include "GerenciarOrcamento.h"
// #include "Condutor.h"

// class Condutor;

class Data;			/* forward declaration */

class Veiculo;		/* forward declaration */

class Sinistro;		/* forward declaration */

class Orcamento;	/* forward declaration */

class Apolice
{
	/* atributos da classe Apolice */
	private:

		static const int MAX; 		/* atributo constante da classe */

		int num;	          		/* número da apólice */
		
		int classificacao;    		/* classificação da apólice */

		int qtdeSinistro;     		/* contador da quantidade de sinistros */

		int qtdeOrcamento;    		/* contador da quantidade de orçamentos */
		
		Data vigencia;		 		/* objeto da classe Data onde é armazenada a data de vigência da apólice */

		Veiculo *veiculo;     		/* ponteiro para um objeto da classe Veiculo */

		Sinistro *sinistro[100];    /* vetor de ponteiros para um objeto da classe Sinistro */

		Orcamento *orcamento[100];  /* vetor de ponteiros para um objeto da classe Orcamento */

		// Condutor *condutor;

	/* métodos da classe Apolice */
	public:

		Apolice();  /* construtor */

		~Apolice(); /* destrutor */

		void criarApolice(int x, int c, Data d, Veiculo *veic, Orcamento *orcam); /* chama as funções Set para modificar os atributos da classe Apolice */

		bool gerarOrcamentoApolice();				/* imprime o orçamento da apólice */

		void gerarBoletoApolice();					/* imprime o boleto da apólice */

		bool pesquisarVeiculo(std::string placa);	/* pesquisa por um veículo */

		void imprimirDadosApolice();				/* imprime os dados da apólice */

		void imprimirDadosOrcamentoApolice();		/* imprime os dados dos orçamentos da apólice */

		void imprimirDadosSinistroApolice();		/* imprime os dados dos sinistros da apólice */

		void salvarArquivoApolice();				/* salva em arquivo os dados */

		void salvarArquivoOrcamentoApolice();		/* salva em arquivo os dados */

		void salvarArquivoSinistroApolice(); 		/* salva em arquivo os dados */

		/* funções Set da classe */

		void setNumApolice(int x);					/* modifica o atributo 'num' */

		void setClassificacaoApolice(int c);		/* modifica o atributo 'classificacao' */

		void setVigenciaApolice(Data d);			/* modifica o atributo 'vigencia' */

		void setVeiculoApolice(Veiculo *veic);		/* modifica o atributo 'veiculo' */

		bool setSinistroApolice(Sinistro *snt);		/* modifica o atributo 'sinistro' */

		bool setOrcamentoApolice(Orcamento *orcam); /* modifica o atributo 'orcamento' */

		// void setCondutorApolice(Condutor *cond);

		/* funções Get da classe */

		int getNumApolice() const;					/* retorna o atributo 'num' */

		int getClassificacaoApolice() const;		/* retorna o atributo 'classificacao' */

		int getQtdeSinistro() const;				/* retorna o atributo 'qtdeSinistro' */

		int getQtdeOrcamento() const;				/* retorna o atributo 'qtdeOrcamento' */

		Data getVigenciaApolice() const;			/* retorna o atributo 'vigencia' */

		Veiculo* getVeiculoApolice() const;			/* retorna o atributo 'veiculo' */
};

#endif /* __APOLICE_H__ */