#include "array_operations.h"
#include "vector_operations.h"
#include "list_operations.h"
#include "map_operations.h"
#include "deque_set_operations.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    dynamicArrayOperations();
    vectorOperations();
    listOperations();
    mapOperations();
    dequeSetOperations();
    return 0;
}
