/*******************************************************************************
 *		Programa concluido dia: 25/11/2009									   *
 *      Nome do arquivo: main.cpp											   *
 *      Author: Gabriel Trita Ferreira da Cunha                                *
 *      RA : 345024															   *
 *		Author: Rubens Onari Júnior                                            *
 *      RA : 317373                                                            *
 *		Author: Diego Lima De Freitas                                          *
 *      RA : 317632															   *
 *      Bacharelado de Ciencia da computacao - Estrutura de dados e            *
 *		Programacao orientada a objeto.										   *
 *                                                                             * 
 *******************************************************************************
 *      OBS: A descricao nao apresenta nenhuma acentuacao, pelo o fato do      *
 *      algoritmo ser feito em Windows, para que nao altere caracteres         *
 *      acentuados no Linux eu aderi retirar os acentos, para uma melhor       *
 *      visualizacao. Codigo realizado com o "print margin column" 80,         *
 *		portanto, alguns codigos ficaram com "quebra de linha" como no         *
 *      EXEMPLO:                                                               *
 *                                                                             *
 *	           while ( aux->getEsq() != NULL                                   *
 *			          && aux->getEsq()->getChave()                             *
 *			          != menor->getChave() && aux->getChave()                  *
 *			          != menor->getChave() )                                   *
 *                                                                             *
 *******************************************************************************
 *      Main() programado para ser um programa que realiza diversor testes     *
 *      sobre a arvore binaria de busca (ABB<TChave, TDado>) que esta          *
 *      implementada no arquivo Arvore.h, main() realiza cinco testes e no     *
 *      fim faz uma comparacao com uma arvore copiada ( com a ajuda do         *
 *      construtor de copia ) para verificar se a remocao realiza o esperado!  *
 *      Caso as professoras queserem testa-lo mais,basta implementar a         *
 *      remocao ou insercao de acordo com o codigo da Arvore.h mais creio que  *
 *      nao seja necessario, acho que todos os testes presentes no main() sao  *
 *      validos e suficientes para verificar a eficiencia dos algoritmos       *
 *      implementados no Arvore.h.                                             *
 ******************************************************************************/


//Bibliotecas/////////
#include <iostream>///
#include <time.h>  ///
#include <stdlib.h>///
#include<stdio.h>/////
#include "Arvore.h"///
//////////////////////


///////////////////////
using namespace std;///
///////////////////////


int main ( )
{
	
	/*Arvore binaria de busca*/
	ABB < int , std::string > A;
	int numero;
	int repetidos[ 100 ];
	/* Inicializando a semente do rand */
	srand(time(NULL));
	/* Explicativo do programa */
	cout << "Programa para realizacao de testes";
	cout << " sobre o template da arvore binaria de busca";
	cout << " ABB<TChave,TDado>." << endl;
	cout << "************************** INICIALIZANDO TESTES ****************";
	cout << "****************" << endl;
	cout << "Clique em qualquer tecla para continuar ..." << endl;
	getchar();
	system("cls");
	system("clear");

	cout << endl << endl << endl;
	/* Inicio de testes, tentativa de inserir 100 aleatorios na arvore A, por
	 * ser uma insercao utilizando o metodo rand(), ele tenta inserir qualquer
	 * numero que esteja no intervalo de 0 e 100, portanto, ele tenta inserir
	 * numeros repetidos, que obviamente nao seram inseridos, portanto, a arvore
	 * A tera menos que 100 elementos. */
	cout << "************************************INSERIR*********************";
	cout << "****************" << endl;
	cout << "Inserindo o numeros aleatorios: " << endl;
	/* Contador para o vetor de inteiros que sao repitidos */
	int k = 0;
	for ( int i = 0 ; i < 100 ; i++ )
	{
		/* Gerando um numero que esta entre 0 e 100. */
		numero = rand() % 100;
		/* Verificando de o numero a ser acrescentado ja existe na arvore. */
		if ( A.buscaRecursiva(A.getRaiz(), numero) == NULL )
		{
			/* Inserindo o numero na arvore. */
			A.inserir(numero, "TESTE");
			cout << numero << " ";
		}
		else
		{
			/* Vetor que armazena os numeros repitidos. */
			repetidos[ k ] = numero;
			k++;
		}
	}
	cout << endl << endl << endl;
	cout << "Numeros que nao foram inseridos";
	cout << " por causa de serem repitidos." << endl;
	for ( int i = 0 ; i < k ; i++ )
	{
		/* Mostra os valores repitidos. */
		cout << repetidos[ i ] << " ";
	}
	cout << endl << endl;
	cout << "Como podemos analizar tivemos numeros repetidos";
	cout << " ,portanto, nao foram inseridos!" << endl << endl;
	cout << "\t\t   ****************************************" << endl;
	cout << "Clique em qualquer tecla para continuar ..." << endl;
	getchar();
	system("cls");
	system("clear");
	cout << endl << endl << endl;

	/* Continuando os testes, inicia o teste do contrutor de copia. Criamos uma
	 * arvore B com um parametro a arvore A. Com isso e iniciado o construtor de
	 * copia, que copia todos os elementos de A para B. */
	cout << "*************************CONSTRUTOR DE COPIA!*******************";
	cout << "****************" << endl;
	/* Arvore B chama o construtor de copia. */
	ABB < int , string > B(A);
	cout << "Construtor de copia ok!" << endl << endl;
	cout << "Arvore B copia todos os elementos da arvore A";
	cout << " com sucesso! Verificamos seu resultado ";
	cout << "na aba de 'ESCRITA'" << endl << endl;
	cout << "\t\t   ****************************************" << endl;
	cout << "Clique em qualquer tecla para continuar ..." << endl;
	getchar();
	system("cls");
	system("clear");
	cout << endl << endl << endl;

	/* Continuando os testes, inicia o teste de escrita. Mandamos escrever as
	 * duas arvores ja criadas ( que por sinal sao iguais ). Mando escrever as
	 * duas pos quero verificar se todos os elementos de A foram inseridos com
	 * sucesso e se a arvore B copiou certo todos os elementos de A, com isso
	 * verificamos a eficacia do construtor de copia. */
	cout << "************************************ESCRITA!********************";
	cout << "****************" << endl;
	cout << "Escrevendo a arvore A e a arvore B(copia de A)" << endl;
	cout << "Clique em qualquer tecla para continuar ..." << endl;
	getchar();
	cout << endl << endl << endl;
	cout << "Arvore A: " << endl << endl << endl;
	cout << A;
	cout << endl;
	cout << "Clique em qualquer tecla para continuar ..." << endl;
	getchar();
	cout << endl << endl << endl;
	cout << "Arvore B ( Copia de A / pelo construtor de copia): " << endl
			<< endl << endl;
	cout << B << endl << endl;
	cout << "\t\t   ****************************************" << endl;
	cout << "Clique em qualquer tecla para continuar ..." << endl;
	getchar();
	system("cls");
	system("clear");
	cout << endl << endl << endl;

	/* Continuando os testes, inicia o teste de busca de um elemento na arvore
	 * binaria, e utilizado o metodo 'buscaRecursiva'. O teste inicia varios
	 * valores aleatorios e tanta acha-los na arvore A, com isso varios valores
	 * nao seram encontrados, e tambem varios valores seram encontrados, com
	 * isso podemos ver se o metodo busca consegue encontrar todos os elementos
	 * sem erros.*/
	cout << "*************************************BUSCA!*********************";
	cout << "****************" << endl;
	cout << "Iniciando busca de elementos ";
	cout << "na arvore A." << endl << endl;
	cout << "Clique em qualquer tecla para continuar ..." << endl;
	getchar();
	cout << endl << endl << endl;
	for ( int i = 0 ; i < 30 ; i++ )
	{
		/* Metodo que gera numeros aleatorios. */
		numero = rand() % 100;
		cout << "Buscando o numero " << numero << endl;
		/* Faz a busca do numero na arvore. */
		if ( A.buscaRecursiva(A.getRaiz(), numero) != NULL )
		{
			cout << "Numero " << numero << " foi achado!" << endl << endl;
		}
		else
		{
			cout << "Numero " << numero << " nao foi encontrado!" << endl
					<< endl;
		}

	}
	cout << "\t\t   ****************************************" << endl;
	cout << "Clique em qualquer tecla para continuar ..." << endl;
	getchar();
	system("cls");
	system("clear");
	cout << endl << endl << endl;

	/* Continuando os testes, inicia o teste de remover um elemento da arvore,
	 * para o teste vamos utilizar a funcao 'rand()' novamente , para gerar 100
	 * numeros aleatorios, entao ele tentara eliminar numeros nao existentes na
	 * arvore e tambem numeros existentes. Com isso podemos verificar se o
	 * metodo 'remove()' possui erros.*/
	cout << "************************************REMOVER!********************";
	cout << "****************" << endl;
	cout << "Sera gerando 100 numeros aleatorios para testar ";
	cout << "a remocao na arvore A." << endl << endl << endl;
	cout << "Clique em qualquer tecla para continuar ..." << endl;
	getchar();
	cout << endl << endl << endl;
	for ( int i = 0 ; i < 100 ; i++ )
	{
		/* Gera numeros aleatorios. */
		numero = rand() % 100;
		cout << "Tentativa de remover o numero: " << numero << endl;
		/* metodo que remove um elemento da arvore. */
		A.remove(numero);
		cout << endl;
	}

	cout << "\t\t   ****************************************" << endl;
	cout << "Clique em qualquer tecla para continuar ..." << endl;
	getchar();
	system("cls");
	system("clear");
	cout << endl << endl << endl;

	/* Fim dos testes, agora iniciamos o que dizemos em cima, que vamos realizar
	 * uma comparacao da arvore A com a arvore B para saber se os elementos de 
     * da arvore A foram removidos com sucesso. Se foi, a arvore A deve
     * apresentar bem menos numeros que a arvore B. */
	cout << "*************COMPARACAO DA ARVORE REMOVIDA COM A ARVORE COPIADA*";
	cout << "****************" << endl;
	cout << "Clique em qualquer tecla para continuar ..." << endl;
	getchar();
	cout << endl << endl << endl;
	cout << "Comparacao da arvore A com a sua copia(arvore B) para verificar";
	cout << " os elementos removidos: " << endl;
	cout << endl << endl << endl;
	cout << "Copia inicial: " << endl;
	cout << endl << endl << endl;
	cout << B;
	cout << endl << endl << endl;
	cout << "Arvore A com elementos removidos: " << endl;
	cout << endl << endl << endl;
	cout << A;
	cout << "\t\t   ****************************************" << endl;
	cout << "Clique em qualquer tecla para continuar ..." << endl;
	getchar();
}
