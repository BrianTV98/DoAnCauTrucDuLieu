//#include <conio.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <windows.h>
//#include <iostream>
//#include <fstream>
//#include "Cautruc.h"
//#include "mylib.h"
//#include "head.h"
//#include "UI.h"
//#include "VatTu.h"
//#include "NhanVien.h"
//#include "DocGhiFile.h"
//#include "CT_HD.cpp"
//
//using namespace std;

//int main(){
//	LISTNHANVIEN ls;
//	InitNhanVien(ls);
//	DocfileNhanVien(ls);
//	NODEVATTU nodeVatTu;
//	InitVatTu(nodeVatTu);
//	DocfileVatTu(nodeVatTu);
//	ChucNangLapHoaDon(ls,nodeVatTu);
//	return 0;	
//}
//PTRHoaDOn getDSHoaDon(LISTNHANVIEN &ls,NODEVATTU nodeVatTu){
//	PTRHoaDOn firs;//=new NodeHoaDon;
//NhapTiep:	HOADON hd=NhapHoaDon(ls,nodeVatTu);
//	Insert_First(firs,hd);
//	if(TiepTuc()==true) goto NhapTiep;
//	return firs;
//}
void InitDSCTHoaDon(HOADON &hoaDon){
	hoaDon.n=-1;
}
void ChucNangLapHoaDon(LISTNHANVIEN ls,NODEVATTU nodeVatTu){
	char *maNV;
	char *maHD;
	char *maVT;
	int k=0;
	HOADON hoaDon;
	InitDSCTHoaDon(hoaDon);
	CT_HOADON cthd;
NhapMaNhanVien:
	XoaTrangThai(-1,-1);
	KhungTrangThai(HCN(2,16),HCN(160,50),1);
	KhungTrangThai(HCN(3,16),HCN(40,17),0);
	
	gotoxy(3,16); cout<<"Nhap Ma NV: ";
	gotoxy(20,16);maNV=getMa(10);
	NhanVien *p;
	p=Search_infor_NhanVien(ls,maNV);
	if(p){ // ma khong bi trung
		XoaTrangThai(-1,-1);
		goto NhapMaHoaDon;	
	}
	else{ // ma bi trung
		TrangThai(-1,-1,"khong ton tai NV nay");
		if(TiepTuc()==true){
			goto NhapMaNhanVien;
		}
		else return;
	}
NhapMaHoaDon:
	KhungTrangThai(HCN(3,18),HCN(50,21),0);
	
	gotoxy(3,18);        cout<<"So Hoa Don        :";
	gotoxy(3,wherey()+1);cout<<"Loai Hoa Don (N/X):";
	gotoxy(3,wherey()+1);cout<<"Ngay (YY/MM/DD)   :";
	
	gotoxy(25,18);  maHD=getMa(20);
	PTRHoaDOn pHoaDon=KiemTraMaHoaDon(ls,maHD);
	if(!pHoaDon){//ma khong bi trung
		XoaTrangThai(-1,-1);
	  	strcpy(hoaDon.SoHD,maHD);
		gotoxy(25,19);hoaDon.Loai=getLoai('N','X');
		gotoxy(25,wherey()+1);hoaDon.dateAndTime=getNgayLapHoaDon();
		goto NhapCTHD;
	}
	else{
		TrangThai(-1,-1,"So HD bi trung!");
		goto NhapMaHoaDon;
	}
NhapCTHD:
	KhungTrangThai(HCN(3,22),HCN(50,27),0);
	
	gotoxy(3,22);cout<<"Nhap Ma Vat Tu:";
	maVT=getMa(10);
	NODEVATTU pVatTu=search(nodeVatTu,maVT);
	if(pVatTu&&KiemTraTrungCTDH(hoaDon,maVT)==false){ // ton tai vat tu va vat tu thi ko bi trung lap
		strcpy(cthd.MAVT,maVT);
		colorDialogue();
		gotoxy(3,23);        cout<<"Nhap so luong:  ";
		gotoxy(3,wherey()+1);cout<<"Nhap Don Gia :   ";
		gotoxy(3,wherey()+1);cout<<"Nhap Vat     :   ";
NhapSoLuong:
		KhungTrangThai(HCN(20,23),HCN(30,24),0);		
		gotoxy(20,23);cthd.Sl=getNumber(3);
		if(hoaDon.Loai=='N') {
			if(HieuChinhSoLuongTon(nodeVatTu,cthd.MAVT,cthd.Sl)==false){
				goto NhapSoLuong;
			}
		}
		else{
			if(HieuChinhSoLuongTon(nodeVatTu,cthd.MAVT,-cthd.Sl)==false){
//				string str="Ton Kho :" ;//+ search(nodeVatTu,cthd.MAVT)->vatTu.SLT;
//				TrangThai(-1,-1, str);
				goto NhapSoLuong;
			}
		}
		gotoxy(20,wherey()+1);cthd.DonGia=getNumber(10);
		gotoxy(20,wherey()+1);cthd.Vat=getNumber(2);
		k=Insert_CTHoaDon(hoaDon,cthd);	
		
		if(k==1){
			In_1_HoaDon(hoaDon,80, 16);
			TrangThai(-1,-1,"Nhap Thanh Cong! ");
		}
		else{
			TrangThai(-1,-1,"Nhap That Bai ! ");
		}
	while(true){
		int maHoi=ESC_ENTER_F2();
		if(maHoi==1){ // nhap lai
			goto NhapCTHD;
		}
		if(maHoi==2){ // thoat
			GhiHoaDon(hoaDon,maNV);
//			Insert_First(ls.dsnv[searchIndexInsert(ls,maNV,0,ls.sl)]->DSHoaDon,hoaDon);	
			Insert_First(ls.dsnv[Search_index_NhanVien(ls,maNV)]->DSHoaDon,hoaDon);
			break;		
		}
		if(maHoi==3){ // xoa 1 vat tu trong chi tiet hoa don
			KhungTrangThai(HCN(3,22),HCN(50,27),0);
			gotoxy(3,22); cout<<"Nhap Ma Can Xoa: ";
NhapMaXoa:	
			char *temp= getMa(10);
			if(KiemTraTrungCTDH(hoaDon,temp)){
				Xoa_1_VatTu_CTHD(hoaDon,temp);
				KhungTrangThai(HCN(80,16),HCN(127,50),1);
				In_1_HoaDon(hoaDon,80, 16);
				
			}
			else {
				TrangThai(-1,-1,"Khong Ton Tai Ma!");
				if(TiepTuc()==true) goto NhapMaXoa;
			}
			 // 
		}	
	}
		
	}
	else{
		if(KiemTraTrungCTDH(hoaDon,maVT)==true){// neu trung lam thi bao trung lap
			TrangThai(-1,-1,"Trung lap!");
		}
		else TrangThai(-1,-1,"Khong Ton Tai Vat Tu!");
		goto NhapCTHD;
	}
	
//	gotoxy(20,35);cout<<ls.dsnv[searchIndexInsert(ls,maNV,0,ls.sl)]->DSHoaDon->hoadon.dscthd[0].Vat;
//NhapMaChucNang:
//	KhungTrangThai(HCN(3,16),HCN(40,17),0);
//	colorDialogue();
//	gotoxy(3,16);cout<<"Nhap Ma Nhan Vien: ";
//	char *MaNV=getMa(10);
//	if(strcmp(MaNV,"0")==0) {
//		KhungTrangThai(HCN(3,16),HCN(40,17),1);
//		return ;
//	}
//	NhanVien *kiemtra=searchNhanVienBinary(ls,MaNV,0,ls.sl);
//	LISTNHANVIEN p;
//	if(!kiemtra){
//		TrangThai(-1,-1,"Khong ton tai Nhan Vien! ");
//		goto NhapMaChucNang;
//	}
//	else{
//		HOADON *hoaDon=NhapHoaDon(ls,nodeVatTu);;
//		for(int i=0;i<ls.sl;i++){
//			if(strcmp(ls.dsnv[i]->MANV,MaNV)==0){// tim thay ma , thi se tao danh sach gan danh sach cho ma;
//				if(!ls.dsnv[i]->DSHoaDon){
//					if(hoaDon){
//						ls.dsnv[i]->DSHoaDon= new NodeHoaDon;
//						Insert_First(ls.dsnv[i]->DSHoaDon,*NhapHoaDon(ls,nodeVatTu));
//					}
//					
//				}
//				else{
//					if(hoaDon){
//						Insert_First(ls.dsnv[i]->DSHoaDon,*NhapHoaDon(ls,nodeVatTu));
//					}	
//				}
//				
//				break;
//			}
//		}
//	}
}
void Xoa_1_VatTu_CTHD(HOADON &hoaDon,char *ma){
	int vitri;
	for(vitri=0;vitri<=hoaDon.n;vitri++){
		if(strcmp(hoaDon.dscthd[vitri].MAVT,ma)==0){
			for(vitri;vitri<hoaDon.n;vitri++){
				strcpy(hoaDon.dscthd[vitri].MAVT,hoaDon.dscthd[vitri+1].MAVT);
				hoaDon.dscthd[vitri].Sl=hoaDon.dscthd[vitri+1].Sl;
				hoaDon.dscthd[vitri].DonGia=hoaDon.dscthd[vitri+1].DonGia;
				hoaDon.dscthd[vitri].Vat=hoaDon.dscthd[vitri+1].Vat;
			}
		}
	}
	hoaDon.n--;
}
PTRHoaDOn KiemTraMaHoaDon(LISTNHANVIEN ls,char *ma){//trung tra ve p, ko trung tra ve NuLL
	PTRHoaDOn p;
	for(int i=0;i<=ls.sl;i++){
	
		p=ls.dsnv[i]->DSHoaDon;
		if(p){
			for(p;p!=NULL;p=p->next){
				if(strcmp(p->hoadon.SoHD,ma)==0)
				return p;	
			}
		}	
	}
	return NULL;
}
HOADON *NhapHoaDon(LISTNHANVIEN ls,NODEVATTU nodeVatTu){
//	PTRHoaDOn dshd= new NodeHoaDon;  
	HOADON *hd=new HOADON;
NhapMaHoaDon:	KhungTrangThai(HCN(3,18),HCN(50,21),0);
	colorDialogue();
	gotoxy(3,18);        cout<<"So Hoa Don        :";
	gotoxy(3,wherey()+1);cout<<"Loai Hoa Don (N/X):";
	gotoxy(3,wherey()+1);cout<<"Ngay (YY/MM/DD)   :";
	gotoxy(25,18);strcpy(hd->SoHD,getMa(20));// Nhap vao so hoa Don;	
	if(strcmp(hd->SoHD,"0")==0){ //nhap 0 de thoat
		KhungTrangThai(HCN(3,18),HCN(50,21),1);
		return NULL;
	}
	if(KiemTraMaHoaDon(ls,hd->SoHD)){
		TrangThai(-1,-1,"Ma HD Trung!");
		goto NhapMaHoaDon;
	}
	gotoxy(25,wherey()+1);hd->Loai=getLoai('N','X');// Chi nhan N (Nhap) X (Xuat)
	gotoxy(25,wherey()+1);hd->dateAndTime=getNgayLapHoaDon();
	hd->n=-1; // khoi tao so  vat tu trong hoa don la -1;
	char *ma= new char[11];
NhapMa:
	KhungTrangThai(HCN(3,22),HCN(50,27),0);	
	gotoxy(3,22);cout<<"Nhap Ma Vat Tu:";
	strcpy(ma,getMa(10));
	if(strcmp(ma,"0")==0) {
		KhungTrangThai(HCN(3,22),HCN(50,27),1);
		return NULL;
	}
	NODEVATTU p=search(nodeVatTu,ma); // kiem tra xem co ton tai vat tu do khong
	if(hd->n<MAX_CTHD){// kiem tra danh sach vat tu co bi day ko
		if(p){ // neu ton tai thi kiem tra xem trong danh sach vat tu co bi trung lap ko
				if(is_EmptyCTHD(*hd)==true){
					Insert_CTHoaDon(*hd,LapCTHoaDon(ma));
					TrangThai(-1,-1,"Chen Thanh Cong!");
					if(TiepTuc()==true) {
						XoaTrangThai(-1,-1);
						goto NhapMa;
					}
					else{
						XoaTrangThai(-1,-1);
						KhungTrangThai(HCN(3,22),HCN(50,27),1);
					}
				}
				else{
					if(KiemTraTrungCTDH(*hd,ma)==true){
						TrangThai(-1,-1,"Trung Lap!");
						goto NhapMa;
					}
					else{
						Insert_CTHoaDon(*hd,LapCTHoaDon(ma));
						
						TrangThai(-1,-1,"Chen Thanh Cong!");
						if(TiepTuc()==true) {
							XoaTrangThai(-1,-1);
							goto NhapMa;
						}
						else {
							XoaTrangThai(-1,-1);
							KhungTrangThai(HCN(3,22),HCN(50,27),1);
						}
					}
				}
			}
		
		else{
			TrangThai(-1,-1,"Khong ton tai Vat Tu nay!");
			goto NhapMa;
		}
	}	
	else{
		TrangThai(-1,-1,"Danh Sach Day!");
	} 	
}
DateAndTime getNgayLapHoaDon(){
	colorDialogue();
	int viTriX=wherex();
	int vitriY=wherey();
	DateAndTime dateAndTime;
	gotoxy(viTriX+3,vitriY); cout<<"/";
	gotoxy(viTriX+6,vitriY); cout<<"/";
	gotoxy(viTriX,vitriY);dateAndTime.year=getNumber(2);
thang:	gotoxy(viTriX+4,vitriY);
		dateAndTime.month=getNumber(2);
		if(dateAndTime.month<1||dateAndTime.month>12) {
			TrangThai(-1,-1,"Thang khong hop le!");
			goto thang; 
		}
		else{
			XoaTrangThai(-1,-1);
		}
ngay:	gotoxy(viTriX+7,vitriY);
		dateAndTime.day= getNumber(2);
		if(dateAndTime.month==1||dateAndTime.month==3||dateAndTime.month==5||
			dateAndTime.month==8||dateAndTime.month==10||dateAndTime.month==12){
				if(dateAndTime.day<1||dateAndTime.day>31){
					TrangThai(-1,-1,"Thang khong hop le!");
					goto ngay;
				}
			}
		else XoaTrangThai(-1,-1);
		if(dateAndTime.month==2&&dateAndTime.year%4==0){ //nam nhuan
			if(dateAndTime.day<1||dateAndTime.day>29){
				TrangThai(-1,-1,"Ngay khong hop le!");
					goto ngay;
			}
		}
		else XoaTrangThai(-1,-1);
		if(dateAndTime.month==2&&dateAndTime.year%4!=0){
			if(dateAndTime.day<0||dateAndTime.day>28){
				TrangThai(-1,-1,"Ngay khong hop le!");
					goto ngay;
			}
		}
		else XoaTrangThai(-1,-1);
		if(dateAndTime.month==4||dateAndTime.month==6||dateAndTime.month==9||dateAndTime.month==11){
			if(dateAndTime.day<0||dateAndTime.day>30){
				TrangThai(-1,-1,"Ngay khong hop le!");
				goto ngay;
			}
		}
		else XoaTrangThai(-1,-1);
	return dateAndTime;
}

char *getMa(int n){// n la so ki tu cho phep nhap
	nohidecursor();
	colorDialogue();
	char key;
	char *str= new char [n+1];
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
					if(i==n-1)//||(i==0&&str[i]=='0')) 
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
						if(i<=n-2){ // 0->8 : 9 phan tu, duoi 10 phan tu moi cho nhap;
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
						if(i<=n-2){ // 0->8 : 9 phan tu, duoi 10 phan tu moi cho nhap;
							i++;
							str[i]=key;	
							cout<<key;
							str[i+1]= '\0';
							}		
						}
						else{// sua chua
//							
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
void Init_DSHoaDon(PTRHoaDOn &first){
	first=NULL;
}
bool is_EmptyHoaDon(PTRHoaDOn First){
	return (First==NULL)? true:false;
} 
PTRHoaDOn newNode(){
	PTRHoaDOn p= new NodeHoaDon;
	return p;
}
void Insert_First(PTRHoaDOn &First,HOADON x){
	PTRHoaDOn p;
	p= newNode();
	//chuyen noi dung tu node a sang node p
	p->hoadon=x;
	p->next=First;
	First=p;
}
//void SaoChepNode(PTRHoaDOn &output, PTRHoaDOn ){
	
//}
void Insert_After(PTRHoaDOn p,HOADON x){ // chen vao sau phan tu  P
	PTRHoaDOn q;
	if(p=NULL){
		cout<<"Khong the them vao danh sach dc:";		
	}
	else{
		q= newNode();
		q->hoadon=x;
		q->next=p->next;
		p->next=q;
	}
}
PTRHoaDOn Search_inforHoaDon(PTRHoaDOn First,HOADON x){
	PTRHoaDOn p;
	for(p=First;p!=NULL;p=p->next){
		if(strcmp(p->hoadon.SoHD,x.SoHD)==0){
			return p;
		}
	}
}
int Delete_First(PTRHoaDOn &First){
	PTRHoaDOn p;
	if(is_EmptyHoaDon(First)==true){
		return 0;
	}
	p=First;
	First=p->next;
	Delete_First(p);
	return 1; 
}
//int delete_info(PTRHoaDOn &First, HOADON x){
//	PTRHoaDOn p=First;
//	if(is_EmptyHoaDon()==true) return 0;
//	if(strcmp(First->hoadon.SoHD,x.SoHD)==0){
//		p=First;
//		First=p->next;
//		delete p;
//		return 1;
//	}
//	for(p=First;p->next!NULL&&strcmp())
//} 
void ClearList(PTRHoaDOn &First){
	PTRHoaDOn p;
	while(First!=NULL){
		p=First;
		First=First->next;
		delete p; 
	}
}
void Traverser(PTRHoaDOn First){
	PTRHoaDOn p;
	if(p==NULL) return ;
	for(p=First;p!=NULL;p=p->next){
		DuyetCTDH(p->hoadon);
	}
}

//void Selection_Sort(PTRHoaDOn &First){
//	PTRHoaDOn p,q,pmin;
//	char min[11];
//	for(p=First;p->next=NULL;p=p->next){
//		strcpy(min,p->hoadon.SoHD);
//		pmin=p;
//		for(q=p->next;q!=NULL;q=q->next){
//			if(strcmp(q->hoadon.SoHD,min)<0){
//				min=q->hoadon;
//				pmin=q;
//			}
//		}
//		pmin->hoadon=p->hoadon;
//		p->hoadon=min
//	}
//}
bool InHoaDon(LISTNHANVIEN ls,char *ma){
	KhungTrangThai(HCN(2,17),HCN(150,18),3);
	gotoxy(3,18); cout<<"Ma NV Lap";
	gotoxy(20,wherey()); cout<< "Ngay Lap";
	gotoxy(40,wherey()); cout<<"Loai";
	gotoxy(60,wherey()); cout<<"Tong VT";
	gotoxy(80,wherey()); cout<<"Ma VT ";
	gotoxy(100,wherey()); cout<<"So luong ";
	gotoxy(120,wherey()); cout<<"Don Gia ";
	gotoxy(140,wherey()); cout<<"VAT ";
	KhungTrangThai(HCN(2,19),HCN(150,20),3);
	
	int dem=0;
	PTRHoaDOn p;
	for(int i=0;i<=ls.sl;i++){	
		if(ls.dsnv[i]->DSHoaDon!=NULL){
			for(p=ls.dsnv[i]->DSHoaDon;p!=NULL;p=p->next){
					if(strcmp(p->hoadon.SoHD,ma)==0){
						// xuat thong tin hoa 
						gotoxy(3,wherey()+1);cout<<ls.dsnv[i]->MANV;
						gotoxy(20,wherey());
						cout<<p->hoadon.dateAndTime.day<<"/"<<p->hoadon.dateAndTime.month<<"/"<<p->hoadon.dateAndTime.year;
						gotoxy(40,wherey()); cout<<p->hoadon.Loai;
						gotoxy(60,wherey());cout<<p->hoadon.n+1;
						DuyetCTDH(p->hoadon);
						dem=1;
					}
					
			}
		}		
	}
	return (dem==1) ?true:false;
}
bool InFullHoaDon(LISTNHANVIEN ls){
	KhungTrangThai(HCN(2,17),HCN(150,18),3);
	gotoxy(3,18); cout<<"Ma NV Lap";
	gotoxy(20,wherey()); cout<< "Ngay Lap";
	gotoxy(40,wherey()); cout<<"Loai";
	gotoxy(60,wherey()); cout<<"Tong VT";
	gotoxy(80,wherey()); cout<<"Ma VT ";
	gotoxy(100,wherey()); cout<<"So luong ";
	gotoxy(120,wherey()); cout<<"Don Gia ";
	gotoxy(140,wherey()); cout<<"VAT ";
	KhungTrangThai(HCN(2,19),HCN(150,20),3);
	
	int dem=0;
	PTRHoaDOn p;
	for(int i=0; i<=ls.sl; i++){	
		if(ls.dsnv[i]->DSHoaDon != NULL){
			for(p = ls.dsnv[i]->DSHoaDon; p != NULL; p = p->next){
				gotoxy(3,wherey()+1);cout<<ls.dsnv[i]->MANV;
				gotoxy(20,wherey());
				cout<<p->hoadon.dateAndTime.day<<"/"<<p->hoadon.dateAndTime.month<<"/"<<p->hoadon.dateAndTime.year;
				gotoxy(40,wherey()); cout<<p->hoadon.Loai;
				gotoxy(60,wherey());cout<<p->hoadon.n;
				DuyetCTDH(p->hoadon);
				dem=1;
			}
		}
	}
	return (dem==1)?true:false;
}
bool DocDSHoaDon(LISTNHANVIEN ls){
	int dem=0;
	PTRHoaDOn p;
	for(int i=0; i<=ls.sl; i++){
		DocHoaDon(ls.dsnv[i]->DSHoaDon, ls.dsnv[i]->MANV);	// neu ton tai danh sach thi se doc			
	}
	return (dem==1)?true:false;
}
bool ThongKeHoaDon(LISTNHANVIEN ls,DateAndTime ngayDau,DateAndTime ngayCuoi){
	KhungTrangThai(HCN(2,17),HCN(150,18),3);
	KhungTrangThai(HCN(2,19),HCN(150,20),3);
	gotoxy(6,18); cout<<"So Hoa Don";
	gotoxy(34,wherey()); cout<< "Ngay Lap";
	gotoxy(62,wherey()); cout<<"Loai Hoa Don";
	gotoxy(90,wherey()); cout<<"Ho Ten NV Lap";
	gotoxy(130,wherey()); cout<<"Tri Gia Hoa Don ";
	int dem=0;
	PTRHoaDOn p;
	for(int i=0; i<=ls.sl; i++){	
		if(ls.dsnv[i]->DSHoaDon != NULL){
			for(p = ls.dsnv[i]->DSHoaDon; p != NULL; p = p->next){
//				cout<<strcmp(toStringDateAndTime(p->hoadon.dateAndTime).c_str(),toStringDateAndTime(ngayDau).c_str());
				if(strcmp(toStringDateAndTime(p->hoadon.dateAndTime).c_str(),toStringDateAndTime(ngayDau).c_str())>=0&& // ngay lon hon bat dau
					strcmp(toStringDateAndTime(p->hoadon.dateAndTime).c_str(),toStringDateAndTime(ngayCuoi).c_str())<=0){ // ngay be hon ket thuc
					gotoxy(3,wherey()+2);cout<<p->hoadon.SoHD; // xuat ra so hoa don
					gotoxy(35,wherey());
					cout<<p->hoadon.dateAndTime.day<<"/"<<p->hoadon.dateAndTime.month<<"/"<<p->hoadon.dateAndTime.year; // xuat ra ngay lap
					gotoxy(65,wherey()); 
					if(p->hoadon.Loai=='N') cout<<"Nhap"; // xuat ra loai hoa don;
					else cout<<"Xuat";
					gotoxy(90,wherey()); cout<<ls.dsnv[i]->HO<<" "<<ls.dsnv[i]->TEN; // xuat ra ho ten nhan vien 
					gotoxy(135,wherey()); cout<<TongTriGiaHoaDon(p->hoadon);
//					DuyetCTDH(p->hoadon);
					dem=1;
				}
				
			}
		}
	}
	return (dem==1)?true:false;
}
string toStringDateAndTime(DateAndTime dateAndTime){
	string str;
	if(dateAndTime.year<10){
		str=to_string(0);
		str+=to_string(dateAndTime.year);
	}
	else str+=to_string(dateAndTime.year);;
	if(dateAndTime.month<10){
		str+=to_string(0);
		str+=to_string(dateAndTime.month);
	}
	else str+=to_string(dateAndTime.month);
	if(dateAndTime.day<10){
		str+=to_string(0);
		str+=to_string(dateAndTime.day);
	}
	else str+=to_string(dateAndTime.day);
	return str;
}
int TongTriGiaHoaDon(HOADON hoaDon){
	int Tong=0;
	for(int i=0;i<=hoaDon.n;i++){
		Tong=Tong+hoaDon.dscthd[i].Sl*hoaDon.dscthd[i].DonGia;
	}
	return Tong;
}
void In_1_HoaDon(HOADON hoaDon, int x, int y){
		gotoxy(x,y-1);
	for(int i=0;i<=hoaDon.n;i++){
		gotoxy(x,wherey()+1);cout<<"Ma      :"<<hoaDon.dscthd[i].MAVT;
		gotoxy(x,wherey()+1);cout<<"So Luong:"<<hoaDon.dscthd[i].Sl;
		gotoxy(x,wherey()+1);cout<<"Don gia :"<<hoaDon.dscthd[i].DonGia;
		gotoxy(x,wherey()+1);cout<<"VAT     :"<<hoaDon.dscthd[i].Vat;
		gotoxy(x,wherey()+1);cout<<"------------------------";
	}
}
