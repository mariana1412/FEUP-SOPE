#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_STUDENTS 10
#define MAX_NUM_LEN 15
#


//exercicio a
/*int main(int argc, char *argv[]){

    if (argc != 2) {
		printf("usage: %s <file_name>\n" , argv[0]);
		return 1;	
	}


    int f1 = open(argv[1], O_WRONLY|O_TRUNC);

	if(f1 == -1){
		printf("Failed to open file for writing!\n");
		return 2;
	}



	//Read student names and grades
	char names[MAX_NUM_STUDENTS][MAX_NAME_LEN];
	char grades[MAX_NUM_STUDENTS][MAX_NUM_LEN];

	printf("\nPlease enter %d students names and their respective grades:\n\n", MAX_NUM_STUDENTS);

	
	for(int i = 0; i < MAX_NUM_STUDENTS; i++){

		printf("Name: ");
		fgets(names[i], MAX_NAME_LEN, stdin);
		printf("Grade: ");
		fgets(grades[i], MAX_NUM_LEN, stdin);
		printf("------------------------------\n");
	}

	//Write names and grades 

	for(int i = 0; i < MAX_NUM_STUDENTS; i++){
		write(f1 , names[i] , strlen(names[i])-1);
		write(f1 , "  -  " , strlen("  -  "));
		write(f1 , grades[i] , strlen(grades[i])-1);
		write(f1 , "\n" , strlen("\n"));
	}

	close(f1);

	return 0;
}*/


//exercicio b


typedef struct Student{
	char name[MAX_NAME_LEN];
	int grade;
} Student;


int reading(){


	int f1 = open("ola.txt", O_RDONLY);

	if(f1 == -1){
		printf("Failed to open file for writing!\n");
		return 2;
	}


	Student s;

	while(read(f1, &s, sizeof(Student)) > 0){
		printf("Name: %s; Grade: %d\n", s.name, s.grade);
	}
	

	close(f1);

	return 0;
}



int main(int argc, char *argv[]){

    if (argc != 2) {
		printf("usage: %s <file_name>\n" , argv[0]);
		return 1;	
	}


    int f1 = open(argv[1], O_WRONLY|O_TRUNC);

	if(f1 == -1){
		printf("Failed to open file for writing!\n");
		return 2;
	}



	//Read student names and grades
	Student students[MAX_NUM_STUDENTS];

	printf("\nPlease enter %d students names and their respective grades:\n\n", MAX_NUM_STUDENTS);

	Student s;
	for(int i = 0; i < MAX_NUM_STUDENTS; i++){

		printf("Name: ");
		fgets(s.name, MAX_NAME_LEN, stdin);
		printf("Grade: ");
		scanf("%d", &s.grade);
		getchar(); //Ignore \n from input stream

		students[i] = s;

		printf("------------------------------\n");
	}

	//Write names and grades 

	for(int i = 0; i < MAX_NUM_STUDENTS; i++){
		write(f1, &students, sizeof(Student));
	}

	close(f1);

	reading();

	return 0;
}


