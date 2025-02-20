#include <iostream>
using namespace std;


class CVector {
private:
    int* m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;

    void Init(int delta) {
        m_nCount = 0;
        m_nMax = delta;
        m_nDelta = delta;
        m_pVect = new int[m_nMax];
    }

    void Resize() {
        m_nMax += m_nDelta;
        int* temp = new int[m_nMax];
        for (int i = 0; i < m_nCount; i++) {
            temp[i] = m_pVect[i];
        }
        delete[] m_pVect;
        m_pVect = temp;
    }

public:
    // Constructor
    CVector(int delta = 10) {
        Init(delta);
    }

    // Método para insertar un elemento al final del vector
    void Insert(int elem) {
        if (m_nCount == m_nMax) {
            Resize();
        }
        m_pVect[m_nCount++] = elem;
    }

    // Método para mostrar los elementos del vector
    void Display() {
        for (int i = 0; i < m_nCount; i++) {
            cout << m_pVect[i] << " ";
        }
        cout << endl;
    }

    int BinarySearchRecursive(int left, int right, int target) {
        if (left <= right) {
            int mid = left + (right - left) / 2;
            if (m_pVect[mid] == target) return mid;
            if (m_pVect[mid] > target) return BinarySearchRecursive(left, mid - 1, target);
            return BinarySearchRecursive(mid + 1, right, target);
        }
        return -1;
    }

    int BinarySearchIterative(int target) {
        int left = 0, right = m_nCount - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (m_pVect[mid] == target) return mid;
            if (m_pVect[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }

    int GetCount() const {
        return m_nCount;
    }

    ~CVector() {
        delete[] m_pVect;
    }
};

// Función principal
int main() {
    CVector gVect;

    gVect.Insert(5);
    gVect.Insert(10);
    gVect.Insert(15);
    gVect.Insert(20);
    gVect.Insert(30);
    gVect.Insert(50);

    cout << "Elementos en el vector: ";
    gVect.Display(); // Mostrar los elementos antes de la búsqueda

    int target = 20;

    int resultRec = gVect.BinarySearchRecursive(0, gVect.GetCount() - 1, target);
    cout << "Búsqueda recursiva - ";
    if (resultRec != -1) {
        cout << "Elemento " << target << " encontrado en la posición: " << resultRec << endl;
    } else {
        cout << "Elemento " << target << " no encontrado." << endl;
    }

    int resultIter = gVect.BinarySearchIterative(target);
    cout << "Búsqueda iterativa - ";
    if (resultIter != -1) {
        cout << "Elemento " << target << " encontrado en la posición: " << resultIter << endl;
    } else {
        cout << "Elemento " << target << " no encontrado." << endl;
    }

    return 0;
}
