#include "tables.h"












 //=========================================================================================

//===================================Dinamik def begin============================


#ifndef ERRORQ
#define ERRORQ(expr) \
        if ((expr)) { \
		FILE *fran;\
	    fran=fopen("ERRORq.txt", "w");\
		fprintf(fran,"qext file %s: line %d: assertion failed: " \
			"(%s)\n",__FILE__,__LINE__,#expr); \
			int i=fclose(fran); \
			int t;\
	while(true)\
	{\
		printf("ERROR");\
	    scanf("%d",&t);\
	     }\
			exit(1);\
	}
#endif /* !ASSERT */

#ifndef WORNQ
#define WORNQ(expr) if ((expr)){}// \
       // if ((expr)) { \
	//	FILE *fran;\
	 //   fran=fopen("wornq.txt", "a");\
//		fprintf(fran,"qext file %s: line %d: assertion failed: " \
//			"(%s)\n",__FILE__,__LINE__,#expr); \
//			int i=fclose(fran); \
//        			}
#endif /* !ASSERT */

 //typedef  chart;
 char *RD;
 bool MM(char *kind){
	 return true;
 }


 //======================================================================================================
// typedef unsigned char *drow;
//
//  drow drow_new(int size) {
//	drow r;
//	int i=size+2;
//	int j=sizeof(unsigned char);
//	r=(unsigned char*)malloc((i)*j);
//
//	if (r==NULL) {if(MM(RD)) r=(unsigned char*)malloc((i)*j);}
//
//	ERRORQ(r==NULL);
//
//	return &(r[1]);
//}
//static void drow_free(drow &r) {
//	  // 	 if (NULL!=r)
//		{ free(&(r[-1]));
//		  ERRORQ(NULL==&(r[-1]));
//		  r=NULL;
//			}
//}
 //================================================================




//==============================dmati begin======================================




 #if 0== BIGL

typedef short int *drowi;
//extern drowi drowi_new(unsigned long long int size);
//extern void drowi_free(drowi r);

  drowi drowi_new1(unsigned long long int size) {
	drowi r;
	r=(short int*)malloc((size+1)*sizeof(short int));
	if (r==NULL) {if(MM(RD)) r=(short int*)malloc((size+1)*sizeof(short int));}
	//ERRORQ(NULL==r);
	return &(r[0]);
}

  drowi drowi_new(unsigned long long int size) {
	drowi r;
	r=(short int*)malloc((size+1)*sizeof(short  int));
	if (r==NULL) {if(MM(RD)) r=(short int*)malloc((size+1)*sizeof(short int));}
	ERRORQ(NULL==r);
	return &(r[0]);

}

void drowi_free(drowi r) {
	     free(r);
		 ERRORQ(NULL==r);
		}

# endif

 #if 1== BIGL

 typedef  int *drowi;

 drowi drowi_new1(unsigned long long int size) {
	drowi r;
	r=( int*)malloc((size+1)*sizeof( int));
	if (r==NULL) {if(MM(RD)) r=( int*)malloc((size+1)*sizeof( int));}
	//ERRORQ(NULL==r);
	return &(r[0]);
}

  drowi drowi_new(unsigned long long int size) {
	drowi r;
	r=(int*)malloc((size+1)*sizeof( int));
	if (r==NULL) {if(MM(RD)) r=(int*)malloc((size+1)*sizeof(int));}
	ERRORQ(NULL==r);
	return &(r[0]);
}


void drowi_free(drowi r) {
	     free(r);
		 ERRORQ(NULL==r);
		}


#endif








typedef struct _dmati_type dmati_type;
extern  void dmati_free(dmati_type &c);

struct _dmati_type {
	unsigned long long n,m,nreal,d,mreal,k,f,q,mem,nn,max1;             /*  */
	drowi *a;      /* A array of drows. */
	}colorm;

dmati_type dmati_newh(dmati_type &c, unsigned long long int m, unsigned long long int  n,int q) {

	unsigned long long int  i;
	c.n=n;
	c.f=3;
	c.m=m;
	c.nreal=n;
	c.mreal=m;
	c.q=q;
	int ttt=sizeof(drowi);
	c.a=(drowi*)malloc((m+1) * sizeof(drowi));
	if (c.a==NULL) {if(MM(RD)) c.a=(drowi*)malloc((m+1) * sizeof(drowi));}

    ERRORQ(c.a==NULL);
	for (i=0; i < m+1; i++) {
		c.a[i]=drowi_new(n);
		}
	c.mem=1;
	return c;
}


dmati_type dmati_new(dmati_type &c, unsigned long long int  m, unsigned long long int n, int q) {
	c.m=m;
	c.n=n;
	c.f=1;
	if (1==c.mem)
	{if ((c.nreal<n)|| (c.mreal<m))
		{  WORNQ(c.nreal<n);
	       WORNQ(c.mreal<m);
		 dmati_free(c);
		 c.f=3;
		 c=dmati_newh(c, m,n,q);
	     }
	};
	if (0==c.mem)
	{c.mem=1;
	c.f=3;
	c=dmati_newh(c, m,n,q);}
	return c;
}


void dmati_free(dmati_type &c) {
	unsigned long long int  i;
	if (0==c.mem)
	{WORNQ(0==c.mem);
	return;}

	for (i=0; i < c.mreal+1; i++) {
		drowi_free(c.a[i]);
	}

	{free(c.a);
	c.mem=0;
	 ERRORQ(NULL==c.a);
	}
	return;
}














typedef  unsigned long long int longlongu;
typedef longlongu	*drowlu;
 drowlu drowlu_new( unsigned long long int size);
 void drowlu_free(drowlu r);

  drowlu drowlu_new( int size) {
	drowlu r;
	r=( unsigned long long int*)malloc((size+2)*sizeof( unsigned long long int));
	if (r==NULL) {if(MM(RD)) r=( unsigned long long int*)malloc((size+2)*sizeof( unsigned long long int));}
	ERRORQ(NULL==r);
	return &(r[1]);
}

   void drowlu_free(drowlu r) {
	      free(&(r[-1]));
		  ERRORQ(NULL==&(r[-1]));
		  r=NULL;
		}
typedef struct  _dmatlu_type dmatlu_type;
//extern  void dmatlu_free(dmatl_type &c);

struct _dmatlu_type {
	int n,m,nreal,mreal,k,d,q,mem;
	drowlu *b;
	drowlu *a;
	};//dmatluv;

dmatlu_type dmatlu_newh(dmatlu_type &c,int m, int n,int q) {

	int i;
	c.n=n;
	c.m=m;
	c.nreal=n;
	c.mreal=m;
	c.q=q;
	c.a=(drowlu*)malloc((m+1) * sizeof(drowlu));
	if (c.a==NULL) {if(MM(RD)) c.a=(drowlu*)malloc((m+1) * sizeof(drowlu));}

	 ERRORQ(c.a==NULL);
	for (i=0; i < m+1; i++) {
		c.a[i]=drowlu_new(n);
		}

	c.b=(drowlu*)malloc((m+1) * sizeof(drowlu));
	if (c.b==NULL) {if(MM(RD)) c.b=(drowlu*)malloc((m+1) * sizeof(drowlu));}

    ERRORQ(c.a==NULL);
	for (i=0; i < m+1; i++) {
		c.b[i]=drowlu_new(n);
		}
	c.mem=1;
	return c;
}

void dmatlu_free(dmatlu_type &c) {
	int i;
	if (0==c.mem)
	{WORNQ(0==c.mem);
	return;}

	for (i=0; i < c.mreal+1; i++) {
		drowlu_free(c.a[i]);
	}


	for (i=0; i < c.mreal+1; i++) {
		drowlu_free(c.b[i]);
	}




	{free(c.a);
	 free(c.b);
	c.mem=0;
	 ERRORQ(NULL==c.a);
	 ERRORQ(NULL==c.b);
	}
	return;
}



dmatlu_type dmatlu_new(dmatlu_type &c, int m, int n, int q) {
	c.m=m;
	c.n=n;
	if (1==c.mem)
	{if ((c.nreal<n)|| (c.mreal<m))
		{  WORNQ(c.nreal<n);
	       WORNQ(c.mreal<m);
		 dmatlu_free(c);
		 c=dmatlu_newh(c,m,n,q);
	     }
	};
	if (0==c.mem)
	{c.mem=1;
	c=dmatlu_newh(c,m,n,q);}
	return c;
}



//===================beginmatpartlu===========================

dmatlu_type dmatlu_part_newh(dmatlu_type &c,int m, int n,int q) {

//	int i;
	c.n=n;
	c.m=m;
	c.nreal=n;
	c.mreal=m;
	c.q=q;
	c.a=(drowlu*)malloc((m+1) * sizeof(drowlu));
	if (c.a==NULL) {if(MM(RD)) c.a=(drowlu*)malloc((m+1) * sizeof(drowlu));}
    ERRORQ(c.a==NULL);

	c.b=(drowlu*)malloc((m+1) * sizeof(drowlu));
	if (c.b==NULL) {if(MM(RD)) c.b=(drowlu*)malloc((m+1) * sizeof(drowlu));}
    ERRORQ(c.b==NULL);
	c.mem=3;
	return c;
}


void dmatlu_part_free(dmatlu_type &c) {

	if (!((3==c.mem)||(0==c.mem)))
		ERRORQ(!((3==c.mem)||(0==c.mem)))
	if (0==c.mem)
	{WORNQ(0==c.mem);
	return;}

	{free(c.a);
	c.mem=0;
	 ERRORQ(NULL==c.a);
	 }
	{free(c.b);
	c.mem=0;
	 ERRORQ(NULL==c.a);
	 }
	return;
}



dmatlu_type dmatlu_part_new(dmatlu_type &c, int m, int n, int q) {
	c.m=m;
	c.n=n;
	if (!((3==c.mem)||(0==c.mem)))
		ERRORQ(!((3==c.mem)||(0==c.mem)))
	if (3==c.mem)
	{if ((c.nreal<n)|| (c.mreal<m))
		{  WORNQ(c.nreal<n);
	       WORNQ(c.mreal<m);
		 dmatlu_part_free(c);
		 c=dmatlu_part_newh(c,m,n,q);
	     }
	};
	if (0==c.mem)
	{c.mem=3;
	c=dmatlu_part_newh(c,m,n,q);}
	return c;
}



////===================endmatlu_part===========================





  //=============================dmatlolonguend=============================================


//typedef unsigned char *drow;
//  drow drow_new(int size) {
//	drow r;
//	int i=size+2;
//	int j=sizeof(unsigned char);
//	r=(unsigned char*)malloc((i)*j);
//
//	if (r==NULL) {if(MM(RD)) r=(unsigned char*)malloc((i)*j);}
//
//	ERRORQ(r==NULL);
//	return &(r[1]);
//}
//static void drow_free(drow &r) {
//	  // 	 if (NULL!=r)
//		{ free(&(r[-1]));
//		  ERRORQ(NULL==&(r[-1]));
//		  r=NULL;
//			}
//}





typedef  long long int longlong;
typedef longlong	*drowl;
extern drowl drowl_new( long long int size);
extern void drowl_free(drowl r);

  drowl drowl_new( long long int size) {
	drowl r;
	r=( long long int*)malloc((size+1)*sizeof( long long int));
	if (r==NULL) {if(MM(RD)) r=( long long int*)malloc((size+1)*sizeof( long long int));}
	ERRORQ(NULL==r);
	return &(r[0]);
}
 void drowl_free(drowl r) {
	     free(r);
		 ERRORQ(NULL==r);

		}

typedef struct _dmatl_type dmatl_type;
extern  void dmatl_free(dmatl_type &c);

struct _dmatl_type {
	int n,m,nreal,mreal,k,d,q,mem;             /*  */
	drowl *a;      /* A array of drows. */
	};

dmatl_type dmatl_newh(dmatl_type &c,int m, int n,int q) {

	int i;
	c.n=n;
	c.m=m;
	c.nreal=n;
	c.mreal=m;
	c.q=q;
	c.a=(drowl*)malloc((m+1) * sizeof(drowl));
	if (c.a==NULL) {if(MM(RD)) c.a=(drowl*)malloc((m+1) * sizeof(drowl));}

    ERRORQ(c.a==NULL);
	for (i=0; i < m+1; i++) {
		c.a[i]=drowl_new(n);
		}
	c.mem=1;
	return c;
}


dmatl_type dmatl_new(dmatl_type &c, int m, int n, int q) {
	c.m=m;
	c.n=n;
	if (1==c.mem)
	{if ((c.nreal<n)|| (c.mreal<m))
		{  WORNQ(c.nreal<n);
	       WORNQ(c.mreal<m);
		 dmatl_free(c);
		 c=dmatl_newh(c,m,n,q);
	     }
	};
	if (0==c.mem)
	{c.mem=1;
	c=dmatl_newh(c,m,n,q);}
	return c;
}


void dmatl_free(dmatl_type &c) {
	int i;
	if (0==c.mem)
	{WORNQ(0==c.mem);
	return;}

	for (i=0; i < c.mreal+1; i++) {
		drowl_free(c.a[i]);
	}

	{free(c.a);
	c.mem=0;
	 ERRORQ(NULL==c.a);
	}
	return;
}





//=================================infsett begin =========================================================================
struct infsett{
	bool
		count,  // ako e true togava se startirat funkciite za broene broene i ili zapazvane
		       // ako e false samo se tarsi dali minimalnoto teglo otgovaria
			   //opredelia dali shte se broi i zapazva ili tyrsi minimalno razstoianie ili dali to e po malko ili ravno na tova v "infsettv.stop"
		stopok,// ako e false nakraia na saotvetnata procedura ne e spriala ne  e namerila po leka (po leka ili ravna na infsettv.stop, kodova duma
		       // ako e true znachi e namerila po leka kodova duma ot tyrsenata
			   // v nachaloto vinagi triabva da se inivializira kato 'false'

	   	colect,   // ako e true  togava funkciite zapisvat vektorite s teglo po-malko ili ravno na infsettv.weight
		exactweight; // ako e true  togava funkciite zapisvat vektorite s teglo tochno ravno na infsettv.weight

	int b,  //broj matrici v sistemati`en vid
	t,
	z, // pri z=1 se polsva Z64 pri z=0 ne se polzva -- za nulevia red na matricite
	m,  //standartni parameteri
	bk, // parvite "bk" matrici imat razmernost k
	d,  // namerenoto do sega minimalno razstoianie
	stop, //
	mem, //0 ako ne e zaeta
	sups,
	weight, //do kakvo teglo;
	regsp,// ako e 1-smiata spectara,3-zapazvavsichki kodovidumi,4-minimalno rastoianie
	numgen,//broj na zadelenite matrici
	nreal,mreal,numgenreal;
    long long int  n,numcount,numcountold;
               drowi *a;// int a[NUMGENC +1][MAXKC];  tova e matrica s redowe kolkoto sa informacionnite mnogestwa kato wsiako edno
			             // e zapisano na edin red i pochvat ot 1 a ne ot nula
			   //drowi *a0;//	int a0[NUMGENC +1][MAXKC];
			   //drowi *a1;//	int a1[NUMGENC +1][MAXKC];
               drowi k;// int k[NUMGENC +1];
               drowi lcv,lcvo;// int lcv[NUMGENC +1];
               drowi vecrank;// int vecrank[MAXNC];
			   drowi prop;// int k[NUMGENC +1];
		//	   drow Pos_weight;// vyzmovni tegla  1 -da 0 ne
               /*drowi inv; 	*/

			   drowl Aspec;
			   drowl Bspec;
			   // char stoprun; // AKo e  1 e za namirane na minimalno rasztojanie,ako e 3 stop e fiksirano,
			   //	  // ako 0 ne raboti stop
			   drowi colorcolval;// ot tuk se kopira tazi stojnost w strukturatata sa ocvetiavaneto
			   drowi colorm;// a kato rezultat se vrushta tozi vektor na cvetovete koito se izpolzva v CANON
			      // ako ima i vynshen cviat  se izpolzva i v  equcheck6(htfile,3);
			   int colorcol;
			   int colrow;
			   int Inpcolor; //dali ima vynshni cvetove po stylbove
				   // ako ima dva ili poveche vynshni cviata po stylbove te mogat da se sachetaiat s vytreshnite kato se izpolzva maksimuma- kakto e napraveno do sega
               drowi INPinvcolval; // wynshnite cvetove po stylbove mogat da se naslagvat edin sled drug
			   // po redove moge da ima zamo vynshno ocvetiavane c poredni cvetove ot edno natatuk do k
			   // ako ima vynshno ocvetiavane po redove triabva da ima i po stulbove wunshno ocvetiavane
			   // naj malko da se otbelegi koi stylbowe sa za cbiat
			   // matricata "mat" togava shte ima broi na stylbove mat.v= mata1.n+colrow;
			   // za da se zaredi mat triabva da se otdeli pamet i da se znaiat parametrite i
}infsettv;

infsett infset_newh(infsett &c,int mreal, int nreal,int numgenreal) {

	int i;
	c.n=nreal;
	c.m=mreal;
	c.nreal=nreal;
	c.mreal=mreal;
	c.numgenreal=numgenreal;

	c.a=(drowi*)malloc((c.numgenreal+1) * sizeof(drowi));
    ERRORQ(c.a==NULL);
	for (i=0; i <c.numgenreal+1; i++) {
		c.a[i]=drowi_new(mreal);
		}

	/*c.a0=(drowi*)malloc((c.numgenreal+1) * sizeof(drowi));
    ERRORQ(c.a0==NULL);
	for (i=0; i <c.numgenreal+1; i++) {
		c.a0[i]=drowi_new(mreal);
		}

	c.a1=(drowi*)malloc((c.numgenreal+1) * sizeof(drowi));
    ERRORQ(c.a1==NULL);
	for (i=0; i < c.numgenreal+1; i++) {
		c.a1[i]=drowi_new(mreal);
		}*/
	c.Aspec=drowl_new(c.nreal);
	c.Bspec=drowl_new(c.nreal);
	//c.Pos_weight=drow_new(c.nreal);
	c.k=drowi_new(c.numgenreal);
	c.lcv=drowi_new(c.numgenreal);
	c.lcvo=drowi_new(c.numgenreal);
    /*c.inv=drowi_new(c.numgenreal);*/
	c.vecrank=drowi_new(c.nreal);
	c.prop=drowi_new(c.nreal);
    ERRORQ(c.vecrank==NULL);
	c.mem=1;
	return c;
}



void infset_free(infsett &c) {
	int i;

	//ASSERT((sizeof(setelement)*8)==ELEMENTSIZE);
	//ASSERT(g!=NULL);
	//ASSERT(g->n > 0);
	if (0==c.mem)
	{WORNQ(0==c.mem);
	return;
	}

	for (i=0; i < c.numgenreal+1; i++) {
		drowi_free(c.a[i]);
	}
	//if (NULL==c.a)
	free(c.a);
	 ERRORQ(NULL==c.a);

	//for (i=0; i < c.numgenreal+1; i++) {
	//	drowi_free(c.a0[i]);
	//}
	////if (NULL==c.a0)
	//free(c.a0);
	// ERRORQ(NULL==c.a0);
	//
	//for (i=0; i < c.numgenreal+1; i++) {
	//	drowi_free(c.a1[i]);
	//}
	//if (NULL==c.a1)
	free(c.Aspec);
    ERRORQ(NULL==c.Aspec);

	free(c.Bspec);
    ERRORQ(NULL==c.Bspec);

	/*free(c.Pos_weight);
    ERRORQ(NULL==c.Pos_weight);
*/
	/*free(c.a1);
    ERRORQ(NULL==c.a1);*/
	free(c.k);
	ERRORQ(NULL==c.k);
	free(c.lcv);
	ERRORQ(NULL==c.lcv);
	free(c.lcvo);
	ERRORQ(NULL==c.lcvo);
	/*free(c.inv);
	ERRORQ(NULL==c.inv);*/
	free(c.vecrank);
	ERRORQ(NULL==c.vecrank);
	free(c.prop);
	ERRORQ(NULL==c.prop);

	c.mem=0;

}

infsett infset_new(infsett &c, int m, int n,int kind) {

	//int i;
	c.m=m;
	c.n=n;
	// if kind == 3 togava e za namirane na spektara i ni triabvat samo 3 matrici;
	if(3==kind)	{
		c.numgen=3;}
	else{
		c.numgen=n/m+4;}

	if (1==c.mem)
	{if ((c.nreal<n)|| (c.mreal<m) ||  (c.numgenreal<c.numgen))
		{  WORNQ((c.nreal!=n));
	       WORNQ(c.mreal!=m);
		   WORNQ(c.numgenreal<c.numgen);
		 infset_free(c);
		 c=infset_newh(c,m,n,c.numgen);
	     }
	};
	if (0==c.mem)
	{   c.mem=1;
	    if(3==kind)	{
		c.numgenreal=3;}
	else{
		c.numgenreal=n/m+4;}
		c=infset_newh(c,m,n,c.numgenreal);}
	return c;
}





//=================================infsett end =========================================================================



//=================================infsett end =========================================================================









//=========================begin dmat=============================

 typedef unsigned char *drow;

  drow drow_new(int size) {
	drow r;
	int i=size+2;
	int j=sizeof(unsigned char);
	r=(unsigned char*)malloc((i)*j);

	if (r==NULL) {if(MM(RD)) r=(unsigned char*)malloc((i)*j);}

	ERRORQ(r==NULL);


	return &(r[1]);
}
 void drow_free(drow &r) {
	  // 	 if (NULL!=r)
		{ free(&(r[-1]));
		  ERRORQ(NULL==&(r[-1]));
		  r=NULL;
			}
}

typedef struct _dmat_type dmat_type;
extern  void dmat_free(dmat_type &c);

struct _dmat_type {
	int n,m,nreal,mreal,k,d,q,mem,dd,numreg;             /*  */
	drow *a;      /* A array of drows. */
	};

dmat_type dmat_newh(dmat_type &c, int m, int n,int q) {
	//dmat_type c;
	int i;
	c.n=n;
	c.numreg=(n-1)/CREG+1;
	n=c.numreg*CREG;// realnata golemina stava takava che ot pozicia 1 do kraia na zadelenata pamet da e kratno na CREG
	c.m=m;
	c.nreal=n;
	c.mreal=m;
	c.q=q;
	c.a=(drow*)malloc((m+1) * sizeof(drow));
	if (c.a==NULL) {if(MM(RD)) c.a=(drow*)malloc((m+1) * sizeof(drow));}
    ERRORQ(c.a==NULL);
	for (i=0; i < m+1; i++) {
		c.a[i]=drow_new(n);
		}
	c.mem=1;
	return c;
}


dmat_type dmat_new(dmat_type &c, int m, int n, int q) {
	if (!((1==c.mem)||(0==c.mem)))
		ERRORQ(!((1==c.mem)||(0==c.mem)))
	c.m=m;
	c.q=q;
	c.n=n;
	if (1==c.mem)
	{if ((c.nreal<n)|| (c.mreal<m))
		{  WORNQ(c.nreal<n);
	       WORNQ(c.mreal<m);
		 dmat_free(c);
		 c=dmat_newh(c,m,n,q);
	     }
	};
	if (0==c.mem)
	{c.mem=1;
	c=dmat_newh(c,m,n,q);}
	return c;
}


void dmat_free(dmat_type &c) {
	int i;
	if (!((1==c.mem)||(0==c.mem)))
		ERRORQ(!((1==c.mem)||(0==c.mem)))

	if (0==c.mem)
	{WORNQ(0==c.mem);
	return;}

	for (i=0; i < c.mreal+1; i++) {
		drow_free(c.a[i]);
	}

	free(c.a);
	c.mem=0;
	 ERRORQ(NULL==c.a);

	return;
}
dmat_type make_dmat(int m, int n, int q) {
	dmat_type c;
	c.mem = 0;
	dmat_new(c, m, n, q);
	return c;

}

//===================endmat===========================







//============================dinamik global variable begin==============================

dmat_type  //dgfmatrixhmainv,// matrica v koiato shte se generirat kodovite dumi
					            //stoinostta na parvia red triabva da e predvaritelno zadadena
             //    dgfmatrixhv, // pomoshtna matrica v koiato se generirat vektorite pri informacionna chast po malka ot k
				             // vseki vektor ot tazi matrica se pishe kato parvi na "gfmatrixhmainv"
						 //  i se vika podxodiashta procedura
                 //genmatsys,
		    	 //genmatdual,
                 //dgenmatv,
				 dgenmatvh,
				 mat,
	             matven,
				 dmatq;
				 //dmatqh;



//============================dinamik global variable end ===============================================================================

//===================================input autput static begin ==================================================================================
 int dobly_even;
 int checkortmat(dmat_type &matv){
	 int i,i1,j,tt;
	 if (2 == matv.q) {
		 dobly_even = true;
		 for (i = 1; i <= matv.k; i++) {
			 tt = 0;
			 for (j = 1; j <= matv.n; j++) {
				 if (0 != matv.a[i][j]) tt++;
			 }
			 if (0 != (tt % 2)) {
				 return 0;
			 }
			 if (0 != (tt % 4)) {
				 dobly_even = false;
			 }
		 }


		 if (dobly_even) {
			 //printf("1");
			                   for(i=1;i<=matv.k-1;i++)
			 				  for(i1=i+1;i1<=matv.k;i1++){
			 				  tt=0;
			 	              for(j=1;j<=matv.n;j++){
			 					  if(matv.a[i1][j]!=matv.a[i][j]) tt++;}
			 	              if (0!=(tt%4)){
			 					  dobly_even=false;
							  }
			                    }
			                   return 1;
			                   }
		 }
	else        {
		 for(i=1;i<=matv.k-1;i++)
				  for(i1=i+1;i1<=matv.k;i1++){
				  tt=0;
	              for(j=1;j<=matv.n;j++){
					  if(matv.a[i1][j]!=matv.a[i][j]) tt++;}
	              if (0!=(tt%2)){
					  return 0;}
                   }
                  return 1;
                  }



if (3==matv.q){int tt1;
                for(i=1;i<=matv.k;i++){
				  tt=0;
	              for(j=1;j<=matv.n;j++){
					  if(0!=matv.a[i][j]) tt++;}
				  if (0!=(tt%3)){
					  return 0;}
				}
	        for(i=1;i<=matv.k-1;i++)
				  for(i1=i+1;i1<=matv.k;i1++){
				  tt=0;
	              for(j=1;j<=matv.n;j++){
				      tt1=ADD[tt] [	  MUL[matv.a[i1][j]][matv.a[i][j]] ];
				      tt=tt1;}
	                     if (0!=tt){
					  	  return 0;}
                     }
			return 1;
          }

if (4==matv.q){int tt1,sp;
             for(i=1;i<=matv.k;i++){
				  tt=0;
	              for(j=1;j<=matv.n;j++){
					  if(0!=matv.a[i][j]) tt++;}
				  if (0!=(tt%2)){
					  return 0;}
			 }
	        for(i=1;i<=matv.k-1;i++)
				  for(i1=i+1;i1<=matv.k;i1++){
				  tt=0;
	              for(j=1;j<=matv.n;j++){
					  sp=matv.a[i1][j];
					  if((2==sp)||(3==sp)){
					          if(2==sp){sp=3;}
							  else
					            {sp=2;}
					  }
				      tt1=ADD[tt] [	 MUL[sp][matv.a[i][j]] ];
				      tt=tt1;}
	                     if (0!=tt){
					  	  return 0;}
                     }
			return 1;
          }
	 return 1;
 }


 void randomgen(int n, int k,  int q, int num)
{   //time_t t;

      /* Intializes random number generator */
	 time_t t;

      /* Intializes random number generator */
   srand((unsigned) time(&t));

   FILE *fran;
   char st1[30],st3[30];
   itoa(k,st1);
   itoa(n,st3);
   strcat(st3,"_");
   strcat(st3,st1);
   strcat(st3,".");
   itoa(q,st1);
   strcat(st3,st1);
   fran=fopen(st3, "w");
	 // Print n random numbers.
   int numi,ki,ni;
   fprintf(fran,"\n");
   for( numi = 1; numi <= num; numi++ )
   {
	    fprintf(fran,"? %d %d %d %d \n",k,n,q,numi);
        for( ki=1;ki<=k;ki++ )
          {
	       for( ni=1;ni<=n;ni++ )
	          { fprintf(fran,"%d",rand()%q);}
	       fprintf(fran,"\n");
          }
    }
   int i=fclose(fran);
};


  void randomgenf(char *st3,int n, int k,  int q, int num)
{  // time_t t;

      /* Intializes random number generator */
	 time_t t;

      /* Intializes random number generator */
   srand((unsigned) time(&t));

   FILE *fran;
   //q=5;
   fran=fopen(st3, "w");
	 // Print n random numbers.
   int numi,ki,ni;
   fprintf(fran,"\n");
   for( numi = 1; numi <= num; numi++ )
   {
	    fprintf(fran,"? %d %d %d %d \n",k,n,q,numi);
        for( ki=1;ki<=k;ki++ )
          {
	       for( ni=1;ni<=n;ni++ )
	          { int qh=rand()%q;
	          fprintf(fran,"%d",qh);}
	       fprintf(fran,"\n");
          }
    }
   int i=fclose(fran);
};

  void randomgenr(int n, int k,  int q, int num)
{   time_t t;

      /* Intializes random number generator */
   srand((unsigned) time(&t));
   FILE *fran;
   char st1[30],st3[30];
   itoa(k,st1);
   itoa(n,st3);
   strcat(st3,"_");
   strcat(st3,st1);
   strcat(st3,".");
   itoa(q,st1);
   strcat(st3,st1);
   fran=fopen(st3, "w");
	 // Print n random numbers.
   int numi,ki,ni,kk,nn;
   fprintf(fran,"\n");
   for( numi = 1; numi <= num; numi++ )
   {   kk= rand()%k;
       nn= rand()%n;
	    fprintf(fran,"? %d %d %d %d \n",kk,nn,q,numi);
        for( ki=1;ki<=kk;ki++ )
          {
	       for( ni=1;ni<=nn;ni++ )
	          { fprintf(fran,"%d",rand()%q);}
	       fprintf(fran,"\n");
          }
    }
   int i=fclose(fran);
};






void writemat()
{ FILE *fran;
   fran=fopen("res.bin", "w");
	 // Print n random numbers.
   int ki,ni;
    fprintf(fran,"\n");

   {
	    fprintf(fran,"?  %d %d %d \n",mat.m,mat.n,mat.q);
for( ki=1;ki<=mat.m;ki++ )
 {
	 for( ni=1;ni<=mat.n;ni++ )
	 { fprintf(fran,"%d",mat.a[ki][ni]);}
	 fprintf(fran,"\n");
 }

   }
   int i=fclose(fran);
};





//===================================input autput static end ==================================================================================

//===================================input autput dinamic begin ==================================================================================




//===================================input autput dinamic end ==================================================================================

void dreadgmatv(FILE *fpr, dmat_type &genmat)
{

 int i,j,d=0,m,n,q;
 char ch[100];
 fscanf(fpr,"%d",&m);
 fscanf(fpr,"%d",&n);
 fscanf(fpr,"%d",&q);
 //fgets(ch, sizeof(ch), fpr);
 dmat_new(genmat,m,n,q); //otdelia pamet za matricata ako ne e otdelena

 maketable(genmat.q); // zaregda tablicite na poleto

 genmat.k=genmat.m;

 char c=1;
 while (/*(c!='\r')&&*/(c!='\n')){
	 c=getc(fpr);}

 for( i=0;i<genmat.k;i++){
	 for( j=0; j< genmat.n;j++){
		c =getc(fpr);
        if(c=='0') d=0;
        if(c=='1') d=1;
		if(c=='2') d=2;
		if(c=='3') d=3;
		if(c=='4') d=4;
		if(c=='5') d=5;
		if(c=='6') d=6;
		if(c=='7') d=7;
		if(c=='8') d=8;
		if(c=='9') d=9;
        genmat.a[i+1][j+1]=d;
        }
        if (i<(genmat.k-1)){
			c=1;
		    while (/*(c!='\r')&&*/(c!='\n')){
			c =getc(fpr); }
      }
  }
}




void dreadgmativ(FILE *fp, dmati_type &genmat)
{
 int i,j,d,m,n;
 fscanf(fp,"%d",&m);
 fscanf(fp,"%d",&n);
 fscanf(fp,"%d",&genmat.q);
 //genmat.mem=0;
 //genmath.mem=0;

 //for(i=1;i<10;i++){
 // dmat_new(genmat,m,n,genmat.q);
 // dmat_free(genmat);
 //}
  dmati_new(genmat,m,n,genmat.q);
  maketable(genmat.q);
  genmat.k=genmat.m;

 char c=1;
 while ((c!='\r')&&(c!='\n'))
  c=getc(fp);

 for( i=0;i<genmat.k;i++)
 { for( j=0; j< genmat.n;j++)
    {  c =getc(fp);
        if(c=='0') d=0;
        if(c=='1') d=1;
		if(c=='2') d=2;
		if(c=='3') d=3;
		if(c=='4') d=4;
		if(c=='5') d=5;
		if(c=='6') d=6;
		if(c=='7') d=7;
		if(c=='8') d=8;
		if(c=='9') d=9;
       genmat.a[i+1][j+1]=d;

     }
 if (i<(genmat.k-1))
{ c=1; while ((c!='\r')&&(c!='\n')){ c =getc(fp); }
 }

 }
}

void writedmat(char *fname,dmat_type &mat,int k,int num)
{ FILE *fran;
   fran=fopen(fname, "a");

   int ki,ni;
    fprintf(fran,"\n");

   {
	    fprintf(fran,"? %d %d %d %d \n",k,mat.n,mat.q,num/*,mat.mreal,mat.nreal*/);
for( ki=1;ki<=k;ki++ )
 { int tt=0;
	 for(ni=1; ni<=mat.n;ni++ )
	 { if(0!=mat.a[ki][ni]){tt++;}
		 fprintf(fran,"%d",mat.a[ki][ni]);}

	 fprintf(fran," tt= %d\n",tt);
 }

   }
   int i=fclose(fran);
};

void writedmat3(FILE *fran,dmat_type &mat,int k,int num)
{

   int ki,ni;
    fprintf(fran,"\n");

   {
	    fprintf(fran,"? %d %d %d %d \n",k,mat.n,mat.q,num/*,mat.mreal,mat.nreal*/);
for( ki=1;ki<=k;ki++ )
 { int tt=0;
	 for(ni=1; ni<=mat.n;ni++ )
	 { if(0!=mat.a[ki][ni]){tt++;}
		 fprintf(fran,"%d",mat.a[ki][ni]);}

	 fprintf(fran,"\n");
 }

   }

};

void writedmat33(FILE *fran,dmat_type &mat,int k,int num)
{

   int ki,ni,tb=0;
   for(ni=1; ni<=mat.n;ni++ ){
	   int tt=0;
	   for( ki=1;ki<=k;ki++ )
		     { if(0==mat.a[ki][ni]){tt++;}
	   if (tt==k){tb++;}

   }

   }

   {
	    fprintf(fran,"? %d %d %d %d \n",k,mat.n-tb,mat.q,num/*,mat.mreal,mat.nreal*/);
for( ki=1;ki<=k;ki++ )
 { int tt=0;
	 for(ni=tb+1; ni<=mat.n;ni++ )
	 { if(0!=mat.a[ki][ni]){tt++;}
		 fprintf(fran,"%d",mat.a[ki][ni]);}

	 fprintf(fran,"\n");
 }

   }

};

void writedmattr(char *fname,dmat_type &mat,int k,int num)
{ FILE *fran;
   fran=fopen(fname, "a");

   int ki,ni;
    fprintf(fran,"\n");

   {
	    fprintf(fran,"? %d %d %d %d \n",mat.n,k,mat.q,num/*,mat.mreal,mat.nreal*/);
for( ki=1;ki<=mat.n;ki++ )
 {
	 for(ni=1; ni<=k;ni++ )
	 {
		 fprintf(fran,"%d",mat.a[ni][ki]);}

	 fprintf(fran,"\n");
 }

   }
   int i=fclose(fran);
};


void writedmatold(char *fname,dmat_type &mat,int k,int num)
{ FILE *fran;
   fran=fopen(fname, "a");

   int ki,ni;
    fprintf(fran,"\n");

   {
	    fprintf(fran,"? %d %d 2 %d %d %d  \n",k,mat.n,num,mat.mreal,mat.nreal);
for( ki=1;ki<=k;ki++ )
 {
	 for(ni=1; ni<=mat.n;ni++ )
	 {
		 fprintf(fran,"%d",mat.a[ki][ni]);}
	 fprintf(fran,"\n");
 }

   }
   int i=fclose(fran);
};

void writedmatstef(char *fname,dmat_type &mat,int k,int num,int numb)
{ FILE *fran;
   fran=fopen(fname, "a");

   int ki,ni;
    fprintf(fran,"\n");

   {
	    fprintf(fran,"? %d %d 2 %d %d  \n",k,mat.n,num,numb);
for( ki=1;ki<=k;ki++ )
 {
	 for(ni=1; ni<=mat.n;ni++ )
	 {
		 fprintf(fran,"%d",mat.a[ki][ni]);}
	 fprintf(fran,"\n");
 }

   }
   int i=fclose(fran);
};


void writedmatof1(FILE *fran,dmat_type &mat,int k,int num)
{

   int ki,ni;
    fprintf(fran,"\n");

   {
	    fprintf(fran,"? %d %d %d %d %d %d  \n",k,mat.n,mat.q,num,mat.mreal,mat.nreal);
for( ki=0;ki<=k;ki++ )
 {
	 for(ni=-1; ni<=mat.n;ni++ )
	 {
		 fprintf(fran,"%d,",mat.a[ki][ni]);}
	 fprintf(fran,"\n");
 }

   }
  };

void writedmatof(FILE *fran,dmat_type &mat,int k,int num,unsigned long long size)
{

   int ki,ni;
    fprintf(fran,"\n");

   {
	    fprintf(fran,"? %d %d %d %d %d %d  \n",k,mat.n,mat.q,num,mat.mreal,mat.nreal);
for( ki=1;ki<=k;ki++ )
 {
	 for(ni=1; ni<=mat.n;ni++ )
	 {
		 fprintf(fran,"%d",mat.a[ki][ni]);}
	     fprintf(fran,"\n");
	 //fprintf(fran," %d %d,\n",mat.a[ki][-1],mat.a[ki][0]);
 }

   }

   fprintf(fran,"G= %llu \n",size);
  };


void writedmatoftr(FILE *fran,dmat_type &mat,int k,int num)
{

   int ki,ni;
    fprintf(fran,"\n");

   {
	    fprintf(fran,"? %d %d %d %d %d %d  \n",mat.n,k,mat.q,num,mat.mreal,mat.nreal);
for( ki=1;ki<=mat.n;ki++ )
 {
	 for(ni=1; ni<=k;ni++ )
	 {
		 fprintf(fran,"%d",mat.a[ni][ki]);}
	     fprintf(fran,"\n");
	 //fprintf(fran," %d %d,\n",mat.a[ki][-1],mat.a[ki][0]);
 }

   }
  };


void writedmati(char *fname,dmati_type &mat,int k,int num)
{ FILE *fran;
   fran=fopen(fname, "a");

   int ki,ni;
    fprintf(fran,"\n");

   {
	    fprintf(fran,"? %d %d %d %d %d %d  \n",k,mat.n,mat.q,num,mat.mreal,mat.nreal);
for( ki=0;ki<=k;ki++ )
 {
	 for(ni=0; ni<=mat.n;ni++ )
	 {
		 fprintf(fran,"%d,",mat.a[ki][ni]);}
	 fprintf(fran,"\n");
 }

   }
   int i=fclose(fran);
};


void writedmatl(char *fname,dmatl_type &mat,int k,int num)
{ FILE *fran;
   fran=fopen(fname, "a");

   int ki,ni;
    fprintf(fran,"\n");

   {
	    fprintf(fran,"? %d %d %d %d %d %d  \n",k,mat.n,mat.q,num,mat.mreal,mat.nreal);
for( ki=1;ki<=k;ki++ )
 {
	 for(ni=0; ni<=mat.n;ni++ )
	 {
		 fprintf(fran,"%lli,",mat.a[ki][ni]);}
	 fprintf(fran,"\n");
 }

   }
   int i=fclose(fran);
};



void writespec(const char *fname)
{ FILE *fran;
   fran=fopen(fname, "a");
	int i;
	fprintf(fran," \n");
	for (i=0;i<=infsettv.n;i++)
		if(0!=infsettv.Aspec[i])
		fprintf(fran,"  %d ^ %lld ",i,infsettv.Aspec[i]);

    i=fclose(fran);
};

void writespecof(FILE *fran)
{

	int i;
	fprintf(fran," \n");
	for (i=0;i<=infsettv.n;i++)
		if(0!=infsettv.Aspec[i])
		fprintf(fran,"  %d ^ %lld ",i,infsettv.Aspec[i]);


};


void writespecofh(FILE *fran)
{

	int i;
	fprintf(fran," \n");
	for (i=0;i<=infsettv.n;i++)
		if(0!=infsettv.Bspec[i])
		fprintf(fran," %d^%lld ",i,infsettv.Bspec[i]);


};

void writespech(char *fname)
{ FILE *fran;
   fran=fopen(fname, "a");
	int i;

	fprintf(fran," \n");
	fprintf(fran,"B");
	for (i=0;i<=infsettv.n;i++)
		if(0!=infsettv.Bspec[i])
		fprintf(fran,"  %d ^ %lld ",i,infsettv.Bspec[i]);

    i=fclose(fran);
};

void writeprop(char *fname)
{ FILE *fran;
   fran=fopen(fname, "a");
	int i;

	fprintf(fran," \n");
	for (i=0;i<=infsettv.n;i++)
		if(0!=infsettv.prop[i])
		fprintf(fran,"%d",infsettv.prop[i]);

    i=fclose(fran);
};




int hh=0;
unsigned long long E64=0,EA64[64],Z64[10];

unsigned long long  binom(int n, int ii) {
	if ((n / 2) < ii) { ii = n - ii; }
	int w=2;
	unsigned long long a=1;

	for (int i = n - ii + 1; i <= n; i++) {
		a = a * i;
		ERRORQ(a > EA64[56]);
		if (0 == (a % w)) {
			a = a / w;
			if (w == ii) { w = 1; }
			if (w < ii) { w++; }


		}

	}
	return a;
}

const int CINVAR=101;
 bool  GLARC;
 bool repeated_column,ONEINT;


 //int yyy2 = 0;

 int PARALELnivo;
 int PARALELbr;
 int PARALELcur=0;
 int color=0;
 int  cpuInfo[4];

int HASH_TABLE_SIZE = 555555;//
dmatlu_type hashMas;
dmat_type HHhelp;
int cyrhfile;
dmati_type hasharr;

 int numHF=11;
 const int  numHFMAX=11;
 char dirNameres[300],// direktoriata kadeto se zapisvat osnovnite failove s rezultatite ako PARALLEL=0 tova e osnovnata direktoria ako e paralelno za vseki proces e nRES_DIR
	  dirName[300],//direktotiata kudeto sa vremennite reshenia   ako ne e paralelno tia e RES_DIR inache e /dev/shm/RES_DIR
	  dirNamedev[300];
 //unsigned int __level,
//unsigned int *__eax,  *__ebx, *__ecx,  *__edx;
unsigned int cinf000,cinf00;
 unsigned int cinf0,cinf1,cinf2,cinf3;



int sumresult(char lokaldir[300],char codepar[300],int numpr){
 FILE *infile,*resfile,*inf;
 char ch[300];
 //char lokaldir[300]; // RES_DIRM
 //char codepar[300];  // 29_3_24.7
 char allrfilename[300]; //  all29_3_24.7
 char lokalfilename[300];
 char glfilename[300];
 char glfilenameinf[300];
 //int numpr=10;
 char nivoch[10];
 int numc,numall;
 strcpy(glfilename,"all");
 strcat(glfilename,codepar);
 strcpy(glfilenameinf,glfilename);
 strcat(glfilenameinf,"inf");

 resfile=fopen(glfilename,"w");
 inf=fopen(glfilenameinf,"w");
 numall=0;
  for(int i=0;i<numpr;i++){
	      strcpy(lokalfilename,lokaldir);
		  itoa(i, nivoch);
		  strcat(lokalfilename,nivoch);
          strcat(lokalfilename, PATH_SEPARATOR);
          strcat(lokalfilename,codepar);
          printf("%s",lokalfilename);
		  infile=fopen(lokalfilename,"r");
		  if(NULL==infile){
		  printf("File with name: %s  does not exist",lokalfilename );
		  return 5;
		  }
		  numc=0;
		  while (!(feof(infile))) {
			  strcpy(ch,"");
		  fgets(ch, sizeof(ch),infile);
		  //if('?'==ch[0]){
		  if('?'==ch[0]){
			  if((0==i) ||((0<i)&&('2'!=ch[1])&&('3'!=ch[1]&&('4'!=ch[1])))) //ako e paralelno i do nivo 4 se povtariat
				                                                             //ako ne se povtariat triabva da se zatapi
			  {
		  numc++;
		  numall++;
		  fprintf(resfile,"%s",ch);
			  }
		  }
		  else{
			  fprintf(resfile,"%s",ch);}
		  if('E'==ch[5]){
		  fprintf(inf,"%s",ch);
		   }

		  }

		  fprintf(resfile,"PR    %d   NUMSTRUCT - %d  \n", i,numc);
		  fprintf(inf,"PR    %d   NUMSTRUCT - %d  \n", i,numc);
		   fclose(infile);

      }
  fprintf(resfile,"\n  NUMSTRUCTALL  %d  \n", numall);
  fprintf(inf,"\n  NUMSTRUCTALL  %d  \n", numall);
 fclose(resfile);
  fclose(inf);
  return 1;
  }

 int readintf(FILE *f){
char *p, s[100];
strcpy(s,"");
 int n=-1;
    if(NULL!=fgets(s, sizeof(s), f));
    n = strtol(s, &p, 10);
	return n;
	}


 int readint(int lb, int ub, int kind){
char *p, s[100];
    int n=-1,b=-1;
	if(0==kind){
		strcpy(s,"");
    while (fgets(s, sizeof(s), stdin)) {
        n = strtol(s, &p, 10);
        if (p == s || *p != '\n') {
            printf("");
        } else break;
    }
	return n;}
	else{
		while((n<lb)||(n>ub)){
			b++;
			if (0<b){
		printf("ENTER THE INTEGER BETWEEN %d and %d ",lb,ub);}
			  while (fgets(s, sizeof(s), stdin)) {
        n = strtol(s, &p, 10);
        if (p == s || *p != '\n') {
            printf("Please enter an integer: ");
        } else break;
    }


		}
		return n;
	}
}

char getyn(){
	char ch[50];
	strcpy(ch,"");
	while(!((ch[0]=='y')||(ch[0]=='Y')||(ch[0]=='n')||(ch[0]=='N'))){
		//ch[0]=getchar();
		fgets(ch, sizeof(ch), stdin);

        //while (fgets(ch, sizeof(ch), stdin)) {
		//}
		//ch[1]='\0';
    }

	return ch[0];
}


void getstring(char ch[300]){
char ch0[300];
int i;
     /*strcpy(ch0,"");
     strcpy(ch,"");
     for(i=0;i<sizeof(ch0);i++){
     ch0[i]=' ';
     ch[i]=' ';}
*/
     strcpy(ch0,"");
     strcpy(ch,"");


     while(fgets(ch0, sizeof(ch0),stdin)){
     if (ch0[0]!=' '  && ch0[0] != '\n') {
            break;
        }
}
     i=strlen(ch0);
     strncpy(ch,ch0,i-1);
	 ch[i-1] = '\0';
     /* for(i=0;i<(i-1);i++){
      if('\n'!=ch0[i]){
      ch[i]=ch0[i];}
      else break;
      }
      */
    // strcpy(ch,ch0);
 //printf(" %s \n",ch);
     }

void getstring1(char ch[300]){
     char *ch0 = NULL;  /* forces getline to allocate with malloc */
size_t len = 0;     /* ignored when line = NULL */
int i;
/* snip */
//getline (&ch0, &len, stdin);
i=strlen(ch0);
     //strcpy(ch,ch0);
     strncpy(ch,ch0,i-1);
     ch[i-1] = '\0';
    // printf(" %s \n",ch);
}

 void sumresmain(){
	char ch1[300],ch3[300];
	int num,hh;
	do{
	printf(" enter the directory:");
	getstring(ch1);
	//scanf("%s", &ch1);
	printf("enter the number of treds:");
	  num=readint(0, 10000, 0);
	printf(" enter the name:");
	  getstring(ch3);
	  hh=sumresult(ch1,ch3,num);}
	while(1!=hh);
     //sumresult("RES_DIRM","29_3_24.7",3);
 }

  int suminf(char lokaldir[300],char codepar[300],int numpr){
 FILE *infile,*resfile,*inf;
 char ch[300];
 //char lokaldir[300]; // RES_DIRM
 //char codepar[300];  // 29_3_24.7
 char allrfilename[300]; //  all29_3_24.7
 char lokalfilename[300];
 char glfilename[300];
 char glfilenameinf[300];
 //int numpr=10;
 char nivoch[10];
 int numc,numall;
 strcpy(glfilename,"all");
 strcat(glfilename,codepar);
 strcpy(glfilenameinf,glfilename);
 //strcat(glfilenameinf,"inf");

 resfile=fopen(glfilename,"w");
 inf=fopen(glfilenameinf,"w");
 numall=0;
 unsigned long long int rrr[100][50];
 for(int i=0;i<100;i++)
	 for(int j=0;j<50;j++){
	 rrr[i][j]=0;
	 }
	 rrr[0][0]=1;
	 int n,k,num,ok=0;
  for(int i=0;i<numpr;i++){
	      strcpy(lokalfilename,lokaldir);
		  itoa(i, nivoch);
		  strcat(lokalfilename,nivoch);
          strcat(lokalfilename, PATH_SEPARATOR);
          strcat(lokalfilename,codepar);
          printf("%s",lokalfilename);
		  infile=fopen(lokalfilename,"r");
		  if(NULL==infile){

		  printf("File with name: %s  does not exist",lokalfilename );
		  return 5;
		  }
		  numc=0;
		  int ii;
		  while (!(feof(infile))) {
			  //fscanf(infile,"%d,%d,%d",&n,&k,&num);
			  ii=fscanf(infile,"%d",&n);
              ii=fscanf(infile,"%d",&k);
              ii=fscanf(infile,"%d",&num);

			  if (0==i){
				  rrr[n][k]=rrr[n][k]+num;
			      rrr[n][0]=rrr[n][0]+num;
				  rrr[0][k]=rrr[0][k]+num;
			  }
			  if ((0<i)&&(4<k)){
				  rrr[n][k]=rrr[n][k]+num;
				  rrr[n][0]=rrr[n][0]+num;
				  rrr[0][k]=rrr[0][k]+num;
			  }
		  }
		  //char  c=1; while (/*feof(infile)||*/(c!='\n')){
			//  c =getc(infile); }
		/*	  strcpy(ch,"");
		  fgets(ch, sizeof(ch),infile);
		  if('?'==ch[0]){
		  numc++;
		  numall++;}
		  fprintf(resfile,"%s",ch);
		  if('E'==ch[5]){
		  fprintf(inf,"%s",ch);
		   }

		  }*/



		   fclose(infile);
      }

     for(int i=0;i<100;i++){
		     if(0!=rrr[i][0]){
				     fprintf(resfile," %d ",i);
			    	 for(int j=0;j<50;j++){

						  if(0!=rrr[0][j]){
							  fprintf(resfile," %llu  " , rrr[i][j]);}}


			 }
			 fprintf(resfile," \n  ");
	 }

  //fprintf(resfile,"\n  NUMSTRUCTALL  %d  \n", numall);
  //fprintf(inf,"\n  NUMSTRUCTALL  %d  \n", numall);
 fclose(resfile);
  fclose(inf);
  return 0;
  }


 void suminfmain(){
	char ch1[300],ch3[300];
	int num,hh;
	do{
	printf(" enter the directory:");
	getstring(ch1);
	//scanf("%s", &ch1);
	printf("enter the number of treds:");
	  num=readint(0, 10000, 0);
	printf(" enter the name:");
	  getstring(ch3);
	  hh=suminf(ch1,ch3,num);}
	while(1!=hh);
     //sumresult("RES_DIRM","29_3_24.7",3);
 }








 int ordrer_of_first_codeword=1;
 bool Look_forcodeword=false;
 int FIRST_TEG=0;

