#include <stdio.h>
#include <stdlib.h>
#define M 5
#define N 4
void read_set_collection(int Set_Collection[][M], int size){
	int i , j, data;

	for(i=0;i<size;i++){
		printf("���� �� �������� ��� ������� s%d:\n",i);
			
		for(j=0;j<M;j++){
				printf("������ �� �������� s%d ��� ������ s (0 (���) , 1 (���)) : ",i); // ������ �� ��������
				scanf("%d",&data);
				if(data==1||data==0)// �� �� �������� �����
					Set_Collection[i][j]=data; // �� ������� ���� ������
				else            
					j-=1;  // �� �� �������� ����� ����� ��������� ��� pointer ��� ���� ����
		}
	}	
	for(i=0;i<size;i++){
			
		for(j=0;j<M;j++){
			printf("%d ",Set_Collection[i][j]); // �������� ��� ������
			
		}
			printf("\n");
	}
		printf("\n");
}
		
double jaccard_coefficient(int Set_Collection[][M],int size,int row1,int row2){
	int i;
	int datasect=0,datajoin=5; // ��� ��������� ��� ��� ���� ����� ��� ��� ��� ��� ����� ��� �� ������������ ��� 
	
	double coefficient; // �����������
	
		for(i=0;i<M;i++){ // ����������� ��� ������ ��� ��������� ��� 2 ������� ��� �������
			if((Set_Collection[row1][i]==Set_Collection[row2][i])){ // �� ����� ��� �� �������� �������� ��� �������
					datasect++;              // ��������� ��� ����
					
					if((Set_Collection[row1][i]==0 ) &&  (Set_Collection[row2][i]==0)){// �� �������� ��� �� 2 �������� �� 0 
						datajoin--;   // ��������� ���� ��� �� ������ ��� ������
						datasect--; // ��� ��� �����
						
					}
		}

	}
		printf("\n");
	coefficient=(double)datasect/datajoin; // ������ ���������� �� ���� �� ������

	return coefficient; //��� ��� ������������
	
}



void set_clustering(int Set_Collection[][M], int size){
	
	int i, j,k,rowone,rowtwo,helptemp,*help;// ���������� ��� �� ����������� ��� ������ ��� ��� �� ������� ��� �������
	
	double max,temp;// ���������� ��� ��� max coefficient

	
	
	for(k=size;k>1;k--){// ���������� ��� �� ������� ��� ������� ����� ��  �������� ��� 2 ���������
	
		max=-1;
		for(i=0;i<k-1;i++){
			for(j=i+1;j<k;j++){    // �������� �� ��������� ��� �� ������ ��� ��������� ��� ��� ������� 
				temp=jaccard_coefficient(Set_Collection,k ,i ,j);//��� ��� ������������ �� ��� ��������� ���������
				if(temp >= max){// ��������� �� ���������� � �� ������ ������� ������ �������� �����
					max=temp; 
					rowone=i;// ��� ������� ��� ����������� ������� 
					rowtwo=j;
				}	
			}
				
		}
		printf("�� ������������ ��� ������������ ����� :\n");
		
		printf("�� ������ ���� �������  %d, %d, �� ���� ���������� %0.2f  ������������� ��� ������ %d \n",rowone,rowtwo,max,rowone); 
			printf("\n");
		for(i=rowone;i<rowtwo;i++){ //��������� ���� ��� ����� ��� ������� ��� ��� ����������
			for(j=0;j<M;j++){
	
				Set_Collection[rowone][j]=Set_Collection[rowone][j] | Set_Collection[rowtwo][j];// (�� �� ����� ��� bitwise operator | )  ��� ���� ��� 1� �� ���� 1 ���� �� ��� �� 2 �������� ��� ����� 0 
	
			}
		}
	
		for(i=rowtwo+1;i<k;i++){// ���������� ��� �� ������ ���� ��� �� ������� ������
			for(j=0;j<M;j++){
				Set_Collection[i-1][j]=Set_Collection[i][j];// ����������� ��� ������� ��� ���� ��� ���� 
			}
		}
		
		printf("\n");
		printf("� ������� ����� :\n");

		for(i=0;i<k-1;i++){//��������� ��� ������ ���� ��� ������ ��������
				
			for(j=0;j<M;j++){
					printf("%d ",Set_Collection[i][j]); 	
			}
				printf("\n");
		}
		
		
	}	
	
}


int main (){
	system("chcp 1253>nul");
	int i;
	int Set_Collection[N][M];
	
	read_set_collection(Set_Collection,N);
	set_clustering(Set_Collection,N);
	
	return 0;
}

