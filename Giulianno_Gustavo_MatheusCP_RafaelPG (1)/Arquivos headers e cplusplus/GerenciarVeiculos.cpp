/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: GerenciarVeiculos.cpp

   Definição dos métodos da classe GerenciarVeiculos.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

/* inclusão dos headers referentes às classes utilizadas */
#include "GerenciarVeiculos.h"

using namespace std;

/* construtor da classe, aloca espaço suficiente para um objeto da classe Veiculo */
GerenciarVeiculos::GerenciarVeiculos()
{
	try 
	{
		veiculo = new Veiculo;
	}

	catch(bad_alloc)
	{
		cout << "Memória insuficiente!" << endl;
	}
}

/* destrutor da classe, devolve a memória que foi alocada */
GerenciarVeiculos::~GerenciarVeiculos()
{
	delete veiculo;
}

/* chama as funções Set da classe para atribuir valores aos atributos */
void GerenciarVeiculos::inserirVeiculo(string p, int x, string r, int tv, int m)
{
	veiculo->setPlacaVeiculo(p);
	veiculo->setAnoVeiculo(x);
	veiculo->setRenavamVeiculo(r);
	veiculo->setTipoVeiculoVeiculo(tv);
	veiculo->setMarcaVeiculo(m);
}

/* método que imprime os atributos da classe */
void GerenciarVeiculos::imprimirDadosVeiculo()
{
	cout << "Impressão do veículo" << endl;
	cout << "Placa: " << veiculo->getPlacaVeiculo() << endl;
	cout << "Ano: " << veiculo->getAnoVeiculo() << endl;
	cout << "Renavam: " << veiculo->getRenavamVeiculo() << endl;
	cout << "Tipo veículo: " << veiculo->getTipoVeiculoVeiculo() << endl;
	cout << "Marca: " << veiculo->getMarcaVeiculo() << endl;
	cout << endl;
}

/* função Get que retorna um ponteiro do tipo 'Veiculo' */
Veiculo* GerenciarVeiculos::getVeiculo() const
{
	return veiculo;
}