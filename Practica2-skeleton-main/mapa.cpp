
#include <stdio.h>

void iniciar_taula(float taula[][4]){
	//bucle que crea una taula amb 0s
	for (int i = 0; i < 950; i++){
		for (int j = 0; j < 4; j++){
			taula[i][j] = 0;
		}
	}
}
void llegir_localitzacio(float taula[][4]){
	char c;
	int comptador_columnes = 0, comptador_linies = 0;
	float valor;

	//bucle per llegir el fitxer
	do {
		scanf("%c", &c);
		if (c == ','){
			scanf("%c", &c);
			if(c == '"'){
				comptador_columnes++;
				if(comptador_columnes == 5){
					scanf("%f", &valor);
					taula[comptador_linies][0] = valor;
					
				}		
				if(comptador_columnes == 13){
					scanf("%f", &valor);
					taula[comptador_linies][1] = valor;
				}

				if(comptador_columnes == 14){
					scanf("%f", &valor);
					taula[comptador_linies][2] = valor;
				}
			}
		} 
			
		if (c == '\n'){
			comptador_linies++;
			comptador_columnes = 0;

		}

	}while (c != '#');


}
void buscar_localitzacio(float taula [][4], float num_casos, float codi_municipi){
	for (int j = 0; j < 950; j++){
		if (taula[j][0] == codi_municipi){
			taula[j][3] = taula [j][3] + num_casos;
		}
	
	}



}
void llegir_registre(float taula [][4]){
	char c;
	float codi_municipi, num_casos;
	int comptador_columnes = 0;

		do {
			scanf("%c", &c);
			if (c == ','){
				comptador_columnes++;
				if (comptador_columnes == 3){
					scanf("%f", &codi_municipi);
				}
				if (comptador_columnes == 8){
					scanf("%f", &num_casos);
				}
			} 
			
			if (c == '\n'){
				buscar_localitzacio(taula, num_casos, codi_municipi);
				comptador_columnes = 0;
			}

		} while (c != '#');

		for (int i = 0; i < 950; i++){
			for (int j = 0; j < 4; j++){
				printf("%f\t", taula[i][j]);
			}
			printf("\n");				
		}

}
int coordenada_x(float x){
	float coordenada = 0.25 + 0.1515;
	for (int i = 0; i < 20; i++){
		if (x <= coordenada){
			return i;
		} else{
			coordenada = coordenada + 0.1515;
		}
	}
	
	return -1;
}
int coordenada_y(float y){
	float coordenada = 40.54 + 0.115;
	for (int j = 0; j < 20; j++){
		if (y <= coordenada){
			return j;
		} else{
			coordenada = coordenada + 0.115;
		}
	}
	return -1;
}
void crear_mapa(float taula[][4], int mapa[][20]){

	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 20; j++){
			mapa[i][j] = 0;
		
		}
	}
	for (int j = 0; j < 950; j++){
		if (taula[j][0] != 0){

			int x = coordenada_x(taula[j][1]);
			int y = coordenada_y(taula[j][2]);

												//taula[j][3] = num_casos
			mapa[x][y] = mapa [x][y] + taula[j][3];


		}




	}
	
	
}

int main() {
	float localitzacio[950][4]; //creem una taula, 950 ja que tenim 947 municipis, i 4 perquè volem llegir la longitud, latitud, el codi del municipi i el número de casos				corresponent
	int mapa[20][20];

	iniciar_taula(localitzacio); 
	llegir_localitzacio(localitzacio);
	llegir_registre(localitzacio);
	crear_mapa(localitzacio, mapa);

	
	
}
