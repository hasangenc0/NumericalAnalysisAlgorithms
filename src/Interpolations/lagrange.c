/**
* veri.txt
* 5
* 1.0 0.7651977
* 1.3 0.6200860
* 1.6 0.4554022
* 1.9 0.2818186
* 2.2 0.1103623
*/

#include <stdio.h>

// prototypes
int lagrange(); // reads points and 

// file name
char filename[8] = "veri.txt";

int main() {
	lagrange();
}

int lagrange() {
	int size;
	double result = 0;
	double desired;
	FILE *fp;

	// check file exist
	if( (fp = fopen(filename, "r")) == NULL ) {
		printf("%s File not found. \n", filename);
		return 0;
	} 

	// get point size
	fscanf(fp, "%d", &size);
	printf("Point Count: %d\n", size);
 
	double arr[size][size];

	printf("Values:\n");
	for (int i = 0; !feof(fp) ; i++) {
		fscanf(fp, "%lf%lf", &arr[i][0], &arr[i][1]);
		printf("%lf %lf \n", arr[i][0], arr[i][1]);
	}

	// close file
	fclose(fp);

	printf("Enter the Desired mid point\n");
	scanf("%lf", &desired);

	double coeff[size];

	for(int i = 0; i < size; i++) {
		coeff[i] = 1;
		for(int k = 0; k < size; k++) {
			if (k == i) continue;
			coeff[i] *= (desired - arr[k][0]) / (arr[i][0] - arr[k][0]);
		}
		coeff[i] *= arr[i][1];
	}

	printf("Lagrange Coefficents:\n");

	for(int i = 0; i < size; i++) {
		printf("%lf\n", coeff[i]);
		result += coeff[i];
	}

	printf("Result: %lf\n", result);

	return 0;
}
