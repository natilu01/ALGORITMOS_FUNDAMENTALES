#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *derecho;
    Nodo *izquierdo;
};


Nodo *crearNodoPadresHijos(int n);

Nodo *arbolBinario = NULL;

void insertarNodosEnArbolBinario(Nodo *&arbolBinario, int n);

void mostrarArbolBinario(Nodo *&arbolBinario, int separador);

void preOrden (Nodo *&arbolBinario);
void postOrden(Nodo *&arbolBinario);
void inOrden(Nodo *&arbolBinario);


int main(){

    int n;
    int opcion;

    cout<<"\t\t\tALGORITMOS FUNDAMENTALES "<<endl;
    cout<<"\t\t\tARBOL BINARIO\n"<<endl;

    cout<<"\tIngrese 1 si desea el recorrido del arbol en PRE-ORDEN"<<endl;
    cout<<"\tIngrese 2 si desea el recorrido del arbol en POST-ORDEN"<<endl;
    cout<<"\tIngrese 3 si desea el recorrido del arbol en IN-ORDEN"<<endl;
    cin>>opcion;

   switch(opcion){

     case 1:

     cout<<"\n\t\tCASO 1 PRE-ORDEN\n"<<endl;

      
      //ARBOL
      for(int i=0; i<7;i++)
    {
        cout<<"Ingrese el numero:  ";
        cin>>n;
        insertarNodosEnArbolBinario(arbolBinario,n);
        cout<<""<<endl; 
    }
    mostrarArbolBinario(arbolBinario,0);
    cout<<""<<endl; 
    cout<<""<<endl; 

    //RECORRIDO
    cout<<"RECORRIDO EN PRE-ORDEN ES:  ";
    preOrden(arbolBinario);
    cout<<""<<endl;

 break;


      case 2:

  cout<<"\n\t\tCASO 2 POST-ORDEN\n"<<endl;

  //ARBOL
       for(int i=0; i<7;i++)
    {
        cout<<"Ingrese el numero:  ";
        cin>>n;
        insertarNodosEnArbolBinario(arbolBinario,n);
        cout<<""<<endl; 
    }
    mostrarArbolBinario(arbolBinario,0);
    cout<<""<<endl; 
    cout<<""<<endl; 
     
  //RECORRIDO
    cout<<"RECORRIDO EN POST-ORDEN ES:  ";
    postOrden(arbolBinario);
    cout<<""<<endl;
    break;


      case 3:

        cout<<"\n\t\tCASO 3 IN-ORDEN\n"<<endl;


    //ARBOL
       for(int i=0; i<7;i++)
    {
        cout<<"Ingrese el numero:  ";
        cin>>n;
        insertarNodosEnArbolBinario(arbolBinario,n);
        cout<<""<<endl; 
    }
    mostrarArbolBinario(arbolBinario,0);
    cout<<""<<endl; 
    cout<<""<<endl; 

    //RECORRIDO
    cout<<"RECORRIDO EN IN-ORDEN ES:  ";
    inOrden(arbolBinario);
    cout<<""<<endl;
    break;
    
     default:
     cout<<"\tERROR"<<endl;
      cout<<"\tesa opcion no existe"<<endl;

      
     break;
   }
     
    return 0;
}


Nodo *crearNodoPadresHijos(int n)
{
    Nodo *nuevo= new Nodo();
    nuevo -> dato=n;
    nuevo -> derecho=NULL;
    nuevo -> izquierdo=NULL;
    return nuevo;
}

void insertarNodosEnArbolBinario(Nodo *&arbolBinario, int n)
{
    if (arbolBinario==NULL)
    {
        Nodo *nuevo = crearNodoPadresHijos(n);
        arbolBinario = nuevo;
    }
    else
    {
        int datoRaiz = arbolBinario->dato;
        if (n<datoRaiz)
        {
            insertarNodosEnArbolBinario(arbolBinario->izquierdo,n);
        }
        else
        {
            insertarNodosEnArbolBinario(arbolBinario->derecho,n);
        }
    }
}
//Pre Orden

void preOrden (Nodo *&arbolBinario)
{
    if (arbolBinario==NULL)
    {
       return;
    }
    else
    {
        cout<<arbolBinario->dato<<"-";
        preOrden(arbolBinario->izquierdo);
        preOrden(arbolBinario->derecho);
    }
}
//Post Orden

void postOrden(Nodo *&arbolBinario)
{
	if(arbolBinario==NULL)
	{
		return ;
	}
	else
	{
    	postOrden(arbolBinario->izquierdo);
        postOrden(arbolBinario->derecho);
        cout << arbolBinario->dato << "-";
	 
	}

}

//In Orden

void inOrden(Nodo *&arbolBinario)
{
    if(arbolBinario==NULL)
    {
    	return ;
	}else
	{
		inOrden(arbolBinario->izquierdo);
        cout << arbolBinario->dato << "-";
        inOrden(arbolBinario->derecho);
	}
            
}

//MUESTRA EL ARBOL BINARIO
void mostrarArbolBinario(Nodo *&arbolBinario, int separador)
{
    if (arbolBinario==NULL)
    {
       return;
    }
    else
    {
       mostrarArbolBinario(arbolBinario->derecho,separador+1);
       for (int i=0; i<separador; i++)
       {
           cout<<"    ";
        }
        cout<<arbolBinario->dato<<endl;
        mostrarArbolBinario(arbolBinario-> izquierdo,separador+1);
    }
}








