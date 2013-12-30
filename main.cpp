#include <cstdlib>
#include <iostream>
#include <time.h>
#include <unistd.h>

using namespace std;

void rysuj( int tab[], int size )
{
  for( int i = 0; i < size; i++ )
  {
    cout<<tab[i]<<" ";
  }
  cout<<endl;
}

void Bombelkowe( int tab[], int size )
{
    for( int i = 0; i < size; i++ )
    {
        for( int j = 0; j < size - 1; j++ )
        {
            if( tab[ j ] > tab[ j + 1 ] )
                 swap( tab[ j ], tab[ j + 1 ] );
        }
    }
}

void Grzebieniowe( int tab[], int size )
{
    int gap = size;
    bool replace = true;

    while( gap > 1 || replace )
    {
        gap = gap * 10 / 13;
        if( gap == 0 )
             gap = 1;

        replace = false;
        for( int i = 0; i + gap < size; i++ )
        {
            if( tab[ i + gap ] < tab[ i ] )
            {
                swap( tab[ i ], tab[ i + gap ] );
                replace = true;
            }
        }
    }
}

void Koktailowe( int tab[], int size )
{
    int bottom = 0, top = size - 1;
    bool replace = true;

    while( replace )
    {
        replace = false;

        for( int i = bottom; i < top; i++ )
        {
            if( tab[ i ] > tab[ i + 1 ] )
            {
                swap( tab[ i ], tab[ i + 1 ] );

                replace = true;
            }
        }

        top--;
        for( int i = top; i > bottom; i-- )
        {
            if( tab[ i ] < tab[ i - 1 ] )
            {
                swap( tab[ i ], tab[ i - 1 ] );

                replace = true;
            }
        }

        bottom++;
    }
}

void PrzezWstawianie( int tab[], int size )
{
    int temp, j;

    for( int i = 1; i < size; i++ )
    {
        temp = tab[ i ];

        for( j = i - 1; j >= 0 && tab[ j ] > temp; j-- )
             tab[ j + 1 ] = tab[ j ];

        tab[ j + 1 ] = temp;
    }
}

void PrzezWybieranie( int tab[], int size )
{
    int k;
    for( int i = 0; i < size; i++ )
    {
        k = i;
        for( int j = i + 1; j < size; j++ )
        if( tab[ j ] < tab[ k ] )
             k = j;

        swap( tab[ k ], tab[ i ] );
    }
}

void Sybkie( int tab[], int left, int right )
{
    int i = left;
    int j = right;
    int x = tab[( left + right ) / 2 ];
    do
    {
        while( tab[ i ] < x )
             i++;

        while( tab[ j ] > x )
             j--;

        if( i <= j )
        {
            swap( tab[ i ], tab[ j ] );

            i++;
            j--;
        }
    } while( i <= j );

    if( left < j ) Sybkie( tab, left, j );

    if( right > i ) Sybkie( tab, i, right );

}
int main()
{
  srand( time( NULL));
  int zakres;
  int poczatek;
  int t;
  int a;

  cout<<"zakres liczb losowych:\n"
      <<"od: "; cin>>poczatek;
  cout<<"do: "; cin>>zakres;
  zakres-=poczatek;
  cout<<"ilosc liczb do posortowania: "; cin>>t;
  cout<<"1.Sortowanie Bombelkowe\n"
      <<"2.Sortowanie Grzebieniowe\n"
      <<"3.Sortowanie Koktailowe\n"
      <<"4.Sortowanie Przez Wstawianie\n"
      <<"5.Sortowanie Przez Wybieranie\n"
      <<"6.Sortowanie Sybkie\n"
      <<"---------Dane do posortowania---------\n";
  int tablica[t];
  for(int i=0;i<t;i++)
  {
    tablica[i] = ( rand() % zakres) + poczatek;
  }
  rysuj(tablica,t);

  cin>>a;
  switch(a)
  {
    case 1:
    {
      time_t begin;
      time_t end;
      begin = clock();
      Bombelkowe(tablica,t);
      end = clock();
      rysuj(tablica,t);
      cout<<((end-begin)*1000/CLK_TCK);
      break;
    }

    case 2:
      Grzebieniowe(tablica,t);
      rysuj(tablica,t);
      break;

    case 3:
      Koktailowe(tablica,t);
      rysuj(tablica,t);
      break;

    case 4:
      PrzezWstawianie(tablica,t);
      rysuj(tablica,t);
      break;

    case 5:
      PrzezWybieranie(tablica,t);
      rysuj(tablica,t);
      break;

    case 6:
      Sybkie(tablica, t-t, t-1);
      rysuj(tablica,t);
      break;
  }
  return 0;
}
