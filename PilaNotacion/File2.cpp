#include <iostream>
#include "UPilaDi.h"
#include <math.h>
using namespace std;

//Declaracion de metodos
string postfijainfijaToPostfija(string cadena);
bool es_digito(char c);
bool es_operador(char c);
//int evaluarPostfija(string cadena);

int main() { //Principal
	string infija="(22+3)*5";
	string postfija= postfijainfijaToPostfija(infija);
	cout<< postfija <<endl;
	system("pause");
	return 0;
}

//Metodos Logica    2
bool es_digito(char c){
   return c >= 0x30 && c <= 0x39 ;
}
//                    +
bool es_operador(char c){
  return c =='^'||c =='*'||c =='/'||c =='+'||c =='-';
}

int prioridad_infija(char c){
  if (c == ' ^ ')
		return 4;
	if (c == ' * ')
		return 2;
	if (c == ' / ')
		return 2;
	if (c == ' + ')
		return 1;
	if (c == ' - ')
		return 1;
	if (c == '(')
		return 5;
}

int prioridad_pila(char c){
	if (c == ' ^ ')
		return 3;
	if (c == ' * ')
		return 2;
	if (c == ' / ')
		return 2;
	if (c == ' + ')
		return 1;
	if (c == ' - ')
		return 1;
	if (c == '(')
		return 0;
}

string postfijainfijaToPostfija(string cadena){
   PilaDi p;
   string postfija="";
   for(int i=0;i<cadena.length();i++){
	  char c=cadena[i];//
	  if(es_digito(c)){
		 string num="";
		 char aux=cadena[i];   //2
		 while(es_digito(aux)){
			 num+=aux;   //2
			 i++;
			 aux=cadena[i];
		 }
		 i--;
		 postfija+=num+" ";      //aqui solo carga numeros
		 cout<< " postfija=" << postfija<<endl;

	  }else{
		 if(es_operador(c)){
			bool salir=false;
			while(!salir){
			 char aux=p.cima();  //( --consulta
			 cout<< p.to_str()<<endl;
			  if(p.vacia()||
			  (prioridad_infija(c)> prioridad_pila(aux)) ){
				 p.meter(c);
				   cout<< p.to_str()<<endl;
				  salir=true;
			  }else{
				  int x;
				  p.sacar(x);
				  aux=x;
				  postfija+=aux;
			  }



			}
		 } else{
			 if(c=='('){
			  p.meter(c);
				 cout<< p.to_str()<<endl;
			 }else{
				 if(c==')'){
				 char aux;
				 do{

						int x ;
						p.sacar(x);
						aux=x;
						if(aux!='(')
							postfija+=aux;

				   }while(aux!='(');

				 }
             }

         }
      }

   }

   char aux;
   while(!p.vacia()){
   int x;
	p.sacar(x);
	aux=x;
	postfija+=aux;
   }



   int evaluarPostfija(string cadena) {
	PilaDi p;
	int z = 0;
	for (int i = 0; i < cadena.length(); i++) {
		char c = cadena[i];
		if (es_digito(c)) {
			string num = "";
			char aux = cadena[i];
			while (es_digito(aux)) {
				num += aux;
				i++;
				aux = cadena[i];
			}
			i--;
			int n = atoi((char*)num.c_str());
			p.meter(n);
		}
		else if (c != ' ') {
			int op1, op2;
			p.sacar(op2);
			p.sacar(op1);
			char operacion = c;
			z = evaluar(op1, c, op2);
			p.meter(z);
		}
	}
	return z;
}





   return postfija;
}

