#include <iostream>
#include <cstring>
#include <map>
using namespace std;

bool AND(string circuit);
bool OR(string circuit);
bool NOT(string circuit);
bool NAND(string circuit);
bool NOR(string circuit);
bool XOR(string circuit);
bool evaluate_logic_gate(string &circuit);
int main()
{
    map<string, function<bool(string&)>> funcMap =
        {{ "AND", AND},
        { "OR", OR},
        {"NOT", NOT},
        { "NAND", NAND},
        { "NOR", NOR},
        { "XOR", XOR}
             };
    string circuit;
    cout << "Enter the logic circuit: ";
    getline(cin, circuit);
    transform(circuit.begin(), circuit.end(), circuit.begin(), ::toupper);
    int spos = circuit.find(' ');
    string parent_gate = circuit.substr(0, spos);
    circuit = circuit.substr(spos+1, circuit.length());
    funcMap[parent_gate](circuit);

}
bool evaluate_logic_gate(string &circuit){
    return 1;
}
bool AND(string &circuit)
{
    bool input1 = evaluate_logic_gate(circuit); //TODO: Input subcircuit 1
    bool input2 = evaluate_logic_gate(circuit); //TODO: Input Subcircuit 2

    return (input1 && input2);
}

bool OR(string &circuit)
{
    bool input1; //TODO: Input subcircuit 1
    bool input2; //TODO: Input Subcircuit 2

    return (input1 || input2);
}

bool NOT(string &circuit)
{
    bool input1; //TODO: Input subcircuit 1

    return (!(input1));
}

bool NAND(string &circuit)
{
    bool input1; //TODO: Input subcircuit 1
    bool input2; //TODO: Input Subcircuit 2

    return (!(input1 && input2));
}

bool NOR(string &circuit)
{
    bool input1; //TODO: Input subcircuit 1
    bool input2; //TODO: Input Subcircuit 2

    return (!(input1 || input2));
}

bool XOR(string &circuit)
{
    bool input1; //TODO: Input subcircuit 1
    bool input2; //TODO: Input Subcircuit 2

    return ((input1 != input2));
}
