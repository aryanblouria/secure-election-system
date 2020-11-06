#include<bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <sys/stat.h>
#include<opencv.hpp>
#include<highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>


using namespace cv;

using namespace std;

int totvt=0,totct=0;

struct voter
{
    string name,vid,aadhar,mob,gender,add,street,city,state,voted_for;
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
        cout<<"Hello New Voter, \nPlease enter the following data to register yourself as a voter.";
        cout<<"\n\nEnter your Name : ";
        getline(cin,name);
        cout<<"Enter your Gender : ";
        getline(cin,gender);
        cout<<"Enter your Aadhar Number : ";
        getline(cin,aadhar);
        cout<<"Enter your Mobile number : ";
        getline(cin,mob);
        cout<<"\nEnter date of birth below \n\n";
        cout<<"Enter the date (dd) : ";
        cin>>d;
        cout<<"Enter the month (mm) : ";
        cin>>m;
        cout<<"Enter the year (yyyy): ";
        cin>>y;
        cout<<"\nEnter your address below  ";
        cout<<"\n\nEnter the House Address :";
        getline(cin,add);
        getline(cin,add);
        cout<<"Enter the Street Name : ";
        getline(cin,street);
        cout<<"Enter the City Name : ";
        getline(cin,city);
        cout<<"Enter the State : ";
        getline(cin,state);
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
        cout<<"\n\nYour Voter ID has been generated.";
        cout<<"\n\nYour Voter Id is "<<vid;
        cout<<"\n\nPlease do not share your Voter Id with anyone else.\n\n";
        system("PAUSE");
    }

    void showdata()
    {
        cout<<"\n\nName : "<<name;
        cout<<"\nGender : "<<gender;
        cout<<"\nAadhar Number : "<<aadhar;
        cout<<"\nMobile Number : "<<mob;
        cout<<"\nDate of birth : "<<d<<" - "<<m<<" - "<<y;
        cout<<"\nAddress : "<<add<<", "<<street<<", "<<city<<", "<<state;
        cout<<"\nVoter ID : "<<vid<<"\n\n";
        cout<<"\nUsername :"<<usnm;
        cout<<"\nPassword: "<<pswd<<"\n\n";
//         cout<<"\n\nPress Any Key to Move Back to the Main Screen.";
        system("PAUSE");
    }

    void addchange()
    {
        cout<<"\n\nEnter your new address below \n\n";
        cout<<"Enter the House Address :";
        getline(cin,add);
        getline(cin,add);
        cout<<"Enter the Street Name : ";
        getline(cin,street);
        cout<<"Enter the City Name : ";
        getline(cin,city);
        cout<<"Enter the State : ";
        getline(cin,state);
        cout<<"\n\nYour new address has been successfully updated.\n\n";
//         cout<<"\n\nPress Any Key to Move Back to the Main Screen.";
        system("PAUSE");
    }

    void mobchange()
    {
        cout<<"\n\nEnter your new mobile number : ";
        getline(cin,mob);
        getline(cin,mob);
        cout<<"\n\nYour new mobile number has been updates successfully.\n\n";
//         cout<<"\n\nPress Any Key to Move Back to the Main Screen.";
        system("PAUSE");
    }
} vt[50],currvt;

struct candidate
{
    string name,candidate_id,aadhar,mob,gender;
    string add,street,city,state,party_name,party_slogan;
    int m,d,y,votes;
    string retcanid()
    {
        return candidate_id;
    }
    void showvotes()
    {
        cout<<"\n\nCandidate Name : "<<name<<"\n";
        cout<<"Votes Received : "<<votes<<"\n\n";
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
        cout<<"Welcome New Candidate, Please fill out the following information to register.\n\n";
        cout<<"Enter your Name : ";
        getline(cin,name);
        cout<<"Enter your Gender : ";
        getline(cin,gender);
        cout<<"Enter your Aadhar Number : ";
        getline(cin,aadhar);
        cout<<"Enter your Mobile number : ";
        getline(cin,mob);
        cout<<"\nEnter date of birth below\n\n";
        cout<<"Enter the date (dd) : ";
        cin>>d;
        cout<<"Enter the month (mm) : ";
        cin>>m;
        cout<<"Enter the year (yyyy): ";
        cin>>y;
        cout<<"\n\nEnter your address below\n\n";
        cout<<"Enter the house address :";
        getline(cin,add);
        getline(cin,add);
        cout<<"Enter the street name : ";
        getline(cin,street);
        cout<<"Enter the city name : ";
        getline(cin,city);
        cout<<"Enter the state : ";
        getline(cin,state);
        cout<<"\n\nEnter the details of the political party you are affiliated with below \n";
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
        cout<<"\n\nYour Candidate ID has been generated.";
        cout<<"\n\nYour Candidate Id is "<<candidate_id;
    }
    void showdata()
    {
        cout<<"\n\nYour data has been stored as follows :";
        cout<<"\n\nPersonal Data";
        cout<<"\n\nName : "<<name;
        cout<<"\nGender : "<<gender;
        cout<<"\nAadhar Number : "<<aadhar;
        cout<<"\nMobile Number : "<<mob;
        cout<<"\nDate of birth : "<<d<<" - "<<m<<" - "<<y;
        cout<<"\nAddress : "<<add<<", "<<street<<", "<<city<<", "<<state;
        cout<<"\n\n";
        cout<<"\nCandidate ID : "<<candidate_id;
        cout<<"\n\nParty Data\n\n";
        cout<<"\nParty Name : "<<party_name;
        cout<<"\nParty Slogan : "<<party_slogan;
        cout<<"\n\nPlease do not share your Candidate Id with anyone else.\n\n";
        system("PAUSE");
    }
    void addchange()
    {
        cout<<"\n\nEnter your new address below : \n\n";
        cout<<"Enter the house address :";
        getline(cin,add);
        getline(cin,add);
        cout<<"Enter the street name : ";
        getline(cin,street);
        cout<<"Enter the city name : ";
        getline(cin,city);
        cout<<"Enter the state : ";
        getline(cin,state);
        cout<<"\n\nYour new address has been successfully updated.\n\n";
        system("PAUSE");
    }
    void mobchange()
    {
        cout<<"\n\nEnter your new Mobile Number : ";
        getline(cin,mob);
        getline(cin,mob);
        cout<<"\nYour new mobile number has been updates successfully.\n\n";
        system("PAUSE");
    }
    string retaadhar()
    {
        return aadhar;
    }
} ct[50],currct;

long int p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i,r;
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

int lsbencvoter()
    {
     string ipim,iptxt,opim;
     ipim = "D:/insta.png";
     iptxt = "D:/VtData.txt";
     opim = "D:/insvot.png";
       ifstream file(iptxt);
	   if(!file.is_open()) {
		cout << "File Error\n";
		exit(-1);
	    }
     Mat image = imread(ipim);
     if(image.empty())
        {
         cout<<"Image Error\n";
         exit(-1);
        }
     char ch;
     file.get(ch);
     int bit_count = 0;
     bool last_null_char = false;
     bool encoded = false;

     for(int row = 0; row < image.rows;row++)
        {
         for(int col = 0;col < image.cols;col++)
            {
             for(int clr = 0;clr < 3;clr++)
                {

                 Vec3b pixel = image.at<Vec3b>(Point(row,col));

                 if(issetbit(ch,7-bit_count))
                    pixel.val[clr] |= 1;
                 else
                    pixel.val[clr] &= ~1;

                 image.at<Vec3b>(Point(row,col)) = pixel;
                 bit_count++;

                 if(last_null_char && bit_count == 8)
                   {
                    encoded = true;
                    goto OUTv;
                   }

                 if(bit_count == 8)
                   {
                    bit_count = 0;
                    file.get(ch);

                    if(file.eof())
                      {
                       last_null_char = true;
                       ch='\0';
                      }
                   }
                }
            }
        }

     OUTv: ;

     if(!encoded)
       {
        cout<<"Message is too big. try a larger image.";
        exit(-1);
       }

       imwrite(opim,image);
       return 0;
    }

int lsbenccandidate()
    {
     string ipim,iptxt,opim;
     ipim = "D:/insta.png";
     iptxt = "D:/CtData.txt";
     opim = "D:/inscan.png";
       ifstream file(iptxt);
	   if(!file.is_open()) {
		cout << "File Error\n";
		exit(-1);
	    }
     Mat image = imread(ipim);
     if(image.empty())
        {
         cout<<"Image Error\n";
         exit(-1);
        }
     char ch;
     file.get(ch);
     int bit_count = 0;
     bool last_null_char = false;
     bool encoded = false;

     for(int row = 0; row < image.rows;row++)
        {
         for(int col = 0;col < image.cols;col++)
            {
             for(int clr = 0;clr < 3;clr++)
                {

                 Vec3b pixel = image.at<Vec3b>(Point(row,col));

                 if(issetbit(ch,7-bit_count))
                    pixel.val[clr] |= 1;
                 else
                    pixel.val[clr] &= ~1;

                 image.at<Vec3b>(Point(row,col)) = pixel;
                 bit_count++;

                 if(last_null_char && bit_count == 8)
                   {
                    encoded = true;
                    goto OUTc;
                   }

                 if(bit_count == 8)
                   {
                    bit_count = 0;
                    file.get(ch);

                    if(file.eof())
                      {
                       last_null_char = true;
                       ch='\0';
                      }
                   }
                }
            }
        }

     OUTc:;

     if(!encoded)
       {
        cout<<"Message is too big. try a larger image.";
        exit(-1);
       }

       imwrite(opim,image);
       return 0;
    }


bool isBitSet(char ch, int pos) {
	ch = ch >> pos;
	if(ch & 1)
		return true;
	return false;
}

int lsbdecvot() {

   string ipim;
	ipim = "D:/insvot.png";
	Mat image = imread(ipim);
	if(image.empty()) {
		cout << "Image Error\n";
		exit(-1);
	}


    ofstream f1;
    f1.open("D://VTDecoded.txt",ios::out);
	char ch=0;
	int bit_count = 0;
	for(int row=0; row < image.rows; row++) {
		for(int col=0; col < image.cols; col++) {
			for(int color=0; color < 3; color++) {
				Vec3b pixel = image.at<Vec3b>(Point(row,col));
				if(isBitSet(pixel.val[color],0))
					ch |= 1;
				bit_count++;
				if(bit_count == 8) {
					if(ch == '\0')
						goto OUTvt;
					bit_count = 0;
					cout << ch;
					f1<<ch;
					ch = 0;
				}
				else {
					ch = ch << 1;
				}

			}
		}
	}
	OUTvt:;
	f1.close();
    return 0;
}


int lsbdeccan() {

   string ipim;
	ipim = "D:/inscan.png";
	Mat image = imread(ipim);
	if(image.empty()) {
		cout << "Image Error\n";
		exit(-1);
	}


    ofstream f1;
    f1.open("D://CTDecoded.txt",ios::out);
	char ch=0;
	int bit_count = 0;
	for(int row=0; row < image.rows; row++) {
		for(int col=0; col < image.cols; col++) {
			for(int color=0; color < 3; color++) {
				Vec3b pixel = image.at<Vec3b>(Point(row,col));
				if(isBitSet(pixel.val[color],0))
					ch |= 1;
				bit_count++;
				if(bit_count == 8) {
					if(ch == '\0')
						goto OUTct;
					bit_count = 0;
					cout << ch;
					f1<<ch;
					ch = 0;
				}
				else {
					ch = ch << 1;
				}

			}
		}
	}
	OUTct:;
	f1.close();
    return 0;
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
	input.open("D://ElectionWin.txt",ios::in);
	getline(input,data);
	input.close();

	string es = enc(S, T, data);
	cout << "Input Message: " << data << endl;
	cout << "Encrypted Message:  " << es << endl;

	ofstream enct;
	enct.open("D://Electionrc4enc.txt",ios::out);
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
	input.open("D://Electionrc4enc.txt",ios::in);
	getline(input,es);
	input.close();

	string ds = dec(S, T, es);
	cout << "Encrypted Message:  " << es << endl;
	cout << "Decrypted Message:  " << ds << endl;

	ofstream dect;
	dect.open("D://Electionrc4dec.txt",ios::out);
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
//			 system("PAUSE");
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
            cout<<"Enter Password : ";
//           cin.get();
            getline(cin,password);
            cout<<password<<"\n";;
            //cout<<vt.pswd;
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

    for(int i=0; i<totct; i++)
    {
        ct[i].showdata();
        cout<<"Press Enter to show the next candidate.";
    }
    system("CLS");
    char ans;
    bool vtd=false;
    cout<<"\n\nNow you can select which Candidate to vote for : ";
    for(int i=0; i<totct; i++)
    {
        if(!vtd)
        {
            ct[i].showdata();
            cout<<"Do you want to vote for this Candidate ? (Please type Y or N)";
            cin>>ans;
            if(ans=='y'||ans=='Y')
            {
                ct[i].voteadd();
                currvt.vote();
                currct=ct[i];
                cout<<"You have successfully voted for this candidate.";
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
    cout<<"1.View your data.";
    cout<<"\n2.Change your address.";
    cout<<"\n3.Update your mobile number.";
    cout<<"\n4.Goto election Screen.";
    cout<<"\n5.Logout";
    cout<<"\n\nEnter your choice : ";
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
//	 cin.get();
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
//			 system("PAUSE");
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
            cout<<"Enter Password : ";
//            cin.get();
            getline(cin,password);
//              cout<<password<<"\n";;
            //cout<<ct.pswd;
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
                    cout<<"Please re-enter your Password :";
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
    cout<<"1.View your data.";
    cout<<"\n2.Change your address.";
    cout<<"\n3.Update your mobile number.";
    cout<<"\n4.Logout";
    cout<<"\n\nEnter your choice : ";
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
    cout<<"\nThe Message is as follows : \n";
    ifstream f1;
    string tp;
    f1.open("D://ElectionWin.txt",ios::in);
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
    fcdc.open("D://ElectionWinCoded.txt",ios::in);
    ftmp.open("D://tmp.txt",ios::in);
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
//        cout<<en[i]<<" ";
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
    cout << "\nTHE DECRYPTED MESSAGE IS\n";
    for (i = 0; m[i] != -1; i++)
        printf("%c", (char)m[i]);
//    cout<<"\n\n";
    ofstream fcddc;
    fcddc.open("D://CandidateWinDecoded.txt",ios::out);
    for (i = 0; m[i] != -1; i++)
        fcddc<<(char)m[i];
    fcddc.close();
}

void admin_func()
{
    system("CLS");
    string usid,pass;
    cout<<"Enter the administrator username : ";
    cin.get();
    getline(cin,usid);
    if(usid=="@dm!n")
    {
reenter:
        ;
        cout<<"\nEnter the password : ";
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
    cout<<"\n\nHello Admin";
    cout<<"\n\n1.Display the votes received by each Candidate and the winning Candidate.\n(It also stores the name and number of votes received in a new file)";
    cout<<"\n2.Reset the votes.";
    cout<<"\n3.Decrypt the Candidate and Voter Data Files.";
    cout<<"\n4.Decrypt the Winning Candidate Data File";
    cout<<"\n5.Logout";
    cout<<"\n\nEnter your choice : ";
    cin>>ch;
    ofstream f1;
    switch(ch)
    {
    case 1:
        for(int i=0; i<totct; i++)
        {
            ct[i].showvotes();
            if(ct[i].retvt()>max_vote)
            {
                max_vote=ct[i].retvt();
                tp=ct[i];
            }
        }
        cout<<"\n\nThe candidate who won is \n\n";
        tp.showdata();
        f1.open("D://ElectionWin.txt",ios::out);
//        f1<<"Name "<<tp.name<<"    ";
//        f1<<"Candidate_ID "<<tp.candidate_id<<"    ";
//        f1<<"Gender "<<tp.gender<<"    ";
//        f1<<"Mobile Number "<<tp.mob<<"    ";
//        f1<<"Party "<<tp.party_name<<"     ";
//        f1<<"Party Slogan "<<tp.party_slogan<<"     ";
//        f1<<"Votes Received "<<to_string(tp.votes)<<"     ";
        f1<<"The winning candidate is "<<tp.name<<" with "<<to_string(tp.votes)<<" amount of votes.";
        f1.close();
        encrypt_main();
        rc4modenc();
        remove("D://ElectionWin.txt");
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
        cout<<"The voting Status has been reset successfully.\n";
        system("PAUSE");
        goto redo;
    case 3:
          lsbdeccan();
          lsbdecvot();
          goto redo;
    case 4:
        dcrypt_main();
        rc4modecr();
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
    fvt.open("VoterData.txt",ios::in);
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
    fct.open("CandidateData.txt",ios::in);
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
        fv.open("VoterData.txt",ios::out);
        for(int i=0; i<totvt; i++)
        {
            fv.write((char*)&vt[i],sizeof(vt[i]));
        }
        fv.close();
    }
    if(totct!=0)
    {
        ofstream fc;
        fc.open("CandidateData.txt",ios::out);
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
     fvt.open("D://VtData.txt",ios::out);
     if(totvt!=0)
       {
        for(int i=0;i<totvt;i++)
           {
            fvt<<"Name : "<<vt[i].name<<"\n";
            fvt<<"Voter ID : "<<vt[i].vid<<"\n";
            fvt<<"Aadhar Number : "<<vt[i].aadhar<<"\n";
            fvt<<"Gender : "<<vt[i].gender<<"\n";
            fvt<<"Mobile Number : "<<vt[i].mob<<"\n";
            fvt<<"Date Of Birth : "<<vt[i].d<<" - "<<vt[i].m<<" - "<<vt[i].y<<"\n";
           }
       }
     fvt.close();
     fct.open("D://CtData.txt",ios::out);
     if(totct!=0)
       {
        for(int i=0;i<totct;i++)
           {
            fct<<"Name : "<<ct[i].name<<"\n";
            fct<<"Candidate ID : "<<ct[i].candidate_id<<"\n";
            fct<<"Aadhar Number : "<<ct[i].aadhar<<"\n";
            fct<<"Gender : "<<ct[i].gender<<"\n";
            fct<<"Mobile Number : "<<ct[i].mob<<"\n";
            fct<<"Date Of Birth : "<<ct[i].d<<" - "<<ct[i].m<<" - "<<ct[i].y<<"\n";
            fct<<"Party : "<<ct[i].party_name<<"\n";
            fct<<"Party Slogan: "<<ct[i].party_slogan<<"\n";
           }
       }
     fct.close();
    }

int main()
{
    system("Color 0A");
    cout << "Welcome to India 2020 Election System!\n";
    system("PAUSE");
    getdata();
    system("CLS");
    if(totct!=0)
        totct--;
    if(totvt!=0)
        totvt--;
//    cout<<"These are "<<totct<<" candidates found stored till now : \n\n";
//    for(int i=0;i<totct;i++)
//        ct[i].showdata();
//    system("PAUSE");
//    system("CLS");
//    cout<<"These are "<<totvt<<" voters found stored till now : \n\n";
//    for(int i=0;i<totvt;i++)
//        vt[i].showdata();
//    system("PAUSE");

Choose:
    ;
    system("CLS");
    int logop;
    cout << "Choose the login option: \n";
    cout << "1. Voter Login\n2. Candidate Login\n3. Admin Login\n4. Exit\n";
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
        lsbencvoter();
        lsbenccandidate();
        remove("D://CtData.txt");
        remove("D://VtData.txt");
        return 0;
    default:
        cout<<"Invalid Choice";
        goto Choose;
    }
    goto Choose;
}

