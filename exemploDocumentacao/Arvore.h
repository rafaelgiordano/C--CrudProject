/*******************************************************************************
 * DESCRICAO:																   *
 *				 				 											   *
 *      Classe ABB, implementada com a intecao de virar um template, a classe  *
 * e implementacao de uma arvore binaria com uma classe No interna no private. *
 * A classe No possui 14 metodos, sendo que 2 sao construtores, 2 retornam um  *
 * ponteiro para a classe No, 4 do tipo void, 2 do tipo bool, 2 friend, 1 do   *
 * tipo TChave e 1 do tipo TDado. A classe ABB possui 14 metodos, sendo que 1  *
 * construtor, 1 construtor de copia, 4 metodos void, 1 metodo bool, 1 metodo  *
 * TDado, 1 friend , 1 destrutor e 4 metodos que retornam um ponteiro para     *
 * classe No.																   *                   
 *																	           *
 * DATA DA ULTIMA MODIFICACAO:                                                 *
 *		-> 25/11/2009														   *
 *																			   *
 *																			   *
 *																		       *
 *******************************************************************************/


//Bibliotecas//////////////
#include <iostream>		///
#include <string>		///
///////////////////////////


template < class TChave , class TDado >
class ABB
{
private:

	/* Classe No, ela e uma classe interna a classe ABB. */
	class No
	{
	public:

		/* Construtor padrao da classe No. */
		No ( );

		/* Construtor sobrecarregado da classe No. */
		No ( TDado item2 , TChave chave2 , No *dir = NULL , No *esq = NULL );

		/* Retorna o atributo 'direita'. */
		No* getDir ( );

		/* Retorna o atributo 'esquerda'. */
		No* getEsq ( );

		/* Retorna o atributo 'item'. */
		TDado getItem ( );

		/* Retorna o atributo 'chave'. */
		TChave getChave ( );

		/* Modifica o atributo 'direita'. */
		void setDir ( No *dir );

		/* Modifica o atributo 'esquerda'. */
		void setEsq ( No *esq );

		/* Modifica o atributo 'item'. */
		void setItem ( TDado item2 );

		/* Modifica o atributo 'chave'. */
		void setChave ( TChave chave2 );

		/* Sobrecarga do operador para o '<' para o tipo TChave. */
		bool operator< ( const TChave &obj );

		/* Sobrecarga do operador para o '==' para o tipo TChave. */
		bool operator== ( const TChave &obj );

	private:

		/* Atributo 'esquerda' e um ponteiro que aponta para o No da
		 * esquerda. */
		No *esquerda;

		/* Atributo 'direita' e um ponteiro que aponta para o No da direita. */
		No *direita;

		/* Atributo 'item' guarda a informacao dentro do No. */
		TDado item;

		/* Atributo 'chave' e a identificacao de um elemento. */
		TChave chave;
	};
public:

	/*Construtor padrao.*/
	ABB ( );

	/* Construtor de copia. */
	ABB ( ABB &arv );

	/* Metodo verifica se a arvore esta vazia. */
	bool vazia ( );

	/* Metodo insere um novo elemento na arvore. */
	void inserir ( TChave chave , TDado item );

	/* Metodo que remove o elemento que possui o atributo 'chave' que o cliete
	 * quer. */
	void remove ( TChave chave );

	/* Metodo imprime todos os elementos de uma  arvore (In - Order). */
	void mostra ( No* aux , std::ostream &out );

	/* Metodo que realiza uma busca na arvore e retorna um dado. */
	TDado busca ( TChave chave );

	/* Operador sobrecarregado para que seja possivel a escrita do de um objeto
	 * ABB<TChave, TDado>. */
	template < typename TChave2 , typename TDado2 >
	friend std::ostream& operator<< ( std::ostream & out , ABB < TChave2 ,
			TDado2 > & obj )
	{
		obj.mostra(obj.raiz, out);
		return out;
	}

	/* Destrutor. */
	~ABB ( );

	/* Copia uma arvora para outra. */
	void copia ( No* aux , ABB < TChave , TDado > &copiar );

	/* Metodo que realiza uma busca na arvore e retorna um no. */
	No* buscaRecursiva ( No *auxNo , TChave chave );

	/* Metodo informa qual o menor elemento da arvore. */
	No* menorElemento ( No *arv );

	/* Metodo informa qual o maior elemento da arvore. */
	No* maiorElemento ( );

	/* Metodo retorna o atributo 'raiz'. */
	No* getRaiz ( );

private:

	/* Atributo 'raiz' e um ponteiro que aponta para o primeiro elemento da
	 * arvore. */
	No *raiz;
};

/******************************************************************************
 ******************************************************************************
 ******************************************************************************/

/* Construtor padrao da classe No, inicializa as variaveis 'esquerda', 'direita'
 * com NULL e 'altura' com 0 (sera modificada no metodo de inserir). 
 * Dados de entrada : Nenhum.
 * Dados de saida: Nenhum.*/
template < class TChave , class TDado >
ABB < TChave , TDado >::No::No ( )
{
	esquerda = NULL;
	direita = NULL;
}

/* Construtor sobrecarregado da classe No, inicializa as variaveis 'direita',
 * 'esquerda' e 'item' de acordo com o usuario.
 * Dados de entrada : TDado item2, TChave chave2, No *dir No *esq.
 * Dados de saida: Nenhum.*/
template < class TChave , class TDado >
ABB < TChave , TDado >::No::No ( TDado item2 , TChave chave2 , No *dir ,
		No *esq )
{
	direita = dir;
	esquerda = esq;
	item = item2;
	chave = chave2;
}

/* Metodo da classe No que retorna o atributo 'direita'.
 * Dados de entrada : Nenhum.
 * Dados de saida: No* direita . */
template < class TChave , class TDado >
typename ABB < TChave , TDado >::No* ABB < TChave , TDado >::No::getDir ( )
{
	return direita;
}

/* Metodo da classe No que retorna o atributo 'direita'. 
 * Dados de entrada : Nenhum.
 * Dados de saida: No* esquerda. */
template < class TChave , class TDado >
typename ABB < TChave , TDado >::No* ABB < TChave , TDado >::No::getEsq ( )
{
	return esquerda;
}

/* Metodo da classe No que retorna o atributo 'item'.
 * Dados de entrada : Nenhum.
 * Dados de saida: TDado item. */
template < class TChave , class TDado >
TDado ABB < TChave , TDado >::No::getItem ( )
{
	return item;
}

/* Metodo da classe No que retorna o atributo 'chave'.
 * Dados de entrada : Nenhum.
 * Dados de saida: TChave chave. */
template < class TChave , class TDado >
TChave ABB < TChave , TDado >::No::getChave ( )
{
	return chave;
}

/* Metodo da classe No que modifica o atributo 'direita'.
 * Dados de entrada : No *dir.
 * Dados de saida: Nenhum. */
template < class TChave , class TDado >
void ABB < TChave , TDado >::No::setDir ( No *dir )
{
	direita = dir;
}

/* Metodo da classe No que modifica o atributo 'esquerda'.
 * Dados de entrada : No *esq.
 * Dados de saida: Nenhum. */
template < class TChave , class TDado >
void ABB < TChave , TDado >::No::setEsq ( No *esq )
{
	esquerda = esq;
}

/* Metodo da classe No que modifica o atributo 'item'.
 * Dados de entrada : TDado item2.
 * Dados de saida: Nenhum. */
template < class TChave , class TDado >
void ABB < TChave , TDado >::No::setItem ( TDado item2 )
{
	item = item2;
}

/* Metodo da classe No que modifica o atributo 'chave'.
 * Dados de entrada : TChave chave2.
 * Dados de saida: Nenhum. */
template < class TChave , class TDado >
void ABB < TChave , TDado >::No::setChave ( TChave chave2 )
{
	chave = chave2;
}

/* Metodo sobrecarregado da classe No, ele permite a comparacao de menor de
 * dois objetos do tipo TChave.
 * Dados de entrada : TChave &obj.
 * Dados de saida: booleano(true ou false). */
template < class TChave , class TDado >
bool ABB < TChave , TDado >::No::operator< ( const TChave &obj )
{
	if ( chave < obj.chave )
		return true;
	return false;
}

/* Metodo sobrecarregado da classe No, ele permite a comparacao de igualdade
 * de dois objetos do tipo TChave.
 * Dados de entrada : TChave &obj.
 * Dados de saida: booleano(true ou false). */
template < class TChave , class TDado >
bool ABB < TChave , TDado >::No::operator== ( const TChave &obj )
{
	if ( chave == obj.chave )
		return true;
	return false;
}

/******************************************************************************
 ******************************************************************************
 ******************************************************************************/

/* Construtor padrao da classe ABB, inicializa a variavel raiz com NULL.
 * Dados de entrada : Nenhum.
 * Dados de saida: Nenhum. */
template < class TChave , class TDado >

ABB < TChave , TDado >::ABB ( )
{
	raiz = NULL;
}

/* Construtor de copia da arvore ABB, ela inicializa a raiz com NULL e
 * executa o metodo copia com o primeiro parametro sendo sua raiz, e o
 * segundo sendo ela mesma.
 * Dados de entrada : ABB < TChave , TDado > &arv.
 * Dados de saida: Nenhum. */
template < class TChave , class TDado >
ABB < TChave , TDado >::ABB ( ABB < TChave , TDado > &arv )
{
	raiz = NULL;
	this->copia(arv.raiz, arv);
}

/* Metodo da classe ABB que verifica se a arvore esta vazia, se ela estiver
 retorna um codigo 'true', caso contrario retorna um codigo de erro 'false'.
 * Dados de entrada : Nenhum.
 * Dados de saida: booleano ( true ou false ). */
template < class TChave , class TDado >
bool ABB < TChave , TDado >::vazia ( )
{
	if ( raiz == NULL )
		return true;
	return false;
}

/* Metodo da classe ABB, que e um metodo recursivo para copiar uma arvore
 * para outra, ela recebe como parametro um ponteiro No e uma arvore. O
 * metodo vai inserindo novos elementos de acordo com a chamada do metodo.
 * Dados de entrada : No* aux , ABB < TChave , TDado > &copiar.
 * Dados de saida: Nenhum. */
template < class TChave , class TDado >
void ABB < TChave , TDado >::copia ( No* aux , ABB < TChave , TDado > &copiar )
{
	if ( aux != NULL )
	{
		inserir(aux->getChave(), aux->getItem());
		/* Recursao. */
		copia(aux->getEsq(), copiar);
		/* Recursao. */
		copia(aux->getDir(), copiar);
	}
}

/* Metodo da classe ABB que insere um elemento na arvore, ela retorna um codigo
 * 'true' caso o elemento for inserido com sucesso, caso contrario retorna um
 * codigo de erro 'false'.
 * Dados de entrada : TChave chave , TDado item.
 * Dados de saida: Nenhum. */
template < class TChave , class TDado >
void ABB < TChave , TDado >::inserir ( TChave chave , TDado item )
{

	No *verificacao;
	verificacao = this->buscaRecursiva(getRaiz(), chave);
	try
	{
		/* Verificacao necessaria para saber se o elemento a ser inserido
		 * ja existe. Se existir e lancado um codigo para o bloco
		 * catch(typename ABB<TChave, TDado>::No*). */
		if ( verificacao != NULL )
			throw verificacao;
		try
		{
			No *novoNo;
			/* Tentativa de alocar memoria, se nao conseguir e lancado um
			 * codigo para o bloco catch(std::bad_alloc). */
			novoNo = new No(item, chave);

			/* Verifica se a arvore esta inicialmente vazia. */
			if ( vazia() )
			{
				raiz = novoNo;

			}
			else
			{
				No *auxNo = raiz , *auxNo2 = NULL;
				/* 'auxNo' vai ate o ultimo elemento (NULL) da arvore em que o
				 * elemento sera inserido. */
				while ( auxNo != NULL )
				{
					/* Se o elemento que queremos inserir for menor que o que
					 * ele esta analizando no momento ele vai para o proximo
					 * no a esquerda. Senao ele vai para o no a direita. */
					if ( novoNo->getChave() < auxNo->getChave() )
					{
						auxNo2 = auxNo;
						auxNo = auxNo->getEsq();
					}
					else
					{
						auxNo2 = auxNo;
						auxNo = auxNo->getDir();
					}
				}

				/* Se o no que queremos inserir for menor que o no do 'auxNo2'
				 * entao colocamos ele em um no a sua esquerda. Senao colocamos
				 * ele num no a sua direita.*/
				if ( novoNo->getChave() < auxNo2->getChave() )
				{
					auxNo2->setEsq(novoNo);
				}
				else
				{
					auxNo2->setDir(novoNo);
				}

			}

		}
		catch ( std::bad_alloc )
		{
			std::cout << "Erro na alocacao de memoria!" << std::endl;
			std::cout << "Insercao cancelada!" << std::endl;
		}

	}
	catch ( typename ABB < TChave , TDado >::No* )
	{
		std::cout << "Erro! ";
		std::cout << "Insercao cancelada" << std::endl;
	}
}

/* Metodo da classe ABB que remove o elemento que o usuario deseja, verifica se
 * exite elementos na arvore, se existe o elemento em que quer ser deletado e
 * logo apos realiza a remocao.
 * Dados de entrada : TChave chave.
 * Dados de saida: Nenhum. */
template < class TChave , class TDado >
void ABB < TChave , TDado >::remove ( TChave chave )
{
	No *auxNo;
	/* Verifica se a arvore esta vazia. */
	try
	{
		if ( vazia() )
			throw false;

		No *verificacao;
		verificacao = this->buscaRecursiva(getRaiz(), chave);
		/* Verifica se existe esse elemento na arvore. */
		try
		{
			if ( verificacao == NULL )
				throw verificacao;

			/* Verifica se o no a ser removido e uma raiz. */
			if ( chave == raiz->getChave() )
			{
				/* Remover raiz sem filhos. */
				if ( raiz->getDir() == NULL && raiz->getEsq() == NULL )
				{
					auxNo = raiz;
					raiz = NULL;
					delete auxNo;
				}
				else
				{

					/* Remover raiz com 2 filhos. Procuro o menor no da
					 * sub-arvore direita e procuro o menor no desta arvore. */
					if ( raiz->getDir() != NULL && raiz->getEsq() != NULL )
					{
						No *aux;
						No *menor = menorElemento(raiz->getDir());
						aux = raiz->getDir();
						menor->setEsq(raiz->getEsq());
						while ( aux->getEsq() != NULL
								&& aux->getEsq()->getChave()
								!= menor->getChave() && aux->getChave()
								!= menor->getChave() )
						{
							aux = aux->getEsq();
						}
						if ( menor->getChave() != aux->getChave() )
						{
							aux->setEsq(NULL);
							if ( menor->getDir() == NULL )
							{
								menor->setDir(raiz->getDir());
							}
							else
							{
								aux = menor->getDir();
								while ( aux->getDir() != NULL )
								{
									aux = aux->getDir();
								}
								aux->setDir(raiz->getDir());
							}
						}
						raiz = menor;
					}
					else
					{

						/* Remove raiz com 1 filho. */
						/* Verificando se o filho esta na esquerda. */
						if ( raiz->getEsq() != NULL )
						{
							auxNo = raiz;
							raiz->setDir(raiz->getEsq());
							raiz = raiz->getEsq();
						}
						/* Verifica se o filho esta na direita. */
						else
						{
							auxNo = raiz;
							raiz->setDir(raiz->getDir());
							raiz = raiz->getDir();
						}
						delete auxNo;
					}
				}
			}
			/* Remover folha */
			else
			{
				No *auxNo = raiz;
				No *auxNo2 = NULL;
				/* While necessario para que o auxNo aponte para o no que
				 * queremos remover e que auxNo2 aponte para o no anterior
				 * a ele. */
				while ( auxNo != NULL && auxNo->getChave() != chave )
				{
					if ( chave < auxNo->getChave() )
					{
						auxNo2 = auxNo;
						auxNo = auxNo->getEsq();
					}
					else
					{
						auxNo2 = auxNo;
						auxNo = auxNo->getDir();
					}
				}
				/* Pai sem filhos. */

				if ( auxNo->getDir() == NULL && auxNo->getEsq() == NULL )
				{
					if ( auxNo2->getDir() == auxNo )
					{
						auxNo2->setDir(NULL);
					}
					else
					{
						auxNo2->setEsq(NULL);
					}
					delete auxNo;
				}
				else
				{
					/* Pai com 2 filhos. Procuro o menor no da sub-arvore
					 * direita e procuro o menor no desta arvore. */

					if ( auxNo->getDir() != NULL && auxNo->getEsq() != NULL )
					{
						No *menor = menorElemento(auxNo->getDir());
						No *aux = auxNo->getDir();
						menor->setEsq(auxNo->getEsq());
						while ( aux->getEsq() != NULL
								&& aux->getEsq()->getChave()
								!= menor->getChave() && aux->getChave()
								!= menor->getChave() )
						{
							aux = aux->getEsq();
						}

						if ( menor->getChave() != aux->getChave() )
						{
							aux->setEsq(NULL);

							if ( menor->getDir() == NULL )
							{
								menor->setDir(auxNo->getDir());
							}
							else
							{
								aux = menor->getDir();
								while ( aux->getDir() != NULL )
								{
									aux = aux->getDir();
								}
								aux->setDir(auxNo->getDir());
							}
						}

						/* Verifica se auxNo2 esta na direita. */
						if ( auxNo2->getDir() == auxNo )
							auxNo2->setDir(menor);
						else
						{
							/* Verifica se auxNo2 esta na esquerda. */
							if ( auxNo2->getEsq() == auxNo )
								auxNo2->setEsq(menor);
						}
						delete auxNo;
					}
					else
					{
						/* Remove pai com 1 filho.
						 * Verificando se o filho esta na esquerda. */
						if ( auxNo->getEsq() != NULL )
						{
							if ( auxNo2->getDir() == auxNo )
								auxNo2->setDir(auxNo->getEsq());
							else
								auxNo2->setEsq(auxNo->getEsq());

						}
						/* Verifica se o filho esta na direita. */
						else
						{
							if ( auxNo2->getDir() == auxNo )
								auxNo2->setDir(auxNo->getDir());
							else
								auxNo2->setEsq(auxNo->getDir());

						}
						delete auxNo;
					}

				}
			}

		}
		catch ( typename ABB < TChave , TDado >::No* )
		{
			std::cout << "Remocao negada, elemento inexiste na arvore!"
					  << std::endl;
		}
	}
	catch ( bool )
	{
		std::cout << "Remocao negada, arvore vazia!" << std::endl;
	}
}

/* Metodo da classe ABB que realiza a exibicao de todos os elementos de uma
 * arvore. Utilizada a recusao para poder buscar todos os elementos dela. A
 * escrita e feita no modo In-Order, isso quer dizer que e feita em ordem
 * crescente. O metodo utiliza o 'std::ostream &out' em seu parametro pois
 * sobrecarregamos o operador de escrita (<<), com isso podemos mandar escrever
 * um objeto do tipo ABB com o  std::cout em qualquer parte do codigo.
 * Dados de entrada : No* aux , std::ostream &out.
 * Dados de saida: Nenhum. */
template < class TChave , class TDado >
void ABB < TChave , TDado >::mostra ( No* aux , std::ostream &out )
{
	/* Se aux for diferente de NULL ele vai realizar a recurcao para o no da
	 * esquerda, realizar a escrita do vertece e realizar a recursao para o no
	 * da direita. */
	if ( aux != NULL )
	{
		mostra(aux->getEsq(), out);
		out << "Chave: ";
		out << aux->getChave() << " ";
		out << "Item: ";
		out << aux->getItem() << " " << std::endl;
		mostra(aux->getDir(), out);
	}
}

/* Metodo da classe ABB que verifica qual o maior elemento de uma arvore.
 * Como o maior elemento sempre esta ao lado direito da arvore, nao precimos
 * verificar o lado esquerdo. Se a arvore estiver vazia ele retorna NULL, senao
 * retorna o endereco de memoria do maior no.
 * Dados de entrada : Nenhum.
 * Dados de saida: No* auxNo ou NULL. */
template < class TChave , class TDado >
typename ABB < TChave , TDado >::No* ABB < TChave , TDado >::maiorElemento ( )
{
	/* Verifica se a arvore esta vazia no momento. */
	if ( vazia() )
	{
		return NULL;
	}
	No *auxNo = raiz;
	/* Verifica a raiz e os elementos do lado direito de uma arvore ate que o
	 * no da direita de algum vertece seja NULL. */
	while ( auxNo->getDir() != NULL )
	{
		auxNo = auxNo->getDir();
	}

	return auxNo;
}

/* Metodo da classe ABB que verifica qual o maior elemento de uma arvore.
 * Como o menor elemento sempre esta ao lado esquerdo da arvore, nao precimos
 * verificar o lado direito. Se a arvore estiver vazia ele retorna NULL, senao
 * retorna o endereco de memoria do menor no.
 * Dados de entrada : No *arv.
 * Dados de saida: No *auxNo ou NULL. */
template < class TChave , class TDado >
typename ABB < TChave , TDado >::No* ABB < TChave , TDado >::menorElemento (
		No *arv )
{
	/* Verifica se a arvore esta vazia no momento. */
	if ( vazia() )
	{
		return NULL;
	}
	No *auxNo = arv;
	/* Verifica a raiz e os elementos do lado esquerdo de uma arvore ate que
	 * o no da esquerda de algum vertece seja NULL. */
	while ( auxNo->getEsq() != NULL )
	{
		auxNo = auxNo->getEsq();
	}

	return auxNo;
}

/* Metodo da classe ABB que retorna o atributo raiz.
 * Dados de entrada : Nenhum.
 * Dados de saida: No *raiz. */
template < class TChave , class TDado >
typename ABB < TChave , TDado >::No* ABB < TChave , TDado >::getRaiz ( )
{
	return raiz;
}

/* Metodo da classe ABB que busca na arvore o elemento que possui a chave em
 * que o cliente quer utilizando metodos recursivos. Se encontra-lo retorna o no
 * em que esse elemento possui. Se nao achar retorna NULL.
 * Dados de entrada : No *auxNo , TChave chave.
 * Dados de saida: No *auxNo ou NULL. */
template < class TChave , class TDado >
typename ABB < TChave , TDado >::No* ABB < TChave , TDado >::buscaRecursiva (
		No *auxNo , TChave chave )
{
	/* Verifica se a arvore esta vazia. */
	if ( vazia() )
	{
		return NULL;
	}
	if ( auxNo == NULL )
		return NULL;
	/* Inicia a procura. */
	if ( chave < auxNo->getChave() )
	{
		/* Recursao. */
		return buscaRecursiva(auxNo->getEsq(), chave);
	}
	else
	{
		if ( chave > auxNo->getChave() )
		{
			/* Recursao. */
			return buscaRecursiva(auxNo->getDir(), chave);
		}
		else
		{
			/* Se encontrar o elemento retorna o no. */
			return auxNo;
		}
	}
	/* Se nao encontrar o elemento retorna NULL. */
	return NULL;
}

/* Metodo da classe ABB que busca na arvore o elemento que possui a chave em
 * que o cliete quer. Se encontra-lo retorna o dado em que esse elemento possui.
 * Se nao achar retorna NULL.
 * Dados de entrada : TChave chave.
 * Dados de saida: TDado auxNo->getItem() ou NULL. */
template < class TChave , class TDado >
TDado ABB < TChave , TDado >::busca ( TChave chave )
{
	No *auxNo = raiz;
	/* Verifica se a arvore esta vazia. */
	if ( vazia() )
	{
		return NULL;
	}
	else
	{
		/* Comeca a procurar o elemento que possui a chave */
		while ( auxNo != NULL && auxNo->getChave() != chave )
		{
			if ( chave < auxNo->getChave() )
			{
                 /* procurar sub-arvore esquerda. */
				auxNo = auxNo->getEsq(); 
			}
			else
			{
                /* procurar sub-arvore direita. */
				auxNo = auxNo->getDir(); 
			}
		}
	}
	/* Se ele nao encontra o elemento retorna NULL. */
	if ( auxNo == NULL )
	{
		return NULL;
	}

	return auxNo->getItem();
}

/* Destrutor da classe ABB.
 * Dados de entrada : Nenhum.
 * Dados de saida: Nenhum. */
template < class TChave , class TDado >
ABB < TChave , TDado >::~ABB ( )
{
	No* aux;
	int x = 0;
	while ( !this->vazia() )
	{
		aux = this->maiorElemento();
		this->remove(aux->getChave());
		x++;
	}
	std::cout << "Arvore com " << x << " elementos foi removida!" << std::endl;
	this->raiz = NULL;
}
