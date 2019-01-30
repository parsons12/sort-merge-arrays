#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/* takes a file of numbers and reads them to an array
	param: fname is the file to be read
				v[] takes the array to read into
				n is the length of the array
 */
void readToArray(string fname, double v[], int n) {
	ifstream fin(fname.c_str());
	for (int i = 0; i < n; i++)
		fin >> skipws >> v[i];
	fin.close();
}

/*	sorts an array in ascending order,
		Implementation is selection sort
		param: v the array to sort
					 n the length of the array
*/
void sortArray(double v[], int n){
	int i, j, min;
	double tmp;
       for (i = 0; i < n - 1; i++) {
             min = i;
             for (j = i + 1; j < n; j++)
                   if (v[j] < v[min])
                         min = j;
             if (min != i) {
                   tmp = v[i];
                   v[i] = v[min];
                   v[min] = tmp;
             }
       }
}

/* Merges two arrays together while keeping them sorted
	param: v first array
				 q second array
				 n length of first array
				 m length of second array
				 out the merged output array
*/
void mergeArrays(double v[], double q[], int n,
                             int m, double out[])
{
    int i = 0, j = 0, k = 0;


    while (i<n && j <m)
    {

        if (v[i] < q[j])
            out[k++] = v[i++];
        else
            out[k++] = q[j++];
    }

    while (i < n)
        out[k++] = v[i++];

    while (j < m)
        out[k++] = q[j++];
}

/* Computes the average of an array
	 param: v the array to find avg
	 				n the length of the array
*/
double computeAvg(double v[], int n){
		double sum = 0;
		for(int i = 0; i < n; i++){
			sum = sum + v[i];
		}
		return sum/n;
}

/* Computes the median of an array
param: v the array to find avg
			 n the length of the array
*/
double computeMedian(double v[], int n){
		return v[n/2 + 1];
}

/* the driver class, initalizes variables and calls methods
	 to read the data into arrays and merge them. Displays the
	 average, median, and the merged array in an output file called
	 hw1Out.txt
*/
int main() {
	int n = 1067, m = 824;
	double avg, median;
	double data1[n];
	double data2[m];
	double mergedArray[n+m];

	readToArray("data1.txt", data1, n);
	readToArray("data2.txt", data2, m);
	sortArray(data1, n);
	sortArray(data2, m);
	mergeArrays(data1,data2,n,m,mergedArray);
	ofstream outputFile;
	outputFile.open("out.txt");
	avg = computeAvg(mergedArray, n+m);
	median = computeMedian(mergedArray, n+m);
	outputFile << "Average: " << avg << endl;
	outputFile << "Median: " << median << endl;
	for(int i = 0; i < n + m; i++){
		outputFile << mergedArray[i] << endl;
	}
	outputFile.close();
}
