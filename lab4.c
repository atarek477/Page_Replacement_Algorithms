#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//#include <conio.h>
//#include <windows.h>
//int r=0;
int c;
int seqpage[5000];
int **mult;
int handlerr = 0, m, n, s;
int j;
int rep =0;
int test=1;
int i,j;
 int min_index(int *a, int n)
    {
        if(n <= 0) return -1;
        int i, min_i = 0;
        int min = a[0];
        for(i = 1; i < n; ++i){
            if(a[i] < min){
                min = a[i];
                min_i = i;
            }
        }
        return min_i;
    }

    int max_index(int *a, int n)
    {
        if(n <= 0) return -1;
        int i, max_i = 0;
        int max = a[0];
        for(i = 1; i < n; ++i){
            if(a[i] > max){
                max = a[i];
                max_i = i;
            }
        }
        return max_i;
    }






void OPTIMAL()
{
    int i=0;
    int r=0;
    int val=0;
    int checkfault=0;
    while(seqpage[i-1]!=-1)
    {
       // printf("enter seq of page :\n");
        scanf("%d",&seqpage[i]);
        r++;
        i++;
    }
    r=r-1;
    int fr[c];


    printf("Replacement Policy = OPTIMAL\n");
    printf("-------------------------------------\n");
	printf("Page   Content of Frames\n");
	printf("----   -----------------\n");
    int j=0;
    int k;
    int check1;
    int pagefault=0;
    int flag=0;
    int flag1[c];
	for(i=0;i<c;i++)
    fr[i]=-1;
	for(i=0;i<r;i++){
		check1=0;
		for(k=0;k<c;k++){
	 		if(fr[k]==seqpage[i])
				check1=1;
		}
	if(check1==0){
		if(fr[j]==-1){
			flag=1;
		fr[j]=seqpage[i];
		j++;
		if(j==c)
            j=0;
		}
	 	//j=(j+1)%c;
	else
     {
         for(int n=0 ;n<c;n++){
            for(int m=i ;m<r;m++){
                    val++;
                if(fr[n]==seqpage[m])
                    break;




            }
 //  printf("\n val:%d\n",val);
  flag1[n]=val;
  val=0;
         }
         /*for(int n=0 ;n<c;n++){
            printf("\n %d\n",flag1[n]);
         }*/

j=max_index(flag1,c);
         fr[j]=seqpage[i];
         }


		if(flag==0){
	 		pagefault++;

		}
	}
	if(checkfault<pagefault){
		printf("%02d F   ",seqpage[i]);
		checkfault=pagefault;
	}
	else
		printf("%02d     ",seqpage[i]);
	for(k=0;k<c;k++){
		if(fr[k]!=-1)
			printf("%02d ",fr[k]);
	}
	printf("\n");
	flag=0;

	}
	printf("-------------------------------------\n");
	printf("Number of page faults = %d\n",pagefault);
}
void LRU()
{
int i=0;
    int r=0;
    int checkfault=0;
    while(seqpage[i-1]!=-1)
    {
       // printf("enter seq of page :\n");
        scanf("%d",&seqpage[i]);
        r++;
        i++;
    }
    r=r-1;
    int fr[c];


     printf("Replacement Policy = LRU\n");
    printf("-------------------------------------\n");
	printf("Page   Content of Frames\n");
	printf("----   -----------------\n");
    int j=0;
    int val=0;
    int k;
    int flag2[c];
    int check1;
    int pagefault=0;
    int flag=0;
	for(i=0;i<c;i++)
    fr[i]=-1;
	for(i=0;i<r;i++){
		check1=0;
		for(k=0;k<c;k++){
	 		if(fr[k]==seqpage[i])
				check1=1;
		}
	if(check1==0){
		if(fr[j]==-1){
			flag=1;
		fr[j]=seqpage[i];
	 	j++;
		if(j==c)
            j=0;
	 	}
	 else{

        for(int n=0;n<c;n++)
        {
            for(int m=i;m>=0;m--)
            {
                val++;
                if(fr[n]==seqpage[m])
                    break;
            }
            flag2[n]=val;
            val=0;
        }
     /*   for(int n=0 ;n<c;n++){
            printf("\n %d\n",flag2[n]);
         }*/
        j=max_index(flag2,c);
        fr[j]=seqpage[i];

	 }
		if(flag==0){
	 		pagefault++;

		}
	}
	if(checkfault<pagefault){
		printf("%02d F   ",seqpage[i]);
		checkfault=pagefault;
	}
	else
		printf("%02d     ",seqpage[i]);
	for(k=0;k<c;k++){
		if(fr[k]!=-1)
			printf("%02d ",fr[k]);
	}
	printf("\n");
	flag=0;

	}
	printf("-------------------------------------\n");
	printf("Number of page faults = %d\n",pagefault);
}

void FIFO()
{
    int i=0;
    int r=0;
    int checkfault=0;
    while(seqpage[i-1]!=-1)
    {
        //printf("enter seq of page :\n");
        scanf("%d",&seqpage[i]);
        r++;
        i++;
    }
    r=r-1;
    int fr[c];


    printf("Replacement Policy = FIFO\n");
    printf("-------------------------------------\n");
	printf("Page   Content of Frames\n");
	printf("----   -----------------\n");
    int j=0;
    int k;
    int check1;
    int pagefault=0;
    int flag=0;
	for(i=0;i<c;i++)
    fr[i]=-1;
	for(i=0;i<r;i++){
		check1=0;
		for(k=0;k<c;k++){
	 		if(fr[k]==seqpage[i])
				check1=1;
		}
	if(check1==0){
		if(fr[j]==-1)
			flag=1;
		fr[j]=seqpage[i];
	 	j=(j+1)%c;
		if(flag==0){
	 		pagefault++;

		}
	}
	if(checkfault<pagefault){
		printf("%02d F   ",seqpage[i]);
		checkfault=pagefault;
	}
	else
		printf("%02d     ",seqpage[i]);
	for(k=0;k<c;k++){
		if(fr[k]!=-1)
			printf("%02d ",fr[k]);
	}
	printf("\n");
	flag=0;

	}
	printf("-------------------------------------\n");
	printf("Number of page faults = %d\n",pagefault);
}



void CLOCK()
{
    int i=0;
    int r=0;
    int t=1;
    int checkfault=0;
    while(seqpage[i-1]!=-1)
    {
        //printf("enter seq of page :\n");
        scanf("%d",&seqpage[i]);
        r++;
        i++;
    }
    r=r-1;
    int fr[c];


    printf("Replacement Policy = CLOCK\n");
    printf("-------------------------------------\n");
	printf("Page   Content of Frames\n");
	printf("----   -----------------\n");
    int j=0;
    int k;
    int check1;
    int flag3[c];
    int pfault=0;
    int flag=0;
	for(i=0;i<c;i++)
    {fr[i]=-1;
    flag3[i]=0;
    }
	for(i=0;i<r;i++){
		check1=0;
		for(k=0;k<c;k++){
	 		if(fr[k]==seqpage[i]){
				check1=1;
				if(flag3[k]==0){
                    flag3[k]=1;
                    }
				}
		}
	if(check1==0){
		if(fr[j]==-1){
			flag=1;
		fr[j]=seqpage[i];
		flag3[j]=1;
	 	j++;
		if(j==c)
            j=0;
	 	}
	 	else{
            while(t)
            {
                if(flag3[j]==1)
                {
                    flag3[j]=0;
                    j++;
		          if(j==c)
                      j=0;

                }
                else{
                    fr[j]=seqpage[i];
                    flag3[j]=1;
                    j++;
		            if(j==c)
                    j=0;

                    break;
                }
            }

	 	}

		if(flag==0){
	 		pfault++;

		}
	}
	if(checkfault<pfault){
		printf("%02d F   ",seqpage[i]);
		checkfault=pfault;
	}
	else
		printf("%02d     ",seqpage[i]);
	for(k=0;k<c;k++){
		if(fr[k]!=-1)
			printf("%02d ",fr[k]);
	}
	printf("\n");
	flag=0;

	}
	printf("-------------------------------------\n");
	printf("Number of page faults = %d\n",pfault);


}


/*for(int i=0;i<50;i++)
{     printf("enter sequence of page :");
      scanf("%d \n"seqpage[i]);
      if(seqpage[i]==-1)
      {
        seqpage[i]='\0'
      }
      else{
            r++;

      }
}*/




int main()
{
    int run=1;
    char operation[10];
//int c;

    //while(run)
    
        //printf("Enter Number Of Frames: ");
        scanf("%d",&c);

        //printf("operation you can use:\n");
        //printf("1.OPTIMAL\n2.LRU\n3.FIFO\n4.CLOCK\n5.Quit\n");
        //printf("Enter Operation: ");
        scanf("%s",operation);
        if(strcasecmp(operation,"OPTIMAL")==0||strcmp(operation,"1")==0)
        {

            OPTIMAL();

        }
        else if(strcasecmp(operation,"LRU")==0||strcmp(operation,"2")==0)
        {

            LRU();

        }
        else if(strcasecmp(operation,"FIFO")==0||strcmp(operation,"3")==0)
        {

            FIFO();

        }
        else if(strcasecmp(operation,"CLOCK")==0||strcmp(operation,"4")==0)
        {

            CLOCK();

        }
       
        else
        {
            printf("Invalid operation please reenter\n");
            
        }

       // printf("Press any key to Continue\n");
        //getch();
        //system("cls");

        //printf("Operations you can use:\n");
        //printf("1.OPTIMAL\n2.LRU\n3.FIFO\n4.CLOCK\n5.Quit\n");

    

    return 0;
}