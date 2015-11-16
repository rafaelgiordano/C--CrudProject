/**
 * blackJ.c - Implementação do jogo de cartas Black Jack, mais conhecido como
 *            21.
 * Autores: BRUNO HARUO YOKOYAMA        R.A. 323063
 *          DANIEL RÉCIO                R.A. 323535
 *          LUIS SATOSHI IJICHI TANAKA  R.A. 323365
 * Turma: Engenharia de Produção - A
 * Última atualização: 25/06/2008
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//
//
//
//! BEM VINDO AO BLACK JACK ! ANTES DE IMPLEMENTARMOS A FUNÇÃO MAIN, CRIAMOS 3 DIFERENTES PROCEDIMENTOS PARA QUE NO DECORRER DO JOGO FOSSEM DESENHADAS AS CARTAS//
//AO INICIAR O PROGRAMA O JOGADOR PODE OPTAR ENTRE COMEÇAR A JOGAR OU VER AS REGRAS DO JOGO. O JOGADOR COMEÇARÁ COM 1000 DE CASH. ANTES DE RECEBER SUAS CARTAS O JOGADOR ENTRA COM UMA QUANTIA A SER APOSTADA.//
//TAL QUANTIA SERA VERIFICADA PELO PROGRAMA SE ESTA É MAIOR QUE 0 E SE É MENOR QUE SEU CASH.CRIAMO UM while PARA QUE O JOGO SÓ RODE ENQUANTO CASH FOR MAIOR QUE 0.PARA INICIAR O JOGO CRIAMOS UMA MATRIZ 5x14 QUE É PREENCHIDA POR NUMEROS 0.//
//PRIMEIRAMENTE O COMPUTADOR RECEBE UMA CARTA. ESTA É DEFINIDA POR UM COMANDO random QUE SORTEARÁ UM NÚMERO DEFINIDO DE UM A QUATRO, REPRESENTANDO OS QUATROS NIPES, E UM NUMERO DE UM A TREZE, REPRESENTANDO AS TREZES CARTAS DO BARALHO. //
//PARA EVITAR QUE O SORTEIRO DE CARTAS SEJA IGUAL, FOI USADO srand(time(NULL)) QUE SINCRONIZA A RAMDOMIZAÇÃO AO RELÓGIO DO COMPUTADOR//
//O PROBLEMA DA REPETIÇÃO DAS CARTAS, FOI RESOLVIDO SUBSTITUINDO O VALOR DA MATRIZ DE POSIÇÃO EQUIVALENTE AO NIPE E AO VALOR DA CARTA POR UM APÓS UMA CARTA JA TER SIDO SORTEADA,ASSIM EM UM PROXIMO SORTEIO CONFERIMOS SE O NUMERO DA POSIÇÃO (nipexvalor)  DA MATRIZ É IGUAL A UM, SE FOR É FEITO UM NOVO RANDOM ATE Q O VALOR DA POSIÇÃO SEJA 0.//
//CRIAMOS UMA VARIAVEL PARA GUARDAR A SOMA DOS PONTOS DO JOGADOR. PARA CALCULAR TAL VALOR É SOMADO PARA CARTAS DE 2 A 10 SEUS RESPECTIVOS VALORES, É SOMADO 10 PARA FIGURAS, E PARA A CARTA 'AS' É SOMADO 1 OU 11 DEPENDENDO DOS PONTOS JÁ OBTIDOS. SE OS PONTOS SOMADOS FOREM MAIORES QUE 10, SOMA-SE 1, CASO CONTRARIO SOMA-SE 11.//
//SE COM AS SUAS DUAS PRIMEIRAS CARTAS O JOGADOR SOMAR 21 PONTOS, ELE FAZ 'BLACK JACK' E COM ISSO GANHA O DOBRO DO VALOR APOSTADO. QUANDO ISSO ACONTECE, O PROGRAMA NAO RODA A JOGADA DO COMPUTADOR, ENCERRANDO A RODADA.//
//DEPOIS DE RECEBER SUAS DUAS PRIMEIRAS CARTAS E CASO O JOGADOR NAO FAÇA 'BLACK JACK', ELE PODE OPTAR EM COMPRAR MAIS UMA CARTA OU ENCERRAR SUA JOGADA. SE OPTAR EM COMPRAR MAIS UMA CARTA, REPETIR-SE-A O PROCESSO DE SOMA DOS PONTOS.//
//SE A SOMA DE SEUS PONTOS FOR MAIOR QUE 21 VOCE PERDE AUTOMATICAMENTE E DE SEU CASH SUBTRAIR-SE-A O VALOR APOSTADO.CASO ELE OPTE POR ENCERRAR SUA RODADA INICIA-SE O JOGO DO PC.//
//NELE FAZ-SE O MESMO PROCESSO DE RANDOMIZAÇÃO E O PC SOMENTE PARA QUANDO SEUS PONTOS SOMADOS FOREM MAIOR OU IGUAL AO DOS JOGADOR.CASO ELE SOME MAIS QUE 21 PONTOS O JOGADOR GANHA A APOSTA FEITA NO INICIO DO JOGO.//
//CASO A SOMA DO COMPUTADOR E DO JOGADOR FOREM IGUAIS, HA UM EMPATE E NADA ACONTECE QUANTO A APOSTA. APOS TUDO ISSO O JOGADOR PODE OPTAR EM CONTINUAR JOGANDO OU NAO. SE OPTAR EM CONTINUAR, A MATRIZ É REPREENCHIDA COM 0. E INICIA-SE O JOGO NOVAMENTE COM O CASH SOMADO OU SUBTRAIDO A APOSTA FEITA.//

//PARA JOGAR NAS CONFIGURAÇÕES ORIGINAIS, COMPILE O CODIGO E ABRA O ARQUIVO. APERTE COM O BOTÃO DIREITO DO MOUSE SOBRE A BARRA E ENTRE EM PROPERTIES(PROPRIEDADES). NA OPÇÃO LAYOUT AUMENTE O Width PARA 300. E NA OPÇÃO COLORS CLIQUE NA COR VERDE ESCURO E PRESSIONE "OK".//
//ESCOLHA A OPÇÃO "SAVE PROPERTIES FOR FUTURE WINDOWS WITH SAME TITLE"(SALVAR PROPRIEDADES PARA JANELAS FUTURAS COM O MESMO TITULO). FECHE O ARQUIVO E ABRA NOVAMENTE.//


/**
 * Escreve nipe da carta na tela
 * parâmetros: a - valor do nipe (1 a 4)
 */
void nipe(int a){
  switch(a){
  case(1):
    printf("                                              ,,,,,\n                                              |%c  |\n",3);
    break;
  case(2):
    printf("                                              ,,,,,\n                                              |%c  |\n",4);
    break;
  case(3):
    printf("                                              ,,,,,\n                                              |%c  |\n",5);
    break;
  case(4):
    printf("                                              ,,,,,\n                                              |%c  |\n",6);
    break;
  }
}

/**
 * Escreve a valor da carta na tela
 * parâmetros: a - valor da carta (1 a 13)
 */
void nipe2(int a){
  switch(a){
  case(1):
    printf("                                              |  %c|\n                                              `````\n",3);
    break;
  case(2):
    printf("                                              |  %c|\n                                              `````\n",4);
    break;
  case(3):
    printf("                                              |  %c|\n                                              `````\n",5);
    break;
  case(4):
    printf("                                              |  %c|\n                                              `````\n",6);
    break;
  }
}

/**
 * Escreve a o valor de uma carta na tela
 * parâmetros: b - valor da carta
 */
void valor(int b){                    
  switch(b){
  case(1): {printf("                                              | A |\n");}break;
  case(2): {printf("                                              | 2 |\n");}break;
  case(3): {printf("                                              | 3 |\n");}break;
  case(4): {printf("                                              | 4 |\n");}break;
  case(5): {printf("                                              | 5 |\n");}break; 
  case(6): {printf("                                              | 6 |\n");}break;
  case(7): {printf("                                              | 7 |\n");}break;
  case(8): {printf("                                              | 8 |\n");}break;
  case(9): {printf("                                              | 9 |\n");}break;
  case(10):{printf("                                              | 10|\n");}break;
  case(11):{printf("                                              | J |\n");}break;
  case(12):{printf("                                              | Q |\n");}break;
  case(13):{printf("                                              | K |\n");}break;
  }
}

int main(){
  int a,           // armazena um nipe (valores de 1 a 4)
    b,             // armazena o valor de uma carta (1 a 13)
    fimJogo,       // fim de jogo
    verRegras,     // opção de ver as regras do jogo
    vApostaOK,     // verificação do valor da aposta
    cash,          //quantidade em dinheiro atual do jogador
    aposta,        //quantidade em dinheiro a ser apostado
    maisCartas,    // vale 0 quando eh necessario virar outra carta
    i,             // controla linha da matriz 
    j,             // controla coluna da matriz
    comp,          // pontuacao do computador
    primeiraCarta, // anota se eh a primeira carta do jogador
    cartaaspc,     // anota se o computador virou um as
    jogo,          // pontuacao do jogador
    cartaasjogador,// anota se o jogador virou um as
    mat[5][14];    // anota as cartas sorteadas

  // impressao da tela inicial
  printf("                                        BBBBBBB     LLLL               AAAA         CCCCCCCC    KKK     KK\n");
  printf("                                        BB    BB    LLLL              AAAAAA        CCCCCCCC    KKK    KK\n");
  printf("                                        BB    BB    LLLL             AA    AA       CCC         KKK   KK\n");
  printf("                                        BBBBBBB     LLLL            AA      AA      CCC         KKKKKKK\n");
  printf("                                        BB    BB    LLLL           AAAAAAAAAAAA     CCC         KKK   KK   \n");
  printf("                                        BB    BB    LLLLLLLLL     AAA        AAA    CCCCCCCC    KKK    KK\n");
  printf("                                        BBBBBBB     LLLLLLLLLL   AAA          AAA   CCCCCCCC    KKK     KK \n\n");
  printf("                                            JJJJJJJJJJJJJJJJJJ       AAAA          CCCCCCCCCCC     KKKK      KKK\n   ");
  printf("                                         JJJJJJJJJJJJJJJJJJ      AAAAAA         CCCCCCCCCCC     KKKK     KKK\n    ");
  printf("                                               JJJJJ           AA    AA        CCCC            KKKK   KKKK\n");
  printf("                                                   JJJJJ          AA      AA       CCCC            KKKKKKKKKK\n");
  printf("                                                   JJJJJ         AAA       AA      CCCC            KKKKKKKK\n ");
  printf("                                          JJJJJ   JJJJJ        AAAAAAAAAAAAAA     CCCC            KKKK  KKKK\n ");
  printf("                                            JJJJJJJJJJ        AAA          AAA    CCCCCCCCCCC     KKKK   KKKK\n ");
  printf("                                              JJJJJJ         AAA            AAA   CCCCCCCCCCC     KKKK     KKKK  \n\n\n\n\n ");
  cash = 1000;
  printf("                                              %c JOGAR (0)             %c COMO JOGAR (1)\n",26,26);
  scanf("%d",&verRegras);

  // para ver as regras do jogo
  if(verRegras == 1){ 
    printf("\n\n                                              ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,");
    printf("\n                                              |OBJETIVO: NESTE JOGO GANHA QUEM OBTER A MAIOR SOMA MENOR QUE 22,        |\n");
    printf("                                              |          CASO PASSE 22 O JOGADOR PERDE!                                |\n");
    printf("                                              |          CADA JOGADOR COMECARA COM DUAS CARTAS.                        |\n");
    printf("                                              |          VOCE PODE OPTAR POR RECEBER MAIS CARTAS OU PARAR A JOGADA     |\n");
    printf("                                              |          SE COM AS SUAS DUAS PRIMEIRAS CARTAS VOCE SOMAR 21,           |\n");
    printf("                                              |          VOCE FAZ 'BLACK JACK' E GANHA EM DOBRO A QUANTIA APOSTADA.    |\n");
    printf("                                              |          ANTES DE JOGAR VOCE RECEBERA 1000 REAIS.                      |\n");
    printf("                                              |          ESTES SERAO APOSTADOS NO DECORRER DO JOGO.                    |\n");
    printf("                                              |          QUANDO VOCE OS NAO TER MAIS DINHEIRO O JOGO ACABA.            |\n");
    printf("                                              |                                                                        |\n");               
    printf("                                              |                           %c ! BOM JOGO ! %c                             |\n",1,1);
    printf("                                              ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n\n\n ");
  }
  
  // enquanto tem dinheiro para apostar
  while(cash > 0){
    printf("\n                                        DINHEIRO = %d\n\n",cash);
    printf("                                        ENTRE COM A QUANTIA A APOSTAR:\n ",cash);
    // lê o valor a ser apostado
    scanf("%d",&aposta);

    vApostaOK = 0;
    // não permite valores inadequados para aposta
    while(vApostaOK == 0){
      while(aposta <= 0){
	printf("\n                                        A aposta deve de ser maior que 0! Tente apostar novamente:\n ");
	scanf("%d",&aposta);
      }
      while(aposta > cash){
	printf("\n                                        Voce nao tem esse dinheiro para apostar! Tente apostar novamente:\n ");          
	scanf("%d",&aposta);
      }  
      if(aposta > 0 && aposta <=cash){
	vApostaOK = 1;
      }
    }

    
    printf("                                        SUA APOSTA = %d",aposta);
    if(vApostaOK == 1){ 
      jogo = 0;
      cartaasjogador = 0;
      cartaaspc = 0;
      maisCartas = 0;

      // preenche a matriz de cartas com 0
      for(i=0;i<=4;i++){
	for(j=0;j<=13;j++){
	  mat[i][j] = 0;
	}
      }
      
      printf("\n\n\n                                        CARTA DO ADVERSARIO :\n");
      comp = 0;                  
      srand(time(NULL));

      // sorteia a primeira carta do computador
      // sorteia nipe 1 a 4
      a = rand()%4+1;
      // sorteia valor 1 a 13
      b = rand()%13+1;

      // imprime a carta na tela
      nipe(a);
      valor(b);
      nipe2(a);
      printf("                                              ,,,,,\n                                              |   |\n                                              | %c |\n                                              |   |\n                                              `````\n",1);

      // se a carta eh um As, soma 11
      if(b == 1){
	comp = comp + 11;
	cartaaspc = 1;
      }
      // senão soma o valor da carta
      else{
	if(b < 11){
	  comp = comp + b;
	}
	else{
	  comp = comp + 10;
	}
      }

      // anota a virada da carta para que nao haja repeticao
      mat[a][b] = 1;

      // sorteia duas cartas para o jogador
      printf("\n\n                                        SUAS CARTAS: \n");
      // sorteia nipe 1 a 4
      a = rand()%4+1;
      // sorteia valor 1 a 13
      b = rand()%13+1;
      
      // caso a carta ja tenha sido sorteada, sorteia nova carta 
      while(mat[a][b] == 1){      
	a = rand()%4+1;
	b = rand()%13+1;
      }
      mat[a][b] = 1;

      // imprime carta sorteada
      nipe(a);
      valor(b);
      nipe2(a);

      // soma a carta sorteada com os pontos do jogador
      if(b == 1){
	jogo = jogo + 11;
	cartaasjogador = 1;
      }                    
      else{
	if(b < 11){
	  jogo = jogo + b;
	}
	else{
	  jogo = jogo + 10;
	}
      }
      
      primeiraCarta = 0;
      // enquanto jogador quer mais cartas      
      while(maisCartas == 0){

	// sorteia outra carta para jogador
	primeiraCarta = primeiraCarta + 1;
	a = rand()%4+1;
	b = rand()%13+1;

	// caso a carta ja tenha sido sorteada, sorteia nova carta 
	while(mat[a][b] == 1){
	  a = rand()%4+1;
	  b = rand()%13+1;
	}
	mat[a][b] = 1;

	// imprime carta sorteada
	nipe(a);
	valor(b);
	nipe2(a);

	// soma a carta sorteada com os pontos do jogador
	if(b == 1){
	  if(jogo < 11){
	    cartaasjogador = 1;
	    jogo = jogo + 11;
	  }
	  else{
	    jogo = jogo + 1;
	  }                                         
	}
	else{
	  if(b < 11){
	    jogo = jogo + b;
	  }
	  else{
	    jogo = jogo + 10;
	  }
	}

	// se pontuacao do jogador eh maior que 21
	if(jogo > 21){
	  // se jogador possui um as
	  if(cartaasjogador == 1){
	    // altera o valor do as para 1
	    jogo = jogo - 10;
	    cartaasjogador = 0;
	  }
	}
	printf("\n\n                                        SOMA TOTAL = %d\n\n",jogo);

	// se pontuacao do jogador eh igual a 21
	if(jogo == 21){
	  // se eh a segunda carta do jogador
	  if(primeiraCarta == 1){
	    // black - jogador ganhou e recebe o dobro da aposta
	    printf("                                                       BBBB  L         A     CCCCCC K   K\n               "); 
	    printf("                                        B  B  L        A A    C      K  K   \n         ");
	    printf("                                              BBBB  L       A   A   C      KKK     \n         ");
	    printf("                                              B   B L      AAAAAAA  C      K  K     \n   ");
	    printf("                                                    BBBB  LLLLL A       A CCCCCC K   K     \n\n        ");
	    printf("                                                 JJJJJJJJJ     A     CCCCCC K   K       \n");
	    printf("                                                             J        A A    C      K  K   \n");
	    printf("                                                             J       A   A   C      KKK  \n");
	    printf("                                                        J    J      AAAAAAA  C      K  K      \n");
	    printf("                                                         JJJJJ     A       A CCCCCC K   K  \n\n");
	    printf("\n                                        %c !VOCE GANHOU ! %c\n\n",1,1);
	    cash = cash + 2*(aposta);
	    primeiraCarta = 0;
	  }
	}

	// se pontuacao maior que 21
	if(jogo > 21){
	  // jogador perdeu e desconta o valor da aposta
	  printf("                                        ! =( VOCE PERDEU =( !\n");
	  cash = cash - aposta;
	  maisCartas = 1;
	}

	// se jogador tem chance de virar outra carta
	else{                                                
	  if(primeiraCarta == 0){
	    maisCartas = 1;
	  }
	  else{
	    printf("                                        DESEJA MAIS UMA CARTA?\n                                        %c SIM (0)              %c NAO (1)\n",26,26);
	    scanf("%d",&maisCartas);}
	}
      }


      // se o jogador tem pontuacao menor que 22
      if(jogo < 22){
	if(primeiraCarta == 0){
	  maisCartas = 5;
	}

	// enquanto computador deve virar mais cartas
	while(maisCartas == 1){        
	  printf("\n                                        CARTA DO ADVERSARIO :\n");

	  // sorteia outra carta para jogador
	  a = rand()%4+1;
	  b = rand()%13+1;

	  // caso a carta ja tenha sido sorteada, sorteia nova carta 	  
	  while(mat[a][b] == 1){
	    a = rand()%4+1;
	    b = rand()%13+1;
	  }
	  mat[a][b] = 1;

	  // imprime carta sorteada	  
	  nipe(a);
	  valor(b);
	  nipe2(a);

	  // soma a carta sorteada com os pontos do computador	  
	  if(b == 1){ 
	    if(comp < 11){                                                   
	      cartaaspc = 1;
	      comp = comp + 11;
	    }
	    else{
	      comp = comp + 1;
	    }                                         
	  }
	  else{
	    if(b < 11){
	      comp = comp + b;
	    }
	    else{
	      comp = comp + 10;
	    }
	  }

	  // se pontuacao do computador eh menor que do jogador, computador
	  // vira mais cartas
	  if(comp < 22){
	    if(comp >= jogo){
	      maisCartas = 0;
	    }
	    else{
	      maisCartas = 1;
	    }              
	  }
	  else{
	    // se computador possui um as
	    if(cartaaspc == 1){
	      // altera o valor do as para 1
	      comp = comp - 10;
	      maisCartas = 1;
	      cartaaspc = 0;
	    }
	    else{
	      maisCartas = 3;
	    }
	  }            
	}
	// fim do jogo para o computador
	if(maisCartas == 3){
	  printf("\n\n\n                                        TOTAL DO ADVERSARIO = %d\n\n                                        %c !VOCE GANHOU! %c \n\n",comp,1,1);
	  // jogador recebe dinheiro da aposta
	  cash = cash + aposta;                           
	}

	// fim de jogo
	if(maisCartas == 0){
	  printf("\n                                        TOTAL DO ADVERSARIO = %d\n",comp);
	  
	  // empate
	  if(comp == jogo){
	    printf("\n\n                                        !EMPATOU!\n");
	  }

	  // jogador perdeu
	  else{
	    printf("\n\n                                        ! =( VOCE PERDEU =( !\n");
	    cash = cash - aposta;                                                                                                        
	  }
	} 
      }
    }

    // se jogador ainda tem saldo positivo
    if(cash > 0){
      printf("\n\n                                        DESEJA CONTINUAR JOGANDO?\n                                        %c SIM (0)                    %c NAO (1)\n",26,26);
      scanf("%d",&fimJogo);
      // se jogador quer sair do jogo
      if(fimJogo == 1){
	cash = 0;
      }
    }
  }        
  printf("\n\n                                          FFFFF II MM     MM      DDDDDD  EEEEE     JJJJJJJJ OOOOOOO  GGGGGGG  OOOOOOO");     
  printf("\n                                          FF    II MMM   MMM      DD   DD EE           JJ    OO   OO  GG       OO   OO");
  printf("\n                                          FFFF  II M  M M  M      DD   DD EEEE         JJ    OO   OO  GG  GGGG OO   OO");
  printf("\n                                          FF    II M   M   M      DD   DD EE        J  JJ    OO   OO  GG    G  OO   OO");
  printf("\n                                          FF    II M       M      DDDDDD  EEEEE      JJJ     OOOOOOO  GGGGGGG  OOOOOOO\n\n\n");
  
  
  system("PAUSE");
  return 0;
}

