#define MAXLIST 500 
#define Max 20
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
struct DateAndTime{
	int day;
	int mon;
	int year;
};
struct CT_HOADON{
	char MAVT[11];
	int Sl;
	float DonGia;
	int Vat;
};
//struct nodeCT_HOADON{
//	int n;
//	struct nodeCT_HOADON *next;
//};
//typedef nodeCT_HOADON *PTRNodeCTHD;
struct HOADON{
	char SoHD[21];
	DateAndTime Ngay;
	char Loai;
	int n;// danh sach tuyen tinh
	CT_HOADON dscthd[Max];// danh sach vat tu co toi da 20 vat tu
};
struct NodeHoaDon{
	HOADON hoadon;
	struct NodeHoaDon * next;
};
typedef struct NodeHoaDon *PTRHoaDOn;
struct NhanVien{
	char MANV[11];
	char HO[11];
	char TEN[31];
	bool PHAI;
	PTRHoaDOn HoaDon;
};
struct ListNhanVien{
	int sl;
	NhanVien *dsnv[MAXLIST];
};
