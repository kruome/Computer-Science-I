```cpp

#include <iostream>
using namespace std;

int main(){
    int values[3] = { 4, 7, 11 };
    int *valptr = values;
    for (int i = 0; i < 3; i++){
        cout<<valptr[i]<<" ";
    }cout<<endl;
    
    cout<<values<<endl;
    cout<<valptr<<endl;
    
    cout<<*values;
    return 0;
}

--------------------------------------------------------

int
main ()
{
  int values[3] = { 4, 7, 11 };

  int *valptr = values;
  
  
  for (int i = 0; i < 3; i++)
    {
      cout << valptr[i] << " ";
    } cout << endl;

  cout << values<<endl;
  cout<< *valptr<< " "<< *(valptr+1)<< " "<< *(valptr+2);
  
  return 0;
}

```