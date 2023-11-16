




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

int aleatorio(int min, int max) {
    srand(time(NULL));
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

void efeitoDigitador(char texto[]) {
    int i = 0;
    while (texto[i] != '\0') {
        printf("%c", texto[i]);
        fflush(stdout);
        Sleep(30);
        i++;
    }
}

void resultado_acao(int numero, int *vida_personagem, int *vida_monstro, int *vida_espada) {
    if (numero == 1 || numero == 2) {
        int dano1=5;
        printf("Voc� danificou sua espada neste ataque e causou %d de dano\n", dano1);
        *vida_espada -= 3;
        *vida_monstro-= 5;
    } else if (numero >= 3 && numero <= 5) {
         int total = aleatorio(8,12);
        printf("Voc� acertou o ataque e causou %d de dano!\n",total);
       *vida_monstro-=total;
    } else if (numero == 6) {
        int total1=19;
        printf("Voc� acertou um ataque cr�tico e causou %d de dano!\n",total1);
        *vida_monstro -= 19;
    } else {
        printf("Bug! N�mero errado recebido no resultado_acao\n");
    }

    if (*vida_monstro > 0) {
        int dano_monstro = aleatorio(4, 6);
        printf("O monstro te atacou e causou %d de dano!\n", dano_monstro);
        *vida_personagem -= dano_monstro;
    }
}

void exibir_status(int vida_personagem, int vida_monstro, int almas, int vida_espada) {
    printf("\n---- Status ----\n");
    printf("Vida do Personagem: %d\n", vida_personagem);
    printf("Vida do Monstro: %d\n", vida_monstro);
    printf("Almas: %d\n", almas);
    printf("Vida da Espada: %d\n", vida_espada);
    printf("----------------\n\n");
}
void personagem_status(int vida_personagem, int almas, int vida_espada) {
    printf("\n---- Status ----\n");
    printf("Vida do Personagem: %d\n", vida_personagem);
    printf("Almas: %d\n", almas);
    printf("Vida da Espada: %d\n", vida_espada);
    printf("----------------\n\n");
}

void comprar_item(int *almas, int *potion, int *vida_espada) {
    int escolha2;

    printf("\n---- Loja ----\n");
    printf("[1] - Comprar Po��o de Vida (Custo: 10 almas, Efeito: +10 HP)\n");
    printf("[2] - Concertar a Espada (Custo: 10 almas)\n");
    printf("[3] - Sair da Loja\n");
    printf("Escolha o item que deseja comprar: ");
    scanf("%d", &escolha2);

    switch (escolha2) {
        case 1:
            if (*almas >= 10) {
                printf("Voc� comprou uma Po��o de Vida!\n");
                *almas -= 10;
                *potion += 1;
            } else {
                printf("Voc� n�o tem almas suficientes para comprar este item!\n");
            }
            break;
        case 2:
            printf("Voc� decidiu consertar sua espada.\n");
            *vida_espada = 100;
            break;
        default:
            printf("Op��o inv�lida!\n");
            break;
    }
}
int main() {
    int inicio, escolha, potion = 0, almas = 0, escolha2;
    int vida_personagem = 100, vida_monstro = 20, gold = 0, dano_arma = 10, vida_espada = 100;
    char nome[50];
    setlocale(LC_ALL, "portuguese");

    printf(" \n _________________________________________________________________________________");
    printf(" \n                     ��������������������������");
    printf(" \n                              SOULFORGED ");
    printf(" \n                     ��������������������������");
    printf(" \n _________________________________________________________________________________\n");

    efeitoDigitador("\n\nNum mundo envolto em trevas, onde a luz se esvaiu, surge um her�i destinado a enfrentar os horrores da escurid�o. Em um reino amaldi�oado, ele parte em busca do temido Deus da Noite, um ser sinistro que espalha terror entre os habitantes. Armado com coragem e uma l�mina incandescente, o her�i se aventura em florestas sombrias e cavernas tenebrosas, prontas para revelar os segredos ocultos e desafios mortais que o aguardam. Seu destino se entrela�a com o destino do mundo, enquanto ele se prepara para a batalha que decidir� o futuro de todos.");

    efeitoDigitador("\n\nVoc� quer participar dessa Jornada?");
    efeitoDigitador("\n[1] - Sim ou [2] - N�o\n");
    scanf("%d", &inicio);
    if (inicio == 1) {
        printf("Muito bom, vamos adentrar na masmorra.\n");
    } else if (inicio == 2) {
        printf("Que pena, perdemos um guerreiro.\n");
        system("pause");
        return 0;
    } else {
        printf("Caractere inv�lido.\n");
        system("pause");
        return 0;
    }

    printf("Me diga, qual � o seu nome guerreiro?: \n");
    scanf("%s", nome);
    system("cls");

    exibir_status(vida_personagem, 0, almas, vida_espada);
    printf("Ok %s, estamos adentrando na masmorra, fique de olhos bem abertos e atento.\n\n", nome);
    printf("Para te auxiliar na jornada, eu lhe concedo a espada de prata de Lican. \n\n");
    printf("Me acompanhe que eu vou te mostrar o que essa masmorra nos aguarda.\n\n");

    printf("No in�cio da masmorra voc� observa de longe.....");
    printf("\n1 - Ba�\n2 - Monstro\n");
    printf("Voc� deve tomar uma decis�o:\n");
    printf("\n\n[1] - Abrir o ba�\n[2] - Batalhar com o monstro (Ser� liberado o avan�o de sala ap�s a derrota do monstro)\n");

    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            printf("Voc� encontrou 4 po��es de vida e 20 almas.\n");
            potion += 4;
            almas += 20;
            printf("Voc� deve agora enfrentar o monstro para prosseguir.\n");
            break;
        case 2:
            printf("Se prepare para uma batalha fren�tica.\n");
            break;
        default:
            printf("Op��o inv�lida!\n");
            system("pause");
            return 0;
    }

    while (vida_personagem > 0 && vida_monstro > 0) {
        printf("\nEscolha sua a��o:\n");
        printf("[1] - Atacar\n");
        printf("[2] - Usar Po��o de Vida\n");
        printf("[3] - Sair da Masmorra\n");
        printf("A��o: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if (vida_espada > 0) {
                    int numero = aleatorio(1, 6);
                    resultado_acao(numero, &vida_personagem, &vida_monstro, &vida_espada);
                } else {
                    printf("Sua espada est� quebrada! N�o � poss�vel atacar.\n");
                }
                break;
            case 2:
                if (potion > 0) {
                    printf("Voc� usou uma Po��o de Vida e recuperou 10 pontos de vida.\n");
                    vida_personagem += 10;
                    potion--;
                } else {
                    printf("Voc� n�o tem po��es de vida!\n");
                }
                break;
            case 3:
                printf("Voc� decidiu sair da masmorra. Fim de jogo.\n");
                system("pause");
                return 0;
            default:
                printf("Op��o inv�lida!\n");
                break;
        } exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
        }

        if (vida_personagem <= 0) {
            printf("Voc� foi derrotado! Game Over.\n");
            system("pause");
            return 0;
        } else if (vida_monstro <= 0) {
            printf("Voc� derrotou o monstro!\n");
            int almas_ganhas = aleatorio(5, 10);
            almas += almas_ganhas;
            printf("Voc� ganhou %d almas!\n", almas_ganhas);
}system("cls");
personagem_status(vida_personagem, almas, vida_espada);
            printf("Voc� esta avan�ando para a pr�xima sala.\n");
            printf("Nesta nova sala voc� se depara com um ferreiro.\n");
          printf("\nEscolha uma op��o:\n");
          printf("[1] - Ir ao ferreiro\n");
          printf("[2] - Abrir o ba�\n");
          printf("[3] - Enfrentar um novo monstro\n");
          scanf("%d", &escolha2);

          switch (escolha2) {
              case 1:
              printf("Voc� decidiu ir ao ferreiro.\n");
              comprar_item(&almas, &potion, &vida_espada);
              personagem_status(vida_personagem, almas, vida_espada);
              int escolha3;
              printf("Deseja abrir o ba� ou enfrentar um novo monstro?\n");
              printf("[1]. Abrir o ba�.\n");
              printf("[2]. Enfrentar um novo monstro.\n");
              scanf("%d", &escolha3);
              switch (escolha3) {
              case 1:
                printf("Voc� abriu o ba� e achou um cora��o que lhe concede 25 HP e 20 almas.\n");
                vida_personagem += 25;
                almas += 20;
                printf("Voc� ir� sentir a ira do monstro, Gravelord Nito! Prepare-se para sofrer.\n");
                vida_monstro=38;
                break;
              case 2:
                printf("Voc� decidiu enfrentar um novo monstro.\n");
                vida_monstro = 38;
                break;
              default:
                printf("Op��o inv�lida!\n");
                system("pause");
                return 0;
                }
                break;
                case 2:
                printf("Voc� abriu o ba� e achou um cora��o que lhe concede 25 HP e 20 almas.\n");
                vida_personagem += 25;
                almas += 20;
                printf("Voc� ir� sentir a ira do monstro, Gravelord Nito! Prepare-se para sofrer.\n");
                vida_monstro=38;
                exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
                break;
                case 3:
                printf("Voc� escolheu enfrentar o monstro, grande coragem!\n");
                printf("Voc� ir� sentir a ira do monstro, Gravelord Nito! Prepare-se para sofrer.\n");
                vida_monstro=38;
                exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
                break;
                default:
                printf("Op��o inv�lida!\n");
                system("pause");
                return 0;
                
}while( vida_monstro >0){ 
        printf("\nEscolha sua a��o:\n");
        printf("[1] - Atacar\n");
        printf("[2] - Usar Po��o de Vida\n");
        printf("[3] - Sair da Masmorra\n");
        printf("A��o: ");
        scanf("%d", &escolha2);

        switch (escolha2 ) {
            case 1:
                if (vida_espada > 0) {
                    int numero = aleatorio(1, 6);
                    resultado_acao(numero, &vida_personagem, &vida_monstro, &vida_espada);
                } else {
                    printf("Sua espada est� quebrada! N�o � poss�vel atacar.\n");
                }
                break;
            case 2:
                if (potion > 0) {
                    printf("Voc� usou uma Po��o de Vida e recuperou 10 pontos de vida.\n");
                    vida_personagem += 10;
                    potion--;
                } else {
                    printf("Voc� n�o tem po��es de vida!\n");
                }
                break;
            case 3:
                printf("Voc� decidiu sair da masmorra. Fim de jogo.\n");
                system("pause");
                return 0;
}exibir_status( vida_personagem,  vida_monstro, almas, vida_espada);
if (vida_personagem <= 0) {
            printf("Voc� foi derrotado! Game Over.\n");
            system("pause");
            return 0;
        } else if (vida_monstro <= 0) {
            printf("Voc� derrotou o monstro!\n");
            int almas_ganhas = aleatorio(9, 14);
            almas += almas_ganhas;
            printf("Voc� ganhou %d almas!\n", almas_ganhas);
}
}system("cls");
printf("Voc� estava explorando a regi�o, e percebe que esta sendo observado\n");
printf("Quando avan�a rapidamente para cima de voc� um Stray Demon, com um olhar mortal fixado em voc�\n");
printf("\033[1;31m"); 
efeitoDigitador("Lute pela sua sobreviv�ncia\n");  
printf("\033[0m");
vida_monstro=90;
exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
while( vida_monstro >0){ 
        printf("\nEscolha sua a��o:\n");
        printf("[1] - Atacar\n");
        printf("[2] - Usar Po��o de Vida\n");
        printf("[3] - Sair da Masmorra\n");
        printf("A��o: ");
        scanf("%d", &escolha2);

        switch (escolha2 ) {
            case 1:
                if (vida_espada > 0) {
                    int numero = aleatorio(1, 6);
                    resultado_acao(numero, &vida_personagem, &vida_monstro, &vida_espada);
                } else {
                    printf("Sua espada est� quebrada! N�o � poss�vel atacar.\n");
                }
                break;
            case 2:
                if (potion > 0) {
                    printf("Voc� usou uma Po��o de Vida e recuperou 10 pontos de vida.\n");
                    vida_personagem += 10;
                    potion--;
                } else {
                    printf("Voc� n�o tem po��es de vida!\n");
                }
                break;
            case 3:
                printf("Voc� decidiu sair da masmorra. Fim de jogo.\n");
                system("pause");
                return 0;
}exibir_status( vida_personagem,  vida_monstro, almas, vida_espada);
if (vida_personagem <= 0) {
            printf("Voc� foi derrotado! Game Over.\n");
            system("pause");
            return 0;
        } else if (vida_monstro <= 0) {
            printf("Voc� derrotou o monstro!\n");
            int almas_ganhas = aleatorio(20, 25);
            almas += almas_ganhas;
            printf("Voc� ganhou %d almas!\n", almas_ganhas);
}
}

printf("\n\nVoc� avan�a para a segunda fase...\n");
    printf("Ao entrar na pr�xima sala, voc� se depara com uma ponte estreita e uma criatura monstruosa bloqueando o caminho.\n");
    printf("A criatura parece extremamente perigosa. O que voc� deseja fazer?\n");
    printf("[1] - Lutar contra a criatura\n[2] - Procurar outro caminho\n");

    scanf("%d", &escolha);

    switch (escolha) {
    case 1:
        printf("Voc� decide lutar contra a criatura.\n");
        vida_monstro=100;
        exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
        break;
    case 2:
        printf("Voc� procura outro caminho para evitar a criatura.\n");
        printf("Infelizmente, voc� acaba caindo em uma armadilha e � capturado por uma horda de monstros. Voc� n�o sobrevive.\n");
        system("pause");
        return 0;
    default:
        printf("Op��o inv�lida!\n");
        return 0;
}

while (vida_personagem > 0 && vida_monstro > 0) {
    printf("\nEscolha sua a��o:\n");
    printf("[1] - Atacar\n");
    printf("[2] - Usar Po��o de Vida\n");
    printf("[3] - Sair da Masmorra\n");
    printf("A��o: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            if (vida_espada > 0) {
                int numero = aleatorio(1, 6);
                resultado_acao(numero, &vida_personagem, &vida_monstro, &vida_espada);
            } else {
                printf("Sua espada est� quebrada! N�o � poss�vel atacar.\n");
            }
            break;
        case 2:
            if (potion > 0) {
                printf("Voc� usou uma Po��o de Vida e recuperou 10 pontos de vida.\n");
                vida_personagem += 10;
                potion--;
            } else {
                printf("Voc� n�o tem po��es de vida!\n");
            }
            break;
        case 3:
            printf("Voc� decidiu sair da masmorra. Fim de jogo.\n");
            system("pause");
            return 0;
        default:
            printf("Op��o inv�lida!\n");
            break;
    }
    exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
    if (vida_personagem <= 0) {
        printf("Voc� foi derrotado!\n");
        printf("\033[1;31m"); 
        printf("GAME OVER!\n");
        printf("\033[0m");
        system("pause");
        return 0;
    } else if (vida_monstro <= 0) {
        printf("Voc� derrotou o monstro!\n");
        int almas_ganhas = aleatorio(30, 40);
        almas += almas_ganhas;
        printf("Voc� ganhou %d almas!\n", almas_ganhas);
    }
}
exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
int escolha4;
printf("Voc� coseguiu passar pela ponte e agora esta adentrando a segunda fase.\n");
printf("E avista uma caverna, oque voc� deseja fazer?\n");
printf("[1] - Entrar e explorar a caverna.\n [2] - seguir em dire��o a uma constru��o estranha.\n");
scanf("%d",&escolha4);
switch(escolha4){
    case 1:
    printf("Voc� come�a explorar a caverna.\n");
    printf("E encontrou um ba� no inicio da caverna.\n");
    printf("E decide abrir para ver oque tem dentro.\n");
    potion += 2;
    almas += 15;
    printf("Voc� encontrou 2 por�oes e 15 almas.");
    printf("Ao adentrar mais a caverna,voc� se depara com um terr�vel Iron Golem\n");
    efeitoDigitador("VOC� TER� QUE BATALHAR PELA SUA VIDA!!!!!\n");
    vida_monstro =70;
       while (vida_personagem > 0 && vida_monstro > 0) {
        printf("\nEscolha sua a��o:\n");
        printf("[1] - Atacar\n");
        printf("[2] - Usar Po��o de Vida\n");
        printf("[3] - Sair da Masmorra\n");
        printf("A��o: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if (vida_espada > 0) {
                    int numero = aleatorio(1, 6);
                    resultado_acao(numero, &vida_personagem, &vida_monstro, &vida_espada);
                } else {
                    printf("Sua espada est� quebrada! N�o � poss�vel atacar.\n");
                }
                break;
            case 2:
                if (potion > 0) {
                    printf("Voc� usou uma Po��o de Vida e recuperou 10 pontos de vida.\n");
                    vida_personagem += 10;
                    potion--;
                } else {
                    printf("Voc� n�o tem po��es de vida!\n");
                }
                break;
            case 3:
                printf("Voc� decidiu sair da masmorra. Fim de jogo.\n");
                system("pause");
                return 0;
            default:
                printf("Op��o inv�lida!\n");
                break;
        } exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
        }

        if (vida_personagem <= 0) {
            printf("Voc� foi derrotado! Game Over.\n");
            system("pause");
            return 0;
        } else if (vida_monstro <= 0) {
            printf("Voc� derrotou o monstro!\n");
            int almas_ganhas = aleatorio(20, 40);
            almas += almas_ganhas;
            potion += 2;
            printf("Voc� ganhou %d almas!\n", almas_ganhas);
            printf("Voc� ganhou 2 po��es!\n" );
            break;
            }
        case 2:
                printf("Voc� deixa a caverna de lado, e decide ir verificar a constru��o estranha.\n");
                printf("Ap�s caminhar alguns instantes voc� se aproxima da entrada da constru��o.\n");
                printf("Ao chegar na entrada da constru��o, voc� avista um ba� e sai em sua dire��o.\n");
                printf("Porem ao se aproximar avista um monstro proximo ao ba� o defendendo.\n");
                efeitoDigitador("Agora uma batalha � inevitavel, contra o terr�vel IROM GOLEM!!!!\n");
                vida_monstro= 70;
                while (vida_personagem > 0 && vida_monstro > 0) {
        printf("\nEscolha sua a��o:\n");
        printf("[1] - Atacar\n");
        printf("[2] - Usar Po��o de Vida\n");
        printf("[3] - Sair da Masmorra\n");
        printf("A��o: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if (vida_espada > 0) {
                    int numero = aleatorio(1, 6);
                    resultado_acao(numero, &vida_personagem, &vida_monstro, &vida_espada);
                } else {
                    printf("Sua espada est� quebrada! N�o � poss�vel atacar.\n");
                }
                break;
            case 2:
                if (potion > 0) {
                    printf("Voc� usou uma Po��o de Vida e recuperou 10 pontos de vida.\n");
                    vida_personagem += 10;
                    potion--;
                } else {
                    printf("Voc� n�o tem po��es de vida!\n");
                }
                break;
            case 3:
                printf("Voc� decidiu sair da masmorra. Fim de jogo.\n");
                system("pause");
                return 0;
            default:
                printf("Op��o inv�lida!\n");
                break;
        } exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
        }

        if (vida_personagem <= 0) {
            printf("Voc� foi derrotado! Game Over.\n");
            system("pause");
            return 0;
        } else if (vida_monstro <= 0) {
            printf("Voc� derrotou o monstro!\n");
            int almas_ganhas = aleatorio(20, 40);
            almas += almas_ganhas;
            potion += 2;
            printf("Voc� ganhou %d almas!\n", almas_ganhas);
            printf("Voc� ganhou 2 po��es!\n" );
            break;
            }
        }
            printf("Voc� passou por esse desafio e encontra um ferreiro e vai falar com ele\n");
            printf("O ferreiro percebendo sua situa��o ,lhe concede 1 po��o de vida gratuita\n");
            potion += 1;
            printf("O ferreiro te mostra as op��es.\n");
            comprar_item(&almas, &potion, &vida_espada);
            
            
            printf("\n Ao passar pelo ferreiro e avan�ar a proxima sala voc� nota que o ar esta muito pesado.....\n");
            printf("\n Voc� consegue escutar sons estranho vindo do fundo da caverna.... e isso de deixa com medo.....\n");
            efeitoDigitador("\n Hoc sepulchrum tuum erit, vita tua nunc exterminabitur.........\n");
            printf("\n Se prepare para a luta definitiva!\n");
            vida_monstro = 110;
            while (vida_personagem > 0 && vida_monstro > 0) {
        printf("\nEscolha sua a��o:\n");
        printf("[1] - Atacar\n");
        printf("[2] - Usar Po��o de Vida\n");
        printf("[3] - Sair da Masmorra\n");
        printf("A��o: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                if (vida_espada > 0) {
                    int numero = aleatorio(1, 6);
                    resultado_acao(numero, &vida_personagem, &vida_monstro, &vida_espada);
                } else {
                    printf("Sua espada est� quebrada! N�o � poss�vel atacar.\n");
                }
                break;
            case 2:
                if (potion > 0) {
                    printf("Voc� usou uma Po��o de Vida e recuperou 10 pontos de vida.\n");
                    vida_personagem += 10;
                    potion--;
                } else {
                    printf("Voc� n�o tem po��es de vida!\n");
                }
                break;
            case 3:
                printf("Voc� decidiu sair da masmorra. Fim de jogo.\n");
                system("pause");
                return 0;
            default:
                printf("Op��o inv�lida!\n");
                break;
        } exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
        }

        if (vida_personagem <= 0) {
            printf("Voc� foi derrotado! Game Over.\n");
            system("pause");
            return 0;
        } else if (vida_monstro <= 0) {
            printf("Mesmo em sua derrota, minhas palavras ecoam atrav�s do v�u da morte, amaldi�oando voc� para a eternidade, onde seu nome ser� sin�nimo de fracasso e sofrimento.\n\n"); 
            
            printf("Voc� derrotou o Deus da Noite e assim termina o seu reinado........... ou sera que n�o......");
            }
        
            
system("pause");
return 0;
}
