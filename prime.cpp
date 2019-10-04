#include <iostream>
#include<cstdlib>

using namespace std;
 int prime (int num)    
 {
     

            for(int i=2; i<=num/2; i++)

           {

                if(num%i==0)

               {

                  return 0;

               }

           }
   return 1;
 }
            



int main(int argc, char**argv)

{
           int s = atoi(argv[1]);
           int e = atoi(argv[2]);
           
              for(int i=s;i<=e;i++)
            
        {
           cout<<prime(i)<< " ";
		}
		
		
}	
