#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char key[65];

 //PCMONE
 int PCMONE[56]={57,	49,	41,	33,	25,	17,	9,
		 1 ,	58,	50,	42,	34,	26,	18,
		 10,	2,	59,	51,	43,	35,	27,
		 19,	11,	3,	60,	52,	44,	36,
		 63,	55,	47,	39,	31,	23,	15,
		 7 ,	62,	54,	46,	38,	30,	22,
		 14,	6,	61,	53,	45,	37,	29,
 		 21,	13,	5,	28,	20,	12,	4};
 //PCMTWO
 int PCMTWO[48]={14,	17,	11,	24,	1,	5,	3,	28,
		 15,	6,	21,	10,	23,	19,	12,	4,
		 26,	8,	16,	7,	27,	20,	13,	2,
		 41,	52,	31,	37,	47,	55,	30,	40,
		 51,	45,	33,	48,	44,	49,	39,	56,
		 34,	53,	46,	42,	50,	36,	29,	32};
 //E-�ڽ� 
 int E[48]={32, 1, 2, 3, 4, 5,
		 4, 5, 6, 7, 8, 9,
		 8, 9, 10, 11, 12, 13,
		 12, 13, 14, 15, 16, 17,
		 16, 17, 18, 19, 20, 21,
		 20, 21, 22, 23, 24, 25,
		 24, 25, 26, 27, 28, 29,
		 28, 29, 30, 31, 32, 1};
//P-�ڽ�(�ܼ�ġȯ)
 char P[32] = {  16,  7, 20, 21, 29, 12, 28, 17, 
                1, 15, 23, 26,  5, 18, 31, 10, 
           2,  8, 24, 14, 32, 27,  3,  9, 
          19, 13, 30,  6, 22, 11,  4, 25   };
 //64��Ʈ�� �̷���� 8���� S-�ڽ� 
 char S[8][4][16] = {        
 
   //S-�ڽ�1
   {{14, 4,13, 1, 2,15,11, 8, 3,10, 6,12, 5, 9, 0, 7},
    { 0,15, 7, 4,14, 2,13, 1,10, 6,12,11, 9, 5, 3, 8}, 
    { 4, 1,14, 8,13, 6, 2,11,15,12, 9, 7, 3,10, 5, 0},
    {15,12, 8, 2, 4, 9, 1, 7, 5,11, 3,14,10, 0, 6,13}  },
  
  //S-�ڽ�2
   {{15, 1, 8,14, 6,11, 3, 4, 9, 7, 2,13,12, 0, 5,10},
    { 3,13, 4, 7,15, 2, 8,14,12, 0, 1,10, 6, 9,11, 5}, 
    { 0,14, 7,11,10, 4,13, 1, 5, 8,12, 6, 9, 3, 2,15},
    {13, 8,10, 1, 3,15, 4, 2,11, 6, 7,12, 0, 5,14, 9}  },
  //S-�ڽ�3
   {{10, 0, 9,14, 6, 3,15, 5, 1,13,12, 7,11, 4, 2, 8},
    {13, 7, 0, 9, 3, 4, 6,10, 2, 8, 5,14,12,11,15, 1}, 
    {13, 6, 4, 9, 8,15, 3, 0,11, 1, 2,12, 5,10,14, 7},
    { 1,10,13, 0, 6, 9, 8, 7, 4,15,14, 3,11, 5, 2,12}  },
  
  
  //S-�ڽ�4
   {{ 7,13,14, 3, 0, 6, 9,10, 1, 2, 8, 5,11,12, 4,15},
    {13, 8,11, 5, 6,15, 0, 3, 4, 7, 2,12, 1,10,14, 9}, 
    {10, 6, 9, 0,12,11, 7,13,15, 1, 3,14, 5, 2, 8, 4},
    { 3,15, 0, 6,10, 1,13, 8, 9, 4, 5,11,12, 7, 2,14}  },
  
  //S-�ڽ�5
   {{ 2,12, 4, 1, 7,10,11, 6, 8, 5, 3,15,13, 0,14, 9},
    {14,11, 2,12, 4, 7,13, 1, 5, 0,15,10, 3, 9, 8, 6}, 
    { 4, 2, 1,11,10,13, 7, 8,15, 9,12, 5, 6, 3, 0,14},
    {11, 8,12, 7, 1,14, 2,13, 6,15, 0, 9,10, 4, 5, 3}  },
  
  
  //S-�ڽ�6
   {{12, 1,10,15, 9, 2, 6, 8, 0,13, 3, 4,14, 7, 5,11}, 
    {10,15, 4, 2, 7,12, 9, 5, 6, 1,13,14, 0,11, 3, 8}, 
    { 9,14,15, 5, 2, 8,12, 3, 7, 0, 4,10, 1,13,11, 6},
    { 4, 3, 2,12, 9, 5,15,10,11,14, 1, 7, 6, 0, 8,13}  },
  
  
  //S-�ڽ�7
   {{ 4,11, 2,14,15, 0, 8,13, 3,12, 9, 7, 5,10, 6, 1},
    {13, 0,11, 7, 4, 9, 1,10,14, 3, 5,12, 2,15, 8, 6}, 
    { 1, 4,11,13,12, 3, 7,14,10,15, 6, 8, 0, 5, 9, 2},
    { 6,11,13, 8, 1, 4,10, 7, 9, 5, 0,15,14, 2, 3,12}  },
  
  
  //S-�ڽ�8
  {{13, 2, 8, 4, 6,15,11, 1,10, 9, 3,14, 5, 0,12, 7},
   { 1,15,13, 8,10, 3, 7, 4,12, 5, 6,11, 0,14, 9, 2}, 
   { 7,11, 4, 1, 9,12,14, 2, 0, 6,10,13,15, 3, 5, 8},
   { 2, 1,14, 7, 4,10, 8,13,15,12, 9, 0, 3, 5, 6,11}  }
 };
 
 char IP[64] ={ 58, 50, 42, 34, 26, 18, 10, 2, 
         60, 52, 44, 36, 28, 20, 12, 4, 
         62, 54, 46, 38, 30, 22, 14, 6, 
         64, 56, 48, 40, 32, 24, 16, 8, 
         57, 49, 41, 33, 25, 17, 9, 1, 
         59, 51, 43, 35, 27, 19, 11, 3, 
         61, 53, 45, 37, 29, 21, 13, 5, 
         63, 55, 47, 39, 31, 23, 15, 7  };
 
 char IPinv[64] ={40, 8, 48, 16, 56, 24, 64, 32,
          39, 7, 47, 15, 55, 23, 63, 31, 
         38, 6, 46, 14, 54, 22, 62, 30, 
         37, 5, 45, 13, 53, 21, 61, 29, 
         36, 4, 44, 12, 52, 20, 60, 28, 
         35, 3, 43, 11, 51, 19, 59, 27, 
         34, 2, 42, 10, 50, 18, 58, 26, 
         33, 1, 41, 9, 49, 17, 57, 25 };
         

//des��ȣȭ�� �����ϴ� �Լ� 
void des(char* first, bool endn){
	char sl[33];//="00000000111111110111100001010101";
	char sr[33];//="00000000111111111000000001100110";
	char sk[16][49];//="010100000010110010101100010001000000000001000000";
	//01011011111101111100010110110010 ��� 
	
	int i, j, sboxuse, sboxuse2, round;
	char eout[49], xorout[49], sboxout[33], pout[33], xorafter[33], ipout[65];
	
	//encryption or decryption
//	bool endn = true;
	
	//ip
	for(i=0;i<64;i++) ipout[i]=first[IP[i]-1];
	ipout[64]='\0';
 if(endn==true){ //��ȣȭ�� ��� ���ʿ��� ���������� �״�� ǥ�� 
	for(i=0;i<32;i++) sl[i]=ipout[i];
	for(i=32;i<64;i++) sr[i-32]=ipout[i];
 }
 else{ //��ȣȭ�� ��� �����ʰ� ������ �ٲپ ǥ�� 
 	for(i=0;i<32;i++) sr[i]=ipout[i];
	for(i=32;i<64;i++) sl[i-32]=ipout[i];
 }
	sl[32]=sr[32]='\0';
//	printf("ipout = %s%s\n",sl,sr);
	
	char pcmone[57], pcmtwo[49], shift[3];
	
	//pcmone
	for(i=0;i<56;i++) pcmone[i]=key[PCMONE[i]-1];
	pcmone[56]='\0';
//	printf("pcmone = %s\n", pcmone);
	
  //key make
  for(j=0;j<16;j++){
	//shift
  	if(j==0||j==1||j==8||j==15){
		shift[0]=pcmone[0];
		for(i=0;i<27;i++) pcmone[i]=pcmone[i+1];
		pcmone[27]=shift[0];
		
		shift[0]=pcmone[28];
		for(i=28;i<55;i++) pcmone[i]=pcmone[i+1];
		pcmone[55]=shift[0];
  	}
 	 else{
		shift[0]=pcmone[0];
		shift[1]=pcmone[1];
		for(i=0;i<26;i++) pcmone[i]=pcmone[i+2];
		pcmone[26]=shift[0];
		pcmone[27]=shift[1];
		
		shift[0]=pcmone[28];
		shift[1]=pcmone[29];
		for(i=28;i<54;i++) pcmone[i]=pcmone[i+2];
		pcmone[54]=shift[0];
		pcmone[55]=shift[1];
  	
  	}
// 	printf("shift = %s\n", pcmone);
	
  	//pcmtwo
	for(i=0;i<48;i++) pcmtwo[i]=pcmone[PCMTWO[i]-1];
	pcmtwo[48]='\0';
	for(i=0;i<=48;i++) sk[j][i]=pcmtwo[i];
//	printf("key %d = %s\n",j+1, sk[j]);
	
	
  }
	
	//start func
 for(round=0;round<16;round++){
//	printf("*******************************\n%d round\n****************************\n",round+1);
	
//	printf("sl = %s\n",sl);
//	printf("sr = %s\n",sr);
	
	//init right
	sr[32]='\0';
//	printf("sr = %s\n", sr);
	
	//ebox
	for(i=0; i<48; i++)	eout[i]=sr[E[i]-1];
	eout[48]='\0';
//	printf("eout =   %s\n", eout);
	
	
	//xor
  if(endn==true){
//	printf("key  =   %s\n", sk[round]);
	for(i=0;i<48; i++){
		if((eout[i]=='0'&&sk[round][i]=='0')||(eout[i]=='1'&&sk[round][i]=='1')) xorout[i]='0';
		else xorout[i]='1';
	}
	xorout[48]='\0';
//	printf("xorout = %s\n", xorout);
  }
  else{
//	printf("key  =   %s\n", sk[15-round]);
	for(i=0;i<48; i++){
		if((eout[i]=='0'&&sk[15-round][i]=='0')||(eout[i]=='1'&&sk[15-round][i]=='1')) xorout[i]='0';
		else xorout[i]='1';
	}
	xorout[48]='\0';
//	printf("xorout = %s\n", xorout);
  }
	//Sbox one
	sboxuse=0;
	if(xorout[1]=='1') sboxuse+=8;
	if(xorout[2]=='1') sboxuse+=4;
	if(xorout[3]=='1') sboxuse+=2;
	if(xorout[4]=='1') sboxuse+=1;
	
	if(xorout[0]=='0'&&xorout[5]=='0') sboxuse2=S[0][0][sboxuse];
	else if(xorout[0]=='0'&&xorout[5]=='1') sboxuse2=S[0][1][sboxuse];
	else if(xorout[0]=='1'&&xorout[5]=='0') sboxuse2=S[0][2][sboxuse];
	else if(xorout[0]=='1'&&xorout[5]=='1') sboxuse2=S[0][3][sboxuse];
	
	if(sboxuse2>=8){ sboxout[0]='1'; sboxuse2-=8; }
	else sboxout[0]='0';
	if(sboxuse2>=4){ sboxout[1]='1'; sboxuse2-=4; }
	else sboxout[1]='0';
	if(sboxuse2>=2){ sboxout[2]='1'; sboxuse2-=2; }
	else sboxout[2]='0';
	if(sboxuse2>=1){ sboxout[3]='1'; sboxuse2-=1; }
	else sboxout[3]='0';
	
	//Sbox two
	sboxuse=0;
	if(xorout[7]=='1') sboxuse+=8;
	if(xorout[8]=='1') sboxuse+=4;
	if(xorout[9]=='1') sboxuse+=2;
	if(xorout[10]=='1') sboxuse+=1;
	
	if(xorout[6]=='0'&&xorout[11]=='0') sboxuse2=S[1][0][sboxuse];
	else if(xorout[6]=='0'&&xorout[11]=='1') sboxuse2=S[1][1][sboxuse];
	else if(xorout[6]=='1'&&xorout[11]=='0') sboxuse2=S[1][2][sboxuse];
	else if(xorout[6]=='1'&&xorout[11]=='1') sboxuse2=S[1][3][sboxuse];
	
	if(sboxuse2>=8){ sboxout[4]='1'; sboxuse2-=8; }
	else sboxout[4]='0';
	if(sboxuse2>=4){ sboxout[5]='1'; sboxuse2-=4; }
	else sboxout[5]='0';
	if(sboxuse2>=2){ sboxout[6]='1'; sboxuse2-=2; }
	else sboxout[6]='0';
	if(sboxuse2>=1){ sboxout[7]='1'; sboxuse2-=1; }
	else sboxout[7]='0';
	
	//Sbox three
	sboxuse=0;
	if(xorout[13]=='1') sboxuse+=8;
	if(xorout[14]=='1') sboxuse+=4;
	if(xorout[15]=='1') sboxuse+=2;
	if(xorout[16]=='1') sboxuse+=1;
	
	if(xorout[12]=='0'&&xorout[17]=='0') sboxuse2=S[2][0][sboxuse];
	else if(xorout[12]=='0'&&xorout[17]=='1') sboxuse2=S[2][1][sboxuse];
	else if(xorout[12]=='1'&&xorout[17]=='0') sboxuse2=S[2][2][sboxuse];
	else if(xorout[12]=='1'&&xorout[17]=='1') sboxuse2=S[2][3][sboxuse];
	
	if(sboxuse2>=8){ sboxout[8]='1'; sboxuse2-=8; }
	else sboxout[8]='0';
	if(sboxuse2>=4){ sboxout[9]='1'; sboxuse2-=4; }
	else sboxout[9]='0';
	if(sboxuse2>=2){ sboxout[10]='1'; sboxuse2-=2; }
	else sboxout[10]='0';
	if(sboxuse2>=1){ sboxout[11]='1'; sboxuse2-=1; }
	else sboxout[11]='0';
	
	//Sbox four
	sboxuse=0;
	if(xorout[19]=='1') sboxuse+=8;
	if(xorout[20]=='1') sboxuse+=4;
	if(xorout[21]=='1') sboxuse+=2;
	if(xorout[22]=='1') sboxuse+=1;
	
	if(xorout[18]=='0'&&xorout[23]=='0') sboxuse2=S[3][0][sboxuse];
	else if(xorout[18]=='0'&&xorout[23]=='1') sboxuse2=S[3][1][sboxuse];
	else if(xorout[18]=='1'&&xorout[23]=='0') sboxuse2=S[3][2][sboxuse];
	else if(xorout[18]=='1'&&xorout[23]=='1') sboxuse2=S[3][3][sboxuse];
	
	if(sboxuse2>=8){ sboxout[12]='1'; sboxuse2-=8; }
	else sboxout[12]='0';
	if(sboxuse2>=4){ sboxout[13]='1'; sboxuse2-=4; }
	else sboxout[13]='0';
	if(sboxuse2>=2){ sboxout[14]='1'; sboxuse2-=2; }
	else sboxout[14]='0';
	if(sboxuse2>=1){ sboxout[15]='1'; sboxuse2-=1; }
	else sboxout[15]='0';
	
	//Sbox five
	sboxuse=0;
	if(xorout[25]=='1') sboxuse+=8;
	if(xorout[26]=='1') sboxuse+=4;
	if(xorout[27]=='1') sboxuse+=2;
	if(xorout[28]=='1') sboxuse+=1;
	
	if(xorout[24]=='0'&&xorout[29]=='0') sboxuse2=S[4][0][sboxuse];
	else if(xorout[24]=='0'&&xorout[29]=='1') sboxuse2=S[4][1][sboxuse];
	else if(xorout[24]=='1'&&xorout[29]=='0') sboxuse2=S[4][2][sboxuse];
	else if(xorout[24]=='1'&&xorout[29]=='1') sboxuse2=S[4][3][sboxuse];
	
	if(sboxuse2>=8){ sboxout[16]='1'; sboxuse2-=8; }
	else sboxout[16]='0';
	if(sboxuse2>=4){ sboxout[17]='1'; sboxuse2-=4; }
	else sboxout[17]='0';
	if(sboxuse2>=2){ sboxout[18]='1'; sboxuse2-=2; }
	else sboxout[18]='0';
	if(sboxuse2>=1){ sboxout[19]='1'; sboxuse2-=1; }
	else sboxout[19]='0';
	
	//Sbox six
	sboxuse=0;
	if(xorout[31]=='1') sboxuse+=8;
	if(xorout[32]=='1') sboxuse+=4;
	if(xorout[33]=='1') sboxuse+=2;
	if(xorout[34]=='1') sboxuse+=1;
	
	if(xorout[30]=='0'&&xorout[35]=='0') sboxuse2=S[5][0][sboxuse];
	else if(xorout[30]=='0'&&xorout[35]=='1') sboxuse2=S[5][1][sboxuse];
	else if(xorout[30]=='1'&&xorout[35]=='0') sboxuse2=S[5][2][sboxuse];
	else if(xorout[30]=='1'&&xorout[35]=='1') sboxuse2=S[5][3][sboxuse];
	
	if(sboxuse2>=8){ sboxout[20]='1'; sboxuse2-=8; }
	else sboxout[20]='0';
	if(sboxuse2>=4){ sboxout[21]='1'; sboxuse2-=4; }
	else sboxout[21]='0';
	if(sboxuse2>=2){ sboxout[22]='1'; sboxuse2-=2; }
	else sboxout[22]='0';
	if(sboxuse2>=1){ sboxout[23]='1'; sboxuse2-=1; }
	else sboxout[23]='0';
	
	//Sbox seven
	sboxuse=0;
	if(xorout[37]=='1') sboxuse+=8;
	if(xorout[38]=='1') sboxuse+=4;
	if(xorout[39]=='1') sboxuse+=2;
	if(xorout[40]=='1') sboxuse+=1;
	
	if(xorout[36]=='0'&&xorout[41]=='0') sboxuse2=S[6][0][sboxuse];
	else if(xorout[36]=='0'&&xorout[41]=='1') sboxuse2=S[6][1][sboxuse];
	else if(xorout[36]=='1'&&xorout[41]=='0') sboxuse2=S[6][2][sboxuse];
	else if(xorout[36]=='1'&&xorout[41]=='1') sboxuse2=S[6][3][sboxuse];
	
	if(sboxuse2>=8){ sboxout[24]='1'; sboxuse2-=8; }
	else sboxout[24]='0';
	if(sboxuse2>=4){ sboxout[25]='1'; sboxuse2-=4; }
	else sboxout[25]='0';
	if(sboxuse2>=2){ sboxout[26]='1'; sboxuse2-=2; }
	else sboxout[26]='0';
	if(sboxuse2>=1){ sboxout[27]='1'; sboxuse2-=1; }
	else sboxout[27]='0';
	
	//Sbox eight
	sboxuse=0;
	if(xorout[43]=='1') sboxuse+=8;
	if(xorout[44]=='1') sboxuse+=4;
	if(xorout[45]=='1') sboxuse+=2;
	if(xorout[46]=='1') sboxuse+=1;
	
	if(xorout[42]=='0'&&xorout[47]=='0') sboxuse2=S[7][0][sboxuse];
	else if(xorout[42]=='0'&&xorout[47]=='1') sboxuse2=S[7][1][sboxuse];
	else if(xorout[42]=='1'&&xorout[47]=='0') sboxuse2=S[7][2][sboxuse];
	else if(xorout[42]=='1'&&xorout[47]=='1') sboxuse2=S[7][3][sboxuse];
	
	if(sboxuse2>=8){ sboxout[28]='1'; sboxuse2-=8; }
	else sboxout[28]='0';
	if(sboxuse2>=4){ sboxout[29]='1'; sboxuse2-=4; }
	else sboxout[29]='0';
	if(sboxuse2>=2){ sboxout[30]='1'; sboxuse2-=2; }
	else sboxout[30]='0';
	if(sboxuse2>=1){ sboxout[31]='1'; sboxuse2-=1; }
	else sboxout[31]='0';
	
	sboxout[32]='\0';
//	printf("sboxout = %s\n", sboxout);
	
	//pbox
	for(i=0; i<32; i++)	pout[i]=sboxout[P[i]-1];
	pout[32]='\0';
//	printf("pout =      %s\n", pout);
//	printf("sl   =      %s\n",sl);
	
	//xorafter
	for(i=0;i<32; i++){
		if((pout[i]=='0'&&sl[i]=='0')||(pout[i]=='1'&&sl[i]=='1')) xorafter[i]='0';
		else xorafter[i]='1';
	}
	xorafter[32]='\0';
//	printf("xor after = %s\n", xorafter);
	
	//new sl&sr
	for(i=0;i<32; i++){
		sl[i]=sr[i];
		sr[i]=xorafter[i];
	}
//	printf("sl = %s\n",sl);
//	printf("sr = %s\n",sr);
	//end func
 }
 	
	//IPinv
 if(endn==true){
 	for(i=0;i<32;i++) ipout[i]=sl[i];
 	for(i=32;i<64;i++) ipout[i]=sr[i-32];
 }
 else{
 	for(i=0;i<32;i++) ipout[i]=sr[i];
 	for(i=32;i<64;i++) ipout[i]=sl[i-32];
 }
	for(i=0;i<64;i++) first[i]=ipout[IPinv[i]-1]; // �ʱ� ���� ���� ���� 
		
}

//���� �Լ� 
int main(){
	int run, i, j;
	run=1;
	
	FILE *fp; //("en.txt"); //des.txt ��ȣȭ �� ������ ���� 
	FILE *fq; //("entodn.txt"); //des_en.txt ��ȣȭ�� ���� �Ǵ� ��ȣȭ �� ������ ���� 
	FILE *fr; //("ento.txt"); //des_dn.txt ��ȣȭ�� ������ ���� 
	
	char endnchar; //��ȣȭ�� ���ϴ��� ��ȣȭ�� ���ϴ��� �Է¹ޱ� ���� ���� 
	char filename[26]; //���� �̸��� ���� 
	bool endn; //��ȣȭ�� ���ϴ��� ��ȣȭ�� ���ϴ��� �Է� ���� �Ϳ� ���� �� 
	//bool endn =true; //��ȣȭ 
	//bool endn=false; //��ȣȭ 
	
	//mode
	while(1){
		printf("enter the mode(encryption is e, decryption is d) "); //���� �Է��� ���� ������Ʈ 
		scanf("%c",&endnchar); //��ȣȭ�� �� ������ ��ȣȭ�� �� ������ �Է¹��� 
		//endnchar&=0xff;
		if(endnchar == 'e' ||endnchar == 'E'||endnchar == 'd' ||endnchar == 'D'  ) break;
		printf("\nplease enter the e or d"); //�߸��� ���� ��� �ٽ� �Է��� ���� 
	}
	
	//��ȣȭ ������ ���� ���ϸ��� �Է� �޴� �κ�
	if(endnchar == 'e' || endnchar == 'E'){  
		endn=true;
		printf("\n**************************\nenter the exsist txt file name(include .txt) ");
		scanf("%s",filename); //���� �̸��� �Է¹��� 
		filename[25]=0; 
		
		fp = fopen(filename,"r"); //�ش� ������ ���� 
		
		if(fp<0){ //�����̸� ���α׷� ���� 
			printf("inputfile missing\n");
			exit(0);
		}
		for(i=0;filename[i]!='.';i++); //��ȣȭ�� �����̸� ���� 
		filename[i++]='_'; filename[i++]='e'; filename[i++]='n'; filename[i++]='.'; filename[i++]='t'; filename[i++]='x'; filename[i++]='t'; filename[i]=0;
		fq = fopen(filename,"w"); //��ȣȭ ���� ���� 
	}
	else{ //��ȣȭ ������ ���� ���ϸ� �Է� �޴� �κ� 
		endn=false; 
		printf("\n**************************\nenter the original txt file name(include .txt) ");
		scanf("%s",filename); //���ϸ� �Է¹��� 
		filename[25]=0;
		for(i=0;filename[i]!='.';i++) ; //[���ϸ�]_en.txt������ ���� 
		filename[i++]='_'; filename[i++]='e'; filename[i++]='n'; filename[i++]='.'; filename[i++]='t'; filename[i++]='x'; filename[i++]='t'; filename[i]=0;
		
		fq = fopen(filename,"r"); //���� �� ���� �����̸� ���α׷����� 
		if(fp<0){
			printf("inputfile missing\n");
			exit(0);
		}
		for(i=0;filename[i]!='_';i++) ; // [���ϸ�]_dn.txt������ ���� 
		filename[i++]='_'; filename[i++]='d'; filename[i++]='n'; filename[i++]='.'; filename[i++]='t'; filename[i++]='x'; filename[i++]='t'; filename[i]=0; 
		fr = fopen(filename,"w");
	}

	//en buf //��ȣȭ�� ���� ������� 
	char buf[9]; //8 (1 byte) 2nible //64��Ʈ �� 1char * 8 = 1byte * 8�� �����ϱ� ���� ���� 
	char buftofirst[65]; //��ȣȭ�� ���� 64��Ʈ�� ǥ���� ���� �����ϱ� ���� ���� 
	
	//���� �ʱ�ȭ 
	buftofirst[64]=0;
	buf[8]=0;
	
	//dn buf //��ȣȭ�� ���� ������� 
	char dnbuf[65]; //64��Ʈ�� �������� ��Ʈ�� �о�� ���� ���� 
	char dnbuftofirst[65]; //��ȣȭ �� ���� �����ϱ� ���� ���� 
	char temp; //��ȣȭ �� ���� �ٽ� char���·� �ٲٱ� ���� ���� 
	
	//key input
	char keychar[9];
	
	printf("please input the key(within 8 letter) : "); //�������� key���� �Է¹��� 
	scanf("%s",keychar);
	keychar[8]=0;
	
	//change key 64bit
	for(i=0;i<8;i++){ //Ű ���� 64��Ʈ�� ǥ���ϴ� �κ� 
		if( (keychar[i]&0x80)> 0){
			key[i*8]='1';
		}
		else key[i*8]='0';
		if( (keychar[i]&0x40)> 0){
			key[i*8+1]='1';
		}
		else key[i*8+1]='0';
		if( (keychar[i]&0x20)> 0){
			key[i*8+2]='1';
		}
		else key[i*8+2]='0';
		if( (keychar[i]&0x10)> 0){
			key[i*8+3]='1';
		}
		else key[i*8+3]='0';
		if( (keychar[i]&0x08)> 0){
			key[i*8+4]='1';
		}
		else key[i*8+4]='0';
		if( (keychar[i]&0x04)> 0){
			key[i*8+5]='1';
		}
		else key[i*8+5]='0';
		if( (keychar[i]&0x02)> 0){
			key[i*8+6]='1';
		}
		else key[i*8+6]='0';
		if( (keychar[i]&0x01)> 0){
			key[i*8+7]='1';
		}
		else key[i*8+7]='0';
	
	}
	key[64]=0;
	
	//en part //��ȣȭ �κ� 
	if(endn == true){
		while(1){
			for(i=0; i<8; i++) buf[i]=0; //buf�� �ʱ�ȭ 
			for(i=0;i<8;i++){ //1char * 8 �� 64��Ʈ�� ������ �Է¹޴� �κ� 
				if( feof(fp) ){
					if(i!=0) for( ;i<8;i++) buf[i]=0;
					run=0;
					break;
				}
				fscanf(fp,"%c",&buf[i]);
			}
			if(i==0) break;
			
			for(i=0; i<64; i++) buftofirst[i]=0;
			//cout<<buf<<endl;
			for(i=0;i<8;i++){ //�Է¹��� ������ 64��Ʈ�� char�� �ٲٴ� �κ� 
				if( (buf[i]&0x80)> 0){
					buftofirst[i*8]='1';
				}
				else buftofirst[i*8]='0';
				if( (buf[i]&0x40)> 0){
					buftofirst[i*8+1]='1';
				}
				else buftofirst[i*8+1]='0';
				if( (buf[i]&0x20)> 0){
					buftofirst[i*8+2]='1';
				}
				else buftofirst[i*8+2]='0';
				if( (buf[i]&0x10)> 0){
					buftofirst[i*8+3]='1';
				}
				else buftofirst[i*8+3]='0';
				if( (buf[i]&0x08)> 0){
					buftofirst[i*8+4]='1';
				}
				else buftofirst[i*8+4]='0';
				if( (buf[i]&0x04)> 0){
					buftofirst[i*8+5]='1';
				}
				else buftofirst[i*8+5]='0';
				if( (buf[i]&0x02)> 0){
					buftofirst[i*8+6]='1';
				}
				else buftofirst[i*8+6]='0';
				if( (buf[i]&0x01)> 0){
					buftofirst[i*8+7]='1';
				}
				else buftofirst[i*8+7]='0';
				
			}
			
			buftofirst[64]=0; //Ȥ�� ���� ���κ� �ʱ�ȭ 
			
			//cout<<"pl " << buftofirst << endl;
			
			des(buftofirst,true); //��ȣȭ�� �����ϴ� �κ� 
			
			//cout<<"en " << buftofirst <<endl;
			
			buftofirst[64]=0;// Ȥ�� ���� �ٽ� �ʱ�ȭ
			 
			fprintf(fq,"%s",buftofirst); //��ȣȭ �� ���� [���ϸ�]_en.txt�� ���� 
			
			//des(buftofirst,false);
			//cout<<"dn " << buftofirst <<endl;
			
			if(run==0) break;
		}
		printf("create file : %s\n",filename); //������ ���� �Ǿ����� �˸��� �κ� 
	}
	
	//it is using main empty less
	//endn=true;
	
	if(endn==false){
		while(1){
			
			for(i=0;i<64;i++) dnbuf[i]=0; //�ʱ�ȭ �κ�
			 
			for(i=0;i<64;i++){ //64bit�� �о���� �κ� 
				if( feof(fq) ){
					//for(;i<64;i++) dnbuf[i]=0;
					run=0;
					break;
				}
				fscanf(fq,"%c",&dnbuf[i]);
				//cout<<dnbuf[i]<<endl;
			}
			
			dnbuf[64]=0; 
			
			if(run==0) break;
			
			//cout<<dnbuf<<endl;
			
			des(dnbuf,false); //��ȣȭ ���� ���� 
			dnbuf[64]=0; 
			
			//cout<<dnbuf<<endl;
			
			for(i=0;i<8;i++){ //��ȣȭ �� ���� char�� ǥ���ϴ� ���� 
				temp=0x00;
				if(dnbuf[8*i]=='1'){
					temp |= 0x80;
				}
				if(dnbuf[8*i+1]=='1'){
					temp |= 0x40;
				}
				if(dnbuf[8*i+2]=='1'){
					temp |= 0x20;
				}
				if(dnbuf[8*i+3]=='1'){
					temp |= 0x10;
				}
				if(dnbuf[8*i+4]=='1'){
					temp |= 0x08;
				}
				if(dnbuf[8*i+5]=='1'){
					temp |= 0x04;
				}
				if(dnbuf[8*i+6]=='1'){
					temp |= 0x02;
				}
				if(dnbuf[8*i+7]=='1'){
					temp |= 0x01;
				}
				//cout << temp;
				//buf[i]=temp;
				
				if(temp!=0) fprintf(fr,"%c",temp);
			}
			//cout<<buf<<endl;
			
			
			if(run==0) break;
			
		}
		printf("create file : %s\n",filename); //������ �����Ǿ����� �˷��ִ� �κ� 
	}	
		
	


	return 0;
}

