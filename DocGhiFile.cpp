void Ghi_1_VatTu(VatTu vt){
	ofstream file;
	file.open("VatTu.txt",ios::binary|ios::app);
	//Ghi theo thu tu:
	//1. Ma Vat Tu:10 ki tu;
	//2. Ten Vat Tu: 30 ki tu:
	//3. Don Vi Tinh: 10 ki tu;
	//4. So luong Ton: kieu integer
	char buffer1[11];
	char buffer2[31];
	char buffer3[11];
	strcpy(buffer1,vt.MAVT);
	strcpy(buffer2,vt.TENVT);
	strcpy(buffer3,vt.DVT);
	file.write(buffer1,sizeof(buffer1));
	file.write(buffer2,sizeof(buffer2));
	file.write(buffer3,sizeof(buffer3));
	file.write(reinterpret_cast <char*> (&vt.SLT),sizeof(vt.SLT));
	file.close();
}
void DocfileVatTu(NODEVATTU &root){
	ifstream file;
	file.open("VatTu.txt",ios::binary);
	if(!file.is_open()){
		gotoxy(20,10); //cout<<"Khong ton tai CSDL vat tu! ";
	}
	else {
		VatTu vt;
		// doc lan luoc theo thu tu da luu:
		//1. Ma VatTu : 10 ki tu;
		//2. Ten Vat Tu: 30 ki tu;
		//3. Don Vi Tinh: 10 ki tu;
		//4. So luong: kieu int ;
		while(!file.eof()){
			char buffer1[11];// ma vat tu
			char buffer2[31];// ten vat tu
			char buffer3[11];
			buffer1[0]='\0';
			buffer2[0]='\0';
			buffer3[0]='\0';
			vt.SLT=-1;
			file.read(buffer1, sizeof(buffer1));
			file.read(buffer2, sizeof(buffer2));
			file.read(buffer3, sizeof(buffer3));
			file.read(reinterpret_cast <char*> (&vt.SLT),sizeof(vt.SLT));
			if(strlen(buffer1)>0&&buffer2>0&&buffer3>0&&vt.SLT){ // bat truong hop rong het van cho chen vao tree
				strcpy(vt.MAVT,buffer1);
				strcpy(vt.TENVT,buffer2);
				strcpy(vt.DVT,buffer3);
				Insert_nodeVatTu(root,vt);
			}
			
			
		}
	}
	file.close();
}
void CapNhapFileVatTu(NODEVATTU vt){
	int x=remove("VatTu.txt");
	if(x==0){
		GhiDanhSachVatTu(vt);
	}
}
void GhiDanhSachVatTu(NODEVATTU root){
	if(root!=NULL){
		Ghi_1_VatTu(root->vatTu);
		GhiDanhSachVatTu(root->left);
		GhiDanhSachVatTu(root->right);
	}
}
void Ghi_1_NhanVien(NhanVien nv){
	ofstream file;
	file.open("NhanVien.txt",ios::binary|ios::app);
	//Ghi theo thu tu:
	//1. Ma Vat Tu:10 ki tu;
	//2. Ho Vat Tu: 30 ki tu:
	//3. Ten Vi Tinh: 10 ki tu;
	//4. Phai luong Ton: kieu bool
	char buffer1[11];
	char buffer2[31];
	char buffer3[11];
	strcpy(buffer1,nv.MANV);
	strcpy(buffer2,nv.HO);
	strcpy(buffer3,nv.TEN);
	file.write(buffer1,sizeof(buffer1));
	file.write(buffer2,sizeof(buffer2));
	file.write(buffer3,sizeof(buffer3));
	file.write(reinterpret_cast <char*> (&nv.PHAI),sizeof(nv.PHAI));
	file.close();
}
void GhiDanhSachNhanVien(LISTNHANVIEN ls){
	for(int i=0;i<=ls.sl;i++){
		Ghi_1_NhanVien(*ls.dsnv[i]);	
	}
}
void CapNhapFileNhanVien(LISTNHANVIEN ls){
	int x=remove("NhanVien.txt");
//	if(x==0){
		GhiDanhSachNhanVien(ls);
//	}
}
void DocfileNhanVien(ListNhanVien &ls){
	ifstream file;
	file.open("NhanVien.txt",ios::binary);
	if(!file.is_open()){
		gotoxy(20,10);// cout<<"Khong ton tai CSDL Nhan Vien! ";
	}
	else {
		NhanVien nv;
		// doc lan luoc theo thu tu da luu:
		//1. Ma Nhan Vien : 10 ki tu;
		//2. Ho Nhan Vien: 30 ki tu;
		//3. Ten Nhan Vien: 10 ki tu;
		//4. Phai : kieu bool ;
		while(!file.eof()){
			char buffer1[11];// ma vat tu
			char buffer2[31];// ho nhan vien
			char buffer3[11];
			buffer1[0]='\0';
			buffer2[0]='\0';
			buffer3[0]='\0';
			nv.PHAI=true;
			nv.DSHoaDon=NULL;
			file.read(buffer1, sizeof(buffer1));
			file.read(buffer2, sizeof(buffer2));
			file.read(buffer3, sizeof(buffer3));
			file.read(reinterpret_cast <char*> (&nv.PHAI),sizeof(nv.PHAI));
			if(strlen(buffer1)>0&&buffer2>0&&buffer3>0){ // bat truong hop rong het van cho chen vao tree
				strcpy(nv.MANV,buffer1);
				strcpy(nv.HO,buffer2);
				strcpy(nv.TEN,buffer3);
//				cout<<"Ma Nhan Vien: "<<nv.MANV<<endl;
				InsertNhanVien(ls,nv);
			}		
		}
	}
	file.close();
}

///////////////////////////////////////////////////////DOC GHI HOA DON///////////////////////////////////////////////////

void GhiHoaDon(HOADON hoaDon, char *tenfile){	
	ofstream file;
	string str="data/HoaDon/"+string(tenfile)+".txt";
	file.open(str.c_str(),ios::binary|ios::app);
	//Ghi theo thu tu:
	//1. So HD:20 ki tu;
	//2. Loai: 1 ki tu:
	//3. year: int;
	//4. Month: int 
	//5. Year: int
	
	file.write(reinterpret_cast <char*> (&hoaDon),sizeof(HOADON));
	
	file.close();
}

void DocHoaDon(PTRHoaDOn &hd, char *filename){
	HOADON hoaDon;
	ifstream file;
	string str="data/HoaDon/"+string(filename)+".txt";
	file.open(str.c_str(),ios::binary);
	if(!file.is_open()){
//		gotoxy(20,10); cout<<"Ko co hoa Don ";
	}
	else {
		
		// doc lan luoc theo thu tu da luu:
		//1. Ma Nhan Vien : 10 ki tu;
		//2. Ho Nhan Vien: 30 ki tu;
		//3. Ten Nhan Vien: 10 ki tu;
		//4. Phai : kieu bool ;
		while(!file.eof()){
			file.read(reinterpret_cast <char*> (&hoaDon), sizeof(HOADON));
			Insert_First(hd, hoaDon);
			file.peek();
		}
	}
	file.close();
}

//////////////////////////////////////////////////////DOC GHI CHI TIET HOA DON///////////////////////////////////////////////

void GhiCTHD(CT_HOADON cthd, char *tenfile){
	ofstream file;
	string str="data/CTHD/"+string(tenfile)+".txt";
	file.open(str.c_str(),ios::binary|ios::app);
	//Ghi theo thu tu:
	//1. Ma VATu:10 ki tu;
	//2. Soluong: int:
	//3. Don Gia: int;
	//4. vat: int 
//	char buffer1[11];
//	strcpy(buffer1,cthd.MAVT);
//	file.write(buffer1,sizeof(buffer1));
//	file.write(reinterpret_cast <char*> (&cthd.Sl),sizeof(cthd.Sl));
//	file.write(reinterpret_cast <char*> (&cthd.DonGia),sizeof(cthd.DonGia));
//	file.write(reinterpret_cast <char*> (&cthd.Vat),sizeof(cthd.Vat));
	file.write(reinterpret_cast <char*> (&cthd), sizeof(CT_HOADON));
	file.close();
}

void DocDSCTHD(HOADON &hd,char *filename){
	ifstream file;
	CT_HOADON cthd;
	string str="data/CTHD/"+string(filename)+".txt";
	file.open(str.c_str(),ios::binary);

	if(!file.is_open()){
		gotoxy(20,10); cout<<"Ko co hoa Don ";
	}
	else {
		do{
//			char buffer1[11];
//			file.read(buffer1,sizeof(buffer1));
//			file.read(reinterpret_cast <char*> (&cthd.Sl),sizeof(cthd.Sl));
//			file.read(reinterpret_cast <char*> (&cthd.DonGia),sizeof(cthd.DonGia));
//			file.read(reinterpret_cast <char*> (&cthd.Vat),sizeof(cthd.Vat));
//			strcpy(cthd.MAVT,buffer1);
			file.read(reinterpret_cast <char*> (&cthd), sizeof(CT_HOADON));
			Insert_CTHoaDon(hd,cthd);
		
			file.peek();
		}while(!file.eof());
	}
	
	file.close();
}
