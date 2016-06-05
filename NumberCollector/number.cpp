#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    FILE *f1, *f2;
    char c;
    printf("Data \n\n");
    f1 = fopen("INPUT.txt","r");
    f2 = fopen("OTPUT.txt","w");
    bool i =false,j=false,k=false,l=false ,track_number =false;
    int digit =0;
    int total =0;

    while((c = getc(f1)) != EOF)
    {

        switch(c)
        {
            case 't' :
               i=true;
            break;
            case 'e' :
                 j=true;
                break;
            case 'l' :
                 k=true;
                break;
            case ':':
                l=true;
                break;
            default :
            if(i&j&k&l)
            {
               track_number=true;
                i=j=k=l=false;

            }
             i=j=k=l=false;
           break;
        }

         if(track_number)
            {

                 if(c=='\"')
                {
                    digit=11;
                }
                if(digit ==11)
                 {
                       digit =0; track_number=false;
                       printf("\n");
                        putc('\n',f2);
                       total++;
                 }
                 else{
                     printf("%c",c);
                     putc(c,f2);
                 }
                if(c=='+')
                {
                    digit--;
                }

                digit++;

            }


    }


    fclose(f1);
     fclose(f2);
     printf("\n\n%d",total);
    //string name ="Nazmul";
    //cout<<name;
}
