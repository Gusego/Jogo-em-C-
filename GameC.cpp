#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

typedef struct{
	int dificuldade;
	int valor1;
	int valor2;
	int operacao;
	int resultado;
} Calcular;

void jogar();

void mostrarInfo(Calcular calc);

int pontos = 0;

int main(){
	setlocale(LC_ALL,"portuguese");
	//Deve ser chamado apenas 1 vez.
	srand(time(NULL));
	
	jogar();
	
	return 0;
}



void mostrarInfo(Calcular calc){
	char op[25];
	
	if(calc.operacao == 0){//0 == somar
		sprintf(op,"Somar");
	}else if(calc.operacao == 1){//1==diminuir
		sprintf(op,"Diminuir");
	}else if(calc.operacao == 2){//2==multiplicar
		sprintf(op,"Multiplicar");
	}else{
		sprintf(op,"Opera��o desconhecida");
	}
	printf("Valor 1: %d\nValor2: %d\nDificuldade: %d\nOpera��o: %s",calc.valor1,calc.valor2,calc.dificuldade,op);
	 
}

int somar(int resposta, Calcular calc){
	int resultado = calc.valor1+calc.valor2;
	calc.resultado=resultado;
	
	int certo = 0;//0 == errou, 1 == acertou
	if(resposta==calc.resultado){
		printf("Resposta correta!\n");
		certo=1;
	}else{
		printf("Resposta errada!\n");
	}
	printf("%d + %d = %d\n",calc.valor1,calc.valor2,calc.resultado);
	return certo;
}
int diminuir(int resposta, Calcular calc){
	int resultado = calc.valor1 - calc.valor2;
	calc.resultado=resultado;
	
	int certo = 0;//0 == errou, 1 == acertou
	if(resposta==calc.resultado){
		printf("Resposta correta!\n");
		certo=1;
	}else{
		printf("Resposta errada!\n");
	}
	printf("%d - %d = %d\n",calc.valor1,calc.valor2,calc.resultado);
	return certo;
	
}
int multiplicar(int resposta, Calcular calc){
	int resultado = calc.valor1 * calc.valor2;
	calc.resultado=resultado;
	
	int certo = 0;//0 == errou, 1 == acertou
	if(resposta==calc.resultado){
		printf("Resposta correta!\n");
		certo=1;
	}else{
		printf("Resposta errada!\n");
	}
	printf("%d x %d = %d\n",calc.valor1,calc.valor2,calc.resultado);
	return certo;
	
}
void jogar(){
	Calcular calc;
	int dificuldade;
	 
 	printf("Informe o nivel de dificuldade desejada[1][2][3][4]:\n");
	scanf("%d", &dificuldade);
	 
	calc.dificuldade=dificuldade;
	 
	//gera um valor inteiro randomico entre 0 e 2
	//0 == somar, 1 == diminuir, 2 == multiplicar
	calc.operacao=rand()%3;
	 
	if(calc.dificuldade==1){
		//f�cil
		calc.valor1= rand()% 11;//0 a 10
		calc.valor2= rand()% 11;
	}else if(calc.dificuldade==2){
		//m�dia
		calc.valor1 = rand()%101;//0 a 100
		calc.valor2 = rand()%101;
	}else if(calc.dificuldade==3){
		//dificil
		calc.valor1 = rand()%1001;//0 a 1000
		calc.valor2 = rand()%1001;		
	}else if (calc.dificuldade == 4){
		//muito dificil(insano)
		calc.valor1 = rand() % 10001;//0 a 1000
		calc.valor2 = rand() % 10001;
	}else{
		//o pr�prio einstein 
		calc.valor1 = rand() % 100000001;//0 a 100000000
		calc.valor2 = rand() % 100000001;
	} 
	 int resposta;
	 printf("Informe o resultado para a seguinte opera��o: \n");
	 
	 if (calc.operacao == 0){//somar
	 	printf("%d + %d\n",calc.valor1,calc.valor2);
	 	scanf("%d", &resposta);
	 	
	 	if(somar(resposta, calc)){
	 		pontos+=1;
	 		printf("Voc� tem %d pontos\n", pontos);
		 }
	 }else if (calc.operacao == 1){//diminuir
	 	printf("%d - %d\n",calc.valor1,calc.valor2);
	 	scanf("%d", &resposta);
	 	
	 	if(diminuir(resposta, calc)){
	 		pontos+=1;
	 		printf("Voc� tem %d pontos\n", pontos);
		 }
	 }else if (calc.operacao == 2){//multiplicar
	 	printf("%d x %d\n",calc.valor1,calc.valor2);
	 	scanf("%d", &resposta);
	 	
	 	if(multiplicar(resposta, calc)){
	 		pontos+=1;
	 		printf("Voc� tem %d pontos\n", pontos);
		 }
	 }//desconhecida
	 else{
	 	printf("A opera�� %d n�o � reconhecida.\n",calc.operacao);
	 }
	 
	 //recome�ar o jogo?
	 printf("Deseja continuar o jogo ? [1] - Sim / [0] - N�o\n");
	 int continuar;
	 scanf("%d", &continuar);
	 
	 if(continuar){
	 	jogar();
	 }else{
	 	printf("Voc� finalizou com %d ponto(s). \n", pontos);
	 	exit(0);
	 }
}
