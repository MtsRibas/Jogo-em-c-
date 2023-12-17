

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>
#include <string.h>

int aleatorio(int min, int max)
{
    srand(time(NULL));
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

void efeitoDigitador(char texto[])
{
    int i = 0;
    while (texto[i] != '\0')
    {
        printf("%c", texto[i]);
        fflush(stdout);
        Sleep(30);
        i++;
    }
}

void resultado_acao(int numero, int *vida_personagem, int *vida_monstro, int *vida_espada)
{
    if (numero == 1 || numero == 2)
    {
        int dano1 = 5;
        printf("Você danificou sua espada neste ataque e causou %d de dano\n", dano1);
        *vida_espada -= 3;
        *vida_monstro -= 5;
    }
    else if (numero >= 3 && numero <= 5)
    {
        int total = aleatorio(8, 12);
        printf("Você acertou o ataque e causou %d de dano!\n", total);
        *vida_monstro -= total;
    }
    else if (numero == 6)
    {
        int total1 = 19;
        printf("Você acertou um ataque crítico e causou %d de dano!\n", total1);
        *vida_monstro -= 19;
    }
    else
    {
        printf("Bug! Número errado recebido no resultado_acao\n");
    }

    if (*vida_monstro > 0)
    {
        int dano_monstro = aleatorio(4, 6);
        printf("O monstro te atacou e causou %d de dano!\n", dano_monstro);
        *vida_personagem -= dano_monstro;
    }
}

void exibir_status(int vida_personagem, int vida_monstro, int almas, int vida_espada)
{
    printf("\n---- Status ----\n");
    printf("Vida do Personagem: %d\n", vida_personagem);
    printf("Vida do Monstro: %d\n", vida_monstro);
    printf("Almas: %d\n", almas);
    printf("Vida da Espada: %d\n", vida_espada);
    printf("----------------\n\n");
}
void personagem_status(int vida_personagem, int almas, int vida_espada)
{
    printf("\n---- Status ----\n");
    printf("Vida do Personagem: %d\n", vida_personagem);
    printf("Almas: %d\n", almas);
    printf("Vida da Espada: %d\n", vida_espada);
    printf("----------------\n\n");
}

void comprar_item(int *almas, int *potion, int *vida_espada)
{
    int escolha2;

    printf("\n---- Loja ----\n");
    printf("[1] - Comprar Poção de Vida (Custo: 10 almas, Efeito: +10 HP)\n");
    printf("[2] - Concertar a Espada (Custo: 10 almas)\n");
    printf("[3] - Sair da Loja\n");
    printf("Escolha o item que deseja comprar: ");
    scanf("%d", &escolha2);

    switch (escolha2)
    {
    case 1:
        if (*almas >= 10)
        {
            printf("Você comprou uma Poção de Vida!\n");
            *almas -= 10;
            *potion += 1;
        }
        else
        {
            printf("Você não tem almas suficientes para comprar este item!\n");
        }
        break;
    case 2:
        printf("Você decidiu consertar sua espada.\n");
        *vida_espada = 100;
        break;
    default:
        printf("Opção inválida!\n");
        break;
    }
}
int main()
{
    int inicio, escolha, potion = 0, almas = 0, escolha2;
    int vida_personagem = 100, vida_monstro = 20, gold = 0, dano_arma = 10, vida_espada = 100;
    char nome[50];
    setlocale(LC_ALL, "portuguese");

    printf(" \n _________________________________________________________________________________");
    printf(" \n                     ºººººººººººººººººººººººººº");
    printf(" \n                              SOULFORGED ");
    printf(" \n                     ºººººººººººººººººººººººººº");
    printf(" \n _________________________________________________________________________________\n");

    efeitoDigitador("\n\nNum mundo envolto em trevas, onde a luz se esvaiu, surge um herói destinado a enfrentar os horrores da escuridão. Em um reino amaldiçoado, ele parte em busca do temido Deus da Noite, um ser sinistro que espalha terror entre os habitantes. Armado com coragem e uma lâmina incandescente, o herói se aventura em florestas sombrias e cavernas tenebrosas, prontas para revelar os segredos ocultos e desafios mortais que o aguardam. Seu destino se entrelaça com o destino do mundo, enquanto ele se prepara para a batalha que decidirá o futuro de todos.");

    efeitoDigitador("\n\nVocê quer participar dessa Jornada?");
    efeitoDigitador("\n[1] - Sim ou [2] - Não\n");
    scanf("%d", &inicio);
    if (inicio == 1)
    {
        printf("Muito bom, vamos adentrar na masmorra.\n");
    }
    else if (inicio == 2)
    {
        printf("Que pena, perdemos um guerreiro.\n");
        system("pause");
        return 0;
    }
    else
    {
        printf("Caractere inválido.\n");
        system("pause");
        return 0;
    }

    printf("Me diga, qual é o seu nome guerreiro?: \n");
    scanf("%s", nome);
    system("cls");

    exibir_status(vida_personagem, 0, almas, vida_espada);
    printf("Ok %s, estamos adentrando na masmorra, fique de olhos bem abertos e atento.\n\n", nome);
    printf("Para te auxiliar na jornada, eu lhe concedo a espada de prata de Lican. \n\n");
    printf("Me acompanhe que eu vou te mostrar o que essa masmorra nos aguarda.\n\n");

    printf("No início da masmorra você observa de longe.....");
    printf("\n1 - Baú\n2 - Monstro\n");
    printf("Você deve tomar uma decisão:\n");
    printf("\n\n[1] - Abrir o baú\n[2] - Batalhar com o monstro (Será liberado o avanço de sala após a derrota do monstro)\n");

    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        printf("Você encontrou 4 poções de vida e 20 almas.\n");
        potion += 4;
        almas += 20;
        printf("Você deve agora enfrentar o monstro para prosseguir.\n");
        break;
    case 2:
        printf("Se prepare para uma batalha frenética.\n");
        break;
    default:
        printf("Opção inválida!\n");
        system("pause");
        return 0;
    }

    while (vida_personagem > 0 && vida_monstro > 0)
    {
        printf("\nEscolha sua ação:\n");
        printf("[1] - Atacar\n");
        printf("[2] - Usar Poção de Vida\n");
        printf("[3] - Sair da Masmorra\n");
        printf("Ação: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            if (vida_espada > 0)
            {
                int numero = aleatorio(1, 6);
                resultado_acao(numero, &vida_personagem, &vida_monstro, &vida_espada);
            }
            else
            {
                printf("Sua espada está quebrada! Não é possível atacar.\n");
            }
            break;
        case 2:
            if (potion > 0)
            {
                printf("Você usou uma Poção de Vida e recuperou 10 pontos de vida.\n");
                vida_personagem += 10;
                potion--;
            }
            else
            {
                printf("Você não tem poções de vida!\n");
            }
            break;
        case 3:
            printf("Você decidiu sair da masmorra. Fim de jogo.\n");
            system("pause");
            return 0;
        default:
            printf("Opção inválida!\n");
            break;
        }
        exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
    }

    if (vida_personagem <= 0)
    {
        printf("Você foi derrotado! Game Over.\n");
        system("pause");
        return 0;
    }
    else if (vida_monstro <= 0)
    {
        printf("Você derrotou o monstro!\n");
        int almas_ganhas = aleatorio(5, 10);
        almas += almas_ganhas;
        printf("Você ganhou %d almas!\n", almas_ganhas);
    }
    system("cls");
    personagem_status(vida_personagem, almas, vida_espada);
    printf("Você esta avançando para a próxima sala.\n");
    printf("Nesta nova sala você se depara com um ferreiro.\n");
    printf("\nEscolha uma opção:\n");
    printf("[1] - Ir ao ferreiro\n");
    printf("[2] - Abrir o baú\n");
    printf("[3] - Enfrentar um novo monstro\n");
    scanf("%d", &escolha2);

    switch (escolha2)
    {
    case 1:
        printf("Você decidiu ir ao ferreiro.\n");
        comprar_item(&almas, &potion, &vida_espada);
        personagem_status(vida_personagem, almas, vida_espada);
        int escolha3;
        printf("Deseja abrir o baú ou enfrentar um novo monstro?\n");
        printf("[1]. Abrir o baú.\n");
        printf("[2]. Enfrentar um novo monstro.\n");
        scanf("%d", &escolha3);
        switch (escolha3)
        {
        case 1:
            printf("Você abriu o baú e achou um coração que lhe concede 25 HP e 20 almas.\n");
            vida_personagem += 25;
            almas += 20;
            printf("Você irá sentir a ira do monstro, Gravelord Nito! Prepare-se para sofrer.\n");
            vida_monstro = 38;
            break;
        case 2:
            printf("Você decidiu enfrentar um novo monstro.\n");
            vida_monstro = 38;
            break;
        default:
            printf("Opção inválida!\n");
            system("pause");
            return 0;
        }
        break;
    case 2:
        printf("Você abriu o baú e achou um coração que lhe concede 25 HP e 20 almas.\n");
        vida_personagem += 25;
        almas += 20;
        printf("Você irá sentir a ira do monstro, Gravelord Nito! Prepare-se para sofrer.\n");
        vida_monstro = 38;
        exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
        break;
    case 3:
        printf("Você escolheu enfrentar o monstro, grande coragem!\n");
        printf("Você irá sentir a ira do monstro, Gravelord Nito! Prepare-se para sofrer.\n");
        vida_monstro = 38;
        exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
        break;
    default:
        printf("Opção inválida!\n");
        system("pause");
        return 0;
    }
    while (vida_monstro > 0)
    {
        printf("\nEscolha sua ação:\n");
        printf("[1] - Atacar\n");
        printf("[2] - Usar Poção de Vida\n");
        printf("[3] - Sair da Masmorra\n");
        printf("Ação: ");
        scanf("%d", &escolha2);

        switch (escolha2)
        {
        case 1:
            if (vida_espada > 0)
            {
                int numero = aleatorio(1, 6);
                resultado_acao(numero, &vida_personagem, &vida_monstro, &vida_espada);
            }
            else
            {
                printf("Sua espada está quebrada! Não é possível atacar.\n");
            }
            break;
        case 2:
            if (potion > 0)
            {
                printf("Você usou uma Poção de Vida e recuperou 10 pontos de vida.\n");
                vida_personagem += 10;
                potion--;
            }
            else
            {
                printf("Você não tem poções de vida!\n");
            }
            break;
        case 3:
            printf("Você decidiu sair da masmorra. Fim de jogo.\n");
            system("pause");
            return 0;
        }
        exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
        if (vida_personagem <= 0)
        {
            printf("Você foi derrotado! Game Over.\n");
            system("pause");
            return 0;
        }
        else if (vida_monstro <= 0)
        {
            printf("Você derrotou o monstro!\n");
            int almas_ganhas = aleatorio(9, 14);
            almas += almas_ganhas;
            printf("Você ganhou %d almas!\n", almas_ganhas);
        }
    }
    system("cls");
    printf("Você estava explorando a região, e percebe que esta sendo observado\n");
    printf("Quando avança rapidamente para cima de você um Stray Demon, com um olhar mortal fixado em você\n");
    printf("\033[1;31m");
    efeitoDigitador("Lute pela sua sobrevivência\n");
    printf("\033[0m");
    vida_monstro = 90;
    exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
    while (vida_monstro > 0)
    {
        printf("\nEscolha sua ação:\n");
        printf("[1] - Atacar\n");
        printf("[2] - Usar Poção de Vida\n");
        printf("[3] - Sair da Masmorra\n");
        printf("Ação: ");
        scanf("%d", &escolha2);

        switch (escolha2)
        {
        case 1:
            if (vida_espada > 0)
            {
                int numero = aleatorio(1, 6);
                resultado_acao(numero, &vida_personagem, &vida_monstro, &vida_espada);
            }
            else
            {
                printf("Sua espada está quebrada! Não é possível atacar.\n");
            }
            break;
        case 2:
            if (potion > 0)
            {
                printf("Você usou uma Poção de Vida e recuperou 10 pontos de vida.\n");
                vida_personagem += 10;
                potion--;
            }
            else
            {
                printf("Você não tem poções de vida!\n");
            }
            break;
        case 3:
            printf("Você decidiu sair da masmorra. Fim de jogo.\n");
            system("pause");
            return 0;
        }
        exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
        if (vida_personagem <= 0)
        {
            printf("Você foi derrotado! Game Over.\n");
            system("pause");
            return 0;
        }
        else if (vida_monstro <= 0)
        {
            printf("Você derrotou o monstro!\n");
            int almas_ganhas = aleatorio(20, 25);
            almas += almas_ganhas;
            printf("Você ganhou %d almas!\n", almas_ganhas);
        }
    }

    printf("\n\nVocê avança para a segunda fase...\n");
    printf("Ao entrar na próxima sala, você se depara com uma ponte estreita e uma criatura monstruosa bloqueando o caminho.\n");
    printf("A criatura parece extremamente perigosa. O que você deseja fazer?\n");
    printf("[1] - Lutar contra a criatura\n[2] - Procurar outro caminho\n");

    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        printf("Você decide lutar contra a criatura.\n");
        vida_monstro = 100;
        exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
        break;
    case 2:
        printf("Você procura outro caminho para evitar a criatura.\n");
        printf("Infelizmente, você acaba caindo em uma armadilha e é capturado por uma horda de monstros. Você não sobrevive.\n");
        system("pause");
        return 0;
    default:
        printf("Opção inválida!\n");
        return 0;
    }

    while (vida_personagem > 0 && vida_monstro > 0)
    {
        printf("\nEscolha sua ação:\n");
        printf("[1] - Atacar\n");
        printf("[2] - Usar Poção de Vida\n");
        printf("[3] - Sair da Masmorra\n");
        printf("Ação: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            if (vida_espada > 0)
            {
                int numero = aleatorio(1, 6);
                resultado_acao(numero, &vida_personagem, &vida_monstro, &vida_espada);
            }
            else
            {
                printf("Sua espada está quebrada! Não é possível atacar.\n");
            }
            break;
        case 2:
            if (potion > 0)
            {
                printf("Você usou uma Poção de Vida e recuperou 10 pontos de vida.\n");
                vida_personagem += 10;
                potion--;
            }
            else
            {
                printf("Você não tem poções de vida!\n");
            }
            break;
        case 3:
            printf("Você decidiu sair da masmorra. Fim de jogo.\n");
            system("pause");
            return 0;
        default:
            printf("Opção inválida!\n");
            break;
        }
        exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
        if (vida_personagem <= 0)
        {
            printf("Você foi derrotado!\n");
            printf("\033[1;31m");
            printf("GAME OVER!\n");
            printf("\033[0m");
            system("pause");
            return 0;
        }
        else if (vida_monstro <= 0)
        {
            printf("Você derrotou o monstro!\n");
            int almas_ganhas = aleatorio(30, 40);
            almas += almas_ganhas;
            printf("Você ganhou %d almas!\n", almas_ganhas);
        }
    }
    exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
    int escolha4;
    printf("Você coseguiu passar pela ponte e agora esta adentrando a segunda fase.\n");
    printf("E avista uma caverna, oque você deseja fazer?\n");
    printf("[1] - Entrar e explorar a caverna.\n [2] - seguir em direção a uma construção estranha.\n");
    scanf("%d", &escolha4);
    switch (escolha4)
    {
    case 1:
        printf("Você começa explorar a caverna.\n");
        printf("E encontrou um baú no inicio da caverna.\n");
        printf("E decide abrir para ver oque tem dentro.\n");
        potion += 2;
        almas += 15;
        printf("Você encontrou 2 porçoes e 15 almas.");
        printf("Ao adentrar mais a caverna,você se depara com um terrível Iron Golem\n");
        efeitoDigitador("VOCÊ TERÁ QUE BATALHAR PELA SUA VIDA!!!!!\n");
        vida_monstro = 70;
        while (vida_personagem > 0 && vida_monstro > 0)
        {
            printf("\nEscolha sua ação:\n");
            printf("[1] - Atacar\n");
            printf("[2] - Usar Poção de Vida\n");
            printf("[3] - Sair da Masmorra\n");
            printf("Ação: ");
            scanf("%d", &escolha);

            switch (escolha)
            {
            case 1:
                if (vida_espada > 0)
                {
                    int numero = aleatorio(1, 6);
                    resultado_acao(numero, &vida_personagem, &vida_monstro, &vida_espada);
                }
                else
                {
                    printf("Sua espada está quebrada! Não é possível atacar.\n");
                }
                break;
            case 2:
                if (potion > 0)
                {
                    printf("Você usou uma Poção de Vida e recuperou 10 pontos de vida.\n");
                    vida_personagem += 10;
                    potion--;
                }
                else
                {
                    printf("Você não tem poções de vida!\n");
                }
                break;
            case 3:
                printf("Você decidiu sair da masmorra. Fim de jogo.\n");
                system("pause");
                return 0;
            default:
                printf("Opção inválida!\n");
                break;
            }
            exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
        }

        if (vida_personagem <= 0)
        {
            printf("Você foi derrotado! Game Over.\n");
            system("pause");
            return 0;
        }
        else if (vida_monstro <= 0)
        {
            printf("Você derrotou o monstro!\n");
            int almas_ganhas = aleatorio(20, 40);
            almas += almas_ganhas;
            potion += 2;
            printf("Você ganhou %d almas!\n", almas_ganhas);
            printf("Você ganhou 2 poções!\n");
            break;
        }
    case 2:
        printf("Você deixa a caverna de lado, e decide ir verificar a construção estranha.\n");
        printf("Após caminhar alguns instantes você se aproxima da entrada da construção.\n");
        printf("Ao chegar na entrada da construção, você avista um baú e sai em sua direção.\n");
        printf("Porem ao se aproximar avista um monstro proximo ao baú o defendendo.\n");
        efeitoDigitador("Agora uma batalha é inevitavel, contra o terrível IROM GOLEM!!!!\n");
        vida_monstro = 70;
        while (vida_personagem > 0 && vida_monstro > 0)
        {
            printf("\nEscolha sua ação:\n");
            printf("[1] - Atacar\n");
            printf("[2] - Usar Poção de Vida\n");
            printf("[3] - Sair da Masmorra\n");
            printf("Ação: ");
            scanf("%d", &escolha);

            switch (escolha)
            {
            case 1:
                if (vida_espada > 0)
                {
                    int numero = aleatorio(1, 6);
                    resultado_acao(numero, &vida_personagem, &vida_monstro, &vida_espada);
                }
                else
                {
                    printf("Sua espada está quebrada! Não é possível atacar.\n");
                }
                break;
            case 2:
                if (potion > 0)
                {
                    printf("Você usou uma Poção de Vida e recuperou 10 pontos de vida.\n");
                    vida_personagem += 10;
                    potion--;
                }
                else
                {
                    printf("Você não tem poções de vida!\n");
                }
                break;
            case 3:
                printf("Você decidiu sair da masmorra. Fim de jogo.\n");
                system("pause");
                return 0;
            default:
                printf("Opção inválida!\n");
                break;
            }
            exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
        }

        if (vida_personagem <= 0)
        {
            printf("Você foi derrotado! Game Over.\n");
            system("pause");
            return 0;
        }
        else if (vida_monstro <= 0)
        {
            printf("Você derrotou o monstro!\n");
            int almas_ganhas = aleatorio(20, 40);
            almas += almas_ganhas;
            potion += 2;
            printf("Você ganhou %d almas!\n", almas_ganhas);
            printf("Você ganhou 2 poções!\n");
            break;
        }
    }
    printf("Você passou por esse desafio e encontra um ferreiro e vai falar com ele\n");
    printf("O ferreiro percebendo sua situação ,lhe concede 1 poção de vida gratuita\n");
    potion += 1;
    printf("O ferreiro te mostra as opções.\n");
    comprar_item(&almas, &potion, &vida_espada);

    printf("\n Ao passar pelo ferreiro e avançar a proxima sala você nota que o ar esta muito pesado.....\n");
    printf("\n Você consegue escutar sons estranho vindo do fundo da caverna.... e isso de deixa com medo.....\n");
    efeitoDigitador("\n Hoc sepulchrum tuum erit, vita tua nunc exterminabitur.........\n");
    printf("\n Se prepare para a luta definitiva!\n");
    vida_monstro = 110;
    while (vida_personagem > 0 && vida_monstro > 0)
    {
        printf("\nEscolha sua ação:\n");
        printf("[1] - Atacar\n");
        printf("[2] - Usar Poção de Vida\n");
        printf("[3] - Sair da Masmorra\n");
        printf("Ação: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            if (vida_espada > 0)
            {
                int numero = aleatorio(1, 6);
                resultado_acao(numero, &vida_personagem, &vida_monstro, &vida_espada);
            }
            else
            {
                printf("Sua espada está quebrada! Não é possível atacar.\n");
            }
            break;
        case 2:
            if (potion > 0)
            {
                printf("Você usou uma Poção de Vida e recuperou 10 pontos de vida.\n");
                vida_personagem += 10;
                potion--;
            }
            else
            {
                printf("Você não tem poções de vida!\n");
            }
            break;
        case 3:
            printf("Você decidiu sair da masmorra. Fim de jogo.\n");
            system("pause");
            return 0;
        default:
            printf("Opção inválida!\n");
            break;
        }
        exibir_status(vida_personagem, vida_monstro, almas, vida_espada);
    }

    if (vida_personagem <= 0)
    {
        printf("Você foi derrotado! Game Over.\n");
        system("pause");
        return 0;
    }
    else if (vida_monstro <= 0)
    {
        printf("Mesmo em sua derrota, minhas palavras ecoam através do véu da morte, amaldiçoando você para a eternidade, onde seu nome será sinônimo de fracasso e sofrimento.\n\n");

        printf("Você derrotou o Deus da Noite e assim termina o seu reinado........... ou sera que não......");
    }

    system("pause");
    return 0;
}
