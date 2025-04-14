#include <stdio.h>
#include <string.h>

void parser(char*string){
    int in=0;
    int index=0;
    for(int i=0;i<strlen(string);i++){
       if(string[i]=='<') {
            in=1;
            continue;
       }
       else if(string[i]=='>'){
            in=0;
            continue;
       }
       if(in==0){
            string[index]=string[i];
            index++;
       }
    }
    string[index]='\0';     //to remove spaces at start

    //shifting the string to left
    while(string[0]==' '){
        for(int i=0;i<strlen(string);i++){
            string[i]=string[i+1];
        }
    }

    //to remove spaces from end
    while(string[strlen(string)-1]==' '){
        string[strlen(string)-1]='\0';
    }
}

int main() {
    //char string[]="  <h1> This is a car   </h1>";
    char string[100];
    fgets(string, sizeof(string), stdin);
    parser(string);
    printf("The parsed string is:\n");
    printf("%s",&string);
    return 0;
}
