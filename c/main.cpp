#include <iostream>
#include <cstring>
#include <map>
#include <functional>
#include <algorithm>
using namespace std;
int ands = 0;
int ors = 0;
int nots = 0;
int nands = 0;
int nors = 0;
int xors = 0;

bool evaluate_logic_gate(string &circuit);
bool AND(string &circuit)
{
    ands ++;
    bool input1 = evaluate_logic_gate(circuit);
    bool input2 = evaluate_logic_gate(circuit);

    return (input1 && input2);
}

bool OR(string &circuit)
{
    ors ++;
    bool input1 = evaluate_logic_gate(circuit);
    bool input2 = evaluate_logic_gate(circuit);

    return (input1 || input2);
}

bool NOT(string &circuit)
{
    nots ++;
    bool input1 = evaluate_logic_gate(circuit);

    return (!(input1));
}

bool NAND(string &circuit)
{
    nands ++;
    bool input1 = evaluate_logic_gate(circuit);
    bool input2 = evaluate_logic_gate(circuit);

    return (!(input1 && input2));
}

bool NOR(string &circuit)
{
    nors ++;
    bool input1 = evaluate_logic_gate(circuit);
    bool input2 = evaluate_logic_gate(circuit);

    return (!(input1 || input2));
}

bool XOR(string &circuit)
{
    xors ++;
    bool input1 = evaluate_logic_gate(circuit);
    bool input2 = evaluate_logic_gate(circuit);

    return ((input1 != input2));
}

map < string, function < bool(string&) >> funcMap =
    {{ "AND", AND},
    { "OR", OR},
    {"NOT", NOT},
    { "NAND", NAND},
    { "NOR", NOR},
    { "XOR", XOR}
         };
bool evaluate_logic_gate(string &circuit){
    if (circuit.find(' ') == 1){
        bool value = stoi(circuit.substr(0,1));
        circuit = circuit.substr(2,circuit.length());
        return value;
    }
    string sub_gate = circuit.substr(0, circuit.find(' '));
    string input = circuit.substr(circuit.find(' ')+1, circuit.find('E'));
    circuit = circuit.substr(circuit.find('E')+1, circuit.length());
    return funcMap[sub_gate](input);
    
}
int main()
{
    int output = 0;
    string circuit;
    getline(cin, circuit);
    transform(circuit.begin(), circuit.end(), circuit.begin(), ::toupper);
    int spos = circuit.find(' ');
    string parent_gate = circuit.substr(0, spos);
    circuit = circuit.substr(spos+1, circuit.length());
    if(funcMap[parent_gate](circuit)){
        output = 1;
        
    }
    
    cout << "AND gates : " << ands << "\n";
    cout << "OR gates : " << ors << "\n";
    cout << "NOT gates : " << nots << "\n";
    cout << "XOR gates : " << xors << "\n";
    cout << "NAND gates : " << nands << "\n";
    cout << "NOR gates : " << nors << "\n";
    cout << "result : " << output << "\n";
        return 0;
}
