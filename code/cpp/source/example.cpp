/* Dodaje flagę wymaganą do kompilacji jako plik .dll dla rodziny systemów Windows*/
#ifdef _WIN32
#define def __declspec(dllexport)
#else
#define def
#endif

#include <iomanip>
#include <string>
#include <cmath>
#include <iostream>

extern "C" {

    def int add(int a, int b) {
        return (a + b);
    }

    def void subtractArrays(int* a, int* b, int size) {
        for(int i = 0; i < size; i++) {
            a[i] -= b[i];
        }
    }

    def float kalkulator(float waga, float wzrost) {
        float wzrostM = wzrost/100;
        return (waga / pow(wzrostM,2));
    }
}




/*


Person opis(Person a)
{
  if(a.plec==true)
  {
    if(a.wiek>=25&&a.wiek<=34)
    {
      if(a.BMI>20)
      {
        a.opis="niedowaga";
      }
      else if(a.BMI>=20&&a.BMI<25)
      {
        a.opis="waga prawidłowa";
      }
      else if(a.BMI>=25&&a.BMI<30)
      {
        a.opis="nadwaga";
      }
      else if(a.BMI>=30&&a.BMI<40)
      {
        a.opis="otyłość";
      }
      else if(a.BMI>=40)
      {
        a.opis="otyłość skrajna";
      }
    }
    else if(a.wiek>=35&&a.wiek<=44)
    {
      if(a.BMI>21)
      {
        a.opis="niedowaga";
      }
      else if(a.BMI>=21&&a.BMI<26)
      {
        a.opis="waga prawidłowa";
      }
      else if(a.BMI>=26&&a.BMI<31)
      {
        a.opis="nadwaga";
      }
      else if(a.BMI>=31&&a.BMI<41)
      {
        a.opis="otyłość";
      }
      else if(a.BMI>=41)
      {
        a.opis="otyłość skrajna";
      }
    }
    else if(a.wiek>=45&&a.wiek<=54)
    {
      if(a.BMI>22)
      {
        a.opis="niedowaga";
      }
      else if(a.BMI>=22&&a.BMI<27)
      {
        a.opis="waga prawidłowa";
      }
      else if(a.BMI>=27&&a.BMI<32)
      {
        a.opis="nadwaga";
      }
      else if(a.BMI>=32&&a.BMI<42)
      {
        a.opis="otyłość";
      }
      else if(a.BMI>=42)
      {
        a.opis="otyłość skrajna";
      }
    }
    else if(a.wiek>=55&&a.wiek<=64)
    {
      if(a.BMI>23)
      {
        a.opis="niedowaga";
      }
      else if(a.BMI>=23&&a.BMI<28)
      {
        a.opis="waga prawidłowa";
      }
      else if(a.BMI>=28&&a.BMI<33)
      {
        a.opis="nadwaga";
      }
      else if(a.BMI>=33&&a.BMI<43)
      {
        a.opis="otyłość";
      }
      else if(a.BMI>=43)
      {
        a.opis="otyłość skrajna";
      }
    }
    else if(a.wiek>=65)
    {
      if(a.BMI>24)
      {
        a.opis="niedowaga";
      }
      else if(a.BMI>=24&&a.BMI<29)
      {
        a.opis="waga prawidłowa";
      }
      else if(a.BMI>=29&&a.BMI<34)
      {
        a.opis="nadwaga";
      }
      else if(a.BMI>=34&&a.BMI<44)
      {
        a.opis="otyłość";
      }
      else if(a.BMI>=44)
      {
        a.opis="otyłość skrajna";
      }
    }
  }
    return a;
}
*/