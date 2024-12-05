#include<stdio.h>
int main(){
	int choice, del, search, length, arr[100];
	int odd = 0, even = 0;
	int a = 0;
	int b = length -1;
	int addNumber; 
	do{
		printf("---MENU---\n");
	    printf("1.Nhap so phan tu va gia tri cho mang\n");
	    printf("2.In ra gia tri cho cac phan tu trong mang\n");
	    printf("3.Dem so luong cac phan tu chan le trong mang\n");
	    printf("4.Tim gia tri lon thu hai trong mang\n");
	    printf("5.Them mot phan tu vao dau mang\n");
	    printf("6.Xoa phan tu\n");
	    printf("7.Sap xep mang theo thu tu giam dan\n");
	    printf("8.Tim kiem phan tu\n");
	    printf("9.In ra so nguyen to binh phuong\n");
	    printf("10.Sap xep mang theo thu tu giam dan\n");
	    printf("11.Thoat\n"); 
		printf("Moi nhap lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1://Nhap so phan tu va gia tri cho mang
		        printf("Moi ban nhap so luong phan tu cua mang:");
				scanf("%d", &length);
				printf("Moi ban nhap gia tri phan tu cua mang:\n");
				for(int i = 0; i < length; i ++){
					printf("Phan tu thu %d = ", i + 1);
					scanf("%d", &arr[i]); 
				}
				break; 
			case 2://In ra gia tri cho cac phan tu trong mang
			    printf("Gia tri cac phan tu cua mang la:\n");
			    for(int i = 0; i < length; i++){
			    	printf("Arr[%d] = %d\n", i + 1, arr[i] );
				}
				break; 
			case 3://Dem so luong cac phan tu chan le trong mang
			    for(int i = 0; i < length; i++){
			    	if(arr[i] % 2 != 0){
			    		odd ++; 
					} else {
						even ++; 
					} 
				}
				printf("Mang co %d so chan và %d so le\n", even, odd);
				break; 
			case 4://Tim gia tri lon thu hai trong mang
			    
			case 5://Them mot phan tu vao dau mang
			    printf("Moi ban nhap gia tri phan tu muon them vao trong mang: ");
	            scanf("%d", &addNumber);
		        for (int i = length + 1; i >= 0; i--){
                        arr[i] = arr[i - 1];
                }
                arr[0] = addNumber;
                length++;
                printf("Mang sau khi them phan tu la: ");
                for (int i = 0; i < length; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n"); 
                break; 
			case 6://Xoa phan tu
			    printf("Moi ban nhap vi tri phan tu muon xoa:\n");
				scanf("%d", &del);
			    if( 0 < del <= length){
		            for (int i = del - 1; i < length - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    length--;
                    printf("Mang sau khi xoa: ");
                    for (int i = 0; i < length; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
	            } else {
	                printf("Vi tri phan tu khong hop le\n ");
	            }
				break; 
			case 7://Sap xep mang theo thu tu giam dan(Insertion sort)
			    for(int i = 1; i < length;i++){
			    	int key = arr[i];
					int j = i - 1;
					while(j >= 0 && arr[j] < key){
						arr[j + 1] = arr[j];
						j = j - 1;
					}
					arr[j + 1] = key;	
				}
				printf("Mang sau khi duoc sap xep la:\n");
				for(int i = 0; i < length;i++){
					printf("%d ", arr[i]);
				}
				printf("\n"); 
				break; 
			case 8://Tim kiem phan tu
			    for(int i = 1; i < length;i++){
			    	int key = arr[i];
					int j = i - 1;
					while(j >= 0 && arr[j] > key){
						arr[j + 1] = arr[j];
						j = j - 1;
					}
					arr[j] = key;
				}
				printf("Moi ban nhap phan tu ban muon tim:\n");
				scanf("%d", &search);
				while( a <= b){
					int c = (a + b) / 2;
					if( search == arr[c]){
						printf("Vi tri phan tu ban muon tim la: %d\n", c + 2);
						break; 
					} else if(arr[c] < search){
						a = c + 1; 
					} else {
						b = c - 1; 
					}	
				}
				break;  
			case 9://In ra so nguyen to binh phuong
			case 10://Sap xep mang theo thu tu giam dan(Bubble sort)
			    for(int i = 0; i < length - 1; i++){
		            for(int j = 0;j < length - 1 - i; j++){
			            if(arr[j] < arr[j + 1]){
				            int temp = arr[j];
				            arr[j] = arr[j + 1];
				            arr[j + 1] = temp; 
			            } 
		            } 
	            }
	            printf("Mang sau khi duoc sap xep la:\n");
	            for(int i = 0; i < length; i++){
		            printf("%d ", arr[i]);
	            }
	            printf("\n"); 
	            break; 
			case 11://Thoat
			    printf("Thoat chuong trinh\n");
				break; 
			default:
				printf("Lua chon ban nhap khong hop le.Vui long nhap lai!\n"); 
			 
		} 
	}while (choice != 11); 
    return 0; 
} 
