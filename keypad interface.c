#include <reg51.h>

//Pin declaring for LCD
sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;

//Pin declaration for rows and colums of keypad

sbit C1=P1^0;
sbit C2=P1^1;
sbit C3=P1^2;
sbit C4=P1^3;
sbit R1=P1^4;
sbit R2=P1^5;
sbit R3=P1^6;
sbit R4=P1^7;


void lcdcmd(char);
void lcddata(char);
void lcdclr();
void delay();
void sdelay();

//row finder functions
void row_find1();
void row_find2();
void row_find3();
void row_find4();


void main(){
P3=0x00;//Pin3 is the output
lcdcmd(0x38);//intialization
lcdclr();

	while(1){
		C1=C2=C3=C4=1;
		R1=R2=R3=R4=0;
		if(C1==0){
		row_find1();
		sdelay();}
		else if(C2==0){
		row_find2();
		sdelay();}
		else if(C3==0){
		row_find3();
		sdelay();}
		else if(C4==0){
		row_find4();
		sdelay();}
	
	
	}

}


void lcdcmd(char var){
		P3=var;
		rs=0;
	rw=0;//command mode
	en=1;
	delay();
	en=0;
}

 void lcddata(char var){
	 lcdclr();
	 delay();
	P3=var;
	rs=1;
	rw=0;
	en=1;
	delay();
	en=0;}

void delay(){
	int a;
	for (a=0;a<15000;a++){
	}
}

void sdelay(){
	int i;
	for (i=0;i<7000;i++)
	{}
	}

	void lcdclr(){
		lcdcmd(0x01);
		delay();
		lcdcmd(0x0c);
	}
	
	
	
	//row functions 
	void row_find1(){
		R1=R2=R3=R4=1;
		C1=C2=C3=C4=0;
		if(R1==0){
			lcddata('7');
			sdelay();
		}
		else if(R2==0){
			lcddata('4');
			sdelay();
		}
		else if(R3==0){
			lcddata('1');
			sdelay();
		}
		
		else if(R4==0){
			lcddata('*');
			sdelay();
		}
	}
	
	void row_find2(){
		R1=R2=R3=R4=1;
		C1=C2=C3=C4=0;
		if(R1==0){
			lcddata('8');
			sdelay();
		}
		else if(R2==0){
			lcddata('5');
			sdelay();
		}
		else if(R3==0){
			lcddata('2');
			sdelay();
		}
		
		else if(R4==0){
			lcddata('0');
			sdelay();
		}
	}
	
	void row_find3(){
		R1=R2=R3=R4=1;
		C1=C2=C3=C4=0;
		if(R1==0){
			lcddata('9');
			sdelay();
		}
		else if(R2==0){
			lcddata('6');
			sdelay();
		}
		else if(R3==0){
			lcddata('3');
			sdelay();
		}
		
		else if(R4==0){
			lcddata('#');
			sdelay();
		}
	}
	
	void row_find4(){
		R1=R2=R3=R4=1;
		C1=C2=C3=C4=0;
		if(R1==0){
			lcddata('A');
			sdelay();
		}
		else if(R2==0){
			lcddata('B');
			sdelay();
		}
		else if(R3==0){
			lcddata('C');
			sdelay();
		}
		
		else if(R4==0){
			lcddata('D');
			sdelay();
		}
	}