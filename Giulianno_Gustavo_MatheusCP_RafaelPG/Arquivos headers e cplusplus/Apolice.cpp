/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: Apolice.cpp

   Definição dos métodos da classe Apolice.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

/* inclusão dos headers referentes às classes utilizadas */
#include "Apolice.h"

using namespace std;

const int Apolice::MAX = 100; /* define o tamanho máximo do vetor de ponteiros */

/* construtor da classe, zera os contadores e atribui NULL a todas as posições dos vetores de ponteiros */
Apolice::Apolice()
{
	qtdeSinistro = 0;
	qtdeOrcamento = 0;

	for (int i = 0; i < MAX; i++)
	{
		sinistro[i] = NULL;
		orcamento[i] = NULL;
	}
}

/* destrutor da classe, devolve a memória alocada por cada ponteiro dos vetores de ponteiros, depois atribui NULL */
Apolice::~Apolice()
{
	for (int i = 0; i < qtdeSinistro; i++)
	{
		if (sinistro[i] != NULL)
		{
			delete sinistro[i];
			sinistro[i] = NULL;
		}
	}

	for (int i = 0; i < qtdeOrcamento; i++)
	{
		if (orcamento[i] != NULL)
		{
			delete orcamento[i];
			orcamento[i] = NULL;
		}
	}
}

/* chama as funções Set da classe para atrbuir valor aos atributos */
void Apolice::criarApolice(int x, int c, Data d, Veiculo *veic, Orcamento *orcam) 
{
	setNumApolice(x);
	setClassificacaoApolice(c);
	setVigenciaApolice(d);
	setVeiculoApolice(veic);
	setOrcamentoApolice(orcam);
	// setCondutorApolice(cond);
	// setSinistroApolice(snt);
}

/* função Set que modifica o atributo 'num' */
void Apolice::setNumApolice(int x)
{
	num = x;
}

/* função Set que modifica o atributo 'classificacao' */
void Apolice::setClassificacaoApolice(int c)
{
	classificacao = c;
}

/* função Set que modifica o atributo 'vigencia' */
void Apolice::setVigenciaApolice(Data d)
{
	vigencia = d;
}

/* função Set para o atributo veiculo */
void Apolice::setVeiculoApolice(Veiculo *veic)
{
	veiculo = veic;
}

/* função Set para o atributo sinistro, utiliza o contador para que cada índice do vetor de ponteiros aponte para o objeto corretamente */
bool Apolice::setSinistroApolice(Sinistro *snt)
{
	if (qtdeSinistro == MAX)
	{
		return false;
	}

	sinistro[qtdeSinistro] = snt;
	qtdeSinistro++;

	return true;
}

/* função Set para o atributo orcamento, utiliza o contador para que cada índice do vetor de ponteiros aponte para o objeto corretamente */
bool Apolice::setOrcamentoApolice(Orcamento *orcam)
{
	if (qtdeOrcamento == MAX)
	{
		return false;
	}

	orcamento[qtdeOrcamento] = orcam;
	qtdeOrcamento++;

	return true;
}

// void Apolice::setCondutorApolice(Condutor *cond)
// {
// 	condutor = cond;
// }

/* função Get que retorna o número da apólice */
int Apolice::getNumApolice() const
{
	return num;
}

/* função Get que retorna a classificação da apólice */
int Apolice::getClassificacaoApolice() const
{
	return classificacao;
}

/* função Get que retorna a quantidade de sinistros da apólice */
int Apolice::getQtdeSinistro() const
{
	return qtdeSinistro;
}

/* função Get que retorna a quantidade de orçamentos da apólice */
int Apolice::getQtdeOrcamento() const
{
	return qtdeOrcamento;
}

/* função Get que retorna a data de vigência da apólice */
Data Apolice::getVigenciaApolice() const
{
	return vigencia;
}

/* função Get que retorna o veículo da apólice */
Veiculo* Apolice::getVeiculoApolice() const
{
	return veiculo;
}

/* se não houver orçamentos na apólice, o método retorna false. Caso contrário, é impresso o acumulado do valor de cada orçamento */
bool Apolice::gerarOrcamentoApolice() 
{
	if (qtdeOrcamento == 0)
	{
		return false;
	}

	cout << "Orçamento da apólice: " << GerenciarOrcamento::getValorTotal << endl;

	return true;
}

/* imprime as informações referentes ao boleto da apólice */
void Apolice::gerarBoletoApolice() 
{
	cout << "BOLETO" << endl;
	cout << "Vencimento: " << vigencia.getDiaData() << "." << vigencia.getMesData() << "." << vigencia.getAnoData() << endl;
	
	if (!gerarOrcamentoApolice())
	{
		cout << "Não há orçamentos nesta apólice" << endl;
	}

	cout << "Número: " << num << endl;
	cout << "Classificação: " << classificacao << endl;
	cout << endl;
}

/* chama o método da classe Veiculo, que retorna a placa do veículo. A função retorna true se as placas forem iguais */
bool Apolice::pesquisarVeiculo(string placa)
{
	if (veiculo != NULL)
	{
		if ((placa) == (veiculo->getPlacaVeiculo()))
		{
			cout << endl << endl;
			cout << "Ano: " << veiculo->getAnoVeiculo() << endl;
			cout << "Placa: " << veiculo->getPlacaVeiculo() << endl;
			cout << "Renavam: " << veiculo->getRenavamVeiculo() << endl;
			cout << "Tipo veículo: ";

			if ((veiculo->getTipoVeiculoVeiculo()) == 1)
			{
				cout << "passeio" << endl;
			}
			else
			{
				cout << "transporte" << endl;
			}

			cout << "Marca: ";

			switch (veiculo->getMarcaVeiculo())
			{
				case 1:
				{
					cout << " Fiat" << endl;
				}
				break;

				case 2:
				{
					cout << " Volkswagen" << endl;
				}
				break;

				case 3:
				{
					cout << " Ford" << endl;
				}
				break;

				case 4:
				{
					cout << " Honda" << endl;
				}
			}

			return true;
		}
	}

	return false;
}

/* imprime as informações referentes aos dados da apólice */
void Apolice::imprimirDadosApolice()
{
	cout << "Data de vigência: " << vigencia.getDiaData() << "." << vigencia.getMesData() << "." << vigencia.getAnoData() << endl << endl;
	cout << "Veículo" << endl;
	cout << "Ano: " << veiculo->getAnoVeiculo() << endl;
	cout << "Placa: " << veiculo->getPlacaVeiculo() << endl;
	cout << "Renavam: " << veiculo->getRenavamVeiculo() << endl;
	cout << "Tipo veículo: ";

	if ((veiculo->getTipoVeiculoVeiculo()) == 1)
	{
		cout << "passeio" << endl;
	}
	else
	{
		cout << "transporte" << endl;
	}

	cout << "Marca: ";

	switch (veiculo->getMarcaVeiculo())
	{
		case 1:
		{
			cout << " Fiat" << endl;
		}
		break;

		case 2:
		{
			cout << " Volkswagen" << endl;
		}
		break;

		case 3:
		{
			cout << " Ford" << endl;
		}
		break;

		case 4:
		{
			cout << " Honda" << endl;
		}
	}
}

/* função que imprime os atributos da classe orçamento */
void Apolice::imprimirDadosOrcamentoApolice()
{
	for (int i = 0; i < getQtdeOrcamento(); i++)
	{
		cout << "Orçamento #" << i + 1 << endl;
		cout << "Tipo: " << orcamento[i]->getTipoOrcamento() << endl;
		cout << "Valor de ressarcimento: " << orcamento[i]->getValorRessarcOrcamento() << endl << endl;
	}

	cout << endl;
}

/* imprime as informações referentes aos dados do sinistro */
void Apolice::imprimirDadosSinistroApolice()
{
	for (int i = 0; i < getQtdeSinistro(); i++)
	{
		cout << "Sinistro #" << i + 1 << endl;
		cout << "Número: " << sinistro[i]->getNumSinistro() << endl;
		cout << "Local: " << sinistro[i]->getLocalSinistro() << endl;

		cout << "Tipo: ";

		switch(sinistro[i]->getTipoSinistro())
		{
			case 1:
			{
				cout << "incêndio" << endl;
			}
			break;

			case 2:
			{
				cout << "colisão" << endl;
			}
			break;

			case 3:
			{
				cout << "furto" << endl;
			}
			break;
		}

		sinistro[i]->imprimirDadosSinistro();
	}
}