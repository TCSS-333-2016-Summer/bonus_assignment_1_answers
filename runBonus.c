#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void allocate10(int **a){
	*a=malloc(10*sizeof(int));
	if(!a) exit(EXIT_FAILURE);
	for(int i=0;i<10;i++){
  (*a)[i]=i;
	}
}

void joinStrings(char *a,char *b, char **c){
	int length=strlen(a)+strlen(b)+1;
	*c=malloc(length);
	if(!*c){
		exit(EXIT_FAILURE);
	}
	strcpy(*c,a);
	strcat(*c,b);
}

void arrayWrite(int (*a)[3],int size, char *binaryFilename){
	FILE *binfp=fopen(binaryFilename,"w");
	if(!binfp)exit(EXIT_FAILURE);
	fwrite(a,size*sizeof(a[0]),1,binfp);
	fclose(binfp);
}

void binaryIO(char *binaryFilename,char *textFilename){
	FILE *binfp=fopen(binaryFilename,"r");
	if(!binfp)exit(EXIT_FAILURE);
	FILE *textfp=fopen(textFilename,"w");
	if(!textfp)exit(EXIT_FAILURE);
	int i=0;
 while(fread(&i,sizeof(int),1,binfp)){
	 fprintf(textfp,"%d,%d\n",i,i*i);
 }
 fclose(binfp);
	fclose(textfp);
}
void arrayCopy(int (*a)[3],int **b, int **c,int *sizes) {
	for(int i=0;i<sizes[0];i++){
		for(int j=0;j<sizes[1];j++){
			b[i][j]=a[i][j];
			c[i][j]=a[i][j];
		}	
	}	
}
	
int main(){
	int *a;
	char *b="Hello ";
	char *c= "World";
	char *d;
	char *file1="e.bin";
	char *file2="text.bin";
	int size;
	int sizes[2];
	int e[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
	int **f;
 int **g;
	
	//1 mark
	//write a function "allocate10" that allocates space for 10 integer using the parameter list
	//in other words the function is of VOID type, takes a parameter and allocates and assigns memory to that parameter
	//call the function to allocate and assign memory to a
	//use a loop in the function to assign a[0] to a[9] to integers 0 to 9 
	//print the values out one per line in the main program
	//To be clear - the memory is allocated and assigning values happens in the function
	//in the main function
 //free the memory in a
 allocate10(&a);
 for(int i=0;i<10;i++){
  printf("%d\n",a[i]);
	}
 //1 mark 
 //Write a function "joinStrings" takes as parameters 3 strings. It joins the first 2 together and puts the result in the third string
 //The function allocates memory for the third string using malloc
 //apply the function to strings b,c, and d. After the function is done d should have memory allocated to it and contain "Hello World"
 //the function should not assume the sizes of b or c - it needs to be general enough for any string
 //after calling the function using b,c,d as parameters print out d from the main function
 //free the memory in d
 
 joinStrings(b,c,&d);
 printf("%s\n",d); 

 //1 mark
 //write a function "arrayWrite" that takes as parameters an array of the same type as e, the size of the first dimension, and a string variables, binaryFilename
 //the function "arrayWrite" writes the values of the the array (starting from array[0][0] and ending at array[size-1][2]) to the binaryFilename
 //apply the function to array e and file1
 size=4;
 arrayWrite(e,size,file1);
 
 //1 mark
 //write a function "binaryIO" to take as a parameter two filenames
 //it opens the first file which is binary reads in sizeof(int) bytes at a time
 //it writes value and the value squared separated by a ',' one set of values per line i.e.
 //0,0
 //1,1
 //2,4 
 //etc. to a the second file
 //
 //run the function with parameters file1, file2
 //so at the end of this there should be two new files
 
 binaryIO(file1,file2);
 
 //2 marks
 //malloc and assign memory for	f as a pointer to pointers to integer style array of the same size as e
 //malloc and assign memory for g as a pointer to pointer to integer where you assign the pointers to a block of memory the size of e
	//write a function "arrayCopy" that that takes parameters of the same type as e, f, and g and a sizes array parameter
	//sizes is an array of the dimension sizes
	//use for loops to copy values of e to f and g inside the function
	//in main print out e, f and g 0
 //in main free the memory for f
 //in main free the memory for g
 
 f=(int**) malloc(sizeof(int*)*4);
 for(int i=0;i<4;i++)
  f[i]=(int*) malloc(sizeof(int)*3);
  
 g=(int**) malloc(sizeof(int*)*4);
 g[0]=malloc(12*sizeof(int));
 for(int i=1;i<4;i++)
  g[i]=g[i-1]+3;
 
 sizes[0]=4;
 sizes[1]=3;
 
 arrayCopy(e,f,g,sizes);
 for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			printf("%d %d %d\n",e[i][j],f[i][j],g[i][j]);
		}
	}	
 for(int i=0;i<4;i++)
  free(f[i]);
 free(f);
 f=0;
 
 free(g[0]);
 free(g);
 g=0;
	return 1;
}

