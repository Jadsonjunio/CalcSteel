#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

struct Metal{
	char tipo[100];
	float precometro;
	float altura;
	float comprimento;
	float metroquadrado;
	float custo;
	float maodeobra;
	float percentual;
};

struct Transporte{
	float gasolina;
	float distancia;
	float consumokm;
	float consumototal;
};

struct Item{
	char nameit[100];
	int quantit;
	float precoit;
	float itempreco;
	
};

struct Metal cadastro[10];
	float calccusto(float precometro, float metroquadrado){
	float custo;
	custo = precometro * metroquadrado;
	return custo;
};

struct Transporte consumo[10];
	float calcconsumo(float gasolina, float distancia, float consumokm){
		float consumototal;
		consumototal = gasolina * distancia * consumokm;
		return consumototal;
	}

struct Item adicional[100];
	float calcitem(int quantit, float precoit){
		float itempreco;
		itempreco = quantit * precoit;
		return itempreco;
	}

int main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	int opt, i, j, item;
	float entrega, somapreco;
	float precofinal[10];
	float orfinal;
	
	
		
	do{
		system("cls");
		printf("\n\t\t\t\t\t -----CalcSteel----\n");		
		printf("1 - cadastrar novo orçamento.\n");
		printf("2 - listar opções de orçamento.\n");
		printf("3 - adicionar entrega.\n");
		printf("4 - adicionar itens para confecção.\n");
		printf("5 - detalhar orçamento.\n");
		printf("6 - apagar orçamento.\n");
		printf("0 - sair\n\n");
		
		scanf("%d", &opt);
		
		if(opt == 0){
			break;
		}
		switch(opt){
			case 1:
				printf("Digite a posição do orçamento 1 a 10: \n");
				scanf("%d", &i);
				printf("Qual o tipo do metal: \n");
				scanf("%s", &cadastro[i].tipo);
				printf("Digite o preço por m² do metal desejado: \n");
				scanf("%f", &cadastro[i].precometro);
				printf("Digite a altura: \n");
				scanf("%f", &cadastro[i].altura);
				printf("Digite o comprimento: \n");
				scanf("%f", &cadastro[i].comprimento);						
				printf("Adicione o valor percentual da mão de obra: \n");
				scanf("%f", &cadastro[i].percentual);
				cadastro[i].metroquadrado = cadastro[i].altura * cadastro[i].comprimento;
				cadastro[i].custo = cadastro[i].precometro * cadastro[i].metroquadrado;
				cadastro[i].maodeobra = cadastro[i].custo * cadastro[i].percentual / 100;
				
				
			case 2:				
				precofinal[i] = cadastro[i].custo + cadastro[i].maodeobra + consumo[i].consumototal;
				printf("\n");
				for(i=1;i<=10;i++){
				if(cadastro[i].custo != 0){	
					if(consumo[i].consumototal !=0){
						printf("Orçamento-%d - %s | material %.2fm² X R$:%.2f = R$:%.2f\n | mão de obra R$:%.2f custo do transporte = R$:%.2f | preço final = R$:%.2f\n", i,
						 cadastro[i].tipo,cadastro[i].metroquadrado, cadastro[i].precometro, cadastro[i].custo, cadastro[i].maodeobra, consumo[i].consumototal, precofinal[i]);
					}else{
						printf("Orçamento-%d - %s | material %.2fm² X R$:%.2f = R$:%.2f | mão de obra R$:%.2f | preço final = R$:%.2f \n", i, 
						cadastro[i].tipo,cadastro[i].metroquadrado, cadastro[i].precometro, cadastro[i].custo, cadastro[i].maodeobra, precofinal[i]);
					}		
				}
				}
				system("pause");
			break;
			case 3:
				
				printf("Digite a posição do orçamento que queira adicionar a entrega: \n");
				scanf("%d", &i);
				printf("Digite o preço atual da gasolina: \n");
				scanf("%f", &consumo[i].gasolina);
				printf("Digite a distancia em km: \n");
				scanf("%f", &consumo[i].distancia);
				printf("Digite a autonomia em km/l de combustível: \n");
				scanf("%f", &consumo[i].consumokm);
				consumo[i].consumototal = (consumo[i].distancia / consumo[i].consumokm ) * consumo[i].gasolina ;
			break;
			
			case 4:
				printf("Digite a posição do orçamento que queira adicionar a entrega: \n");
				scanf("%d", &i);
				
				do{
					
				system("cls");
				
					printf("Qual o nome do item: \n");
					scanf("%s", &adicional[i].nameit);
					printf("Qual o valor do item: \n");
					scanf("%f", &adicional[i].precoit);
					printf("Qual a quantidade de itens: \n");
					scanf("%d", &adicional[i].quantit);
					adicional[i].itempreco = adicional[i].precoit * adicional[i].quantit;
					j = adicional[i].itempreco;
					somapreco = somapreco + adicional[i].itempreco;
					i++;
					
				printf("Deseja adicionar mais alguma item? 1-SIM | 2-NÃO\n");
				scanf("%d", &item);
				
				}while(item == 1);
			break;
			
			case 5:
				printf("Digite a posição a ser listada: \n");
				scanf("%d", &i);
				j = i;
				
				for(i=1;i<=10;i++){
					if(adicional[i].quantit != 0){
					printf("Item = %s - preço/unidade = %.2f - quantidade = %d - preço total %.2f\n", 
					adicional[i].nameit, adicional[i].precoit, adicional[i].quantit, adicional[i].itempreco);
				}
			}
					printf("Preço total dos itens:  R$:%.2f\n", somapreco);
					printf("\n");
					
					printf("Orçamento-%d - %s | material %.2fm² X %.2f = R$:%.2f\n | mão de obra R$:%.2f custo do transporte = R$:%.2f | preço final = R$:%.2f\n\n", j,
						 cadastro[j].tipo,cadastro[j].metroquadrado, cadastro[j].precometro, cadastro[j].custo, cadastro[j].maodeobra, consumo[j].consumototal, precofinal[j]);
					orfinal = somapreco + precofinal[j];
					printf("Orçamento completo:  R$:%.2f\n", orfinal);
					
					printf("\n");
				system("pause");
			break;
			
			case 6:
				printf("Digite a posição a ser apagada: \n");
				scanf("%d", &i);
				cadastro[i].custo = 0;
			break;
		default:
			printf("Opção inválida!\n");
			system("pause");
		}
	}while(1==1);
	
	return 0;
} 
