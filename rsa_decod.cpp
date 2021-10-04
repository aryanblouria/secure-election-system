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
void decrypt();
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
int main()
{
    p=17;
    q=19;
    r=23;
    n = p * q * 2;
    t = (p - 1) * (q - 1) * (r-1);
    ce();
    decrypt();
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
void decrypt()
{
    string st,st1;
    ifstream fcdc,ftmp;
    i=0;
    fcdc.open("C://ISA//ElectionWinCoded.txt",ios::in);
    ftmp.open("C://ISA//tmp.txt",ios::in);
    cout<<"\n\nThe Encrypted File Contains\n\n";
    while(fcdc)
    {
        if(fcdc.eof())
        {
            break;
        }
        fcdc>>st;
        ftmp>>st1;
//        cout<<stol(st)<<" ";
        en[i]=stol(st);
        cout<<en[i]<<" ";
        if(en[i]!=-1)
          {
           temp[i]=stol(st1);
          }
     i++;
    }
    fcdc.close();
    ftmp.close();
    long int pt, ct, key = d[0], k;
    i = 0;
    while (en[i] != -1)
    {
        ct = temp[i];
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * ct;
            k = k % n;
        }
        pt = k + 96;
        m[i] = pt;
        i++;
    }
    m[i] = -1;
    ofstream fdcd;
    fdcd.open("C://ISA//ElectionWinDecoded.txt",ios::out);
    cout << "\nTHE DECRYPTED MESSAGE IS\n";
    for (i = 0; m[i] != -1; i++)
    {
        printf("%c", m[i]);
        fdcd<<(char)m[i];
    }
    fdcd.close();
    cout<<"\n\n";
}
