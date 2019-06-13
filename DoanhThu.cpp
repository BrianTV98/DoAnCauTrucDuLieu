// dua danh thu vao danh sach lien ket don
//#include<iostream>
//#include "Cautruc.h"
//#include "NhanVien.h"
using namespace std;
void InitDSDoanhThu(PTRDOANHTHU &ptrDoanhThu){
	ptrDoanhThu=NULL;
}
PTRDOANHTHU NewnodeDoanhThu()
{   
      PTRDOANHTHU p = new NodeDanhThu;
      return p;
}
void Insert_First_DSDoanhThu(PTRDOANHTHU &First, char *ma, float x)
{
   PTRDOANHTHU p = new NodeDanhThu;
   strcpy(p->doanhThuVatTu.MaVatTu,ma);
   p->doanhThuVatTu.DanhThu=x;
   p->next = First;
   First = p;
}
bool EmptyDSDanhThu(PTRDOANHTHU First)
{
   return(First == NULL)?true:false;
}
void ClearlistDSDanhThu(PTRDOANHTHU &First)
{  
   PTRDOANHTHU p;  
  while(First != NULL)
   {
      p = First;
      First = First->next;
      delete p;
   }
}
PTRDOANHTHU Search_inforDoanhThu(PTRDOANHTHU First,char *ma){
	PTRDOANHTHU p;
	for(p=First;p!=NULL;p=p->next){
		if(strcmp(p->doanhThuVatTu.MaVatTu,ma)==0){
			return p;
		}
	}
}
bool CapNhapTongSo(PTRDOANHTHU &First, char *ma,float muctang){ // neu cap nhap dc thi tra ve true, neu ko cap nhap dc thi tra ve false
	PTRDOANHTHU p;
	for(p=First;p!=NULL;p=p->next){
		if(strcmp(p->doanhThuVatTu.MaVatTu,ma)==0){
			p->doanhThuVatTu.DanhThu+=muctang;
			return true;
		}
	}
	return false;
}
int delete_infoDoanhThu(PTRDOANHTHU &First, char *ma){
	PTRDOANHTHU p,q;
	if(EmptyDSDanhThu(First)==true) return 0;
	if(strcmp(First->doanhThuVatTu.MaVatTu,ma)==0){
		q=First;
		delete First;
		First= q->next;
	}
	else{
		for(p=First;p!=NULL;p=p->next){
		if(strcmp(p->doanhThuVatTu.MaVatTu, ma)==0){			
			q->next=p->next;
			delete p;
			return 1;
		}
		q=p;
	}
	}
	
	return 0;
} 
void DuyetDanhSachThongKeGia(PTRDOANHTHU &First, NODEVATTU vt)
{ 	
	KhungTrangThai(HCN(2,17),HCN(150,18),3); //Giao Dieb
	KhungTrangThai(HCN(2,19),HCN(150,20),3);
	PTRDOANHTHU p;
  	int i=0;
  	int max;
   PTRDOANHTHU ValueMax;
   ColorUI();
   gotoxy(3,18);cout<<"Ma Vat Tu";
   gotoxy(30,18); cout<<"Ten Vat Tu";
   gotoxy(60,18); cout<<"Tong Gia Tri Xuat";
   if(First== NULL)
      TrangThai(-1,-1,"Rong");
    else{
		while(i<10){
			max=0; //reset max
			ValueMax=NULL;
			if(First==NULL) return;
			for (p = First ; p!= NULL; p=p->next){
				if(p->doanhThuVatTu.DanhThu>max){
					max=p->doanhThuVatTu.DanhThu;
					ValueMax=p;
				}
			}
			gotoxy(3, wherey()+2);
			cout<<ValueMax->doanhThuVatTu.MaVatTu;
			gotoxy(25,wherey());cout<<search(vt,ValueMax->doanhThuVatTu.MaVatTu)->vatTu.TENVT; 
			gotoxy(65,wherey());
			cout<<ValueMax->doanhThuVatTu.DanhThu;
			delete_infoDoanhThu(First, ValueMax->doanhThuVatTu.MaVatTu);	
			i++;
		}
    	
	}
}

void ThongKeTriGiaHoaDon(LISTNHANVIEN ls,DateAndTime ngayDau,DateAndTime ngayCuoi,PTRDOANHTHU &ptrDoanhThu){
	PTRHoaDOn p;
	PTRDOANHTHU q;
	for(int i=0; i<=ls.sl; i++){	
		if(ls.dsnv[i]->DSHoaDon != NULL){
			for(p = ls.dsnv[i]->DSHoaDon; p != NULL; p = p->next){
//				cout<<strcmp(toStringDateAndTime(p->hoadon.dateAndTime).c_str(),toStringDateAndTime(ngayDau).c_str());
				if(strcmp(toStringDateAndTime(p->hoadon.dateAndTime).c_str(),toStringDateAndTime(ngayDau).c_str())>=0&& // ngay lon hon bat dau
					strcmp(toStringDateAndTime(p->hoadon.dateAndTime).c_str(),toStringDateAndTime(ngayCuoi).c_str())<=0){ // ngay be hon ket thuc
					 if(p->hoadon.Loai=='X'){
					 	for(int i=0;i<=p->hoadon.n;i++){
					 		q=Search_inforDoanhThu(ptrDoanhThu,p->hoadon.dscthd[i].MAVT); // kiem tra ma con ton tai trong danh sach chua
					 		if(q){// neu ma da ton tai trong danh sach thi cap nhap lai
					 			CapNhapTongSo(ptrDoanhThu,p->hoadon.dscthd[i].MAVT,p->hoadon.dscthd[i].Sl*p->hoadon.dscthd[i].DonGia);
							}
							else{
								Insert_First_DSDoanhThu(ptrDoanhThu,p->hoadon.dscthd[i].MAVT,p->hoadon.dscthd[i].Sl*p->hoadon.dscthd[i].DonGia);
							}
						 }
					 }
//					dem=1;
				}
				
			}
		}
	}
}

