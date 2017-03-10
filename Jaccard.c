#include <stdio.h>
#include <stdlib.h>
#define M 5
#define N 4
void read_set_collection(int Set_Collection[][M], int size){
	int i , j, data;

	for(i=0;i<size;i++){
		printf("Δώσε τα στοιχεία του συνόλου s%d:\n",i);
			
		for(j=0;j<M;j++){
				printf("Ανήκει το στοιχείο s%d στο σύνολο s (0 (ΟΧΙ) , 1 (ΝΑΙ)) : ",i); // ζηταμε τα στοιχεια
				scanf("%d",&data);
				if(data==1||data==0)// αν τα στοιχεία σωστα
					Set_Collection[i][j]=data; // τα βάζουμε στον πίνακα
				else            
					j-=1;  // αν τα στοιχεια είναι λάθος στελνουμε τον pointer μια θεση πίσω
		}
	}	
	for(i=0;i<size;i++){
			
		for(j=0;j<M;j++){
			printf("%d ",Set_Collection[i][j]); // εμφάνιση του πίνακα
			
		}
			printf("\n");
	}
		printf("\n");
}
		
double jaccard_coefficient(int Set_Collection[][M],int size,int row1,int row2){
	int i;
	int datasect=0,datajoin=5; // μια μεταβλητη για την τομη πρωτα και μια για την ένωση που τα περιλαμβάνει όλα 
	
	double coefficient; // συντελεστης
	
		for(i=0;i<M;i++){ // διατρέχουμε τον πινακα και ελέγχουμε τις 2 γραμμές που θέλουμε
			if((Set_Collection[row1][i]==Set_Collection[row2][i])){ // αν ειναι ισα τα εκαστοτε στοιχεια των συνολων
					datasect++;              // αυξανουμε την τομη
					
					if((Set_Collection[row1][i]==0 ) &&  (Set_Collection[row2][i]==0)){// αν βρεθουνε και τα 2 εκαστοτε με 0 
						datajoin--;   // μειώνουμε κατα ένα το πληθος της ένωσης
						datasect--; // και της τομής
						
					}
		}

	}
		printf("\n");
	coefficient=(double)datasect/datajoin; // ευρεση συντελεστη με βάση το πληθος

	return coefficient; //και τον επιστρέφουμε
	
}



void set_clustering(int Set_Collection[][M], int size){
	
	int i, j,k,rowone,rowtwo,helptemp,*help;// μεταβλητες για να διατρέχουμε τον πίνακα και για να κρατάμε τις γραμμές
	
	double max,temp;// μεταβλητές για τον max coefficient

	
	
	for(k=size;k>1;k--){// ξεκινώντας απο το μεγεθος των συνολων μεχρι να  φτασουμε στα 2 τελευταία
	
		max=-1;
		for(i=0;i<k-1;i++){
			for(j=i+1;j<k;j++){    // τρέχουμε τη συναρτηση για να βρούμε την ομοιότητα των των γραμμων 
				temp=jaccard_coefficient(Set_Collection,k ,i ,j);//και την αποθηκεύουμε σε μια προσωρινη μεταβλητη
				if(temp >= max){// βρίσκουκε τη μεγαλύτερη η αν βρεθεί επόμενη μεγάλη πέρνουμε αυτήν
					max=temp; 
					rowone=i;// και κρατάμε τις αντιστοιχες γραμμές 
					rowtwo=j;
				}	
			}
				
		}
		printf("Τα αποτελέσματα των συγχωνεύσεων είναι :\n");
		
		printf("Τα σύνολα στις γραμμές  %d, %d, με τιμή ομοιότητας %0.2f  αποθηκεύονται στη γραμμή %d \n",rowone,rowtwo,max,rowone); 
			printf("\n");
		for(i=rowone;i<rowtwo;i++){ //ψαχνοντας μεσα στο εύρος των γραμμών που μας ενδιαφέρει
			for(j=0;j<M;j++){
	
				Set_Collection[rowone][j]=Set_Collection[rowone][j] | Set_Collection[rowtwo][j];// (με τη χρήση του bitwise operator | )  στη θέση της 1η θα μπει 1 μονο αν και τα 2 στοιχεια δεν ειναι 0 
	
			}
		}
	
		for(i=rowtwo+1;i<k;i++){// ξεκινώντας απο τη γραμμή κατω απο τη δεύτερη γραμμη
			for(j=0;j<M;j++){
				Set_Collection[i-1][j]=Set_Collection[i][j];// μετακινούμε τις γραμμές μια θέση πιο πάνω 
			}
		}
		
		printf("\n");
		printf("Ο πίνακας είναι :\n");

		for(i=0;i<k-1;i++){//τυπώνουμε τον πίνακα κατα μια γραμμή λιγότερη
				
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

