#include<iostream>
using namespace std;
class A 
{ 
        int a; 
        public: 
        A() 
        {
                 a = 1; 
        } 
        virtual void show() 
        { 
                    cout <<a;
        } 
};

class B: public A 
{ 
         int b; 
         public: 
         B() 
         { 
                 b = 2; 
         }
          virtual void show() 
         {  
                  cout <<b;
         }
};

int main() 
{ 
           A *pA = new A; 
           B *oB = new B; 
           pA = oB; 
           pA->show();
		   cout<<"hello"; 
		   int a=16;
		   a=~a;
		   cout<<a;
           return 0; 
}