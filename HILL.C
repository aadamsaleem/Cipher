#include<stdio.h>
#include<string.h>
#include<math.h>

#define n 3

int main()
{
	int i,j,k,key,ch,msglen;
	char message[1000],encrypted[1000];
    int c[3];
	int mat[3][3]   =  { {17 , 17 , 5 },
	                     {21 , 18 , 21},
	                     {2  , 2  , 19}
                       };
	int matinv[3][3] = { {4  , 9  , 15},
	                     {15 , 17 , 6 },
	                     {24 , 0  , 17}
                       };

	FILE *p;
//	system("clear");

	printf("\n\t\tHill Cipher\n");
	while(1)
	{
		printf("\n1.Encrypt\n2.Decrypt\n3.Exit\nEnter your Choice : ");
//		fpurge(stdin);
        fflush(stdin);
		scanf("%d",&ch);
		if(ch==1)
		{ 
            printf("\nEnter the Message : ");

//			fpurge(stdin);
            fflush(stdin);
			fgets(message,1000,stdin);
			msglen=strlen(message);
			msglen--;
            while(msglen%n)
               message[msglen++]='x';

			p=fopen("out.txt","w");
			printf("\nThe Encrypted text is : ");
			
            for(i=0;i<msglen;i+=3)
            {
                for(j=0;j<n;j++)
                {
                    c[j]=0;
                    for(k=0;k<n;k++)
                    {
                        c[j]+=mat[j][k]*(message[i+k]-97);
                    }
                    c[j] %=26;
                    encrypted[i+j]=c[j]+97;
                    putchar(encrypted[i+j]);
                    fprintf(p,"%c",encrypted[i+j]);
                }
            }

			fclose(p);
		}	
		else if(ch==2)
		{
			p=fopen("out.txt","r");
			
//			fpurge(stdin);
            fflush(stdin);
			fgets(encrypted,1000,p);
			fclose(p);

			printf("\nEncrypted text  : ");
			puts(encrypted);
			msglen=strlen(encrypted);
			
			printf("\nThe Actual Message is :- ");
			for(i=0;i<msglen;i+=3)
            {
                for(j=0;j<n;j++)
                {
                    c[j]=0;
                    for(k=0;k<n;k++)
                    {
                        c[j]+=matinv[j][k]*(encrypted[i+k]-97);
                    }
                    c[j] %=26;
                    message[i+j]=c[j]+97;
                    putchar(message[i+j]);
                }
            }
		}
		else
			return 0;
	}
	return 0;
}
