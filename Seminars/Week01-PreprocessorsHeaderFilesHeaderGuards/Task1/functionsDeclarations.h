struct DynArray
{
    int capacity;
    int size;
    int* numbers;
};

DynArray create();

void push_back(DynArray& array, int element);

void resize(DynArray& array);

void pop_back(DynArray& array);

int get(DynArray array, int index);

void remove(DynArray& array, int index);


