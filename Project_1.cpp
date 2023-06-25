#include <iostream>
#include <string>
using namespace std;

class TextEditor {
private:
     string text;
    int  cursor_pos;

public:
    TextEditor() {
        text = "";
         cursor_pos = 0;
    }

    void addText(const  string& newtxt) {
        text.insert( cursor_pos, newtxt);
         cursor_pos += newtxt.length();
    }

    void deleteText(int a) {
        if ( cursor_pos > 0 &&  cursor_pos <= text.length()) {
            text.erase( cursor_pos - 1, a );
             cursor_pos--;
        }
    }

    void moveCursorLeft(int b ) {
        if ( cursor_pos > 0) {
             cursor_pos -= b;
        }
    }

    void backspace(int d) {
        if (cursor_pos > 0) {
            text.erase(cursor_pos - 1, d);
            cursor_pos--;
        }
    }    

    void moveCursorRight(int c) {
        if ( cursor_pos < text.length()) {
             cursor_pos+= c;
        }
    }

    void displayText() {
        cout << text <<  endl;
        cout <<  string( cursor_pos, ' ') << "^" <<  endl;
    }

    void displayText() {
        cout << text <<  endl;
       
    }

    int findCursor() {
        return cursor_pos;
    }

    string showText(int k) {
        return text.substr(cursor_pos, k);
    }
};

int main() {
    string textin;
    int left , right , deletion, back , k;

    TextEditor editor;

    cout << "Enter your string !!" << endl  ; 
    cin >> textin ;
    editor.addText(textin);
    editor.displayText(); 

    cout << "Enter number of positions to left :" << endl  ; 
    cin >> left ;
    editor.moveCursorLeft(left);
    editor.displayText();  

    cout << "Enter number of positions to right :" << endl  ; 
    cin >> right ;
    editor.moveCursorRight(right);
    editor.displayText(); 

    cout << "Enter number of letter to delete (will delete from right) :" << endl  ; 
    cin >> deletion ;
    editor.deleteText(deletion);
    editor.displayText(); 

    cout << "Enter number of letter to backspace : :" << endl  ; 
    cin >> back ;
    editor.backspace(back);
    editor.displayText(); 
    
    cout << "Enter value for k for show text :" << endl  ;
    cin >> k ;
    cout << editor.showText(k) << endl;
    
    editor.findCursor();
    cout << "Final String : " << endl;
    editor.displayTextFinal(); 

    
    return 0;
}
