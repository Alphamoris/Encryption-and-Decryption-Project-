#include <iostream>
#include <string>
using namespace std;
string encrypt(const string& plaintext, int shift) {
    string difftext = "";
    for (size_t i = 0; i < plaintext.length(); ++i) {
        char ch = plaintext[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = static_cast<char>((ch - base + shift) % 26 + base);
        }
        difftext += ch;
    }
    return difftext;
}


string decrypt(const string& difftext, int shift) {
    return encrypt(difftext, 26 - shift);
}


int main() {
    string plaintext, difftext,decrypttext;
    int shift,ans;
    cout<<"\n\n\t\t\t\tWelcome To The ENCRYPTING And DECRYPTING Program!!!\n\n";
    cout<<"----------------------------------------------------------------------------------------------------------------------";
	while(1){
    	cout<<"\n\n\t1.Encrypt The Text\n\n";
	    cout<<"\t2.Decrypt The Text\n\n";
	    cout<<"\t3.Encrypt And Decrypt The Text\n\n";
	    cout<<"\t4.Exit From Program\n\n";
		cout<<"Please Enter The Preferred Option[1/2/3/4]  :  ";
	    cin>>ans;
	    
	    
	    if(ans==1){
	    	cout << "\n\nEnter plaintext: ";
            cin.ignore();
			getline(cin, plaintext);
            cout << "\n\nEnter shift (a positive integer): ";
            cin >> shift;
            difftext = encrypt(plaintext, shift);
            cout << "\n\nEncrypted text: " << difftext << endl;
		}
	
	    if(ans==2){
		    cout<<"\n\nEnter The Encrypted Text To Decrypt  :  ";
		    cin.ignore();
			getline(cin,decrypttext);
		    string decryptedText = decrypt(decrypttext, shift);
            cout << "\n\nDecrypted text: " << decryptedText << endl;
	    }
	    
	    
	    if(ans==3){
	        cout << "\n\nEnter plaintext: ";
            cin.ignore();
			getline(cin, plaintext);
            cout << "\n\nEnter shift (a positive integer): ";
            cin >> shift;
            difftext = encrypt(plaintext, shift);
            cout << "\n\nEncrypted text: " << difftext << endl;
            string decryptedText = decrypt(difftext, shift);
            cout << "\n\nDecrypted text: " << decryptedText << endl;
	    }
	    
	    
	    if(ans==4){
		    cout<<"\n\nThank You For Using Our Program!!!\n";
		    cout<<"\n\nHave A Good Day";
		    break;
	    }
	}
	return 0;
}

