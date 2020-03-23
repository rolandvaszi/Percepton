#include <iostream>

using namespace std;

void tanitPercepton(int x[4][2], int d[4], int n) {
    //Tanulás mértéke
    int lr = 1;
    //Súlyzok és a bias
    int w1 = 0, w2 = 0, b = 0;
    //Összegzés és kimenet
    int sum, y;
    //Számláló a ciklusból való kilépéshez és súlyzó mértéke
    int db = 0, ei;
    while(true) {
        for(int i=0; i < n; ++i) {
            //Szumma számítás
            sum = x[i][0] * w1 + x[i][1] * w2 + b;
            //Kimenet meghatározása aktiválo függvénnyel
            (sum >= 0) ? y = 1 : y = 0;
            //Súlyzó mértékének kiszámolása
            ei = (d[i] - y);
            //Ha a kapott kimenet egyezik a várt kimenettömb adott pozición levő 
            //elemével, akkor növeljük a számlálót, különben 
            //a bias és a súlyzók új értéket kapnak
            if(d[i] == y) {
                db++;
            }
            else {
                w1 = w1 + lr * ei * x[i][0];
                w2 = w2 + lr * ei * x[i][1];
                b = b + ei;
            }
            //Kapott értékek kiíratása: két bemenet, bias, összegzés és kimenet
            cout << x[i][0] << " " << x[i][1] << " " << b << " " << sum << " " << y << endl; 
        }
        cout << endl;
        //Ha a számláló mértéke egyenlő 4, akkor a várt kimenetet megkapta a
        //percepton és kilép a ciklusból, ha nem, akkor lenullázzuk
        if(db == 4){
            break;
        }
        else {
            db = 0;
        }
    }
}

int main(int argc, char *argv[]) {
    //Bemenetek tömbje: x1, x2
    int x[4][2] = {{0,0}, {0,1}, {1,0}, {1,1}};
    //Várt kimenet AND esetében
    int d[4] = {0, 0, 0, 1};
    //Méret meghatározása
    int n = sizeof(d) / sizeof(d[0]);
    tanitPercepton(x, d, n);
    return 0;
}