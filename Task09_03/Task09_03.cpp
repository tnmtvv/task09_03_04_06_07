// Task09_03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
void output01(int** arr, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            printf_s("%d ", arr[i][j]);
        }
        printf_s("\n");
    }

}

void output01double(double** arr, int n, int m)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            printf_s("%lf ", arr[i][j]);
        }
        printf_s("\n");
    }

}

void solution(double** arr, int n, double** y)
{

    int k = 0;
    double mnoj;
    //обратно
    for (k = n - 1; k > 0; k--)
    {
        for (int j = k - 1; j >= 0; j--) {
            mnoj = arr[j][k];
            arr[j][k] -= arr[k][k] * mnoj;
            for (int i = n - 1; i >= 0; i--)
                y[j][i] -= y[k][i] * mnoj;
        }
    }

}

void swapdouble(double& a, double& b) {

    double t;

    t = a;
    a = b;
    b = t;
}

void swap(int& a, int& b) {
    int t;

    t = a;
    a = b;
    b = t;
}

void Copy(double** arr1, double** arr2, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            arr2[i][j] = arr1[i][j];
        }
    }

}

double** MtrxMult(double** arr1, double** arr2, int n) {

    double** prov = (double**)malloc(n * sizeof(double*));

    for (int i = 0; i < n; i++)
    {
        prov[i] = (double*)malloc(n * sizeof(double));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            prov[i][j] = 0;

            for (int k = 0; k < n; k++)
                prov[i][j] += arr1[i][k] * arr2[k][j];

            //if (fabs(c[i][j]) < 0.000001)
            //    c[i][j] = 0;
        }

    }
    return prov;
}


void choiceSort(int* arr, int n, int m, int** arr2d, int strrow )
{
    int min;
    for (int j = 0; j < n; j++) {
        min = arr[j];
        int indmin = j;
        for (int i = j + 1; i < n; i++) {
            if (arr[i] < min) {
                min = arr[i];
                indmin = i;

            }

        }
        if (arr[j] > min)
        {

            swap(arr[indmin], arr[j]);
            if (strrow == 1)//сортируем по строкам
            {
                //for (int k = 0; k < m; k++)
                //{
                //    swaparray(arr2d[indmin], arr2d[j]);
                //}

                for (int k = 0; k < m; k++) {
                    swap(arr2d[indmin][k], arr2d[j][k]);
                }
                    
            }

            if (strrow == 2)//сортируем по столбцам
            {
                for (int k = 0; k < m; k++) {
                    swap(arr2d[k][indmin], arr2d[k][j]);
                }
            }
        }
    }
}

double detcalcutation(double** arr, int n, int sign) {

    double det = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                det *= arr[i][j];
            }
        }
    }

    return det * sign;

}

double** triangular_matrix2_0(double** arr, int n, int& sign) {

    int k = 0, index;
    double curcoeff;
    while (k < n)
    {
        //туда
        // если коэффициент ноль, меняем строки
        if (arr[k][k] == 0)
        {
            sign *= -1;
            index = 0;
            for (int i = k + 1; i < n; i++)
            {
                if (arr[i][k] != 0)
                {
                    index = i;
                    break;
                }
            }

            if (index == 0)
            {

                return NULL;
            }

            else
            {
                for (int j = 0; j < n; j++)
                    swapdouble(arr[k][j], arr[index][j]);
            }
        }
        
        curcoeff = arr[k][k];
        for (int i = k + 1; i < n; i++)
        {
            double mnoj = arr[i][k];
            for (int j = 0; j < n; j++)
                arr[i][j] = arr[i][j] - (arr[k][j] / curcoeff) * mnoj;
        }
        k++;
        printf("\n");
    }
    
    return arr;
}


double** triangular_matrix(double** arr, int n, double** y) {

    int k = 0, index;
    double curcoeff;
    while (k < n)
    {
        //туда

        // если коэффициент ноль, меняем строки
        if (arr[k][k] == 0)
        {
            index = 0;
            for (int i = k + 1; i < n; i++)
            {
                if (arr[i][k] != 0)
                {
                    index = i;
                    break;
                }
            }

            if (index == 0)
            {

                return NULL;
            }

            else
            {

                for (int j = 0; j < n; j++)
                {
                    swapdouble(arr[k][j], arr[index][j]);
                    swapdouble(y[k][j], y[index][j]);
                }
            }

        }


        curcoeff = arr[k][k];

        for (int j = 0; j < n; j++)
        {
            arr[k][j] = arr[k][j] / curcoeff;
            y[k][j] = y[k][j] / curcoeff;
        }

        for (int i = k + 1; i < n; i++)
        {

            int mnoj = arr[i][k];
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = arr[i][j] - arr[k][j] * mnoj;
                y[i][j] = y[i][j] - y[k][j] * mnoj;
            }
        }
        k++;
    }

        return y;
}


void task09_07()
{
    int n;
    printf_s("Введите количество строк и столбцов:\n ");
    scanf_s("%d", &n);

    double det = 0;

    double** arr = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (double*)malloc(n * sizeof(double));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("arr[%i][%i] = ", i, j);
            scanf_s("%lf", &arr[i][j]);
        }

    }

    output01double(arr,n, n);

    int sign = 1;
    arr = triangular_matrix2_0(arr, n, sign);
    if (arr == NULL) {
        printf_s("Определитель матрицы равен 0\n ");
    }
    else 
    {
        det = detcalcutation(arr, n, sign);

        printf_s("Определитель матрицы равен:\n ");
        printf_s("%f", det);
    }


}

void task09_06()
{
    int n;
    printf_s("Введите количество строк и столбцов:\n ");
    scanf_s("%d", &n);

    double** arr = (double**)malloc(n * sizeof(double*));
    double** arr_copy = (double**)malloc(n * sizeof(double*));
    double** Emtrx = (double**)malloc(n * sizeof(double*));
    double** answ = (double**)malloc(n * sizeof(double*));

    for (int i = 0; i < n; i++)
    {
        arr[i] = (double*)malloc(n * sizeof(double));
        arr_copy[i] = (double*)malloc(n * sizeof(double));
        Emtrx[i] = (double*)malloc(n * sizeof(double));
        answ[i] = (double*)malloc(n * sizeof(double));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf_s("arr[%d][%d] = ", i, j);
            scanf_s("%lf", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == j)
            {
                Emtrx[i][j] = 1;
            }
            else Emtrx[i][j] = 0;
        }
    }
    Copy(arr, arr_copy, n);
    if (triangular_matrix(arr, n, Emtrx) != NULL) {


        solution(arr, n, Emtrx);
        printf_s("\nобратная матрица\n");

        output01double(Emtrx, n, n);

        printf_s("\nпроверка\n");
        printf_s("A * A^-1 = ");
        printf_s("\n");
        answ = MtrxMult(Emtrx, arr_copy, n);
        output01double(answ, n, n);
    }
    else {
        printf_s("Решений нет (");
    }

}

void task09_04() {

    int n, m;

    printf_s("Введите количество строк и столбцов \n");
    scanf_s("%d%d", &n, &m);

    int choice;

    int** arr1 = (int**)malloc(n * sizeof(int**));
    for (int j = 0; j < n; j++)
    {
        arr1[j] = (int*)malloc(m * sizeof(int*));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("arr[%i][%i] = ", i, j);
            scanf_s("%d", &arr1[i][j]);
        }

    }
    printf("\nМассив\n");

    output01(arr1, n, m);


    printf_s("Как вы хотите отсортировть массив: 1 - по строкам, 2 - столбцам \n");
    scanf_s("%d", &choice);

    int* array;
    if (choice == 1)
    {
        array = (int*)malloc(n * sizeof(int*));

        for (int i = 0; i < n; i++)
        {
            array[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
            {
                array[i] += arr1[i][j];
            }
        }
        choiceSort(array, n, m, arr1, choice);

        
        //choiceSort(array, n, m, arr1, choice);
    }


    else
    {
        array = (int*)malloc(m * sizeof(int*));

        for (int i = 0; i < m; i++)
        {
            array[i] = 0;
        }

        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++)
            {
                array[j] += arr1[i][j];
            }
        }
        choiceSort(array, m, n, arr1, choice);
        
    }

    
    printf("\nотсортированный массив\n");
    output01(arr1, n, m);

}


void task09_03()
{
    int n = 9, m = 9;

    int** arr1 = (int**)malloc(n * sizeof(int**));
    for (int j = 0; j < n; j++)
    {
        arr1[j] = (int*)malloc(m * sizeof(int*));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("arr[%i][%i] = ", i, j);
            scanf_s("%d", &arr1[i][j]);
        }

    }
    printf("\nМассив\n");

    output01(arr1, n, m);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            if (i <= j && j <= n - i - 1 || i >= j && j >= n - i - 1)
            {
                sum += arr1[i][j];
            }
        }
    }

    printf_s("\nсумма равна\n");
    printf("%d", sum);
}


int main()
{
    setlocale(LC_ALL, "Russian");

    setlocale(LC_ALL, "Russian");

    int n = 5;

    while (n != 0) {
        printf("\nВведите номер задания\n");
        printf("\n1 - task 9.3, 2 - task 9.4, 3 - task 9.6, 4 - task 9.7, любая другая клавиша - завершение программы\n");
        scanf_s("%d", &n);

        switch (n) {
        case 1:
            task09_03();

            break;

        case 2:
            task09_04();
            break;

        case 3:
            task09_06();
            break;

        case 4:
            task09_07();
            break;
        default:
            n = 0;
            break;
        }

    }
   
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
