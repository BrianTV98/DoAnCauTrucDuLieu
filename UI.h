int InitMenu(string *Menu){
	int i=0;
	Menu[i++]="1.Cap Nhap Vat Tu.                                 ";
	Menu[i++]="2.IN danh Sach Vat Tu Ton Kho.                     ";
	Menu[i++]="3.Cap Nhap Nhan Vien.                              ";
	Menu[i++]="4.In danh sach nhan vien theo thu tu tang dan      ";
	Menu[i++]="5.Lap Hoa Don                                      ";
	Menu[i++]="6.In hoa Don                                       ";
	Menu[i++]="7.Thong ke hoa don.                                ";	
	Menu[i++]="8.10 Vat Tu co danh thu cao nhat                   ";
	Menu[i++]="9.Thoat phan mem                                   ";
	return i;
}	
int IntMenu1(string *Menu){
	int i=0;
	Menu[i++]="1.Them                                              ";
	Menu[i++]="2.Sua                                               ";
	Menu[i++]="3.Xoa                                               ";
	Menu[i++]="4.Quay lai.                                         ";
	return i;	
}
int MenuDynamic(int x,int y,string *Menu, int n){ // x, y la  toa do goc tren, n la so luong Menu
//	int n=8;
	colorBasic();
	for(int i=0;i<n;i++){
		gotoxy(x,y+i);cout<<Menu[i]<<endl;
	}
	HightLight();
	gotoxy(x,y); cout<<Menu[0];// khoi tao gia tri dau tien cua menu cho no dynamic
	int count=0;
	char key;
	do{
		key=getch();
		switch(key){
			case 80: colorBasic(); //xuong
				gotoxy(x,y+count); cout<<Menu[count];
				if(count==n-1) count=0;
				else count++;
				HightLight();
				gotoxy(x,y+count); cout<<Menu[count];
				colorBasic();
				break;
			case 72: colorBasic();// len
				gotoxy(x,y+count); cout<<Menu[count];
				if(count==0) count=n-1;
				else count--;
				HightLight();
				gotoxy(x,y+count); cout<<Menu[count];
				colorBasic();
				break;
			case 13: colorBasic();
			return count;	
		}
		
	}while(1);
	gotoxy(1,20);// dua con tro ve cuoi trang
}
int ShowMenuPhu(int i, int x, int y){ // i la so hieu menu phu, x, y la toa do goc tren cua Menu Phu
	int key=-1;
	switch(i){
		case 0:{
			string *Menu= new string[4];
			int n=IntMenu1(Menu);
			key=MenuDynamic(x,y,Menu,n);
			if(key==3) xoaMeuPhu(x,y);
			break;
		}
		case 1:{
//			gotoxy(4,20); cout<<"day la chuc nang sua! ";
			break;
		}
		case 2:{
//			showMenu3();
			break;
		}
		case 3:{
//			showMenu4();
			break;
		}
		case 4:{
//			showMenu5();
			break;
		}
		case 5:{
//			showMenu6();
			break;
		}
		case 6:{
//			showMenu7();
			break;
		}
		case 7:{
			
			break;
		}
	}
	return key;
}
int MenuTONG(int x,int y,string *Menu, int n){ // x, y la  toa do goc tren, n la so luong Menu
//	int n=8;
	colorBasic();
	gotoxy(3,5); 
	cout<<"                   MENU                            "<<"\n";
	for(int i=0;i<n;i++){
		gotoxy(3,5+i+1);cout<<Menu[i]<<endl;
	}
	HightLight();
	gotoxy(3,6); cout<<Menu[0];// khoi tao gia tri dau tien cua menu cho no dynamic
//	ShowMenuPhu(0, 70, 6);
	int count=0;
	char key;
	do{
		key=getch();
		switch(key){
			case 80: colorBasic(); //xuong
				gotoxy(3,6+count); cout<<Menu[count];
				if(count==n-1) count=0;
				else count++;
				HightLight();
				gotoxy(3,6+count); cout<<Menu[count];
//				ShowMenuPhu(count, 70, 6+count);
				colorBasic();
				break;
			case 72: colorBasic();// len
				gotoxy(3,6+count); cout<<Menu[count];
				if(count==0) count=n-1;
				else count--;
				HightLight();
				gotoxy(3,6+count); cout<<Menu[count];
//				ShowMenuPhu(count, 70, 6+count);
				colorBasic();
				break;
			case 77:{
				ShowMenuPhu(count,70, 6+count);
				break;
			}
			case 13: colorBasic();
			return count;	
		}
		
	}while(1);
	gotoxy(1,20);// dua con tro ve cuoi trang
}

