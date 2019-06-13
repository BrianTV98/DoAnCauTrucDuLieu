//#include "Cautruc.cpp">
//#include "mylib.h"
NODEVATTU rp;
void InitVatTu(NODEVATTU &root){
	root=NULL;
}
NODEVATTU New_NodeVatTu(){
	NODEVATTU p;
	p= new nodeVatTu;
	return p;
}
int Insert_nodeVatTu(NODEVATTU &p,VatTu vt ){
	if(p==NULL){ // khoi tao cay neu cay chua co
		p=new nodeVatTu;
		p->vatTu=vt;
		p->left=NULL;
		p->right=NULL;
		return 1;
	}
	else {
		int x= strcmp(p->vatTu.MAVT, vt.MAVT);
		if(x>0){
			int a=Insert_nodeVatTu(p->left,vt);
			if(a==1) return 1 ; // neu chen dc( ma ko trung) tra ve 1
			else return 0;
		}
		else if(x<0){
			int a=Insert_nodeVatTu(p->right,vt);
			if(a==1) return 1;
			else return 0;
		}
	}
	return 0;
}

void Create_nodeVatTu(NODEVATTU &root){
	nohidecursor();
	VatTu vt;
	//show khung chuong trinh
	KhungTrangThai(HCN(3,16),HCN(40,20),0);
	colorDialogue();
	gotoxy(3,16);
	cout<<"Nhap ma vat tu   : ";
	gotoxy(3,wherey()+1);
	cout<<"Nhap ten vat tu  : ";
	gotoxy(3,wherey()+1);
	cout<<"Nhap don vi tinh : ";
	gotoxy(3,wherey()+1);
	cout<<"Nhap so luong ton: ";	
	do{
		KhungTrangThai(HCN(23,16),HCN(40,20),0); // xoa nhung gi vua nhap truoc do neu co:
		gotoxy(23,wherey()+1);
		gotoxy(23,16);	
		strcpy(vt.MAVT,getMaVatTu());
		if(strcmp(vt.MAVT,"0")!=0){
			gotoxy(23,wherey()+1);
			strcpy(vt.TENVT,getTenVatTu());
			gotoxy(23,wherey()+1);
			strcpy(vt.DVT,getTenVatTu());
			gotoxy(23,wherey()+1);
			vt.SLT=getNumber(5);// nhap toi da dc 5 so
			int key=Insert_nodeVatTu(root, vt);
			if(key==1 ) {
				TrangThai(-1,-1,"Chen Vat Tu Thanh Cong! ");
				Ghi_1_VatTu(vt);
				if(TiepTuc()==false) break;
			}
			else TrangThai(-1,-1,"Ma Trung!Nhap lai! ");
//			Insert_nodeVatTu(root,vt);
		}		
	}while(strcmp(vt.MAVT,"0")!=0);
	//xoa khung nhap
	KhungTrangThai(HCN(3,16),HCN(40,20),1);
	TrangThai(-1,-1,"Thoat Nhap Thanh Cong! ");
	xoaMeuPhu(70,6);
	hidecursor();
}
void showVatTu(VatTu vt){
	gotoxy(wherex(),wherey()+1);
	gotoxy(15,wherey()); cout<<vt.MAVT;
	gotoxy(57,wherey());cout<<vt.TENVT;
	gotoxy(99,wherey());cout<<vt.DVT;
	gotoxy(140,wherey());cout<<vt.SLT;
	
}
void HienThiDanhSachVatTu(NODEVATTU root){// duyet NLR 
	// da bat truong hop rong
	
	if(root!=NULL){
//		gotoxy(4,wherey()+1);	
		HienThiDanhSachVatTu(root->left);
		showVatTu(root->vatTu);
		HienThiDanhSachVatTu(root->right);
	}	
}
bool HieuChinhSoLuongTon(NODEVATTU root,char *ma,int n){
	NODEVATTU p;
	p=root;
	while(p!=NULL&&strcmp(p->vatTu.MAVT,ma)!=0){
		if(strcmp(p->vatTu.MAVT,ma)>0){
			p=p->left;
		}
		else
			p=p->right;
		
	}
	if((p->vatTu.SLT+n)>=0){
		p->vatTu.SLT=p->vatTu.SLT+n;
		return true;
	}
	return false;
}
NODEVATTU search(NODEVATTU root,char *ma){
	NODEVATTU p;
	p=root;
	while(p!=NULL&&strcmp(p->vatTu.MAVT,ma)!=0){
		if(strcmp(p->vatTu.MAVT,ma)>0){
			p=p->left;
		}
		else
			p=p->right;
		
	}
//	cout<<"pass!";
	return p;
}
///----ngay 20/5----
bool is_Emty(NODEVATTU r){
	if (r==NULL) return true;
	return false;
}
void  remove_case_3 (NODEVATTU &r )
{

  if (r->left != NULL)
     remove_case_3(r->left);
   //den day r la nut cuc trai cua cay con ben phai co nut goc la rp}
    else 
	{
		rp->vatTu= r->vatTu;//chep noi dung cua vat tu
		rp=r;           	
   		r=rp->right;
	}
  } 
void  remove(NODEVATTU &p, char *x )
{
	if (p == NULL)  TrangThai(-1,-1,"Khong tim thay vat Tu!");
		else
	  	if (strcmp(p->vatTu.MAVT,x)>0)   remove ( p->left,x);
	  	else if (strcmp(p->vatTu.MAVT,x)<0)
		 	remove ( p->right,x);
	       	else{
		 		rp = p;
              	if (rp->right == NULL)  p = rp->left;   
	// p là nút lá hoac la nut chi co cay con ben trai
			 	else 	if(rp->left == NULL)
			   	p=rp->right;  // p là nut co cay con ben phai
			else remove_case_3 (rp->right);
		 delete rp;
	    }
}
void XoaVatTu(NODEVATTU &root){
	//if tree rong thi thong bao cay rong;
	// if cay ko rong thi kiem tra xem ma can xoa co ton tai hay ko,
	// truong hop ma can xoa khong ton tai thi thong bao loi
	// truong hop ma ton tai thi hien thi thong tin can xoa, truoc khi xoa,
	//---giao dien---
A:	KhungTrangThai(HCN(3,16),HCN(40,17),0);
	//------------Back end-----
	if(is_Emty(root)) TrangThai(-1,-1,"D/s Vat Tu Rong!");
	else {
		NODEVATTU rp,p;
		char *buffer= new char[11];
		colorDialogue();
		nohidecursor();
		gotoxy(4,16);cout<<"Ma Vat Tu Can Xoa: ";
		strcpy(buffer, getMaVatTu());
		p=search(root,buffer);
		if(p){
			showVatTuDon(p->vatTu);
			gotoxy(4, wherey()+2);
			cout<<"Ban Co muon xoa Vat Tu Khong. Thao Tac Xoa se ko the hoan tac!(y/n):";
			char key=getch();
			cout<<key;
			if(key=='y'||key=='Y'){
					remove(root,buffer);
					TrangThai(-1,-1,"Ban Da Xoa Thanh Cong!");
					CapNhapFileVatTu(root);
					if(TiepTuc()==true){
						KhungTrangThai(HCN(2,16),HCN(160,50),1);
						goto A;
					}
					else KhungTrangThai(HCN(2,16),HCN(160,50),1);
				}
				else TrangThai(-1,-1,"Ban Da Xoa That Bai!");
		}
		else{
			TrangThai(-1,-1,"Vat Tu Khong Ton Tai!");
		}	
	}	
}
void showVatTuDon(VatTu vt){
	KhungTrangThai(HCN(50,16),HCN(90,21),0);
	colorBasic();
	gotoxy(51,16); cout<<"Thong Tin Vat Tu: ";
	gotoxy(51,wherey()+1); cout<<"Ma Vat Tu   :"<<vt.MAVT;
	gotoxy(51,wherey()+1); cout<<"Ten Vat Tu  :"<<vt.TENVT;
	gotoxy(51,wherey()+1); cout<<"Don Vi Tinh :"<<vt.DVT;
	gotoxy(51,wherey()+1); cout<<"So luong ton:"<<vt.SLT;
}
void ChinhSuaVatTu(NODEVATTU root,VatTu &vt){
	nohidecursor();
	//show khung chuong trinh
	KhungTrangThai(HCN(3,16),HCN(40,20),0);
	colorDialogue();
	gotoxy(3,16);
	cout<<"Nhap ma moi      : ";
	gotoxy(3,wherey()+1);
	cout<<"Nhap ten moi     : ";
	gotoxy(3,wherey()+1);
	cout<<"Don vi tinh      : ";
	gotoxy(3,wherey()+1);
	int key;	
	do{
		KhungTrangThai(HCN(23,16),HCN(40,20),0); // xoa nhung gi vua nhap truoc do neu co:
		gotoxy(23,wherey()+1);
		gotoxy(23,16);	
		strcpy(vt.MAVT,getMaVatTu());
		if(strcmp(vt.MAVT,"0")!=0){
			gotoxy(23,wherey()+1);
			strcpy(vt.TENVT,getTenVatTu());
			gotoxy(23,wherey()+1);
			strcpy(vt.DVT,getTenVatTu());
			gotoxy(23,wherey()+1);// nhap toi da dc 5 so
			key=Insert_nodeVatTu(root, vt);
			if(key==1 ) {
				TrangThai(-1,-1,"Chinh Sua Vat Tu Thanh Cong! ");
			}
			else TrangThai(-1,-1,"Ma Trung!Nhap lai! ");
		}		
	}while(key!=1);
}
void HieuChinhVatTu( NODEVATTU &root){
// --------------------------
// | Nhap ma vat tu:                 
// | Thong tin vat tu:
// | Ma Vat Tu:                 -> cho phep thay doi
//	 Ten Vat Tu:                -> Ten Vat Tu Moi:
//   Don Vi Tinh:               -> Don Vi Tinh   :
	//B1: Tim kiem nut va in ra mang hinh
	//B2: Chinh Sua nut
	KhungTrangThai(HCN(3,16),HCN(40,17),0);
	//------------Back end-----
	if(is_Emty(root)) TrangThai(-1,-1,"D/s Vat Tu Rong!");
	else {
		NODEVATTU rp,p;
		char *buffer= new char[11];
		colorDialogue();
		nohidecursor();
		gotoxy(4,16);cout<<"Ma Vat Tu Chinh Sua: ";
		strcpy(buffer, getMaVatTu());
		p=search(root,buffer);
		if(p){
			showVatTuDon(p->vatTu);
			VatTu vt;
			vt.SLT=p->vatTu.SLT;
			remove(root,buffer);
			ChinhSuaVatTu(root,vt);
			CapNhapFileVatTu(root);
		}	
	}	
} 
int  DemSoNutCayNhiPhan(NODEVATTU roor){
	if(roor==NULL){
		return 0;
	}
	else {
		return 1 + DemSoNutCayNhiPhan(roor->left)+DemSoNutCayNhiPhan(roor->right);
	}
}

