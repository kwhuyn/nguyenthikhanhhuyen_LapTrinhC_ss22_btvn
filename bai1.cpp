#include <stdio.h>
#define MAX 100
struct Grade {
	float math;
	float eng;
	float phys;
};
struct Student {
	char name[50];
	int age;
	struct Grade grade;
};

void inputStudent (struct Student st[],int n){
	for(int i=0;i<n;i++){
		printf("Nhap thong tin sinh vien thu %d:\n",i+1);
		getchar();
		printf("Nhap ho ten:");
		fgets(st[i].name,sizeof(st[i].name),stdin);
		printf("Nhap tuoi:");
		scanf("%d",&st[i].age);
		printf("Nhap diem mon toan:");
		scanf("%f",&st[i].grade.math);
		printf("Nhap diem mon anh:");
		scanf("%f",&st[i].grade.eng);
		printf("Nhap diem mon vat ly:");
		scanf("%f",&st[i].grade.phys);
	}
}
void outputStudent(struct Student st[],int n){
	printf("Thong tin cac sinh vien:\n");
	for(int i=0;i<n;i++){
		printf("Sinh vien thu %d:\n",i+1);
		printf("Ho ten:%s\n",st[i].name);
		printf("Tuoi:%d",st[i].age);
		printf("Diem toan:%.2f\n",st[i].grade.math);
		printf("Diem anh:%.2f\n",st[i].grade.eng);
		printf("Diem vat ly:%.2f\n",st[i].grade.phys);
		printf("\n");		
	}
	
}
void avarage(struct Student st[],int n){
	for(int i=0;i<n;i++){
		printf("Diem trung binh cua sinh vien %d\n",i+1);
		printf("%.2f",(st[i].grade.math+st[i].grade.eng+st[i].grade.phys)/3);
	}
	
}
int main(){
	int n=0,choose;
	struct Student st[MAX];
	do{
		printf("===================MENU======================\n");
		printf("1.Nhap thong tin hoc sinh\n");
		printf("2.Hien thi thong tin hoc sinh\n");
		printf("3.Tinh diem trung binh hoc sinh\n");
		printf("Nhap chuc nang:");
		scanf("%d",&choose);
		switch(choose){
			case 1:{
				printf("Nhap so luong sinh vien:");
				scanf("%d",&n);
				inputStudent(st,n);
				break;
			}
			case 2:{
				outputStudent(st,n);
				break;
			}
			case 3:{
				avarage(st,n);
				break;
			}
			default:
				printf(">>> Lua chon khong hop le! Vui long nhap 1-4.\n");
                break;
		}
	}while(choose!=4);
	return 0;
}
