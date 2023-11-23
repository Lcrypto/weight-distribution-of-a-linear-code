//#include <io.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <malloc.h>

//#include "mpi.h"
#define _CRT_SECURE_NO_DEPRECATE

//#include <tmmintrin.h>
//#include <smmintrin.h>
// "mpi.h"
using namespace std;

#define BIGL 1 // 0 short
             //1   int

#define SIZEREG 128

#if 128==SIZEREG
     const int CREG=16;// broj bajtove w edin registar
#endif

#if 256==SIZEREG
     const int CREG=32;// broj bajtove w edin registar
#endif


#define NINSR 1
//#define CODEBL 1 // za GSS1
 #if 1== NINSR
     #include <tmmintrin.h>
      #include <smmintrin.h>
//#if CODEBL
//      #include <cpuid.h>
//#endif


// "mpi.h"

  #endif

//#if 0==CODEBL
// #include <direct.h>
//#endif

//#include <direct.h>
#if (defined(__linux__)/*||(CODEBL)*/)
   #include <sys/types.h>
   #include <sys/stat.h>
//#include <sys/types.h>
    #include <dirent.h>
    #include <unistd.h>
     //#if 1== NINSR
     //   #include <cpuid.h>
     //#endif
//#include <dirent.h>
//#include <intrin.h>
//#elseif

#endif


#if  (0!=PARALEL)

#include <mpi.h>

#endif

#if  (1==PARALEL)

#include <mpi.h>

#endif

#if  (6==PARALEL)

#include <mpi.h>

#endif


//#if  (3==PARALEL)
//
//#include <mpi.h>
//
//#endif


int bigmat[50000][300];
int bigmat1[50000][300];

 int myrank, nprocs;

//#include <cpuid.h>
//#include <mmintrin-common.h>
//#include <conio.h>


//DDD4
clock_t start_t, end_t, start_tcan, end_tcan, total_tcan, start_temp;
bool USINV;

bool BITPR;


#if ((ULONG_MAX) == (UINT_MAX))
# define IS3264 32
#else
# define IS3264 64
#endif



const int NTABLEC=20;
unsigned int mi[65536];

 static union
{
  unsigned long long int I64;
  unsigned short A64[4];
  unsigned int A32[2];
  //stt st;222222222222222222222
};

unsigned long long sys1[68], sys[68];
char BIT=0,CHEK=0;

unsigned long long /*half_mask,half_word,*/t_w,w_w;
int weight0(unsigned long long& word){
	//unsigned long long t;
	//unsigned long long w;
	t_w = word - ((word >> 1) & 0x5555555555555555L);
	t_w = (t_w & 0x3333333333333333L) + ((t_w >> 2) & 0x3333333333333333L);
	t_w = ((t_w + (t_w >> 4)) & 0x0f0f0f0f0f0f0f0fL);
	w_w = (t_w * 0x0101010101010101L) >> 56;

	return int(w_w);
}

//__declspec(selectany) int __popcnt64(unsigned long long  int){}
// unsigned short *A321=&AA32[0],*A322=&AA32[1];
int FASTTEG=0;

//#if 1== NINSR
//
//#if ((defined(_WIN64))/*&&(!CODEBL)*/)
//#include <intrin.h>
//#include <direct.h>
//   /* #ifndef __SSE4_2__
//    inline int teg(unsigned long long  int &word){
//		 I64=word;
//		  return mi[A64[1]]+mi[A64[2]]+mi[A64[3]]+mi[A64[0]];
//     }
//    #else*/
//     //#include <smmintrin.h>
//    inline	int teg(unsigned long long  int &word){
//	  // if(1==FASTTEG)
//	    {
//		   /*if (__popcnt64(word) != _mm_popcnt_u64(word))
//		   {
//			   int t = 9;
//		   };*/
//		 return _mm_popcnt_u64(word);
//	   }
//	    //else
//		{
//	     I64=word;
//	     return mi[A64[1]]+mi[A64[2]]+mi[A64[3]]+mi[A64[0]];}
//        }
////#endif /* __SSE4_2__ */
//#endif
//
//#if ((_WIN32) &&(!CODEBL)&& (!_WIN64))/* Microsoft Windows (32-bit). ------------------------------ */
//#include <intrin.h>
//#include <direct.h>
//inline int teg(unsigned long long  int &word){
//
//		I64=word;
//		 if(false)//1==FASTTEG)
//	    {
//			return _mm_popcnt_u32(A32[0])+ _mm_popcnt_u32(A32[1]);
//	     }
//	    else{
//
//	 return mi[A64[1]]+mi[A64[2]]+mi[A64[3]]+mi[A64[0]];}
//}
//
//#endif
//
//#if (defined(__linux__)||(CODEBL))
////inline
//int teg(unsigned long long  int &word) {
//
//	if (1 == FASTTEG)
//	{
//		//return __popcnt64(word);
//
//     #if (64==IS3264)
//		return _mm_popcnt_u64(word);
//	#endif // __WORDSIZE
//
//	#if   (32==IS3264)
//		return _mm_popcnt_u32(word);
//	#endif // __WORDSIZE
//
//	}
//	else
//	{
//		I64 = word;
//
//		return mi[A64[1]] + mi[A64[2]] + mi[A64[3]] + mi[A64[0]];
//	}
//		}
//
//
//#endif
//
//#else
//inline int teg(unsigned long long  int &word) {
//
////printf("   okteg \n");
//		I64 = word;
//		return mi[A64[1]] + mi[A64[2]] + mi[A64[3]] + mi[A64[0]];
//
//		}
//#endif
//
//
//

// const int CHEK = 1;       //  pri 1 pravi dopalnitelni zasechki za korektnostta na programata
//typedef int[100] arr;
int ADD[NTABLEC][NTABLEC];
int MUL[NTABLEC][NTABLEC];
int TRE[NTABLEC];

int NEG[NTABLEC];
int TABTEG; //tegloto na nenulevite ot vsiako q v dvoichnata matrica
unsigned long long QN[NTABLEC+3];
int INV[NTABLEC];
int bazemain[NTABLEC];
int baze[NTABLEC][NTABLEC];
int CYCL[NTABLEC][NTABLEC];
int t[4]={1,2,3,4};
extern void maketable();
extern unsigned long long stepl(int a, int b);


unsigned long long stepl(int a, int b)
{int i;
 unsigned long long int c;
 c=1;
 for(i=1;i<=b;i++)
	 c=c*a;
 return c;
}

unsigned long long stepltita(int a, int b)
{int i;
 unsigned long long int c;
 c=1;
 for(i=1;i<=b;i++)
	 c=c*a;
 return (c-1)/(a-1);
}

unsigned long long tital(int a, int b)
{
 int i;
 unsigned long long int c;
 c=1;
 for(i=1;i<=b;i++)
	 c=c*a;
 return (c-1)/(a-1);
}

const char PATH_SEPARATOR[2] =
#ifdef _WIN32||_WIN64
{'\\'};
#else
{'/'};
#endif





//void makeDirectory( char* name) {
//#if CODEBL
//	int status;
//
////mkdir(name);
//status = mkdir(name, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
//
//#else
//  _mkdir(name);
////mkdir(path,0777);
////rek_mkdir(name);
////struct stat st = {0};
//
////if (stat(name, &st) == -1) {
////    mkdir(name);
////}
//
//#endif
//}

 char* itoa(int i, char b[])
 {
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0){
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do{ //Move to where representation ends
        ++p;
        shifter = shifter/10;
    }while(shifter);
    *p = '\0';
    do{ //Move back, inserting digits as u go
        *--p = digit[i%10];
        i = i/10;
    }while(i);
    return b;
}


 int QLOAD=0;
 void maketable(int q)
 {
	 if(QLOAD==q){
		 return;}
	 if (q>4){ USINV=false;}
	 if (q>4){ BITPR=false;}

	  QN[0] = 1;
	 int i = 0;
	 while ((QN[i] < stepl(2, 63)) && (i < (NTABLEC-1)))
	 {
		 i++;
		 QN[i] = QN[i - 1] * q;
	 }

	 if (2 == q) {
		 /* */ADD[0][0] = 0; ADD[1][0] = 1;
		 ADD[0][1] = 1; ADD[1][1] = 0;
		 MUL[0][0] = 0; MUL[1][0] = 0;
		 MUL[0][1] = 0; MUL[1][1] = 1;
		 INV[1] = 1; INV[0] = 0;
		 NEG[1] = 1; NEG[0] = 0;
		TABTEG=1;

	 }
	 /* */
	 if (3 == q) {
		 ADD[0][0] = 0; ADD[1][0] = 1; ADD[2][0] = 2;
		 ADD[0][1] = 1; ADD[1][1] = 2; ADD[2][1] = 0;
		 ADD[0][2] = 2; ADD[1][2] = 0; ADD[2][2] = 1;

		 MUL[0][0] = 0; MUL[1][0] = 0; MUL[2][0] = 0;
		 MUL[0][1] = 0; MUL[1][1] = 1; MUL[2][1] = 2;
		 MUL[0][2] = 0; MUL[1][2] = 2; MUL[2][2] = 1;

		 int c0[4] = { 0,0,0,0 };
		 for (int i = 0; i < 4; i++) baze[0][i] = c0[i];
		 int c1[4] = { 1,0,1,1 };
		 for (int i = 0; i < 4; i++) baze[1][i] = c1[i];
		 int c2[4] = { 1,1,1,0 };
		 for (int i = 0; i < 4; i++) baze[2][i] = c2[i];



		 int a0[2] = { 0,0 };
		 for (int i = 0; i < 2; i++) CYCL[0][i] = a0[i];

		 int a1[2] = { 1,2 };
		 for (int i = 0; i < 2; i++) CYCL[1][i] = a1[i];
		 int a2[2] = { 2,1 };
		 for (int i = 0; i < 2; i++) CYCL[2][i] = a2[i];



		 INV[1] = 1; INV[0] = 0; INV[2] = 2;
		 NEG[1] = 2; NEG[0] = 0; NEG[2] = 1;

		 TABTEG=3;
	 }
	 /* */

	 if (4 == q) {
		 ADD[0][0] = 0; ADD[1][0] = 1; ADD[2][0] = 2; ADD[3][0] = 3;
		 ADD[0][1] = 1; ADD[1][1] = 0; ADD[2][1] = 3; ADD[3][1] = 2;
		 ADD[0][2] = 2; ADD[1][2] = 3; ADD[2][2] = 0; ADD[3][2] = 1;
		 ADD[0][3] = 3; ADD[1][3] = 2; ADD[2][3] = 1; ADD[3][3] = 0;


		 MUL[0][0] = 0; MUL[1][0] = 0; MUL[2][0] = 0; MUL[3][0] = 0;
		 MUL[0][1] = 0; MUL[1][1] = 1; MUL[2][1] = 2; MUL[3][1] = 3;
		 MUL[0][2] = 0; MUL[1][2] = 2; MUL[2][2] = 3; MUL[3][2] = 1;
		 MUL[0][3] = 0; MUL[1][3] = 3; MUL[2][3] = 1; MUL[3][3] = 2;

    	  int c0[6] = { 0,0,0,0,0,0 };
		 for (int i = 0; i < 6; i++) baze[0][i] = c0[i];
		 int c1[6] = { 1,0,1,1,1,1 };
		 for (int i = 0; i < 6; i++) baze[1][i] = c1[i];
		 int c2[6] = { 1,1,1,0,1,1, };
		 for (int i = 0; i < 6; i++) baze[2][i] = c2[i];
		 int c3[6] = { 1,1,1,1,1,0 };
		 for (int i = 0; i < 6; i++) baze[3][i] = c3[i];


		 int a0[3] = { 0,0,0, };
		 for (int i = 0; i < 3; i++) CYCL[0][i] = a0[i];

		 int a1[3] = { 1,2,3, };
		 for (int i = 0; i < 3; i++) CYCL[1][i] = a1[i];
		 int a2[3] = { 2,3,1, };
		 for (int i = 0; i < 3; i++) CYCL[2][i] = a2[i];
		 int a3[3] = { 3,1,2 };
		 for (int i = 0; i < 3; i++) CYCL[3][i] = a3[i];

		 TRE[0] = 0; TRE[1] = 0; TRE[2] = 1; TRE[3] = 1;
		 INV[0] = 0; INV[1] = 1; INV[2] = 3; INV[3] = 2;
		 NEG[0] = 0; NEG[1] = 1; NEG[2] = 2; NEG[3] = 3;
		 TABTEG=5;

	 }

	 if (7 == q) {
		 ADD[0][0] = 0; ADD[1][0] = 1; ADD[2][0] = 2; ADD[3][0] = 3; ADD[4][0] = 4; ADD[5][0] = 5; ADD[6][0] = 6;
		 ADD[0][1] = 1; ADD[1][1] = 2; ADD[2][1] = 3; ADD[3][1] = 4; ADD[4][1] = 5; ADD[5][1] = 6; ADD[6][1] = 0;
		 ADD[0][2] = 2; ADD[1][2] = 3; ADD[2][2] = 4; ADD[3][2] = 5; ADD[4][2] = 6; ADD[5][2] = 0; ADD[6][2] = 1;
		 ADD[0][3] = 3; ADD[1][3] = 4; ADD[2][3] = 5; ADD[3][3] = 6; ADD[4][3] = 0; ADD[5][3] = 1; ADD[6][3] = 2;
		 ADD[0][4] = 4; ADD[1][4] = 5; ADD[2][4] = 6; ADD[3][4] = 0; ADD[4][4] = 1; ADD[5][4] = 2; ADD[6][4] = 3;
		 ADD[0][5] = 5; ADD[1][5] = 6; ADD[2][5] = 0; ADD[3][5] = 1; ADD[4][5] = 2; ADD[5][5] = 3; ADD[6][5] = 4;
		 ADD[0][6] = 6; ADD[1][6] = 0; ADD[2][6] = 1; ADD[3][6] = 2; ADD[4][6] = 3; ADD[5][6] = 4; ADD[6][6] = 5;

		 MUL[0][0] = 0; MUL[1][0] = 0; MUL[2][0] = 0; MUL[3][0] = 0; MUL[4][0] = 0; MUL[5][0] = 0; MUL[6][0] = 0;
		 MUL[0][1] = 0; MUL[1][1] = 1; MUL[2][1] = 2; MUL[3][1] = 3; MUL[4][1] = 4; MUL[5][1] = 5; MUL[6][1] = 6;
		 MUL[0][2] = 0; MUL[1][2] = 2; MUL[2][2] = 4; MUL[3][2] = 6; MUL[4][2] = 1; MUL[5][2] = 3; MUL[6][2] = 5;
		 MUL[0][3] = 0; MUL[1][3] = 3; MUL[2][3] = 6; MUL[3][3] = 2; MUL[4][3] = 5; MUL[5][3] = 1; MUL[6][3] = 4;
		 MUL[0][4] = 0; MUL[1][4] = 4; MUL[2][4] = 1; MUL[3][4] = 5; MUL[4][4] = 2; MUL[5][4] = 6; MUL[6][4] = 3;
		 MUL[0][5] = 0; MUL[1][5] = 5; MUL[2][5] = 3; MUL[3][5] = 1; MUL[4][5] = 6; MUL[5][5] = 4; MUL[6][5] = 2;
		 MUL[0][6] = 0; MUL[1][6] = 6; MUL[2][6] = 5; MUL[3][6] = 4; MUL[4][6] = 3; MUL[5][6] = 2; MUL[6][6] = 1;

		 int c0[12] = { 0,0,0,0,0,0,0,0,0,0,0,0, };
		 for (int i = 0; i < 12; i++) baze[0][i] = c0[i];
		 int c1[12] = { 1,0,1,1,0,0,0,0,0,0,0,0, };
		 for (int i = 0; i < 12; i++) baze[1][i] = c1[i];
		 int c2[12] = { 0,0,1,0,1,1,0,0,0,0,0,0, };
		 for (int i = 0; i < 12; i++) baze[2][i] = c2[i];
		 int c3[12] = { 0,0,0,0,1,0,1,1,0,0,0,0, };
		 for (int i = 0; i < 12; i++) baze[3][i] = c3[i];
		 int c4[12] = { 0,0,0,0,0,0,1,0,1,1,0,0, };
		 for (int i = 0; i < 12; i++) baze[4][i] = c4[i];
		 int c5[12] = { 0,0,0,0,0,0,0,0,1,0,1,1, };
		 for (int i = 0; i < 12; i++) baze[5][i] = c5[i];
		 int c6[12] = { 1,1,0,0,0,0,0,0,0,0,1,0, };
		 for (int i = 0; i < 12; i++) baze[6][i] = c6[i];

		 //10 11 00 00 00 00
		 //00 10 11 00 00 00
		 //00 00 10 11 00 00
		 //00 00 00 10 11 00
		 //00 00 00 00 10 11
		 //
		 //2->  (0 0 1 2 0 0) -> (00 00 10 11 00 00)
		 //3->  (0 1 2 0 0 0) -> (00 10 11 00 00 00)
		 //4->  (0 0 0 0 1 2) -> (00 00 00 00 10 11)
		 //5->  (2 0 0 0 0 1) -> (11 00 00 00 00 10)
		 //6->  (0 0 0 1 2 0) -> (00 00 00 10 11 00)


		 int a0[6] = { 0,0,0,0,0,0 };
		 for (int i = 0; i < 6; i++) CYCL[0][i] = a0[i];

		 int a1[6] = { 1,2,3,4,5,6 };
		 for (int i = 0; i < 6; i++) CYCL[1][i] = a1[i];
		 int a2[6] = { 3,4,5,6,1,2 };
		 for (int i = 0; i < 6; i++) CYCL[2][i] = a2[i];
		 int a3[6] = { 2,3,4,5,6,1, };
		 for (int i = 0; i < 6; i++) CYCL[3][i] = a3[i];
		 int a4[6] = { 5,6,1,2,3,4 };
		 for (int i = 0; i < 6; i++) CYCL[4][i] = a4[i];
		 int a5[6] = { 6,1,2,3,4,5, };
		 for (int i = 0; i < 6; i++) CYCL[5][i] = a5[i];
		 int a6[6] = { 4,5,6,1,2,3, };
		 for (int i = 0; i < 6; i++) CYCL[6][i] = a6[i];


		 INV[0] = 0; INV[1] = 1; INV[2] = 4; INV[3] = 5; INV[4] = 2; INV[5] = 3; INV[6] = 6;
		 NEG[0] = 0; NEG[1] = 6; NEG[2] = 5; NEG[3] = 4; NEG[4] = 3; NEG[5] = 2; NEG[6] = 1;
		 TABTEG=3;

	 }

	 /**/
	 if (5 == q) {
		 ADD[0][0] = 0; ADD[1][0] = 1; ADD[2][0] = 2; ADD[3][0] = 3; ADD[4][0] = 4;
		 ADD[0][1] = 1; ADD[1][1] = 2; ADD[2][1] = 3; ADD[3][1] = 4; ADD[4][1] = 0;
		 ADD[0][2] = 2; ADD[1][2] = 3; ADD[2][2] = 4; ADD[3][2] = 0; ADD[4][2] = 1;
		 ADD[0][3] = 3; ADD[1][3] = 4; ADD[2][3] = 0; ADD[3][3] = 1; ADD[4][3] = 2;
		 ADD[0][4] = 4; ADD[1][4] = 0; ADD[2][4] = 1; ADD[3][4] = 2; ADD[4][4] = 3;

		 MUL[0][0] = 0; MUL[1][0] = 0; MUL[2][0] = 0; MUL[3][0] = 0; MUL[4][0] = 0;
		 MUL[0][1] = 0; MUL[1][1] = 1; MUL[2][1] = 2; MUL[3][1] = 3; MUL[4][1] = 4;
		 MUL[0][2] = 0; MUL[1][2] = 2; MUL[2][2] = 4; MUL[3][2] = 1; MUL[4][2] = 3;
		 MUL[0][3] = 0; MUL[1][3] = 3; MUL[2][3] = 1; MUL[3][3] = 4; MUL[4][3] = 2;
		 MUL[0][4] = 0; MUL[1][4] = 4; MUL[2][4] = 3; MUL[3][4] = 2; MUL[4][4] = 1;

		 int c0[8] = { 0,0,0,0,0,0,0,0, };
		 for (int i = 0; i < 8; i++) baze[0][i] = c0[i];
		 int c1[8] = { 1,0,1,1,0,0,0,0, };
		 for (int i = 0; i < 8; i++) baze[1][i] = c1[i];
		 int c2[8] = { 0,0,1,0,1,1,0,0, };
		 for (int i = 0; i < 8; i++) baze[2][i] = c2[i];
		 int c3[8] = { 0,0,0,0,1,0,1,1, };
		 for (int i = 0; i < 8; i++) baze[3][i] = c3[i];
		 int c4[8] = { 1,1,0,0,0,0,1,0, };
		 for (int i = 0; i < 8; i++) baze[4][i] = c4[i];

		 int a0[4] = { 0,0,0,0, };
		 for (int i = 0; i < 4; i++) CYCL[0][i] = a0[i];

		 int a1[4] = { 1,2,3,4, };
		 for (int i = 0; i < 4; i++) CYCL[1][i] = a1[i];
		 int a2[4] = { 2,3,4,1, };
		 for (int i = 0; i < 4; i++) CYCL[2][i] = a2[i];
		 int a3[4] = { 4,1,2,3, };
		 for (int i = 0; i < 4; i++) CYCL[3][i] = a3[i];
		 int a4[4] = { 3,4,1,2, };
		 for (int i = 0; i < 4; i++) CYCL[4][i] = a4[i];


		 /*int a1[4] = { 1,2,3,4, };
		 for (int i = 0; i < 4; i++) CYCL[1][i] = a1[i];
		 int a2[4] = { 2,3,4,1, };
		 for (int i = 0; i < 4; i++) CYCL[2][i] = a2[i];
		 int a3[4] =  { 3,4,1,2, };
		 for (int i = 0; i < 4; i++) CYCL[3][i] = a3[i];
		 int a4[4] ={ 4,1,2,3, };
		 for (int i = 0; i < 4; i++) CYCL[4][i] = a4[i];
*/

		 INV[0] = 0; INV[1] = 1; INV[2] = 3; INV[3] = 2; INV[4] = 4;
		 NEG[0] = 0; NEG[1] = 4; NEG[2] = 3; NEG[3] = 2; NEG[4] = 1;
		 TABTEG=3;
		 /**/
	 }

	 if (13 == q) {
		 ADD[ 0][ 0]   = 0; ADD[ 0][ 1]  = 1; ADD[ 0][ 2]  = 2; ADD[ 0][ 3]  = 3; ADD[ 0][ 4]  = 4; ADD[ 0][ 5]  = 5;
		 ADD[ 0][ 6]  = 6; ADD[ 0][ 7]  = 7; ADD[ 0][ 8]  = 8; ADD[ 0][ 9]  = 9; ADD[ 0][ 10]  = 10; ADD[ 0][ 11]  = 11; ADD[ 0][ 12]  = 12;
		 ADD[1][ 0]  = 1; ADD[1][ 1]  = 2; ADD[1][ 2]  = 3; ADD[1][ 3]  = 4; ADD[1][ 4]  = 5; ADD[1][ 5]  = 6; ADD[1][ 6]  = 7;
		 ADD[1][ 7]  = 8; ADD[1][ 8]  = 9; ADD[1][ 9]  = 10; ADD[1][ 10]  = 11; ADD[1][ 11]  = 12; ADD[1][ 12]  = 0;
		 ADD[2][ 0]  = 2; ADD[2][ 1]  = 3; ADD[2][ 2]  = 4; ADD[2][ 3]  = 5; ADD[2][ 4]  = 6; ADD[2][ 5]  = 7;
		 ADD[2][ 6]  = 8; ADD[2][ 7]  = 9; ADD[2][ 8]  = 10; ADD[2][ 9]  = 11; ADD[2][ 10]  = 12; ADD[2][ 11]  = 0; ADD[2][ 12]  = 1;
		 ADD[3][ 0]  = 3; ADD[3][ 1]  = 4; ADD[3][ 2]  = 5; ADD[3][ 3]  = 6; ADD[3][ 4]  = 7; ADD[3][ 5]  = 8; ADD[3][ 6]  = 9;
		 ADD[3][ 7]  = 10; ADD[3][ 8]  = 11; ADD[3][ 9]  = 12; ADD[3][ 10]  = 0; ADD[3][ 11]  = 1; ADD[3][ 12]  = 2;
		 ADD[4][ 0]  = 4; ADD[4][ 1]  = 5; ADD[4][ 2]  = 6; ADD[4][ 3]  = 7; ADD[4][ 4]  = 8; ADD[4][ 5]  = 9;
		 ADD[4][ 6]  = 10; ADD[4][ 7]  = 11; ADD[4][ 8]  = 12; ADD[4][ 9]  = 0; ADD[4][ 10]  = 1; ADD[4][ 11]  = 2; ADD[4][ 12]  = 3;
		 ADD[5][ 0]  = 5; ADD[5][ 1]  = 6; ADD[5][ 2]  = 7; ADD[5][ 3]  = 8; ADD[5][ 4]  = 9; ADD[5][ 5]  = 10; ADD[5][ 6]  = 11;
		 ADD[5][ 7]  = 12; ADD[5][ 8]  = 0; ADD[5][ 9]  = 1; ADD[5][ 10]  = 2; ADD[5][ 11]  = 3; ADD[5][ 12]  = 4;
		 ADD[6][ 0]  = 6; ADD[6][ 1]  = 7; ADD[6][ 2]  = 8; ADD[6][ 3]  = 9; ADD[6][ 4]  = 10; ADD[6][ 5]  = 11;
		 ADD[6][ 6]  = 12; ADD[6][ 7]  = 0; ADD[6][ 8]  = 1; ADD[6][ 9]  = 2; ADD[6][ 10]  = 3; ADD[6][ 11]  = 4; ADD[6][ 12]  = 5;
		 ADD[7][ 0]  = 7; ADD[7][ 1]  = 8; ADD[7][ 2]  = 9; ADD[7][ 3]  = 10; ADD[7][ 4]  = 11; ADD[7][ 5]  = 12; ADD[7][ 6]  = 0;
		 ADD[7][ 7]  = 1; ADD[7][ 8]  = 2; ADD[7][ 9]  = 3; ADD[7][ 10]  = 4; ADD[7][ 11]  = 5; ADD[7][ 12]  = 6;
		 ADD[8][ 0]  = 8; ADD[8][ 1]  = 9; ADD[8][ 2]  = 10; ADD[8][ 3]  = 11; ADD[8][ 4]  = 12; ADD[8][ 5]  = 0;
		 ADD[8][ 6]  = 1; ADD[8][ 7]  = 2; ADD[8][ 8]  = 3; ADD[8][ 9]  = 4; ADD[8][ 10]  = 5; ADD[8][ 11]  = 6; ADD[8][ 12]  = 7;
		 ADD[9][ 0]  = 9; ADD[9][ 1]  = 10; ADD[9][ 2]  = 11; ADD[9][ 3]  = 12; ADD[9][ 4]  = 0; ADD[9][ 5]  = 1;
		 ADD[9][ 6]  = 2; ADD[9][ 7]  = 3; ADD[9][ 8]  = 4; ADD[9][ 9]  = 5; ADD[9][ 10]  = 6; ADD[9][ 11]  = 7; ADD[9][ 12]  = 8;
		 ADD[10][ 0]  = 10; ADD[10][ 1]  = 11; ADD[10][ 2]  = 12; ADD[10][ 3]  = 0; ADD[10][ 4]  = 1; ADD[10][ 5]  = 2;
		 ADD[10][ 6]  = 3; ADD[10][ 7]  = 4; ADD[10][ 8]  = 5; ADD[10][ 9]  = 6; ADD[10][ 10]  = 7; ADD[10][ 11]  = 8; ADD[10][ 12]  = 9;
		 ADD[11][ 0]  = 11; ADD[11][ 1]  = 12; ADD[11][ 2]  = 0; ADD[11][ 3]  = 1; ADD[11][ 4]  = 2; ADD[11][ 5]  = 3; ADD[11][ 6]  = 4;
		 ADD[11][ 7]  = 5; ADD[11][ 8]  = 6; ADD[11][ 9]  = 7; ADD[11][ 10]  = 8; ADD[11][ 11]  = 9; ADD[11][ 12]  = 10;
		 ADD[12][ 0]  = 12; ADD[12][ 1]  = 0; ADD[12][ 2]  = 1; ADD[12][ 3]  = 2; ADD[12][ 4]  = 3; ADD[12][ 5]  = 4;
		 ADD[12][ 6]  = 5; ADD[12][ 7]  = 6; ADD[12][ 8]  = 7; ADD[12][ 9]  = 8; ADD[12][ 10]  = 9; ADD[12][ 11]  = 10; ADD[12][ 12]  = 11;
		 NEG[0]  = 0; NEG[1]  = 12; NEG[2]  = 11; NEG[3]  = 10; NEG[4]  = 9; NEG[5]  = 8; NEG[6]  = 7; NEG[7]  = 6; NEG[8]  = 5;
		 NEG[9]  = 4; NEG[10]  = 3; NEG[11]  = 2; NEG[12]  = 1;
		 MUL[ 0][ 0]  = 0; MUL[ 0][ 1]  = 0; MUL[ 0][ 2]  = 0; MUL[ 0][ 3]  = 0; MUL[ 0][ 4]  = 0; MUL[ 0][ 5]  = 0; MUL[ 0][ 6]  = 0;
		 MUL[ 0][ 7]  = 0; MUL[ 0][ 8]  = 0; MUL[ 0][ 9]  = 0; MUL[ 0][ 10]  = 0; MUL[ 0][ 11]  = 0; MUL[ 0][ 12]  = 0;
		 MUL[1][ 0]  = 0; MUL[1][ 1]  = 1; MUL[1][ 2]  = 2; MUL[1][ 3]  = 3; MUL[1][ 4]  = 4; MUL[1][ 5]  = 5; MUL[1][ 6]  = 6;
		 MUL[1][ 7]  = 7; MUL[1][ 8]  = 8; MUL[1][ 9]  = 9; MUL[1][ 10]  = 10; MUL[1][ 11]  = 11; MUL[1][ 12]  = 12;
		 MUL[2][ 0]  = 0; MUL[2][ 1]  = 2; MUL[2][ 2]  = 4; MUL[2][ 3]  = 6; MUL[2][ 4]  = 8; MUL[2][ 5]  = 10;
		 MUL[2][ 6]  = 12; MUL[2][ 7]  = 1; MUL[2][ 8]  = 3; MUL[2][ 9]  = 5; MUL[2][ 10]  = 7; MUL[2][ 11]  = 9; MUL[2][ 12]  = 11;
		 MUL[3][ 0]  = 0; MUL[3][ 1]  = 3; MUL[3][ 2]  = 6; MUL[3][ 3]  = 9; MUL[3][ 4]  = 12; MUL[3][ 5]  = 2; MUL[3][ 6]  = 5;
		 MUL[3][ 7]  = 8; MUL[3][ 8]  = 11; MUL[3][ 9]  = 1; MUL[3][ 10]  = 4; MUL[3][ 11]  = 7; MUL[3][ 12]  = 10;
		 MUL[4][ 0]  = 0; MUL[4][ 1]  = 4; MUL[4][ 2]  = 8; MUL[4][ 3]  = 12; MUL[4][ 4]  = 3; MUL[4][ 5]  = 7;
		 MUL[4][ 6]  = 11; MUL[4][ 7]  = 2; MUL[4][ 8]  = 6; MUL[4][ 9]  = 10; MUL[4][ 10]  = 1; MUL[4][ 11]  = 5; MUL[4][ 12]  = 9;
		 MUL[5][ 0]  = 0; MUL[5][ 1]  = 5; MUL[5][ 2]  = 10; MUL[5][ 3]  = 2; MUL[5][ 4]  = 7; MUL[5][ 5]  = 12; MUL[5][ 6]  = 4;
		 MUL[5][ 7]  = 9; MUL[5][ 8]  = 1; MUL[5][ 9]  = 6; MUL[5][ 10]  = 11; MUL[5][ 11]  = 3; MUL[5][ 12]  = 8;
		 MUL[6][ 0]  = 0; MUL[6][ 1]  = 6; MUL[6][ 2]  = 12; MUL[6][ 3]  = 5; MUL[6][ 4]  = 11; MUL[6][ 5]  = 4;
		 MUL[6][ 6]  = 10; MUL[6][ 7]  = 3; MUL[6][ 8]  = 9; MUL[6][ 9]  = 2; MUL[6][ 10]  = 8; MUL[6][ 11]  = 1; MUL[6][ 12]  = 7;
		 MUL[7][ 0]  = 0; MUL[7][ 1]  = 7; MUL[7][ 2]  = 1; MUL[7][ 3]  = 8; MUL[7][ 4]  = 2; MUL[7][ 5]  = 9; MUL[7][ 6]  = 3;
		 MUL[7][ 7]  = 10; MUL[7][ 8]  = 4; MUL[7][ 9]  = 11; MUL[7][ 10]  = 5; MUL[7][ 11]  = 12; MUL[7][ 12]  = 6;
		 MUL[8][ 0]  = 0; MUL[8][ 1]  = 8; MUL[8][ 2]  = 3; MUL[8][ 3]  = 11; MUL[8][ 4]  = 6; MUL[8][ 5]  = 1;
		 MUL[8][ 6]  = 9; MUL[8][ 7]  = 4; MUL[8][ 8]  = 12; MUL[8][ 9]  = 7; MUL[8][ 10]  = 2; MUL[8][ 11]  = 10; MUL[8][ 12]  = 5;
		 MUL[9][ 0]  = 0; MUL[9][ 1]  = 9; MUL[9][ 2]  = 5; MUL[9][ 3]  = 1; MUL[9][ 4]  = 10; MUL[9][ 5]  = 6; MUL[9][ 6]  = 2;
		 MUL[9][ 7]  = 11; MUL[9][ 8]  = 7; MUL[9][ 9]  = 3; MUL[9][ 10]  = 12; MUL[9][ 11]  = 8; MUL[9][ 12]  = 4;
		 MUL[10][ 0]  = 0; MUL[10][ 1]  = 10; MUL[10][ 2]  = 7; MUL[10][ 3]  = 4; MUL[10][ 4]  = 1; MUL[10][ 5]  = 11;
		 MUL[10][ 6]  = 8; MUL[10][ 7]  = 5; MUL[10][ 8]  = 2; MUL[10][ 9]  = 12; MUL[10][ 10]  = 9; MUL[10][ 11]  = 6; MUL[10][ 12]  = 3;
		 MUL[11][ 0]  = 0; MUL[11][ 1]  = 11; MUL[11][ 2]  = 9; MUL[11][ 3]  = 7; MUL[11][ 4]  = 5; MUL[11][ 5]  = 3; MUL[11][ 6]  = 1;
		 MUL[11][ 7]  = 12; MUL[11][ 8]  = 10; MUL[11][ 9]  = 8; MUL[11][ 10]  = 6; MUL[11][ 11]  = 4; MUL[11][ 12]  = 2;
		 MUL[12][ 0]  = 0; MUL[12][ 1]  = 12; MUL[12][ 2]  = 11; MUL[12][ 3]  = 10; MUL[12][ 4]  = 9; MUL[12][ 5]  = 8;
		 MUL[12][ 6]  = 7; MUL[12][ 7]  = 6; MUL[12][ 8]  = 5; MUL[12][ 9]  = 4; MUL[12][ 10]  = 3; MUL[12][ 11]  = 2; MUL[12][ 12]  = 1;
		 INV[1]  = 1; INV[2]  = 7; INV[3]  = 9; INV[4]  = 10; INV[5]  = 8; INV[6]  = 11; INV[7]  = 2; INV[8]  = 5; INV[9]  = 3;
		 INV[10]  = 4; INV[11]  = 6; INV[12]  = 12;

	 }

	 if (16 == q) {
		 ADD[0][ 0] = 0; ADD[0][ 1] = 1; ADD[0][ 2] = 2; ADD[0][ 3] = 3; ADD[0][ 4] = 4; ADD[0][ 5] = 5; ADD[0][ 6] = 6; ADD[0][ 7] = 7; ADD[0][ 8] = 8;
		 ADD[0][ 9] = 9; ADD[0][ 10] = 10; ADD[0][ 11] = 11; ADD[0][ 12] = 12; ADD[0][ 13] = 13; ADD[0][14] = 14; ADD[0][15] = 15;
		 ADD[1][0] = 1; ADD[1][1] = 0; ADD[1][2] = 3; ADD[1][3] = 2; ADD[1][4] = 5; ADD[1][5] = 4; ADD[1][6] = 7; ADD[1][7] = 6;
		 ADD[1][8] = 9; ADD[1][9] = 8; ADD[1][10] = 11; ADD[1][11] = 10; ADD[1][12] = 13; ADD[1][13] = 12; ADD[1][14] = 15; ADD[1][15] = 14;
		 ADD[2][0] = 2; ADD[2][1] = 3; ADD[2][2] = 0; ADD[2][3] = 1; ADD[2][4] = 6; ADD[2][5] = 7; ADD[2][6] = 4; ADD[2][7] = 5; ADD[2][8] = 10;
		 ADD[2][9] = 11; ADD[2][10] = 8; ADD[2][11] = 9; ADD[2][12] = 14; ADD[2][13] = 15; ADD[2][14] = 12; ADD[2][15] = 13;
		 ADD[3][0] = 3; ADD[3][1] = 2; ADD[3][2] = 1; ADD[3][3] = 0; ADD[3][4] = 7; ADD[3][5] = 6; ADD[3][6] = 5; ADD[3][7] = 4;
		 ADD[3][8] = 11; ADD[3][9] = 10; ADD[3][10] = 9; ADD[3][11] = 8; ADD[3][12] = 15; ADD[3][13] = 14; ADD[3][14] = 13; ADD[3][15] = 12;
		 ADD[4][0] = 4; ADD[4][1] = 5; ADD[4][2] = 6; ADD[4][3] = 7; ADD[4][4] = 0; ADD[4][5] = 1; ADD[4][6] = 2; ADD[4][7] = 3; ADD[4][8] = 12;
		 ADD[4][9] = 13; ADD[4][10] = 14; ADD[4][11] = 15; ADD[4][12] = 8; ADD[4][13] = 9; ADD[4][14] = 10; ADD[4][15] = 11;
		 ADD[5][0] = 5; ADD[5][1] = 4; ADD[5][2] = 7; ADD[5][3] = 6; ADD[5][4] = 1; ADD[5][5] = 0; ADD[5][6] = 3; ADD[5][7] = 2;
		 ADD[5][8] = 13; ADD[5][9] = 12; ADD[5][10] = 15; ADD[5][11] = 14; ADD[5][12] = 9; ADD[5][13] = 8; ADD[5][14] = 11; ADD[5][15] = 10;
		 ADD[6][0] = 6; ADD[6][1] = 7; ADD[6][2] = 4; ADD[6][3] = 5; ADD[6][4] = 2; ADD[6][5] = 3; ADD[6][6] = 0; ADD[6][7] = 1; ADD[6][8] = 14;
		 ADD[6][9] = 15; ADD[6][10] = 12; ADD[6][11] = 13; ADD[6][12] = 10; ADD[6][13] = 11; ADD[6][14] = 8; ADD[6][15] = 9;
		 ADD[7][0] = 7; ADD[7][1] = 6; ADD[7][2] = 5; ADD[7][3] = 4; ADD[7][4] = 3; ADD[7][5] = 2; ADD[7][6] = 1; ADD[7][7] = 0;
		 ADD[7][8] = 15; ADD[7][9] = 14; ADD[7][10] = 13; ADD[7][11] = 12; ADD[7][12] = 11; ADD[7][13] = 10; ADD[7][14] = 9; ADD[7][15] = 8;
		 ADD[8][0] = 8; ADD[8][1] = 9; ADD[8][2] = 10; ADD[8][3] = 11; ADD[8][4] = 12; ADD[8][5] = 13; ADD[8][6] = 14; ADD[8][7] = 15;
		 ADD[8][8] = 0; ADD[8][9] = 1; ADD[8][10] = 2; ADD[8][11] = 3; ADD[8][12] = 4; ADD[8][13] = 5; ADD[8][14] = 6; ADD[8][15] = 7;
		 ADD[9][0] = 9; ADD[9][1] = 8; ADD[9][2] = 11; ADD[9][3] = 10; ADD[9][4] = 13; ADD[9][5] = 12; ADD[9][6] = 15; ADD[9][7] = 14;
		 ADD[9][8] = 1; ADD[9][9] = 0; ADD[9][10] = 3; ADD[9][11] = 2; ADD[9][12] = 5; ADD[9][13] = 4; ADD[9][14] = 7; ADD[9][15] = 6;
		 ADD[10][0] = 10; ADD[10][1] = 11; ADD[10][2] = 8; ADD[10][3] = 9; ADD[10][4] = 14; ADD[10][5] = 15; ADD[10][6] = 12; ADD[10][7] = 13;
		 ADD[10][8] = 2; ADD[10][9] = 3; ADD[10][10] = 0; ADD[10][11] = 1; ADD[10][12] = 6; ADD[10][13] = 7; ADD[10][14] = 4; ADD[10][15] = 5;
		 ADD[11][0] = 11; ADD[11][1] = 10; ADD[11][2] = 9; ADD[11][3] = 8; ADD[11][4] = 15; ADD[11][5] = 14; ADD[11][6] = 13; ADD[11][7] = 12;
		 ADD[11][8] = 3; ADD[11][9] = 2; ADD[11][10] = 1; ADD[11][11] = 0; ADD[11][12] = 7; ADD[11][13] = 6; ADD[11][14] = 5; ADD[11][15] = 4;
		 ADD[12][0] = 12; ADD[12][1] = 13; ADD[12][2] = 14; ADD[12][3] = 15; ADD[12][4] = 8; ADD[12][5] = 9; ADD[12][6] = 10; ADD[12][7] = 11;
		 ADD[12][8] = 4; ADD[12][9] = 5; ADD[12][10] = 6; ADD[12][11] = 7; ADD[12][12] = 0; ADD[12][13] = 1; ADD[12][14] = 2; ADD[12][15] = 3;
		 ADD[13][0] = 13; ADD[13][1] = 12; ADD[13][2] = 15; ADD[13][3] = 14; ADD[13][4] = 9; ADD[13][5] = 8; ADD[13][6] = 11; ADD[13][7] = 10;
		 ADD[13][8] = 5; ADD[13][9] = 4; ADD[13][10] = 7; ADD[13][11] = 6; ADD[13][12] = 1; ADD[13][13] = 0; ADD[13][14] = 3; ADD[13][15] = 2;
		 ADD[14][0] = 14; ADD[14][1] = 15; ADD[14][2] = 12; ADD[14][3] = 13; ADD[14][4] = 10; ADD[14][5] = 11; ADD[14][6] = 8; ADD[14][7] = 9;
		 ADD[14][8] = 6; ADD[14][9] = 7; ADD[14][10] = 4; ADD[14][11] = 5; ADD[14][12] = 2; ADD[14][13] = 3; ADD[14][14] = 0; ADD[14][15] = 1;
		 ADD[15][0] = 15; ADD[15][1] = 14; ADD[15][2] = 13; ADD[15][3] = 12; ADD[15][4] = 11; ADD[15][5] = 10; ADD[15][6] = 9; ADD[15][7] = 8;
		 ADD[15][8] = 7; ADD[15][9] = 6; ADD[15][10] = 5; ADD[15][11] = 4; ADD[15][12] = 3; ADD[15][13] = 2; ADD[15][14] = 1; ADD[15][15] = 0;

		 MUL[0][0] = 0; MUL[0][1] = 0; MUL[0][2] = 0; MUL[0][3] = 0; MUL[0][4] = 0; MUL[0][5] = 0; MUL[0][6] = 0; MUL[0][7] = 0; MUL[0][8] = 0;
		 MUL[0][9] = 0; MUL[0][10] = 0; MUL[0][11] = 0; MUL[0][12] = 0; MUL[0][13] = 0; MUL[0][14] = 0; MUL[0][15] = 0;
		 MUL[1][0] = 0; MUL[1][1] = 1; MUL[1][2] = 2; MUL[1][3] = 3; MUL[1][4] = 4; MUL[1][5] = 5; MUL[1][6] = 6; MUL[1][7] = 7;
		 MUL[1][8] = 8; MUL[1][9] = 9; MUL[1][10] = 10; MUL[1][11] = 11; MUL[1][12] = 12; MUL[1][13] = 13; MUL[1][14] = 14; MUL[1][15] = 15;
		 MUL[2][0] = 0; MUL[2][1] = 2; MUL[2][2] = 4; MUL[2][3] = 6; MUL[2][4] = 8; MUL[2][5] = 10; MUL[2][6] = 12; MUL[2][7] = 14;
		 MUL[2][8] = 3; MUL[2][9] = 1; MUL[2][10] = 7; MUL[2][11] = 5; MUL[2][12] = 11; MUL[2][13] = 9; MUL[2][14] = 15; MUL[2][15] = 13;
		 MUL[3][0] = 0; MUL[3][1] = 3; MUL[3][2] = 6; MUL[3][3] = 5; MUL[3][4] = 12; MUL[3][5] = 15; MUL[3][6] = 10; MUL[3][7] = 9;
		 MUL[3][8] = 11; MUL[3][9] = 8; MUL[3][10] = 13; MUL[3][11] = 14; MUL[3][12] = 7; MUL[3][13] = 4; MUL[3][14] = 1; MUL[3][15] = 2;
		 MUL[4][0] = 0; MUL[4][1] = 4; MUL[4][2] = 8; MUL[4][3] = 12; MUL[4][4] = 3; MUL[4][5] = 7; MUL[4][6] = 11; MUL[4][7] = 15;
		 MUL[4][8] = 6; MUL[4][9] = 2; MUL[4][10] = 14; MUL[4][11] = 10; MUL[4][12] = 5; MUL[4][13] = 1; MUL[4][14] = 13; MUL[4][15] = 9;
		 MUL[5][0] = 0; MUL[5][1] = 5; MUL[5][2] = 10; MUL[5][3] = 15; MUL[5][4] = 7; MUL[5][5] = 2; MUL[5][6] = 13; MUL[5][7] = 8;
		 MUL[5][8] = 14; MUL[5][9] = 11; MUL[5][10] = 4; MUL[5][11] = 1; MUL[5][12] = 9; MUL[5][13] = 12; MUL[5][14] = 3; MUL[5][15] = 6;
		 MUL[6][0] = 0; MUL[6][1] = 6; MUL[6][2] = 12; MUL[6][3] = 10; MUL[6][4] = 11; MUL[6][5] = 13; MUL[6][6] = 7; MUL[6][7] = 1;
		 MUL[6][8] = 5; MUL[6][9] = 3; MUL[6][10] = 9; MUL[6][11] = 15; MUL[6][12] = 14; MUL[6][13] = 8; MUL[6][14] = 2; MUL[6][15] = 4;
		 MUL[7][0] = 0; MUL[7][1] = 7; MUL[7][2] = 14; MUL[7][3] = 9; MUL[7][4] = 15; MUL[7][5] = 8; MUL[7][6] = 1; MUL[7][7] = 6;
		 MUL[7][8] = 13; MUL[7][9] = 10; MUL[7][10] = 3; MUL[7][11] = 4; MUL[7][12] = 2; MUL[7][13] = 5; MUL[7][14] = 12; MUL[7][15] = 11;
		 MUL[8][0] = 0; MUL[8][1] = 8; MUL[8][2] = 3; MUL[8][3] = 11; MUL[8][4] = 6; MUL[8][5] = 14; MUL[8][6] = 5; MUL[8][7] = 13;
		 MUL[8][8] = 12; MUL[8][9] = 4; MUL[8][10] = 15; MUL[8][11] = 7; MUL[8][12] = 10; MUL[8][13] = 2; MUL[8][14] = 9; MUL[8][15] = 1;
		 MUL[9][0] = 0; MUL[9][1] = 9; MUL[9][2] = 1; MUL[9][3] = 8; MUL[9][4] = 2; MUL[9][5] = 11; MUL[9][6] = 3; MUL[9][7] = 10;
		 MUL[9][8] = 4; MUL[9][9] = 13; MUL[9][10] = 5; MUL[9][11] = 12; MUL[9][12] = 6; MUL[9][13] = 15; MUL[9][14] = 7; MUL[9][15] = 14;
		 MUL[10][0] = 0; MUL[10][1] = 10; MUL[10][2] = 7; MUL[10][3] = 13; MUL[10][4] = 14; MUL[10][5] = 4; MUL[10][6] = 9; MUL[10][7] = 3;
		 MUL[10][8] = 15; MUL[10][9] = 5; MUL[10][10] = 8; MUL[10][11] = 2; MUL[10][12] = 1; MUL[10][13] = 11; MUL[10][14] = 6; MUL[10][15] = 12;
		 MUL[11][0] = 0; MUL[11][1] = 11; MUL[11][2] = 5; MUL[11][3] = 14; MUL[11][4] = 10; MUL[11][5] = 1; MUL[11][6] = 15; MUL[11][7] = 4;
		 MUL[11][8] = 7; MUL[11][9] = 12; MUL[11][10] = 2; MUL[11][11] = 9; MUL[11][12] = 13; MUL[11][13] = 6; MUL[11][14] = 8; MUL[11][15] = 3;
		 MUL[12][0] = 0; MUL[12][1] = 12; MUL[12][2] = 11; MUL[12][3] = 7; MUL[12][4] = 5; MUL[12][5] = 9; MUL[12][6] = 14; MUL[12][7] = 2;
		 MUL[12][8] = 10; MUL[12][9] = 6; MUL[12][10] = 1; MUL[12][11] = 13; MUL[12][12] = 15; MUL[12][13] = 3; MUL[12][14] = 4; MUL[12][15] = 8;
		 MUL[13][0] = 0; MUL[13][1] = 13; MUL[13][2] = 9; MUL[13][3] = 4; MUL[13][4] = 1; MUL[13][5] = 12; MUL[13][6] = 8; MUL[13][7] = 5;
		 MUL[13][8] = 2; MUL[13][9] = 15; MUL[13][10] = 11; MUL[13][11] = 6; MUL[13][12] = 3; MUL[13][13] = 14; MUL[13][14] = 10; MUL[13][15] = 7;
		 MUL[14][0] = 0; MUL[14][1] = 14; MUL[14][2] = 15; MUL[14][3] = 1; MUL[14][4] = 13; MUL[14][5] = 3; MUL[14][6] = 2; MUL[14][7] = 12;
		 MUL[14][8] = 9; MUL[14][9] = 7; MUL[14][10] = 6; MUL[14][11] = 8; MUL[14][12] = 4; MUL[14][13] = 10; MUL[14][14] = 11; MUL[14][15] = 5;
		 MUL[15][0] = 0; MUL[15][1] = 15; MUL[15][2] = 13; MUL[15][3] = 2; MUL[15][4] = 9; MUL[15][5] = 6; MUL[15][6] = 4; MUL[15][7] = 11;
		 MUL[15][8] = 1; MUL[15][9] = 14; MUL[15][10] = 12; MUL[15][11] = 3; MUL[15][12] = 8; MUL[15][13] = 7; MUL[15][14] = 5; MUL[15][15] = 10;

		 INV[1] = 1; INV[2] = 9; INV[3] = 14; INV[4] = 13; INV[5] = 11; INV[6] = 7; INV[7] = 6; INV[8] = 15; INV[9] = 2; INV[10] = 12;
		 INV[11] = 5; INV[12] = 10; INV[13] = 4; INV[14] = 3; INV[15] = 8;

		 NEG[0] = 0; NEG[1] = 1; NEG[2] = 2; NEG[3] = 3; NEG[4] = 4; NEG[5] = 5; NEG[6] = 6; NEG[7] = 7; NEG[8] = 8; NEG[9] = 9; NEG[10] = 10;
		 NEG[11] = 11; NEG[12] = 12; NEG[13] = 13; NEG[14] = 14; NEG[15] = 15;

		 /*(10 11 11 00 11 00 00 00 11 00 00 00 00 00 00)
		 2-> (0 1 2 2 0 2 0 0 0 2 0 0 0 0 0) -> (00 10 11 11 00 11 00 00 00 11 00 00 00 00 00)
		 3-> (0 0 1 2 2 0 2 0 0 0 2 0 0 0 0) -> (00 00 10 11 11 00 11 00 00 00 11 00 00 00 00)
		 4-> (0 0 0 1 2 2 0 2 0 0 0 2 0 0 0) -> (00 00 00 10 11 11 00 11 00 00 00 11 00 00 00)
		 5-> (0 0 0 0 1 2 2 0 2 0 0 0 2 0 0) -> (00 00 00 00 10 11 11 00 11 00 00 00 11 00 00)
		 6-> (0 0 0 0 0 1 2 0 0 2 0 0 0 2 0) -> (00 00 00 00 00 10 11 11 00 11 00 00 00 11 00)
		 7-> (0 0 0 0 0 0 1 2 0 0 2 0 0 0 2) -> (00 00 00 00 00 00 10 11 11 00 11 00 00 00 11)
		 8-> (2 0 0 0 0 0 0 1 2 0 0 2 0 0 0) -> (11 00 00 00 00 00 00 10 11 11 00 11 00 00 00)
		 9-> (0 2 0 0 0 0 0 0 1 2 0 0 2 0 0) -> (00 11 00 00 00 00 00 00 10 11 11 00 11 00 00)
		 A-> (0 0 2 0 0 0 0 0 0 1 2 0 0 2 0) -> (00 00 11 00 00 00 00 00 00 10 11 11 00 11 00)
		 B-> (0 0 0 2 0 0 0 0 0 0 1 2 0 0 2) -> (00 00 11 00 00 00 00 00 00 00 10 11 11 00 11)
		 C-> (2 0 0 0 2 0 0 0 0 0 0 1 2 0 0) -> (11 00 00 11 00 00 00 00 00 00 00 10 11 11 00)
		 D-> (0 2 0 0 0 2 0 0 0 0 0 0 1 2 0) -> (00 11 00 00 11 00 00 00 00 00 00 00 10 11 11)
		 E-> (0 0 2 0 0 0 2 0 0 0 0 0 0 1 2) -> (11 00 11 00 00 11 00 00 00 00 00 00 00 10 11)
		 F-> (2 0 0 2 0 0 0 2 0 0 0 0 0 0 1) -> (11 11 00 11 00 00 11 00 00 00 00 00 00 00 10)*/

		 int c0[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, };
		 for (int i = 0; i < 30; i++) baze[0][i] = c0[i];
		 int c1[30] = { 1,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0, };
		 for (int i = 0; i < 30; i++) baze[1][i] = c1[i];
		 int c2[30] = { 0,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0, };
		 for (int i = 0; i < 30; i++) baze[2][i] = c2[i];
		 int c3[30] = { 0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0, };
		 for (int i = 0; i < 30; i++) baze[3][i] = c3[i];
		 int c4[30] = { 0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0, };
		 for (int i = 0; i < 30; i++) baze[4][i] = c4[i];
		 int c5[30] = { 0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0, };
		 for (int i = 0; i < 30; i++) baze[5][i] = c5[i];
		 int c6[30] = { 0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0, };
		 for (int i = 0; i < 30; i++) baze[6][i] = c6[i];
		 int c7[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1, };
		 for (int i = 0; i < 30; i++) baze[7][i] = c7[i];
		 int c8[30] = { 1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0,0,0, };
		 for (int i = 0; i < 30; i++) baze[8][i] = c8[i];
		 int c9[30] = { 0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,0,0,0, };
		 for (int i = 0; i < 30; i++) baze[9][i] = c9[i];
		 int c10[30] = { 0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,0, };
		 for (int i = 0; i < 30; i++) baze[10][i] = c10[i];
		 int c11[30] = { 0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1, };
		 for (int i = 0; i < 30; i++) baze[11][i] = c11[i];
		 int c12[30] = { 1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0, };
		 for (int i = 0; i < 30; i++) baze[12][i] = c12[i];
		 int c13[30] = { 0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1, };
		 for (int i = 0; i < 30; i++) baze[13][i] = c13[i];
		 int c14[30] = { 1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1, };
		 for (int i = 0; i < 30; i++) baze[14][i] = c14[i];
		 int c15[30] = { 1,1,1,1,0,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0, };
		 for (int i = 0; i < 30; i++) baze[15][i] = c15[i];

		 int a0[15] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, };
		 for (int i = 0; i < 15; i++) CYCL[0][i] = a0[i];

		 int a1[15] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15, };
		 for (int i = 0; i < 15; i++) CYCL[1][i] = a1[i];
		 int a2[15] = { 2,3,4,5,6,7,8,9,10,11,12,13,14,15,1, };
		 for (int i = 0; i < 15; i++) CYCL[2][i] = a2[i];
		 int a3[15] = { 3,4,5,6,7,8,9,10,11,12,13,14,15,1,2, };
		 for (int i = 0; i < 15; i++) CYCL[3][i] = a3[i];
		 int a4[15] = { 4,5,6,7,8,9,10,11,12,13,14,15,1,2,3, };
		 for (int i = 0; i < 15; i++) CYCL[4][i] = a4[i];
		 int a5[15] = { 5,6,7,8,9,10,11,12,13,14,15,1,2,3,4, };
		 for (int i = 0; i < 15; i++) CYCL[5][i] = a5[i];
		 int a6[15] = { 6,7,8,9,10,11,12,13,14,15,1,2,3,4,5, };
		 for (int i = 0; i < 15; i++) CYCL[6][i] = a6[i];
		 int a7[15] = { 7,8,9,10,11,12,13,14,15,1,2,3,4,5,6, };
		 for (int i = 0; i < 15; i++) CYCL[7][i] = a7[i];
		 int a8[15] = { 8,9,10,11,12,13,14,15,1,2,3,4,5,6,7, };
		 for (int i = 0; i < 15; i++) CYCL[8][i] = a8[i];
		 int a9[15] = { 9,10,11,12,13,14,15,1,2,3,4,5,6,7,8, };
		 for (int i = 0; i < 15; i++) CYCL[9][i] = a9[i];
		 int a10[15] = { 10,11,12,13,14,15,1,2,3,4,5,6,7,8,9, };
		 for (int i = 0; i < 15; i++) CYCL[10][i] = a10[i];
		 int a11[15] = { 11,12,13,14,15,1,2,3,4,5,6,7,8,9,10, };
		 for (int i = 0; i < 15; i++) CYCL[11][i] = a11[i];
		 int a12[15] = { 12,13,14,15,1,2,3,4,5,6,7,8,9,10,11, };
		 for (int i = 0; i < 15; i++) CYCL[12][i] = a12[i];
		 int a13[15] = { 13,14,15,1,2,3,4,5,6,7,8,9,10,11,12, };
		 for (int i = 0; i < 15; i++) CYCL[13][i] = a13[i];
		 int a14[15] = { 14,15,1,2,3,4,5,6,7,8,9,10,11,12,13, };
		 for (int i = 0; i < 15; i++) CYCL[14][i] = a14[i];
		 int a15[15] = { 15,1,2,3,4,5,6,7,8,9,10,11,12,13,14, };
		 for (int i = 0; i < 15; i++) CYCL[15][i] = a15[i];

	 }

 }
/*
9
begin

{ new table}
ADD[ 0][0] =0;ADD[ 0][1] =1;ADD[ 0][2] =2;ADD[ 0][3] =3;ADD[ 0][4] =4;ADD[ 0][5] =5;ADD[ 0][6] =6;ADD[ 0][7] =7;ADD[ 0][8] =8;
ADD[1][0] =1;ADD[1][1] =5;ADD[1][2] =3;ADD[1][3] =8;ADD[1][4] =7;ADD[1][5] =0;ADD[1][6] =4;ADD[1][7] =6;ADD[1][8] =2;
ADD[2][0] =2;ADD[2][1] =3;ADD[2][2] =6;ADD[2][3] =4;ADD[2][4] =1;ADD[2][5] =8;ADD[2][6] =0;ADD[2][7] =5;ADD[2][8] =7;
ADD[3][0] =3;ADD[3][1] =8;ADD[3][2] =4;ADD[3][3] =7;ADD[3][4] =5;ADD[3][5] =2;ADD[3][6] =1;ADD[3][7] =0;ADD[3][8] =6;
ADD[4][0] =4;ADD[4][1] =7;ADD[4][2] =1;ADD[4][3] =5;ADD[4][4] =8;ADD[4][5] =6;ADD[4][6] =3;ADD[4][7] =2;ADD[4][8] =0;
ADD[5][0] =5;ADD[5][1] =0;ADD[5][2] =8;ADD[5][3] =2;ADD[5][4] =6;ADD[5][5] =1;ADD[5][6] =7;ADD[5][7] =4;ADD[5][8] =3;
ADD[6][0] =6;ADD[6][1] =4;ADD[6][2] =0;ADD[6][3] =1;ADD[6][4] =3;ADD[6][5] =7;ADD[6][6] =2;ADD[6][7] =8;ADD[6][8] =5;
ADD[7][0] =7;ADD[7][1] =6;ADD[7][2] =5;ADD[7][3] =0;ADD[7][4] =2;ADD[7][5] =4;ADD[7][6] =8;ADD[7][7] =3;ADD[7][8] =1;
ADD[8][0] =8;ADD[8][1] =2;ADD[8][2] =7;ADD[8][3] =6;ADD[8][4] =0;ADD[8][5] =3;ADD[8][6] =5;ADD[8][7] =1;ADD[8][8] =4;

NEG[0] =0;NEG[1] =5;NEG[2] =6;NEG[3] =7;NEG[4] =8;NEG[5] =1;NEG[6] =2;NEG[7] =3;NEG[8] =4; { }



MUL[ 0][0] =0;MUL[ 0][1] =0;MUL[ 0][2] =0;MUL[ 0][3] =0;MUL[ 0][4] =0;MUL[ 0][5] =0;MUL[ 0][6] =0;MUL[ 0][7] =0;MUL[ 0][8] =0;
MUL[1][0] =0;MUL[1][1] =1;MUL[1][2] =2;MUL[1][3] =3;MUL[1][4] =4;MUL[1][5] =5;MUL[1][6] =6;MUL[1][7] =7;MUL[1][8] =8;
MUL[2][0] =0;MUL[2][1] =2;MUL[2][2] =3;MUL[2][3] =4;MUL[2][4] =5;MUL[2][5] =6;MUL[2][6] =7;MUL[2][7] =8;MUL[2][8] =1;
MUL[3][0] =0;MUL[3][1] =3;MUL[3][2] =4;MUL[3][3] =5;MUL[3][4] =6;MUL[3][5] =7;MUL[3][6] =8;MUL[3][7] =1;MUL[3][8] =2;
MUL[4][0] =0;MUL[4][1] =4;MUL[4][2] =5;MUL[4][3] =6;MUL[4][4] =7;MUL[4][5] =8;MUL[4][6] =1;MUL[4][7] =2;MUL[4][8] =3;
MUL[5][0] =0;MUL[5][1] =5;MUL[5][2] =6;MUL[5][3] =7;MUL[5][4] =8;MUL[5][5] =1;MUL[5][6] =2;MUL[5][7] =3;MUL[5][8] =4;
MUL[6][0] =0;MUL[6][1] =6;MUL[6][2] =7;MUL[6][3] =8;MUL[6][4] =1;MUL[6][5] =2;MUL[6][6] =3;MUL[6][7] =4;MUL[6][8] =5;
MUL[7][0] =0;MUL[7][1] =7;MUL[7][2] =8;MUL[7][3] =1;MUL[7][4] =2;MUL[7][5] =3;MUL[7][6] =4;MUL[7][7] =5;MUL[7][8] =6;
MUL[8][0] =0;MUL[8][1] =8;MUL[8][2] =1;MUL[8][3] =2;MUL[8][4] =3;MUL[8][5] =4;MUL[8][6] =5;MUL[8][7] =6;MUL[8][8] =7;

INV[1] =1;INV[2] =8;INV[3] =7;INV[4] =6;INV[5] =5;INV[6] =4;INV[7] =3;INV[8] =2;
end;

8
begin



ADD[ 0][0] =0;ADD[ 0][1] =1;ADD[ 0][2] =2;ADD[ 0][3] =3;ADD[ 0][4] =4;ADD[ 0][5] =5;ADD[ 0][6] =6;ADD[ 0][7] =7;

ADD[1][0] =1;ADD[1][1] =0;ADD[1][2] =4;ADD[1][3] =7;ADD[1][4] =2;ADD[1][5] =6;ADD[1][6] =5;ADD[1][7] =3;

ADD[2][0] =2;ADD[2][1] =4;ADD[2][2] =0;ADD[2][3] =5;ADD[2][4] =1;ADD[2][5] =3;ADD[2][6] =7;ADD[2][7] =6;

ADD[3][0] =3;ADD[3][1] =7;ADD[3][2] =5;ADD[3][3] =0;ADD[3][4] =6;ADD[3][5] =2;ADD[3][6] =4;ADD[3][7] =1;

ADD[4][0] =4;ADD[4][1] =2;ADD[4][2] =1;ADD[4][3] =6;ADD[4][4] =0;ADD[4][5] =7;ADD[4][6] =3;ADD[4][7] =5;

ADD[5][0] =5;ADD[5][1] =6;ADD[5][2] =3;ADD[5][3] =2;ADD[5][4] =7;ADD[5][5] =0;ADD[5][6] =1;ADD[5][7] =4;

ADD[6][0] =6;ADD[6][1] =5;ADD[6][2] =7;ADD[6][3] =4;ADD[6][4] =3;ADD[6][5] =1;ADD[6][6] =0;ADD[6][7] =2;

ADD[7][0] =7;ADD[7][1] =3;ADD[7][2] =6;ADD[7][3] =1;ADD[7][4] =5;ADD[7][5] =4;ADD[7][6] =2;ADD[7][7] =0;


NEG[0] =0;NEG[1] =1;NEG[2] =2;NEG[3] =3;NEG[4] =4;NEG[5] =5;NEG[6] =6;NEG[7] =7;





MUL[ 0][0] =0;MUL[ 0][1] =0;MUL[ 0][2] =0;MUL[ 0][3] =0;MUL[ 0][4] =0;MUL[ 0][5] =0;MUL[ 0][6] =0;MUL[ 0][7] =0;
MUL[1][0] =0;MUL[1][1] =1;MUL[1][2] =2;MUL[1][3] =3;MUL[1][4] =4;MUL[1][5] =5;MUL[1][6] =6;MUL[1][7] =7;

MUL[2][0] =0;MUL[2][1] =2;MUL[2][2] =3;MUL[2][3] =4;MUL[2][4] =5;MUL[2][5] =6;MUL[2][6] =7;MUL[2][7] =1;

MUL[3][0] =0;MUL[3][1] =3;MUL[3][2] =4;MUL[3][3] =5;MUL[3][4] =6;MUL[3][5] =7;MUL[3][6] =1;MUL[3][7] =2;

MUL[4][0] =0;MUL[4][1] =4;MUL[4][2] =5;MUL[4][3] =6;MUL[4][4] =7;MUL[4][5] =1;MUL[4][6] =2;MUL[4][7] =3;

MUL[5][0] =0;MUL[5][1] =5;MUL[5][2] =6;MUL[5][3] =7;MUL[5][4] =1;MUL[5][5] =2;MUL[5][6] =3;MUL[5][7] =4;

MUL[6][0] =0;MUL[6][1] =6;MUL[6][2] =7;MUL[6][3] =1;MUL[6][4] =2;MUL[6][5] =3;MUL[6][6] =4;MUL[6][7] =5;

MUL[7][0] =0;MUL[7][1] =7;MUL[7][2] =1;MUL[7][3] =2;MUL[7][4] =3;MUL[7][5] =4;MUL[7][6] =5;MUL[7][7] =6;
{MUL[8][0] =0;MUL[8][1] =8;MUL[8][2] =4;MUL[8][3] =7;MUL[8][4] =3;MUL[8][5] =2;MUL[8][6] =5;MUL[8][7] =1;}
INV[1] =1;INV[2] =7;INV[3] =6;INV[4] =5;INV[5] =4;INV[6] =3;INV[7] =2;
end;









11
begin


ADD[ 0][0] =0;ADD[ 0][1] =1;ADD[ 0][2] =2;ADD[ 0][3] =3;ADD[ 0][4] =4;ADD[ 0][5] =5;ADD[ 0][6] =6;ADD[ 0][7] =7;
ADD[ 0][8] =8;ADD[ 0][9] =9;ADD[ 0][10] =10;
ADD[1][0] =1;ADD[1][1] =2;ADD[1][2] =3;ADD[1][3] =4;ADD[1][4] =5;ADD[1][5] =6;ADD[1][6] =7;ADD[1][7] =8;
ADD[1][8] =9;ADD[1][9] =10;ADD[1][10] =0;
ADD[2][0] =2;ADD[2][1] =3;ADD[2][2] =4;ADD[2][3] =5;ADD[2][4] =6;ADD[2][5] =7;ADD[2][6] =8;ADD[2][7] =9;
ADD[2][8] =10;ADD[2][9] =0;ADD[2][10] =1;
ADD[3][0] =3;ADD[3][1] =4;ADD[3][2] =5;ADD[3][3] =6;ADD[3][4] =7;ADD[3][5] =8;ADD[3][6] =9;ADD[3][7] =10;
ADD[3][8] =0;ADD[3][9] =1;ADD[3][10] =2;
ADD[4][0] =4;ADD[4][1] =5;ADD[4][2] =6;ADD[4][3] =7;ADD[4][4] =8;ADD[4][5] =9;ADD[4][6] =10;ADD[4][7] =0;
ADD[4][8] =1;ADD[4][9] =2;ADD[4][10] =3;
ADD[5][0] =5;ADD[5][1] =6;ADD[5][2] =7;ADD[5][3] =8;ADD[5][4] =9;ADD[5][5] =10;ADD[5][6] =0;ADD[5][7] =1;
ADD[5][8] =2;ADD[5][9] =3;ADD[5][10] =4;
ADD[6][0] =6;ADD[6][1] =7;ADD[6][2] =8;ADD[6][3] =9;ADD[6][4] =10;ADD[6][5] =0;ADD[6][6] =1;ADD[6][7] =2;
ADD[6][8] =3;ADD[6][9] =4;ADD[6][10] =5;
ADD[7][0] =7;ADD[7][1] =8;ADD[7][2] =9;ADD[7][3] =10;ADD[7][4] =0;ADD[7][5] =1;ADD[7][6] =2;ADD[7][7] =3;
ADD[7][8] =4;ADD[7][9] =5;ADD[7][10] =6;
ADD[8][0] =8;ADD[8][1] =9;ADD[8][2] =10;ADD[8][3] =0;ADD[8][4] =1;ADD[8][5] =2;ADD[8][6] =3;ADD[8][7] =4;
ADD[8][8] =5;ADD[8][9] =6;ADD[8][10] =7;
ADD[9][0] =9;ADD[9][1] =10;ADD[9][2] =0;ADD[9][3] =1;ADD[9][4] =2;ADD[9][5] =3;ADD[9][6] =4;ADD[9][7] =5;
ADD[9][8] =6;ADD[9][9] =7;ADD[9][10] =8;
ADD[10][0] =10;ADD[10][1] =0;ADD[10][2] =1;ADD[10][3] =2;ADD[10][4] =3;ADD[10][5] =4;ADD[10][6] =5;ADD[10][7] =6;
ADD[10][8] =7;ADD[10][9] =8;ADD[10][10] =9;
NEG[0] =0;NEG[1] =10;NEG[2] =9;NEG[3] =8;NEG[4] =7;NEG[5] =6;NEG[6] =5;NEG[7] =4;NEG[8] =3;NEG[9] =2;NEG[10] =1;
MUL[ 0][0] =0;MUL[ 0][1] =0;MUL[ 0][2] =0;MUL[ 0][3] =0;MUL[ 0][4] =0;MUL[ 0][5] =0;MUL[ 0][6] =0;
MUL[ 0][7] =0;MUL[ 0][8] =0;MUL[ 0][9] =0;MUL[ 0][10] =0;
MUL[1][0] =0;MUL[1][1] =1;MUL[1][2] =2;MUL[1][3] =3;MUL[1][4] =4;MUL[1][5] =5;MUL[1][6] =6;
MUL[1][7] =7;MUL[1][8] =8;MUL[1][9] =9;MUL[1][10] =10;
MUL[2][0] =0;MUL[2][1] =2;MUL[2][2] =4;MUL[2][3] =6;MUL[2][4] =8;MUL[2][5] =10;MUL[2][6] =1;
MUL[2][7] =3;MUL[2][8] =5;MUL[2][9] =7;MUL[2][10] =9;
MUL[3][0] =0;MUL[3][1] =3;MUL[3][2] =6;MUL[3][3] =9;MUL[3][4] =1;MUL[3][5] =4;MUL[3][6] =7;
MUL[3][7] =10;MUL[3][8] =2;MUL[3][9] =5;MUL[3][10] =8;
MUL[4][0] =0;MUL[4][1] =4;MUL[4][2] =8;MUL[4][3] =1;MUL[4][4] =5;MUL[4][5] =9;MUL[4][6] =2;
MUL[4][7] =6;MUL[4][8] =10;MUL[4][9] =3;MUL[4][10] =7;
MUL[5][0] =0;MUL[5][1] =5;MUL[5][2] =10;MUL[5][3] =4;MUL[5][4] =9;MUL[5][5] =3;MUL[5][6] =8;
MUL[5][7] =2;MUL[5][8] =7;MUL[5][9] =1;MUL[5][10] =6;
MUL[6][0] =0;MUL[6][1] =6;MUL[6][2] =1;MUL[6][3] =7;MUL[6][4] =2;MUL[6][5] =8;MUL[6][6] =3;
MUL[6][7] =9;MUL[6][8] =4;MUL[6][9] =10;MUL[6][10] =5;
MUL[7][0] =0;MUL[7][1] =7;MUL[7][2] =3;MUL[7][3] =10;MUL[7][4] =6;MUL[7][5] =2;MUL[7][6] =9;
MUL[7][7] =5;MUL[7][8] =1;MUL[7][9] =8;MUL[7][10] =4;
MUL[8][0] =0;MUL[8][1] =8;MUL[8][2] =5;MUL[8][3] =2;MUL[8][4] =10;MUL[8][5] =7;MUL[8][6] =4;
MUL[8][7] =1;MUL[8][8] =9;MUL[8][9] =6;MUL[8][10] =3;
MUL[9][0] =0;MUL[9][1] =9;MUL[9][2] =7;MUL[9][3] =5;MUL[9][4] =3;MUL[9][5] =1;MUL[9][6] =10;
MUL[9][7] =8;MUL[9][8] =6;MUL[9][9] =4;MUL[9][10] =2;
MUL[10][0] =0;MUL[10][1] =10;MUL[10][2] =9;MUL[10][3] =8;MUL[10][4] =7;MUL[10][5] =6;
MUL[10][6] =5;MUL[10][7] =4;MUL[10][8] =3;MUL[10][9] =2;MUL[10][10] =1;
INV[1] =1;INV[2] =6;INV[3] =4;INV[4] =3;INV[5] =9;INV[6] =2;INV[7] =8;INV[8] =7;
INV[9] =5;INV[10] =10;
end;
13
begin


ADD[ 0][0] =0;ADD[ 0][1] =1;ADD[ 0][2] =2;ADD[ 0][3] =3;ADD[ 0][4] =4;ADD[ 0][5] =5;
ADD[ 0][6] =6;ADD[ 0][7] =7;ADD[ 0][8] =8;ADD[ 0][9] =9;ADD[ 0][10] =10;ADD[ 0][11] =11;ADD[ 0][12] =12;
ADD[1][0] =1;ADD[1][1] =2;ADD[1][2] =3;ADD[1][3] =4;ADD[1][4] =5;ADD[1][5] =6;ADD[1][6] =7;
ADD[1][7] =8;ADD[1][8] =9;ADD[1][9] =10;ADD[1][10] =11;ADD[1][11] =12;ADD[1][12] =0;
ADD[2][0] =2;ADD[2][1] =3;ADD[2][2] =4;ADD[2][3] =5;ADD[2][4] =6;ADD[2][5] =7;
ADD[2][6] =8;ADD[2][7] =9;ADD[2][8] =10;ADD[2][9] =11;ADD[2][10] =12;ADD[2][11] =0;ADD[2][12] =1;
ADD[3][0] =3;ADD[3][1] =4;ADD[3][2] =5;ADD[3][3] =6;ADD[3][4] =7;ADD[3][5] =8;ADD[3][6] =9;
ADD[3][7] =10;ADD[3][8] =11;ADD[3][9] =12;ADD[3][10] =0;ADD[3][11] =1;ADD[3][12] =2;
ADD[4][0] =4;ADD[4][1] =5;ADD[4][2] =6;ADD[4][3] =7;ADD[4][4] =8;ADD[4][5] =9;
ADD[4][6] =10;ADD[4][7] =11;ADD[4][8] =12;ADD[4][9] =0;ADD[4][10] =1;ADD[4][11] =2;ADD[4][12] =3;
ADD[5][0] =5;ADD[5][1] =6;ADD[5][2] =7;ADD[5][3] =8;ADD[5][4] =9;ADD[5][5] =10;ADD[5][6] =11;
ADD[5][7] =12;ADD[5][8] =0;ADD[5][9] =1;ADD[5][10] =2;ADD[5][11] =3;ADD[5][12] =4;
ADD[6][0] =6;ADD[6][1] =7;ADD[6][2] =8;ADD[6][3] =9;ADD[6][4] =10;ADD[6][5] =11;
ADD[6][6] =12;ADD[6][7] =0;ADD[6][8] =1;ADD[6][9] =2;ADD[6][10] =3;ADD[6][11] =4;ADD[6][12] =5;
ADD[7][0] =7;ADD[7][1] =8;ADD[7][2] =9;ADD[7][3] =10;ADD[7][4] =11;ADD[7][5] =12;ADD[7][6] =0;
ADD[7][7] =1;ADD[7][8] =2;ADD[7][9] =3;ADD[7][10] =4;ADD[7][11] =5;ADD[7][12] =6;
ADD[8][0] =8;ADD[8][1] =9;ADD[8][2] =10;ADD[8][3] =11;ADD[8][4] =12;ADD[8][5] =0;
ADD[8][6] =1;ADD[8][7] =2;ADD[8][8] =3;ADD[8][9] =4;ADD[8][10] =5;ADD[8][11] =6;ADD[8][12] =7;
ADD[9][0] =9;ADD[9][1] =10;ADD[9][2] =11;ADD[9][3] =12;ADD[9][4] =0;ADD[9][5] =1;
ADD[9][6] =2;ADD[9][7] =3;ADD[9][8] =4;ADD[9][9] =5;ADD[9][10] =6;ADD[9][11] =7;ADD[9][12] =8;
ADD[10][0] =10;ADD[10][1] =11;ADD[10][2] =12;ADD[10][3] =0;ADD[10][4] =1;ADD[10][5] =2;
ADD[10][6] =3;ADD[10][7] =4;ADD[10][8] =5;ADD[10][9] =6;ADD[10][10] =7;ADD[10][11] =8;ADD[10][12] =9;
ADD[11][0] =11;ADD[11][1] =12;ADD[11][2] =0;ADD[11][3] =1;ADD[11][4] =2;ADD[11][5] =3;ADD[11][6] =4;
ADD[11][7] =5;ADD[11][8] =6;ADD[11][9] =7;ADD[11][10] =8;ADD[11][11] =9;ADD[11][12] =10;
ADD[12][0] =12;ADD[12][1] =0;ADD[12][2] =1;ADD[12][3] =2;ADD[12][4] =3;ADD[12][5] =4;
ADD[12][6] =5;ADD[12][7] =6;ADD[12][8] =7;ADD[12][9] =8;ADD[12][10] =9;ADD[12][11] =10;ADD[12][12] =11;
NEG[0] =0;NEG[1] =12;NEG[2] =11;NEG[3] =10;NEG[4] =9;NEG[5] =8;NEG[6] =7;NEG[7] =6;NEG[8] =5;
NEG[9] =4;NEG[10] =3;NEG[11] =2;NEG[12] =1;
MUL[ 0][0] =0;MUL[ 0][1] =0;MUL[ 0][2] =0;MUL[ 0][3] =0;MUL[ 0][4] =0;MUL[ 0][5] =0;MUL[ 0][6] =0;
MUL[ 0][7] =0;MUL[ 0][8] =0;MUL[ 0][9] =0;MUL[ 0][10] =0;MUL[ 0][11] =0;MUL[ 0][12] =0;
MUL[1][0] =0;MUL[1][1] =1;MUL[1][2] =2;MUL[1][3] =3;MUL[1][4] =4;MUL[1][5] =5;MUL[1][6] =6;
MUL[1][7] =7;MUL[1][8] =8;MUL[1][9] =9;MUL[1][10] =10;MUL[1][11] =11;MUL[1][12] =12;
MUL[2][0] =0;MUL[2][1] =2;MUL[2][2] =4;MUL[2][3] =6;MUL[2][4] =8;MUL[2][5] =10;
MUL[2][6] =12;MUL[2][7] =1;MUL[2][8] =3;MUL[2][9] =5;MUL[2][10] =7;MUL[2][11] =9;MUL[2][12] =11;
MUL[3][0] =0;MUL[3][1] =3;MUL[3][2] =6;MUL[3][3] =9;MUL[3][4] =12;MUL[3][5] =2;MUL[3][6] =5;
MUL[3][7] =8;MUL[3][8] =11;MUL[3][9] =1;MUL[3][10] =4;MUL[3][11] =7;MUL[3][12] =10;
MUL[4][0] =0;MUL[4][1] =4;MUL[4][2] =8;MUL[4][3] =12;MUL[4][4] =3;MUL[4][5] =7;
MUL[4][6] =11;MUL[4][7] =2;MUL[4][8] =6;MUL[4][9] =10;MUL[4][10] =1;MUL[4][11] =5;MUL[4][12] =9;
MUL[5][0] =0;MUL[5][1] =5;MUL[5][2] =10;MUL[5][3] =2;MUL[5][4] =7;MUL[5][5] =12;MUL[5][6] =4;
MUL[5][7] =9;MUL[5][8] =1;MUL[5][9] =6;MUL[5][10] =11;MUL[5][11] =3;MUL[5][12] =8;
MUL[6][0] =0;MUL[6][1] =6;MUL[6][2] =12;MUL[6][3] =5;MUL[6][4] =11;MUL[6][5] =4;
MUL[6][6] =10;MUL[6][7] =3;MUL[6][8] =9;MUL[6][9] =2;MUL[6][10] =8;MUL[6][11] =1;MUL[6][12] =7;
MUL[7][0] =0;MUL[7][1] =7;MUL[7][2] =1;MUL[7][3] =8;MUL[7][4] =2;MUL[7][5] =9;MUL[7][6] =3;
MUL[7][7] =10;MUL[7][8] =4;MUL[7][9] =11;MUL[7][10] =5;MUL[7][11] =12;MUL[7][12] =6;
MUL[8][0] =0;MUL[8][1] =8;MUL[8][2] =3;MUL[8][3] =11;MUL[8][4] =6;MUL[8][5] =1;
MUL[8][6] =9;MUL[8][7] =4;MUL[8][8] =12;MUL[8][9] =7;MUL[8][10] =2;MUL[8][11] =10;MUL[8][12] =5;
MUL[9][0] =0;MUL[9][1] =9;MUL[9][2] =5;MUL[9][3] =1;MUL[9][4] =10;MUL[9][5] =6;MUL[9][6] =2;
MUL[9][7] =11;MUL[9][8] =7;MUL[9][9] =3;MUL[9][10] =12;MUL[9][11] =8;MUL[9][12] =4;
MUL[10][0] =0;MUL[10][1] =10;MUL[10][2] =7;MUL[10][3] =4;MUL[10][4] =1;MUL[10][5] =11;
MUL[10][6] =8;MUL[10][7] =5;MUL[10][8] =2;MUL[10][9] =12;MUL[10][10] =9;MUL[10][11] =6;MUL[10][12] =3;
MUL[11][0] =0;MUL[11][1] =11;MUL[11][2] =9;MUL[11][3] =7;MUL[11][4] =5;MUL[11][5] =3;MUL[11][6] =1;
MUL[11][7] =12;MUL[11][8] =10;MUL[11][9] =8;MUL[11][10] =6;MUL[11][11] =4;MUL[11][12] =2;
MUL[12][0] =0;MUL[12][1] =12;MUL[12][2] =11;MUL[12][3] =10;MUL[12][4] =9;MUL[12][5] =8;
MUL[12][6] =7;MUL[12][7] =6;MUL[12][8] =5;MUL[12][9] =4;MUL[12][10] =3;MUL[12][11] =2;MUL[12][12] =1;
INV[1] =1;INV[2] =7;INV[3] =9;INV[4] =10;INV[5] =8;INV[6] =11;INV[7] =2;INV[8] =5;INV[9] =3;
INV[10] =4;INV[11] =6;INV[12] =12;
end;
16
begin


ADD[ 0][0] =0;ADD[ 0][1] =1;ADD[ 0][2] =2;ADD[ 0][3] =3;ADD[ 0][4] =4;ADD[ 0][5] =5;ADD[ 0][6] =6;ADD[ 0][7] =7;ADD[ 0][8] =8;
ADD[ 0][9] =9;ADD[ 0][10] =10;ADD[ 0][11] =11;ADD[ 0][12] =12;ADD[ 0][13] =13;ADD[ 0][14] =14;ADD[ 0][15] =15;
ADD[1][0] =1;ADD[1][1] =0;ADD[1][2] =3;ADD[1][3] =2;ADD[1][4] =5;ADD[1][5] =4;ADD[1][6] =7;ADD[1][7] =6;
ADD[1][8] =9;ADD[1][9] =8;ADD[1][10] =11;ADD[1][11] =10;ADD[1][12] =13;ADD[1][13] =12;ADD[1][14] =15;ADD[1][15] =14;
ADD[2][0] =2;ADD[2][1] =3;ADD[2][2] =0;ADD[2][3] =1;ADD[2][4] =6;ADD[2][5] =7;ADD[2][6] =4;ADD[2][7] =5;ADD[2][8] =10;
ADD[2][9] =11;ADD[2][10] =8;ADD[2][11] =9;ADD[2][12] =14;ADD[2][13] =15;ADD[2][14] =12;ADD[2][15] =13;
ADD[3][0] =3;ADD[3][1] =2;ADD[3][2] =1;ADD[3][3] =0;ADD[3][4] =7;ADD[3][5] =6;ADD[3][6] =5;ADD[3][7] =4;
ADD[3][8] =11;ADD[3][9] =10;ADD[3][10] =9;ADD[3][11] =8;ADD[3][12] =15;ADD[3][13] =14;ADD[3][14] =13;ADD[3][15] =12;
ADD[4][0] =4;ADD[4][1] =5;ADD[4][2] =6;ADD[4][3] =7;ADD[4][4] =0;ADD[4][5] =1;ADD[4][6] =2;ADD[4][7] =3;ADD[4][8] =12;
ADD[4][9] =13;ADD[4][10] =14;ADD[4][11] =15;ADD[4][12] =8;ADD[4][13] =9;ADD[4][14] =10;ADD[4][15] =11;
ADD[5][0] =5;ADD[5][1] =4;ADD[5][2] =7;ADD[5][3] =6;ADD[5][4] =1;ADD[5][5] =0;ADD[5][6] =3;ADD[5][7] =2;
ADD[5][8] =13;ADD[5][9] =12;ADD[5][10] =15;ADD[5][11] =14;ADD[5][12] =9;ADD[5][13] =8;ADD[5][14] =11;ADD[5][15] =10;
ADD[6][0] =6;ADD[6][1] =7;ADD[6][2] =4;ADD[6][3] =5;ADD[6][4] =2;ADD[6][5] =3;ADD[6][6] =0;ADD[6][7] =1;ADD[6][8] =14;
ADD[6][9] =15;ADD[6][10] =12;ADD[6][11] =13;ADD[6][12] =10;ADD[6][13] =11;ADD[6][14] =8;ADD[6][15] =9;
ADD[7][0] =7;ADD[7][1] =6;ADD[7][2] =5;ADD[7][3] =4;ADD[7][4] =3;ADD[7][5] =2;ADD[7][6] =1;ADD[7][7] =0;
ADD[7][8] =15;ADD[7][9] =14;ADD[7][10] =13;ADD[7][11] =12;ADD[7][12] =11;ADD[7][13] =10;ADD[7][14] =9;ADD[7][15] =8;
ADD[8][0] =8;ADD[8][1] =9;ADD[8][2] =10;ADD[8][3] =11;ADD[8][4] =12;ADD[8][5] =13;ADD[8][6] =14;ADD[8][7] =15;
ADD[8][8] =0;ADD[8][9] =1;ADD[8][10] =2;ADD[8][11] =3;ADD[8][12] =4;ADD[8][13] =5;ADD[8][14] =6;ADD[8][15] =7;
ADD[9][0] =9;ADD[9][1] =8;ADD[9][2] =11;ADD[9][3] =10;ADD[9][4] =13;ADD[9][5] =12;ADD[9][6] =15;ADD[9][7] =14;
ADD[9][8] =1;ADD[9][9] =0;ADD[9][10] =3;ADD[9][11] =2;ADD[9][12] =5;ADD[9][13] =4;ADD[9][14] =7;ADD[9][15] =6;
ADD[10][0] =10;ADD[10][1] =11;ADD[10][2] =8;ADD[10][3] =9;ADD[10][4] =14;ADD[10][5] =15;ADD[10][6] =12;ADD[10][7] =13;
ADD[10][8] =2;ADD[10][9] =3;ADD[10][10] =0;ADD[10][11] =1;ADD[10][12] =6;ADD[10][13] =7;ADD[10][14] =4;ADD[10][15] =5;
ADD[11][0] =11;ADD[11][1] =10;ADD[11][2] =9;ADD[11][3] =8;ADD[11][4] =15;ADD[11][5] =14;ADD[11][6] =13;ADD[11][7] =12;
ADD[11][8] =3;ADD[11][9] =2;ADD[11][10] =1;ADD[11][11] =0;ADD[11][12] =7;ADD[11][13] =6;ADD[11][14] =5;ADD[11][15] =4;
ADD[12][0] =12;ADD[12][1] =13;ADD[12][2] =14;ADD[12][3] =15;ADD[12][4] =8;ADD[12][5] =9;ADD[12][6] =10;ADD[12][7] =11;
ADD[12][8] =4;ADD[12][9] =5;ADD[12][10] =6;ADD[12][11] =7;ADD[12][12] =0;ADD[12][13] =1;ADD[12][14] =2;ADD[12][15] =3;
ADD[13,0] =13;ADD[13,1] =12;ADD[13,2] =15;ADD[13,3] =14;ADD[13,4] =9;ADD[13,5] =8;ADD[13,6] =11;ADD[13,7] =10;
ADD[13,8] =5;ADD[13,9] =4;ADD[13,10] =7;ADD[13,11] =6;ADD[13,12] =1;ADD[13,13] =0;ADD[13,14] =3;ADD[13,15] =2;
ADD[14,0] =14;ADD[14,1] =15;ADD[14,2] =12;ADD[14,3] =13;ADD[14,4] =10;ADD[14,5] =11;ADD[14,6] =8;ADD[14,7] =9;
ADD[14,8] =6;ADD[14,9] =7;ADD[14,10] =4;ADD[14,11] =5;ADD[14,12] =2;ADD[14,13] =3;ADD[14,14] =0;ADD[14,15] =1;
ADD[15,0] =15;ADD[15,1] =14;ADD[15,2] =13;ADD[15,3] =12;ADD[15,4] =11;ADD[15,5] =10;ADD[15,6] =9;ADD[15,7] =8;
ADD[15,8] =7;ADD[15,9] =6;ADD[15,10] =5;ADD[15,11] =4;ADD[15,12] =3;ADD[15,13] =2;ADD[15,14] =1;ADD[15,15] =0;
NEG[0] =0;NEG[1] =1;NEG[2] =2;NEG[3] =3;NEG[4] =4;NEG[5] =5;NEG[6] =6;NEG[7] =7;NEG[8] =8;NEG[9] =9;NEG[10] =10;
NEG[11] =11;NEG[12] =12;NEG[13] =13;NEG[14] =14;NEG[15] =15;
MUL[ 0][0] =0;MUL[ 0][1] =0;MUL[ 0][2] =0;MUL[ 0][3] =0;MUL[ 0][4] =0;MUL[ 0][5] =0;MUL[ 0][6] =0;MUL[ 0][7] =0;MUL[ 0][8] =0;
MUL[ 0][9] =0;MUL[ 0][10] =0;MUL[ 0][11] =0;MUL[ 0][12] =0;MUL[ 0][13] =0;MUL[ 0][14] =0;MUL[ 0][15] =0;
MUL[1][0] =0;MUL[1][1] =1;MUL[1][2] =2;MUL[1][3] =3;MUL[1][4] =4;MUL[1][5] =5;MUL[1][6] =6;MUL[1][7] =7;
MUL[1][8] =8;MUL[1][9] =9;MUL[1][10] =10;MUL[1][11] =11;MUL[1][12] =12;MUL[1][13] =13;MUL[1][14] =14;MUL[1][15] =15;
MUL[2][0] =0;MUL[2][1] =2;MUL[2][2] =4;MUL[2][3] =6;MUL[2][4] =8;MUL[2][5] =10;MUL[2][6] =12;MUL[2][7] =14;
MUL[2][8] =3;MUL[2][9] =1;MUL[2][10] =7;MUL[2][11] =5;MUL[2][12] =11;MUL[2][13] =9;MUL[2][14] =15;MUL[2][15] =13;
MUL[3][0] =0;MUL[3][1] =3;MUL[3][2] =6;MUL[3][3] =5;MUL[3][4] =12;MUL[3][5] =15;MUL[3][6] =10;MUL[3][7] =9;
MUL[3][8] =11;MUL[3][9] =8;MUL[3][10] =13;MUL[3][11] =14;MUL[3][12] =7;MUL[3][13] =4;MUL[3][14] =1;MUL[3][15] =2;
MUL[4][0] =0;MUL[4][1] =4;MUL[4][2] =8;MUL[4][3] =12;MUL[4][4] =3;MUL[4][5] =7;MUL[4][6] =11;MUL[4][7] =15;
MUL[4][8] =6;MUL[4][9] =2;MUL[4][10] =14;MUL[4][11] =10;MUL[4][12] =5;MUL[4][13] =1;MUL[4][14] =13;MUL[4][15] =9;
MUL[5][0] =0;MUL[5][1] =5;MUL[5][2] =10;MUL[5][3] =15;MUL[5][4] =7;MUL[5][5] =2;MUL[5][6] =13;MUL[5][7] =8;
MUL[5][8] =14;MUL[5][9] =11;MUL[5][10] =4;MUL[5][11] =1;MUL[5][12] =9;MUL[5][13] =12;MUL[5][14] =3;MUL[5][15] =6;
MUL[6][0] =0;MUL[6][1] =6;MUL[6][2] =12;MUL[6][3] =10;MUL[6][4] =11;MUL[6][5] =13;MUL[6][6] =7;MUL[6][7] =1;
MUL[6][8] =5;MUL[6][9] =3;MUL[6][10] =9;MUL[6][11] =15;MUL[6][12] =14;MUL[6][13] =8;MUL[6][14] =2;MUL[6][15] =4;
MUL[7][0] =0;MUL[7][1] =7;MUL[7][2] =14;MUL[7][3] =9;MUL[7][4] =15;MUL[7][5] =8;MUL[7][6] =1;MUL[7][7] =6;
MUL[7][8] =13;MUL[7][9] =10;MUL[7][10] =3;MUL[7][11] =4;MUL[7][12] =2;MUL[7][13] =5;MUL[7][14] =12;MUL[7][15] =11;
MUL[8][0] =0;MUL[8][1] =8;MUL[8][2] =3;MUL[8][3] =11;MUL[8][4] =6;MUL[8][5] =14;MUL[8][6] =5;MUL[8][7] =13;
MUL[8][8] =12;MUL[8][9] =4;MUL[8][10] =15;MUL[8][11] =7;MUL[8][12] =10;MUL[8][13] =2;MUL[8][14] =9;MUL[8][15] =1;
MUL[9][0] =0;MUL[9][1] =9;MUL[9][2] =1;MUL[9][3] =8;MUL[9][4] =2;MUL[9][5] =11;MUL[9][6] =3;MUL[9][7] =10;
MUL[9][8] =4;MUL[9][9] =13;MUL[9][10] =5;MUL[9][11] =12;MUL[9][12] =6;MUL[9][13] =15;MUL[9][14] =7;MUL[9][15] =14;
MUL[10][0] =0;MUL[10][1] =10;MUL[10][2] =7;MUL[10][3] =13;MUL[10][4] =14;MUL[10][5] =4;MUL[10][6] =9;MUL[10][7] =3;
MUL[10][8] =15;MUL[10][9] =5;MUL[10][10] =8;MUL[10][11] =2;MUL[10][12] =1;MUL[10][13] =11;MUL[10][14] =6;MUL[10][15] =12;
MUL[11][0] =0;MUL[11][1] =11;MUL[11][2] =5;MUL[11][3] =14;MUL[11][4] =10;MUL[11][5] =1;MUL[11][6] =15;MUL[11][7] =4;
MUL[11][8] =7;MUL[11][9] =12;MUL[11][10] =2;MUL[11][11] =9;MUL[11][12] =13;MUL[11][13] =6;MUL[11][14] =8;MUL[11][15] =3;
MUL[12][0] =0;MUL[12][1] =12;MUL[12][2] =11;MUL[12][3] =7;MUL[12][4] =5;MUL[12][5] =9;MUL[12][6] =14;MUL[12][7] =2;
MUL[12][8] =10;MUL[12][9] =6;MUL[12][10] =1;MUL[12][11] =13;MUL[12][12] =15;MUL[12][13] =3;MUL[12][14] =4;MUL[12][15] =8;
MUL[13,0] =0;MUL[13,1] =13;MUL[13,2] =9;MUL[13,3] =4;MUL[13,4] =1;MUL[13,5] =12;MUL[13,6] =8;MUL[13,7] =5;
MUL[13,8] =2;MUL[13,9] =15;MUL[13,10] =11;MUL[13,11] =6;MUL[13,12] =3;MUL[13,13] =14;MUL[13,14] =10;MUL[13,15] =7;
MUL[14,0] =0;MUL[14,1] =14;MUL[14,2] =15;MUL[14,3] =1;MUL[14,4] =13;MUL[14,5] =3;MUL[14,6] =2;MUL[14,7] =12;
MUL[14,8] =9;MUL[14,9] =7;MUL[14,10] =6;MUL[14,11] =8;MUL[14,12] =4;MUL[14,13] =10;MUL[14,14] =11;MUL[14,15] =5;
MUL[15,0] =0;MUL[15,1] =15;MUL[15,2] =13;MUL[15,3] =2;MUL[15,4] =9;MUL[15,5] =6;MUL[15,6] =4;MUL[15,7] =11;
MUL[15,8] =1;MUL[15,9] =14;MUL[15,10] =12;MUL[15,11] =3;MUL[15,12] =8;MUL[15,13] =7;MUL[15,14] =5;MUL[15,15] =10;
INV[1] =1;INV[2] =9;INV[3] =14;INV[4] =13;INV[5] =11;INV[6] =7;INV[7] =6;INV[8] =15;INV[9] =2;INV[10] =12;
INV[11] =5;INV[12] =10;INV[13] =4;INV[14] =3;INV[15] =8;
end;
end;
end;
end*/
