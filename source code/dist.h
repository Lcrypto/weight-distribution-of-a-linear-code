
#include "cons_str.h" ;






//===========================================================distance  HS=============================================

void Fprim(dmati_type &HS,int c,int d)
{
	// HS[begHs+tita+i+1]=F'(HS[begHS+titanext]);
    HS.a[c][0]=HS.a[c][0]+HS.a[d][1];
}

void copytempmat(dmati_type &HS,dmati_type &temp,int titav,int &i,int &begHS){
	int j,jh,r;
	for(j=0;j<HS.q;j++){
		jh=begHS+j*titav+i;
       for( r=0;r<HS.q;r++){
		 	temp.a[j+1][r]=HS.a[jh][r];
	   }
	}
}

//



	void Fbuterfly(dmati_type &HS,dmati_type &temp,int titav,int &i,int &begHS){
	int j,jh;
	for(j=0;j<HS.q;j++){
		jh=begHS+j*titav+i;
		if(2==HS.q)
		{ if (0==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][0];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][1];
		    }
		 if (1==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][1];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][0];
		    }
		}
		if(3==HS.q)
		{ if (0==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][0]+temp.a[3][0];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][1]+temp.a[3][1];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][2]+temp.a[3][2];
		    }
		 if (1==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][2]+temp.a[3][1];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][0]+temp.a[3][2];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][1]+temp.a[3][0];
		    }
		  if (2==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][1]+temp.a[3][2];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][2]+temp.a[3][0];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][0]+temp.a[3][1];
		    }
		}
		//=====================================================================
		if(5==HS.q)
		{ if (0==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][0]+temp.a[3][0]+temp.a[4][0]+temp.a[5][0];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][1]+temp.a[3][1]+temp.a[4][1]+temp.a[5][1];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][2]+temp.a[3][2]+temp.a[4][2]+temp.a[5][2];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][3]+temp.a[3][3]+temp.a[4][3]+temp.a[5][3];
		    HS.a[jh][4]=temp.a[1][4]+temp.a[2][4]+temp.a[3][4]+temp.a[4][4]+temp.a[5][4];
		    }
		 if (1==j){
            HS.a[jh][0]=temp.a[1][0]+temp.a[2][4]+temp.a[3][3]+temp.a[4][2]+temp.a[5][1];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][0]+temp.a[3][4]+temp.a[4][3]+temp.a[5][2];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][1]+temp.a[3][0]+temp.a[4][4]+temp.a[5][3];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][2]+temp.a[3][1]+temp.a[4][0]+temp.a[5][4];
		    HS.a[jh][4]=temp.a[1][4]+temp.a[2][3]+temp.a[3][2]+temp.a[4][1]+temp.a[5][0];


		    }
		  if (2==j){
			 HS.a[jh][0]=temp.a[1][0]+temp.a[2][3]+temp.a[3][1]+temp.a[4][4]+temp.a[5][2];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][4]+temp.a[3][2]+temp.a[4][0]+temp.a[5][3];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][0]+temp.a[3][3]+temp.a[4][1]+temp.a[5][4];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][1]+temp.a[3][4]+temp.a[4][2]+temp.a[5][0];
		    HS.a[jh][4]=temp.a[1][4]+temp.a[2][2]+temp.a[3][0]+temp.a[4][3]+temp.a[5][1];

		    }
		  if (3==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][2]+temp.a[3][4]+temp.a[4][1]+temp.a[5][3];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][3]+temp.a[3][0]+temp.a[4][2]+temp.a[5][4];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][4]+temp.a[3][1]+temp.a[4][3]+temp.a[5][0];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][0]+temp.a[3][2]+temp.a[4][4]+temp.a[5][1];
		    HS.a[jh][4]=temp.a[1][4]+temp.a[2][1]+temp.a[3][3]+temp.a[4][0]+temp.a[5][2];
		    }



		  if (4==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][1]+temp.a[3][2]+temp.a[4][3]+temp.a[5][4];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][2]+temp.a[3][3]+temp.a[4][4]+temp.a[5][0];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][3]+temp.a[3][4]+temp.a[4][0]+temp.a[5][1];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][4]+temp.a[3][0]+temp.a[4][1]+temp.a[5][2];
		    HS.a[jh][4]=temp.a[1][4]+temp.a[2][0]+temp.a[3][1]+temp.a[4][2]+temp.a[5][3];
		    }
		}
	//============================================================================================
		if(4==HS.q)
		{ if (0==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][0]+temp.a[3][0]+temp.a[4][0];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][1]+temp.a[3][1]+temp.a[4][1];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][2]+temp.a[3][2]+temp.a[4][2];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][3]+temp.a[3][3]+temp.a[4][3];
		    }
		if (1==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][1]+temp.a[3][2]+temp.a[4][3];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][0]+temp.a[3][3]+temp.a[4][2];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][3]+temp.a[3][0]+temp.a[4][1];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][2]+temp.a[3][1]+temp.a[4][0];
		    }
		if (2==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][2]+temp.a[3][3]+temp.a[4][1];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][3]+temp.a[3][2]+temp.a[4][0];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][0]+temp.a[3][1]+temp.a[4][3];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][1]+temp.a[3][0]+temp.a[4][2];
		    }
		if (3==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][3]+temp.a[3][1]+temp.a[4][2];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][2]+temp.a[3][0]+temp.a[4][3];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][1]+temp.a[3][3]+temp.a[4][0];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][0]+temp.a[3][2]+temp.a[4][1];
		    }

		}

    //================================================================================================
		if(7==HS.q)
		{ if (0==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][0]+temp.a[3][0]+temp.a[4][0]+temp.a[5][0]+temp.a[6][0]+temp.a[7][0];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][1]+temp.a[3][1]+temp.a[4][1]+temp.a[5][1]+temp.a[6][1]+temp.a[7][1];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][2]+temp.a[3][2]+temp.a[4][2]+temp.a[5][2]+temp.a[6][2]+temp.a[7][2];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][3]+temp.a[3][3]+temp.a[4][3]+temp.a[5][3]+temp.a[6][3]+temp.a[7][3];
		    HS.a[jh][4]=temp.a[1][4]+temp.a[2][4]+temp.a[3][4]+temp.a[4][4]+temp.a[5][4]+temp.a[6][4]+temp.a[7][4];
			HS.a[jh][5]=temp.a[1][5]+temp.a[2][5]+temp.a[3][5]+temp.a[4][5]+temp.a[5][5]+temp.a[6][5]+temp.a[7][5];
		    HS.a[jh][6]=temp.a[1][6]+temp.a[2][6]+temp.a[3][6]+temp.a[4][6]+temp.a[5][6]+temp.a[6][6]+temp.a[7][6];
		    }
		if (1==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][6]+temp.a[3][5]+temp.a[4][4]+temp.a[5][3]+temp.a[6][2]+temp.a[7][1];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][0]+temp.a[3][6]+temp.a[4][5]+temp.a[5][4]+temp.a[6][3]+temp.a[7][2];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][1]+temp.a[3][0]+temp.a[4][6]+temp.a[5][5]+temp.a[6][4]+temp.a[7][3];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][2]+temp.a[3][1]+temp.a[4][0]+temp.a[5][6]+temp.a[6][5]+temp.a[7][4];
		    HS.a[jh][4]=temp.a[1][4]+temp.a[2][3]+temp.a[3][2]+temp.a[4][1]+temp.a[5][0]+temp.a[6][6]+temp.a[7][5];
			HS.a[jh][5]=temp.a[1][5]+temp.a[2][4]+temp.a[3][3]+temp.a[4][2]+temp.a[5][1]+temp.a[6][0]+temp.a[7][6];
		    HS.a[jh][6]=temp.a[1][6]+temp.a[2][5]+temp.a[3][4]+temp.a[4][3]+temp.a[5][2]+temp.a[6][1]+temp.a[7][0];
		    }
		if (2==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][5]+temp.a[3][3]+temp.a[4][1]+temp.a[5][6]+temp.a[6][4]+temp.a[7][2];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][6]+temp.a[3][4]+temp.a[4][2]+temp.a[5][0]+temp.a[6][5]+temp.a[7][3];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][0]+temp.a[3][5]+temp.a[4][3]+temp.a[5][1]+temp.a[6][6]+temp.a[7][4];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][1]+temp.a[3][6]+temp.a[4][4]+temp.a[5][2]+temp.a[6][0]+temp.a[7][5];
		    HS.a[jh][4]=temp.a[1][4]+temp.a[2][2]+temp.a[3][0]+temp.a[4][5]+temp.a[5][3]+temp.a[6][1]+temp.a[7][6];
			HS.a[jh][5]=temp.a[1][5]+temp.a[2][3]+temp.a[3][1]+temp.a[4][6]+temp.a[5][4]+temp.a[6][2]+temp.a[7][0];
		    HS.a[jh][6]=temp.a[1][6]+temp.a[2][4]+temp.a[3][2]+temp.a[4][0]+temp.a[5][5]+temp.a[6][3]+temp.a[7][1];
		    }
		if (3==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][4]+temp.a[3][1]+temp.a[4][5]+temp.a[5][2]+temp.a[6][6]+temp.a[7][3];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][5]+temp.a[3][2]+temp.a[4][6]+temp.a[5][3]+temp.a[6][0]+temp.a[7][4];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][6]+temp.a[3][3]+temp.a[4][0]+temp.a[5][4]+temp.a[6][1]+temp.a[7][5];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][0]+temp.a[3][4]+temp.a[4][1]+temp.a[5][5]+temp.a[6][2]+temp.a[7][6];
		    HS.a[jh][4]=temp.a[1][4]+temp.a[2][1]+temp.a[3][5]+temp.a[4][2]+temp.a[5][6]+temp.a[6][3]+temp.a[7][0];
			HS.a[jh][5]=temp.a[1][5]+temp.a[2][2]+temp.a[3][6]+temp.a[4][3]+temp.a[5][0]+temp.a[6][4]+temp.a[7][1];
		    HS.a[jh][6]=temp.a[1][6]+temp.a[2][3]+temp.a[3][0]+temp.a[4][4]+temp.a[5][1]+temp.a[6][5]+temp.a[7][2];
		    }
		if (4==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][3]+temp.a[3][6]+temp.a[4][2]+temp.a[5][5]+temp.a[6][1]+temp.a[7][4];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][4]+temp.a[3][0]+temp.a[4][3]+temp.a[5][6]+temp.a[6][2]+temp.a[7][5];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][5]+temp.a[3][1]+temp.a[4][4]+temp.a[5][0]+temp.a[6][3]+temp.a[7][6];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][6]+temp.a[3][2]+temp.a[4][5]+temp.a[5][1]+temp.a[6][4]+temp.a[7][0];
		    HS.a[jh][4]=temp.a[1][4]+temp.a[2][0]+temp.a[3][3]+temp.a[4][6]+temp.a[5][2]+temp.a[6][5]+temp.a[7][1];
			HS.a[jh][5]=temp.a[1][5]+temp.a[2][1]+temp.a[3][4]+temp.a[4][0]+temp.a[5][3]+temp.a[6][6]+temp.a[7][2];
		    HS.a[jh][6]=temp.a[1][6]+temp.a[2][2]+temp.a[3][5]+temp.a[4][1]+temp.a[5][4]+temp.a[6][0]+temp.a[7][3];
		    }
		if (5==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][2]+temp.a[3][4]+temp.a[4][6]+temp.a[5][1]+temp.a[6][3]+temp.a[7][5];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][3]+temp.a[3][5]+temp.a[4][0]+temp.a[5][2]+temp.a[6][4]+temp.a[7][6];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][4]+temp.a[3][6]+temp.a[4][1]+temp.a[5][3]+temp.a[6][5]+temp.a[7][0];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][5]+temp.a[3][0]+temp.a[4][2]+temp.a[5][4]+temp.a[6][6]+temp.a[7][1];
		    HS.a[jh][4]=temp.a[1][4]+temp.a[2][6]+temp.a[3][1]+temp.a[4][3]+temp.a[5][5]+temp.a[6][0]+temp.a[7][2];
			HS.a[jh][5]=temp.a[1][5]+temp.a[2][0]+temp.a[3][2]+temp.a[4][4]+temp.a[5][6]+temp.a[6][1]+temp.a[7][3];
		    HS.a[jh][6]=temp.a[1][6]+temp.a[2][1]+temp.a[3][3]+temp.a[4][5]+temp.a[5][0]+temp.a[6][2]+temp.a[7][4];
		    }
		if (6==j){
			HS.a[jh][0]=temp.a[1][0]+temp.a[2][1]+temp.a[3][2]+temp.a[4][3]+temp.a[5][4]+temp.a[6][5]+temp.a[7][6];
		    HS.a[jh][1]=temp.a[1][1]+temp.a[2][2]+temp.a[3][3]+temp.a[4][4]+temp.a[5][5]+temp.a[6][6]+temp.a[7][0];
		    HS.a[jh][2]=temp.a[1][2]+temp.a[2][3]+temp.a[3][4]+temp.a[4][5]+temp.a[5][6]+temp.a[6][0]+temp.a[7][1];
			HS.a[jh][3]=temp.a[1][3]+temp.a[2][4]+temp.a[3][5]+temp.a[4][6]+temp.a[5][0]+temp.a[6][1]+temp.a[7][2];
		    HS.a[jh][4]=temp.a[1][4]+temp.a[2][5]+temp.a[3][6]+temp.a[4][0]+temp.a[5][1]+temp.a[6][2]+temp.a[7][3];
			HS.a[jh][5]=temp.a[1][5]+temp.a[2][6]+temp.a[3][0]+temp.a[4][1]+temp.a[5][2]+temp.a[6][3]+temp.a[7][4];
		    HS.a[jh][6]=temp.a[1][6]+temp.a[2][0]+temp.a[3][1]+temp.a[4][2]+temp.a[5][3]+temp.a[6][4]+temp.a[7][5];
		    }


		    }
		}

	}



 void Fsec(dmati_type &HS,dmati_type &temp,int r){
int i,j;
 for(i=0;i<HS.q;i++){
	 HS.a[r][i]=0;
	 for(j=0;j<HS.q;j++){
		  HS.a[r][i]= HS.a[r][i]+temp.a[i+1][j];
	 }
 }


 }

void New_HS_from_begHS_to_endHS(dmati_type &HS,dmati_type &temp,int begHS, int endHS,int tita,int titanext) {
//begin
/* Part 1 */
int i;
for(i=1;i<=tita;i++){//  begin
     Fprim(HS,begHS+tita+i,begHS+titanext);
}//end;


 for(i=1;i<=tita;i++){//  begin
	 /* Part 2 */
	 copytempmat(HS,temp,tita,i,begHS);
	 // HS[begHS+titanext]=F''(HS[begHs+0*tita+1],HS[begHs+1*tita+1],...,HS[begHs+(q-1)*tita+1]);
	  if(1==i) Fsec(HS,temp,begHS+titanext);
	 /* Part 3 */
	 // writedmati("RES",HS,HS.m,1);
	 Fbuterfly(HS,temp,tita,i,begHS);
	 // writedmati("RES",HS,HS.m,1);
 }
}
     /*TEMP:= (HS[begHs+0*tita+i],HS[begHs+1*tita+i],...,HS[begHs+(q-1)*tita+i]);

     HS[begHs+0*tita+i]=F1(TEMP);
     HS[begHs+1*tita+i]=F2(TEMP);
     ----------------------------
     HS[begHs+(q-1)*tita+i]=F(q-1)(TEMP);
  end


end;*/


void main_HS(dmati_type &HS,dmati_type &temp){
int a[30];
int titav,j,titanext,u,begHS,endHS,IND;
for(IND=2;IND<=HS.k;IND++){
   for(int j1=1;j1<=HS.k;j1++)a[j1]=0;

   titav=tital(HS.q,(IND-1));
   titanext=tital(HS.q,IND);
   u=0;

   while(u<HS.m){
        begHS=u;
        u=u+titanext;
        endHS=u;
		New_HS_from_begHS_to_endHS(HS,temp,begHS,endHS,titav,titanext);
		if(titanext>100000000000)
		printf("%lu\n",titanext);
		a[IND]=a[IND]+1;
        j=IND;
        while (a[j]==HS.q){
             u=u+1;
			 a[j]=0;
             j=j+1;
             a[j]=a[j]+1;
		}//end WHILE
   }//end WHILE
}//end for;
for(int i=0;i<=infsettv.n;i++)
	infsettv.Bspec[i]=0;
for(int i=1;i<=HS.m;i++)
	infsettv.Bspec[infsettv.n-HS.a[i][0]]++;

//for (int i=0;i<=infsettv.n;i++)
//		printf("  %d  ",HS.a[i][0]);
//printf("  \n");
//
//for (int i=0;i<=infsettv.n;i++)
//		printf("  %d  ",HS.a[i][1]);
//printf("  \n");


}//end;





//===================================================





unsigned long long  int eee=1;

 #if 0== BIGL
void fwtCPU1( short int *hV, unsigned long long  int l2N)
{
    const unsigned long long  int  N = eee << l2N;

    for (unsigned  long long  int  step = N / 2; step >= 1; step >>= eee)
    {
        for (unsigned  long long  int  from = 0; from < N; from += 2 * step)

            for (unsigned  long long  int  j = 0; j < step; j++)
            {
				/*int tt[63];
	                 for ( int  g = 0; g < 64; g++){
	                  tt[g]=hV[g];}*/
                unsigned  long long  int  i0 = from + j;
                unsigned  long long  int  i1 = from + j + step;

                long long  int  LL1 = hV[i0];
                long long  int  LL2 = hV[i1];
                hV[i0] = LL1 + LL2;
                hV[i1] = LL1 - LL2;
            }
	}
	/*int ttt[64];
	for ( int  g = 0; g < 64; g++){
	ttt[g]=hV[g];}*/

}

 #endif 0
 #if 1== BIGL

 void fwtCPU1l( int *hV, unsigned long long  int l2N)
{
    const unsigned long long  int  N = eee << l2N;

    for (unsigned  long long  int  step = N / 2; step >= 1; step >>= eee)
    {
        for (unsigned  long long  int  from = 0; from < N; from += 2 * step)

            for (unsigned  long long  int  j = 0; j < step; j++)
            {
                unsigned  long long  int  i0 = from + j;
                unsigned  long long  int  i1 = from + j + step;

                long long  int  LL1 = hV[i0];
                long long  int  LL2 = hV[i1];
                hV[i0] = LL1 + LL2;
                hV[i1] = LL1 - LL2;
            }
	}
}



  #endif
void main_HS_walsh1(dmati_type &HS,dmati_type &temp){
	if((2==HS.q)||(4==HS.q)){//for binary codes
      #if 0== BIGL
	fwtCPU1( HS.a[0], HS.k);

	 #endif
	  #if 1== BIGL
	  fwtCPU1l( HS.a[0], HS.k);
	   #endif

    for(long long  int i=0;i<=infsettv.n;i++)
	infsettv.Bspec[i]=0;
	if(2==HS.q){
    for(long long  int  i=0;i<=HS.n;i++)
		infsettv.Bspec[(infsettv.n-HS.a[0][i])>>1]++;}
	if(4==HS.q){
    for(long long  int  i=0;i<=HS.n;i++)
		infsettv.Bspec[(infsettv.n-HS.a[0][i])>>2]++;}
		return;
	}

int a[30];
int titav,j,titanext,u,begHS,endHS,IND;
for(IND=2;IND<=HS.k;IND++){
   for(int j1=1;j1<=HS.k;j1++)a[j1]=0;

   titav=tital(HS.q,(IND-1));
   titanext=tital(HS.q,IND);
   u=0;

   while(u<HS.m){
        begHS=u;
        u=u+titanext;
        endHS=u;
		New_HS_from_begHS_to_endHS(HS,temp,begHS,endHS,titav,titanext);
		if(titanext>100000000000)
		printf("%lu\n",titanext);
		a[IND]=a[IND]+1;
        j=IND;
        while (a[j]==HS.q){
             u=u+1;
			 a[j]=0;
             j=j+1;
             a[j]=a[j]+1;
		}//end WHILE
   }//end WHILE
}//end for;
for(int i=0;i<=infsettv.n;i++)
	infsettv.Bspec[i]=0;
for(int i=1;i<=HS.m;i++)
	infsettv.Bspec[infsettv.n - HS.a[0][1] -HS.a[i][0]]=infsettv.Bspec[infsettv.n-HS.a[0][1] -HS.a[i][0]]+(HS.q-1);

}//end;
