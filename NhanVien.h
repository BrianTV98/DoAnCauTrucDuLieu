void InitNhanVien(LISTNHANVIEN &ls)
{
	ls.sl=-1;
}
bool is_EmptyNhanVien(LISTNHANVIEN ls){
	if(ls.sl==-1){
		return true;
	}
	else return  false;
}
bool FullNhanVien(LISTNHANVIEN ls){
	if(ls.sl==MaxListNhaVien){
		return true;
	}
	return  false;
}
void InsertNhanVien(LISTNHANVIEN &ls,NhanVien nv){
	string tenHo= string(nv.TEN)+string(nv.HO);
	for(int i=0;i<42-tenHo.length();i++){
		tenHo+="0";
	}
	if(ls.sl==-1){
		ls.sl++;
		ls.dsnv[ls.sl]= new NhanVien;
		strcpy(ls.dsnv[ls.sl]->MANV,nv.MANV);
		strcpy(ls.dsnv[ls.sl]->HO,nv.HO);
		strcpy(ls.dsnv[ls.sl]->TEN,nv.TEN);
		ls.dsnv[ls.sl]->PHAI=nv.PHAI;
	}
	else{
		if(searchNhanVienBinary(ls,nv.MANV,0,ls.sl)) return; // fix bug ... ma trung van load tu file len
//		int a= searchIndexInsert(ls,nv.MANV,0,ls.sl);
		
		int a= searchIndexInsertfollowName(ls,tenHo,0,ls.sl);
		ls.sl++;
		ls.dsnv[ls.sl]= new NhanVien;
		for(int i=ls.sl;i>a;i--){
			strcpy(ls.dsnv[i]->MANV,ls.dsnv[i-1]->MANV);
			strcpy(ls.dsnv[i]->HO,ls.dsnv[i-1]->HO);
			strcpy(ls.dsnv[i]->TEN,ls.dsnv[i-1]->TEN);
			ls.dsnv[i]->PHAI=ls.dsnv[i-1]->PHAI;
		}
			strcpy(ls.dsnv[a]->MANV,nv.MANV);
			strcpy(ls.dsnv[a]->HO,nv.HO);
			strcpy(ls.dsnv[a]->TEN,nv.TEN);
			ls.dsnv[a]->PHAI=nv.PHAI;
	}
	
}
NhanVien NhapNhanVien(){
	NhanVien nv;
	bool phai;
	gotoxy(1,1);
	cout<<"Nhap MaNV:";
	strcpy(nv.MANV,getMaVatTu());//su dung chung ham
	cout<<"\nTen NV   :";
	strcpy(nv.TEN,getTenVatTu());//su dung chung ham 
	cout<<"\nHo NV    :";
	strcpy(nv.HO,getHoNhanVien());
	cout<<"\nPhai(m/f):";
	phai=getPhai();
	return nv;
}
void NhapDanhSachNhanVien(LISTNHANVIEN &ls){
	nohidecursor();
	NhanVien nv;
	gotoxy(3,16);
B:	if(FullNhanVien(ls)==true){
		cout<<"Danh Sach Day! ";
		TrangThai(-1,-1,"Nhap That Bai!");
		return;
	}
	else{
		KhungTrangThai(HCN(3,16),HCN(40,20),0);
		colorDialogue();
		gotoxy(3,16);
		cout<<"Nhap ma NV       : ";
		gotoxy(3,wherey()+1);
		cout<<"Nhap ten NV      : ";
		gotoxy(3,wherey()+1);
		cout<<"Nhap ho NV       : ";
		gotoxy(3,wherey()+1);
		cout<<"Nhap Phai (m/f)  : ";
		do{
			KhungTrangThai(HCN(23,16),HCN(40,20),0);// xoa nhung gi vua nhap truoc do
			gotoxy(23,16);	
			strcpy(nv.MANV,getMaVatTu());
			if(strcmp(nv.MANV,"0")!=0){	
				if(searchNhanVienBinary(ls,nv.MANV,0,ls.sl)){
				TrangThai(-1,-1,"Ma Trung! Nhap Lai!");
				goto B;
				}
				else{
					
					XoaTrangThai(-1,-1);
					gotoxy(23,17);
					strcpy(nv.TEN,getTenVatTu());
					gotoxy(23,wherey()+1);
					strcpy(nv.HO,getHoNhanVien());
					gotoxy(23,wherey()+1);
					nv.PHAI= getLoai('m','f');//getPhai();
					nv.DSHoaDon=NULL;
					InsertNhanVien(ls,nv);
					TrangThai(-1,-1,"Nhap Thanh Cong!");
					if(TiepTuc()==true){
						goto B;
					}
					else{
						break;
					}
					
				}
			}
			
		}while(strcmp(nv.MANV,"0")!=0);
		
		CapNhapFileNhanVien(ls);
	}
	KhungTrangThai(HCN(3,16),HCN(40,20),1);
	TrangThai(-1,-1,"Thoat Nhap Thanh Cong! ");	 
}
//NhanVien *searchNhanVien(LISTNHANVIEN ls,char *Ma){
//	NhanVien *p=NULL; 
//	for(int i=0;i<=ls.sl;i++){
//		if(strcmp(ls.dsnv[i]->MANV,Ma)==0){
//			p=ls.dsnv[i];
//		}
//	}
//	return p;
//}
void HienThiDanhSachNhaVien(LISTNHANVIEN ls){
	KhungTrangThai(HCN(2,16),HCN(160,50),1);
	XoaTrangThai(-1,-1);
	if(ls.sl==-1){
		gotoxy(4,17);
		cout<<"Danh sach vat tu rong! ";
		if(Thoat()==true) KhungTrangThai(HCN(2,16),HCN(160,50),1);
	}
	else{
		ColorUI();
		gotoxy(20,16);cout<<"MA ";
		gotoxy(60,16);cout<<"TEN";
		gotoxy(100,16);cout<<"Ho";
		gotoxy(140,16);cout<<"Phai";
		gotoxy(1,17);
		VeDuongThangNgang(2,160,17);
		showDanhSachNhanVien(ls);
		if(Thoat()==true) KhungTrangThai(HCN(2,16),HCN(160,50),1);
	}	
}
void showDanhSachNhanVien(LISTNHANVIEN ls){
	for(int i=0;i<=ls.sl;i++){
		gotoxy(wherex(),wherey()+1);
		gotoxy(15,wherey());cout<<ls.dsnv[i]->MANV;
		gotoxy(57,wherey());cout<<ls.dsnv[i]->TEN;
		gotoxy(99,wherey());cout<<ls.dsnv[i]->HO;
		gotoxy(140,wherey());
		if(ls.dsnv[i]->PHAI==true)
		{
			cout<<"Nam";
		}
		else {
			cout<<"Nu";
		}
	}
}
NhanVien *searchNhanVienBinary(ListNhanVien ls, char *Ma, int low, int high) { 	// tra ve nhan vien neu tim thay
	if(ls.sl==-1) return NULL;
    if (high < low) 
    	return NULL; 
    int mid = (low + high)/2; 
  
	if(strcmp(Ma,ls.dsnv[mid]->MANV)==0){
		return ls.dsnv[mid];
	}   
	
  	if(strcmp(Ma,ls.dsnv[mid]->MANV)>0){
  		return searchNhanVienBinary(ls, Ma, mid+1, high); 
	  }
	else  
	return searchNhanVienBinary(ls, Ma, low, mid-1);
} 
int searchIndexInsert(ListNhanVien ls, char *Ma, int low, int high) { 	
	//tra ve vi tri neu tim thay nhan vien, 
	// tra ve vi tri hop ly co the chen neu  ko tim thay nhan vien
	
	if(ls.sl==-1) return -1;
	
    if (high <= low)  {
    	return (strcmp(Ma,ls.dsnv[low]->MANV)>0)?(low+1):low; 
	}
    
    int mid = (low + high)/2; 
    if(strcmp(Ma,ls.dsnv[mid]->MANV)==0){
		return mid ;
		gotoxy(0,1); cout<<"bat 2";
	}   
  	if(strcmp(Ma,ls.dsnv[mid]->MANV)>0){
  		return searchIndexInsert(ls, Ma, mid+1, high); 
	  }
	  
	return searchIndexInsert(ls, Ma, low, mid-1); 
} 
int searchIndexInsertfollowName(ListNhanVien ls, string tenHo, int low, int high) { 	
	//tra ve vi tri neu tim thay nhan vien, 
	// tra ve vi tri hop ly co the chen neu  ko tim thay nhan vien
	int mid = (low + high)/2; 
	//==================GOP TEN VA HO lai vs nhau==============
	string tenHoLow,tenHoHigh,tenHoMid;
	tenHoLow=string(ls.dsnv[low]->TEN)+string(ls.dsnv[low]->HO);
	tenHoMid=string(ls.dsnv[mid]->TEN)+string(ls.dsnv[mid]->HO);
	tenHoHigh=string(ls.dsnv[high]->TEN)+string(ls.dsnv[high]->HO);
	//==================Quy  chuoi ve cung chieu dai===========
	for(int i=0;i<42-tenHoLow.length();i++){
		tenHoLow+="0";
	}
	for(int i=0;i<42-tenHoMid.length();i++){
		tenHoMid+="0";
	}
	//chuyen ve cung kieu thuong;
	transform(tenHo.begin(),tenHo.end(),tenHo.begin(),::tolower);
	transform(tenHoLow.begin(),tenHoLow.end(),tenHoLow.begin(),::tolower);
	transform(tenHoMid.begin(),tenHoMid.end(),tenHoMid.begin(),::tolower);
	if(ls.sl==-1) return -1;
	
    if (high <= low)  {
    	
    	return (strcmp(tenHo.c_str(),tenHoLow.c_str())>0)?(low+1):low; 
	}
    
    
    
    
    if(strcmp(tenHo.c_str(),tenHoMid.c_str())==0){
		return mid ;
//		gotoxy(0,1); cout<<"bat 2";
	}   
  	if(strcmp(tenHo.c_str(),tenHoMid.c_str())>0){
  		return searchIndexInsertfollowName(ls, tenHo, mid+1, high); 
	  }
	  
	return searchIndexInsertfollowName(ls, tenHo, low, mid-1); 
} 
void HieuChinhNhanVien(LISTNHANVIEN &ls){
editNhanVien:	KhungTrangThai(HCN(3,16),HCN(40,17),0);
	//------------Back end-----
	if(is_EmptyNhanVien(ls)) TrangThai(-1,-1,"D/s Vat Tu Rong!");
	else {
		NhanVien *p= new NhanVien;
		int vitri;
		char *buffer= new char[11];
		colorDialogue();
		nohidecursor();
		gotoxy(4,16);cout<<"Ma Vat Tu Chinh Sua: ";
		strcpy(buffer, getMaVatTu());
		p=searchNhanVienBinary(ls, buffer,0,ls.sl);
		if(p){
			showNhanVienDon(*p);
			vitri= searchIndexInsert(ls,buffer,0,ls.sl);
			PTRHoaDOn hoadon= ls.dsnv[vitri]->DSHoaDon;
			delete_NhanVien(ls,vitri);
			//--------
			KhungTrangThai(HCN(3,16),HCN(40,20),0);
			colorDialogue();
			gotoxy(3,16);
			cout<<"Nhap ma NV       : ";
			gotoxy(3,wherey()+1);
			cout<<"Nhap ten NV      : ";
			gotoxy(3,wherey()+1);
			cout<<"Nhap ho NV       : ";
			gotoxy(3,wherey()+1);
			cout<<"Nhap Phai (m/f)  : ";
			KhungTrangThai(HCN(23,16),HCN(40,20),0);// xoa nhung gi vua nhap truoc do
			NhanVien nv;
			gotoxy(23,16);	
NhapLaiMa:	strcpy(nv.MANV,getMaVatTu()); // nhap vao ma nhan vien moi
			if(strcmp(nv.MANV,"0")!=0){	
				if(searchNhanVienBinary(ls,nv.MANV,0,ls.sl)){ //
					TrangThai(-1,-1,"Ma Trung! Nhap Lai!");
					goto NhapLaiMa;
				}
				else{		
					XoaTrangThai(-1,-1);
					gotoxy(23,17);
					strcpy(nv.TEN,getTenVatTu());
					gotoxy(23,wherey()+1);
					strcpy(nv.HO,getHoNhanVien());
					gotoxy(23,wherey()+1);
					nv.PHAI=getPhai();
					InsertNhanVien(ls,nv);
					TrangThai(-1,-1,"Chinh Sua Thanh Cong!");
					int a=TiepTuc();
					if(a==true){
						KhungTrangThai(HCN(2,16),HCN(160,50),1);
						goto editNhanVien;	
					}
					else KhungTrangThai(HCN(2,16),HCN(160,50),1);				
				}
			}
				
		}
		else {
			if(strcmp(buffer,"0")==0){
				return;
			}
			TrangThai(-1,-1,"Khong tim thay Nhan Vien");
			goto editNhanVien;
		}
	}
}
void showNhanVienDon(NhanVien nv){
	KhungTrangThai(HCN(50,16),HCN(90,21),0);
	colorBasic();
	gotoxy(51,16); cout<<"Thong Tin Nhan Vien: ";
	gotoxy(51,wherey()+1); cout<<"Ma Nhan Vien   :"<<nv.MANV;
	gotoxy(51,wherey()+1); cout<<"Ten Nhan Vien  :"<<nv.TEN;
	gotoxy(51,wherey()+1); cout<<"Ho Nhan Vien   :"<<nv.HO;
	gotoxy(51,wherey()+1); cout<<"Gioi Tinh      :";
	if(nv.PHAI==true) cout<<"Nam";
	else cout<<"Nu";
}
void delete_NhanVien(LISTNHANVIEN &ls,int vitri){
	if(vitri<0||vitri>ls.sl){
		TrangThai(-1,-1,"Xoa That Bai! ");
	}
	else{
		for(int i=vitri;i<ls.sl;i++){
			strcpy(ls.dsnv[i]->MANV,ls.dsnv[i+1]->MANV);
			strcpy(ls.dsnv[i]->HO,ls.dsnv[i+1]->HO);
			strcpy(ls.dsnv[i]->TEN,ls.dsnv[i+1]->TEN);
			ls.dsnv[i]->PHAI=ls.dsnv[i+1]->PHAI;
			ls.dsnv[i]->DSHoaDon=ls.dsnv[i+1]->DSHoaDon;
		}
		delete ls.dsnv[ls.sl];
		ls.sl--; 
	}
	
}
void Nhap_1_NhanVien(LISTNHANVIEN ls){
	KhungTrangThai(HCN(3,16),HCN(40,20),0);
	colorDialogue();
	gotoxy(3,16);
	cout<<"Nhap ma NV       : ";
	gotoxy(3,wherey()+1);
	cout<<"Nhap ten NV      : ";
	gotoxy(3,wherey()+1);
	cout<<"Nhap ho NV       : ";
	gotoxy(3,wherey()+1);
	cout<<"Nhap Phai (m/f)  : ";
	KhungTrangThai(HCN(23,16),HCN(40,20),0);// xoa nhung gi vua nhap truoc do
	NhanVien nv;
	gotoxy(23,16);	
C:	strcpy(nv.MANV,getMaVatTu());
	if(strcmp(nv.MANV,"0")!=0){	
		if(searchNhanVienBinary(ls,nv.MANV,0,ls.sl)){
			TrangThai(-1,-1,"Ma Trung! Nhap Lai!");
			goto C;
		}
		else{		
			XoaTrangThai(-1,-1);
			gotoxy(23,17);
			strcpy(nv.TEN,getTenVatTu());
			gotoxy(23,wherey()+1);
			strcpy(nv.HO,getHoNhanVien());
			gotoxy(23,wherey()+1);
			nv.PHAI=getPhai();
			InsertNhanVien(ls,nv);
			TrangThai(-1,-1,"Chinh Sua Thanh Cong!");
		}
	
	}
}
void XoaNhanVien(LISTNHANVIEN &ls){
	//if tree rong thi thong bao cay rong;
	// if cay ko rong thi kiem tra xem ma can xoa co ton tai hay ko,
	// truong hop ma can xoa khong ton tai thi thong bao loi
	// truong hop ma ton tai thi hien thi thong tin can xoa, truoc khi xoa,
	//---giao dien---
begin:	KhungTrangThai(HCN(3,16),HCN(40,17),0);
	//------------Back end-----
	if(is_EmptyNhanVien(ls)==true) TrangThai(-1,-1,"D/s Vat Tu Rong!");
	else {
//		NODEVATTU rp,p;
		NhanVien *p= new NhanVien;
		char *buffer= new char[11];
		colorDialogue();
		nohidecursor();
		gotoxy(4,16);cout<<"Ma Vat Tu Can Xoa: ";
		strcpy(buffer, getMaVatTu());
		p=searchNhanVienBinary(ls,buffer,0,ls.sl);
		if(p){
			showNhanVienDon(*p);
			gotoxy(4, wherey()+2);
			int vitri=searchIndexInsert(ls,buffer,0,ls.sl);
			cout<<"Ban Co muon xoa Vat Tu Khong. Thao Tac Xoa se ko the hoan tac!(y/n)";
			char key=getLoai('Y','N');
			
			if(key=='y'||key=='Y'){
					delete_NhanVien(ls,vitri);
					TrangThai(-1,-1,"Ban Da Xoa Thanh Cong!");
					CapNhapFileNhanVien(ls);
					if(TiepTuc()==true) {
						KhungTrangThai(HCN(2,16),HCN(160,50),1);
						goto begin;
					}
					
				}
				else {
					TrangThai(-1,-1,"Ban Da Xoa That Bai!");
					
					if(TiepTuc()==true) {
						KhungTrangThai(HCN(2,16),HCN(160,50),1);
						goto begin;
					}
				}
		}
		else{
			TrangThai(-1,-1,"Ma khong ton tai!");
			if(TiepTuc()==true) goto begin;
		}	
	}
	KhungTrangThai(HCN(2,16),HCN(160,50),1);
}
	
