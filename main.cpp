#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <sstream>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Cautruc.h"
#include "mylib.h"
#include "head.h"
#include "UI.h"
#include "VatTu.cpp"
#include "NhanVien.cpp"
#include "DocGhiFile.cpp"
#include "CT_HD.cpp"
#include "HoaDon.cpp"
#include "DoanhThu.cpp"
#define Up 72
#define Dow 80
#define Enter 13
#define Left 77
#define Right 75
#define BackSpace 32
#define Esc 27
#define MAX_CTHD 20
using namespace std;
//----- prototype----------------------------

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
NODEVATTU rootVatTu;
int main(){

	//----- Khai bao cau truc root----
	InitVatTu(rootVatTu); 
//	gotoxy(40,40);if(rootVatTu==NULL) cout<<"Danh Sach Vat Tu rong!"; // test
	DocfileVatTu(rootVatTu);
//	gotoxy(40,41);if(rootVatTu==NULL) cout<<"Nhap xong no het rong!";// test
	//khoi tao nhan vien;
	LISTNHANVIEN ls;
	InitNhanVien(ls);
	
	DocfileNhanVien(ls);
	
	//---------------------------------
	//----- code xu ly----------------
	string *Mn= new string[9];
	int n=InitMenu(Mn);
	int key=-1;
	UI();// ve khung giao dien vao..
	//**UI
	DocDSHoaDon(ls);
	ChonChucNang:
	do{
		KhungTrangThai(HCN(2,16),HCN(160,50),1);
		XoaTrangThai(-1,-1);
		key= MenuTONG(1,3,Mn,n);	
		switch(key){
			case 0:{
				while(true){
					KhungTrangThai(HCN(2,16),HCN(160,50),1);
					int key2=ShowMenuPhu(0,70,6);
					switch(key2){
						case 0:{
							Create_nodeVatTu(rootVatTu);
							break;
						}
						case 1:{
							HieuChinhVatTu(rootVatTu);
							
							break;
						}
						case 2:{
							XoaVatTu(rootVatTu);
							break;
						}
						case 3:{
//							
							break;
						}
					}
					if(key2==3) break;
				}
				break;
			}
			case 1:{

				if(rootVatTu==NULL){
					gotoxy(4,17);
					cout<<"Danh sach vat tu rong! ";
					if(Thoat()==true) KhungTrangThai(HCN(2,16),HCN(160,50),1);
				}
				else{
					ColorUI();
					gotoxy(20,16);cout<<"MA ";
					gotoxy(60,16);cout<<"TEN";
					gotoxy(100,16);cout<<"DVT";
					gotoxy(140,16);cout<<"SLT";
					gotoxy(1,17);
					VeDuongThangNgang(2,160,17);
					HienThiDanhSachVatTu(rootVatTu);
					if(Thoat()==true) KhungTrangThai(HCN(2,16),HCN(160,50),1);
				}	
				getch();
				break;
			}
			case 2:{
				while(true){
					KhungTrangThai(HCN(2,16),HCN(160,50),1);
					int key3=ShowMenuPhu(0,70,6);
						switch(key3){
							case 0:{
								NhapDanhSachNhanVien(ls);
								break;
							}
							case 1:{
								HieuChinhNhanVien(ls);
								break;
							}
							case 2:{
								XoaNhanVien(ls);
								break;
							}
							case 3:{						
								break;
							}
						}
						if(key3==3) break;
					}
					break;
			}
			case 3:{
				HienThiDanhSachNhaVien(ls);
				break;
			}
			case 4:{
				ChucNangLapHoaDon(ls,rootVatTu);
				CapNhapFileVatTu(rootVatTu);
				break;
			}
			case 5:{
				KhungTrangThai(HCN(2,16),HCN(50,17),0);  // boi den nen hien thi cho dong nhap hoa don
				gotoxy(3,16); cout<<"Nhap Ma HD: ";
				char *soHD= getMa(20);
				if(InHoaDon(ls,soHD)==false){
					TrangThai(-1,-1,"Danh Sach Rong!");
				}
				else XoaTrangThai(-1,-1);
				if(Thoat()==true) 	
				break;
			}
			case 6:{
				KhungTrangThai(HCN(2,16),HCN(160,17),0);
				DateAndTime ngayDau,ngayCuoi;
				gotoxy(3,16);
				cout<<"Nhap ngay: (YY/MM/DD) ";
				gotoxy(50,16);cout<<"Den Ngay: (YY/MM/DD) ";
				gotoxy(30,16);ngayDau=getNgayLapHoaDon();
				gotoxy(75,16);ngayCuoi=getNgayLapHoaDon();
				int kt=ThongKeHoaDon(ls,ngayDau,ngayCuoi);
				if(kt==0) TrangThai(-1,-1,"D/S Rong") ;
				if(Thoat()==true){
					break;
				}
//				KhungTrangThai(HCN(2,16),HCN(160,50),1); //  in full danh sach
//				if(InFullHoaDon(ls)==false){
//					TrangThai(-1,-1,"DanhSachRong");
//				}	
				break;
			}
			case 7:{
				KhungTrangThai(HCN(2,16),HCN(160,17),0);
				DateAndTime ngayDau,ngayCuoi;
				gotoxy(3,16);
				cout<<"Nhap ngay: (YY/MM/DD) ";
				gotoxy(50,16);cout<<"Den Ngay: (YY/MM/DD) ";
				gotoxy(30,16);ngayDau=getNgayLapHoaDon();
				gotoxy(75,16);ngayCuoi=getNgayLapHoaDon();
				PTRDOANHTHU ptrDoanhThu=NULL;
				ThongKeTriGiaHoaDon(ls,ngayDau,ngayCuoi,ptrDoanhThu);
				DuyetDanhSachThongKeGia(ptrDoanhThu,rootVatTu);
				if(Thoat()==true){
					break;
				}
			
			}
			case 8:{
				return 0;
				break;
			}
			default: {
				break;
			}
		}
	}while(true); 
	SetBGColor(5);
	getch();
	return 0;
}
