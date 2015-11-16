/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: Veiculo.cpp

   Definição dos métodos da classe Veiculo.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

/* inclusão dos headers referentes às classes utilizadas */
#include "Veiculo.h"

using namespace std;

/* função Set que modifica o atributo 'placa' */
void Veiculo::setPlacaVeiculo(string p)
{
	placa = p;
}

/* função Set que modifica o atributo 'ano' */
void Veiculo::setAnoVeiculo(int x)
{
	ano = x;
}

/* função Set que modifica o atributo 'renavam' */
void Veiculo::setRenavamVeiculo(string r)
{
	renavam = r;
}

/* função Set que modifica o atributo 'tipoveiculo' */
void Veiculo::setTipoVeiculoVeiculo(int tv)
{
	tipoveiculo = tv;
}

/* função Set que modifica o atributo 'marca' */
void Veiculo::setMarcaVeiculo(int m)
{
	marca = m;
}

/* função Get que retorna a placa do veículo */
string Veiculo::getPlacaVeiculo() const
{
	return placa;
}

/* função Get que retorna o ano do veículo */
int Veiculo::getAnoVeiculo() const
{
	return ano;
}

/* função Get que retorna o renavam do veículo */
string Veiculo::getRenavamVeiculo() const
{
	return renavam;
}

/* função Get que retorna o tipo do veículo */
int Veiculo::getTipoVeiculoVeiculo() const
{
	return tipoveiculo;
}

/* função Get que retorna a marca do veículo */
int Veiculo::getMarcaVeiculo() const
{
	return marca;
}
