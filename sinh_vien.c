
#include <stdio.h>
#include <stdlib.h>

typedef struct sinh_vien
{
    char MSSV[11];
    char hoten[50];
    int tuoi;
    float KTLT;
    float CTDL;
    float WebSite;
    float diemTB;
    char hocLuc[10];
}sinh_vien;

void nhapThongTinSV(SV &sv);
void nhapSV(sinh_vien sv[], int n);
void ghiFile(sinh_vien sv[], int n, char fileName[]);
int docFile(sinh_vien sv[], char fileName[]);
void showStudent(sinh_vien sv[], int n);
void printfLine(int n);
void sapXepTheoTen(sinh_vien sv[], int n);
void sapXepTheoDTB(sinh_vien sv[], int n);
void tinhDTB(sinh_vien &sv);
void xeploai(sinh_vien &sv);
void timKiemTheoTen(sinh_vien sv[], char hoten[], int n);

int main() 
{
	int key;
    char fileName[] = "sinhvien.txt";
    sinh_vien arraySV[MAX];
    int soluongSV = 0;
	
	// nhap danh sach sinh vien tu file
    soluongSV = docFile(arraySV, fileName);
    idCount = idLonNhat (arraySV, soluongSV);
    
    while(true) 
	{
    	printf("CHUONG TRINH QUAN LY SINH VIEN C/C++\n");
    	printf("*************************MENU**************************\n");
    	printf("**  1. Them sinh vien.                               **\n");
    	printf("**  2. Cap nhat thong tin sinh vien boi ID.          **\n");
    	printf("**  3. Xoa sinh vien boi ID.                         **\n");
    	printf("**  4. Tim kiem sinh vien theo ten.                  **\n");
    	printf("**  5. Sap xep sinh vien theo diem trung binh (GPA). **\n");
    	printf("**  6. Sap xep sinh vien theo ten.                   **\n");
    	printf("**  7. Hien thi danh sach sinh vien.                 **\n");
    	printf("**  8. Ghi danh sach sinh vien vao file.             **\n");
    	printf("**  0. Thoat                                         **\n");
    	printf("*******************************************************\n");
    	printf("Nhap tuy chon: ");
    	scanf("%d", &key);
    	switch(key)
    	{
    		case 1:
    			printf("\n1. Them sinh vien.");
    			nhapSV(arraySV,soluongSV);
    			printf("\nThem sinh vien thanh cong!");
    			soluongSV++;
    			pressAnyKey();
    			break;
    		case 2:
    			break;
    		case 3: 
    			break;
    		case 4: 
    			if(soluongSV > 0)
    			{
    				printf("\n4. Tim kiem sinh vien theo ten.");
    				char strTen[30];
    				printf("\nNhap ten de tim kiem: "); fflush(stdin); gets(strTen);
    				timKiemTheoTen(arraySV, strTen, soluongSV);
				} else 
				{
					printf("\nSanh sach sinh vien trong!");
				}
				pressAnyKey();
                break;
            case 5: 
            	if(soluongSV > 0) {
                    printf("\n5. Sap xep sinh vien theo diem trung binh (GPA).");
                    sapxepTheoDTB(arraySV, soluongSV);
                    showStudent(arraySV, soluongSV);
                }else{
                    printf("\nSanh sach sinh vien trong!");
                }
                pressAnyKey();
                break;
		}
	}
}

void nhapThongTinSV(sinh_vien &sv)
{
	printf("\n Nhap MSSV: "); fflush(stdin); gets(sv.MSSV);
	printf("\n Nhap ten: "); fflush(stdin); gets(sv.hoten);
	printf("\n Nhap tuoi: "); fflush(stdin); scanf("%d", &sv.tuoi);
	printf("\n Nhap KTLT: "); fflush(stdin); scanf("%f", &sv.KTLT);
	printf("\n Nhap CDTL&GT: "); fflush(stdin); scanf("%f", &sv.CTDL);
	printf("\n Nhap WebSite: "); fflush(stdin); scanf("%f", &sv.WebSite);
	tinhDTB(sv);
	xeploai(sv);
}

void nhapSV(sinh_vien sv[], int n)
{
	printLine(40);
    printf("\n Nhap sinh vien thu %d:", n + 1);
    nhapThongTinSV(sv[n]);
    printLine(40);
}
void printfLine(int n)
{
	printf("\n");
	while(n>=0)
	{
		printf("_");
		--n;
	}
		
	printf("\n");	
}
void ghiFile(sinh_vien sv[], int n, char fileName[])
{
	FILE *f;
	f = fopen(fileName, "w");
	int i;
	for(i = 1; i <= n; i++)
		fprintf(f,"%s%s%d%f%f%f%f%s\n",sv[i].MSSV, sv[i].hoten, sv[i].tuoi, sv[i].KTLT, sv[i].CTDL, sv[i].WebSite, sv[i].diemTB, sv[i].hocLuc);
	fclose(f);
}

int docFile(sinh_vien sv[], char fileName[])
{
	FILE *f;
	int i = 0;
	f = fopen(fileName, "r");
	printf("Chuan bi doc file: %d", fileName);
	// doc thong tin sinh vien
	while(fscanf(f, "%s%s%d%f%f%f%f%s\n",&sv[i].MSSV, &sv[i].hoten, &sv[i].tuoi, &sv[i].KTLT, &sv[i].CTDL, &sv[i].WebSite, &sv[i].diemTB, &sv[i].hocLuc) != EOF)
	{
		i++;
		printf("Doc ban ghi thu: %d\n", i);
	}
	printf("So luong sinh vien co san trong file la: %d\n", i);
	return i;
	fclose(f);
}

void showStudent(sinh_vien sv[], int n)
{
	printfLine(100);
	printf("\n\tSTT\tMSSV\tHo va Ten\tTuoi\tKTLT\tCTDL&GT\tWebSite\tDiem Trung Binh\tHoc Luc");
	int i = 0;
	while(i < n)
	{
		printf("\n %d", i+1);
		printf("\t%s", sv[i].MSSV);
		printf("\t%s", sv[i].hoten);
		printf("\t%s", sv[i].tuoi);
		printf("\t%s", sv[i].KTLT);
		printf("\t%s", sv[i].CTDL);
		printf("\t%s", sv[i].WebSite);
		printf("\t%s", sv[i].diemTB);
		printf("\t%s", sv[i].hocLuc);
		i++;
	}
	printfLine(100);
}

void sapXepTheoTen(sinh_vien sv[], int n)
{
	// sap xep theo thu tu tang dan
	sinh_vien tmp;
	char tenSV1[50];
	char tenSV2[50];
	int i = 0;
	while(i < n)
	{
		strcpy(tenSV1, sv[i].hoten);
		int j = i+1;
		while(j < n)
		{
			strcpy(tenSV2, sv[j].hoten);
			if(strcmp(strupr(tenSV1), strupr(tenSV2)) > 0)
			{
				tmp = sv[i];
				sv[i] = sv[j];
				sv[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void sapXepTheoDTB(sinh_vien sv[], int n)
{
	sinh_vien tmp;
	int i = 0;
	while(i < n)
	{
		int j = i+1;
		while(j < n)
		{
			if(sv[i].diemTB > sv[j].diemTB)
			{
				tmp = sv[i].diemTB;
				sv[i].diemTB = sv[j].diemTB;
				sv[j].diemTB = tmp;
			}
			j++;
		}
		i++;
	}
	
}

void tinhDTB(sinh_vien &sv)
{
	sv.diemTB =(sv.CTDL + sv.KTLT + sv.WebSite)/3;
}
void xeploai(sinh_vien &sv)
{
	if(sv.diemTB >= 8) strcpy(sv.hocLuc, "Gioi");
	else if(sv.diemTB >= 6.5) strcpy(sv.hocLuc, "Kha");
    else if(sv.diemTB >= 5) strcpy(sv.hocLuc, "Trung binh");
    else strcpy(sv.hocLuc, "Yeu");
}
void timKiemTheoTen(sinh_vien sv[], char hoten[], int n)
{
	sinh_vien arrFound[MAX];
	char tenSV[50];
	int found = 0, i = 0;
	while(i < n)
	{
		strcpy(tenSV, sv[i].hoten);
		if(strstr(strupr(tenSV), strupr(ten)))
		{
			arrFound[found] = sv[i];
			found++;
		}
		i++;
	}
	showStudent(arrFound, found);
}
