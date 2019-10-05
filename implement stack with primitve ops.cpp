#include <iostream>
using namespace std;

#include <climits>

class StackUsingArray {
int *data;
int nextIndex;
int capacity;

public :

StackUsingArray(int totalSize) {
data = new int[totalSize];
nextIndex = 0;
capacity = totalSize;
}

// return the number of elements present in my stack
int size() {
return nextIndex;
}

bool isEmpty() {

return nextIndex == 0;
}

// insert element
void push(int element) {
if(nextIndex == capacity) {
cout << "Stack full " << endl;
return;
}
data[nextIndex] = element;
nextIndex++;
}

// delete element
int pop() {
if(isEmpty()) {
cout << "Stack is empty " << endl;
return INT_MIN;
}
nextIndex--;
return data[nextIndex];
}

int top() {
if(isEmpty()) {
cout << "Stack is empty " << endl;
return INT_MIN;
}
return data[nextIndex - 1];
}
};

int main() {
    int n;
    cout<<"Enter the Stack array size\n";
    cin>>n;
StackUsingArray st(n);
cout<<"Choose from the following-\n"
   <<"1. push\n"
   <<"2. pop\n"
   <<"3. Display top\n"
   <<"4. Check for Empty Stack\n";
int choice;
        cin >> choice;
        int input;

        while (choice !=-1) {
            if(choice == 1) {
                cin >> input;
                st.push(input);
            }
            else if(choice == 2) {
                int ans = st.pop();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }
            else if(choice == 3) {
                int ans = st.top();
                if(ans != 0) {
                    cout << ans << endl;
                }
                else {
                    cout << "-1" << endl;
                }
            }

            else if(choice == 4) {
                cout << st.isEmpty() << endl;
            }
            cin >> choice;
        }

return 0;
}
