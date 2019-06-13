#define MAXLIST 500 
#define MAX_CTHD 20
struct VatTu{
	char MAVT[11];
	char TENVT[31];
	char DVT[11];
	int SLT; // so luong ton;
};
struct nodeVatTu{
//	int key; // Ma Vat tu la khoa khong trung => lay lam key
	VatTu vatTu;
	struct nodeVatTu *left;
	struct nodeVatTu *right; 
};
typedef struct nodeVatTu *NODEVATTU;
typedef struct{
	int day;
	int month;
	int year;
}DateAndTime;
typedef struct{
	char MAVT[11];
	int Sl;
	float DonGia;
	int Vat;
}CT_HOADON;
//struct nodeCT_HOADON{
//	int n;
//	struct nodeCT_HOADON *next;
//};
//typedef nodeCT_HOADON *PTRNodeCTHD;
struct HOADON{
	char SoHD[21];
	DateAndTime dateAndTime;
	char Loai;
	int n;// danh sach tuyen tinh
	CT_HOADON dscthd[MAX_CTHD];// danh sach vat tu co toi da 20 vat tu
};
struct NodeHoaDon{
	HOADON hoadon;
	struct NodeHoaDon * next;
};
typedef struct NodeHoaDon *PTRHoaDOn;
struct NhanVien{
	char MANV[11];
	char HO[31];
	char TEN[11];
	bool PHAI;
	PTRHoaDOn DSHoaDon;
};
struct ListNhanVien{
	int sl;
	NhanVien *dsnv[MAXLIST];
};
typedef ListNhanVien LISTNHANVIEN;
struct DoanhThuVatTu{
	char MaVatTu[11];
	float DanhThu;
};
struct NodeDanhThu{
	DoanhThuVatTu doanhThuVatTu;
	struct NodeDanhThu *next;
};
typedef NodeDanhThu *PTRDOANHTHU;
