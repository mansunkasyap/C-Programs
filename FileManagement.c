//
//  main.c
//  CRUD_With_File
//
//  Created by Ayush kanyal on 20/07/24.
//

// only works for absolute path


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
char * getPath(FILE *);

enum {MY_FILE_SIZE = 40};

int createFile(char * fileName)
{
    FILE * file = fopen(fileName, "w");
    if(file == NULL)
        return 0;
    char *ptr;
    printf("----------------------\n");
    ptr = getPath(file);
    printf("Path of file: \n");
    printf("%s", ptr);
    printf("----------------------\n");
    char defaultString[] = "#bin/bash\n";
    fputs(defaultString, file);
    fflush(stdin);
    fclose(file);
    return 1;
}

int createFile_with_path(char arr[])
{
    FILE *file = fopen(arr, "r"); // Example of an absolute path
    if (file == NULL)
    {
        return 0;
    }
    char *ptr;
    char c;
    printf("File content:\n");
    while ((c = getc(file)) != EOF)
    {
        printf("%c", c);  // Print character directly
    }
    printf("----------------------\n");
    ptr = getPath(file);
    printf("Path of file: \n");
    printf("%s", ptr);
    printf("----------------------\n");
//    char defaultString[] = "#bin/bash\n";
//    fputs(defaultString, file);
//    fflush(stdin);
    fclose(file);
    return 1;
}
void readFrom(char* fileName)
{
    FILE * file = fopen(fileName, "r");
    if(file == NULL)
    {
        printf("FILE NOT FOUND !!!\n");
    }
    else
    {
        char c;
        printf("File content:\n");
        while ((c = getc(file)) != EOF)
        {
            printf("%c", c);  // Print character directly
        }
        printf("\n----------------------\n");
        char *ptr = getPath(file);
        printf("Path of file: \n");
        printf("%s\n", ptr);
        printf("----------------------\n");
    }
    fclose(file);
}


void appendTo(char * fileName)
{
    char temp[100];
    
    FILE * file = fopen(fileName, "a");
    if(file == NULL)
    {
        printf("FILE NOT FOUND !!!");
    }else
    {
        printf("Enter content to write in file\n");
        fgets(temp, 100, stdin);
        fflush(stdin);
        fputs(temp, file);
    }
    fclose(file);
}
char * getPath(FILE * open)
{
    int fno = fileno(open);
    
    static char path[4096];
    if(fcntl(fno, F_GETPATH, path) == -1)
    {
        perror("Errrorrr....!!");
    }
    return path;
}

void renameFile(char * oldfileName, char * new_fileName)
{
//    char new_fileName[30];
    FILE * file = fopen(oldfileName, "a");
    if(file == NULL)
    {
        printf("FILE NOT FOUND..");
    }
    else{
        rename(oldfileName, new_fileName);
    }
    fclose(file);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int option ;
    char fileName[MY_FILE_SIZE];
    printf("\t__File Management__\n");
    printf("1. Create a file\n2. Read from file\n3. Update a file\n4. Delete a file\n");
    
    printf("Enter your option No. : ");
    scanf("%d", &option);
    fflush(stdin);
    
    switch (option) {
        case 1:
            printf("Enter file name with extension : ");
            fflush(stdin);
            fgets(fileName, MY_FILE_SIZE, stdin);
            fflush(stdin);
            if(createFile(fileName) == 1)
            {
                printf("File created successfully..");
            }else{
                printf("Something went wrong !!! ");
            }
            break;
        case 2:
            printf("Enter file name with extension : ");
            char file1[1000] = ("/Users/ayushkanyal/Documents/file3.txt");
//            fgets(file1, MY_FILE_SIZE, stdin);
//            fflush(stdin);
            readFrom(file1);
            break;
        
        case 3:
            printf("----UPDATE----\n");
            printf("1. For append Content\n2. For rename a file\n");
            int opt;
            scanf("%d", &opt);
            fflush(stdin);
            switch (opt) {
                case 1:
                    // append
                    printf("Enter file name with extension : ");
                    fgets(fileName, MY_FILE_SIZE, stdin);
                    fflush(stdout);
                    appendTo(fileName);
                    break;
                case 2:
                    //rename file
                    printf("Enter original file name with extension : ");
                    fgets(fileName, MY_FILE_SIZE, stdin);
                    fflush(stdout);
                    printf("Enter new file name with extension: ");
                    char new_fileName[30];
                    fgets(new_fileName, 30, stdin);
                    fflush(stdout);
                    renameFile(fileName, new_fileName);
                    break;
                default:
                    
                    break;
            }
            
            break;
            
        default:
            printf("INVALID OPTION ENTERED");
            break;
    }
    
    return 0;
}
