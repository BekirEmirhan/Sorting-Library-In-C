#include <stdio.h>
#include <stdlib.h>



/* Counting sort */
int *counting(int *arr,int size){
	int *c = (int*)malloc(sizeof(int)*size);
	int *b = (int*)malloc(sizeof(int)*size);
	for(int i=0;i<k;i++) c[i] =0;
	for(int j=0;j<size;j++) c[(int)arr[j]] = c[(int)arr[j]] +1; 
	for(int i=1;i<k;i++) c[i] = c[i] + c[i-1];
	for(int j=size;j>0;j--){
		b[(int)c[(int)arr[j]]] = arr[j];
		c[(int)arr[j]] = c[(int)arr[j]]-1;
	}
	return b;

}



/* Double Pivot Quicksort */


int partition(double* arr, int low, int high, int* lp);

void swap(double* a, double* b){
	double temp = *a;
	*a = *b;
	*b = temp;
}

void DualPivotQuickSort(double* arr, int low, int high){
	if (low < high) {
		int lp, rp;
		rp = partition(arr, low, high, &lp);
		DualPivotQuickSort(arr, low, lp - 1);
		DualPivotQuickSort(arr, lp + 1, rp - 1);
		DualPivotQuickSort(arr, rp + 1, high);
	}
}

int partition(double* arr, int low, int high, int* lp){
	if (arr[low] > arr[high])
		swap(&arr[low], &arr[high]);
	int j = low + 1;
	int g = high - 1, k = low + 1;
	double p = arr[low], q = arr[high];
	while (k <= g) {
		if (arr[k] < p) {
			swap(&arr[k], &arr[j]);
			j++;
		}

		else if (arr[k] >= q) {
			while (arr[g] > q && k < g)
				g--;
			swap(&arr[k], &arr[g]);
			g--;
			if (arr[k] < p) {
				swap(&arr[k], &arr[j]);
				j++;
			}
		}
		k++;
	}
	j--;
	g++;
	swap(&arr[low], &arr[j]);
	swap(&arr[high], &arr[g]);
	*lp = j; 

	return g;
}



/* Merge Sort */

void merge(double *arr, int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	double *L = (double*)malloc(sizeof(double)*(n1+1));
	double *R = (double*)malloc(sizeof(double)*(n2+1));
	for (i = 0; i < n1; i++)
	L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
	R[j] = arr[m + 1 + j];
	L[n1]=100000000.0;
	R[n2]=100000000.0;
	i = 0; 
	j = 0;
	for (int k=l; k<=r;k++){ 
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
	}
}
void mergeSort(double *arr, int l, int r){
	if (l < r) {
		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}



/* Insertion Sort */

void insertion(double arr[],int size){
	int i = 1;
	while(i<size){
		int j = i-1;
		int temp= arr[i];
		while(arr[j] >temp && j>=0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
		i++;
	
	}
}



/* Selection Sort */

void selection(double *arr,int size){
	for(int i=0;i<size;i++){
		int k=i;
		double small = arr[i];
		for(int j=i+1;j<size;j++){
			if(arr[j]<arr[k]) k=j;
		}
		double temp = arr[i];
		arr[i] = arr[k];
		arr[k] = temp;
	}
}



/* Quicksort */

int partition (double *arr, int low, int high) { 
    double mean =0;
    for(int i=low;i<=high;i++){
	 mean += arr[i];
    }
    mean = mean/(high-low+1);
    double f = abs(mean -arr[low]);
    int index = low;
    for(int i = low+1;i<=high;i++){
	if(abs(mean-arr[i]) < f) {
		index = i;
		f = abs(mean-arr[i]);
	}
    }
    double temp1 = arr[high];
    arr[high] = arr[index];
    arr[index] = temp1;
    double pivot = arr[high];
    int i = (low - 1);
  
    for (int j = low; j < high; j++){ 
        if (arr[j] <= pivot) { 
            	i++; 
		double temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
        } 
    } 
	double temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
    return i + 1; 
} 

void quickSort(double *arr, int low, int high) { 
    if (low < high) { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 



/* Bubble Sort */


void bubbleSort(double *arr,int size){
	
	for (int i=size-1;i>0;i--){
		for(int j=0;j<i;j++){
			if(arr[j]>arr[j+1]){
				double temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		
	}
}


