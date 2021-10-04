#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<stdlib.h>

using namespace std;

long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i,r;
string msg;

int prime(long int);
void ce();
long int cd(long int);
void encrypt();

int main()
{
    p=17;
    q=19;
    r=23;
    cout<<"\nThe Message is as follows : \n";
    ifstream f1;
    string tp;
    f1.open("Input.txt",ios::in);
     while(f1)
        {
         if(f1.eof())
            {
             break;
            }
         getline(f1,tp);
         msg.append(tp);
        }
     cout<<msg;
     f1.close();
     cout<<"\n\n";
    for (i = 0; msg[i] != '\0'; i++)
        m[i] = msg[i];
    n = p * q * 2;
    t = (p - 1) * (q - 1) * (r-1);
    ce();
    encrypt();
    return 0;
}
void ce()
{
    int k;
    k = 0;
    for (i = 2; i < t; i++)
    {
        if (t % i == 0)
            continue;
        flag = prime(i);
        if (flag == 1 && i != p && i != q && i!=r)
        {
            e[k] = i;
            flag = cd(e[k]);
            if (flag > 0)
            {
                d[k] = flag;
                k++;
            }
            if (k == 99)
                break;
        }
    }
}

long int cd(long int x)
{
    long int k = 1;
    while (1)
    {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}
void encrypt()
{
    long int pt, ct, key = e[0], k, len;
    i = 0;
    len = msg.length();
    while (i != len)
    {
        pt = m[i];
        pt = pt - 96;
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    cout << "\nTHE ENCRYPTED MESSAGE IS\n";
    ofstream fcd;
    fcd.open("Encrypted.txt",ios::out);
    ofstream ftmp;
    ftmp.open("Temp.txt",ios::out);
    for (i = 0; en[i] != -1; i++)
        {
         printf("%ld ", en[i]);
         fcd<<en[i];
         fcd<< " ";
         ftmp<<temp[i]<<" ";
        }
    fcd<<"-1";
    fcd.close();
    ftmp.close();
}

int prime(long int pr)
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}
