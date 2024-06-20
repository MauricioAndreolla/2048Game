#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void inicio () {
	printf("Bem Vindo ao Jogo 2048");

	printf ("\nO objetivo do jogo tem com por objetivo formar um valor de 2048");

	printf("\npara movimentar todos os numeros para cima aperte a seta cima");

	printf("\npara movimentar todos os numeros para baixo aperte a seta baixo");

	printf("\npara movimentar todos os numeros para esquerda aperte a seta esquerda");

	printf("\npara movimentar todos os numeros para cima aperte a seta direita");
}

int leitura(char a,char b) {
	a = getch();
	if (a!=-32) {
		return 0;
	}
	if (a==-32) {
		b= getch();
		if (b==72) {
			// cima
			return 1;
		} else {
			if (b==80) {
				// baixo
				return 2;
			} else {
				if (b==77) {
					// direita
					return 3;
				} else {
					if (b==75) {
						// esquerda
						return 4;
					}
				}
			}
		}
	}
}

int randomicos(int vr[4],int count,int *r) {
	int a,b,i,flag=0,flag2=0;
	srand(time(NULL));
	for (; count<4;) {
		a = rand()%10;
		if (a>0 && a<4) {
			vr[count]=a;
			count ++;
		}
		if(vr[0]==vr[2] && vr[1]==vr[3]) { // SE NA GERAÇÃO DE LINHA E COLUNA OCORRER OS DOIS NUMEROS REPETE A OPERAÇÃO;
			while (flag2!=1) {
				a= rand()%10;
				b= rand()%10;
				if (a>=0 && a<4 && a!=vr[0]) {
					vr[2]=a;
					flag2=1;
				}
				if (b>=0 && b<4 && b!=vr[1]) {
					vr[3]=b;
					flag2=1;
				}
			}
		}
	}
	for(i=0; i<2; i++) { // new
		a = rand()%10;
		if (a==4) {
			flag = 1;
		}
	}
	if (flag==1) {
		*r= 4;
	} else {
		*r = 2;
	}
	return vr[count],*r;
}

int check(int m[4][4],int vr[4],int r,int control) {
	int a0,a1,a2,a3;
	a0= vr[0];
	a1= vr[1];
	a2= vr[2];
	a3= vr[3];

	if (control==0) {

		if (m[a0][a1]==0) {
			m[a0][a1]=2;
		}
		if (m[a2][a3]==0) {
			m[a2][a3]=2;
		}
	}
	if (control==1) {
		if (m[a0][a1]==0) {
			m[a0][a1]=r;
		} else {
			if (m[a2][a3]==0) {
				m[a2][a3]=r;
			}
		}
	}

	return m,vr,r;
}

void movimentacima(int m[4][4],int aux,int k,int i,int j,int soma,int control2) {

	for (k=0; k<4; k++) {
		for (i=1; i<4; i++) {
			for (j=0; j<4; j++) {
				soma=0;
				if (m[i][j]!=0) {
					if (m[i-1][j]==0) {
						aux= m[i-1][j];
						m[i-1][j]=m[i][j];
						m[i][j]=aux;
					} else {
						if (m[i-1][j]==m[i][j] && control2==0) {
							soma= m[i-1][j]+m[i][j];
							m[i][j]=0;
							m[i-1][j]=soma;
							control2==1;
						}
					}
				}
			}
		}
	}
}


void movimentabaixo(int m[4][4],int aux,int k,int i,int j,int soma,int control2) {

	for (k=0; k<4; k++) {
		for (i=2; i>=0; i--) {
			for (j=0; j<4; j++) {
				soma=0;
				if (m[i][j]!=0) {
					if (m[i+1][j]==0) {
						aux= m[i+1][j];
						m[i+1][j]=m[i][j];
						m[i][j]=aux;
					} else {
						if (m[i+1][j]==m[i][j] && control2==0 ) {
							soma= m[i+1][j]+m[i][j];
							m[i][j]=0;
							m[i+1][j]=soma;
							control2=1;
						}
					}
				}
			}
		}
	}
}

void movimentadireita(int m[4][4],int aux,int k,int i,int j,int soma,int control2) {

	for (k=0; k<4; k++) {
		for (i=0; i<4; i++) {
			for (j=0; j<3; j++) {
				if (m[i][j]!=0) {
					if (m[i][j+1]==0) {
						aux = m[i][j+1];
						m[i][j+1]=m[i][j];
						m[i][j]=aux;
					} else {
						if (m[i][j]==m[i][j+1] && control2==0) {
							soma = m[i][j]+m[i][j+1];
							m[i][j+1]=soma;
							m[i][j]=0;
							soma = 0;
							control2=1;
						}
					}
				}
			}
		}
	}
}


void movimentaesquerda(int m[4][4],int aux,int k,int i,int j,int soma,int control2) {
	for (k=0; k<4; k++) {
		for (i=0; i<4; i++) {
			for (j=3; j>0; j--) {
				if (m[i][j]!=0) {
					if (m[i][j-1]==0) {
						aux = m[i][j-1];
						m[i][j-1]=m[i][j];
						m[i][j]=aux;
					} else {
						if (m[i][j]==m[i][j-1] && control2==0) {
							soma = m[i][j]+m[i][j-1];
							m[i][j-1]=soma;
							m[i][j]=0;
							soma =0;
							control2=1;
						}
					}
				}
			}
		}
	}
}
int ganhouperdeu(int m[4][4],int l1,int c1,int *flag) {
	for (l1=0; l1<4; l1++) {
		for (c1=0; c1<4; c1++) {
			if (m[l1][c1]==2048) {
				printf("\nPARABENS VOCE CONSEGUIU ATINGIR O NUMERO 2048");
				return *flag=1;
			}
		}
	}
}

void printa(int m[4][4],int l,int c) {
	for (l=0; l<4; l++) {
		for (c=0; c<4; c++) {
			printf("|%d|\t", m[l][c]);
		}
		printf("\n");
	}

}

int main() {
	char a,b;
	int count=0,vr[4]= {0,0,0,0}; // randomicos
	int r=0; // usado passagem por referencia
	int flag=0; // variavel de teste
	int m[4][4]= {0,0,0,0,0,0,0,0,0,0,0,0} ;
	int aux,k,i,j,soma,operacao;
	int l,c,control=0,control2=0;
	int l1,c1,n;
	inicio();

	while (flag==0) {

		operacao=0;
		control2=0;

		operacao=leitura(a,b);

		randomicos(vr,count,&r);

		check(m,vr,r,control);

		if (operacao==1) {
			movimentacima(m,aux,k,i,j,soma,control2);
		}
		if (operacao==2) {
			movimentabaixo(m,aux,k,i,j,soma,control2);
		}
		if (operacao==3) {
			movimentadireita(m,aux,k,i,j,soma,control2);
		}
		if (operacao==4) {
			movimentaesquerda(m,aux,k,i,j,soma,control2);
		}
		if (operacao==0) {
			printf("\n\nOPERACAO INVALIDA\n");
			printf("DIGITE UMA TECLA VALIDA\n");
		}

		ganhouperdeu(m,l1,c1,&flag);



		control=1;
		printf("\n");
		printa(m,l,c);

	}
	return 0;
}
