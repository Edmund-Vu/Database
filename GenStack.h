using namespace std;

template <class T>
class GenStack{
  public:
    int size;
    int top;
    T *myArray;

    GenStack();
    GenStack(int maxSize);
    ~GenStack();
    void push(T d);
    T pop();
    T peak();
    void grow();
    bool isFull();
    bool isEmpty();
};

template <class T>
GenStack<T>::GenStack(){
  myArray = new T[10];
  size = 10;
  top = -1;
}

template <class T>
GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize];
  size = maxSize;
  top = -1;
}

template <class T>
GenStack<T>::~GenStack(){
  delete myArray;
}

template <class T>
void GenStack<T>::push(T d){
  if(!this->isFUll()){
    myArray[++top] = d;
  } else{
    this->grow();
  }
}

template <class T>
T GenStack<T>::pop(){
  if(!this->Empty()){
    return myArray[top--];
  } else{
    throw std::invalid_argument("Stack Empty");
  }
}

template <class T>
T GenStack<T>::peak(){
  if(!this->isEmpty()){
    return myArray[top];
  } else{
    throw std::invalid_argument("Stack Empty");
  }
}

template <class T>
void GenStack<T>::grow(){
  T* newArray = new T[size + 10];
  for(int i = 0; i < size; ++i){
    newArray[i] = myArray[i];
  }
  myArray = newArray;
  size += 10;
}

template <class T>
bool GenStack<T>::isFull(){
  return(top == size - 1);
}

template <class T>
bool GenStack<T>::isEmpty(){
  return(top == -1);
}
