#include <iostream>
#include <string>

using namespace std;


int main() {

    int contLoop = 1;
    while (contLoop != 0){
        int typeOfDref;
        string baseSignature = "afm";
        string baseAircraft = "m20r";
        string category;
        string topic;
        int hasDescriptor; // 0 is no, yes is 1
        string descriptor;
        string specific;
        string categoryCap;

        cout << "Type of DataRef/ Command: (0 is int, 1 is double, 2 is float, 3 is command) " << endl;
        cin >> typeOfDref;
        if (typeOfDref == 3){
            category = "cmd";
            categoryCap = "Cmd";
        }
        else {
            cout << "category:" << endl;
            cin >> category;
            categoryCap = category;
            categoryCap[0] = toupper(categoryCap[0]);
        }
        cout << "topic" << endl;
        cin >> topic;
        string topicCap = topic;
        topicCap[0] = toupper(topicCap[0]);
        cout << "has descriptor?" << endl;
        cin >> hasDescriptor;
        string descriptorCap;
        if (hasDescriptor != 0){
            cin >> descriptor;
            descriptorCap = descriptor;
            descriptorCap[0] = toupper(descriptorCap[0]);
        }
        cout << "specific:" << endl;
        cin >> specific;
        string specificCap = specific;
        specificCap[0] = toupper(specificCap[0]);

        string combo;
        string comboLowerFirst;

        combo = categoryCap + topicCap;
        if (hasDescriptor != 0) { combo + descriptorCap; }
        combo = combo + specificCap;
        comboLowerFirst = combo;
        comboLowerFirst[0]=tolower(comboLowerFirst[0]);
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

                cout << endl;
                cout << "XPLMUnregisterDataAccessor(" << comboLowerFirst << "DataRef);" << endl;
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

                cout << endl;
                cout << "XPLMUnregisterDataAccessor(" << comboLowerFirst << "DataRef);" << endl;
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

                cout << endl;
                cout << "// " << baseSignature << "/" << baseAircraft << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << " - Float" << endl;
                cout << comboLowerFirst << "DataRef = XPLMRegisterDataAccessor(\"" << baseSignature << "/"
                     << baseAircraft
                     << "/" << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << "\", xplmType_Double, 1, " << "NULL, NULL, get" << combo << "DRCB, set" << combo
                     << "DRCB, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);" << endl;
                cout << comboLowerFirst << "DataRef = XPLMFindDataRef(\"" << baseSignature << "/" << baseAircraft << "/"
                     << category << "/" << topic << "/";
                if (hasDescriptor != 0) { cout << descriptor << "/"; }
                cout << specific << "\");" << endl;
                cout << "XPLMSetDatai(" << comboLowerFirst << "DataRef, 0);" << endl;

                cout << endl;
                cout << "XPLMUnregisterDataAccessor(" << comboLowerFirst << "DataRef);" << endl;
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


                break;
        }

            cin >> contLoop;;
    }
    return 0;
}