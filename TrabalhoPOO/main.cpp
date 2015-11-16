/* main.cpp */
/* g++ GerenciarOrcamento.cpp GerenciarOrcamento.h Orcamento.cpp Orcamento.h Data.h Data.cpp GerenciarSinistro.h GerenciarSinistro.cpp Sinistro.h Sinistro.cpp Terceiro.h Terceiro.cpp CRUDTerceiro.h CRUDTerceiro.cpp PessoaFisica.h GerenciarSegurados.cpp GerenciarSegurados.h Cliente.cpp Cliente.h Apolice.cpp Apolice.h GerenciarVeiculos.cpp GerenciarVeiculos.h Veiculo.cpp Veiculo.h main.cpp -o teste */
/* -------------------------------------------------------------------------------------------------------------------------------------------------
   Programação Orientada a Objetos - Trabalho Prático

   Nome do arquivo: main.cpp

   Autores:
   Giulianno Raphael Sbrugnera RA: 408093
   Gustavo Rodrigues		   RA: 489999
   Matheus Casarin Paez		   RA: 438308
   Rafael Paschoal Giordano	   RA: 408298

   Função principal projetada para funcionar como um sistema de gestão de apólices de seguros, onde há diversos menus onde o usuário escolhe a opção
   desejada, de acordo com as suas necessidades. No menu principal, são um total de sete opções, abrangendo quase todos os requisitos funcionais 
   essenciais descritos no cenário do trabalho prático, sendo que a oitava opção finaliza o programa. Dependendo da opção escolhida no menu 
   principal, há sub-menus onde mais opções são oferecidas ao usuário (por exemplo, no caso do usuário querer cadastrar uma apólice, em seguida ele
   escolhe se deseja inserir, consultar, excluir ou alterar uma apólice). Inclusive após escolher uma as opções dos sub-menus, pode haver mais 
   sub-menus. Através da entrada via teclado, são lidos dados que posteriormente serão atribuídos aos atributos das classes desejadas.

   Data de conclusão: 30.06.2013
   ------------------------------------------------------------------------------------------------------------------------------------------------- */

/* inclusão das bibliotecas do sistema */
#include <iostream>
#include <string>

/* inclusão dos headers referentes às classes utilizadas */
#include "GerenciarSegurados.h"
#include "Cliente.h"
#include "GerenciarSinistro.h"
#include "Sinistro.h"
#include "CRUDTerceiro.h"
#include "Terceiro.h"
#include "PessoaFisica.h"
#include "BO.h"
#include "Data.h"
#include "Apolice.h"
#include "GerenciarOrcamento.h"
#include "Orcamento.h"
#include "GerenciarVeiculos.h"
#include "Veiculo.h"

using namespace std;

int main ()
{
	/* definição de objetos e/ou ponteiros de/para algumas classes */

	BO b;
	Data date, date2, date3;
	Sinistro *snt;
	GerenciarSinistro gs;
	Terceiro *terc;
	CRUDTerceiro crudt;
	Orcamento *orcamento;
	GerenciarOrcamento go;
	Veiculo *veiculo;
	GerenciarVeiculos gv;
	GerenciarSegurados segurados;
	Apolice apolice;

	/* variáveis que servirão de parâmetros para os métodos das classes */

	string nome;
	string telefone;
	string seguradora;
	string endereco;
	string cpf;
	string local;
	string tipo;
	string placa;
	string renavam;
	string numeroCNH;

	int dia;
	int mes;
	int ano;
	int tipoVeiculo;
	int marca;
	int classificacao;
	int idade;
	int num;
	int opcao;
	int segundaOpcao;
	int terceiraOpcao;
	int posicao;
	int x;
	int tipoSinistro;

	float valorRessarc;

	cout << "-----------------------------------------------------" << endl;
	cout << "Sistema de Gestão de Apólices de Seguros inicializado" << endl;
	cout << "-----------------------------------------------------" << endl;

	/* Laço principal que garante a continuação do programa até que a opção desejada seja sair (opcao = 8) */
	do
	{
		cout << endl;
		cout << endl;
		cout << "Menu de opções" << endl;
		cout << "1 - Cadastrar segurados" << endl;
		cout << "2 - Cadastrar veículo" << endl;
		cout << "3 - Cadastrar apólice" << endl;
		cout << "4 - Cadastrar sinistro" << endl;
		cout << "5 - Vincular uma apólice a um cliente" << endl;
		cout << "6 - Vincular um sinistro a uma apólice" << endl;
		cout << "7 - Impressão dos dados" << endl;
		cout << "8 - Finalizar sistema" << endl;
		cin >> opcao;

		switch (opcao)
		{
			case 1: // cadastrar segurados
			{
				cout << "Cadastro de Segurados - opções" << endl;
				cout << "1 - Cadastrar cliente" << endl;
				cout << "2 - Cadastrar condutor" << endl;
				cin >> segundaOpcao;

				switch (segundaOpcao)
				{
					case 1: // cadastro de cliente
					{
						cout << "Cadastro de Cliente - opções" << endl;
						cout << "1 - Inserir cliente" << endl;
						cout << "2 - Consultar cliente" << endl;
						cout << "3 - Excluir cliente" << endl;
						cout << "4 - Alterar cliente" << endl;
						cin >> terceiraOpcao;
						cout << endl << endl;

						switch (terceiraOpcao)
						{
							case 1: // inserir cliente
							{
								cout << "Inserção do Cliente inicializada" << endl;
								cout << "Inserção dos dados do cliente" << endl;
								cout << "Digite o nome do cliente: ";
								cin >> nome;
								cout << "Digite o telefone do cliente: ";
								cin >> telefone;
								cout << "Digite o endereço do cliente: ";
								cin >> endereco;
								cout << "Digite o cpf do cliente: ";
								cin >> cpf;

								if (segurados.criarCliente(nome, telefone, endereco, -1, cpf))
								{
									cout << "Cliente inserido com sucesso" << endl;
								}
								else
								{
									cout << "O sistema não suporta mais clientes!" << endl;
								}

							}
							break;

							case 2: // consultar cliente
							{
								if (!segurados.consultarCliente())
								{
									cout << "O cliente procurado não existe" << endl;
								}
							}	
							break;

							case 3: // excluir cliente
							{
								cout << "Digite a posição do cliente que deseja excluir: ";
								cin >> posicao;

								if (!segurados.excluirCliente(posicao))
								{
									cout << "Posição inválida!" << endl;
								}
								else
								{
									cout << "Cliente excluído com sucesso" << endl;
								}
							}
							break;

							case 4: // alterar cliente
							{
								cout << "Alteração do Cliente inicializada" << endl;
								cout << "Alteração dos dados do cliente" << endl;
								cout << "Digite a posição do cliente que deseja alterar" << endl;
								cin >> posicao;
								cout << "Digite o nome do cliente: ";
								cin >> nome;
								cout << "Digite o telefone do cliente: ";
								cin >> telefone;
								cout << "Digite o endereço do cliente: ";
								cin >> endereco;
								cout << "Digite o cpf do cliente:";
								cin >> cpf;

								if (segurados.alterarCliente(nome, telefone, endereco, posicao, cpf))
								{
									cout << "Cliente alterado com sucesso" << endl;
								}
								else
								{
									cout << "Posição inválida!" << endl;
								}

							}
							break;

							default:
							{
								cout << "Opção inexistente!" << endl;
							}
						}
					}
					break;

					case 2: // cadastro de condutor
					{
						cout << "Cadastro de Condutor - opções" << endl;
						cout << "1 - Inserir condutor" << endl;
						cout << "2 - Consultar condutor" << endl;
						cout << "3 - Excluir condutor" << endl;
						cout << "4 - Alterar condutor" << endl;
						cin >> terceiraOpcao;

						switch (terceiraOpcao)
						{
							case 1: // inserir condutor
							{
								cout << "Digite o nome do condutor: ";
								cin >> nome;
								cout << "Digite o telefone do condutor: ";
								cin >> telefone;
								cout << "Digite o endereço do condutor: ";
								cin >> endereco;
								cout << "Digite o cpf do condutor:";
								cin >> cpf;
								cout << "Digite o número da CNH do condutor: ";
								cin >> numeroCNH;
								cout << "Digite a idade do condutor: ";
								cin >> idade;
							}
							break;

							case 2: // consultar condutor
							{
								// if (!segurados.consultarCondutor())
								// {
								// 	cout << "O condutor procurado não existe" << endl;
								// }
							}	
							break;

							case 3: // excluir condutor
							{
								// cout << "Digite a posição do condutor que deseja excluir" << endl;
								// cin >> num;

								// if (!segurados.excluirCondutor(num))
								// {
								// 	cout << "Posição inválida!" << endl;
								// }
								// else
								// {
								// 	cout << "Condutor excluído com sucesso" << endl;
								// }
							}
							break;

							case 4: // alterar condutor
							{
								cout << "Digite a posição do condutor que deseja alterar" << endl;
								cin >> num;
								cout << "Digite o nome do condutor: ";
								cin >> nome;
								cout << "Digite o telefone do condutor: ";
								cin >> telefone;
								cout << "Digite o endereço do condutor: ";
								cin >> endereco;
								cout << "Digite o cpf do condutor:";
								cin >> cpf;
								cout << "Digite o número da CNH do condutor: ";
								cin >> numeroCNH;
								cout << "Digite a idade do condutor: ";
								cin >> idade;
							}
							break;

							default:
							{
								cout << "Opção inexistente!" << endl;
							}
						}
					}
					break;

					default:
					{
						cout << "Opção inexistente!" << endl;
					}

				}
			}
			break;

			case 2: // cadastrar veículo
			{
				cout << "Cadastro de Veículo - opções" << endl;
				cout << "1 - Inserir veículo" << endl;
				cout << "2 - Consultar veículo" << endl;
				cout << "3 - Excluir veículo" << endl;
				cout << "4 - Alterar veículo" << endl;
				cin >> segundaOpcao;
				cout << endl << endl;

				switch (segundaOpcao)
				{
					case 1: // inserir veículo
					{
						cout << "Inserção do Veículo inicializada" << endl;
						cout << "Inserção dos dados do veículo" << endl;
						cout << "Digite a placa do veículo: ";
						cin >> placa;
						cout << "Digite o ano do veículo: ";
						cin >> num;
						cout << "Digite o RENAVAM do veículo: ";
						cin >> renavam;
						cout << "Digite o tipo de veículo: ";
						cin >> tipoVeiculo;
						cout << "Digite a marca do veículo: ";
						cin >> marca;

						gv.inserirVeiculo(placa, num, renavam, tipoVeiculo, marca); /* cria um objeto do tipo VEICULO */
						veiculo = gv.getVeiculo();									/* faz veiculo apontar para o objeto criado */

						cout << "Veículo inserido" << endl;
					}
					break;

					case 2: // consultar veículo
					{
						cout << "Digite a placa do veículo que deseja procurar: ";
						cin >> placa;

						if (!segurados.consultarVeiculo(placa))
						{
							cout << "Veículo com placa " << placa << " não existe" << endl;
						}
					}
					break;

					case 3: // excluir veículo (?)
					{
						cout << "Veículo destruído" << endl;
					}
					break;

					case 4: // alterar veículo
					{
						cout << "Alteração do Veículo inicializada" << endl;
						cout << "Alteração dos dados do veículo" << endl;
						cout << "Digite a placa do veículo: ";
						cin >> placa;
						cout << "Digite o ano do veículo: ";
						cin >> num;
						cout << "Digite o RENAVAM do veículo: ";
						cin >> renavam;
						cout << "Digite o tipo de veículo: ";
						cin >> tipoVeiculo;
						cout << "Digite a marca do veículo: ";
						cin >> marca;

						gv.inserirVeiculo(placa, num, renavam, tipoVeiculo, marca);
						veiculo = gv.getVeiculo();

						cout << "Veículo alterado" << endl;
					}
					break;

					default:
					{
						cout << "Opção inexistente!" << endl;
					}						
				}
			}
			break;

			case 3: // cadastrar apólice
			{
				cout << "Cadastro de Apólice - opções" << endl;
				cout << "1 - Inserir apólice" << endl;
				cout << "2 - Consultar apólice" << endl;
				cout << "3 - Excluir apólice" << endl;
				cout << "4 - Alterar apólice" << endl;
				cin >> segundaOpcao;
				cout << endl << endl;

				switch (segundaOpcao)
				{
					case 1: // inserir apólice
					{
						cout << "Inserção da Apólice inicializada" << endl;
						cout << "Inserção dos dados da apólice" << endl;
						cout << "Digite o número da apólice: ";
						cin >> num;
						cout << "Digite a classificação da apólice: ";
						cin >> classificacao;
						cout << "Digite a data de vigência da apólice" << endl;
						cout << "Dia: ";
						cin >> dia;
						cout << "Mes: ";
						cin >> mes;
						cout << "Ano: ";
						cin >> ano;

						cout << endl;
						cout << "Inserção dos dados do veículo" << endl;
						cout << "Digite a placa do veículo: ";
						cin >> placa;
						cout << "Digite o ano do veículo: ";
						cin >> num;
						cout << "Digite o RENAVAM do veículo: ";
						cin >> renavam;
						cout << "Digite o tipo de veículo: ";
						cin >> tipoVeiculo;
						cout << "Digite a marca do veículo: ";
						cin >> marca;

						gv.inserirVeiculo(placa, num, renavam, tipoVeiculo, marca);         /* cria um objeto do tipo VEICULO */
						veiculo = gv.getVeiculo();									        /* faz veiculo apontar para o objeto criado */

						date.inserirData(dia, mes, ano);								    /* cria um objeto do tipo DATA */

						cout << endl;
						cout << "Inserção dos dados do orçamento" << endl;
						cout << "Digite o tipo do orçamento: ";
						cin >> tipo;
						cout << "Digite o valor de ressarcimento do orçamento: ";
						cin >> valorRessarc;

						go.inserirOrcamento(tipo, valorRessarc);							/* cria um objeto do tipo ORCAMENTO */
						orcamento = go.getOrcamento();										/* faz orcamento apontar para o objeto criado */

						apolice.criarApolice(num, classificacao, date, veiculo, orcamento);	/* cria um objeto do tipo APOLICE */

						cout << "Apólice inserida com sucesso!" << endl;
					}
					break;

					case 2: // consultar apólice
					{
						cout << "Vá em Cadastrar cliente -> Consultar cliente -> Número da apólice" << endl;
					}
					break;

					case 3: // excluir apólice
					{
						cout << "Digite a posição da apólice que deseja excluir" << endl;
						cin >> num;
						cout << "Digite a posição do cliente que possui a apólice que deseja remover" << endl;
						cin >> posicao;

						if (!segurados.removerApolice(posicao, num))
						{
							cout << "Posição inválida!" << endl;
						}
						else
						{
							cout << "Apólice excluída" << endl;
						}
					}
					break;

					case 4: // alterar apólice
					{
						cout << "Alteração da Apólice inicializada" << endl;
						cout << "Digite a posição da apólice que deseja alterar" << endl;
						cin >> num;
						cout << "Digite a posição do cliente que possui a apólice que deseja alterar" << endl;
						cin >> posicao;

						cout << endl;
						cout << "Inserção dos dados da apólice" << endl;
						cout << "Digite o número da apólice: ";
						cin >> num;
						cout << "Digite a classificação da apólice: ";
						cin >> classificacao;
						cout << "Digite a data de vigência da apólice" << endl;
						cout << "Dia: ";
						cin >> dia;
						cout << "Mes: ";
						cin >> mes;
						cout << "Ano: ";
						cin >> ano;

						cout << endl;
						cout << "Inserção dos dados do veículo" << endl;
						cout << "Digite a placa do veículo: ";
						cin >> placa;
						cout << "Digite o ano do veículo: ";
						cin >> num;
						cout << "Digite o RENAVAM do veículo: ";
						cin >> renavam;
						cout << "Digite o tipo de veículo: ";
						cin >> tipoVeiculo;
						cout << "Digite a marca do veículo: ";
						cin >> marca;

						gv.inserirVeiculo(placa, num, renavam, tipoVeiculo, marca);         /* cria um objeto do tipo VEICULO */
						veiculo = gv.getVeiculo();									        /* faz veiculo apontar para o objeto criado */


						date.inserirData(dia, mes, ano); 								    /* cria um objeto do tipo DATA */

						cout << endl;
						cout << "Inserção dos dados do orçamento";
						cout << "Digite o tipo do orçamento: ";
						cin >> tipo;
						cout << "Digite o valor de ressarcimento do orçamento: ";
						cin >> valorRessarc;

						go.inserirOrcamento(tipo, valorRessarc);							/* cria um objeto do tipo ORCAMENTO */
						orcamento = go.getOrcamento();										/* faz orcamento apontar para o objeto criado */

						apolice.criarApolice(num, classificacao, date, veiculo, orcamento);	/* cria um objeto do tipo APOLICE */

						if (!segurados.alterarApolice(num, posicao, &apolice))
						{
							cout << "Posição do cliente e/ou da apólice inválida(s)!" << endl;
						}
						else
						{
							cout << "Apólice alterada" << endl;
						}
					}
					break;

					default:
					{
						cout << "Opção inexistente!" << endl;
					}
				}
			}
			break;

			case 4: // cadastrar sinistro
			{
				cout << "Cadastro de Sinistro - opções" << endl;
				cout << "1 - Inserir sinistro" << endl;
				cout << "2 - Consultar sinistro" << endl;
				cout << "3 - Excluir sinistro" << endl;
				cout << "4 - Alterar sinistro" << endl;
				cin >> segundaOpcao;
				cout << endl << endl;

				switch (segundaOpcao)
				{
					case 1: // inserir sinistro
					{
						cout << "Inserção do Sinistro inicializada" << endl;
						cout << "Inserção dos dados do terceiro" << endl;
						cout << "Digite a idade do terceiro: ";
						cin >> idade;
						cout << "Digite o nome do terceiro: ";
						cin >> nome;
						cout << "Digite o telefone do terceiro: ";
						cin >> telefone;
						cout << "Digite o endereco do terceiro: ";
						cin >> endereco;
						cout << "Digite o nome da seguradora: ";
						cin >> seguradora;
						cout << "Digite o CPF do terceiro: ";
						cin >> cpf;

						crudt.criarTerceiro(idade, nome, telefone, endereco, seguradora, cpf);				/* cria um objeto do tipo TERCEIRO */
						terc = crudt.getTerceiro();                                                 		/* faz terc apontar para o objeto criado */

						cout << endl;
						cout << "Inserção dos dados do BO" << endl;
						cout << "Digite o número do BO: ";
						cin >> num;
						cout << "Digite a data do BO" << endl;
						cout << "Dia: ";
						cin >> dia;
						cout << "Mês: ";
						cin >> mes;
						cout << "Ano: ";
						cin >> ano;
						date.inserirData(dia, mes, ano); 								  				    /* cria um objeto do tipo DATA */

						cout << "Digite o tipo do BO: ";
						cin >> tipo;

						cout << endl;
						cout << "Inserção dos dados do sinistro" << endl;
						cout << "Digite o número do sinistro: ";
						cin >> x;
						cout << "Digite a data do sinistro" << endl;
						cout << "Dia: ";
						cin >> dia;
						cout << "Mês: ";
						cin >> mes;
						cout << "Ano: ";
						cin >> ano;

						date2.inserirData(dia, mes, ano); 								  				    /* cria um objeto do tipo DATA */

						cout << "Digite o local do sinistro: ";
						cin >> local;
						cout << "Digite o tipo do sinistro: ";
						cin >> tipoSinistro;

						gs.criarSinistro(x, date, local, terc, tipoSinistro, &b);							/* cria um objeto do tipo SINISTRO */
						snt = gs.getSinistro();																/* faz snt apontar para o objeto criado */

						cout << endl;
						cout << "Sinistro inserido";
					}
					break;

					case 2: // consultar sinistro
					{
						cout << "Não há consulta de sinistro" << endl;
					}
					break;

					case 3: // excluir sinistro
					{	
						cout << "Não há exclusao de sinistro" << endl;
					}
					break;

					case 4: // alterar sinistro
					{
						cout << "Não há alteracao de sinistro" << endl;
					}

					default:
					{
						cout << "Opção inexistente!" << endl;
					}
				}
			}
			break;

			case 5: // vincular uma apólice a um cliente
			{
				cout << "Digite a posição do cliente que deseja vincular a apólice: ";
				cin >> posicao;

				if (!segurados.vincularApoliceCliente(&apolice, posicao))
				{
					cout << "Posição inexistente!" << endl;
				}
				else
				{
					cout << "Apólice vinculada com sucesso" << endl;
				}
			}
			break;

			case 6: // vincular um sinistro a uma apólice
			{
				if (!apolice.setSinistroApolice(snt))
				{
					cout << "Quantidade máxima de sinistros atingida!" << endl;
				}
				else
				{
					cout << "Sinistro vinculado com sucesso" << endl;
				}
			}
			break;

			case 7: // impressão dos dados
			{	
				if (!segurados.imprimirDadosCliente())
				{
					cout << "Não há dados para serem impressos!" << endl;
				}
			}
			break;

			case 8: // finalização do programa
			{
				cout << endl;
				cout << endl;
				cout << "---------------------------------------------------" << endl;
				cout << "Sistema de Gestão de Apólices de Seguros finalizado" << endl;
				cout << "---------------------------------------------------" << endl;
			}
			break;

			default:
			{
				cout << "Opção inexistente!" << endl;
			}
		}

	}while (opcao != 8);

	// date.inserirData(8, 5, 1993);																	 /* cria um objeto do tipo DATA */
	// date2.inserirData(27, 6, 2013);																	 /* cria um objeto do tipo DATA */
	// date3.inserirData(12, 7, 2013);																	 /* cria um objeto do tipo DATA */

	// crudt.criarTerceiro(20, "Giulianno", "9151-0021", "Jardim Itapuã", "Secured", "404.771.108-00"); /* cria um objeto do tipo TERCEIRO */

	// terc = crudt.getTerceiro();                                                                      /* faz terc apontar para o objeto criado */

	// gs.criarSinistro(222, date2, "City of Evil", terc, 5, 666, date, "roubo e furto");				 /* cria um objeto do tipo SINISTRO */

	// snt = gs.getSinistro();																			 /* faz snt apontar para o objeto criado */

	// go.inserirOrcamento("Econômico", 15000.35);														 /* cria um objeto do tipo ORCAMENTO */

	// orcamento = go.getOrcamento();																	 /* faz orcamento apontar para o objeto criado */

	// gv.inserirVeiculo("DFW-3900", 2013, "404.771.108-00", 1, 2);									 /* cria um objeto do tipo VEICULO */

	// veiculo = gv.getVeiculo();																		 /* faz veiculo apontar para o objeto criado */

	// apolice.criarApolice(121, 1, date3, veiculo, orcamento);										 /* cria um objeto do tipo APOLICE */

	// apolice.setSinistroApolice(snt);

	// segurados.criarCliente("The Reverend", "1234-5678", "Afterlife", -1, "404.771.108-00");			 /* cria um objeto do tipo CLIENTE */

	// segurados.vincularApoliceCliente(&apolice, 0);

	// segurados.imprimirDadosCliente();

	return 0;
}