/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Nome do arquivo: GerenciarOrcamento.cpp

   Definição dos métodos da classe GerenciarOrcamento.

   Data da última modificação: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

/* inclusão dos headers referentes às classes utilizadas */
#include "GerenciarOrcamento.h"

using namespace std;

float GerenciarOrcamento::valorTotal = 0; /* inicialização do atributo estático */

/* construtor da classe, aloca memória necessária pra um objeto da classe Orcamento */
GerenciarOrcamento::GerenciarOrcamento()
{
	try
	{
		orcamento = new Orcamento;
	}

	catch(bad_alloc)
	{
		cout << "Memória insuficiente!" << endl;
	}
}

/* destrutor da classe, devolve a memória alocada */
GerenciarOrcamento::~GerenciarOrcamento()
{
	delete orcamento;
}

/* chama as funções Set da classe para atribuir valores aos atributos, além de incrementar o atributo estático */
void GerenciarOrcamento::inserirOrcamento(string t, float x)
{
	orcamento->setTipoOrcamento(t);
	orcamento->setValorRessarcOrcamento(x);

	valorTotal = valorTotal + orcamento->getValorRessarcOrcamento();
}

/* método que imprime os atributos da classe */
void GerenciarOrcamento::imprimirDadosOrcamento()
{
	cout << "Impressão do orçamento" << endl;
	cout << "Tipo: " << orcamento->getTipoOrcamento() << endl;
	cout << "Valor ressarcimento: " << orcamento->getValorRessarcOrcamento() << endl;
	cout << endl;
}

/* função Get que retorna o valor total dos orçamentos */
float GerenciarOrcamento::getValorTotal()
{
	return valorTotal;
}

/* função Get que retorna um ponteiro do tipo 'Orcamento' */
Orcamento* GerenciarOrcamento::getOrcamento() const
{
	return orcamento;
}