#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include <ios>

using namespace std;


int main() {
    ofstream log;
    log.open("m20rdrefs.txt");
    ofstream startFile;
    startFile.open("start.txt");
    ofstream stopFile;
    stopFile.open("stop.txt");
    ofstream declare;
    declare.open ("declaration.txt");
    ofstream drefEditor;
    drefEditor.open ("drefeditor.txt");


    int contLoop = 1;
    float looper = 0;
    int typeOfDref;
    string baseSignature = "afm";
    string baseAircraft = "m20r";
    string category;
    string topic;
    int hasDescriptor; // 0 is no, yes is 1
    string descriptor;
    string specific;
    string categoryCap;
    string descriptorCap;
    string combo;
    string comboLowerFirst;
    string topicCap = topic;

    while (contLoop != 0){



        if (looper != 1) {

            cout << "Type of DataRef/ Command: (0 is int, 1 is double, 2 is float, 3 is command, 4 is int array) "
                 << endl;
            cin >> typeOfDref;
            if (typeOfDref == 3) {
                category = "cmd";
                categoryCap = "Cmd";
            } else {
                cout << "category:" << endl;
                cin >> category;
                categoryCap = category;
                categoryCap[0] = toupper(categoryCap[0]);
            }
            cout << "topic" << endl;
            cin >> topic;
            topicCap[0] = toupper(topicCap[0]);
            cout << "has descriptor?" << endl;
            cin >> hasDescriptor;
            if (hasDescriptor != 0) {
                cin >> descriptor;
                descriptorCap = descriptor;
                descriptorCap[0] = toupper(descriptorCap[0]);
            }
            cout << "specific:" << endl;
            cin >> specific;
            string specificCap = specific;
            specificCap[0] = toupper(specificCap[0]);



            combo = categoryCap + topicCap;
            if (hasDescriptor != 0) { combo = combo + descriptorCap; }
            combo = combo + specificCap;
            comboLowerFirst = combo;
            comboLowerFirst[0] = tolower(comboLowerFirst[0]);

        }
        if (looper == 1){
            cout << "descriptor" << endl;
            cin >> descriptor;
            descriptorCap = descriptor;
            descriptorCap[0] = toupper(descriptorCap[0]);

            cout << "specific:" << endl;
            cin >> specific;
            string specificCap = specific;
            specificCap[0] = toupper(specificCap[0]);

            combo = categoryCap + topicCap + descriptorCap + specificCap;
            comboLowerFirst = combo;
            comboLowerFirst[0] = tolower(comboLowerFirst[0]);

        }
        switch (typeOfDref) {
            default:
                cout << "Error" << endl;
                break;
            case 0:
                cout << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << " - Int" << endl;
                cout << "XPLMDataRef " << comboLowerFirst << "DataRef = NULL;" << endl;
                cout << "int " << comboLowerFirst << " = 0;" << endl;
                cout << "int get" << combo << "DRCB (void* inRefcon) { return " << comboLowerFirst << "; }" << endl;
                cout << "void set" << combo << "DRCB (void* inRefcon, int outValue) { " << comboLowerFirst
                     << " = outValue;}" << endl;

                declare << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { declare << descriptor << "/"; }
                declare << specific << " - Int" << endl;
                declare << "XPLMDataRef " << comboLowerFirst << "DataRef = NULL;" << endl;
                declare << "int " << comboLowerFirst << " = 0;" << endl;
                declare << "int get" << combo << "DRCB (void* inRefcon) { return " << comboLowerFirst << "; }" << endl;
                declare << "void set" << combo << "DRCB (void* inRefcon, int outValue) { " << comboLowerFirst
                     << " = outValue;}" << endl << endl;

                cout << endl;

                cout << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << " - Int" << endl;
                cout << comboLowerFirst << "DataRef = XPLMRegisterDataAccessor(\"" << baseSignature << "/"
                     << baseAircraft
                     << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << "\", xplmType_Int, 1, get" << combo << "DRCB, set" << combo
                     << "DRCB, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);" << endl;
                cout << comboLowerFirst << "DataRef = XPLMFindDataRef(\"" << baseSignature << "/" << baseAircraft << "/"
                     << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << "\");" << endl;
                cout << "XPLMSetDatai(" << comboLowerFirst << "DataRef, 0);" << endl;


                startFile << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { startFile << descriptor << "/"; }
                startFile << specific << " - Int" << endl;
                startFile << comboLowerFirst << "DataRef = XPLMRegisterDataAccessor(\"" << baseSignature << "/"
                     << baseAircraft
                     << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { startFile << descriptor << "/"; }
                startFile << specific << "\", xplmType_Int, 1, get" << combo << "DRCB, set" << combo
                     << "DRCB, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);" << endl;
                startFile << comboLowerFirst << "DataRef = XPLMFindDataRef(\"" << baseSignature << "/" << baseAircraft << "/"
                     << category << "/" << topic << "/";
                if (hasDescriptor != 0) { startFile << descriptor << "/"; }
                startFile << specific << "\");" << endl;
                startFile << "XPLMSetDatai(" << comboLowerFirst << "DataRef, 0);" << endl;



                cout << endl;
                cout << "XPLMUnregisterDataAccessor(" << comboLowerFirst << "DataRef);" << endl << endl;
                stopFile << "XPLMUnregisterDataAccessor(" << comboLowerFirst << "DataRef);" << endl;


                cout << "XPLMSendMessageToPlugin(PluginID, MSG_ADD_DATAREF, (void*)\""<< baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/"; if (hasDescriptor != 0) { cout << descriptor << "/"; } cout << specific <<"\");" << endl;

                drefEditor << "XPLMSendMessageToPlugin(PluginID, MSG_ADD_DATAREF, (void*)\""<< baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { drefEditor << descriptor << "/"; } drefEditor << specific <<"\");" << endl;

                break;

            case 1:
                cout << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << " - Double" << endl;
                cout << "XPLMDataRef " << comboLowerFirst << "DataRef = NULL;" << endl;
                cout << "double " << comboLowerFirst << " = 0;" << endl;
                cout << "double get" << combo << "DRCB (void* inRefcon) { return " << comboLowerFirst << "; }" << endl;
                cout << "void set" << combo << "DRCB (void* inRefcon, double outValue) { " << comboLowerFirst
                     << " = outValue;}" << endl;

                declare << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { declare << descriptor << "/"; }
                declare << specific << " - Double" << endl;
                declare << "XPLMDataRef " << comboLowerFirst << "DataRef = NULL;" << endl;
                declare << "double " << comboLowerFirst << " = 0;" << endl;
                declare << "double get" << combo << "DRCB (void* inRefcon) { return " << comboLowerFirst << "; }" << endl;
                declare << "void set" << combo << "DRCB (void* inRefcon, double outValue) { " << comboLowerFirst
                     << " = outValue;}" << endl << endl;



                cout << endl;
                cout << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << " - Double" << endl;
                cout << comboLowerFirst << "DataRef = XPLMRegisterDataAccessor(\"" << baseSignature << "/"
                     << baseAircraft
                     << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << "\", xplmType_Double, 1, " << "NULL, NULL, NULL, NULL, get" << combo << "DRCB, set"
                     << combo << "DRCB, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);" << endl;
                cout << comboLowerFirst << "DataRef = XPLMFindDataRef(\"" << baseSignature << "/" << baseAircraft << "/"
                     << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << "\");" << endl;
                cout << "XPLMSetDatai(" << comboLowerFirst << "DataRef, 0);" << endl;



                startFile << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { startFile << descriptor << "/"; }
                startFile << specific << " - Double" << endl;
                startFile << comboLowerFirst << "DataRef = XPLMRegisterDataAccessor(\"" << baseSignature << "/"
                     << baseAircraft
                     << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { startFile << descriptor << "/"; }
                startFile << specific << "\", xplmType_Double, 1, " << "NULL, NULL, NULL, NULL, get" << combo << "DRCB, set"
                     << combo << "DRCB, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);" << endl;
                startFile << comboLowerFirst << "DataRef = XPLMFindDataRef(\"" << baseSignature << "/" << baseAircraft << "/"
                     << category << "/" << topic << "/";
                if (hasDescriptor != 0) { startFile << descriptor << "/"; }
                startFile << specific << "\");" << endl;
                startFile << "XPLMSetDatai(" << comboLowerFirst << "DataRef, 0);" << endl;



                cout << endl;
                cout << "XPLMUnregisterDataAccessor(" << comboLowerFirst << "DataRef);" << endl << endl;
                cout << "XPLMSendMessageToPlugin(PluginID, MSG_ADD_DATAREF, (void*)\""<< baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";

                stopFile << "XPLMUnregisterDataAccessor(" << comboLowerFirst << "DataRef);" << endl;
                drefEditor << "XPLMSendMessageToPlugin(PluginID, MSG_ADD_DATAREF, (void*)\""<< baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { drefEditor << descriptor << "/"; } drefEditor << specific <<"\");" << endl;

                break;

            case 2:
                cout << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << " - Float" << endl;
                cout << "XPLMDataRef " << comboLowerFirst << "DataRef = NULL;" << endl;
                cout << "float " << comboLowerFirst << " = 0;" << endl;
                cout << "float get" << combo << "DRCB (void* inRefcon) { return " << comboLowerFirst << "; }" << endl;
                cout << "void set" << combo << "DRCB (void* inRefcon, float outValue) { " << comboLowerFirst
                     << " = outValue;}" << endl;


                declare << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { declare << descriptor << "/"; }
                declare << specific << " - Float" << endl;
                declare << "XPLMDataRef " << comboLowerFirst << "DataRef = NULL;" << endl;
                declare << "float " << comboLowerFirst << " = 0;" << endl;
                declare << "float get" << combo << "DRCB (void* inRefcon) { return " << comboLowerFirst << "; }" << endl;
                declare << "void set" << combo << "DRCB (void* inRefcon, float outValue) { " << comboLowerFirst
                     << " = outValue;}" << endl << endl;


                cout << endl;
                cout << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << " - Float" << endl;
                cout << comboLowerFirst << "DataRef = XPLMRegisterDataAccessor(\"" << baseSignature << "/"
                     << baseAircraft
                     << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << "\", xplmType_Float, 1, " << "NULL, NULL, get" << combo << "DRCB, set" << combo
                     << "DRCB, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);" << endl;
                cout << comboLowerFirst << "DataRef = XPLMFindDataRef(\"" << baseSignature << "/" << baseAircraft << "/"
                     << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << "\");" << endl;
                cout << "XPLMSetDatai(" << comboLowerFirst << "DataRef, 0);" << endl;


                cout << endl;


                startFile << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { startFile << descriptor << "/"; }
                startFile << specific << " - Float" << endl;
                startFile << comboLowerFirst << "DataRef = XPLMRegisterDataAccessor(\"" << baseSignature << "/"
                     << baseAircraft
                     << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { startFile << descriptor << "/"; }
                startFile << specific << "\", xplmType_Float, 1, " << "NULL, NULL, get" << combo << "DRCB, set" << combo
                     << "DRCB, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);" << endl;
                startFile << comboLowerFirst << "DataRef = XPLMFindDataRef(\"" << baseSignature << "/" << baseAircraft << "/"
                     << category << "/" << topic << "/";
                if (hasDescriptor != 0) { startFile << descriptor << "/"; }
                startFile << specific << "\");" << endl;
                startFile << "XPLMSetDatai(" << comboLowerFirst << "DataRef, 0);" << endl;



                cout << endl;
                cout << "XPLMUnregisterDataAccessor(" << comboLowerFirst << "DataRef);" << endl << endl;
                stopFile << "XPLMUnregisterDataAccessor(" << comboLowerFirst << "DataRef);" << endl << endl;

                cout << "XPLMSendMessageToPlugin(PluginID, MSG_ADD_DATAREF, (void*)\""<< baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; } cout << specific <<"\");" << endl;

                drefEditor << "XPLMSendMessageToPlugin(PluginID, MSG_ADD_DATAREF, (void*)\""<< baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { drefEditor << descriptor << "/"; } drefEditor << specific <<"\");" << endl;
                break;



            case 3:
                cout << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << " - Command" << endl;
                cout << "XPLMCommandRef " << comboLowerFirst << "CMD = NULL;" << endl;
                cout << "int " << comboLowerFirst << "CMDCommandHandler(XPLMCommandRef inCommand, XPLMCommandPhase inPhase, void* inRefcon) {" << endl;
                cout << endl << "return 0;" << endl << "}" << endl << endl << endl;

                cout << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << " - Command" << endl;
                cout << comboLowerFirst << "CMD = XPLMCreateCommand(\"" << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << "\", \"DESCRIPTION GOES HERE\");" << endl;
                cout << "XPLMRegisterCommandHandler(" << comboLowerFirst << "CMD, " << comboLowerFirst << "CMDCommandHandler, 1, (void *)0);" << endl;
                cout << "XPLMSendMessageToPlugin(PluginID, MSG_ADD_DATAREF, (void*)\""<< baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; } cout << specific <<"\");" << endl;

                declare << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { declare << descriptor << "/"; }
                declare << specific << " - Command" << endl;
                declare << "XPLMCommandRef " << comboLowerFirst << "CMD = NULL;" << endl;
                declare << "int " << comboLowerFirst << "CMDCommandHandler(XPLMCommandRef inCommand, XPLMCommandPhase inPhase, void* inRefcon) {" << endl;
                declare << endl << "return 0;" << endl << "}" << endl << endl << endl;

                startFile << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { startFile << descriptor << "/"; }
                startFile << specific << " - Command" << endl;
                startFile << comboLowerFirst << "CMD = XPLMCreateCommand(\"" << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { startFile << descriptor << "/"; }
                startFile << specific << "\", \"DESCRIPTION GOES HERE\");" << endl;
                startFile << "XPLMRegisterCommandHandler(" << comboLowerFirst << "CMD, " << comboLowerFirst << "CMDCommandHandler, 1, (void *)0);" << endl;
                // drefEditor << "XPLMSendMessageToPlugin(PluginID, MSG_ADD_DATAREF, (void*)\""<< baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { drefEditor << descriptor << "/"; } drefEditor << specific <<"\");" << endl;

                break;


            case 4:
                int valInDR;
                cout << "Values in Dataref:" << endl;
                cin >> valInDR;


                cout << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/"; if (hasDescriptor != 0) { cout << descriptor << "/"; } cout << specific << " - Int Array" << endl;
                cout << "XPLMDataRef " << comboLowerFirst << "DataRef = NULL;" << endl;
                cout << "int " << comboLowerFirst << "[" << valInDR << "] = { "; for (int x=valInDR-1; x>0; x--){ cout << "0, ";} cout << "0};" << endl;
                cout << "int get" << combo << "DRCB(void* inRefcon, int* outValues, int inOffset, int inMax) {" << endl;
                    cout << "int n, r;" << endl;
                    cout << "if (outValues == NULL) { return " << valInDR << "; }" << endl;
                    cout << "r = " << valInDR <<" - inOffset;" << endl;
                    cout << "if (r > inMax) { r = inMax; }" << endl;
                    cout << "for (n = 0; n < r; n++) { outValues[n] = " << comboLowerFirst << "[n + inOffset]; }" << endl;
                    cout << "return r;" << endl << "}" << endl;
                cout << "void set" << combo << "DRCB(void * inRefcon, int * inValues, int inOffset, int inCount) {" << endl;
                        cout << "int n, r;" << endl;
                        cout << "r = " << valInDR << " - inOffset;" << endl;
                        cout << "if (r > inCount) { r = inCount; }" << endl;
                        cout << "for (n = 0; n < r; n++) { " << comboLowerFirst <<"[n + inOffset] = inValues[n]; }" << endl;
                        cout << "}" << endl << endl << endl;




                cout << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/"; if (hasDescriptor != 0) { cout << descriptor << "/"; } cout << specific << " - Int Array" << endl;
                cout << comboLowerFirst << "DataRef = XPLMRegisterDataAccessor(\"" << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/"; if (hasDescriptor != 0) { cout << descriptor << "/"; } cout << specific;
                cout <<"\", xplmType_IntArray, 1, NULL, NULL, NULL, NULL, NULL, NULL, get" << combo << "DRCB, set" << combo << "DRCB, NULL, NULL, NULL, NULL, NULL, NULL);" << endl;
                cout << comboLowerFirst << "DataRef = XPLMFindDataRef(\"" << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/"; if (hasDescriptor != 0) { cout << descriptor << "/"; } cout << specific << "\");" << endl;
                cout << "int " << comboLowerFirst << "DataRefInitVal[" << valInDR << "] = { "; for (int x=valInDR-1; x>0; x--){ cout << "0, ";} cout << "0};" << endl;
                cout << "XPLMSetDatavi(" << comboLowerFirst << "DataRef, &" << comboLowerFirst << "DataRefInitVal[0], 0, " << valInDR << ");" << endl << endl << endl;


                cout << "XPLMUnregisterDataAccessor(" << comboLowerFirst << "DataRef);" << endl << endl;
                cout << "XPLMSendMessageToPlugin(PluginID, MSG_ADD_DATAREF, (void*)\""<< baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; } cout << specific <<"\");" << endl;



                declare << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/"; if (hasDescriptor != 0) { declare << descriptor << "/"; } declare << specific << " - Int Array" << endl;
                declare << "XPLMDataRef " << comboLowerFirst << "DataRef = NULL;" << endl;
                declare << "int " << comboLowerFirst << "[" << valInDR << "] = { "; for (int x=valInDR-1; x>0; x--){ declare << "0, ";} declare << "0};" << endl;
                declare << "int get" << combo << "DRCB(void* inRefcon, int* outValues, int inOffset, int inMax) {" << endl;
                declare << "int n, r;" << endl;
                declare << "if (outValues == NULL) { return " << valInDR << "; }" << endl;
                declare << "r = " << valInDR <<" - inOffset;" << endl;
                declare << "if (r > inMax) { r = inMax; }" << endl;
                declare << "for (n = 0; n < r; n++) { outValues[n] = " << comboLowerFirst << "[n + inOffset]; }" << endl;
                declare << "return r;" << endl << "}" << endl;
                declare << "void set" << combo << "DRCB(void * inRefcon, int * inValues, int inOffset, int inCount) {" << endl;
                declare << "int n, r;" << endl;
                declare << "r = " << valInDR << " - inOffset;" << endl;
                declare << "if (r > inCount) { r = inCount; }" << endl;
                declare << "for (n = 0; n < r; n++) { " << comboLowerFirst <<"[n + inOffset] = inValues[n]; }" << endl;
                declare << "}" << endl << endl << endl;




                startFile << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/"; if (hasDescriptor != 0) { startFile << descriptor << "/"; } startFile << specific << " - Int Array" << endl;
                startFile << comboLowerFirst << "DataRef = XPLMRegisterDataAccessor(\"" << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/"; if (hasDescriptor != 0) { startFile << descriptor << "/"; } startFile << specific;
                startFile <<"\", xplmType_IntArray, 1, NULL, NULL, NULL, NULL, NULL, NULL, get" << combo << "DRCB, set" << combo << "DRCB, NULL, NULL, NULL, NULL, NULL, NULL);" << endl;
                startFile << comboLowerFirst << "DataRef = XPLMFindDataRef(\"" << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/"; if (hasDescriptor != 0) { startFile << descriptor << "/"; } startFile << specific << "\");" << endl;
                startFile << "int " << comboLowerFirst << "DataRefInitVal[" << valInDR << "] = { "; for (int x=valInDR-1; x>0; x--){ startFile << "0, ";} startFile << "0};" << endl;
                startFile << "XPLMSetDatavi(" << comboLowerFirst << "DataRef, &" << comboLowerFirst << "DataRefInitVal[0], 0, " << valInDR << ");" << endl << endl << endl;


                stopFile << "XPLMUnregisterDataAccessor(" << comboLowerFirst << "DataRef);" << endl << endl;
                drefEditor << "XPLMSendMessageToPlugin(PluginID, MSG_ADD_DATAREF, (void*)\""<< baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { drefEditor << descriptor << "/"; } drefEditor << specific <<"\");" << endl;

                break;

        }
        cout << endl << endl << endl << "Go Again? 5 to run Looper command and only change last 2 values" << endl;
        cin >> contLoop;;
        if (contLoop == 5){looper=1;}
        else {looper=0;}
    }
    return 0;
}