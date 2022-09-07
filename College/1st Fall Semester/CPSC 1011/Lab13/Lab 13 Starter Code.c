//Selection Sort
    int i = 0; int j = 0; int temp = 0;
    int index_smallest = 0;

    for (i = 0; i < num i++){
        index_smallest = i;
        for (j = i + 1; j < num; j++){
            if (numberArray[j] < numberArray[index_smallest])
                index_smallest = j;
        }
        temp = numberArray[i];
        numberArray[i] = numberArray[index_smallest];
        numberArray[index_smallest] = temp;
    } 

// Insertion Sort
    int temp = 0; int i = 0; int j = 0;

    for (i = 1; i < num; i++){
        temp = numberArray[i];
        j = i - 1;
        while (temp < numberArray[j] && j >= 0){
            numberArray[j+1] = numberArray[j];
            j--;
        }
        numberArray[j+1] = temp;
    } 

// Bubble Sort
    int i = 0; int j = 0; int temp = 0;

    for (i = 0; i < num; i++){

        for (int j = 0; j < (num - i - 1); j++){
            if (numberArray[j]> numberArray[j+1]){
                temp = numberArray[j];
                numberArray[j] = numberArray[j+1];
                numberArray[j+1] = temp;
            }
        }
    } 


// Quick Sort

    int pivot = 0;
    int i = 0;
    int j = 0;
    int temp = 0;

    if (low < high){
        pivot = low;
        i = low;
        j = high;

        while (i < j){
            while (numberArray[i] <= numberArray[pivot] && i <= high){
                i++;
            }
            while (numberArray[j] > numberArray[pivot] && j >=low){
                j--;
            }

            if (i < j) {
                temp = numberArray[i];
                numberArray[i] = numberArray[j];
                numberArray[j] = temp;
            }

        }
        temp = numberArray[j];
        numberArray[j] = numberArray[pivot];
        numberArray[pivot] = temp;
        quickSort(low, j-1, numberArray);
        quickSort(j+1, high, numberArray);
    } 

// Write Integer Array to Output File
// Write Integer Array to Output File
void writeArrayToFile(int array[], int num) {
  FILE * pFile;
  switch(num) {//based off the file size create a new file with size name
    case 10:
		pF = fopen("sorted.algorithm.small.output", "w+");
		break;
    case 100:
		pF = fopen("sorted.algorithm.medium.output", "w+");
		break;
    case 1000:
		pF = fopen("sorted.algorithm.large.output", "w+");
		break;
    case 10000:
		pF = fopen("sorted.algorithm.jumbo.output", "w+");
		break;
	default:
		pFile = fopen("rand" , "w+");
 		break;
  }
  
  if (pFile == NULL) {
	  perror ("Error opening file");
  }
  else
  {
    int i;
    for(i = 0; i < num; i++) {
      fprintf(pFile, "%d, ", array[i]);
    }
    fclose (pFile);
  }
  return;
}