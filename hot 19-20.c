#include <stdio.h>
#include <conio.h>
#include <ctype.h>



int MAXQUEUE;
int queue[6];
int front=0;\
int rear;
int count = 0;

struct Order {

char customer[50];
int tn, kk, tc;
float totalPayment;
};

struct Order order[];

char month[20];
char ch;

int totaltn = 0, totalkk = 0, totaltc = 0;
float totalPayment = 0.00;

void addOrderInput();
void generateReport();

int main(){

    printf("Which month do you want to order?");
    scanf(" %[^\n]s", &month);

    printf("How many order for the month you choosen?");
    scanf("%d",&MAXQUEUE);

    struct Order order[MAXQUEUE];

   int rear = MAXQUEUE-1;
   addOrderInput(MAXQUEUE);
   generateReport();

	return 0;
}

void addOrderInput(){

   if(count==MAXQUEUE)
   {
        printf("\nEXCEDED LIMIT\n");
        system("pause");
   }
   else
   {
     while(count != MAXQUEUE){


		rear=(rear+1)%MAXQUEUE;
		count++;

        printf("\nCustomer %d name: ",count);
        scanf(" %[^\n]s", &order[rear].customer);

        printf("\nTart Nenas, Kuih Kapit and Tart Coklat orders (separate each input by space, ex:1 1 2) :");
        scanf("%d %d %d",&order[rear].tn,&order[rear].kk,&order[rear].tc);

        printf("\nThe number of order records in queue = %d\n",rear+1);

        order[rear].totalPayment = (order[rear].tn*30.00) +  (order[rear].kk*18.00) +( order[rear].tc*28.00);

        }
   }

}

void generateReport()
{
	int i=front;
	int j=count;

    if(count==0){
        printf("\n!!! Queue UNDERFLOW - \n");
        system("pause");
    }

	else
	{
        printf("\n\nOrder for month: %s ", month);
        printf("\nCustomer  Tart Nenas   Kuih Kapit  Tart coklat     Payment(RM)");

		while (j!=0)
		{

            printf("\n%-12s  %-12d  %-12d  %-12d  %-10.2f\n",order[i].customer,order[i].tn,order[i].kk,order[i].tc, order[i].totalPayment );
            totaltn = totaltn + order[i].tn;
            totalkk = totalkk + order[i].kk;
            totaltc = totaltc + order[i].tc;
            totalPayment = totalPayment + order[i].totalPayment;
			i=(i+1)%MAXQUEUE; //dequeue process
			j--;
		}
              printf("\n=========================================================");
              printf("\n Total Tart Nenas: %d", totaltn);
              printf("\n Total Tart Kapit: %d", totalkk);
              printf("\n Total Tart Coklat: %d", totaltc);
              printf("\n Total Payment: RM%.2f", totalPayment);
              printf("\n=========================================================");

	}
}

