/*
https://www.pilotopolicial.com.br/calculando-distancias-e-direcoes-utilizando-coordenadas-geograficas/
*/

#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
#define DISTMAX 20 /* Foi utilizado uma definição de constante para que seja facil
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
	float tutor,x_tutor,y_tutor,x_pet,y_pet,pet;

	printf("Informe as coordenadas do tutor\n");
	scanf("%f", &x_tutor);
	scanf("%f", &y_tutor);
	
	printf("Informe as coordenadas do pet\n", );
	scanf("%f", &x_pet);
	scanf("%f", &y_pet);

	tutor = (x_tutor * -1) + (y_tutor * -1) * 111.11;
	pet = (x_pet * -1) + (y_pet * -1) * 111.11;

	dist2pontos(tutor, pet);
}

/*Função feita para calcular a distancia entre os dois pontos, retornando a
distancia já calculada.*/
float dist2pontos(float DLA, float DLO){

	float DISTANCIA;
	
	DISTANCIA = hypot(DLA,DLO); //sqrt(pow(DLA,2)+pow(DLO,2));

	return DISTANCIA;
}
float ParaRad(float grau){
	float rad;
	rad = grau * (PI/180);

	return rad;
}
float CalcularDistancia( float nLat1, float nLon1, float nLat2, float nLon2 )
{
    float nRadius = 6371; // Raio da terra em KM
 
    float nDLat = ParaRad(nLat2 - nLat1);
    float nDLon = ParaRad(nLon2 - nLon1);
 
    nLat1 =  ParaRad(nLat1);
    nLat2 =  ParaRad(nLat2);
 
    float nA = pow ( sin(nDLat/2), 2 ) + cos(nLat1) * cos(nLat2) * pow ( sin(nDLon/2), 2 );
 
    float nC = 2 * atan2( sqrt(nA), sqrt( 1 - nA ));
    float nD = nRadius * nC;
 
    return nD; // Return our calculated distance
}
/*Foi utilizado a formula de haversine para o calculo de distância entre 
os dois pontos.
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