#include "dist.h"
#include  <time.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <string.h>
//#include <mpi.h>






 void helpHS(dmat_type &gm,dmati_type &HS){ //make Har vector
 unsigned long long int titaar[33];
int i,j,s,a,t;
for(i=1;i<33;i++){
	titaar[i]=tital(gm.q,i);}


for(int P=1;P<=gm.n;P++){
	i=0;
    j=gm.m;
    s=0;

    while(j>0){
	   if(0==s){
		   if(0!=gm.a[j][P]){
			   t=INV[gm.a[j][P]];
			   s=titaar[i+1];
		       }
	         }
		   else{
			   a=MUL[t][gm.a[j][P]];
			   s=a*titaar[i]+s;
		 }//end if(0==s)
	    i=i+1;
		j=j-1;
	   }//end while(j>0)
	HS.a[s][1]++;
   }

 }









void readmatfrom_specHS(char str[],char st3[])
{  dmat_type dgenmatv;
   dmati_type HS,temp;
   dgenmatv.mem=0;
    HS.mem=0;
	temp.mem=0;
	infsettv.mem=0;
    //beginprogram();

   clock_t begin, end;
   double time_spent;
   FILE *fpr,*res;
   fpr=fopen(str, "r");

   res=fopen(st3, "w");
   char c=1;
   int num=0;
   while (!(feof(fpr)))
       {
        c=getc(fpr);
        if (c=='?')
         {num++;
          dreadgmatv( fpr,dgenmatv);
		  begin = clock();
		  infset_new(infsettv,dgenmatv.m,dgenmatv.n,0);
		  HS.m=tital(dgenmatv.q,dgenmatv.k);
          HS.q=dgenmatv.q;
          dmati_new(HS, HS.m,HS.q-1,HS.q);
		  HS.k=dgenmatv.k;
		   for(int i=1;i<=HS.m;i++)
           for(int j=0;j<=HS.n;j++)
	       HS.a[i][j]= 0;
           dmati_new(temp,HS.q,HS.q-1,HS.q);
	       //begin = clock();
		   helpHS(dgenmatv,HS);//EEE
           main_HS(HS,temp); //EEE
	      //speccalc(dgenmatv);
		    writedmatof(res,dgenmatv,dgenmatv.k,num,1);
          end = clock();
          time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
          fprintf(res,"\n Time =  %10.3f seconds",(double)  time_spent);

          writespecofh(res);
          if(0==num%100)
            { printf("NUM %d",num);printf("\n");
             printf("  MD %d  br %lld \n",infsettv.d, infsettv.numcount);
             }
          }
        }
	int i= fclose(fpr);
	    i= fclose(res);

	dmat_free(dgenmatv);
	dmati_free(HS);
	dmati_free(temp);

}




void helpHS_walsh1(dmat_type &gm,dmati_type &HS){ //make har vector+bin
if((2==HS.q)||(4==HS.q)){
	unsigned long long posh;
	for(int P=1;P<=gm.n;P++)
	{posh=0;
	for(int i=1;i<=gm.m;i++){
		if(1==gm.a[i][P]){
		posh=posh |(eee <<(i-1)); }
	}
	//posh=10;
		HS.a[0][posh]++;}

	return;

	}


 unsigned long long int titaar[33];
long long int i,j,s,a,t;
for(i=1;i<33;i++){
	titaar[i]=tital(gm.q,i);}


for(long long int P=1;P<=gm.n;P++){
	i=0;
    j=gm.m;
    s=0;

    while(j>0){
	   if(0==s){
		   if(0!=gm.a[j][P]){
			   t=INV[gm.a[j][P]];
			   s=titaar[i+1];
		       }
	         }
		   else{
			   a=MUL[t][gm.a[j][P]];
			   s=a*titaar[i]+s;
		 }//end if(0==s)
	    i=i+1;
		j=j-1;
	   }//end while(j>0)
	{
		HS.a[s][1]++;}
   }

 }


void readmatfrom_specHS_walsh1(char str[],char st3[])
{  dmat_type dgenmatv,dgenmatvh;//generator matrix
   dmati_type HS,temp;
   dgenmatv.mem=0;
   dgenmatvh.mem=0;
   HS.mem=0;
   temp.mem=0;
   infsettv.mem=0;
   //beginprogram();
   int ff=sizeof(short int);
   int ff1=sizeof(int)     ;
   clock_t begin, end;
   double time_spent;
   FILE *fpr,*res;
   fpr=fopen(str, "r");
   res=fopen(st3, "w");
   char c=1;
   int num=0;
   while (!(feof(fpr)))
       {
        c=getc(fpr);
        if (c=='?')
         {num++;
          dreadgmatv( fpr,dgenmatv);
		  begin = clock();
		  if(4!=dgenmatv.q){
			  HS.m=tital(dgenmatv.q,dgenmatv.k);
			  infset_new(infsettv,dgenmatv.m,dgenmatv.n,0);}
		  else{
			  dmat_new(dgenmatvh,dgenmatv.m*2,dgenmatv.n*3,dgenmatv.q);
			  HS.m=tital(2,dgenmatv.k*2);
			  infset_new(infsettv,dgenmatv.m,dgenmatv.n*3,0);}
		  
		  
		 		  
          HS.q=dgenmatv.q;
		  if((2==HS.q)||(4==HS.q)){
			 dmati_new(HS, 0,HS.m,HS.q);
			 HS.k=dgenmatv.k;
		   }
		  else{
			  dmati_new(HS, HS.m,HS.q-1,HS.q);
			  HS.k=dgenmatv.k;
			  dmati_new(temp,HS.q,HS.q-1,HS.q);
		      }

		  for(int i=0;i<=HS.m;i++)
           for(int j=0;j<=HS.n;j++)
	       HS.a[i][j]= 0;
		   
		    if(4==HS.q){
				 HS.k=dgenmatv.k*2;
              for(int ii=1;ii<=3;ii++){
             for(int i=1;i<=dgenmatv.m;i++)
				 for(int j=1;j<=dgenmatv.n;j++){
				  dgenmatvh.a[i][dgenmatv.n*(ii-1)+j]=TRE[MUL[dgenmatv.a[i][j]][ii]];
				 }}
             int tt=0;
              for(int ii=2;ii<=4;ii++){
				  int jj=(ii % 3)+1;
				  tt++;
             for(int i=1;i<=dgenmatv.m;i++)
				 for(int j=1;j<=dgenmatv.n;j++){
				  dgenmatvh.a[i+dgenmatv.m][dgenmatv.n*(tt-1)+j]=TRE[MUL[dgenmatv.a[i][j]][jj]];
				 }
			    dgenmatvh.n=dgenmatv.n*3;
                dgenmatvh.m=dgenmatv.m*2;
			    dgenmatvh.k=dgenmatv.m*2;
				
			  }

			 /* int ttr[64];
	                 for ( int g = 0; g < 64; g++){
	                  ttr[g]=HS.a[0][g];}*/

			   helpHS_walsh1(dgenmatvh,HS);
			
			}
			else{	       
		        helpHS_walsh1(dgenmatv,HS);//EEE
			}


         main_HS_walsh1(HS,temp); //EEE
	      //speccalc(dgenmatv);
		   writedmatof(res,dgenmatv,dgenmatv.k,num,1);
		   // writedmatof(res,dgenmatvh,dgenmatvh.k,num,1);
          end = clock();
          time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
          fprintf(res,"\n Time =  %10.3f seconds",(double)  time_spent);

          writespecofh(res);
          if(0==num%100)
            { printf("NUM %d",num);printf("\n");
             printf("  MD %d  br %lld \n",infsettv.d, infsettv.numcount);
             }
          }
        }
	int i= fclose(fpr);
	    i= fclose(res);

	dmat_free(dgenmatv);
	dmat_free(dgenmatvh);
	dmati_free(HS);
	dmati_free(temp);

}


void main_menu_weights(){
	strcpy(dirName,"");
	int n1=40,k1=20,q1=2,num1=30;
	char st[300],st3[300]="",sth[300]="EXAM.txt";

	strcpy(st,dirName);
    strcat(st,sth);
	strcpy(st3,st);
	strcat(st3,"_r");
	int choose=0;
	do{
	do{
	printf("\n");
	printf("\n");
	printf("  QextNewEdition- WDHV (Weight Distribution by Characteristic Vector) v 0.1 ");
	printf("\n");
	printf("\n");
	printf("\n by Iliya Bouyukliev");
	printf("\n");
	 #if 0== BIGL
	printf("\n Computing the weight distribution of [n, k] linear codes over Fq (q<8)  ");
	printf("\n  and  n<2^15 (for q=4 n<2^13)");
	 #endif
	 #if 1== BIGL
	printf("\n Computing the weight distribution of [n, k] linear codes over Fq (q<8)  ");
	printf("\n and  n<2^31 (for q=4 n<2^29)");
	 #endif
	printf("\n");
	printf("\n");
	printf("\n Input file: %s   Output file: %s",st,st3);
	printf("\n");
	printf("\n");
	printf("    1. Start computation \n");
	//printf("    2. Spec. count \n");
	printf("    2. Change Input file\n");
	printf("    3. Generate random codes in the file 'EXAM.txt' \n");
	printf("    4. Exit \n");
	printf("    Choose:");
	scanf("%d",&choose);
	}while (choose<1);
	switch ( choose )
       {

	   case 1:
               printf ( " Computation ...");
			   readmatfrom_specHS_walsh1(st,st3);
               break;
       case 33:
               printf ( " SPEC  ");
			   readmatfrom_specHS(st,st3);
               break;
	   case 2:
		   bool ok;
		   do{
		   printf(" Enter input file name ");
		   //st="";
		   //scanf(" %s", sth);
		   getstring(sth);
		   strcpy(st, dirName);
		   strcat(st, sth);
		   strcpy(st3, st);
		   strcat(st3, "_r");
		   FILE *infile = fopen(st, "r");
	        if(infile == NULL) {
		         perror("Error while opening file.\n");
		         ok=false;

			}
			 else {ok=true;
			 fclose(infile);}
		   }
		  while(false==ok);
		   break;

       case 3:
		    
               printf ( " Enter n k q number: ");
			   scanf(" %d %d %d %d",&n1,&k1,&q1,&num1);
               randomgenf(st,n1,k1,q1,num1); // Triabva da e st3
			   break;
       case 4:
               return;

       default :
               printf ( "Choose someting");
               break;
        }
	}
while(true);

}///////////////*
