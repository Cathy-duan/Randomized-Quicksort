#include<iostream>
#include<ctime>
#include<cstdlib>
#include<chrono>

using namespace std;


void print(int arr[], int n) {
	cout << "{";
	for (int i = 0; i < n; i++) {
		if (i + 1 != n)
			cout << arr[i] << ",";
		else
			cout << arr[i];
	}
	cout << "}";
}
void swap(int& m, int& n) {
	int temp = m;
	m = n;
	n = temp;
}
int RandomizedPartition(int* arr, int p, int q) {
	int r = p + rand() % (q - p + 1);
	swap(arr[r], arr[p]);
	int pivot = arr[p];
	int i = p;
	for (int j = p + 1; j <= q; j++) {
		if (arr[j] <= pivot) {
			i = i + 1;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[p], arr[i]);
	return i;
}

void RandomizedQuicksort(int* arr, int p, int q) {
	if (p < q) {
		int r = RandomizedPartition(arr, p, q);
		RandomizedQuicksort(arr, p, r - 1);
		RandomizedQuicksort(arr, r + 1, q);
	}
}
int main() {
	using namespace std::chrono;
	clock_t startTime, endTime;

	//Generate input array
	const int N = 100;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = i + 1;
	}
	srand((unsigned)time(NULL));

	for (int i = 0; i < 5; i++) {
		for (int i = N - 1; i > 0; i--) {
			int index = rand() % i;
			int temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}

		//Print input array
		cout << "Input array: ";
		print(arr, N);
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		//startTime = clock();
		RandomizedQuicksort(arr, 0, N - 1);
		//endTime = clock();
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
		cout << "\nRunning time: " << time_span.count() << " seconds.";
		//cout << "\nRunning time: " << (double)(endTime - startTime)/ CLOCKS_PER_SEC << " seconds";
		//cout << "\nstartTime:" << startTime;
		//cout << "\nendTime:" << endTime;
		//Print output array
		cout << "\nOutput array: ";
		print(arr, N);
		cout << endl<<endl;
	}
	return 0;
}