#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <time.h>

typedef char string[50];
//deklarasi fungsi + prosedur

void menuadmin(string nama_koin[], string kode_koin[], float harga_koin[]);
void menuclient(string nama_koin[], string kode_koin[], float harga_koin[]);

void tampilkoin(string nama_koin[], string kode_koin[], float harga_koin[]);
void tampilkoin2(string nama_koin[], string kode_koin[], float harga_koin[]);
void randomharga(string nama_koin[], string kode_koin[], float harga_koin[]);

void sortdata(string nama_koin[], string kode_koin[], float harga_koin[]);

int main(int argc, char *argv[]) {
	string nama_koin[10] ={"Bitcoin","Ethereum","Tether","Cardano", "Dogecoin","Polygon","Solana","Litecoin","Shiba Inu","Chainlink"};
	string kode_koin[10]={"BTC","ETH","USDT","ADA","DOGE","MATIC","SOL","LTC","SHIB","LINK"};
	float harga_koin[10]={29000,1912,1,0.41,0.08,1.02,23.41,91,0.01,7.21};
	
	do{
		system("cls");
		string user, pass;
		printf("\n\t[Menu Login]");
		printf("\n\n\tUsername : "); fflush(stdin); gets(user);
		printf("\tPassword : "); fflush(stdin); gets(pass);
		if(strcmp(user, "koin")==0 && strcmp(pass, "kripto")==0){
			menuadmin(nama_koin, kode_koin, harga_koin);
		}else if(strcmp(user, "guest")==0 && strcmp(pass, "guest")==0){
			menuclient(nama_koin, kode_koin, harga_koin);
		}else{
			printf("\n\t[!] Username atau Password salah"); getch();
		}
		
	}while(true);
	
	return 0;
}

void menuadmin(string nama_koin[], string kode_koin[], float harga_koin[]){
	string nama, kode;
	float harga;
	int menu, index;
	do{
		system("cls");
		printf("\n\t--=== [CryptoCurrency] ===--");
		printf("\n\n\t[1] Tambah Crypto");
		printf("\n\t[2] Tampil Crypto");
		printf("\n\t[3] Ubah Data Crypto");
		printf("\n\t[4] Hapus Crypto");
		printf("\n\t[0] Logout");
		printf("\n\t[5] Sorting by Kode Koin (Bonus)");
		printf("\n\t>>> "); scanf("%d", &menu);
		
		switch(menu){
			case 1: 
				if(getEmptyIndex(harga_koin) != -1){
					index=getEmptyIndex(harga_koin);
					printf("[Tambah Crypto]\n");
						do{
							printf("\nNama koin : "); fflush(stdin); gets(nama);
							if(strlen(nama)==0){
								printf("\n[!] Nama tidak boleh kosong");
							}
						}while(strlen(nama)==0);
						
						do{
							printf("\nKode koin : "); scanf("%s", &kode);
							if(strlen(kode)<3 || strlen(kode)>5){
								printf("\n[!] Kode koin harus berjumlah 3 s/d 5 karakter");
							}else if(findkoin(kode_koin, kode)!=-1){
								printf("\n[!] Kode koin tidak boleh sama");
							}
						}while(strlen(kode)<3 || strlen(kode)>5|| findkoin(kode_koin, kode) != -1);
						
						//harga koin
						do{
							printf("\nHarga koin : "); scanf("%s", &harga);
							if(harga < 0){
								printf("\n[!] Harga koin tidak boleh minus");
							}
						}while(harga < 0);
						
						strcpy(nama_koin[index], nama);
						strcpy(kode_koin[index], kode);
						harga_koin[index]=harga;
						
						printf("\n[+] Berhasil menginputkan data");
				}else{
					printf("\n\n\t[!] Data Crypto sudah penuh");
				}
			break;
			break;
				
			case 2: 
				tampilkoin(nama_koin, kode_koin, harga_koin);
			break;
			
			case 3: 
				printf("[Ubah Data Crypto]\n");
				printf("\nMasukkan kode koin yang ingin diubah : "); fflush(stdin); scanf("%s", &kode);
				if(findkoin(kode_koin, kode) != -1 && strlen(kode)!= 0){
					index=findkoin(kode_koin, kode);
					
					do{
						printf("\nNama koin baru : "); fflush(stdin); gets(nama);
						if(strlen(nama)==0){
							printf("[!] Nama tidak boleh kosong ");
						}
					}while(strlen(nama)==0);
					
					do{
						printf("\nKode koin baru : "); fflush(stdin); scanf("%s", &kode);
						if(strlen(kode)<3 || strlen(kode)>5){
							printf("\n[!] Kode koin harus berjumlah 3 s/d 5 karakter");
						}else if(findkoin(kode_koin, kode) != -1){
							printf("\n[!] Kode koin tidak boleh sama");
						}
					}while( (strlen(kode)<3 || strlen(kode)>5) || findkoin(kode_koin, kode) != -1);
					
					strcpy(nama_koin[index], nama);
					strcpy(kode_koin[index], kode);
					
					//harga ngga diubah
					//harga_koin[index]=harga;
					printf("\n[+] Berhasil mengubah data Crypto");
				}else{
					printf("\n[!] Kode koin yang dicari tidak ditemukan");
				}
			break;
			
			case 4: 
				printf("[Hapus Crypto]\n");
				printf("\nMasukkan kode koin yang ingin dihapus : "); scanf("%s", &kode);
				if(findkoin(kode_koin, kode) != -1 && strlen(kode) != 0){
					index = findkoin(kode_koin, kode);
					strcpy(nama_koin[index], "");
					strcpy(kode_koin[index], "");
					harga_koin[index]=0;
					printf("[+] Berhasil menghapus data Crypto");
				}else{
					printf("\n[!] Kode koin yang dicari tidak ditemukan");
				}
				
			break;
			
			case 5: 
				sortdata(nama_koin, kode_koin, harga_koin);
				printf("\n[~] Berhasil men-sorting crypto");
			break;
			
			case 0: 
				printf("\n\n\t[~] Logout berhasil . . .");
			break;
			
			default: 
				printf("\n\n\t[!] Menu tidak tersedia");
			break;
		}getch();
		
		
	}while(menu !=0);
}

void menuclient(string nama_koin[], string kode_koin[], float harga_koin[]){
	int menu, index, i;
	string kode, nama;
	int day=1;
	
	do{
		system("cls");
		printf("\n\t--=== [CryptoCurrency] ===--");
		printf("\n\n\t[1] Crptoprice");
		printf("\n\t[2] Cari by Kode Koin");
		printf("\n\t[0] Logout");
		printf("\n\t[3] Next Day (Bonus)");
		printf("\n\t>>> "); scanf("%d", &menu);
		
		switch(menu){
			case 1: 
				tampilkoin2(nama_koin, kode_koin, harga_koin);
			break;
			
			case 2: 
			printf("[Cari Crypto]\n");
				printf("\nMasukkan kode koin yang ingin dicari : "); fflush(stdin); scanf("%s", &kode);
				if(findkoin(kode_koin, kode) != -1 && strlen(kode) != 0){
					index=findkoin(kode_koin, kode);
					
					for(i=0;i<10;i++){
						if(i==index){
							printf("\nNama koin  : %s", nama_koin[i]);
							printf("\nKode koin  : %s", kode_koin[i]);
							printf("\nHarga koin : %.2f", harga_koin[i]);
						}
					}
					
				}else{
					printf("\n[!] Kode koin yang dicari tidak ditemukan");
				}
			
			break;
			
			case 3: 
				day++;
				printf("\n\n\t[Hari ke-%d]", day);
				randomharga(nama_koin, kode_koin, harga_koin);
			break;
			
			
			case 0: 
				printf("\n\n\t[~] Logout berhasil . . .");
			break;
			
			default: 
				printf("\n\n\t[!] Menu tidak tersedia");
			break;
		}getch();
		
		
	}while(menu !=0);
}

int getEmptyIndex(float harga_koin[]){
	int i;
	for(i=0;i<10;i++){
		if(harga_koin[i]==0.00){
			return i;
		}
	}
	return -1;
}

int findkoin(string kode_koin[], string kode){
	int i;
	for(i=0;i<5;i++){
		if(strcmp(kode_koin[i], kode)==0){
			return i;
		}
	}
	return -1;
}

void tampilkoin(string nama_koin[], string kode_koin[], float harga_koin[]){
	printf("\n[Kode] \t\t [Harga]");
	
	int i;
	for(i=0;i<10;i++){
		if(harga_koin[i] >= 0 && strlen(nama_koin[i])!=0 && strlen(kode_koin[i])!=0 ){
			printf("\n%s \t\t %.2f $", kode_koin[i], harga_koin[i]);
			printf("\n%s", nama_koin[i]);
		}
	}
}

void tampilkoin2(string nama_koin[], string kode_koin[], float harga_koin[]){
	printf("\n[Kode] \t [Harga]");
	
	int i;
	for(i=0;i<10;i++){
		if(harga_koin[i] >= 0 && strlen(nama_koin[i])!=0 && strlen(kode_koin[i])!=0 ){
			printf("\n%s \t %.2f $", kode_koin[i], harga_koin[i]);
		}
	}
}

void sortdata(string nama_koin[], string kode_koin[], float harga_koin[]){
	int i, j;
	float wadahint;
	string temp;
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(strcmp(kode_koin[j], kode_koin[j+1]) < 0){
				//swap kodekoin
				strcpy(temp, kode_koin[j]);
				strcpy(kode_koin[j], kode_koin[j+1]);
				strcpy(kode_koin[j+1], temp);
				//swap namakoin
				strcpy(temp, nama_koin[j]);
				strcpy(nama_koin[j], nama_koin[j+1]);
				strcpy(nama_koin[j+1], temp);
				//swap hargakoin
				wadahint = harga_koin[j+1];
				harga_koin[j+1] = harga_koin[j];
				harga_koin[j] = wadahint;
			}
		}
	}
}


void randomharga(string nama_koin[], string kode_koin[], float harga_koin[]){
	srand(time(NULL));
	int random;
	float randomnum;
	
	int i;
	for(i=0;i<9;i++){
		random= rand()%((515)+1-(-515))+(-515);
		randomnum=1.00*random/100;
		
		if(harga_koin[i]-5.15 >=0){
			harga_koin[i] += randomnum;
		}else if(harga_koin[i]-5.15 < 0){
			harga_koin[i] += randomnum;
			
			if(harga_koin[i] <0){
				harga_koin[i] =0;
			}
		}
	}
}
