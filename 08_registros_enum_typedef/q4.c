#include <stdio.h>


//Enumeração representando itens do jogo
enum item{
  cura = 1,
  dinheiro, 
  vigor
};

//Enumeração representando as armadilhas
enum trap{
  buraco = 1,
  espinhos,
  ladrao
};

//Tipo Personagem, contendo vida e ataque. Usado para definir os inimigos e parte do Jogador
typedef struct person{
  int life, attack;
} Personagem;

//Tipo Jogador. Contém um Personagem com informações de vida e ataque, além de uma posição x,y e informações de dinheiro (loot) e se está equipado com escudo ou não.
typedef struct player{
  Personagem p; 
  int x, y, escudo, loot;
}Jogador;

//Tipo de dado Sala, representa uma casa do mapa. Pode conter um personagem inimigo, um tesouro e/ou uma armadilha
typedef struct room{
  Personagem p;
  int tesouro;
  int armadilha;
} Sala;

//Função principal

int main(){
  int n, m, movimentos, res;
  char passo;
  Jogador player;
  Sala** mapa;

  //Leitura do tamanho do mapa
  scanf("%d %d", &n, &m);

  //Função que cria o mapa e inicializa o Jogador de acordo com os dados da entrada
  mapa = cria_mapa(n, m, &player);

  //Leitura dos movimentos da simulação
  scanf("%d", &movimentos);

  //Para cada movimento do jogador...
  for(int i=0; i<movimentos; i++){
    //Lê o movimento
    scanf(" %c", &passo);

    //Executa a simulação do passo. Se o retorno for -1, o jogador morreu e encerra a simulação
    res = executa_passo(n, m, mapa, passo, &player);
    if(res == -1) break;
  }
 
  //Testa pra ver se o jogador terminou vivo
  res < 0 ? printf("You died...\n"): printf("Vitoria!\n");

  //Imprime as informações finais do jogador
  imprime_status_personagem(player);

  return 0;
}