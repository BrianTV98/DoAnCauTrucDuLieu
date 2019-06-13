#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include "mylib.h"
using namespace std;
void dao_nguoc_so(int a[]);
char *getMaVatTu1(){
	nohidecursor();
	colorDialogue();
	char key;
	char *str= new char [11];
	int i=-1;
	int j=-1;// j la bien chay cua left va  right;
	bool OK=false;// khoi tao bien dung vong lap
	gotoxy(wherex(),wherey());
	do{
		if(kbhit()){
			key=getch();
			switch(key){
				case 27:{
					
					break;
				}
				case 13:{
					if(i==9||(i==0&&str[i]=='0')) 
					OK=true;
					break;
				}	
				case 77:{// right
				// chi chay khi j>-1;
					if(j>-1){
						j--;
						gotoxy(wherex()+1, wherey());
					}
					break;
				}
				case 75:{// left;
					// chi chay khi j<i;
					if(j<i){
						gotoxy(wherex()-1, wherey());
						j++;
						// cho phep sua tai vi tri nay;
					}
					break;
				}
				case 8:{// chi xoa khi mang #rong
					if(j==-1){
						if(i>-1){
						gotoxy(wherex()-1,wherey());
						cout<<" ";
						gotoxy(wherex()-1,wherey());
						str[i]='\0'	;
						i--;
						}
					}
					else{
						if(j<i){
							for(int k=i-j-1;k<i;k++){
								str[k]=str[k+1];
							}
							str[i]='\0';
							i--;
							//xu ly front end
							gotoxy(wherex()-1,wherey());
//							cout<<"^";
							for(int k=0;k<=j;k++){
								cout<<str[i-j+k];
							}
							cout<<" ";
							gotoxy(wherex()-j-2,wherey());
							
						}
						
					}	
				}
				default:{
					if((key>64&&key<91)||(key>47&&key<58)){
						if(j==-1){// nhap lieu
						if(i<=8){ // 0->8 : 9 phan tu, duoi 10 phan tu moi cho nhap;
							i++;
							str[i]=key;	
							cout<<key;
							str[i+1]= '\0';
							}		
						}
						else{// sua chua
							str[i-j]=key;
							cout<<key;
							gotoxy(wherex()-1,wherey());
						}	
						break;
					}
					if(key>96&&key<123){
						key= key-32;
						if(j==-1){// nhap lieu
						if(i<=8){ // 0->8 : 9 phan tu, duoi 10 phan tu moi cho nhap;
							i++;
							str[i]=key;	
							cout<<key;
							str[i+1]= '\0';
							}		
						}
						else{// sua chua
//							i++;
//							for(int k=0;k<j;k++){
//								str[i-j+k+1]=str[j-j+k];
//							}
							str[i-j]=key;
							cout<<key;
							gotoxy(wherex()-1,wherey());
						}	
						break;
					}
				}				
			}
		}
	}while(OK!=true);
	hidecursor();
	ColorUI();
	return str;
}

int getNumber1(){
	char key;
	char str[6];
	int i=-1;
	int j=-1;// j la bien chay cua left va  right;
	bool OK=false;// khoi tao bien dung vong lap
	gotoxy(3,7);
	do{
		if(kbhit()){
			key=getch();
			switch(key){
				case 13:{
//					if(i==9) 
					OK=true;
					break;
				}	
				case 77:{// right
				// chi chay khi j>-1;
					if(j>-1){
						j--;
						gotoxy(wherex()+1, wherey());
					}
					break;
				}
				case 75:{// left;
					// chi chay khi j<i;
					if(j<i){
						gotoxy(wherex()-1, wherey());
						j++;
						// cho phep sua tai vi tri nay;
					}
					break;
				}
				case 8:{// chi xoa khi mang #rong
					if(j==-1){
						if(i>-1){
						gotoxy(wherex()-1,wherey());
						cout<<" ";
						gotoxy(wherex()-1,wherey());
						str[i]='\0'	;
						i--;
						}
					}
					else{
						if(j<i){
							for(int k=i-j-1;k<i;k++){
								str[k]=str[k+1];
							}
							str[i]='\0';
							i--;
							//xu ly front end
							gotoxy(wherex()-1,wherey());
//							cout<<"^";
							for(int k=0;k<=j;k++){
								cout<<str[i-j+k];
							}
							cout<<" ";
							gotoxy(wherex()-j-2,wherey());
							
						}
						
					}	
				}
				default:{
					if(key>47&&key<58)
					if(j==-1){// nhap lieu
						if(i<=8){ // 0->8 : 9 phan tu, duoi 10 phan tu moi cho nhap;
							i++;
							str[i]=key; // ko hien ra ma ki tu ma hien ra ma ascii	
							cout<<key;
							str[i+1]= '\0';
						}		
					}
					else{// sua chua
						str[i-j]=key; // ko hien ra ki tu ma hien ra ma ascii;
						cout<<key;
						gotoxy(wherex()-1,wherey());
					}	
					break;
				}				
			}
		}
	}while(OK!=true);
	cout<<endl;
	int tong=0;
//	dao_nguoc_so(str);
	int count=0;
	for(int i=0;i<6;i++){
		cout<<str[i];
	}
	cout<<endl;
	while(str[count]){
//		cout<<str[count]<<"\t";
		tong=tong*10 +(int)(str[count]-'0');
		count++;
	}
	cout<<"ok";
	

	cout<<tong;
	return 0;

}
void dao_nguoc_so(int a[]){
	int buffer;
	for(int i=0;i<3;i++){
		buffer= a[i];
		a[i]=a[5-i];
		a[5-i]=buffer;
	}
}
// nhap vao chuoi char... cho phep bat phim qua lai. de chinh sua.
int main(){
	char ma[11];
	strcpy(ma,getMaVatTu1());
	cout<<endl<<ma;
//	int a[6]={0,1,2,4,0,0};
//	dao_nguoc_so(a);
//	for(int i=0;i<6;i++){
//		cout<<a[i];
//	}
}
