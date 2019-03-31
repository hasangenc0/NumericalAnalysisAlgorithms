/** TODO
 * hasan genc
 */

#include <stdio.h>

// prototypes
int hermit();

const char filename[8] = "data.txt";

int main() {
	hermit();

  return 0;
}

int hermit() {
  int size;
  double desired;
  FILE *fp;

  if( (fp = fopen('data.txt', 'r')) == NULL) {
    return 0;
  }

  // get point size
	fscanf(fp, "%d", &size);

  double arr[size][size];

	printf("Values:\n");
	for (int i = 0; !feof(fp) ; i++) {
		fscanf(fp, "%lf%lf", &arr[i][0], &arr[i][1]);
		printf("%lf %lf \n", arr[i][0], arr[i][1]);
	}

	// close file
	fclose(fp);

  double coeff[size];

  printf("Enter the Desired mid point\n");
	scanf("%lf", &desired);

	for(int i = 0; i < size; i++) {
		coeff[i] = 1;
		for(int k = 0; k < size; k++) {
			if (k == i) continue;
			coeff[i] *= (desired - arr[k][0]) / (arr[i][0] - arr[k][0]);
		}
		coeff[i] *= arr[i][1];
	}

  return 0;
}