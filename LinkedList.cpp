
#include <iostream>
using namespace std;

class ListNode{
    public:
    ListNode(const double data, ListNode* next = nullptr){
        this->_data = data;
        this->_nextPtr = next;
    }
    
    double _data;
    ListNode* _nextPtr;
};

class List{
    public:

    List(){
        _firstPtr = nullptr;
        _lastPtr = nullptr; 
        _count = 0;
    }
    List(int num) : List()
    {
        while(num > 0)
        {
            insertAtFront(num % 10);
            num /= 10;
        }
    }
    ~List(){
        double data;
        while(removeFromFront(data))
        {
        }
    }
    
    void insertAtFront(const double data){
        ListNode* newPtr = createNode(data);
        newPtr->_nextPtr = _firstPtr;
        if(this->isEmpty()) _lastPtr = newPtr;
        _firstPtr = newPtr;
        _count++;
    };
    void insertAtBack(const double data){
        ListNode* newPtr = createNode(data);
        if(this->isEmpty())
            _lastPtr = _firstPtr = newPtr;
        else{
        _lastPtr->_nextPtr = newPtr;
        _lastPtr = newPtr;
        }
        _count++;
    };
   bool insertAfterIndex(const int index, const double data){
        if(_count == 0 || index >= _count || index < 0)
            return false;
        
        if(index == _count - 1)
            insertAtBack(data);
        else{
                ListNode* newPtr = createNode(data);
                
                ListNode* current = _firstPtr;
                for(int i = 0; i < index; i++)
                    current = current->_nextPtr;
                newPtr->_nextPtr = current->_nextPtr;
                current->_nextPtr = newPtr;
            }
        
        _count++;
        
        return true;
    };
    bool removeFromFront(double& data){
        if(this->isEmpty())
            return false;
        
        ListNode* next = _firstPtr->_nextPtr;
        data = _firstPtr->_data;
        delete _firstPtr;
        if(next == nullptr) _lastPtr = nullptr;
        _firstPtr = next;
        _count--;
        
        return true;
    };
    bool removeFromBack(double& data){
        if(this->isEmpty())
            return false;
        
        data = _lastPtr->_data;    
        
        if(_lastPtr == _firstPtr)
        {
            delete _lastPtr;
            _lastPtr = _firstPtr = nullptr;
            return true;
        }
        
        ListNode* current = _firstPtr;
        while(current->_nextPtr != _lastPtr)
            current = current->_nextPtr;
        delete _lastPtr;
        current->_nextPtr = nullptr;
        _lastPtr = current;
        _count--;
        
        return true;
    };
    int getElementCount(){
        return _count;
    };
    ListNode* getFirstNode()
    {
        return _firstPtr;
    }
    bool isEmpty() const {
        return _firstPtr == nullptr;
    };
    void print() const {
        cout << "List { ";
        ListNode* current = _firstPtr;
        while(current != nullptr)
        {
            cout << current->_data;
            
            current = current->_nextPtr;
        }
        cout << " }" << endl;
    };

    private:

    ListNode* createNode(const double data) const {
        return new ListNode(data);
    };
    
    public:
    
    int _count;

    private:
    
    ListNode* _firstPtr;
    ListNode* _lastPtr;
};

class Summator
{
    private:
    
    List& l1;
    List& l2;
    int l1Sum;
    int l2Sum;
    
    public:
    
    Summator(List& l1, List& l2) : l1(l1), l2(l2)
    {
        l1Sum = getSum(l1);
        l2Sum = getSum(l2);
    }
    
    List& add()
    {
        return *new List(l1Sum + l2Sum);
    }
    
    void getAdders(List& sum, List& adder1, List& adder2)
    {
        adder1 = *new List(getSum(sum) - getSum(l1));
        adder2 = *new List(getSum(sum) - getSum(adder1));
    }
    
    private:
    
    int getSum(List& l)
    {
        ListNode* node = l.getFirstNode();
        int sum = 0;
        
        while(node != nullptr)
        {
            sum *= 10;
            sum += node->_data;
            node = node->_nextPtr;
        }
        
        return sum;
    }
};

int main()
{
    int a;
    int b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    
    List& l1 = *new List(a);
    List& l2 = *new List(b);
    
    l1.print();
    l2.print();
    
    Summator s = *new Summator(l1, l2);
    List& sum = s.add();
    cout << "Sum";
    sum.print();
    
    cout << "GetAdders -> ";
    sum.print();
    
    List adder1 = *new List, adder2 = *new List;
    s.getAdders(sum, adder1, adder2);
    sum.print();
    cout << endl << "------" << endl;
    adder1.print();
    cout << "+" << endl;
    adder2.print();
    
    return 0;
}
