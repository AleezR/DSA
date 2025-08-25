 #include <stdio.h>
int main(){
int i,j,row1,col1,row2,col2,mat1[10][10],mat2[10][10],sp_mat1[10][3],sp_mat2[10][3],k=1,l=1,a=1,b=1,s=1,add[20][3];
printf("FIRST MATRIX\n");
printf("Enter the row for the matrix :");
scanf("%d",&row1);
printf("Enter the column for the matrix :");
scanf("%d",&col1);
for(i=0;i<row1;i++){
	for(j=0;j<col1;j++){
		printf("Enter the element :");
		scanf("%d",&mat1[i][j]);	
		}
	}

i=j=0;
printf("SECOND MATRIX\n");
printf("Enter the row for the matrix :");
scanf("%d",&row2);
printf("Enter the column for the matrix :");
scanf("%d",&col2);
for( i=0;i<row2;i++){
	for(j=0;j<col2;j++){
		printf("Enter the element :");
		scanf("%d",&mat2[i][j]);	
		}
	}
	
printf("First matrix\n");
for(i=0;i<row1;i++){
	for(j=0;j<col1;j++){
		printf("%d\t",mat1[i][j]);
		}
		printf("\n");
	}
printf("Second matrix\n");
for(i=0;i<row2;i++){
	for(j=0;j<col2;j++){
		printf("%d\t",mat2[i][j]);
		}
		printf("\n");
	}

// sparse matrix 1
for(i=0;i<row1;i++){
    for(j=0;j<col1;j++){
        if(mat1[i][j] != 0){
            sp_mat1[k][0] = i;
            sp_mat1[k][1] = j;
            sp_mat1[k][2] = mat1[i][j];
            k++;
        }
    }
}
sp_mat1[0][0] = row1;
sp_mat1[0][1] = col1;
sp_mat1[0][2] = k - 1;

// sparse matrix 2
for(i=0;i<row2;i++){
    for(j=0;j<col2;j++){
        if(mat2[i][j] != 0){
            sp_mat2[l][0] = i;
            sp_mat2[l][1] = j;
            sp_mat2[l][2] = mat2[i][j];
            l++;
        }
    }
}
sp_mat2[0][0] = row2;
sp_mat2[0][1] = col2;
sp_mat2[0][2] = l - 1;

// addition 
if(row1 == row2 && col1 == col2){
    while(a < k && b < l){
        if(sp_mat1[a][0] == sp_mat2[b][0] && sp_mat1[a][1] == sp_mat2[b][1]){
            add[s][0] = sp_mat1[a][0];
            add[s][1] = sp_mat1[a][1];
            add[s][2] = sp_mat1[a][2] + sp_mat2[b][2];
            a++; b++; s++;
        }
        else if(sp_mat1[a][0] < sp_mat2[b][0] || 
               (sp_mat1[a][0] == sp_mat2[b][0] && sp_mat1[a][1] < sp_mat2[b][1])){
            add[s][0] = sp_mat1[a][0];
            add[s][1] = sp_mat1[a][1];
            add[s][2] = sp_mat1[a][2];
            a++; s++;
        }
        else{
            add[s][0] = sp_mat2[b][0];
            add[s][1] = sp_mat2[b][1];
            add[s][2] = sp_mat2[b][2];
            b++; s++;
        }
    }
    
    while(a < k){
        add[s][0] = sp_mat1[a][0];
        add[s][1] = sp_mat1[a][1];
        add[s][2] = sp_mat1[a][2];
        a++; s++;
    }
    while(b < l){
        add[s][0] = sp_mat2[b][0];
        add[s][1] = sp_mat2[b][1];
        add[s][2] = sp_mat2[b][2];
        b++; s++;
    }

    add[0][0] = row1;
    add[0][1] = col1;
    add[0][2] = s - 1;
}

printf("THE SUM OF SPARSE MATRIX .....\n");
for(int h=0;h<s;h++){
	printf("%d\t%d\t%d\n",add[h][0],add[h][1],add[h][2]);
}
int trans;

for(int h=0;h<s;h++){
	trans=add[h][0];
	add[h][0]=add[h][1];
	add[h][1]=trans;
}

printf("TRANSPOSE....\n");
for(int h=0;h<s;h++){
    printf("%d\t%d\t%d\n",add[h][0],add[h][1],add[h][2]);
}

return 0;
}
