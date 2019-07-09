#include <iostream>
#include<cstdlib>
using namespace std;
int t;
void ingresarElementos(int arr[], int n);
void mostrarElementos(int arr[],int n);
void algoritmoInserccion(int arr[], int n);
bool algoritmoInterpolacion (int arr[], int n, int num,int c);
void menu ();
 

int main()
{
	//cambio de colores de fondo y color letra
//	system("color 70 ");//fondo//letra
	cout<<"_________________________________"<<endl;
	cout<<"  ALGORITMOS FUNDAMENTALES"<<endl;
	cout<<"  AMOGUIMBA JESSICA"<<endl;
	cout<<"  GUALLICHICO NATALY"<<endl;
	cout<<"  QUIJIA LIZETH"<<endl;
	cout<<"_________________________________"<<endl;
	
   menu();

    return 0;
}

void ingresarElementos(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<"\n\t\t Elemento-->";
		cin>>arr[i];
    }


}
void mostrarElementos(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        cout<<"|"<<arr[i]<<"|";
    }

}
void algoritmoInserccion(int arr[], int n)
{
    //ALGORITMOO X INSERCCIÓN
    for(int i=0; i<n; i++)
    {

        int aux=arr[i];
        for(int j=i; j>0 ; j--)
        {
            if(arr[j-1]>aux)
            {
                arr[j]=arr[j-1];
                arr[j-1]=aux;
            }
        }
    }
}


bool algoritmoInterpolacion
(int arr[], int n, int num,int c)
{
    //ALGORITMO X INTERPOLACIÓN

    int primero=0;

    int ultimo=n-1;

    int medio;



    medio= primero+((num-arr[primero])*(ultimo -primero))/(arr[ultimo]-arr[primero]);

    if(c<n)
    {
        if(arr[medio]<num)
        {
            primero=medio+1;
        }

        if(arr[medio]>num)
        {
            ultimo=medio-1;
        }

        else
            primero=medio;

            algoritmoInterpolacion(arr,n,num,c+1);

    }

    if(arr[primero]==num)
        return true;
    else
         return false;

}

void menu(){
	int opc;
	do{
		
	cout<<"\n\t\t\t------MENU------"<<endl;
	cout<<endl;
	cout<<"\t\t1  Ingrese Elementos\n";
    cout<<"\t\t2  Mostrar elementos ingresados\n";
    cout<<"\t\t3  Ordenar elementos\n";
    cout<<"\t\t4  Buscar elemento\n";
    cout<<"\t\t5  Salir\n\n";
    cout<<"\t\t  Ingrese una opcion:  ";
	cin>>opc;
    cout<<endl;
	int arr[t];
	int c=0;
	
	
	
	switch(opc)
	{
		case 1:
		cout<<"------Ingrese Elementos------\n"<<endl;
		cout<<"\t\t\tINGRESE EL TAMANIO PARA EL ARREGLO: ";
        cin>>t;
        
    	ingresarElementos(arr,t);
    	cout<<endl;
    	
		break;
		case 2:
		cout<<"-------Mostrar elementos ingresados------\n"<<endl;
		cout<<"\t\t\tLos elementos que ingreso son:  ";
		mostrarElementos(arr,t);
        cout<<endl;	
		break;
		case 3:
		cout<<"-------Ordenar elementos------\n"<<endl;
		//ALGORITMOO X INSERCCIÓN    
		cout<<"\t\t\tLos elementos ordenados son:" ;
		cout<<"\t\t"<<algoritmoInserccion(arr,t);
		cout<<endl;
		mostrarElementos(arr,t);
		break;
		case 4:
		cout<<"------Buscar elemento------\n"<<endl;
		int num;
    	cout<<"\t\t\tINGRESE EL NUMERO A BUSCAR: ";
    	cin>>num;
    	
    	if (algoritmoInterpolacion(arr,t,num,c)==true)
		{
			cout<<"ELEMENTO ENCONTRADO";
		}
        else{
            cout<<"ELEMENTO NO ENCONTRADO";
        }

		
		   	
		break;
		case 5:cout<<"Adios...!!"<<endl;
		
		break;

		default: cout<<"El valor ingresado no esta en el menu"<<endl;
	}
   // cin.ignore(); 
	}while(opc!=6);
	
	
}
	

