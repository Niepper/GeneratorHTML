#include <iostream>
/* Dodaje flagę wymaganą do kompilacji jako plik .dll dla rodziny systemów Windows*/
#ifdef _WIN32
#define def __declspec(dllexport)
#else
#define def
#endif


struct osoba{
    std::string imie;
    std::string nazwisko;
    bool plec; //true-kobieta, false-mezczyzna
    int wiek;
    float waga;
    float wzrost;
    float BMI;
    std::string opis;
};



extern "C"
{

    def int add(int a, int b){
        return (a + b);
    }

    def void subtractArrays(int* a, int* b, int size){
        for(int i = 0; i < size; i++){
            a[i] -= b[i];
        }
    }

}




struct osoba{
string imie;
string nazwisko;
bool plec;//true-kobieta, false-mezczyzna
int wiek;
float waga;
float wzrost;
float BMI;
string opis;
};

osoba kalkulator(osoba a)
{
  a.BMI=(a.waga/(a.wzrost*a.wzrost))*10000;
  return a;
}
osoba opis(osoba a)
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
}