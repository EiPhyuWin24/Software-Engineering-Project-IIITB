#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;
    int delete_line, temp = 1; 
    FILE *fileptr2;
    while(1)
    {
        printf("Choose an option\n");
        printf("Option 1 Add\n");
        printf("Option 2 Display\n");
	printf("Option 3 Delete\n");
        printf("Press 0 to exit\n");
        int option;
        scanf("%d",&option);
        printf("%d\n",option);

        if(option == 1)
        {
            fp = fopen("database.txt","a");
            printf("Give name,rank, address, phone and salary:\n");
	    char name[20]; 
	    char rank[20];
	    char address[20];
	    char phone[15];
	    char salary[20];
	    printf("Enter name,rank, address, phone and salary:");
            scanf("%s %s %s %s %s", name,rank, address,phone, salary);
            printf("%s %s %s %s %s\n",name,rank, address,phone, salary);
            fprintf(fp, "%s %s  %s %s %s\n", name,rank, address,phone, salary);

	    fclose(fp);
        }

        if(option == 0)
        {
            break;
        }

        
	if(option == 2)
        {
          char c;
          fp = fopen("database.txt","r");
          c = fgetc(fp);
          while (c != EOF)
          {
              printf ("%c", c);
              c = fgetc(fp);
          }
          fclose(fp);
        }

	if(option == 3)
       {
        //fp = fopen("database.txt","r");
	//FILE *fileptr1,
    	char filename[40];
    	printf("Enter file name: ");
    	scanf("%s", filename);
        //open file in read mode
        fp = fopen(filename, "r");
    ch = getc(fp);
   while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(fp);
    }
    //rewind
    rewind(fp);
    printf("\nEnter line number of the line to be deleted:");
    scanf("%d", &delete_line);
    //open new file in write mode
    fileptr2 = fopen("replica.c", "w");
    ch = 'A';
    while (ch != EOF)
    {
        ch = getc(fp);
        //except the line to be deleted
        if (temp != delete_line)
        {
            //copy all lines in file replica.c
            putc(ch, fileptr2);
        }
        if (ch == '\n')
        {
            temp++;
        }
    }
    fclose(fp);
    fclose(fileptr2);
    remove(filename);
    //rename the file replica.c to original name
    rename("replica.c", filename);
    printf("\nThe contents of file after being modified are as follows:\n");
    fp = fopen(filename, "r");
    ch = getc(fp);
    while (ch != EOF)
    	{
        	printf("%c", ch);
        	ch = getc(fp);
    	}
      fclose(fp);
    
   }
}
    return 0;
}
