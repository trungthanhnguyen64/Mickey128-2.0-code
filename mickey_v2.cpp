#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int xorr(int a,int b)                                                     //xor operation
{
  if(a==b)
  return 0;
  else
  return 1;
}
int andd(int a, int b)                                                   //and operation
{
  if(a==1 && b==1)
  return 1;
  else
  return 0;

}
int clock_r(int r[], int input_bit_r, int control_bit_r)
{ int tap[] ={0,4,5,8,10,11,14,16,20,25,30,32,35,36,38,42,43,46,50,51,53,54,55,56,57,60,61,62,63,
              65,66,69,73,74,76,79,80,81,82,85,86,90,91,92,95,97,100,101,105,106,107,108,109,111,
			  112,113,115,116,117,127,128,129,130,131,133,135,136,137,140,142,145,148,150,152,153,154,156,157};
  int r_clocked[160];
  int feedback_bit,k;
  k=0;                                                                                          //tap counter
  feedback_bit = xorr(r[159],input_bit_r);
  for(int i=0;i<160;i++)
  { if(i==0)
    r_clocked[i]=0;
    else{
      r_clocked[i]= r[i-1];
    }
  if(i==tap[k])
  {
    r_clocked[i]=xorr(r_clocked[i],feedback_bit);
    k++;
  }
  if(control_bit_r==1)
  r_clocked[i]=xorr(r_clocked[i],r[i]);
  }
for(int i=0;i<160;i++){r[i]=r_clocked[i];}
}
  

int clock_s(int s[],int input_bit_s,int control_bit_s)
{
int comp0[]={'\0',1,1,1,1,0,1,0,0,1,0,0,1,1,1,1,0,1,1,0,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,1,0,0,0,0,0,1,1,0,0,1,0,0,1,0,0,1,1,1,1,0,0,1,0,0,0,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,0,1,0,0,0,1,1,0,0,1,0,0,1,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,0,1,1,0,0,0,1,1,1,1,1,0,1,0,1,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,'\0'};
int comp1[]={'\0',0,0,0,1,1,0,0,1,1,1,1,1,0,0,0,1,0,0,1,1,0,0,0,1,0,1,1,1,1,1,0,0,0,0,1,1,0,0,1,0,0,1,1,1,1,0,0,0,1,1,0,1,1,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,0,1,0,0,0,1,0,1,1,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,1,1,0,0,1,1,0,1,0,1,0,1,1,0,1,1,1,0,1,1,0,1,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,'\0'};
int fb0[]={1,1,1,1,0,1,0,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,0,1,1,0,0,0,1,0,1,1,1,1,1,0,1,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,1,1,0,1,1,0,0,1,0,1,0,1,0,0,1,1,1,0,1,1,0,0,1,1,0,1,0,0,0,1,0,0,1,1,1,0,1,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1};
int fb1[]={1,1,0,1,0,1,0,1,1,1,1,0,1,1,1,0,0,0,1,0,1,1,1,1,1,1,0,1,1,0,0,1,0,0,0,0,1,0,0,1,0,0,1,1,0,0,0,1,1,0,0,1,1,1,1,0,0,0,0,0,1,1,1,0,0,1,1,0,1,1,0,1,0,0,0,1,1,0,0,0,0,1,0,1,1,0,0,1,1,1,1,1,0,1,1,0,1,1,1,0,0,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,0,0,1,0,0,0,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,1,1,1,1,0,0,1,0,1,1,0,0,0,1,0,0,0};
int s_i[160],s_clocked[160];
int feedback_bit=xorr(s[159],input_bit_s);
s_i[0]=0;
s_i[159]=s[158];
for (int i=1;i<159;i++)
{
s_i[i]=xorr(s[i-1],andd(xorr(s[i],comp0[i]),xorr(s[i+1],comp1[i])));
}
if(control_bit_s==0)
{
  for (int i=0;i<160;i++)
  {
    s_clocked[i]=xorr(s_i[i],andd(fb0[i],feedback_bit));
  }
}
else{

    for (int i=0;i<160;i++)
    {
      s_clocked[i]=xorr(s_i[i],andd(fb1[i],feedback_bit));
}

}
for(int i=0;i<160;i++){s[i]=s_clocked[i];};
}
void clock_kg(int r[], int s[],int mixing, int input_bit)
{ int input_bit_r;
  int control_bit_r=xorr(s[53], r[105]);
  int control_bit_s=xorr(s[105], r[52]);
  if (mixing==1)
    input_bit_r=xorr(input_bit,s[80]);
  else
    input_bit_r=input_bit;
  int input_bit_s=input_bit;
  int r_cl[160],s_cl[160];
clock_r(r,input_bit_r,control_bit_r);
clock_s(s,input_bit_s,control_bit_s);

}

int main()
{
  int key[128], iv[80], z[64], l, r[160],s[160];

  printf("Enter length of keystream to be generated(<= 2^64-bit) \n" );
	scanf("%d", &l );
	printf("Enter The 128-bit key \n" );
   
//  for (int j = 0; j< 80; j++)
//		{
//		scanf("%d", &key[j]);
//		printf("key[%d]=%d\n",j+1,key[j]);}
	srand((int)time(0));
    for (int j = 0; j < 128; j++)
    {
        key[j] = rand() % 2;
        printf("%d",key[j]);
    }

  printf("\nEnter the value for iv (80-bit)\n" );
//  for (int j=0; j < 40; j++)
//   	{  
//       scanf("%d", &iv[j]);
//	   printf("iv[%d]=%d\n",j+1,iv[j]);}          
	 for (int j = 0; j < 80; j++)
    {	
        iv[j] = rand() % 2;
        printf( "%d", iv[j]);
    }
//initialising register R and S value as 0
  for(int i = 0; i < 160; i++)
	{
  		r[i]=0;
  		s[i]=0;
	}

	for (int i=0;i<80;i++)                                         //loading in IV
		clock_kg(r,s,1,iv[i]);

	for (int i = 0; i < 128; i++)                                           //loading in key
		clock_kg(r,s,1,key[i]);

	for (int i=0;i<160;i++)                                               //prelock
		clock_kg(r,s,1,0);

	for(int i=0;i<l;i++)                                        //Generating keystream
	{
		z[i]= xorr(r[0],s[0]);
  		clock_kg(r,s,0,0);
	}

  printf("\nThe generated keystream is: \n");
  for(int i = 0; i < l; i++)
    printf("%d ",z[i]);

}


