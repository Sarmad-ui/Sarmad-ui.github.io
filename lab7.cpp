#include <iostream>
#include <string>

using namespace std;

class CString {
private:
    char* str;
    int size;

public:
    CString();
    CString(char c);
    CString(const char*);
    CString(const CString &);
    ~CString();
    int getLenght();
    void display() const;
    int finds(const char* substr, int start=0) const;
    int find(char ch, int start=0) const;
    int insert(int index, const char* substr);
    int insertc(int index, char ch);
    CString left(int count) const;
    CString right(int count) const;
    int remove(int index, int count=1);
    int remove(char ch);
    void replace(char newch);
    int replace(char oldch, char newch);
    int replace(const char* oldst, const char* newst);
    void trim();
    void trimLeft();
    void trimRight();
    void makeUpper();
    void makeLower();
    void reverse();
    void Resize(int add);
    CString concat(const CString& s2) const;
    void concatEqual(const CString& s2);
    void concatEqual(const char* s2);
    int isEqual(const char* s2) const;
    void input();
    char& at(int index);
    int isEmpty();
};

CString::CString() 
{
    size = 1;
    str = new char[size];
    str[0] = '\0';
}

CString::CString(char c) 
{
    size = 2;
    str = new char[size];
    str[0] = c;
    str[1] = '\0';
}

CString::CString(const char* s) 
{
    int len = 0;
    while (s[len] != '\0') len++;
    size = len + 1;
    str = new char[size];
    for (int i = 0; i < len; i++) {
		str[i] = s[i];
	}
    str[len] = '\0';
}

CString::CString(const CString &s) 
{
    size = s.size;
    str = new char[size];
    for (int i = 0; i < size; i++) {
		str[i] = s.str[i];
	}
}

CString::~CString() 
{
    delete[] str;
}

int CString::getLenght() 
{
    int len = 0;
    while(str[len] != '\0') 
		len++;
    return len;
}

void CString::display() const 
{
    cout << str << endl;
}

int CString::finds(const char* substr, int start) const 
{
    int subLen = 0;
    while(substr[subLen] != '\0') 
		subLen++;
    for(int i = start; str[i] != '\0'; i++) 
	{
        int j = 0;
        while(j < subLen && str[i + j] == substr[j]) 
			j++;
        if(j == subLen) 
		{
        	cout << i << endl;
        	return i;
		}
			
    }
    return -1;
}

int CString::find(char ch, int start) const 
{
    for(int i = start; str[i] != '\0'; i++) 
	{
        if(str[i] == ch) {
        	cout << i << endl;
        	return i;
		}
			
    }
    return -1;
}

int CString::insert(int index, const char* substr) 
{
    int len = 0, sublen = 0;
    while(str[len] != '\0') 
		len++;
    while(substr[sublen] != '\0') 
		sublen++;
    char* temp = new char[len + sublen + 1];
    for(int i = 0; i < index; i++) 
		temp[i] = str[i];
    for(int i = 0; i < sublen; i++) 
		temp[index + i] = substr[i];
    for(int i = index; i < len; i++) 
		temp[sublen + i] = str[i];
    temp[len + sublen] = '\0';
    delete[] str;
    str = temp;
    size = len + sublen + 1;
    return len + sublen;
}

int CString::insertc(int index, char ch) 
{
    char temp[2];
    temp[0] = ch;
    temp[1] = '\0';
    return insert(index, temp);
}

CString CString::left(int count) const 
{
    char* temp = new char[count + 1];
    for(int i = 0; i < count; i++) temp[i] = str[i];

    temp[count] = '\0';
    CString s(temp);
    delete[] temp;
    return s;
}

CString CString::right(int count) const 
{
    int len = 0;
    while(str[len] != '\0') 
		len++;
    return CString(str + (len - count));
}

int CString::remove(int index, int count) 
{
    int len = 0;
    while(str[len] != '\0') 
		len++;
    for(int i = index; i < len - count; i++) 
		str[i] = str[i + count];
    str[len - count] = '\0';
    return len - count;
}

int CString::remove(char ch) 
{
    int len = 0, count = 0;
    while(str[len] != '\0') 
		len++;
    for(int i = 0; i < len; i++) 
	{
        if(str[i] == ch) 
		{
            remove(i);
            i--; 
			len--; 
			count++;
        }
    }
    return count;
}

void CString::replace(char newch) 
{
    int i = 0;
    while(str[i] != '\0') 
	{ 
		str[i] = newch;
		i++; 
	}
}

int CString::replace(char oldc, char newc) 
{
    int i = 0, count = 0;
    while(str[i] != '\0') 
	{
        if(str[i] == oldc) 
		{ 
			str[i] = newc; 
			count++; 
		}
        i++;
    }
    return count;
}

int CString::replace(const char* olds, const char* news) 
{
    int pos, count = 0, oldLen = 0;
    while(olds[oldLen] != '\0') 
		oldLen++;
    while((pos = finds(olds)) != -1) 
	{
        remove(pos, oldLen);
        insert(pos, news);
        count++;
    }
    return count;
}

void CString::trim() 
{ 
	trimLeft(); trimRight(); 
}

void CString::trimLeft() 
{
    int i = 0;
    while(isspace(str[i])) i++;
    if(i > 0) 
		remove(0, i);
}

void CString::trimRight() 
{
    int len = 0;
    while(str[len] != '\0') 
		len++;
    len--;
    while(len >= 0 && isspace(str[len])) 
	{ 
		str[len] = '\0'; len--; 
	}
}

void CString::makeUpper() 
{
    int i = 0;
    while(str[i] != '\0') 
	{
        if(str[i] >= 'a' && str[i] <= 'z') str[i] -= 32;
        i++;
    }
}

void CString::makeLower() 
{
    int i = 0;
    while(str[i] != '\0') 
	{
        if(str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
        i++;
    }
}

void CString::reverse() 
{
    int len = 0;
    while(str[len] != '\0') len++;
    for(int i = 0; i < len / 2; i++) 
	{
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void CString::Resize(int add) 
{
    int len = 0;
    while(str[len] != '\0') 
		len++;
    char* temp = new char[len + add + 1];
    for(int i = 0; i < len; i++) 
		temp[i] = str[i];
    temp[len] = '\0';
    delete[] str;
    str = temp;
    size = len + add + 1;
}

CString CString::concat(const CString& s2) const 
{
    int len1 = 0, len2 = 0;
    while(str[len1] != '\0') 
		len1++;
    while(s2.str[len2] != '\0') 
		len2++;
    char* temp = new char[len1 + len2 + 1];
    for(int i = 0; i < len1; i++) 
		temp[i] = str[i];
    for(int i = 0; i < len2; i++) 
		temp[len1 + i] = s2.str[i];
    temp[len1 + len2] = '\0';
    CString s(temp);
    delete[] temp;
    return s;
}

void CString::concatEqual(const CString& s2) 
{
    int len = 0;
    while(str[len] != '\0') 
		len++;
    insert(len, s2.str);
}

void CString::concatEqual(const char* s2) 
{
    int len = 0;
    while(str[len] != '\0') 
		len++;
    insert(len, s2);
}

int CString::isEqual(const char* s2) const 
{
    int i = 0;
    while(str[i] != '\0' && s2[i] != '\0') 
	{
        if(str[i] != s2[i]) return str[i] - s2[i];
        i++;
    }
    return str[i] - s2[i];
}

void CString::input() 
{
    char buffer[1000];
    cin.getline(buffer, 1000);
    int len = 0;
    while(buffer[len] != '\0') 
		len++;
    delete[] str;
    size = len + 1;
    str = new char[size];
    for(int i = 0; i < len; i++) str[i] = buffer[i];
    str[len] = '\0';
}

char& CString::at(int index) 
{
    return str[index];
}

int CString::isEmpty() 
{
    return str[0] == '\0' ? 0 : 1;
}

int main() {
    CString s1("Hello");
    CString s2(" World");
    CString s3;
    CString s4('A');

    cout << "Original s1: ";
    s1.display();

    cout << "Original s2: ";
    s2.display();

    cout << "Default constructor s3: ";
    s3.display();

    cout << "Character constructor s4: ";
    s4.display();

    cout << "\ns1 length: " << s1.getLenght() << endl;

    cout << "\nAppending s2 to s1: ";
    s1.concatEqual(s2);
    s1.display();

    cout << "\nFind character 'o' in s1: ";
    int pos = s1.find('o');
    cout << (pos != -1 ? "Found" : "Not Found") << endl;

    cout << "\nFind substring \"lo Wo\" in s1: ";
    int pos2 = s1.finds("lo Wo");
    cout << (pos2 != -1 ? "Found" : "Not Found") << endl;

    cout << "\nInsert 'X' at index 0 in s1: ";
    s1.insertc(0, 'X');
    s1.display();

    cout << "\nInsert \"TEST\" at index 2 in s1: ";
    s1.insert(2, "TEST");
    s1.display();

    cout << "\nLeft 5 characters of s1: ";
    CString sleft = s1.left(5);
    sleft.display();

    cout << "\nRight 5 characters of s1: ";
    CString sright = s1.right(5);
    sright.display();

    cout << "\nRemove character at index 1: ";
    s1.remove(1);
    s1.display();

    cout << "\nRemove all 'l' characters: ";
    s1.remove('l');
    s1.display();

    cout << "\nReplace all 'H' with 'Y': ";
    s1.replace('H', 'Y');
    s1.display();

    cout << "\nReplace all 'X' with 'Z': ";
    s1.replace('X', 'Z');
    s1.display();

    cout << "\nReplace substring \"TEST\" with \"DONE\": ";
    s1.replace("TEST", "DONE");
    s1.display();

    CString s5("   padded string   ");
    cout << "\nTrimmed string: ";
    s5.trim();
    s5.display();

    cout << "\nMake s1 uppercase: ";
    s1.makeUpper();
    s1.display();

    cout << "\nMake s1 lowercase: ";
    s1.makeLower();
    s1.display();

    cout << "\nReverse s1: ";
    s1.reverse();
    s1.display();

    cout << "\nResize s1 by adding 5 extra spaces: ";
    s1.Resize(5);
    s1.display();

    cout << "\nConcatenate s1 and s2 into s6: ";
    CString s6 = s1.concat(s2);
    s6.display();

    cout << "\nConcatenateEqual s2 to s1: ";
    s1.concatEqual(s2);
    s1.display();

    cout << "\nConcatenateEqual char* \"HELLO\" to s1: ";
    s1.concatEqual("HELLO");
    s1.display();

    cout << "\nInput a new string for s3: ";
    s3.input();
    cout << "You entered: ";
    s3.display();

    cout << "\nCharacter at index 0 of s3: " << s3.at(0) << endl;

    cout << "\nIs s3 empty? " << (s3.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}