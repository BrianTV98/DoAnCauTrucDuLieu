#include<string.h>
#define MaxListNhaVien 500
void DocfileVatTu(NODEVATTU &root);
void Ghi_1_VatTu(VatTu vt);
void CapNhapFileVatTu(NODEVATTU vt);
void GhiDanhSachVatTu(NODEVATTU root);
void Ghi_1_NhanVien(NhanVien nv);
void GhiDanhSachNhanVien(LISTNHANVIEN ls);
void CapNhapFileNhanVien(LISTNHANVIEN ls);
void DocfileNhanVien(ListNhanVien &ls);
void GhiHoaDon(HOADON hoaDon, char *tenfile);
void GhiCTHD(CT_HOADON cthd, char *tenfile);
void DocHoaDon(PTRHoaDOn &hd, char *filename);
void DocDSCTHD(HOADON &hd,char *filename);
//--file vat tu;
int Insert_nodeVatTu(NODEVATTU &p,VatTu vt );
void InitVatTu(NODEVATTU &root);
NODEVATTU New_NodeVatTu();
int Insert_nodeVatTu(NODEVATTU &p,VatTu vt );
void Create_nodeVatTu(NODEVATTU &root);
void showVatTu(VatTu vt);
void HienThiDanhSachVatTu(NODEVATTU root);
NODEVATTU search(NODEVATTU root,char *ma);
bool is_Emty(NODEVATTU r); //20.5
void XoaVatTu(NODEVATTU &root);//20.5
void showVatTuDon(VatTu vt);
void ChinhSuaVatTu(NODEVATTU root, VatTu&vt);
void HieuChinhVatTu( NODEVATTU &root);
int DemNutCayNhiPhan(NODEVATTU root);
int DemNutLa(NODEVATTU root);
bool HieuChinhSoLuongTon(NODEVATTU root,char *ma,int n);
//bool is_MaVatTu(NODEVATTU r, char *MaVatTu);
void remove(NODEVATTU &root, char *MaVatTu);
void remove_case3(NODEVATTU &p,NODEVATTU &root);
//--file UI--
int InitMenu(string *Menu);
int IntMenu1(string *Menu);
int MenuDynamic(int x,int y,string *Menu, int n);
int ShowMenuPhu(int i, int x, int y);
int MenuTONG(int x,int y,string *Menu, int n);
//--file mylib--
void UI();
char *getTenVatTu();
int getNumber(int n);
char *getMaVatTu();
void KhungTrangThai(HCN tren, HCN duoi,int mamau);
void VeDuongThangDoc(int toadoX, int toadoY1, int toadoY2);
void TrangThai(int x, int y, string str);
void colorDialogue();
void ColorUI();
void VeDuongThangNgang(int toadoX1, int todoX2, int toadoY);
void xoaMeuPhu(int x,int y);
void VeHinhChuNhat(HCN TopLeft,HCN BotRight, int MaMau );
void HightLight();
void colorBasic();
void nohidecursor();
void hidecursor();
void SetBGColor(WORD color);
void SetColor(WORD color);
void clreol( );
int wherey( void );
int wherex( void );
void gotoxy(short x, short y);
bool TiepTuc();
bool Thoat();
char getLoai(char x1,char x2);
void XoaTrangThai(int x,int y);
int ESC_ENTER_F2();
//--file nhan vien
void NhapDanhSachNhanVien(LISTNHANVIEN &ls);
NhanVien NhapNhanVien();
void InsertNhanVien(LISTNHANVIEN &ls,NhanVien nv);
bool FullNhanVien(LISTNHANVIEN ls);
bool is_EmptyNhanVien(LISTNHANVIEN ls);
void HienThiDanhSachNhaVien(LISTNHANVIEN ls);
void showDanhSachNhanVien(LISTNHANVIEN ls);
NhanVien *searchNhanVienBinary(ListNhanVien ls, char *Ma, int low, int high); 
void InitNhanVien(LISTNHANVIEN &ls);
//int searchIndexInsert(ListNhanVien ls, char *Ma, int low, int high);
int Search_index_NhanVien(LISTNHANVIEN ls, char *ma);
NhanVien *Search_infor_NhanVien (LISTNHANVIEN ls, char *ma);
void HieuChinhNhanVien( LISTNHANVIEN &ls);
void showNhanVienDon(NhanVien nv);
void delete_NhanVien(LISTNHANVIEN &ls,int vitri);
void XoaNhanVien(LISTNHANVIEN &ls);
int searchIndexInsertfollowName(ListNhanVien ls, string tenHo, int low, int high);
//file CTHD
CT_HOADON LapCTHoaDon(char *Ma);
int Insert_CTHoaDon(HOADON &hd,CT_HOADON cthd);
//file HoaDon
HOADON *NhapHoaDon(LISTNHANVIEN ls,NODEVATTU nodeVatTu);
char *getMa(int n);
void Init_DSHoaDon(PTRHoaDOn &first);
bool is_EmptyHoaDon(PTRHoaDOn First);
PTRHoaDOn newNode();
void Insert_First(PTRHoaDOn &First,HOADON x);
void Insert_After(PTRHoaDOn p,HOADON x);
PTRHoaDOn Search_infor(PTRHoaDOn First,HOADON x);	
int Delete_First(PTRHoaDOn &First);
void ClearList(PTRHoaDOn &First);
void Traverser(PTRHoaDOn First);
DateAndTime getNgayLapHoaDon();
void ChucNangLapHoaDon(LISTNHANVIEN ls,NODEVATTU nodeVatTu);
PTRHoaDOn KiemTraMaHoaDon(LISTNHANVIEN ls,char *ma);
bool DocDSHoaDon(LISTNHANVIEN ls);
string toStringDateAndTime(DateAndTime dateAndTime);
int TongTriGiaHoaDon(HOADON hoaDon);
void In_1_HoaDon(HOADON hoaDon, int x, int y);
void Xoa_1_VatTu_CTHD(HOADON &hoaDon,char *ma);

