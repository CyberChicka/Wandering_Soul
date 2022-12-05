#ifndef WANDERING_SOUL_SMART_POINTER_H
#define WANDERING_SOUL_SMART_POINTER_H

template<typename T> // T может быть чем угодно
class SmartPointer{
public:
    SmartPointer(T *ptr){
        this->ptr = ptr;
    }
    ~SmartPointer(){
        delete ptr; // очищаем память
    }
    T& operator*(){ // чтобы вытаскивать информацию
        return  *ptr;
    }
private:
    T *ptr; // этот указатель может быть чем угодно
};

#endif //WANDERING_SOUL_SMART_POINTER_H
