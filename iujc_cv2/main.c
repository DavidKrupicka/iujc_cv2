#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void priklad1();
void priklad2();
void priklad3();

int main(){
	//priklad1();
	//priklad2();
	priklad3();
	system("pause");
}

void priklad1(){
	//rand(); //generuje nahodna cisla <0; intmax>
	//srand(); //set rand, abych nedostaval stejnou poslouponost vyuzivam time, pripravuje nasadu pro rand

	int t = time(NULL);
	int rovno0 = 0,
		zaporne = 0,
		kladne = 0,
		intDo100 = 0,
		intDo1000 = 0;

	srand(t);

	int length = 100, nahCislo;

	for (int i = 0; i < length; i++)
	{
		nahCislo = rand() % 2001 - 1000; //vypis cisel <-1000; 1000>

		if (nahCislo == 0)
			rovno0++;
		else if (nahCislo > 0){
			kladne++;
			if (nahCislo <= 100)
				intDo100++;
			else
				intDo1000++;
		}
		else
			zaporne++;

		//printf("%d\n", nahCislo);
	}

	printf("rovnych 0 \t %d \n", rovno0);
	printf("kladnych  \t %d \n", kladne);
	printf("zapornych  \t %d \n", zaporne);
	printf("<0, 100> \t %d \n", intDo100);
	printf("<0, 1000> \t %d \n", intDo1000);
}

void priklad2(){
	int a, b, c, cont = 1;

	while (cont == 1){
		printf("zadej tri strany a b c \n");
		scanf("%d", &a);
		scanf("%d", &b);
		scanf("%d", &c);

		if ((a + b > c) && (a + c > b) && (b + c > a)){
			printf("trojuhelnik lze sestrojit\n");
			cont = 0;
		}
		else
			printf("trojuhelnik nelze sestrojit\n");
	}
}

void priklad3(){
	int nahCislo, pocetPokusu, pokus, uhodnul = 0;
	int t = time(NULL);

	srand(t);
	nahCislo = rand() % 21;

	printf("Zadej hadane cislo\n");

	while (uhodnul == 0){
		scanf("%d", &pokus);
		if (pokus == nahCislo){
			uhodnul = 1;
			printf("Gratuluji, uhodl jsi cislo %d\n", nahCislo);
		}
		else if (pokus < nahCislo){
			printf("Zadej vetsi cislo\n");
		}
		else
			printf("Zadej mensi cislo\n");
	}
}