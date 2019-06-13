#include<iostream>
#include<string.h>
#include<windows.h>
using namespace std;
struct VatTu{
	char MAVT[11];
	char TENVT[31];
	char DVT[11];
	int SLT; // so luong ton;
};
struct nodeVatTu{
	VatTu vatTu;
	struct nodeVatTu *left;
	struct nodeVatTu *right; 
};
typedef struct nodeVatTu *PTR;
void showVatTu(VatTu vt);
void Init(PTR &root){
	root==NULL;
}
void InsertNode(PTR &root,VatTu vt){
	if(root==NULL){
		root= new nodeVatTu;
		root->vatTu=vt;
		root->left=NULL;
		root->right=NULL;
	}
	else {
		int x= strcmp(root->vatTu.MAVT, vt.MAVT);
		if(x<0){
			InsertNode(root->left,vt);
		}
		else if(x>0){
			InsertNode(root->right,vt);
		}
	}
}
void LNR(PTR root){
	if(root!=NULL){
		LNR(root->left);
		showVatTu(root->vatTu);
		LNR(root->right);
	}
}
void NhapVatTu(VatTu &vt){
		cout<<"Nhap ma vat tu: ";
		cin.ignore();
		cin.getline(vt.MAVT,11);
		cout<<"Ten vat tu: ";
		cin.ignore();
		cin.getline(vt.TENVT,11);
		cout<<"Nhap DVT: ";
		cin.ignore();
		cin.getline(vt.DVT,11);
		cout<<"Nhap so luong ton";
		cin>>vt.SLT;
	
}
void showVatTu(VatTu vt){
	cout<<"Ma: "<<vt.MAVT<<endl;
	cout<<"Ten:"<<vt.TENVT<<endl;
	cout<<"DVT:"<<vt.DVT<<endl;
	cout<<"SLT:"<<vt.SLT;
}
int main(){
	PTR tree;
	Init(tree);
	VatTu vatu;
	int n;
	cout<<"Nhap tong so vat tu vao: ";
	cin>>n;
	for(int i=0;i<n;i++){
		NhapVatTu(vatu);
		InsertNode(tree,vatu);
		system("cls");
	}
	if(tree==NULL){
		cout<<"danh sach rong! ";
	}
	else{
		LNR(tree);
	}	
	
	return 0;
}
