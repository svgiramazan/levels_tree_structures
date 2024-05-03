#include <iostream>
using namespace std;

struct Dugum {
    int veri;
    struct Dugum* sol;
    struct Dugum* sag;
    Dugum(int veri)
    {
        this->veri = veri;
        sol = sag = NULL;
    }
};

int duzeyiBul(Dugum* kok, int hedef, int duzey) {
    if (kok == nullptr) {
        return -1;
    }
    if (kok->veri == hedef) {
        return duzey;
    }
    int solDuzey = duzeyiBul(kok->sol, hedef, duzey + 1);
    int sagDuzey = duzeyiBul(kok->sag, hedef, duzey + 1);


    if (solDuzey != -1) {
        return solDuzey;
    }
    else {

        return sagDuzey;
    }
}

int main() {

    Dugum* kok = new Dugum(4);
    kok->sol = new Dugum(9);
    kok->sag = new Dugum(7);
    kok->sol->sol = new Dugum(2);
    kok->sol->sol->sol = new Dugum(3);
    kok->sag->sol = new Dugum(6);
    kok->sag->sag = new Dugum(8);
    kok->sag->sag->sol = new Dugum(10);
    kok->sag->sag->sol->sol = new Dugum(5);
    kok->sag->sag->sag = new Dugum(1);


    int hedef;
    std::cout << "aranan deger: ";
    cin >> hedef;

    // Düzeyi bulan fonksiyon çağrılıyor
    int duzey = duzeyiBul(kok, hedef, 1);


    if (duzey != -1) {
        std::cout << "bulundugu duzey: " << duzey << std::endl;
    }
    else {
        std::cout << "Numara Yok" << std::endl;
    }


    delete kok->sag->sag->sol->sol;
    delete kok->sag->sag->sol;
    delete kok->sag->sag->sag;
    delete kok->sag->sol;
    delete kok->sag->sag;
    delete kok->sag;
    delete kok->sol->sol->sol;
    delete kok->sol->sol;
    delete kok->sol;
    delete kok;

    return 0;
}