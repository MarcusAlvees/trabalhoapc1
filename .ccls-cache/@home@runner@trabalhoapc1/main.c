#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main() {
  //srandom(time(NULL));
  //result = rand() % 20;
  
  int num1;
  int num2;
  int operador;
  int level;
  char operadorChar;
  float resultado;
  float resposta;
  char resposta1[21];
  int pontuacao = 0;
  int num_max;
  

  printf("Bem Vindo ao Jogo da Matemática\n");
  printf("Deseja Começar? [Sim/Não]\n");
  int deu_certo = scanf("%s", resposta1);
  for(int i; i<strlen(resposta1); i++) {
    resposta1[i] = toupper(resposta1[i]);
  }
  
  if(strcmp(resposta1, "SIM")) {
    while(1)
    {
      printf("Escolha uma dificuldade: \n");
      printf("1 - Fácil \n");
      printf("2 - Médio \n");
      printf("3 - Difícil \n");
      deu_certo = scanf("%i", &level);
      if(!deu_certo)
      {
        printf("Número Inválido, Tente Novamente\n");
        while(getchar() != '\n');
      }
      if(level > 3 || level < 1)
      {
        printf("Número Inválido, Tente Novamente\n");
        while(getchar() != '\n');
      }
      else{
        break;
      }
    }
    
    system("clear");
    
    switch(level) {
      case 1: {
        num_max = 50;
        break;
      }
      case 2: {
        num_max = 100;
        break;
      }
      case 3: {
        num_max = 1000;
        break;
      }
    }
    
    do {
      srand(time(NULL));
      num1 = rand() % num_max;
      num2 = rand() % num_max;
      operador = rand() % 4;
      
      switch(operador) {
        case 0: {
          resultado = num1 + num2;
          operadorChar = '+';
          break;
        }
        case 1: {
          resultado = num1 - num2;
          operadorChar = '-';

          break;
        }
        case 2: {
          resultado = num1 * num2;
          operadorChar = '*';

          break;
        }
        case 3: {
          if(num1 % num2 != 0) {
            operador = rand() % 4;
            operadorChar = '/';
            break;
          }
          resultado = num1 / num2;
          operadorChar = '/';

          break;
        }
      }
      
      printf("%d %c %d = ", num1, operadorChar, num2);
      deu_certo = scanf("%f", &resposta);

      if(resposta == resultado) {
        system("clear");
        pontuacao++;
        printf("CORRETO! %d pontos\n", pontuacao);
      }
      
    } while(resposta == resultado);
      
    printf("GAME OVER! você conseguiu %d pontos!\n", pontuacao);
  }
  return 0;
}