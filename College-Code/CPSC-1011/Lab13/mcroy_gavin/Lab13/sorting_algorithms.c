//---Finds minimum element and keeps putting it at the beginning
void SelectionSort(int numberArray[], int num) {
    int i = 0;
    int j = 0;
    int temp = 0;
    int index_smallest = 0;
    for (i = 0; i < num; i++) {
        index_smallest = i;
        for (j = i + 1; j < num; j++) {
            if (numberArray[j] < numberArray[index_smallest])
                index_smallest = j;
        }
        temp = numberArray[i];
        numberArray[i] = numberArray[index_smallest];
        numberArray[index_smallest] = temp;
    }
}
//---
void InsertionSort(int numberArray[], int num) {
    int temp = 0;
    int i = 0;
    int j = 0;
    for (i = 1; i < num; i++) {
        temp = numberArray[i];
        j = i - 1;
        while (temp < numberArray[j] && j >= 0) {
            numberArray[j + 1] = numberArray[j];
            j--;
        }
        numberArray[j + 1] = temp;
    }
}


void BubbleSort(int numberArray[], int num) {
    int i = 0;
    int temp = 0;
    for (i = 0; i < num; i++) {
        for (int j = 0; j < (num - i - 1); j++) {
            if (numberArray[j] > numberArray[j + 1]) {
                temp = numberArray[j];
                numberArray[j] = numberArray[j + 1];
                numberArray[j + 1] = temp;
            }
        }
    }
    //return numberArray;
}

void QuickSort(int low, int high, int numberArray[]) {
    int pivot = 0;
    int i = 0;
    int j = 0;
    int temp = 0;

    if (low < high) {
        pivot = low;
        i = low;
        j = high;

        while (i < j) {
            while (numberArray[i] <= numberArray[pivot] && i <= high) {
                i++;
            }
            while (numberArray[j] > numberArray[pivot] && j >= low) {
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
        QuickSort(low, j - 1, numberArray);
        QuickSort(j + 1, high, numberArray);
    }
}

