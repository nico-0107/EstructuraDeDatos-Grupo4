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
    CVector(int delta = 10) { Init(delta); }

    void Insert(int elem) {
        if (m_nCount == m_nMax) {
            Resize();
        }
        m_pVect[m_nCount++] = elem;
    }

    void Display() {
        for (int i = 0; i < m_nCount; i++) {
            cout << m_pVect[i] << " ";
        }
        cout << endl;
    }

    void SelectionSort() {
        for (int i = 0; i < m_nCount - 1; i++) {
            int minIdx = i;
            for (int j = i + 1; j < m_nCount; j++) {
                if (m_pVect[j] < m_pVect[minIdx]) {
                    minIdx = j;
                }
            }
            swap(m_pVect[i], m_pVect[minIdx]);
        }
    }

    int Partition(int low, int high) {
        int pivot = m_pVect[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (m_pVect[j] < pivot) {
                i++;
                swap(m_pVect[i], m_pVect[j]);
            }
        }
        swap(m_pVect[i + 1], m_pVect[high]);
        return i + 1;
    }

    void QuickSort(int low, int high) {
        if (low < high) {
            int pi = Partition(low, high);
            QuickSort(low, pi - 1);
            QuickSort(pi + 1, high);
        }
    }

    void InsertionSort() {
        for (int i = 1; i < m_nCount; i++) {
            int key = m_pVect[i];
            int j = i - 1;
            while (j >= 0 && m_pVect[j] > key) {
                m_pVect[j + 1] = m_pVect[j];
                j--;
            }
            m_pVect[j + 1] = key;
        }
    }

    int GetCount() const { return m_nCount; }

    ~CVector() { delete[] m_pVect; }
};

int main() {
    CVector gVect;
    gVect.Insert(10);
    gVect.Insert(20);
    gVect.Insert(30);
    gVect.Insert(5);
    gVect.Insert(50);
    gVect.Insert(15);

    cout << "Antes de ordenar: ";
    gVect.Display();

    gVect.SelectionSort();
    cout << "Después de Selection Sort: ";
    gVect.Display();

    gVect.Insert(25);
    gVect.Insert(35);

    cout << "Antes de Quick Sort: ";
    gVect.Display();
    gVect.QuickSort(0, gVect.GetCount() - 1);
    cout << "Después de Quick Sort: ";
    gVect.Display();

    gVect.Insert(8);
    gVect.Insert(18);

    cout << "Antes de Insertion Sort: ";
    gVect.Display();
    gVect.InsertionSort();
    cout << "Después de Insertion Sort: ";
    gVect.Display();

    return 0;
}
