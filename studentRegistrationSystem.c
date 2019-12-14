#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct student{
    char ID[6];
    char name[20];
    char add[20];
    char fac[20];
    char depat[100];
    int phone_no;
};

struct student stu;
void add_student(){
    printf("Add Record \n");
    FILE *fp;
    fp = fopen("record.txt","ab+");
    
    if(fp == NULL){
       printf("Error in Opening file\nMake sure your file is not write protected","Warning");

    }else{
        fflush(stdin);
        printf("ID: ");gets(stu.ID);
        if(strlen(stu.ID)>=6){
        	printf("wrong id format !!! \n\n");
		}
		else{
        printf("Name: ");gets(stu.name);
        printf("Address: ");gets(stu.add);
        printf("Faculty: ");gets(stu.fac);
        printf("Department: ");gets(stu.depat);
        printf("Phone Number: ");scanf("%d",&stu.phone_no);
      fwrite(&stu, sizeof(stu), 1, fp);
		 printf("The record is sucessfully added \n");
     }
    }
    
    fclose(fp);
    return;
}

void search_student(){
    
    printf("Search Record \n");
    char s_id[15];
        int isFound = 0;
    printf("Enter ID to Search: ");
	fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp) == 1){
        if(strcmp(s_id,stu.ID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
	printf("\n************************************\n");
	printf("The record is Found! 		   *\n");
	printf("************************************\n");
	printf("*ID: %s \n",stu.ID);
	printf("*Name: %s \n",stu.name);
	printf("*Address: %s \n",stu.add);
	printf("*Faculty: %s \n",stu.fac);
	printf("*Department: %s \n",stu.depat);
	printf("*Phone No: %d \n",stu.phone_no);
	printf("************************************\n\n\n");
	
    }
	else{
	printf("Sory, No record found in the database \n");
    }
    
    fclose(fp);
    return;
}

void mod_student(){
    
    printf("Modify Record \n");
    
    char s_id[15];
    int isFound = 0;
  printf("Enter ID to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp;s
    fp = fopen("record.txt","rb+");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) == 0){
            fflush(stdin);
            printf("ID: ");gets(stu.ID);
            printf("Name: ");gets(stu.name);
            printf("Address: ");gets(stu.add);
     	    printf("Faculty: ");gets(stu.fac);
            printf("Department: ");gets(stu.depat);
            printf("Phone Number: ");scanf("%d",&stu.phone_no);
            fseek(fp,sizeof(stu), SEEK_CUR);
            fwrite(&stu,sizeof(stu), 1, fp);
            isFound = 1;
            break;
        }
    }
    if(!isFound){
     printf("\n\n\n No Record Found \n\n\n");
    }
    fclose(fp);
    
    return;
}

void delete_student(){
   
    printf("Delete Record \n");
    char s_id[15];
    int isFound = 0;
    printf("Enter ID to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp, *temp;
    fp = fopen("record.txt","rb");
    temp = fopen("temp.txt", "wb");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) == 0){
            fwrite(&stu,sizeof(stu),1,temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("record.txt");
    rename("temp.txt","record.txt");
	printf("\n\nThe record is sucessfully deleted \n\n\n");
    return;
}

void display_data(){
    FILE *fp;
    fp = fopen("record.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp) == 1){
      
	printf("************************************\n");
	printf("*ID: %s \n",stu.ID);
	printf("*Name: %s \n",stu.name);
	printf("*Address: %s \n",stu.add);
	printf("*Faculty: %s \n",stu.fac);
	printf("*Department: %s \n",stu.depat);
	printf("*Phone No: %d \n",stu.phone_no);
	printf("************************************\n\n\n");

}
printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tEnd of file\n");

    fclose (fp);
//    return;
}

int main() {
	    char choice;
    

    while(1){
        printf("1. Add Student \n");
        printf("2. Search Student \n");
        printf("3. Modify Student Record \n");
        printf("4. Delete Student Record \n");
        printf("5. Display all records \n");
        printf("6. Exit \n");
        printf("Enter your choice: ");
        scanf("%c",&choice);
        switch(choice){
        	case '1':
                add_student();
                break;
            case '2':
                search_student();
                break;
            case '3':
                mod_student();
                break;
            case '4':
                delete_student();
                break;
            case '5':
                display_data();
                break;
	       case '6':
                exit(0);
                break;
            default:         	
            	printf("\n wrong input please try again \n");
                break;
        }

    }
return 0;
}


