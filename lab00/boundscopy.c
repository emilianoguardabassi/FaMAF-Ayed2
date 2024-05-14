#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
    res.is_upperbound=true;
    res.is_lowerbound=true;
    res.exists=false;
    res.where=1;
    for (unsigned int i = 0; i < length; i++)
    {
        if (arr[i]< value)
        {
            res.is_lowerbound=false;
        }
        else if (arr[i]>value)
        {
            res.is_upperbound=false;
        }
        else
        {
            res.exists=true;
            res.where=i;
        }
        
    }
    
    return res;
}

int main(void) {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;

    printf("Por favor ingrese los valores del arreglo para cada posición.\n");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Posición %d\n",i);
        scanf("%d",&a[i]);
    }   
    printf("Ingrese qué valor quiere checkear\n");
    scanf("%d",&value);
    /*
    printf("[ ");
        for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ",a[i]);
    }
    printf("]");
    printf("\n");
    */
    //
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    if (result.is_upperbound)
    {
        if (result.exists)
        {
            printf("El valor es un máximo y está en la posición %d\n",result.where);
        }
        else
        {
            printf("El valor es cota superior\n");
        }
        
       }
    else if (result.is_lowerbound)
    {
        if (result.exists)
        {
            printf("El valor es un mínimo y está en la posición %d\n",result.where);
        }
        else
        {
            printf("El valor es cota inferior\n");
        }
        
    }
    else
    {
        printf("El valor no ni cota superion ni inferior.\n");
    }
    
    return EXIT_SUCCESS;
}

