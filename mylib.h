#define Enter 13
#define PASSWORD "abcdef"

using namespace std;
char * Pwd () {
     char *S= new char[40];
	 ; int i=0;
     while ((S[i]= getch()) != Enter ) 
     { printf ("%c", '*') ; i++ ; 
     }
     S[i]='\0';
     return S;
}

int CheckPwd () {
    int dem =0; 
    for ( dem =1 ; dem <=3 ; dem++)
    { printf( "Password :"); 
      if (strcmp(Pwd(),PASSWORD) ==0)   return 1;
      else printf ( "\nPassword sai. Hay nhap lai\n")  ; 
    }
    return 0;  
}

void gotoxy(short x, short y)
{
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x,y};
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}  

template <typename T>
void inxy(short x, short y, const T &t){
	gotoxy(x,y);
	cout<<t;
}

int wherex( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

int wherey( void )
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
void clreol( ) {
COORD coord;
DWORD written;
CONSOLE_SCREEN_BUFFER_INFO info;
GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
coord.X = info.dwCursorPosition.X;
coord.Y = info.dwCursorPosition.Y;
FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
  info.dwSize.X - info.dwCursorPosition.X * info.dwCursorPosition.Y, coord, &written);
gotoxy (info.dwCursorPosition.X + 1, info.dwCursorPosition.Y + 1);
}

void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void hidecursor()
{
	CONSOLE_CURSOR_INFO CursorInfo;
	CursorInfo.dwSize = 30;
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
}
void nohidecursor()
{
	CONSOLE_CURSOR_INFO CursorInfo;
	CursorInfo.dwSize = 30;
	CursorInfo.bVisible = true;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
}
void colorBasic(){
	SetColor(7);
	SetBGColor(0);
}
void HightLight(){
	SetColor(5);
	SetBGColor(2);
}
struct HCN{
	int x;
	int y;
	HCN(int X,int Y): x(X),y(Y){}
};
void VeHinhChuNhat(HCN TopLeft,HCN BotRight, int MaMau ){// neu ma mau =-1 thi khong co backgroaud
	
	if(MaMau!=-1){// to mau 
		gotoxy(0,0);
		SetBGColor(MaMau);
		for(int i=0;i<BotRight.y-TopLeft.y+10;i++){
		for(int j=0;j<BotRight.x-TopLeft.x;j++){
			cout<<" ";
		}
	}

	}
	gotoxy(TopLeft.x,TopLeft.y);
	for(int i=TopLeft.x+1;i<BotRight.x-TopLeft.x+2;i++){// ve canh tren
		cout<<char(205);
	}
	gotoxy(TopLeft.x,BotRight.y);
	for(int i=TopLeft.x+1;i<BotRight.x-TopLeft.x+2;i++){// ve canh tren
		cout<<char(205);
	}
	// ve canh trai
	for(int i=TopLeft.x;i<BotRight.y-TopLeft.y;i++){
		gotoxy(TopLeft.x,TopLeft.y+i);
		cout<<char(186);
	}
	//ve canh phai
	for(int i=TopLeft.x;i<BotRight.y-TopLeft.y;i++){
		gotoxy(BotRight.x,TopLeft.y+i);
		cout<<char(186);
	}
	// ve 4 goc
	gotoxy(TopLeft.x,TopLeft.y);
	cout<<char(201);
	gotoxy(BotRight.x,TopLeft.y);
	cout<<char(187);
	gotoxy(BotRight.x,BotRight.y);
	cout<<char(188);
	gotoxy(TopLeft.x,BotRight.y);
	cout<<char(200);	
}
void xoaMeuPhu(int x,int y){
	SetBGColor(1);
	for(int i=0;i<52;i++){
		for(int j=0;j<4;j++){
			gotoxy(x+i,y+j);cout<<" ";
		}
	}
}
void VeDuongThangNgang(int toadoX1, int todoX2, int toadoY){
	gotoxy(toadoX1,toadoY);
	for(int i=0;i<todoX2-toadoX1;i++){
		cout<<"-";
	}
};
void ColorUI(){
	SetBGColor(1);
	SetColor(7);
}
void colorDialogue(){
	SetBGColor(0);
	SetColor(7);
}
void TrangThai(int x, int y, string str){ // mac dinh -1 dua ve  bang trang thai
	// khung trang thai 3 dong...
	//
	colorDialogue();
	for(int i=0;i<3;i++){
		gotoxy(165,18+i);
		for(int j=0;j<30;j++){
			cout<<" ";
		}	
	}
	
	if(x==-1&&y==-1){
		x=170;
		y=19;
		gotoxy(x,y); cout<<str;
	}
	else{
		gotoxy(x,y); cout<<str;
	}
	ColorUI();
}
void XoaTrangThai(int x, int y){ // mac dinh -1 dua ve  bang trang thai
	// khung trang thai 3 dong...
	//
	ColorUI();
	for(int i=0;i<3;i++){
		gotoxy(165,18+i);
		for(int j=0;j<30;j++){
			cout<<" ";
		}	
	}
	ColorUI();
}
void VeDuongThangDoc(int toadoX, int toadoY1, int toadoY2)
{
	for(int i=0;i<toadoY2-toadoY1;i++){
		gotoxy(toadoX,toadoY1+i);
		cout<<char(124);
	}
};
void KhungTrangThai(HCN tren, HCN duoi,int mamau){ // tra ve khung den, chu trang
	hidecursor();
	gotoxy(tren.x, tren.y);
	SetBGColor(mamau);
	SetColor(7);
	for(int i=0;i<duoi.y-tren.y;i++){
		gotoxy(tren.x, tren.y+i);
		for(int j=0;j<duoi.x-tren.x;j++){
			cout<<" ";
		}
	}
	if(mamau==0){
		colorBasic();
	}
	else{
		SetBGColor(1);
	}
}
char *getMaVatTu(){
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

int getNumber(int n){
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
				case 13:{
					if(i>-1) 
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
			}
		}
	}while(OK!=true);
	ColorUI();
	int tong=0;
	int count=0;
	while(str[count]){
		tong=tong*10+ (int)(str[count]-'0');
		count++;
	}
	hidecursor();
	return tong;

}
char *getTenVatTu(){// cho phep nhap toi da 10 ki tu, bao gom ca khoang trang
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
				case 13:{
					if(i>-1) 
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
					if((key>64&&key<91)||(key>96&&key<123)||(key>47&&key<58)||key==32)
					if(j==-1){// nhap lieu
						if(i<=8){ // 0->8 : 9 phan tu, duoi 10 phan tu moi cho nhap;
							i++;
							str[i]=(int)key;	
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
			}
		}
	}while(OK!=true);
	ColorUI();
	hidecursor();
	return str;
}
char *getHoNhanVien(){// cho phep nhap toi da 10 ki tu, bao gom ca khoang trang
	nohidecursor();
	colorDialogue();
	char key;
	char *str= new char [31];
	int i=-1;
	int j=-1;// j la bien chay cua left va  right;
	bool OK=false;// khoi tao bien dung vong lap
	gotoxy(wherex(),wherey());
	do{
		if(kbhit()){
			key=getch();
			switch(key){
				case 13:{
					if(i>-1)
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
					if((key>64&&key<91)||(key>96&&key<123)||(key>47&&key<58)||key==32)
					if(j==-1){// nhap lieu
						if(i<=29){ // 0->29 : 30 phan tu, duoi 31 phan tu moi cho nhap;
							i++;
							str[i]=(int)key;	
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
			}
		}
	}while(OK!=true);
	ColorUI();
	hidecursor();
	return str;
}
bool getPhai(){
	nohidecursor();
	char key;
	do{
		key=getch();
		if(key=='M'||key=='m') {
			cout<<key;
			return true;
		}
		if(key=='F'||key=='f'){
			cout<<key;
			return false;
		};
	} while(true);
	hidecursor();
}
void UI(){ // ve giao dien vao
	hidecursor();// an con tro di
	VeHinhChuNhat(HCN(1,3),HCN(200,50),1);
	//UI**
	gotoxy(200-32,50-1); cout<<"Develop By Tran Van Hieu";
	VeDuongThangNgang(2,200,15);// Khong gian lam viec (Wordspace) va thanh menu
	VeDuongThangDoc(160,16,50);
	SetBGColor(5);
	gotoxy(100,4); cout<<"Quan Ly Vat Tu";
	gotoxy(175,16); cout<<"Trang Thai.";
}
bool TiepTuc(){
	gotoxy(4,49); cout<<"Nhan Enter de tiep tuc.Nhap ESC de quay tro lai!";
	char key;
	do{
		key= getch();
		if(key==13) return true;
		if(key==27) return false;
	}while(key!=13&&key!=27);
}
int ESC_ENTER_F2(){
	gotoxy(4,49); cout<<"Nhan Enter de tiep tuc.Nhap ESC de quay tro lai.Delete De Xoa Vat Tu";
	char key;
	do{
		key= getch();
		if(key==13) return 1;
		if(key==27) return 2;
		if(key==83) return 3;
	}while(true);
}
bool Thoat(){
	ColorUI();
	gotoxy(4,49); cout<<"Nhap ESC de quay tro lai!";
	char key;
	do{
		key= getch();
		if(key==27) return true;
	}while(key!=27);
}
char getLoai(char x1,char x2){
	nohidecursor();
	colorDialogue();
	char key;
	char str[2];
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
					if(i==0) 
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
					if(key==tolower(x1)){
						key= key-32;
						if(j==-1){// nhap lieu
						if(i==-1){ // 0->8 : 9 phan tu, duoi 10 phan tu moi cho nhap;
							i++;
							str[i]=	key;	
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
					if(key==tolower(x2)){
						key= key-32;
						if(j==-1){// nhap lieu
						if(i==-1){ // 0->8 : 9 phan tu, duoi 10 phan tu moi cho nhap;
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
	return str[0];
}
