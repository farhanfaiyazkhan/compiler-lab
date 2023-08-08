#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Symbol structure
struct Symbol {
    string name;
};

class SymbolTable {
    private: 
        unordered_map<string, Symbol> table;
    
    public: 
        void insert(const string &name, const Symbol& symbol) {
            table[name] = symbol;
        }

        bool lookup (const string &name, Symbol& symbol) {
            auto it = table.find(name);
            if(it != table.end()) {
                symbol = it->second;
                return true;
            }
            return false;
        }

        void remove(const string &name) {
            table.erase(name);
        }
};

int main() {
    SymbolTable table;

    Symbol sym1 = {"x"};
    Symbol sym2 = {"y"};
    table.insert("id1", sym1);
    table.insert("id2", sym2);

    Symbol sym3;
    if(table.lookup("id1", sym3)) 
        cout << "Found symbol: " << sym3.name << endl;
    else
        cout << "Not found!!" << endl;

    table.remove("id1");

    if(table.lookup("id1", sym3)) 
        cout << "Found symbol: " << sym3.name << endl;
    else
        cout << "Not found!!" << endl;

    return 0;
}