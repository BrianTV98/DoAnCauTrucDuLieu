//#include <conio.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <windows.h>
//#include<iostream>
//
//#include<string.h>
//#include "mylib.h"
//#include "CauTruc.h"
////#include "HoaDon.cpp";
//#define MaxVatTu 20
//using namespace std;
//
//int main(){
//		
//}
bool is_EmptyCTHD(HOADON hd){
	return (hd.n==-1)? true:false;	
}
bool is_FullCTHD(HOADON hd){
	return(hd.n<20)?false :true;
}
int Insert_CTHoaDon(HOADON &hd,CT_HOADON cthd){// chen sau;
	int j;
//	if(i<0||i>hd.n+1||is_FullCTHD(hd)){ 
//		return 0;
//	}
	if(is_FullCTHD(hd)) return 0;
	hd.n++;
	
//	for(int j=hd.n;j>=i;j--){
//		hd.dscthd[j]=hd.dscthd[j-1];
//	}
	hd.dscthd[hd.n]=cthd;
	return 1;
}
CT_HOADON LapCTHoaDon(char *Ma){
	colorDialogue();
	CT_HOADON cthd;
	strcpy(cthd.MAVT,Ma);
	gotoxy(3,23);        cout<<"Nhap so luong:  ";
	gotoxy(3,wherey()+1);cout<<"Nhap Don Gia :   ";
	gotoxy(3,wherey()+1);cout<<"Nhap Vat     :   ";
	gotoxy(20,23);cthd.Sl=getNumber(3);
	gotoxy(20,wherey()+1);cthd.DonGia=getNumber(10);
	gotoxy(20,wherey()+1);cthd.Vat=getNumber(2);
	return cthd;
}
void InVaTuCT(CT_HOADON cthd){
	gotoxy(80, wherey());cout<<cthd.MAVT; 
	gotoxy(100, wherey());cout<<cthd.Sl;
	gotoxy(120, wherey());cout<<cthd.DonGia;
	gotoxy(140, wherey());cout<<cthd.Vat<<endl;
}
int Delete_CTHD(HOADON &hd, int i){
	int j;
	if(i<0||i>hd.n||is_EmptyCTHD(hd)==true)
		return 0;
	for(j=i+1;j<hd.n;j++)
		hd.dscthd[j-1]=hd.dscthd[j];
	hd.n;
	return 1;
}
void DuyetCTDH(HOADON hd){
	if(is_EmptyCTHD(hd)==true){
		cout<<"Danh Sach rong";
		return;
	}
	for(int i=0;i<=hd.n;i++){
		InVaTuCT(hd.dscthd[i]);
	}
}
bool KiemTraTrungCTDH(HOADON hd,char *ma){
	int i;
	if(is_EmptyCTHD(hd)==true){
//		cout<<"Danh Sach rong";
		return false;
	}
	for(int i=0;i<=hd.n;i++){
		if(strcmp(hd.dscthd[i].MAVT,ma)==0){
			return true;
		}
	}
	return false;
}
int Search_CTHD(HOADON hd, char *ma){
	for(int i=0;i<hd.n;i++){
		if(strcmp(hd.dscthd[i].MAVT,ma)==0){
			InVaTuCT(hd.dscthd[i]);
		}
	}
}
