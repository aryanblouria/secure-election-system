
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    cout << "\nTHE ENCRYPTED MESSAGE IS\n";
    ofstream fcd;
    fcd.open("D://ElectionWinCoded.txt",ios::out);
    ofstream ftmp;
    ftmp.open("D://tmp.txt",ios::out);
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