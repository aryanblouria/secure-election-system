#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<sys/stat.h>
using namespace std;

int totvt=0,totct=0;

struct voter
{
    string name,vid,aadhar,mob,gender,add,voted_for;
    bool voted;
    int m,d,y;

    string usnm,pswd;
    string retaadhar()
    {
        return aadhar;
    }
    string retvid()
    {
        return vid;
    }
    bool vtchk()
    {
        return voted;
    }
    void vote()
    {
        voted=true;
    }
    void vreset()
    {
        voted=false;
    }
    void getinfo()
    {
        cout<<"\nHello New Voter, \nPlease enter the following data to register yourself as a voter.";
        cout<<"\n\nEnter your Name: ";
        getline(cin,name);
        cout<<"Enter your Gender: ";
        getline(cin,gender);
        cout<<"Enter your Aadhar Number: ";
        getline(cin,aadhar);
        cout<<"Enter your Mobile number: ";
        getline(cin,mob);
        cout<<"\nEnter your date of birth below \n\n";
        cout<<"Enter the date (dd): ";
        cin>>d;
        cout<<"Enter the month (mm): ";
        cin>>m;
        cout<<"Enter the year (yyyy): ";
        cin>>y;
        cout<<"\nEnter your Address: ";
        getline(cin,add);
        getline(cin,add);
        voted=false;
        genvotid();
    }

    void genvotid()
    {
        string tp;
        tp=name.substr(0,3);
        vid.clear();
        vid.append(tp);
        tp.clear();
        tp=aadhar.substr(0,4);
        vid.append(tp);
        cout<<"\nYour Voter ID has been generated.";
        cout<<"\nYour Voter Id is "<<vid<<"\n\n";
        system("PAUSE");
    }

    void showdata()
    {
        cout<<"\n\nName: "<<name;
        cout<<"\nGender: "<<gender;
        cout<<"\nAadhar Number: "<<aadhar;
        cout<<"\nMobile Number: "<<mob;
        cout<<"\nDate of birth: "<<d<<"-"<<m<<"-"<<y;
        cout<<"\nAddress: "<<add;
        cout<<"\nVoter ID: "<<vid<<"\n";
        cout<<"\nUsername: "<<usnm;
        cout<<"\nPassword: "<<pswd<<"\n\n";
        system("PAUSE");
    }

    void addchange()
    {
        cout<<"\nEnter your new Address: ";
        getline(cin,add);
        getline(cin,add);
        cout<<"\nYour new address has been updated successfully.\n\n";
        system("PAUSE");
    }

    void mobchange()
    {
        cout<<"\nEnter your new mobile number: ";
        getline(cin,mob);
        getline(cin,mob);
        cout<<"\nYour new mobile number has been updated successfully.\n\n";
        system("PAUSE");
    }
} vt[50],currvt;

struct candidate
{
    string name,candidate_id,aadhar,mob,gender;
    string add,party_name,party_slogan;
    int m,d,y,votes;
    string retcanid()
    {
        return candidate_id;
    }
    void showvotes()
    {
        cout<<"\nCandidate Name : "<<name<<"\n";
        cout<<"Votes Received : "<<votes<<"\n";
    }
    void voteadd()
    {
        votes++;
    }
    int retvt()
    {
        return votes;
    }
    void vreset()
    {
        votes=0;
    }
    string usnm,pswd;
    string retnm()
    {
        return name;
    }
    void getinfo()
    {
        cout<<"\nWelcome New Candidate, Please fill out the following information to register.\n\n";
        cout<<"Enter your Name: ";
        getline(cin,name);
        cout<<"Enter your Gender: ";
        getline(cin,gender);
        cout<<"Enter your Aadhar Number: ";
        getline(cin,aadhar);
        cout<<"Enter your Mobile number: ";
        getline(cin,mob);
        cout<<"\nEnter your date of birth below\n\n";
        cout<<"Enter the date (dd): ";
        cin>>d;
        cout<<"Enter the month (mm): ";
        cin>>m;
        cout<<"Enter the year (yyyy): ";
        cin>>y;
        cout<<"\nEnter your Address: ";
        getline(cin,add);
        getline(cin,add);
        cout<<"\nEnter the details of the political party you are affiliated with below \n";
        cout<<"\nEnter the Party Name: ";
        getline(cin,party_name);
        cout<<"Enter the Party Slogan: ";
        getline(cin,party_slogan);
        get_candidate_id();
        votes=0;
        cout<<"\n\n";
        system("PAUSE");
    }
    void get_candidate_id()
    {
        candidate_id="C";
        string tp;
        tp=name.substr(0,3);
        candidate_id.clear();
        candidate_id.append(tp);
        tp.clear();
        tp=aadhar.substr(0,4);
        candidate_id.append(tp);
        cout<<"\nYour Candidate ID has been generated.";
        cout<<"\nYour Candidate ID is "<<candidate_id;
    }
    void showdata()
    {
        cout<<"\n\nName: "<<name;
        cout<<"\nGender: "<<gender;
        cout<<"\nAadhar Number: "<<aadhar;
        cout<<"\nMobile Number: "<<mob;
        cout<<"\nDate of birth: "<<d<<"-"<<m<<"-"<<y;
        cout<<"\nAddress: "<<add;
        cout<<"\nCandidate ID: "<<candidate_id;
        cout<<"\nParty Name: "<<party_name;
        cout<<"\nParty Slogan: "<<party_slogan<<"\n\n";
        system("PAUSE");
    }
    void addchange()
    {
        cout<<"\nEnter your new Address: ";
        getline(cin,add);
        getline(cin,add);
        cout<<"\nYour new address has been updated successfully.\n\n";
        system("PAUSE");
    }
    void mobchange()
    {
        cout<<"\nEnter your new Mobile Number: ";
        getline(cin,mob);
        getline(cin,mob);
        cout<<"\nYour new mobile number has been updated successfully.\n\n";
        system("PAUSE");
    }
    string retaadhar()
    {
        return aadhar;
    }
} ct[50],currct;


long int p, q, n, t, flag, e[100], d[100], temp[1000], j, m[1000], en[1000], i,r;
string msg;
int prime(long int);
void ce();
long int cd(long int);
void encrypt();
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

bool issetbit(char ch, int pos)
    {
     ch = ch >> pos;
     if(ch & 1)
       {
        return true;
       }
     return false;
    }

bool isBitSet(char ch, int pos) {
	ch = ch >> pos;
	if(ch & 1)
		return true;
	return false;
}


string enc(vector<int>s, vector<int> t, string p)
{
	int i = 0, j = 0, temp = 0, k = 0, tmp1, tmp2;
	int *encrypt = new int [p.length()];
	string encrypted;
	for (int r = 0; r < p.length(); r++)
    {
		i = (i + 1) % 256;
		j = (j + s[i]) % 256;

		tmp1 = s[i];
		s[i] = s[i+j+1];
		s[i+j+1] = tmp1;

		temp = (s[i] + s[j]) % 256;
		k = s[temp];
		tmp2 = ((int)p[r] ^ k ^ j);

		encrypt[r] = tmp2;
		encrypted += (char)encrypt[r];
	}
	return encrypted;
}

vector<int> permute(vector<int> s, vector<int> t)
{
	int j = 0, temp;
	for (int i = 0; i< 256; i++)
    {
		j = (j + s[i] + t[i]) % 256;
        temp = s[i];
        s[i] = s[j];
		s[j] = temp;
	}
    return s;
}

int rc4modenc()
{
	string data;
	vector<int> S(256);
	vector<int> T(256);
	int key[] = {2,3,4,6};
	for (int i = 0; i < 256; i++)
    {
		S[i] = i;
		T[i] = key[(i%(sizeof(key)/sizeof(*key)))];
	}

    S = permute(S,T);

	ifstream input;
	input.open("C://ELECT//Winner.txt",ios::in);
	getline(input,data);
	input.close();

	string es = enc(S, T, data);

	ofstream enct;
	enct.open("C://ELECT//WinnerEncoded.txt",ios::out);
	enct << es;
	enct.close();
	return 0;
}


string dec(vector<int>s, vector<int> t, string p)
{
	int i = 0, j = 0, k = 0, temp = 0, tmp1, tmp2;
	int *decrypt = new int[p.length()];
	string decrypted;
	for (int r = 0; r < p.length(); r++)
    {
		i = (i + 1) % 256;
		j = (j + s[i]) % 256;

		tmp1 = s[i];
		s[i] = s[i+j+1];
		s[i+j+1] = tmp1;

		temp = (s[i] + s[j]) % 256;
		k = s[temp];

		tmp2 = ((int)p[r] ^ k ^ j);
		decrypt[r] = tmp2;
		decrypted += (char)decrypt[r];
	}
	return decrypted;
}

int rc4modecr()
{
	string es;
	vector<int> S(256);
	vector<int> T(256);
	int key[] = {2,3,4,6};
	for (int i = 0; i < 256; i++)
    {
		S[i] = i;
		T[i] = key[(i%(sizeof(key)/sizeof(*key)))];
	}

    S = permute(S,T);

	ifstream input;
	input.open("C://ELECT//WinnerEncoded.txt",ios::in);
	getline(input,es);
	input.close();

	string ds = dec(S, T, es);

	ofstream dect;
	dect.open("C://ELECT//WinnerDecoded.txt",ios::out);
	dect << ds;
	dect.close();
	return 0;
}


void vregister()
{
    string usn;
    string pwd;

    system("CLS");
    cout << "Create a new account: \n";
    cout << "\nEnter your username: ";
    cin.get();
    getline(cin, usn);

    if(usn.empty())
    {
        cout << "\nYou can't leave the username field empty!\n";
        system("PAUSE");
        vregister();
    }
    else if (usn.length() < 3)
    {
        cout << "\nUsername should be more than 3 characters\n";
        system("PAUSE");
        vregister();
    }
    else
    {
        currvt.usnm=usn;
        cout << "Enter password: ";
        getline(cin, pwd);

        bool hasLower = false, hasUpper = false, hasDigit = false;
        for (int i = 0; i < pwd.length(); i++)
        {
            if (islower(pwd[i]))
                hasLower = true;
            if (isupper(pwd[i]))
                hasUpper = true;
            if (isdigit(pwd[i]))
                hasDigit = true;
        }

        if (pwd.empty())
        {
            cout << "\nYour password can't be left empty.\n";
            system("PAUSE");
            vregister();
        }
        else if (pwd.length() < 8)
        {
            cout << "\nYour password can't be less than 8 characters.\n";
            system("PAUSE");
            vregister();
        }
        else if (!hasLower || !hasUpper || !hasDigit)
        {
            cout << "\nCheck if your password contains at least one lowercase letter, one uppercase letter and one digit.\n";
            system("PAUSE");
            vregister();
        }
        else
        {
            currvt.pswd=pwd;
            currvt.getinfo();
            vt[totvt]=currvt;
            totvt++;
            system("CLS");
        }
    }
}


void voter_func();

void vlogin()
{
    string username;
    string password;
    string output;

    system("CLS");
    cout << "Login to your account: \n";
    cout << "\nUsername: ";
    cin.get();
    getline(cin, username);

    if (username.empty())
    {
        cout << "\nYou can't leave the username field empty!\n";
        system("PAUSE");
        vlogin();
    }
    else
    {
        bool flag=false;
        for(int i=0; i<totvt; i++)
        {
            currvt=vt[i];
            if(username==currvt.usnm)
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            cout<<"Password: ";
            getline(cin,password);
            if(password==currvt.pswd)
            {
                cout << "\nLogin successful.\n";
                system("PAUSE");
            }
            else
            {
                cout << "\nIncorrect password.\n";
                do
                {
                    cout<<"Please re-enter your Password :";
                    cin.get();
                    getline(cin,password);
                }
                while(password!=currvt.pswd);
            }
        }
        else
        {
            cout << "\nUsername does not exist.\n";
            system("PAUSE");
            voter_func();
        }
    }
}

void vupdate();

void cupdate();

void elect()
{
    candidate tmp;
    if(currvt.vtchk())
    {
        cout<<"You have already voted.\nYou will be returned to the main screen.\n\n";
        system("PAUSE");
        return;
    }

    system("CLS");
    char ans;
    bool vtd=false;
    cout<<"Select which Candidate to vote for: \n";
    for(int i=0; i<totct; i++)
    {
        if(!vtd)
        {
            cout<<"\nCandidate #"<<i+1;
            cout<<"\n-----------";
            ct[i].showdata();
            cout<<"\nDo you want to vote for this Candidate? (Please type Y or N): ";
            cin>>ans;
            if(ans=='y'||ans=='Y')
            {
                ct[i].voteadd();
                currvt.vote();
                currct=ct[i];
                cout<<"\nYou have successfully voted for this candidate.\n";
                system("PAUSE");
                vtd=true;
                vupdate();
                cupdate();
            }
        }
    }
    return;
}

void vupdate()
{
    for(int i=0; i<totvt; i++)
    {
        if(vt[i].retvid()==currvt.retvid())
        {
            vt[i]=currvt;
            break;
        }
    }
}

void voter_func()
{
    int opt;

selopt:
    ;
    system("CLS");
    cout << "Choose the action you want to perform: \n";
    cout << "1. Register a new account\n2. Login to existing account\n3. Exit program\n\n";
    cout << "-> ";

    cin >> opt;
    switch(opt)
    {
    case 1:
        vregister();
        break;
    case 2:
        vlogin();
        break;
    case 3:
        cout<<"\nThank you for using our election system! We hope to see you again!\n";
        return;
    default:
        cout<<"\nPlease choose a valid option.\n";
        goto selopt;
    }
    system("CLS");
    int ch;
voteraction:
    ;
    system("CLS");
    cout<<"Voter Menu\n";
    cout<<"----------\n";
    cout<<"\n1. View your data";
    cout<<"\n2. Change your address";
    cout<<"\n3. Update your mobile number";
    cout<<"\n4. Go to election screen";
    cout<<"\n5. Logout";
    cout<<"\n\nEnter your choice: ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        currvt.showdata();
        goto voteraction;
        break;
    case 2:
        currvt.addchange();
        goto voteraction;
        break;
    case 3:
        currvt.mobchange();
        goto voteraction;
        break;
    case 4:
        elect();
        break;
    case 5:
        vupdate();
        return;
    default:
        cout<<"Invalid Choice Entered.";
        system("PAUSE");
        goto voteraction;
    }
}

void cregister()
{
    string usn;
    string pwd;

    system("CLS");
    cout << "Create a new account: \n";
    cout << "\nEnter your username: ";
    getline(cin, usn);
    getline(cin, usn);

    if(usn.empty())
    {
        cout << "\nYou can't leave the username field empty!\n";
        system("PAUSE");
        cregister();
    }
    else if (usn.length() < 3)
    {
        cout << "\nUsername should be more than 3 characters\n";
        system("PAUSE");
        cregister();
    }
    else
    {
        currct.usnm=usn;
        cout << "Enter password: ";
        getline(cin, pwd);

        bool hasLower = false, hasUpper = false, hasDigit = false;
        for (int i = 0; i < pwd.length(); i++)
        {
            if (islower(pwd[i]))
                hasLower = true;
            if (isupper(pwd[i]))
                hasUpper = true;
            if (isdigit(pwd[i]))
                hasDigit = true;
        }

        if (pwd.empty())
        {
            cout << "\nYour password can't be left empty.\n";
            system("PAUSE");
            cregister();
        }
        else if (pwd.length() < 8)
        {
            cout << "\nYour password can't be less than 8 characters.\n";
            system("PAUSE");
            cregister();
        }
        else if (!hasLower || !hasUpper || !hasDigit)
        {
            cout << "\nCheck if your password contains at least one lowercase letter, one uppercase letter and one digit.\n";
            system("PAUSE");
            cregister();
        }
        else
        {
            currct.pswd=pwd;
            currct.getinfo();
            ct[totct]=currct;
            totct++;
            system("CLS");
        }
    }
}

void candidate_func();

void clogin()
{
    string username;
    string password;
    string output;

    system("CLS");
    cout << "Login to your account: \n";
    cout << "\nUsername: ";
    cin.get();
    getline(cin, username);

    if (username.empty())
    {
        cout << "\nYou can't leave the username field empty!\n";
        system("PAUSE");
        clogin();
    }
    else
    {
        bool flag=false;
        for(int i=0; i<totct; i++)
        {
            currct=ct[i];
            if(username==currct.usnm)
            {
                flag=true;
                break;
            }
        }
        if(flag)
        {
            cout<<"Password: ";
            getline(cin,password);
            if(password==currct.pswd)
            {
                cout << "\nLogin successful.\n";
                system("PAUSE");
            }
            else
            {
                cout << "\nIncorrect password.\n";
                do
                {
                    cout<<"Please re-enter your Password: ";
                    //cin.get();
                    getline(cin,password);
                }
                while(password!=currct.pswd);
            }
        }
        else
        {
            cout << "\nUsername does not exist.\n";
            system("PAUSE");
            candidate_func();
        }
    }
}

void cupdate()
{
    for(int i=0; i<totct; i++)
    {
        if(ct[i].retcanid()==currct.retcanid())
        {
            ct[i]=currct;
            break;
        }
    }
}

void candidate_func()
{
    int opt;
    candidate tmp;
    ifstream f5;
selopt:
    ;
    system("CLS");
    cout << "Choose the action you want to perform: \n";
    cout << "1. Register a new account\n2. Login to existing account\n3. Exit program\n\n";
    cout << "-> ";

    cin >> opt;
    switch(opt)
    {
    case 1:
        cregister();
        break;
    case 2:
        clogin();
        break;
    case 3:
        cout<<"\nThank you for using our election system! We hope to see you again!\n";
        return;
    default:
        cout<<"\nPlease choose a valid option.\n";
        goto selopt;
    }
    system("CLS");
    int ch;
candidateaction:
    ;
    system("CLS");
    cout<<"Candidate Menu\n";
    cout<<"--------------\n";
    cout<<"\n1. View your data";
    cout<<"\n2. Change your address";
    cout<<"\n3. Update your mobile number";
    cout<<"\n4. Logout";
    cout<<"\n\nEnter your choice: ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        currct.showdata();
        goto candidateaction;
        break;
    case 2:
        currct.addchange();
        goto candidateaction;
        break;
    case 3:
        currct.mobchange();
        goto candidateaction;
        break;
    case 4:
        cupdate();
        return;
    default:
        cout<<"Invalid Choice Entered.";
        goto candidateaction;
    }
}


int encrypt_main()
{
    p=17;
    q=19;
    r=23;
    ifstream f1;
    string tp;
    f1.open("C://ELECT//CandidateList.txt",ios::in);
     while(f1)
        {
         if(f1.eof())
            {
             break;
            }
         getline(f1,tp);
         msg.append(tp);
        }
     f1.close();
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
    ofstream fcd;
    fcd.open("C://ELECT//CandidateListEncoded.txt",ios::out);
    ofstream ftmp;
    ftmp.open("C://ELECT//Temp.txt",ios::out);
    for (i = 0; en[i] != -1; i++)
        {
         if (en[i] == -283)
            fcd<<"\n";
         else
         {
            fcd<<en[i];
            fcd<<" ";
         }
         ftmp<<temp[i]<<" ";
        }
    fcd<<"-1";
    fcd.close();
    ftmp.close();
}

int dcrypt_main()
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


void decrypt()
{
    string st,st1;
    ifstream fcdc,ftmp;
    i=0;
    fcdc.open("C://ELECT//CandidateListDecoded.txt",ios::in);
    ftmp.open("C://ELECT//Temp.txt",ios::in);
    while(fcdc)
    {
        if(fcdc.eof())
        {
            break;
        }
        fcdc>>st;
        ftmp>>st1;
        en[i]=stol(st);
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
    ofstream fcddc;
    fcddc.open("C://ELECT//CandidateListDecoded.txt",ios::out);
    for (i = 0; m[i] != -1; i++)
    {
        if ((char)m[i] == ';')
            fcddc<<"\n";
        else
            fcddc<<(char)m[i];
    }

    fcddc.close();
}

void admin_func()
{
    system("CLS");
    string usid,pass;
    cout<<"Enter administrator username: ";
    cin.get();
    getline(cin,usid);
    if(usid=="@dm!n")
    {
reenter:
        ;
        cout<<"Enter administrator password: ";
        getline(cin,pass);
        if(pass!="passw0rd")
        {
            cout<<"Wrong Password entered.\nPlease re-enter the correct password.";
            goto reenter;
        }
    }
    else
    {
        return;
    }
    int ch;
    long int max_vote=INT_MIN;
    candidate tp;
redo:
    ;
    system("CLS");
    cout<<"Hello Admin!";
    cout<<"\n\n1. Display votes received by each candidate and winning candidate";
    cout<<"\n2. Reset the votes";
    cout<<"\n3. Decrypt the Candidates List File";
    cout<<"\n4. Decrypt the Winning Candidate Data File";
    cout<<"\n5. Logout";
    cout<<"\n\nEnter your choice: ";
    cin>>ch;
    ofstream f1;
    switch(ch)
    {
    case 1:
        cout << "\nVotes Per Candidate";
        cout << "\n-------------------\n";
        for(int i=0; i<totct; i++)
        {
            ct[i].showvotes();
            if(ct[i].retvt()>max_vote)
            {
                max_vote=ct[i].retvt();
                tp=ct[i];
            }
        }
        cout<<"\nWinning Candidate";
        cout<<"\n-----------------";
        tp.showdata();
        f1.open("C://ELECT//Winner.txt",ios::out);
        f1<<"Winning candidate: "<<tp.name<<" - "<<to_string(tp.votes)<<" votes.";
        f1.close();
        encrypt_main();
        rc4modenc();
        goto redo;
    case 2:
        for(int i=0; i<totct; i++)
        {
            ct[i].vreset();
        }
        for(int i=0; i<totvt; i++)
        {
            vt[i].vreset();
        }
        vupdate();
        cupdate();
        cout<<"\nThe voting status has been reset successfully.\n\n";
        system("PAUSE");
        goto redo;
    case 3:
        dcrypt_main();
        cout<<"\nFile decrypted.";
        getch();
        goto redo;
    case 4:
        rc4modecr();
        cout<<"\nFile decrypted.";
        getch();
        goto redo;
    case 5:
        return;
    default:
        cout<<"Invalid Choice";
        system("CLS");
        goto redo;
    }
}


void getdata()
{
    ifstream fvt,fct;
    fvt.open("C://ELECT//VoterData.txt",ios::in);
    totct=totvt=0;
    if(!fvt)
    {
        totvt=0;
    }
    else
    {
        while(fvt)
        {
            if(fvt.eof())
            {
                break;
            }
            fvt.read((char*)&vt[totvt],sizeof(vt[totvt]));
            totvt++;
        }
        fvt.close();
    }
    fct.open("C://ELECT//CandidateData.txt",ios::in);
    if(!fct)
    {
        totct=0;
    }
    else
    {
        while(fct)
        {
            if(fct.eof())
            {
                break;
            }
            fct.read((char*)&ct[totct],sizeof(ct[totct]));
            totct++;
        }
        fct.close();
    }
}

void storedata()
{
    if(totvt!=0)
    {
        ofstream fv;
        fv.open("C://ELECT//VoterData.txt",ios::out);
        for(int i=0; i<totvt; i++)
        {
            fv.write((char*)&vt[i],sizeof(vt[i]));
        }
        fv.close();
    }
    if(totct!=0)
    {
        ofstream fc;
        fc.open("C://ELECT//CandidateData.txt",ios::out);
        for(int i=0; i<totct; i++)
        {
            fc.write((char*)&ct[i],sizeof(ct[i]));
        }
        fc.close();
    }
}

void savefile()
    {
     ofstream fvt,fct;
     fvt.open("C://ELECT//VoterList.txt",ios::out);
     if(totvt!=0)
     {
        for(int i=0;i<totvt;i++)
        {
            fvt<<"Name: "<<vt[i].name<<"\n";
            fvt<<"Voter ID: "<<vt[i].vid<<"\n";
            fvt<<"Aadhar Number: "<<vt[i].aadhar<<"\n";
            fvt<<"Gender: "<<vt[i].gender<<"\n";
            fvt<<"Mobile Number: "<<vt[i].mob<<"\n";
            fvt<<"Date Of Birth: "<<vt[i].d<<"-"<<vt[i].m<<"-"<<vt[i].y<<"\n";
        }
     }
     fvt.close();
     fct.open("C://ELECT//CandidateList.txt",ios::out);
     if(totct!=0)
       {
        for(int i=0;i<totct;i++)
           {
            fct<<"Name: "<<ct[i].name<<";\n";
            fct<<"Candidate ID: "<<ct[i].candidate_id<<";\n";
            fct<<"Aadhar Number: "<<ct[i].aadhar<<";\n";
            fct<<"Gender: "<<ct[i].gender<<";\n";
            fct<<"Mobile Number: "<<ct[i].mob<<";\n";
            fct<<"Date Of Birth: "<<ct[i].d<<" - "<<ct[i].m<<" - "<<ct[i].y<<";\n";
            fct<<"Party: "<<ct[i].party_name<<";\n";
            fct<<"Party Slogan: "<<ct[i].party_slogan<<";;\n";
           }
       }
     fct.close();
    }

int main()
{
    system("Color 0A");
    cout << "Welcome to India 2021 Election System!\n";
    system("PAUSE");
    getdata();
    system("CLS");
    if(totct!=0)
        totct--;
    if(totvt!=0)
        totvt--;

Choose:

    system("CLS");
    int logop;
    cout << "Login Menu\n";
    cout << "----------\n";
    cout << "\nChoose the login option: \n\n";
    cout << "1. Voter Login\n2. Candidate Login\n3. Admin Login\n4. Exit\n\n";
    cout << "-> ";
    cin >> logop;
    switch(logop)
    {
    case 1:
        voter_func();
        break;
    case 2:
        candidate_func();
        break;
    case 3:
        admin_func();
        break;
    case 4:
        storedata();
        savefile();
        return 0;
    default:
        cout<<"Invalid Choice";
        system("PAUSE");
        goto Choose;
    }
    goto Choose;
} 
