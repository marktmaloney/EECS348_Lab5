#include <stdio.h>

void sale_report(float* data){
    char* months[]= {"January", "February", "March", "April", "May", "June" ,"July" ,"August", "September", "October", "November" ,"December"};
    float min_sales=data[0];
    float max_sales=data[0];
    float avg_sales=0;
    int min_index=0;
    int max_index=0;
    printf("Monthly Sales report for 2022:\n");
    printf("Month\t     Sales\n");
    
    for (int i=0; i<12; i++){
        printf("%-9s    $%.2f\n", months[i], data[i]);
        
        if (data[i] < min_sales){
            min_sales=data[i];
            min_index=i;
        };
        if (data[i]>max_sales){
            max_sales=data[i];
            max_index=i;
        };
        avg_sales+=data[i];
    }
    avg_sales/=12;

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min_sales, months[min_index]);
    printf("Maximum sales: $%.2f (%s)\n", max_sales, months[max_index]);
    printf("Average sales: $%.2f \n", avg_sales);

    printf("\nSix-Month Moving Average Report:\n");   
    for (int i=0; i <=6; i++){
        float sum=0;
        for (int j=i; j <=i+5 ; j++){
            sum+=data[j];
        }
        printf("%-9s - %s\t $%9.2f\n", months[i],months[i+5], sum/6);
    }

    printf("\nSales Report (Highest to Lowest): \n");
    printf("Month\t        Sales\n");

    int sorted_indicies[]={0,1,2,3,4,5,6,7,8,9,10,11};

    for (int i=0; i<12; i++){
        for (int j=i+1; j<12; j++){
            if (data[sorted_indicies[i]]<data[sorted_indicies[j]]){
                int temparary= sorted_indicies[i];
                sorted_indicies[i]= sorted_indicies[j];
                sorted_indicies[j]=temparary;
            }
        }
    }
    for(int i=0; i<12; i++){
        printf("%-9s\t$%.2f\n", months[sorted_indicies[i]], data[sorted_indicies[i]]);
    }
}
int main(){
    FILE *file;
    float data[12];
    char filename[]="input.txt";
    file=fopen(filename,"r");
    for (int i=0; i <12; i++){
        fscanf(file, "%f", &data[i]);
    }

    fclose(file);
    sale_report(data);
    return 0;

}