/**
 * Hasan Genç
 */
/**
 * veri.txt file format
 * 5
 * 1.8 10.889365
 * 1.9 12.703199
 * 2.0 14.778112
 * 2.1 17.148957
 * 2.2 19.855030
 */

#include <stdio.h>

// filename
char filename[8] = "veri.txt";

//prototypes
void findDerivative();

int main() {
	findDerivative();

	return 0;
}

void  findDerivative() {
	int size;
	double result = 0;
	double desired;
	FILE *fp;

	// check file exist
	if( (fp = fopen(filename, "r")) == NULL ) {
		printf("%s File not found. \n", filename);
		return;;
	} 

	// get point size
	fscanf(fp, "%d", &size);
	printf("Point Count: %d\n", size);

 	if ( size < 3) {
		printf("Turev Alma metodunu uygulamak için en az 3 nokta verilmesi gerekir\n");
		return;
 	}

	double arr[size][size];

	printf("Values:\n");
	for (int i = 0; i < size ; i++) {
		fscanf(fp, "%lf%lf", &arr[i][0], &arr[i][1]);
		printf("%lf %lf \n", arr[i][0], arr[i][1]);
	}

	// close file
	fclose(fp);
	
	// result will be save to this array
	double results[size];

	// set h value which is in the formula
	const double h = arr[1][0] - arr[0][0]; 

	for(int i = 0; i < size; i++) {

		if (i == 0) { // if it is first point then apply first formula
			double fx0 = arr[i][1];
			double fx1 = arr[i + 1][1];
			double fx2 = arr[i + 2][1];
			results[i] = ( 1/(2*h) ) * (-3*fx0 + 4*fx1 - fx2);
			printf("%d'inci noktanun türevi: %lf\n", i, results[i]);
		} else if (i == (size -1)) { // if it is last value apply third formula
			double fx0 = arr[i - 2][1];
			double fx1 = arr[i - 1][1];
			double fx2 = arr[i][1];
			results[i] = ( 1/(2*h) ) * (fx0 - 4*fx1 + 3*fx2);
			printf("%d'inci noktanun türevi: %lf\n", i, results[i]);
		} else { // if it is between first and last apply second formula
			double fx1 = arr[i + -1][1];
			double fx2 = arr[i + 1][1];
			results[i] = ( 1/(2*h) ) * (fx2 - fx1);
			printf("%d'inci noktanun türevi: %lf\n", i, results[i]);
		}

	}

	return;
}
