#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
#define DISTMAX 20 /* Foi utilizado uma definição de constante para que seja fácil
a mudança, caso necessário for.*/

void insere_dados(){
	/*
	coordenadas que abrangem toda a praça
	-15.833468 > x > -15.833019
	-48.057221 > y > -48.055902
	inserção para o calculo da distancia
	
	15,832655-15,833114
	48,056063-48,055921
	*/
	float tutor,xTutor,yTutor,xPet,yPet,pet;

	printf("Informe as coordenadas do tutor\n");
	scanf("%f", &xTutor);
	scanf("%f", &yTutor);
	fflush(stdin);
	printf("Informe as coordenadas do pet\n");
	scanf("%f", &xPet);
	scanf("%f", &yPet);

	CalcularDistancia(xTutor,yTutor,xPet,yPet);

}

float CalcularDistancia( float nLat1, float nLon1, float nLat2, float nLon2 )
{
    float nRadius, nDLat,nDLon,nA, nC,nD;
 	
 	nRadius = 6371; // Raio da terra em KM
    
    nDLat = (nLat2 - nLat1);
    nDLon = (nLon2 - nLon1);
 
    nLat1 =  (nLat1);
    nLat2 =  (nLat2);
 
    nA = pow ( sin(nDLat/2), 2 ) + cos(nLat1) * cos(nLat2) * pow ( sin(nDLon/2), 2 );
 
    nC = 2 * atan2( sqrt(nA), sqrt( 1 - nA ));
    nD = nRadius * nC;
 
    return nRadius* nD *1000; // Retorna a distancia/1000 pois está em KM.
}
/*Foi utilizado a formula de HAVERSINE para o calculo de distância entre 
os dois pontos.
fonte: https://pt.wikipedia.org/wiki/Fórmula_de_Haversine
*/
void alerta(float DISTANCIA){
	
	if(DISTANCIA < DISTMAX){
		printf("Pet está em distancia segura.\n");
		insere_dados();

	}else {
		if(DISTANCIA > DISTMAX){
			printf("ALERTA, pet está em distancia acima do permitido\n");
			insere_dados(); 
		}
	}
}

int main(){
	
	insere_dados();

	return 0;
}