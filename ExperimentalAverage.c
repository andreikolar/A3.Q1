#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char *argv[])
{
	FILE *file_ptr;
	char line[300];
	int z;
	for (z=0; z<300; z++){
		line[z]='\0';
	}

	file_ptr=fopen(argv[1], "rt");
	if (file_ptr == NULL){
		printf("Error\n");
		return;
	}

	int numElements,i;
	fgets(line,299,file_ptr);
	char name[60];
	for (z=0; z<60; z++){
		name[z]='\0';
	}
	char x;
	int size2;
	int size;
	int temp;
	while (!feof(file_ptr))
	{
		int i=0; 
		int y=0;
		x=line[0];
		size=strlen(line);
		while ((i <size) && (x !=',')){
			name[y]=x;
			i +=1;
			y +=1;
			x=line[i];
		}

		size2=strlen(name);
		for (i=0; i<size2; i++){
			printf("%c", name[i]);
			name[i]='\0';
		}
		printf(" ");
		
		i= size2 +1;
		int start=i;
		int difference;
		double data,average;
		int count=0;
		int lastSize;
		double sum=0.0;
		
		char temp[100];
		for (z=0; z<100; z++){
			temp[z]='\0';
		}
		while (i<=size){
			if (line[i]==',' || i==size){
				data=0.0;
				difference=i-start;
				for (z=0; z<difference; z++){
					temp[z]=line[start];
					start+=1;
				}
				
				lastSize=strlen(temp);
				
				sscanf(temp, "%lf", &data);
				sum +=data;
				count +=1;
				start=i+1;
			}
			i +=1;	
		}
		average=sum/count;
		printf("%.2f\n",average);
		fgets(line,299,file_ptr);
	}
	fclose(file_ptr);
}
