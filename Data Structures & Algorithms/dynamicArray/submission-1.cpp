class DynamicArray {
private:
    int* arrays;
    int size;
    int capacity;
public:
    
    DynamicArray(int capacity) {
        this->arrays = new int[capacity];
        this->size = 0;
        this->capacity = capacity;
    }

    int get(int i) {
        if(i >= 0 && i < size){
            return arrays[i];
        } else {
            throw out_of_range("index out of bound");
        }
    }

    void set(int i, int n) {
        if(i >= 0 && i < size){
            arrays[i] = n;
        } else {
            throw out_of_range("index is out of range");
        }
    }

    void pushback(int n) {
        if(size == capacity){
            resize();
        } 
        //add the element
        arrays[size] = n;
        size++;
    }

    int popback() {
        if(size > 0){
            size--;
            return arrays[size];
        } else {
            throw out_of_range("Index out of bound access");
        }
    }

    void resize() {
        // Allocating a new array with double the current capacity.
            capacity *= 2;
            int* newArray = new int[capacity];
        // Copying the elements from the old array to the new one.
            for(int i = 0; i < size; i++){
                newArray[i] = arrays[i];
            }
        // Deleting the old array.
            delete[] arrays;
        //update the array pointer
            arrays = newArray;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
