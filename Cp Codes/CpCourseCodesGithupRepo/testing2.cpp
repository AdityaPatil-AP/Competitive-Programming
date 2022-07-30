// // C++ program to illustrate std::istringstream
// // to tokenize the string
// #include <iostream>
// #include <sstream>
// #include <string>
// using std::istringstream;
// using std::string;
// using std::cout;

// // Driver Code
// int main()
// {
// 	// Input string
// 	string str("abc,def,ghi");

// 	// Object class of istringstream
// 	istringstream my_stream(str);

// 	// To store the stream string
// 	string token;

// 	size_t pos = -1;

// 	// Traverse till stream is valid
// 	while (my_stream >> token) {

// 		// If ',' is found then tokenize
// 		// the string token
// 		while ((pos = token.rfind(','))
// 			!= std::string::npos) {
// 			token.erase(pos, 1);
// 		}

// 		// Print the tokenize string
// 		cout << token << '\n';
// 	}
// }

#include <stdio.h> 
void combinationUtil(int arr[], int n, int r,int index, int data[], int i); 
void printCombination(int arr[], int n, int r) 
{ 
 int data[r]; 
 combinationUtil(arr, n, r, 0, data, 0); 
} 
void combinationUtil(int arr[], int n, int r, int index,int data[], int i) 
{ 
 if (index == r) 
 { 
 for (int j = 0; j < r; j++) 
 printf("%d ", data[j]); 
 printf("\n"); 
 return; 
 } 
 if (i >= n) 
 return; 
 data[index] = arr[i]; 
 combinationUtil(arr, n, r, index + 1, data, i + 1); 
 combinationUtil(arr, n, r, index, data, i + 1); 
} 
int main() 
{ 
 int arr[50],num, i ,r; 
 printf("Enter no. of elements in array: "); 
 scanf("%d",&num); 
 printf("Enter the %d elements: ",num); 
 for(i=0;i<num;i++) 
 scanf("%d",&arr[i]); 
 r = 2; 
 printCombination(arr,num, r); 
 return 0; 
} 


